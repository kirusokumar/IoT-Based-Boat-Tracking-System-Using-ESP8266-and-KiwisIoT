#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <KiwisIoT.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// GPS Pins
#define GPS_RX D6
#define GPS_TX D7

SoftwareSerial gpsSerial(GPS_RX, GPS_TX);

TinyGPSPlus gps;

KiwisIoT kiwisiot(ssid, pass, topic);

unsigned long previousMillis = 0;

void setup() {

  Serial.begin(115200);
  gpsSerial.begin(9600);

  Serial.println("Boat Tracking System Started");

  kiwisiot.begin();
}

void loop() {

  kiwisiot.run();

  // Read GPS data
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  // Send data every 5 seconds
  if (millis() - previousMillis >= 5000) {

    previousMillis = millis();

    if (gps.location.isValid() &&
        gps.location.age() < 5000) {

      double latitude = gps.location.lat();
      double longitude = gps.location.lng();

      double speed = gps.speed.kmph();

      Serial.println("---- BOAT LOCATION ----");

      Serial.print("Latitude: ");
      Serial.println(latitude, 6);

      Serial.print("Longitude: ");
      Serial.println(longitude, 6);

      Serial.print("Speed: ");
      Serial.print(speed);
      Serial.println(" km/h");

      Serial.print("Satellites: ");
      Serial.println(gps.satellites.value());

      // Send data to KiwisIoT
      kiwisiot.send("0", String(latitude, 6));
      kiwisiot.send("1", String(longitude, 6));
      kiwisiot.send("2", String(speed, 2));

    } else {

      Serial.println("Waiting for GPS Signal...");

    }
  }
}