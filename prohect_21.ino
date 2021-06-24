void setup() {

pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);
}
void loop() {
// put your main code here, to run repeatedly:
int a =analogRead(A0);
//FROM 0 TO 1023
// from 0 TO 255
float b=255 /1023;
b=b*a;
// 10/5 * 4 =8
//a=b;
Serial.println(a);
//delay(100);
analogWrite(10,a);
digitalWrite(9,0);




}
