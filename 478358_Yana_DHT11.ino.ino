#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
String apiKey = "QG173Q9U5E6F4SQH";
const char *ssid = "ayin";
const char *pass = "yanadayinta";
const char *server = "api.thingspeak.com";
#define DHTPIN D7
DHT dht(DHTPIN, DHT11);
WiFiClient client;
unsigned long myChannelNumber = 2068859;
const char *myWriteAPIKey = "QG173Q9U5E6F4SQH";
void setup() {
  Serial.begin(115200);
  delay(10);
  dht.begin();
  Serial.println("Connecting ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
}
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Sensor Tidak Dapat Mendeteksi");
    return;
  }
  ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
  delay(100);
  //ThingSpeak.read();
}