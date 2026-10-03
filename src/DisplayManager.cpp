#include "DisplayManager.hpp"

DisplayManager::DisplayManager(uint8_t width, uint8_t height) 
    : display(width, height, &Wire, -1), _width(width), _height(height) {}

bool DisplayManager::begin(uint8_t i2cAddress) {
    if (!display.begin(SSD1306_SWITCHCAPVCC, i2cAddress)) {
        return false;
    }
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.display();
    return true;
}

void DisplayManager::showStatus(const char* message) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 10);
    display.println(message);
    display.display();
}

void DisplayManager::updateData(uint16_t co2, float temperature, float humidity) {
    display.clearDisplay();
    
    // Header
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("AIR QUALITY MONITOR");
    display.drawLine(0, 10, _width, 10, SSD1306_WHITE);

    // CO2
    display.setTextSize(2);
    display.setCursor(20, 18);
    display.printf("%d", co2);
    display.setTextSize(1);
    display.setCursor(70, 24);
    display.println("ppm CO2");

    // Temp and humidity at the bottom
    display.setCursor(0, 48);
    display.printf("TEMP: %.1fC  HUM: %.0f%%", temperature, humidity);

    display.display();
}
