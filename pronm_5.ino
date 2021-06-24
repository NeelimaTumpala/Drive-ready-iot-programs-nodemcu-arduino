#include <DHT.h>
#include <DHT_U.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define dht 5
#define sensortype DHT11

const char *ssid = "";
const char *pwd = "";

DHT dht(dhtpin,sensortype);
WiFiClient client;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("WiFi Connect with the "+String(ssid));
  WiFi.begin(ssid,pwd);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print("...");
    delay(300);
    
  }
  Serial.print("\n WiFi Connected and IP: ");
  Serial.println(WiFi.localIP());
    
  // put your setup code here, to run once:

}

void loop() {
  String url="";
  float temp,hum;
  temp=dht.readTemperature();
  hum=dht.readHumidity();
  url +="field1="+String(temp)+""
  // put your main code here, to run repeatedly:

}
