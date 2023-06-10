#include <ThingSpeak.h> 
#include <ESP8266WiFi.h> 
const char* ssid = "ayin";
const char* password = "12345678";
const char * myCounterWriteAPIKey = "VEI3WQ5AMNWR6XEG";
unsigned long channel = 2051625;
unsigned int led1 = 1;
unsigned int led2 = 2;
WiFiClient client;
void setup() {
 Serial.begin(9600);
 delay(100);
 pinMode(D4, OUTPUT);
 pinMode(D5, OUTPUT);
 digitalWrite(D4, 0);
 digitalWrite(D5, 0);
 Serial.println();
 Serial.println();
 Serial.print("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
 Serial.print("Netmask: ");
 Serial.println(WiFi.subnetMask());
 Serial.print("Gateway: ");
 Serial.println(WiFi.gatewayIP());
 ThingSpeak.begin(client);
}
void loop(){
 int led_1 = ThingSpeak.readFloatField(channel, led1,
myCounterWriteAPIKey);
 int led_2 = ThingSpeak.readFloatField(channel, led2,
myCounterWriteAPIKey);

 if(led_1 == 1){
 digitalWrite(D4, 1);
 Serial.println("D4 is On..!");
 }
if(led_1 == 0){
 digitalWrite(D4, 0);
 Serial.println("D4 is Off..!");
 }
 if(led_2 == 1){
 digitalWrite(D5, 1);
 Serial.println("D5 is On..!");
}
 if(led_2 == 0){
 digitalWrite(D5, 0);
 Serial.println("D5 is Off..!");
 }
 Serial.println(led_1);
 Serial.println(led_2);
 delay(500);
}