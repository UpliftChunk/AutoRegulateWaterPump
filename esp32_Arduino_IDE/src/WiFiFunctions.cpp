// WiFiFunctions.cpp

#include <WiFi.h>
#include "Constants.h"
#include "WiFiFunctions.h"

void connectWiFi() {
    Serial.println("Attempting to connect to WiFi...");
    WiFi.begin(ssid, password);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 10) {
        delay(1000);
        Serial.println("Connecting...");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Connected to the WiFi network");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("Connection failed. Check your credentials.");
    }
}
