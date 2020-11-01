#include<LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
int DataCheck = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(9,INPUT);
pinMode(10,INPUT);
pinMode(11,OUTPUT);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
   
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
 
int high9 = 0,high10 = 0;

void loop() 
{  if(Serial.available())
  {
    char data = Serial.read();
    Serial.print(data);
    Serial.print("      ======== >      ");
    
    if(data == '1'){DataCheck = 1; digitalWrite(3, HIGH); Serial.println("light on");}
    if(data == '2'){DataCheck = 1; digitalWrite(4, HIGH); Serial.println("fan on");}
    if(data == '3'){DataCheck = 1; digitalWrite(5, HIGH); Serial.println("night lamp on");} 
    if(data == '4'){DataCheck = 1; digitalWrite(3, LOW); Serial.println("light off");}
    if(data == '5'){DataCheck = 1; digitalWrite(4, LOW); Serial.println("fan off");}
    if(data == '6'){DataCheck = 1; digitalWrite(5, LOW); Serial.println("night lamp off");}
    if(data == '7'){DataCheck = 1; digitalWrite(6, HIGH); digitalWrite(5, HIGH); digitalWrite(6, HIGH); Serial.println("all on");}
    if(data == '8'){DataCheck = 1; digitalWrite(6, LOW); digitalWrite(5, LOW); digitalWrite(6, LOW); Serial.println("all off");}
    if(DataCheck == 0){Serial.println("Perintah Salah. Silakan ulangi !!! ");}
    Serial.println();
    DataCheck = 0;
  }
  
 if(Serial.available()>0){

 }
 if(digitalRead(9)==1 && high9 ==0){
  Serial.print(91);
  high9 = 1;
 }
 else if(digitalRead(9)==0 && high9 == 1){
  Serial.print(90);
  high9 = 0;
 }
 else if(digitalRead(10)==1 && high10 ==0){
  Serial.print(101);
  high10 = 1;
 }
 else if(digitalRead(10)==0 && high10 == 1){
  Serial.print(100);
  high10 = 0;
 }
}
