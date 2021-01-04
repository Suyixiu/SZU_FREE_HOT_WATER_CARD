# SZU_FREE_HOT_WATER_CARD
* 一个关于深圳大学无限热水卡的程序  
* 不得不说深大这1.25的热水真的真的很蛋疼，在本科的一次冬天，有一段时间南区的热水超级稀缺，那时也有人向学校反映了热水这个问题，然而根本没有后续，本着自己动手丰衣足食的理念遂搞了这个东西。觉得是个很简单但是很有用的东西遂放在github上。  
* 本来学校的这个热水系统的安全性都有问题，我这也算是利用了系统漏洞，也希望学校能早日发现这个漏洞然后改进这一套系统  
* 这个.md会帮你从0开始建立一张深圳大学的无限热水卡。 
* Enjoy！  
## 你需要的东西(一般实验室都有吧)  
* [Arduino IDE](https://m.zdfans.com/html/31422.html)(软件，这个随便找一个)  
* RFID库(也就是这个文件夹中的RFID.zip，arduino如何安装库自己百度一下，很简单)  
* [Arduino UNO](https://detail.tmall.com/item.htm?spm=a230r.1.14.188.4a8b6558Hnbkz0&id=538662184250&ns=1&abbucket=3)(建议到一些个实验室借)  
* [RFID-RC522模块](https://detail.tmall.com/item.htm?spm=a1z10.3-b.w4011-18192725132.20.590870f78XwZd1&id=44161034569&rn=9beb21db6e84df614ce05818fbe8710d&abbucket=4)(建议到一些个实验室借)
* [杜邦线若干](https://detail.tmall.com/item.htm?spm=a1z10.3-b.w4011-18192725132.51.4e1070f7uvIIqy&id=524695046876&rn=438a65fd5e11461cd5baa0c7e35e6f7b&abbucket=4&sku_properties=122216547:20213)(建议到一些个实验室借)  
* [一张可写0扇区的RFID白卡](https://detail.tmall.com/item.htm?id=542445132258&price=6.5-200&sourceType=item&sourceType=item&detailSharePosition=interactBar&suid=e4564af0-2656-4708-b28d-0f93fec4bfbc&shareUniqueId=6783197763&ut_sk=1.WJHvHlqr0ccDANxYpGpnLJO1_21646297_1609566728316.TaoPassword-QQ.1&un=135a6b66df908145f3ba5a7177d3a823&share_crt_v=1&spm=a2159r.13376460.0.0&sp_tk=SFlqOGNzWms5aTA=&cpp=1&shareurl=true&short_name=h.4hhcoai&bxsign=scdQin4SoUlMsRxZhv_j25M_acTAj_vgTp9Dw-4x5960xDmbGAsfcTMoSfbOhlwexYBTHaAAlNOy_m2hcQNbk-XO1-Nmgp8uXYZPj7Jcwh4POA&app=chrome&skuId=4478350916607)(买的这家的亲测可用，注意一定要是能读写的CUID卡)  
  
## 接线   
|Arduino|RC522模块|
|---|---
|D9|RST
|D10|SDA
|D11|MOSI
|D12|MISO
|D13|SCK
|3.3V|3.3V
|GND|GND
|不用接|IRQ  

## 烧录   
* 打开SZU_FREE_HOT_WATER_CARD.ino然后烧进板子。  
* 把你的校园卡放在RC522模块上然后打开arduino IDE的串口，注意波特率是115200  
* 你会看到你的校园卡的ID将会打印在屏幕上  
* 打印完ID之后请在3秒之内将的校园卡拿起来并把白卡放上去  
* 如果一切顺利你将会看到你白卡原本的ID，在写入成功后会有Write card OK!打印在屏幕上  
* 按一下你aruduino的reset键，你将会看到白卡的新ID会打印在屏幕上，而且可以看到白卡的ID变得跟你校园卡一样了  

## 使用  
* 先将你的校园卡在热水机上刷出“B”的一声，而且显示屏上显示1.25
* 正常显示1.25之后把你的校园卡拿下来，在1.25没消失之前把你的白卡放上去  
* 如果一切顺利那你到这一步应该可以开出热水了  
* 在把白卡1.25都刷完之后重复前面的步骤即可继续使用热水啦:laughing::laughing::laughing:  

## 此外  
* 水资源宝贵，还希望我们能**好好珍惜**这来之不易的热水  
* 这是个超级无敌简单的程序，**不要有用这个东西来改你饭卡余额等想法**  
* 这个白卡可以进图书馆，还可以借书亲测有效，但进了图书馆之后这张白卡貌似就被固定死了ID锁起来了，也就是变成了一张不可写入的卡。但刷过图书馆之后貌似洗澡的时候就不需要使用上面那些刷卡的步骤，直接把白卡放进去就有1.25这样子。好像是这个样子。:smiley:
* Enjoy!
