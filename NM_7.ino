/* NodeMCU MQTT Receive the Data
* Library: ESP8266WiFi, PubSubClient
*
*/



#include <ESP8266WiFi.h> // Nodemcu WiFi library
#include <PubSubClient.h> // MQTT Library for nodemcu



#define clientid "dr_node01"



const char* ssid="ACTFIBERNET"; // WiFi Router username
const char* password="Happy@home"; // WiFi Router password
const char*mqttserver="test.mosquitto.org"; // MQTT Broker
int port =1883; // MQTT port number




WiFiClient espclient; // WiFiClient for Internet connection
PubSubClient client(espclient); // MQTT client for Data Transreciver with WiFiClient



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
client.subscribe("dr/iot/rmqtt"); // Again subscribe the topic
Serial.println("Server Agian Connected");
}
}
}



void callback(char topic, byte payload, unsigned int length)
{
Serial.print("Topic Name: ");
Serial.println(topic);
Serial.print("Message : ");
for(int i=0;i<length;i++)
{
Serial.print((char)payload[i]);
}
}




void setup() {



Serial.begin(9600); // Serial Communication begin with buadrate of 9600
setup_wifi(); //WiFi Connection
client.setServer(mqttserver,port); // set and connect the MQTT server
client.subscribe("dr/iot/rmqtt"); // Subscribe the topic
client.setCallback(callback); // set the callback function for message arraiving




}



void loop() {
if(!client.connected()) // checking server connection
{
reconnectserver(); // call the function for reconnect the server
}



client.loop(); // call the callback function when message is received from the other machine



// delay(5000); //wait for 5 sec
}
