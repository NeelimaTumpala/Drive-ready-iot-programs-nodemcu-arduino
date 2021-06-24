/* NODEMCU BLINK PROGRAM*/
void setup() {
  // put your setup code here, to run once:
pinMode(D0,OUTPUT);
Serial.begin(9600);

}

void loop() {
  digitalWrite(D0,1);
  delay(1000);
  Serial.println("LED is on");
  digitalWrite(D0,1);
  delay(1000);
  Serial.println("LED is off");
  // put your main code here, to run repeatedly:

}
