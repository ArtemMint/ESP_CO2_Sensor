# ESP CO2 Sensor

ESP32-C3 firmware for an indoor air-quality monitor using a Sensirion SCD4x
CO2 sensor and an SSD1306 OLED display. The device displays CO2 concentration,
temperature, and relative humidity, and prints readings to the serial monitor.

## Hardware

- ESP32-C3 DevKitM-1
- Sensirion SCD40/SCD4x CO2 sensor
- SSD1306 128x64 I2C OLED display
- Jumper wires

The sensor and display share the I2C bus:

| ESP32-C3 pin | Connection |
| --- | --- |
| GPIO 8 | SDA on the sensor and display |
| GPIO 9 | SCL on the sensor and display |
| 3V3 | Sensor/display power, according to their board specifications |
| GND | Common ground |

The firmware uses I2C address `0x62` for the SCD4x sensor and `0x3C` for the
display by default. Confirm your module's voltage requirements before wiring.

## Build and upload

Install [PlatformIO Core](https://docs.platformio.org/en/latest/core/index.html)
or the PlatformIO IDE extension for VS Code. Open this directory as a
PlatformIO project; dependencies are declared in `platformio.ini` and will be
installed by PlatformIO.

From the project directory, use the PlatformIO CLI:

```sh
pio run
pio run --target upload
pio device monitor --baud 115200
```

If more than one device is connected, specify the serial port with
`--upload-port` and `--port`, respectively.

## Project layout

- `src/` — firmware implementation and Arduino entry point
- `include/` — project headers
- `lib/` — location for project-specific PlatformIO libraries
- `test/` — location for PlatformIO tests
- `platformio.ini` — board, framework, build flags, and library dependencies

## License

No license has been selected for this project yet. Until one is added, the
default copyright protections apply.
