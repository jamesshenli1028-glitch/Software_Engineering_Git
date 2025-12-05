#pragma once
#include "DeviceInterface.h"

class SealingManager : public DeviceInterface
{
private:
    bool sealingActive;
    float sealingTimeMs;

    SealingManager();

public:
    static SealingManager* getInstance();

    void startDevice() override;
    void stopDevice() override;

    void startSealing();
    void stopSealing();
    void controlSealing(); 
};
