#include <Servo.h>
#include <Key.h>
#include <Keypad.h>

Servo myServo

const int wireToCut = 
int successCounter = 0;
int failCounter = 0;
bool isCorrectCode = false;
bool isWireCut = false;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(); //Change this for whatever we need
  myServo.write(0); //Change this for whatever we need

  if(isCorrectCode == false){
    myServo.write(90); //Change this for whatever we need
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  if(isCorrectCode = true){
    successCounter = 2;
    myServo.write(); //Change this for whatever we need
  }

}
