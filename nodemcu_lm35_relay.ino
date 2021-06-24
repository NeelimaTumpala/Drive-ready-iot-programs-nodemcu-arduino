//using lm35 to display temperature in serial monitor

float vref=3.3;
float resolution=vref/1023;

void setup() {
Serial.begin(9600);
Serial.println(F("DHTxx test!"));
pinMode(16,OUTPUT);
pinMode(4,OUTPUT);
pinMode(0,OUTPUT);
pinMode(2,OUTPUT);


}

void loop() {
float temp=analogRead(A0);
temp=(temp*resolution);
temp=temp*100;
Serial.print("Temperature=");
Serial.println(temp);

 digitalWrite(16,1);
digitalWrite(4,1);
digitalWrite(0,1);
digitalWrite(2,1);
delay(1000);
digitalWrite(16,0);
digitalWrite(4,0);
digitalWrite(0,0);
digitalWrite(2,0);
delay(1000);
}
