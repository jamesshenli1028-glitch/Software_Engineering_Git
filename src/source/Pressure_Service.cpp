#include "Pressure_Service.h"

Pressure_Service* Pressure_Service::getInstance()
{
    static Pressure_Service instance;
    return &instance;
}

float Pressure_Service::getPressure() const
{
    return pressure;
}

void Pressure_Service::setPressure(float p)
{
    pressure = p;
}