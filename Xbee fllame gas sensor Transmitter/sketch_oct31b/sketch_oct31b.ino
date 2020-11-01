#include <Keypad.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'7','8','9', '/'},
  {'4','5','6','x'},
  {'1','2','3','-'},
  {'*','0','#','+'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int KeyCheck = 0;

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop(){
  char key = keypad.getKey();

  if (key)
  {
    if(key == '1'){KeyCheck = 1; Serial.print("1"); lcd.setCursor(0,2);
      lcd.print("Alarm Active");}
    if(key == '2'){KeyCheck = 1; Serial.print("2"); lcd.setCursor(0,2);
      lcd.print("Sprinkle Active");}
    if(key == '3'){KeyCheck = 1; Serial.print("3"); lcd.setCursor(0,2);
      lcd.print("Buzzer Active");}
    
    if(key == '4'){KeyCheck = 1; Serial.print("4"); lcd.setCursor(0,2);
      lcd.print("Alarm Non Active");}
    if(key == '5'){KeyCheck = 1; Serial.print("5"); lcd.setCursor(0,2);
      lcd.print("Sprinkle Non Active");}
    if(key == '6'){KeyCheck = 1; Serial.print("6"); lcd.setCursor(0,2);
      lcd.print("Buzzer Non Active");}

    if(KeyCheck == 0){Serial.print(key);}
    KeyCheck = 0; 
  }
  
  if (key != NO_KEY){
    Serial.print(key);
  }
  if(Serial.available()>0){
    int k = Serial.parseInt();
    if(k == 91){
      lcd.setCursor(0,0);
      lcd.print("GAS DETECTED");
    }
    else if(k == 90){
      lcd.setCursor(0,0);
      lcd.print("GAS NOT DETECTED");
    }
    else if(k == 101){
      lcd.setCursor(0,0);
      lcd.print("FLAME DETECTED");
    }
    else if(k == 100){
      lcd.setCursor(0,0);
      lcd.print("FLAME NOT DETECTED");
    }
  }
}
