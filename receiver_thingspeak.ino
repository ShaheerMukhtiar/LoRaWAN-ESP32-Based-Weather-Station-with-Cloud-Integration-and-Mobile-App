#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";
WiFiClient client;

unsigned long channelID = YOUR_CHANNEL_ID;
const char* readAPIKey = "YOUR_READ_API_KEY";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi Connected.");
}

void loop() {
  float humidity = ThingSpeak.readFloatField(channelID, 1, readAPIKey);
  float temperature = ThingSpeak.readFloatField(channelID, 2, readAPIKey);
  int rainValue = ThingSpeak.readFloatField(channelID, 3, readAPIKey);

  Serial.printf("Humidity: %.2f%%, Temperature: %.2f°C, Rain Value: %d\n", humidity, temperature, rainValue);
  delay(20000);
}
