#include "AirSensor.hpp"

AirSensor::AirSensor()
{
}

bool AirSensor::begin()
{
    _scd4x.begin(Wire, 0x62);
    _scd4x.stopPeriodicMeasurement();
    uint16_t error = _scd4x.startPeriodicMeasurement();
    return (error == 0);
}

bool AirSensor::readData(AirSensorData &outData)
{
    bool isDataReady = false;
    uint16_t error = _scd4x.getDataReadyStatus(isDataReady);

    if (!error && isDataReady)
    {
        error = _scd4x.readMeasurement(outData.co2, outData.temperature, outData.humidity);
        if (!error && outData.co2 > 0)
        {
            outData.valid = true;
            return true;
        }
    }
    outData.valid = false;
    return false;
}
