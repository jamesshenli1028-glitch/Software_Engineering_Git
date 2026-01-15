#pragma once
#include "DeviceInterface.h"

class Vakuum_Manager : public DeviceInterface {
private:
    Vakuum_Manager();
public:
    static Vakuum_Manager* getInstance();
    void startDevice() override;
    void stopDevice() override;
    void startVakuuming(); // Ä£Äâ½µÑ¹¹ý³Ì
};