#include<LiquidCrystal.h>
//int led =13;
int pir=8;
LiquidCrystal screen(6,5,3,2,1,0);
void setup() {
//pinMode(led,OUTPUT);
pinMode(pir,INPUT);
// put your setup code here, to run once:

screen.begin(16,2);


}



void loop() {
int data=digitalRead(pir);
if(data==1)
{
screen.setCursor(0,0);
screen.print(" 1 is detected  ");

}



if(data==0)
{
screen.setCursor(0,0);
screen.print("not detected");


}
// put your main code here, to run repeatedly:



}
