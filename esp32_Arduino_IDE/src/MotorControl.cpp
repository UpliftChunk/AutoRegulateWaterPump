#include <Arduino.h>  // Include Arduino core for ESP32

#include "Constants.h"  

void turnOnMotor() {
    digitalWrite(MOTOR_SWITCH_PIN, HIGH);
    Serial.println("Motor turned on.");
}

void turnOffMotor() {
    digitalWrite(MOTOR_SWITCH_PIN, LOW);
    Serial.println("Motor turned off.");
}
