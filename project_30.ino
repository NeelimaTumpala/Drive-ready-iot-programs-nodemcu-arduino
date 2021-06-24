#include<Wire.h>
#include<TimeLib.h>
#include<DS1307.h>
#include<LiquidCrystal.h>
int y=7,m=6,d=5,h=4,ms=3;

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int clock[7];
void setup()
{
pinMode(y,INPUT);
pinMode(m,INPUT);
pinMode(d,INPUT);
pinMode(h,INPUT);
pinMode(ms,INPUT);
// put your setup code here, to run once:
lcd.begin(16, 2);
DS1307.begin();
DS1307.setDate(21, 6, 2, 3, 9, 01,30);
}


void loop() {
int Y=digitalRead(y);
int M=digitalRead(m);
int D=digitalRead(y);
int H=digitalRead(h);
int MS=digitalRead(ms);

DS1307.getDate(clock);
lcd.setCursor(0, 0);
lcd.print("Time= ");
lcd.print(clock[4]);
lcd.print(":");
lcd.print(clock[5]);
lcd.print(":");
lcd.print(clock[6]);
lcd.setCursor(0, 1);
lcd.print("Date= ");
lcd.print(clock[0]);
lcd.print("/");
lcd.print(clock[1]);
lcd.print("/");
lcd.print(clock[2]);
// put your main code here, to run repeatedly:


if(Y==1)
{
clock[0]++;
DS1307.setDate(clock[0],clock[1],clock[2],clock[3],clock[4],clock[5],clock[6]);
}
if(M==1)
{
clock[1]++;
DS1307.setDate(clock[0],clock[1],clock[2],clock[3],clock[4],clock[5],clock[6]);
}
if(D==1)
{
clock[2]++;
DS1307.setDate(clock[0],clock[1],clock[2],clock[3],clock[4],clock[5],clock[6]);
}
if(H==1)
{
clock[4]++;
DS1307.setDate(clock[0],clock[1],clock[2],clock[3],clock[4],clock[5],clock[6]);
}
if(MS==1)
{ clock[5]++;
DS1307.setDate(clock[0],clock[1],clock[2],clock[3],clock[4],clock[5],clock[6]);
}
delay(500);
}
