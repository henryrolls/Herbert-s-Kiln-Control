#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//////////////
// System Vars

unsigned long Time;

///////////
// LCD Vars

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

int LCDColumns = 20;
int LCDRows = 4;

///////////
// I/O Vars

int analogReadPin = 3;     // potentiometer wiper (middle terminal) connected to analog pin 3
int digitalWritePin = 9;

int buttonPins[] = {2,3,4,5,6,7,8,9,10};
bool buttonStates[8];

////////////
// Kiln Vars

int CurrentTemp;
int DeltaTemp;

enum KilnStates {
  Kiln_Initialising,
  Kiln_Ready,
  Kiln_Toasting,
  Kiln_Cooling,
  Kiln_Safe,
  Kiln_Error
};

enum KilnStates KilnEvents[] = { Kiln_Initialising };


////////
// Setup

void setup() {

  SetupIO();

}


//////////////////
// Setup Functions

void SetupIO() {
  //Serial.begin(9600);                 //  setup serial
  pinMode(digitalWritePin, OUTPUT);   // sets the digital pin as output

  lcd.begin(LCDColumns,LCDRows); 
}

////////////
// Main Loop

void loop() {
  Time = millis();
  if ( CheckEvents() ) {
    UpdateDisplay();
    UpdateKiln();
  }
  //RunKiln(String State);
}

//////////////////////
// Main Loop Functions

bool CheckEvents() {
  bool Updated = false;
  if (KilnEvents.length > 0) {
    Updated=true;
  }
  return Updated;
}

void UpdateDisplay() {

  lcd.setCursor(5,0);
  lcd.print("Main Menu");
  
}

void UpdateKiln() {

  
}


////////////////////////////////////////////////////




  



void WriteTitleRow(int Row, String Title, String Align) {
  int Column = 0;
  if (Align=="Left") {
    Column = 0;
  } else if (Align="Center") {
    Column = (LCDColumns/2)-(Title.length()/2);
  } else if (Align="Right") {
    Column = LCDColumns - Title.length();
  }
  lcd.setCursor(Column,Row);
  lcd.print(Title);
}

void WriteVariableRow(int Row, String Label, int Current) {
  
}

void WriteButtonsRow(int Row, String LeftLabel, String RightLabel) {

  
}

void mainmenuLCD()
{

 
  lcd.setCursor(5,0);
  lcd.print("Main Menu");

  
  lcd.setCursor(8,1);
  lcd.print("CREATE PROG>");
  lcd.setCursor(10,2);
  lcd.print("LOAD PROG>");
  lcd.setCursor(11,3);
  lcd.print("SETTINGS>");

 
}

void mainmenuLCDorig()
{

 
  lcd.setCursor(5,0);
  lcd.print("Main Menu");

  
  lcd.setCursor(0,1);
  lcd.print("<");
  lcd.setCursor(3,1);
  lcd.print("Create Program");
  lcd.setCursor(19,1);
  lcd.print(">");

  lcd.setCursor(14,3);
  lcd.print("ENTER>");
 
}

void createprogLCD()
{

  lcd.setCursor(0,0);
  lcd.print("<");  
  lcd.setCursor(5,0);
  lcd.print("Segment 01");
  lcd.setCursor(19,0);
  lcd.print(">");
  lcd.setCursor(0,1);
  lcd.print("<");
  lcd.setCursor(3,1);
  lcd.print("Target =");
  lcd.setCursor(12,1);
  lcd.print("1050c");
  lcd.setCursor(19,1);
  lcd.print(">");
  lcd.setCursor(0,2);
  lcd.print("<");
  lcd.setCursor(1,2);
  lcd.print("Duration =");
  lcd.setCursor(12,2);
  lcd.print("02h 45m");
  lcd.setCursor(19,2);
  lcd.print(">");
  lcd.setCursor(0,3);
  lcd.print("<BACK");
  lcd.setCursor(15,3);
  lcd.print("DONE>");
 
}


void confirmprogLCD()
{

  lcd.setCursor(4,0);
  lcd.print("New Program");

  lcd.setCursor(0,2);
  lcd.print("<CANCEL");
  lcd.setCursor(15,2);
  lcd.print("FIRE>");
  
  lcd.setCursor(0,3);
  lcd.print("<EDIT");
  lcd.setCursor(15,3);
  lcd.print("SAVE>");
 
}

void saveprogLCD()
{

  lcd.setCursor(0,0);
  lcd.print("Enter program name..");

  lcd.setCursor(0,1);
  lcd.print("<");
  lcd.setCursor(3,1);
  lcd.print("A_____________");
  lcd.setCursor(19,1);
  lcd.print(">");
  
  lcd.setCursor(0,2);
  lcd.print("<DOWN");
  lcd.setCursor(17,2);
  lcd.print("UP>");

  lcd.setCursor(0,3);
  lcd.print("<BACK");
  lcd.setCursor(15,3);
  lcd.print("SAVE>");
 
}

void progsavedLCD()
{
  lcd.setCursor(1,0);
  lcd.print("BISQUE FIRE01");

  lcd.setCursor(1,1);
  lcd.print("Saved in slot 04");

  
  lcd.setCursor(0,3);
  lcd.print("<MAIN MENU");
  lcd.setCursor(15,3);
  lcd.print("FIRE>");
}

void firingLCD()
{
  lcd.setCursor(0,0);
  lcd.print("< C 1002c");
  lcd.setCursor(11,0);
  lcd.print("T 1000c >");

  lcd.setCursor(0,1);
  lcd.print("<finish:");
  lcd.setCursor(11,1);
  lcd.print("04:55:07>");

  
  lcd.setCursor(0,2);
  lcd.print("< SOAKING Segment2 >");
  
  lcd.setCursor(15,3);
  lcd.print("MENU>");
}

