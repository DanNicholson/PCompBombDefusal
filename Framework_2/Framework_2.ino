#include <Password.h>
#include <Keypad.h>
#include <Servo.h> 

Servo myServo;
Password password = Password( "0000" ); //password to unlock, can be changed | we could make it a six digit code and have the password be "215132". B=2 O=15 M=13 B=2

int successCounter = 0;
int failCounter = 0;

bool isCodeCorrect = false;
bool isWireCut = false;

const int wireToCut = A0; //set this to whatever pin you need
int wireState = 0;

const byte ROWS = 4; // Four rows
const byte COLS = 3; // columns
// Defining the Keymap
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 9, 8, 7, 6 };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 5, 4, 3 };


// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  //  Serial.begin(9600);
  //  Serial.write(254);
  //  Serial.write(0x01);
  //  delay(200); 
  //  pinMode(11, OUTPUT);  //green light
  //  pinMode(12, OUTPUT);  //red light
    myServo.attach(13); //servo on digital pin 9 //servo
    keypad.addEventListener(keypadEvent); //event listener for this keypad
}

void loop(){
  keypad.getKey();
  myservo.write(0); //Change this to whatever it needs to be
  
  if(wireToCut == LOW){
    isWireCut = true;
    successCounter + 3;
  }

  if(successCounter = 4 && isCorrectCode = true && isWireCut = true){

    //Put in code for win state or whatever here
  }

  if(failCounter => 3){

    //put fail state here
    
  }
}


  //taking care of some special events
  void keypadEvent(KeypadEvent eKey){
    switch (keypad.getState()){
  //  case PRESSED:
  //  
  //  Serial.print("Enter:");
  //  Serial.println(eKey);
  //  delay(10);
  //  
  //  Serial.write(254);
    
      switch (eKey){
        case '*': checkPassword(); delay(1); break; //* checks the password
        
        case '#': password.reset(); delay(1); break; //# resets the password allowing to start again
        
        default: password.append(eKey); delay(1);
      }
  }
}


void checkPassword(){
  
  if (password.evaluate()){  //if password is right, open
  
      //Serial.println("Accepted");
      //Serial.write(254);delay(10);
      //Add code to run if it works
      isCorrectCode = true;
      successCounter = 1;
      
      myservo.write(150); //change as see fit
      
      
  }else{

      //Serial.println("Denied"); //if passwords wrong, keep locked
      //Serial.write(254);delay(10);
      //add code to run if it did not work

      failCounter++;
      myservo.write(0); //change as see fit
    
  }
}
