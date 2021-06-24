#include<Wire.h>
#include<TimeLib.h>
#include<DS1307.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int clcok[7];
void setup() {
// put your setup code here, to run once:
lcd.begin(16, 2);
DS1307.begin();
DS1307.setDate(21, 6, 2, 3, 9, 01,30);



}



void loop() {
DS1307.getDate(clcok);
lcd.setCursor(0, 0);
lcd.print("Time= ");
lcd.print(clcok[4]);
lcd.print(":");
lcd.print(clcok[5]);
lcd.print(":");



lcd.print(clcok[6]);
// put your main code here, to run repeatedly:



}
