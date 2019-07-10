# Family Feud Button
The component  to the [Family Feud Board](https://github.com/ebron-tech/FamilyFeud). 
Source code and instructions to create the button using arduino.
## Requirements
* Arduino nano.
* DFPlayer. (buy it [[us](https://www.dfrobot.com/index.php?route=product/product&product_id=1121)][[mx](https://articulo.mercadolibre.com.mx/MLM-651633119-mini-modulo-reproductor-mp3-arduino-cdmx-electronica-_JM?quantity=1)])
*  Massive Arcade Button  (buy it [[us](https://www.adafruit.com/product/1185)][[mx](https://articulo.mercadolibre.com.mx/MLM-651900661-3-botones-gigantes-blancos-led-10cm-arcade-98mm-maquinitas-_JM?quantity=1)])
* 1k ohm resistor.
* 10K ohm resistor.
* 3.5mm stereo audio jack (headphones).
* ULN2803
* 12v power supply.


#### Assemble as you require
You can follow the diagram and mount all the components for your need, in my case I used:
* 6x4cm board.
* USB jack (recycled from an old motherboard).

## DFPlayer
This is an mp3 player that can be triggered by Arduino, I used this because can play complex audios like music instead of using some Arduino generated audio wave, it's really cheap (found it at $2.5 USD) and has a lot of useful features like:
* Stereo output for speakers.
* Stereo output for headphones.
* Analog inputs to be used with buttons.
* USB pins ( in case of not using the micro SD card).
* Powerfull library capable of:
    * Trigger specific audios.
    * Set volume.
    * Small eq.
    * Next, prev song.
## Arduino Nano
Has the perfect size and performance and for this project (doesnt require too much).![](https://i.imgur.com/zTJCAat.jpg)

## ULN2803
Some people call it an H bridge, is used to convert the 5v Arduino output to 12v output commonly is used to power motors, led lights and anything that requires more voltage than the nominal power provided by Arduino.
the component it's inside this project to power Each arcade button that contains a 12v led, but also to control 2 channels of RGB led lights for the players, With a few fixes the Arduino could use the available PWD pins D3, D5, D6 and D9, D10, D11 in order to set the value for each color (one port per color per channel), The pins have to be connected to the 6 ULN2803 available spaces in order to get the complete 12v.

## Diagram 
![](https://i.imgur.com/iBsgPsa.jpg)

## References
* dummy question but i accept that i google it: https://www.arduino.cc/en/tutorial/button
* DFPlayer documentation: https://wiki.dfrobot.com/DFPlayer_Mini_SKU_DFR0299
* ULN2803 http://2.bp.blogspot.com/-Hqpv4xndQCc/T1_be_UMb4I/AAAAAAAABCc/pF-63NGLrnQ/s1600/uln2803.PNG

