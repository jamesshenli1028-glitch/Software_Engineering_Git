#pragma once
#include "DeviceInterface.h"

class Sealing_Manager : public DeviceInterface {
private:
    Sealing_Manager();
public:
    static Sealing_Manager* getInstance();
    void startDevice() override;
    void stopDevice() override;
    void startSealing();
};