float vref=3.3;
float resolution=vref/1023;
void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {
  float temperature = analogRead(A0);
  temperature = (temperature*resolution);
  temperature = temperature*100;
  Serial.println(temperature);
  delay(1000);
  // put your main code here, to run repeatedly:

}
