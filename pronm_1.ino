// program to connect wifi to node mcu
#include<ESP8266WiFi.h>

const char *ssid="AndroidAP342C";
const char *pwd="hhmv1487";
void setup() {
  Serial.begin(9600);
  Serial.println("WiFi Connection with "+String(ssid));//WiFi connection with ACTFIBERNET
  WiFi.begin(ssid,pwd);//WiFi connection with SSID and password
  while(WiFi.status()!=WL_CONNECTED)//WiFi Status Checking
  {
    Serial.print("****");
    delay(300);
  }
  Serial.println("*\n WiFi connected with IP address:"); //WiFi connected and display the IP address
  Serial.println(WiFi.localIP());
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
