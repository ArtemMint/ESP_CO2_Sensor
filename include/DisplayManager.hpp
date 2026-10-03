#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class DisplayManager {
public:
    DisplayManager(uint8_t width = 128, uint8_t height = 64);
    bool begin(uint8_t i2cAddress = 0x3C);
    void showStatus(const char* message);
    void updateData(uint16_t co2, float temperature, float humidity);

private:
    Adafruit_SSD1306 display;
    uint8_t _width;
    uint8_t _height;
};

#endif
