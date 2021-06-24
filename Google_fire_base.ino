
//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h" // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>
//#include <DHT.h> // Install DHT11 Library and Adafruit Unified Sensor Library
#define FIREBASE_HOST "iotgfb-c025c-default-rtdb.firebaseio.com " //Without http:// or https:// schemes
#define FIREBASE_AUTH "DzFFqOGHrhqRC7i9lZXIPCZi9WL3jY3YQVFn0qz4"
#define WIFI_SSID "APFIBER_F930"
#define WIFI_PASSWORD "0000009FE5"
//#define DHTPIN 5 // Connect Data pin of DHT to D2
int led = D5; // Connect LED to D5
//#define DHTTYPE DHT11
//DHT dht(DHTPIN, DHTTYPE);
//Define FirebaseESP8266 data object
FirebaseData firebaseData;
FirebaseData ledData;
FirebaseJson json;
void setup()
{
Serial.begin(9600);
//dht.begin();
pinMode(led,OUTPUT);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("Connecting to Wi-Fi");
while (WiFi.status() != WL_CONNECTED)
{
Serial.print(".");
delay(300);
}
Serial.println();
Serial.print("Connected with IP: ");
Serial.println(WiFi.localIP());
Serial.println();
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Firebase.reconnectWiFi(true);
}
void sensorUpdate()
{
// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float h = 50;
// Read temperature as Celsius (the default)
float t = 30;



Serial.print(F("Humidity: "));
Serial.print(h);
Serial.print(F("% Temperature: "));
Serial.print(t);



if (Firebase.setFloat(firebaseData, "/IOTGFB/temperature", t))
{
Serial.println("PASSED");
Serial.println("PATH: " + firebaseData.dataPath());
Serial.println("TYPE: " + firebaseData.dataType());
Serial.println("ETag: " + firebaseData.ETag());
Serial.println("------------------------------------");
Serial.println();
}
else
{
Serial.println("FAILED");
Serial.println("REASON: " + firebaseData.errorReason());
Serial.println("------------------------------------");
Serial.println();
}
if (Firebase.setFloat(firebaseData, "/IOTGFB/humidity", h))
{
Serial.println("PASSED");
Serial.println("PATH: " + firebaseData.dataPath());
Serial.println("TYPE: " + firebaseData.dataType());
Serial.println("ETag: " + firebaseData.ETag());
Serial.println("------------------------------------");
Serial.println();
}
else
{
Serial.println("FAILED");
Serial.println("REASON: " + firebaseData.errorReason());
Serial.println("------------------------------------");
Serial.println();
}
}
void loop() {
sensorUpdate();
if (Firebase.getString(ledData, "/IOTGFB/led")){
Serial.println(ledData.stringData());
if (ledData.stringData() == "1") {
digitalWrite(led, HIGH);
}
else if (ledData.stringData() == "0"){
digitalWrite(led, LOW);
}
}
delay(100);
}
