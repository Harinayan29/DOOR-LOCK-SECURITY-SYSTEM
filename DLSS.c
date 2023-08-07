#include<SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE "srdoor-fb9bf-default-rtdb.firebaseio.com"
#define WIFI_SSID "dooriot"
#define WIFI_PASSWORD "dooriot01"
int buz=D8;
int ir=D2;
int relay=D1;
int i,j,k,l,u,d,v,l_v,lc_v;
int m,n,o,p,y,z,g,r_v;
int q,r,s,t,L,temp_v;
void setup() 
{
Serial.begin(115200);
pinMode(buz,OUTPUT);
pinMode(relay,OUTPUT);
pinMode(ir,INPUT);
digitalWrite(buz,LOW);
digitalWrite(relay,LOW);
WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
 Serial.print("Connecting");
 while(WiFi.status() != WL_CONNECTED)
 {
 Serial.print(".");
 delay(500);
 }
 Serial.println();
 Serial.print("connected: ");
 Serial.println(WiFi.localIP());
digitalWrite(relay,LOW);
 }
void loop() 
{
 if(Firebase.failed())
 {
 Serial.print("Firebase error");
 Serial.println(Firebase.error());
 } 
 Serial.print("IR:");
 Serial.println(digitalRead(ir));
 
 if(Firebase("DOORLOCK/DOOR") == "\"OPEN\"")
 {
 Serial.println("OPEN"); 
digitalWrite(relay,HIGH);
 }
 if(Firebase("DOORLOCK/DOOR") == "\"CLOSE\"")
 {
lc_v=0;
 Serial.println("CLOSE"); 
digitalWrite(relay,LOW);
 }
 if(Firebase("DOORLOCK/DOOR") == "\"LOCK\"")
 {
 Serial.println("LOCK"); 
lc_v=1;
 l_v=1; 
digitalWrite(relay,LOW);
 } 
 if(Firebase("DOORLOCK/DOOR") == "\"UNLOCK\"")
 {
Serial.println("UNLOCK"); 
l_v=0; 
lc_v=0;
digitalWrite(buz,LOW); 
 } 
 
 if(Firebase("DOORLOCK/DOOR") == "\"ALERTON\"")
 {
Serial.println("ALKERTON"); 
digitalWrite(buz,HIGH); 
}
 if(Firebase("DOORLOCK/DOOR") == "\"ALERTOFF\"")
 {
 Serial.println("ALKERTOFF"); 
digitalWrite(buz,LOW); 
 }
if((!digitalRead(ir)) && (lc_v==1))
{
digitalWrite(buz,HIGH);
Serial.println("ALERT"); 
Serial.write('A'); 
if(r_v==0)
{
}
r_v++;
delay(500);
}
}
