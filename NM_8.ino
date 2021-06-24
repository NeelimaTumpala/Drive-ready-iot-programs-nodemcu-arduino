/* NodeMCU WiFi Connection
* Library: ESP8266WiFi
*/



#include <ESP8266WiFi.h> // Nodemcu WiFi library
#include <PubSubClient.h> // MQTT Library for nodemcu
#include <DHT.h>



#define clientid "dr_node01"
#define dhtpin 5 // nodemcu D1 pin or GPIO5
#define dhttype DHT11 // DHT Sensor




const char* ssid="ACTFIBERNET"; // WiFi Router username
const char* password="Happy@home"; // WiFi Router password
const char*mqttserver="broker.hivemq.com"; // MQTT Broker
int port =1883; // MQTT port number




WiFiClient espclient; // WiFiClient for Internet connection
PubSubClient client(espclient); // MQTT client for Data Transreciver with WiFiClient
DHT dht(dhtpin,dhttype); // define the variable with the pin and type



void setup_wifi()
{
Serial.print("WiFi Connect with the username of "); // print the ssid in Serial monitor
Serial.println(ssid);
WiFi.begin(ssid,password); // WiFi connect with username and password
while(WiFi.status()!=WL_CONNECTED) // WiFi connection check
{
Serial.print("....");
delay(200);
}



Serial.println("\n WiFi is Connected");
Serial.print("The IP: ");
Serial.println(WiFi.localIP()); // WiFi IP address display in Serial Monitor
}



void reconnectserver()
{
while(!client.connected()) // repeat the step until server connected
{
Serial.println("Attempting the MQTT Server Connection");
if(client.connect(clientid)) //check the clientid with server connection
{
Serial.println("Server Agian Connected");
}
}
}



void setup() {



Serial.begin(9600); // Serial Communication begin with buadrate of 9600
setup_wifi(); //WiFi Connection
dht.begin();
client.setServer(mqttserver,port); // set and connect the MQTT server




}



void loop() {
if(!client.connected()) // checking server connection
{
reconnectserver(); // call the function for reconnect the server
}



float temp,hum;
String message;
char msg[60];

temp=dht.readTemperature(); // Read the Temperature
hum=dht.readHumidity(); // Read the Humidity
message="Temp: "+String(temp)+ ", Hum: "+String(hum); // String conctation
Serial.println(message); // Print the message
message.toCharArray(msg,60); // String to Char Array conversion



client.publish("dr/iot/tm",msg); // Publish the data



delay(5000); //wait for 5 sec
}
