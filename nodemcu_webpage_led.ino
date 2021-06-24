#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h> 

const char* ssid = "AndroidAP";
const char* password = "password123";

ESP8266WebServer server(80);
char temp[400];
void handleRoot() 
{
  snprintf(temp, 400,
"<html>\
  <head>\
  </head>\
    <body>\ 
       <h1>LED Automation</h1>\
       <a href =\"/1\"> <button onclick=\"alert('Turn ON the LED ?')\"style=\"/font-family:century gothic;color:White;font-size:20px;background-color:Green;\">LED ON</button></a>\
       <a href =\"/0\"> <button onclick=\"alert('Turn OFF the LED ?')\" style=\"/font-family:century gothic;color:White;font-size:20px;background-color:Red;\">LED OFF</button></a>\
       </body>\
</html>");
  server.send(200, "text/html", temp);
}


void ledOn() 
{
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
  delay(1000);
  server.send(200, "text/html", temp);
}

void ledOff() 
{
  pinMode(16, OUTPUT);
  digitalWrite(16, HIGH);
  delay(1000);
  server.send(200, "text/html", temp);
}


void setup()
{

  Serial.begin(9600);
  Serial.println("WiFi Connect with username of ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);   // Connect to WiFi network

  while (WiFi.status() != WL_CONNECTED)
  {   
    
    
    Serial.print("....");
    delay(200);
  }

  Serial.println("\n WiFi Connected to ");
  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); //To display WiFi IP Address

  server.on("/", handleRoot);
  server.on("/0", ledOff);
  server.on("/1", ledOn);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void)
{
  server.handleClient();
}
