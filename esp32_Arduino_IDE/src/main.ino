#include "Constants.h"
#include "WiFiFunctions.h"
#include "SensorFunctions.h"
#include "MotorControl.h"
#include "ServerFunctions.h"
#include <WiFi.h>

void setup() {
    Serial.begin(115200);
    dht.begin();

    pinMode(SOIL_MOISTURE_PIN, INPUT);
    pinMode(MOTOR_SWITCH_PIN, OUTPUT);
    connectWiFi();
}

void loop() {
    readSensorData();

    if (WiFi.status() == WL_CONNECTED) {
        if (soilMoisturePercentage > MOISTURE_LOWER_THRESHOLD) {
            float sleepDuration = Estimate_Sleep_Duration();
            delay(sleepDuration * 1000);
        } else {
            turnOnMotor();
            while (MOISTURE_UPPER_THRESHOLD > soilMoisturePercentage) {
                float requiredWater = Motor_Run_Time();
                delay(requiredWater * 1000);
                readSensorData();
            }
            turnOffMotor();
        }
    } else {
        connectWiFi();
    }
    delay(1000);
}
