#pragma once

class Temperature_Service
{
private:
    float currentTemperature;

    Temperature_Service() : currentTemperature(25.0f) {}

public:
    static Temperature_Service* getInstance();

    float getTemperature() const;
    void setTemperature(float temp);
};