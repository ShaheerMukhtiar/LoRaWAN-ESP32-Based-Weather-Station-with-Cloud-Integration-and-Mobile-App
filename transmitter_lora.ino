#include <SPI.h>
#include <LoRa.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11
#define RAINDROP_PIN 34

#define ss 5
#define rst 14
#define dio0 2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  LoRa.setPins(ss, rst, dio0);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initialized Successfully!");
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int rainValue = analogRead(RAINDROP_PIN);

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from sensors!");
    return;
  }

  LoRa.beginPacket();
  LoRa.print("Temperature : ");
  LoRa.print(temperature);
  LoRa.print("C, Humidity : ");
  LoRa.print(humidity);
  LoRa.print("%, Rain Value : ");
  LoRa.print(rainValue);
  LoRa.endPacket();

  Serial.println("Data sent via LoRa.");
  delay(5000);
}
