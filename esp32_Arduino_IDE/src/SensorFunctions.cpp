// SensorFunctions.cpp

#include "Constants.h"
#include "SensorFunctions.h"


#define DHTPIN 33     // Pin for DHT11
#define DHTTYPE DHT11  // DHT11 type

DHT dht(DHTPIN, DHTTYPE);

void readSensorData() {
    int soilMoisture = analogRead(SOIL_MOISTURE_PIN);
    Serial.print("Soil Moisture: ");
    Serial.println(soilMoisture);

    soilMoisturePercentage = map(soilMoisture, 3500, 4095, 100, 0);
    Serial.print("Soil Moisture Percentage: ");
    Serial.println(soilMoisturePercentage);

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        humidity = 0;
        temperature = 40;
        Serial.println("Failed to read from DHT sensor!");
    }

    Serial.print("Temperature: ");
    Serial.println(temperature);
}
