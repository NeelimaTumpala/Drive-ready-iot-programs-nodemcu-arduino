#include <DHT.h>
#include <DHT_U.h>

#define dhtpin 5
#define dhttype DHT11

DHT dht+sensor(dhtpin,dhttype);
float tempc,hum,tempf;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht_sensor.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  tempc=dht_sensor.readTemperature();
  hum=dht_sensor.readHumidity();
  tempf=dht_sensor.readTemperature(true);
  Serial.print("The Temperature (C): ");
  Serial.print(tempc);
  Serial.print("The Temperature (F): ");
  Serial.print(tempf);
  Serial.print("The humidity : ")
  Serial.print(hum);
  delay(3000);
  

}
