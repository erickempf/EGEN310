#include <SPI.h>
#include <WiFiNINA.h>

#include <BlynkSimpleWiFiNINA.h>


char ssid[] = "Matrix";
char pass[] = "erickempf";
int keyIndex = 0;

int status = WL_IDLE_STATUS;
WiFiServer server(80);

String readString;

void setup() {
  pinMode(13,OUTPUT);   //left motors forward
  pinMode(12,OUTPUT);   //left motors reverse
  pinMode(11,OUTPUT);   //right motors forward
  pinMode(10,OUTPUT);   //right motors reverse
  Serial.begin(9600);

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(1000);
  }
  server.begin();

  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop() {
  WiFiClient client = server.available();
  if (client)
  {
    Serial.println("new client");

    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        if (readString.length() < 100)
        {
          readString += c;
          Serial.write(c);
          
          if (c == '\n') {
            client.println("<a href=\"/?forward\"\">Forward</a>");
            client.println("<br />");
            client.println("<br />");
            client.println("<a href=\"/?backward\"\">Backward</a><br />");   
            client.println("<br />");
            client.println("<br />");  
            client.println("<a href=\"/?stop\"\">Stop</a><br />");
            client.println("<br />");
            client.println("<br />");  
            client.println("<a href=\"/?left\"\">Left</a><br />");
            client.println("<br />");
            client.println("<br />");  
            client.println("<a href=\"/?right\"\">Right</a><br />");
            delay(1);
            
            if(readString.indexOf("?forward") > 0)
            {
              digitalWrite(13,HIGH);
              digitalWrite(11,HIGH);
              Serial.println("Forward");
              delay(1);
            }

            if(readString.indexOf("?backward") > 0)
            {
              digitalWrite(12,HIGH);
              digitalWrite(10,HIGH);
              Serial.println("Backward");   
              delay(1);
            }         

            if(readString.indexOf("?stop") > 0)
            {
              digitalWrite(13,LOW);
              digitalWrite(12,LOW);
              digitalWrite(11,LOW);
              digitalWrite(10,LOW);
              Serial.println("Stop");   
              delay(1);
            }     

            if(readString.indexOf("?left") > 0)
            {
              digitalWrite(11,HIGH);
              digitalWrite(12,HIGH);
              Serial.println("Left");   
              delay(1);
            }         

            if(readString.indexOf("?right") > 0)
            {
              digitalWrite(13,HIGH);
              digitalWrite(10,HIGH);
              Serial.println("Right");   
              delay(1);
            }         

            readString="";

            delay(1);
            client.stop();
          }
        }
      }
    }
  }
}
