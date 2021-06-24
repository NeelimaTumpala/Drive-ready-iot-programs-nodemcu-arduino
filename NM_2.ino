/* SERIAL COMMUNICATION BETWEEN NODEMCU AND SYSTEM*/

void setup() {
  Serial.begin(57600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char response=Serial.read();   // use "int response=serial.parseInt()" if u want use integers
    Serial.println(response);
    if(response=='a' || response=='A')
    {
      digitalWrite(16,0);
      
    }
  else
  {
    digitalWrite(16,1)
  }
  delay(1000);
  }

}
