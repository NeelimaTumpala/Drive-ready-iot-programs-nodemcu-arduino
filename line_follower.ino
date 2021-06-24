#include <MotorDriver.h>


MotorDriver m;

int s1 = A0;
int s2 = A1;
int s3 = A2;
int s4 = A3;
int s5 = A4;
int s6 = A5;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int val1 = digitalRead(s1);
  int val2 = digitalRead(s2);
  int val3 = digitalRead(s3);
  int val4 = digitalRead(s4);
  int val5 = digitalRead(s5);
  int val6 = digitalRead(s6);
  // print out the state of the button:
  Serial.print(val1);
  Serial.print(" ");
  Serial.print(val2);
  Serial.print(" ");
  Serial.print(val3);
  Serial.print(" ");
  Serial.print(val4);
  Serial.print(" ");
  Serial.print(val5);
  Serial.print(" ");
  Serial.print(val6);
  Serial.println(" ");
// stright
if((val1==1 && val2==1 ) && (val3==0 && val4==0) && (val5==1 && val6==1))
{
  m.motor(4,FORWARD,200);//LEFT
  m.motor(1,FORWARD,200);  //RIGHT
}
// right turn
else if((val1==1 && val2==1 ) && (val3==0 && val4==0) && (val5==0 && val6==0))
{
  m.motor(4,FORWARD,200);
  m.motor(1,BACKWARD,200);  
}
//left turn
else if((val1==0 && val2==0 ) && (val3==0 && val4==0) && (val5==1 && val6==1))
{
  m.motor(4,BACKWARD,200);
  m.motor(1,FORWARD,200);  
}
// stop if ending
else if((val1==0 && val2==0 ) &&(val3==0 && val4==0) && (val5==0 && val6==0))
{
  m.motor(4,FORWARD,0);
  m.motor(1,FORWARD,0);  
}
}
