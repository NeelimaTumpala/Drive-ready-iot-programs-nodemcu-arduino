#include <DHT.h>
#include <DHT_U.h>

#define dhtpin 5
#define dhttype DHT11

DHT dht+sensor(dhtpin,dhttype);
float temp,hum;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht_sensor.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  temp=dht_sensor.readTemperature();
  hum=dht_sensor.readHumidity();
  Serial.print("The Temperature : ");
  Serial.print(temp);
  Serial.print("The humidity : ")
  Serial.print(hum);
  delay(1000);
  

}
