/***************************************************
EBRON.TECH 2019 


Family feud table button script
Two buttons, the first one pressed generates a sound and the button blinks.
-Arduino nano.
-DFPlayer. https://www.dfrobot.com/index.php?route=product/product&product_id=1121
-2 Massive Arcade Button  https://www.adafruit.com/product/1185
-ULN2803
****************************************************/



 /***************************************************
 Using the library for DFPlayer.
 Created 2016-12-07
 By [Angelo qiao](Angelo.qiao@dfrobot.com)
 GNU License
 See <http://www.gnu.org/licenses/> for details.
 ****************************************************/


#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(7, 8); // RX, TX //10 11
DFRobotDFPlayerMini myDFPlayer;
const int buttonLeft = 4;      //The Left  Arcade button pin
const int buttonRight = 2;     //The Right Arcade button pin
const int ledLeft =  12;       //The Left  LED pin
const int ledRight =  13;      //The Right LED pin
int buttonStateLeft = 0; 
int buttonStateRight = 0; 

//Player side contans the pins for the button and led, audio index and blinkStatus
struct playerSide
 {
     int led;
     int button;
     int audio;
     int blinkState;
 };
typedef struct playerSide PlayerSide;
playerSide rightSide,leftSide,pressedSide;
//States contains the states for each event.
enum States{
  idle, //waiting to be pressed
  buttonPressed, // when the one of the buttons is pressed
  buttonBlink,   // blinking for a few seconds before return to idle status. 
  
};
States state;

void setup()
{
  //Init DFPlayer
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
  }else{
    Serial.println(F("DFPlayer Mini online."));  
  }
  //Set Volume and test with one sound.
  myDFPlayer.volume(20);  //Set volume value. From 0 to 30
  myDFPlayer.play(0);  //Play the first mp3
  
  //Set pins leds and button.
  pinMode(ledRight, OUTPUT);
  pinMode(ledLeft, OUTPUT);
  pinMode(buttonLeft, INPUT);
  pinMode(buttonRight, INPUT);

  //init playerSide objects:
  leftSide.led = ledLeft;
  leftSide.button = buttonLeft;
  leftSide.audio=1;
  
  rightSide.led = ledRight;
  rightSide.button = buttonRight;
  rightSide.audio=2;
  
  //init state:idle
  state=idle;
}

void loop()
{
  static unsigned long timer = millis();
  static unsigned long blinkTimer = millis(); 

  switch(state){
    case idle:
      buttonStateRight = digitalRead(buttonRight);
      buttonStateLeft = digitalRead(buttonLeft);
      if(buttonStateRight==HIGH){
        state=buttonPressed;
        pressedSide=rightSide; 
      }
      if(buttonStateLeft==HIGH){
        state=buttonPressed;
        pressedSide=leftSide; 
      }
      break;
    case buttonPressed:
      myDFPlayer.play(pressedSide.audio);
      state= buttonBlink;
      timer = millis();
      break;
    case buttonBlink:
      //Blink Timer
      if (millis() - blinkTimer > 300) {
        blinkTimer  = millis();
        pressedSide.blinkState=(pressedSide.blinkState==HIGH)?LOW:HIGH;
        digitalWrite(pressedSide.led,pressedSide.blinkState);
      }
      //Exit Timer:
      if (millis() - timer > 4000) {
        pressedSide.blinkState=LOW;
        digitalWrite(pressedSide.led,LOW);
        state=idle;
      }
      break;
    
  }
}
