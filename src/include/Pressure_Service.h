#pragma once

class Pressure_Service {
private:
    float pressure;
    Pressure_Service() : pressure(1.0f) {} // 初始为 1.0 bar (大气压)
public:
    static Pressure_Service* getInstance();
    float getPressure() const;
    void setPressure(float p);
};