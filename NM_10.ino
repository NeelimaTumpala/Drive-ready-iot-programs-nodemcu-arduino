#include<ESP8266WiFi.h>
const char ssid[]="anil";
const char pass[]="anil";
WiFiServer myhotspot(80);
String Request="";
String header="HTTP/1.1 200 OK\\r\nContent-Type:text/html\r\n\r\n";
String title="<!DOCTYPE html><html><head><title>Nodemcu LED Control</title></head></html><body><div id='main'><h2>Nodemcu led Control</h2>";
int led =LED_BUILTIN;
String body1="<form id ='F1' action='LEDON1'><input class='button'type='submit'value='LED1 ON'></form><br>";
String body2="<form id ='F2' action='LEDOFF1'><input class='button'type='submit'value='LED1 OFF'></form><br>";
String body3="<form id ='F3' action='LEDON2'><input class='button'type='submit'value='LED2 ON'></form><br>";
String body4="<form id ='F4' action='LEDOFF2'><input class='button'type='submit'value='LED2 OFF'></form><br>";
String body5="<form id ='F5' action='LEDON3'><input class='button'type='submit'value='LED3 ON'></form><br>";
String body6="<form id ='F6' action='LEDOFF3'><input class='button'type='submit'value='LED3 OFF'></form><br>";
String body7="<form id ='F7' action='LEDON3'><input class='button'type='submit'value='LED4 ON'></form><br>";
String body8="<form id ='F8' action='LEDOFF4'><input class='button'type='submit'value='LED4 OFF'></form><br>";
String tail="</div></body></html>";
String request="";



void setup() {
// put your setup code here, to run once:
Serial.begin(115200);
pinMode(led,OUTPUT);
boolean conn=WiFi.softAP(ssid,pass);
myhotspot.begin();
}



void loop() {
// put your main code here, to run repeatedly:
WiFiClient mobile=myhotspot.available();
if (!mobile){
return;
}

request=mobile.readStringUntil('\r');
if(request.indexOf("LEDON1")>0){
digitalWrite(led,1);

}if(request.indexOf("LEDOFF1")>0){
digitalWrite(led,0);

}
if(request.indexOf("LEDON2")>0){
Serial.println("LEDON2");

}
if(request.indexOf("LEDOFF2")>0){
Serial.println("LEDOFF2");

}
if(request.indexOf("LEDON3")>0){
Serial.println("LEDON3");

}
if(request.indexOf("LEDOFF3")>0){
Serial.println("LEDOFF3");

}
if(request.indexOf("LEDON4")>0){
Serial.println("LEDON4");

}if(request.indexOf("LEDOFF4")>0){
Serial.println("LEDOFF4");

}
mobile.flush();
mobile.print(header);
mobile.print(title);

mobile.print(body1);
mobile.print(body2);
mobile.print(body3);
mobile.print(body4);
mobile.print(body5);
mobile.print(body6);
mobile.print(body7);
mobile.print(body8);
mobile.print(tail);



delay(10);

}
