#pragma once

class Motor_Service
{
private:
    bool pumpRunning;
    bool heaterRunning;

    Motor_Service();

public:
    static Motor_Service* getInstance();

    void setPumpe(bool on);
    void setHeater(bool on);

    bool isPumpRunning() const;
    bool isHeaterRunning() const;
};