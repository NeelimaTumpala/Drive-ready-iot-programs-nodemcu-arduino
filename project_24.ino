#include<LiquidCrystal.h>
LiquidCrystal LCD(11,10,7,6,5,4);
int i=1;
int j=10;
int opto=3;
void setup() {
pinMode(opto,OUTPUT);
LCD.begin(16,2);
}
void loop() {
while(i<500)
{
analogWrite(opto,i); //even though we haven't used any analog pins why we are using this meanswe are using a pwm pin and if w euse digital write we will not be able to mention two characters inside it 
LCD.setCursor(0,0);
LCD.print("motor is running");
LCD.setCursor(0,1);
LCD.print(i);
LCD.print(" ");
i=(i+1);
i=i*3;
j=250-i;
i=i+j;
delay(100);
}
delay(2000);
i=0;
}
