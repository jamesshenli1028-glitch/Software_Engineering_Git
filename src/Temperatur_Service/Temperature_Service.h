#pragma once

class Temperature_Service
{
private:
    float currentTemperature = 25.0f; 

public:
    float getTemperature() const
    {
        return currentTemperature;
    }

    void setTemperature(float temp)
    {
        currentTemperature = temp;
    }
};