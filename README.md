# Family Feud Button
The add on component to the [Family Feud Board](https://github.com/ebron-tech/FamilyFeud). 
Source code and instructions to create the button using arduino.
## Requirements
* Arduino nano.
* DFPlayer. (buy it [[us](https://www.dfrobot.com/index.php?route=product/product&product_id=1121)][[mx](https://articulo.mercadolibre.com.mx/MLM-651633119-mini-modulo-reproductor-mp3-arduino-cdmx-electronica-_JM?quantity=1)])
*  Massive Arcade Button  (buy it [[us](https://www.adafruit.com/product/1185)][[mx](https://articulo.mercadolibre.com.mx/MLM-651900661-3-botones-gigantes-blancos-led-10cm-arcade-98mm-maquinitas-_JM?quantity=1)])
* 1k ohm resistor.
* 10K ohm resistor.
* 3.5mm stereo audio jack (headpohones).
* ULN2803
* 12v power supply.


#### Assable as you require
You can follow the diagram and mount all the components for your need, in my case i used:
* 6x4cm board.
* Usb jack (recicled from an old motherboard).

## DFPlayer
This is a mp3 player that can be triggered by arduino, i used this because can play complex audios like music insted of using some arduino generated audio wave, it's really cheap (found it at $2.5 usd) and has a lot of usefull features like:
* Stereo output for speakers.
* Stereo output for headphones.
* Analog inputs to be used with buttons.
* USB pins ( in case of not using th micro SD card).
* Powerfull library capable of:
    * Trigger specific audios.
    * Set volume.
    * Small eq.
    * Next, prev song.


## references
* dummy question buy i accept that i google it: https://www.arduino.cc/en/tutorial/button
* DFPlayer documentation: https://wiki.dfrobot.com/DFPlayer_Mini_SKU_DFR0299
* ULN2803 http://2.bp.blogspot.com/-Hqpv4xndQCc/T1_be_UMb4I/AAAAAAAABCc/pF-63NGLrnQ/s1600/uln2803.PNG
*