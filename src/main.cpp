#include <Arduino.h>
#include <Wire.h>

#include "AirSensor.hpp"
#include "DisplayManager.hpp"

// I2C pins
#define SDA_PIN 8
#define SCL_PIN 9

// Instance of the display
DisplayManager display;
// Instance of the SCD40 sensor
AirSensor airSensor;

void setup() {
    Serial.begin(115200);

    unsigned long start = millis();
    while (!Serial && (millis() - start < 4000)) {
        delay(10);
    }

    Wire.begin(SDA_PIN, SCL_PIN);

    if (!display.begin(0x3C)) {
        Serial.println("Error initializing OLED!");
    }

    display.showStatus("Init SCD40...");

    if (!airSensor.begin()) {
        Serial.println("Error initializing SCD40!");
        display.showStatus("SCD40 Error!");
    }

    display.showStatus("SCD40 Ready!");
}

void loop() {
    AirSensorData data;
    if (airSensor.readData(data))
    {
        Serial.printf("CO2: %d ppm | Temp: %.1f C | Hum: %.1f %%\n", data.co2, data.temperature, data.humidity);
        display.updateData(data.co2, data.temperature, data.humidity);
    }
    delay(1000);
}
