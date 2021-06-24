const int currentPin = A0;
int sensitivity = 66;
int adcValue= 0;
int offsetVoltage = 2500;
double adcVoltage = 0;
double currentValue = 0;

void setup()
{
Serial.begin(9600);



}

void loop()
{
adcValue = analogRead(currentPin);
adcVoltage = (adcValue / 1024.0) * 5000;
currentValue = ((adcVoltage - offsetVoltage) / sensitivity);



Serial.print("\t Voltage(mV) = ");
Serial.print(adcVoltage);

Serial.print("\t Current = ");
Serial.println(currentValue);
delay(1000);



}
