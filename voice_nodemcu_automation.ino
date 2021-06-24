#include<ESP8266WiFi.h>

const char* ssid="AndroidAP";
const char* pass="password123";

WiFiClient client;
WiFiServer server(80);

String req;
void setup()
{
pinMode(16,OUTPUT);
Serial.begin(115200);
WiFi.begin(ssid,pass);
Serial.print("Connecting to...");
Serial.println(ssid);
while (!(WiFi.status()==WL_CONNECTED))
{
Serial.print(".");
delay(100);
}
Serial.print("Wifi has been Connected with");
Serial.print(WiFi.localIP());
Serial.println();

 server.begin();
}

void loop()
{
client = server.available();
if(!client)
{
return;
}

 String req1=client.readStringUntil('\r');
req1.remove(0, 5);
req1.remove(req1.length()-9,9);
req=req1;

 if(req=="on")
{
digitalWrite(16,0);
}
if(req=="off")
{digitalWrite(16,1);
}

 client.println("HTTP/1.1 200 OK");
client.println("Content-type: text/html");
client.println("");
client.println("<DOCTYPE HTML>");
client.println("<html>");
client.println(req);
client.println("</html>");
client.stop();
delay(5);
req="";

}
