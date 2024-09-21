//Change Blynk Authentication Details
#define BLYNK_TEMPLATE_ID "TMPL3zKpj7wZG"
#define BLYNK_TEMPLATE_NAME "iot"
#define BLYNK_AUTH_TOKEN "cpYVGUwAbvUzLFeXzutx073ZMQSS10TY"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[]= BLYNK_AUTH_TOKEN;
char ssid[] = "TP-Link_C296"; // Enter your wifi name
char pass[] = "17731294"; // Enter your wifi password
int fire = D1;
int data;
int sound=D3;
BlynkTimer timer;
void sendSensor(){
int data = digitalRead(fire);
Blynk.virtualWrite(V0,"NO");
 if(data==1) // Change the Threshold value
 {
 Blynk.logEvent("iot","FIRE DETECTED");
 digitalWrite(sound,HIGH);
 Blynk.virtualWrite(V0,"YES");
 }
 if(data==0)
 {
 digitalWrite(sound,LOW);
 }
}
void setup(){
 pinMode(fire, INPUT);
 pinMode(sound,OUTPUT);
 Serial.begin(115200);
 Blynk.begin(auth, ssid, pass);
 timer.setInterval(2500L, sendSensor);
}
void loop(){
 Blynk.run();
 timer.run();
}
