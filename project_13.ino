#include<Keypad.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(5,4,3,2,1,0);
const byte rp=4;
const byte cp=3;
char keys[rp][cp]=
{
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rows[rp]={13,12,11,10};
byte cols[cp]={9,8,7};
Keypad mykey(makeKeymap(keys),rows,cols,rp,cp);
int led=6;
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
if (door==0)
{
key=mykey.getKey();
if(key=='#')
{
digitalWrite(led,0);
lcd.print("Door was closed");
delay(1000);
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
