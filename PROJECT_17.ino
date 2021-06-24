/*
* ----------------------------------
LDR to A0
push button to A1
Pir sensor to A3



------------------------------------
13- led
12-RS
11-EN
10-D4
09-D5
08-D6
07-D7
-------------------------------------
C1-6,C2-5,C3-4
R1-3
R2-2
R3-1
R4-0

*/
#include<Keypad.h>
#include<LiquidCrystal.h>
int led=13;
int stat=1;
LiquidCrystal lcd(12,11,10,9,8,7);
const byte rc=4;
const byte cc=3;
char keys[rc][cc]={
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rows[rc]={3,2,1,0};
byte cols[cc]={6,5,4};
Keypad mykey(makeKeymap(keys),rows,cols,rc,cc);



int pass_length=7;
char master_password[7]="123456";
char data[7];
byte dc=0,mc=0;
char key;
bool door=false;



void setup()
{
pinMode(led,OUTPUT);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("PASSWORD BASED");
lcd.setCursor(0,1);
lcd.print("Door Lock SSTM");
delay(2000);
lcd.clear();
}



void loop()
{
if(stat==0)
{
int a=analogRead(A0);//LDR
int b=analogRead(A1);// SWITCH
int c=digitalRead(16);//PIR SENSOR
lcd.clear();
lcd.setCursor(0,0);
lcd.print(a);
lcd.print(" ");
lcd.print(b);
lcd.print(" ");
lcd.print(c);
lcd.print(" ");
delay(1000);





}




if (door==0)
{
key=mykey.getKey();
if(key=='#')
{
digitalWrite(led,0);
lcd.print("Door was closed");
delay(1000);
stat=1;
door=1;

}

}



else
{
lcd.setCursor(0,0);
lcd.print("Enter Password");

key=mykey.getKey();
if(key)
{
data[dc] =key;
lcd.setCursor(dc,1);
lcd.print(data[dc]);
dc=dc+1;
}
if(dc==pass_length-1)
{
if(!strcmp(data,master_password))
{
lcd.clear();
digitalWrite(led,1);
lcd.print("Access Granted");
stat=0;
delay(2000);
door=0;
lcd.clear();
while(dc!=0)
{
data[dc]=0;
dc--;
}
}
else
{
lcd.clear();
digitalWrite(led,0);
lcd.print("Access Dinied");
stat=1;
delay(2000);
door=1;
lcd.clear();
while(dc!=0)
{
data[dc]=0;
dc--;
}
}

}






}




}
