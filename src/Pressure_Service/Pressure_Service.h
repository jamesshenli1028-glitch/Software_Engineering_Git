#pragma once

class Pressure_Service
{
private:
    float pressure;

    Pressure_Service() : pressure(1.0f) {}

public:
    static Pressure_Service* getInstance();

    float getPressure() const;
    void setPressure(float p);
};