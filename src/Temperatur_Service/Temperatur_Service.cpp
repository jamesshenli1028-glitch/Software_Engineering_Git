#include "Temperature_Service.h"

Temperature_Service* Temperature_Service::getInstance()
{
    static Temperature_Service instance;
    return &instance;
}

float Temperature_Service::getTemperature() const 
{ 
    return currentTemperature; 
}

void Temperature_Service::setTemperature(float temp) 
{ 
    currentTemperature = temp; 
}