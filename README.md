# IoT-Based Boat Tracking System Using ESP8266 and KiwisIoT

## Project Overview
This project tracks a boat's real-time location using a NodeMCU ESP8266 and NEO-6M GPS module. It collects latitude, longitude, speed, and satellite information, then sends the location data to the KiwisIoT platform for remote monitoring.

## Hardware Components
- NodeMCU ESP8266
- NEO-6M GPS Module
- Jumper Wires
- Power Supply

## Software Requirements
- Arduino IDE
- ESP8266 Board Package
- KiwisIoT Arduino Library
- TinyGPS++ Library
- SoftwareSerial Library

## Circuit Connections

| GPS Module | ESP8266 |
|---|---|
| TX | D6 (GPS RX) |
| RX | D7 (GPS TX) |
| VCC | Suitable power supply |
| GND | GND |

## Working Principle
The GPS module receives satellite signals and provides the boat's geographical coordinates and movement speed. The ESP8266 processes the GPS data using the TinyGPS++ library.

Every 5 seconds, valid and recent GPS coordinates and speed are transmitted to the KiwisIoT platform. Satellite information is displayed in the Serial Monitor.

## KiwisIoT Dashboard

| Channel | Data |
|---|---|
| Channel 0 | Latitude |
| Channel 1 | Longitude |
| Channel 2 | Boat Speed (km/h) |

## Configuration
Update your Wi-Fi credentials and KiwisIoT Topic ID in the Arduino code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

Upload the code to the NodeMCU ESP8266 and monitor boat location and speed through the KiwisIoT dashboard.

## Applications
- Fishing boat location tracking
- Marine navigation monitoring
- Boat movement tracking
- Fleet monitoring
- IoT-based marine applications

## Project Blog
[Read the full project on Hackster.io](https://www.hackster.io/kirusokumar/iot-based-boat-tracking-system-using-esp8266-and-kiwisiot-b61d09)

## Recommended Platform
[KiwisIoT – IoT Monitoring Platform](https://www.kiwisiot.in/)

**Arduino Library:** https://github.com/Kiwistron/KiwisIoT

**Example Projects:** https://github.com/Kiwistron/KiwisIoT-Projects/tree/main

---
**Author:** Kirusokumar