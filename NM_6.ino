#include <ESP8266WiFi.h> // Nodemcu WiFi library
#include <PubSubClient.h> // MQTT Library for nodemcu



#define clientid "dr_node01"



const char* ssid="ACTFIBERNET"; // WiFi Router username
const char* password="Happy@home"; // WiFi Router password
const char*mqttserver="broker.hivemq.com"; // MQTT Broker
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
Serial.println("Server Agian Connected");
}
}
}



void setup() {



Serial.begin(9600); // Serial Communication begin with buadrate of 9600
setup_wifi(); //WiFi Connection
client.setServer(mqttserver,port); // set and connect the MQTT server




}



void loop() {
if(!client.connected()) // checking server connection
{
reconnectserver(); // call the function for reconnect the server
}



int rnum; // variable for random number
String message; // Message for String
char msg[50]; // Char Array Messgae

rnum=random(100); // random number generation
message="Drive Ready Class-"+String(rnum); // String conctation
Serial.println(message); // Print the message
message.toCharArray(msg,40); // String to Char Array conversion



client.publish("dr/iot/mqtt",msg); // Publish the data



delay(5000); //wait for 5 sec
}
