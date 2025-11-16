#pragma once

class Pressure_Service
{
private:
    float pressure = 1.0f; 

public:
    float getPressure() const 
    {
        return pressure;
    }

    void setPressure(float p)
    {
        pressure = p;
    }
};