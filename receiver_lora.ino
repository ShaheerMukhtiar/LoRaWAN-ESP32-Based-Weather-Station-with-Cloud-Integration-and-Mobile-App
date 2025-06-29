#include <SPI.h>
#include <LoRa.h>

#define ss 5
#define rst 14
#define dio0 2

void setup() {
  Serial.begin(115200);
  LoRa.setPins(ss, rst, dio0);

  while (!LoRa.begin(433E6)) {
    Serial.println("LoRa initialization failed. Retrying...");
    delay(500);
  }

  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initialized Successfully!");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    char receivedData[256];
    int index = 0;
    while (LoRa.available() && index < 255) {
      receivedData[index++] = (char)LoRa.read();
    }
    receivedData[index] = '\0';

    float temperature, humidity;
    int raindrop;
    sscanf(receivedData, "Temperature : %f C, Humidity : %f %%, Rain Value : %d", &temperature, &humidity, &raindrop);

    Serial.printf("Temp: %.1f C, Hum: %.1f%%, Rain: %d\n", temperature, humidity, raindrop);

    int rssi = LoRa.packetRssi();
    Serial.print("Signal Strength (RSSI): ");
    Serial.println(rssi);

    delay(5000);
  }
}
