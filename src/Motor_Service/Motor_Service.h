#pragma once

class Motor_Service
{
private:
    bool pumpRunning = false;
    bool heaterRunning = false;

public:

    void setPumpe(bool on)
    {
        pumpRunning = on;
    }

    void setHeater(bool on)
    {
        heaterRunning = on;
    }

    bool isPumpRunning() const { return pumpRunning; }
    bool isHeaterRunning() const { return heaterRunning; }
};