#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11
#define RAINDROP_PIN 34

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";
const char* server = "http://api.thingspeak.com/update";
String apiKey = "YOUR_API_KEY";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi Connected.");
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int rainValue = analogRead(RAINDROP_PIN);

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  HTTPClient http;
  String url = server + "?api_key=" + apiKey + 
               "&field1=" + String(humidity) + 
               "&field2=" + String(temperature) + 
               "&field3=" + String(rainValue);

  http.begin(url);
  int httpCode = http.GET();
  http.end();

  Serial.println("Data sent to ThingSpeak.");
  delay(20000); // 20 seconds
}
