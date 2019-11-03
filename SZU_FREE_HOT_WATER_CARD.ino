#include <SPI.h>
#include <RFID.h>

RFID rfid(10, 9);						//D10 - 读卡器CS引脚、D9 - 读卡器RST引脚

/* 4字节卡序列号，第5字节为校验字节 */
unsigned char serNum[5];
unsigned char status;
unsigned char str[MAX_LEN];
unsigned char blockAddr;				//选择操作的块地址0～63

unsigned char writeDate[16] = {0X5F, 0XCB, 0XC9, 0X12, 'o', 'm', 'e', ' ', 'Y', 'F', 'R', 'o', 'b', 'o', 't', 0};

/* 原扇区A密码，16个扇区，每个扇区密码6Byte */
unsigned char sectorKeyA[16][16] = {
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
};

void setup()
{
	Serial.begin(9600);
	SPI.begin();
	rfid.init();
}

void loop()
{
	delay(1000);
	rfid.findCard(PICC_REQIDL, str);				//找卡
	if (rfid.anticoll(str) == MI_OK)				//防冲突检测,读取卡序列号
	{
		Serial.print("The card's number is  : ");
		for (int i = 0; i < 4; i++)					//显示卡序列号
		{
			Serial.print(0x0F & (str[i] >> 4), HEX);
			Serial.print(0x0F & str[i], HEX);
		}
		Serial.println("");
		memcpy(rfid.serNum, str, 5);
	}
	rfid.selectTag(rfid.serNum);
	memcpy(writeDate, str, 4);						//将序列号存储到writeData中
	delay(3000);

	rfid.findCard(PICC_REQIDL, str);
	if (rfid.anticoll(str) == MI_OK)				//防冲突检测,读取卡序列号
	{
		Serial.print("The card's number is  : ");
		for (int i = 0; i < 4; i++)					//显示卡序列号
		{
			Serial.print(0x0F & (str[i] >> 4), HEX);
			Serial.print(0x0F & str[i], HEX);
		}
		Serial.println("");
		memcpy(rfid.serNum, str, 5);
	}
	rfid.selectTag(rfid.serNum);					//选卡，返回卡容量（锁定卡片，防止多次读写）

	writeCard(0);									//向卡数据块0中写数据

	rfid.halt();
	while (1)
	{
		SPI.end();
		pinMode(13, OUTPUT);
		digitalWrite(13, HIGH);						//让灯常亮，程序结束
	}
}

/* 写卡 */
void writeCard(int blockAddr)
{
	if (rfid.auth(PICC_AUTHENT1A, blockAddr, sectorKeyA[blockAddr / 4], rfid.serNum) == MI_OK) //认证
	{
		Serial.print("set the new card password, and can modify the data of the Sector: ");
		Serial.println(blockAddr / 4, DEC);
		if (rfid.write(blockAddr, writeDate) == MI_OK)		//选择扇区中的块写数据
		{
			Serial.println("Write card OK!");
		}
	}
}

/* 读卡 */
void readCard(int blockAddr)
{

	if (rfid.auth(PICC_AUTHENT1A, blockAddr, sectorKeyA[blockAddr / 4], rfid.serNum) == MI_OK) //认证
	{
		Serial.print("Read from the blockAddr of the card : ");
		Serial.println(blockAddr, DEC);
		if (rfid.read(blockAddr, str) == MI_OK)			//选择扇区中的块读数据
		{
			Serial.print("The data is : ");
			Serial.println((char *)str);
		}
	}
}
