#pragma once

class Motor_Service
{
private:
    bool pumpRunning;
    bool heaterRunning;

public:
    Motor_Service();

    void setPumpe(bool on);
    void setHeater(bool on);

    bool isPumpRunning() const;
    bool isHeaterRunning() const;
};