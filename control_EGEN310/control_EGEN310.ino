#define BLYNK_PRINT Serial
#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>

char auth[ ] = "Ov_pFAbxwUiRUTKKMYCqOVPzkpmvFAhh";   //auth key

char ssid[ ] = "Matrix";                //network name
char pass[ ] = "erickempf";             //network password

BlynkTimer timer;

BLYNK_WRITE(V4) //Increment forward by 50ms
{
  int pinValue = param.asInt();
  if (pinValue > 0) {
    digitalWrite(13,HIGH);
    digitalWrite(11,HIGH);
    delay(50);
    digitalWrite(13,LOW);
    digitalWrite(11,LOW);
    Serial.println("Inc");
  }
}

BLYNK_WRITE(V5) //Increment left by 50 ms
{
  int pinValue = param.asInt();
  if (pinValue > 0) {
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    delay(50);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    Serial.println("NL");
  }
}

BLYNK_WRITE(V6)   //Increment right by 50ms
{
  int pinValue = param.asInt();
  if (pinValue > 0) {
    digitalWrite(13,HIGH);
    digitalWrite(10,HIGH);
    Serial.println("Right");
    delay(50);
    digitalWrite(13,LOW);
    digitalWrite(10,LOW);
    Serial.println("NR");
  }
}

BLYNK_WRITE(V1) //Forward
{
  int pinValue = param.asInt();
  if (pinValue > 0) {
    digitalWrite(13,HIGH);
    digitalWrite(11,HIGH);
    Serial.println("Forward");
  }
  else{
    digitalWrite(13,LOW);
    digitalWrite(11,LOW);
    Serial.println("NF");
  }
}

BLYNK_WRITE(V0) //Backward
{
  int pinValue = param.asInt();
  if (pinValue > 0) {
    digitalWrite(12,HIGH);
    digitalWrite(10,HIGH);
    Serial.println("Backward");
  }
  else{
    digitalWrite(12,LOW);
    digitalWrite(10,LOW);
    Serial.println("NB");
  }
}

BLYNK_WRITE(V3) //Left
{
  int pinValue = param.asInt();
  if (pinValue > 0) {
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    Serial.println("Left");
  }
  else{
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    Serial.println("NL");
  }
}

BLYNK_WRITE(V2) //Right
{
  int pinValue = param.asInt();
  if (pinValue > 0) {
    digitalWrite(13,HIGH);
    digitalWrite(10,HIGH);
    Serial.println("Right");
  }
  else{
    digitalWrite(13,LOW);
    digitalWrite(10,LOW);
    Serial.println("NR");
  }
}
void setup()
{
  pinMode(13,OUTPUT);   //left motors forward
  pinMode(12,OUTPUT);   //left motors reverse
  pinMode(11,OUTPUT);   //right motors forward
  pinMode(10,OUTPUT);   //right motors reverse
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

//In the loop function include Blynk.run() command.
void loop()
{
  Blynk.run();
  timer.run();
}
