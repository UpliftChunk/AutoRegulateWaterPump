// Constants.h

#ifndef CONSTANTS_H
#define CONSTANTS_H

// WiFi credentials
extern char ssid[33];
extern char password[65];

// Sensor pins
#define DHTPIN 33       // Pin for DHT11
#define DHTTYPE DHT11   // DHT11 type
#define SOIL_MOISTURE_PIN 32
#define MOTOR_SWITCH_PIN 2

// Moisture thresholds
#define MOISTURE_UPPER_THRESHOLD 70
#define MOISTURE_LOWER_THRESHOLD 20

// Server details
extern const char* host;
extern const int port;

// Global variables
extern float soilMoisturePercentage;
extern float temperature;
extern float humidity;
extern int waterSupplyPerSecond;

#endif
