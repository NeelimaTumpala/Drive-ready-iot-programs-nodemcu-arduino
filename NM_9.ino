#include<ESP8266WiFi.h>

// nodemcu hotspot creds
const char Hotspot_Name []="NodeMcu110";
const char Password[]="12345678";

//Http server
WiFiServer myhotspot(80);

String request="";
int led=LED_BUILTIN;

String header="HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
String title="<!DOCTYPE html><html><head><title>NODEMCU LED CONTROL</title></head></html><body><div id='main'><h2>NODEMCU LED CONTROL</h2>";
String body1="<form id='F1' action='LEDON'><input class='button' type='submit' value='LED ON'></form><br>";
String body2="<form id='F2' action='LEDOFF'><input class='button' type='submit' value='LED OFF'></form><br>";
String tail="</div></body></html>";

void setup()
{
pinMode(led,OUTPUT);
boolean conn=WiFi.softAP(Hotspot_Name,Password);
myhotspot.begin();
}

void loop()
{
WiFiClient mobile=myhotspot.available();
if(!mobile)
{
return;
}

 request=mobile.readStringUntil('\r');
if(request.indexOf("LEDON")>0)
{
digitalWrite(led,1);
}
if(request.indexOf("LEDOFF")>0)
{
digitalWrite(led,0);
}
mobile.flush();
mobile.print(header);
mobile.print(title);
mobile.print(body1);
mobile.print(body2);
mobile.print(tail);
delay(10);
}
