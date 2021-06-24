#inlude <DHT.h>
#include <DHT_U.h>

#include<ESP8266WiFi.h>
#include<PubSubClient.h>

#define dhtpin 5
#define sensortype DHT11

#define clintid "node01"
const char *ssid="APFIBER_F930";
const char *PWD="0000009FE5";
const char *mqttserver="test.mosquitto.org";
int port = 1883;

DHT dht(dhtpin,sensortype);

WiFiClient espclient
PubSubClient client(espclient);

void setup_wifi(){
  Serial.print("WiFi Connected with": +String(ssid));
  WiFi.begin(ssid,pwd);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print("....");
    delay(300);  
  }
  Serial.print("\n WiFi Connected with IP:");
  Serial.println(WiFi.localIP());
  
}

void reconnect()
{
  while(!client.connected())
  {
    Serial.print("Attempting the MQTT Connection")
    if(client.connect(clientid))
    {
      Serial.println("MQTT Connected");
    }
  }
}

void setup() {
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqttserver.port);
  dht.begin();
  // put your setup code here, to run once:

}

void loop() {
  if(!client.connected())
  {
    reconnect();
    
  }
  float temp,hum;
  String temp_hum;
  char msg(40);


  temp=dht.readTemperature();
  hum=dht.readHumidity();
  temp_hum="temp="+String(temp)+",hum="+String(hum); //temp=32,hum=64
  temp_hum.toCharArray(msg,40);
  Serial.println(msg);
  client.publish("iot/dht/node1",msg);
  delay(5000);
  // put your main code here, to run repeatedly:

}
