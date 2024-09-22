// ServerFunctions.cpp

#include <WiFiClient.h>
#include "Constants.h"
#include "ServerFunctions.h"

float Estimate_Sleep_Duration() {
    WiFiClient client;
    if (!client.connect(host, port)) {
        Serial.println("Connection to server failed");
        return waterSupplyPerSecond * 3;
    }
    
    String jsonPayload = "{\"Soil Moisture\": " + String(soilMoisturePercentage) + ", \"Temperature\": " + String(temperature) + "}";
    client.print("POST /predictSoilMoistureDeclineTime HTTP/1.1\r\n");
    client.print(jsonPayload);
    
    while (client.connected() && !client.available()) {
        delay(1000);
    }
    
    String jsonResponse = "";
    while (client.available()) {
        char c = client.read();
        jsonResponse += c;
    }
    Serial.println(jsonResponse);
    
    float predictedDeclinePerMinute = jsonResponse.toFloat(); // Simplified parsing
    client.stop();
    
    return (soilMoisturePercentage - MOISTURE_LOWER_THRESHOLD) / predictedDeclinePerMinute * 60;
}

float Motor_Run_Time() {
    WiFiClient client;
    if (!client.connect(host, port)) {
        Serial.println("Connection to server failed");
        return 1;
    }
    
    int growthInSoilMoisture = MOISTURE_UPPER_THRESHOLD - soilMoisturePercentage;
    String jsonPayload = "{\"GrowthInSoilMoisture\": " + String(growthInSoilMoisture) + "}";
    
    client.print("POST /predictRequiredWater HTTP/1.1\r\n");
    client.print(jsonPayload);
    
    while (client.connected() && !client.available()) {
        delay(100);
    }
    
    String jsonResponse = "";
    while (client.available()) {
        char c = client.read();
        jsonResponse += c;
    }
    Serial.println(jsonResponse);
    
    float waterRequired = jsonResponse.toFloat(); // Simplified parsing
    client.stop();
    
    return waterRequired / waterSupplyPerSecond;
}
