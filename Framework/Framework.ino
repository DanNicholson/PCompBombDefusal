#include <Servo.h>
#include <Key.h>
#include <Keypad.h>

Servo myServo

const int wireToCut = A0;
int successCounter = 0;
int failCounter = 0;
bool isCorrectCode = false;
bool isWireCut = false;

#define Password_Lenght 4 // Give enough room for six chars + NULL char

char Data[Password_Lenght]; // 6 is the number of chars it can hold + the null char = 7
char Master[Password_Lenght] = "1234"; 
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {
  2,3,4,5}; //connect to the row pinouts of the keypad (Change this as necessary)
byte colPins[COLS] = {
  10,9,8}; //connect to the column pinouts of the keypad (Change this as necessary)

Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); //initialize an instance of class NewKeypad 


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

   customKey = customKeypad.getKey();
  if (customKey) // makes sure a key is actually pressed, equal to (customKey != NO_KEY)
  {
    Data[data_count] = customKey; // store char into data array
    lcd.setCursor(data_count,1); // move cursor to show each new char
    lcd.print(Data[data_count]); // print char at said cursor
    data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
  }

  if(data_count == Password_Lenght-1) // if the array index is equal to the number of expected chars, compare data to master
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Password is ");

    if(!strcmp(Data, Master)) // equal to (strcmp(Data, Master) == 0)
      lcd.print("Good");
    else
      lcd.print("Bad");

    delay(1000);// added 1 second delay to make sure the password is completely shown on screen before it gets cleared.
    lcd.clear();
    clearData();   
  }

  if(isCorrectCode = true){
    successCounter = 2;
    myServo.write(); //Change this for whatever we need
  }

}

void clearData()
{
  while(data_count !=0)
  {   // This can be used for any array size, 
    Data[data_count--] = 0; //clear array for new data
  }
  return;
}
