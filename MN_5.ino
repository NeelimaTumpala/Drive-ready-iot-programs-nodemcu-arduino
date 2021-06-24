/* NodeMCU WiFi Connection
* Library: ESP8266WiFi
*/



#include <ESP8266WiFi.h> // Nodemcu WiFi library



const char* ssid="APFIBER_F930"; // WiFi Router username
const char* password="0000009FE5"; // WiFi Router password



void setup() {



Serial.begin(9600); // Serial Communication begin with buadrate of 9600
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
void loop()
{
  
}
