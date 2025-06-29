# LoRaWAN-ESP32-Based-Weather-Station-with-Cloud-Integration-and-Mobile-App

A real-time, long-range weather monitoring and automation system using **ESP32-WROOM-32**, **LoRa communication**, and **ThingSpeak Cloud**. Designed for smart agriculture and environmental automation, this project collects temperature, humidity, and rainfall data, transmits it over LoRa, stores it in the cloud, and automates actuators based on environmental conditions.

---

## 📌 Features

- 🔁 **Dual-node Architecture**: Transmitter collects and sends sensor data; Receiver processes it and controls actuators.
- 📡 **Long-range LoRa Communication**: Reliable, low-power data transmission across wide areas.
- ☁️ **ThingSpeak Integration**: Real-time cloud storage, analytics, and API-based control.
- 🤖 **Actuator Automation**: Controls fan, water pump, and curtains using edge logic.
- 📱 **Android App Interface**: Built with MIT App Inventor for mobile visualization and control.

---

## 🧠 System Overview

- **Transmitter Node:**
  - ESP32 collects data from DHT11 and Raindrop sensor
  - Transmits data via LoRa to the receiver
  - Uploads same data to ThingSpeak for redundancy

- **Receiver Node:**
  - Receives LoRa data and/or fetches from ThingSpeak
  - Uses conditions to control actuators (servo motor, fan, pump)
  - Outputs data to serial monitor and logs responses

---

## 🛠️ Hardware Components

- ESP32-WROOM-32 x2  
- LoRa XL1278-SMT (Transmitter & Receiver)  
- DHT11 (Humidity & Temperature Sensor)  
- Raindrop Sensor  
- Servo Motor  
- Micro DC Motor + Propeller  
- 2-Channel 5V Relay Module  
- Breadboard, Wires, Power Supply

---

## 📦 Software Stack

- **Arduino IDE** – For programming ESP32s  
- **ThingSpeak** – For cloud data storage, analytics, and actuator control  
- **MIT App Inventor** – For building a custom Android dashboard  
- **LoRa Libraries (SPI, LoRa.h)** – For wireless transmission  
- **DHT.h** – For temperature/humidity sensor integration

---

## 💡 Working Principle

1. Transmitter node reads sensor values (temperature, humidity, rainfall)
2. Sends data over LoRa and uploads it to ThingSpeak
3. Receiver node:
   - Retrieves data from LoRa or ThingSpeak
   - Applies predefined thresholds to trigger actuators
   - Actuators (fan, pump, curtain motor) are activated via relay module
4. Data can be monitored on:
   - Serial Monitor
   - ThingSpeak dashboard
   - Android App (MIT App Inventor)

---

## 🔐 Cloud Integration (ThingSpeak)

- **Data Upload** (Transmitter):
  - Sends temperature, humidity, and rainfall to Fields 1, 2, 3 on ThingSpeak
- **Data Retrieval** (Receiver):
  - Uses ThingSpeak APIs to fetch latest values
  - Controls actuators accordingly

---

## 📱 Mobile Interface

The mobile app (built with MIT App Inventor):
- Displays real-time sensor data from ThingSpeak
- Plots historical trends (temperature, humidity, rainfall)
- Improves user accessibility and remote monitoring

---

## 🧪 Troubleshooting Highlights

- **LoRa Sync Issues**: Resolved by aligning transmission intervals
- **Sensor Inconsistencies**: Calibrated raindrop sensor for accurate readings
- **Data Parsing Errors**: Used robust string parsing with validation
- **Packet Loss**: Added redundancy by syncing LoRa and ThingSpeak data

---

## 📊 Performance Summary

| Feature            | Result                            |
|--------------------|-----------------------------------|
| LoRa Range         | ~2 km (line-of-sight)             |
| Data Sync Interval | 5–20 seconds                      |
| ThingSpeak Logging | 100% Success with retry logic     |
| Actuator Response  | <2 sec delay on valid thresholds  |
| Cloud Dashboard    | Real-time with historical charts  |

---

## 🚀 Future Improvements

- Integrate ML models for predictive weather-based control  
- Add soil moisture and light sensors for better crop management  
- Implement multi-node LoRa network for large-scale deployments  
- Transition to solar-powered operation for sustainability

---

## 👨‍💻 Contributors

- **Shaheer Mukhtiar**  
- **Shafla Rehman**  
- **Abeera Shahid**  
- **Areesha Batool**  
- **Khadija Zahra**  
- **Maria Butt**

---

## 📚 References

- [ThingSpeak Documentation](https://thingspeak.com/docs/)  
- [MIT App Inventor](https://appinventor.mit.edu/)  
- [ESP32-WROOM-32 Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf)  
- [LoRa by Semtech](https://www.semtech.com/lora/what-is-lora)

---

## 💼 Skills Highlighted

- Embedded Systems  
- Internet of Things (IoT)  
- Wireless Communication (LoRa)  
- Cloud Integration  
- Edge Computing  
- Automation Control  
- Mobile App Development

---
