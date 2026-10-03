#ifndef AIRSENSOR_HPP
#define AIRSENSOR_HPP

#include <SensirionI2cScd4x.h>

struct AirSensorData
{
    uint16_t co2{0};
    float temperature{0.0f};
    float humidity{0.0f};
    bool valid{false};
};

class AirSensor
{
public:
    AirSensor();
    bool begin();
    bool readData(AirSensorData &data);

private:
    SensirionI2cScd4x _scd4x;
};

#endif
