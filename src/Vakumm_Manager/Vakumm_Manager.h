
#pragma once
#include "DeviceInterface.h"

class Vakuum_Manager : public DeviceInterface
{
private:
    float currentPressure;
    float targetPressure;
    Vakuum_Manager();
public:
    static Vakuum_Manager* getInstance();

    void startDevice() override;
    void stopDevice() override;

    void startVakuuming();
    void stopVakuuming();

    void setTargetPressure(float p);
    float monitorPressure() const;
    bool isTargetPressureReached() const;
};
