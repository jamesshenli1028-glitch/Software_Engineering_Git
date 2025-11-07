#pragma once

// Adaptor model

class DeviceInterface // Abstraktion der unterhierachischen Werkzeugen
{
public:
    virtual void startDevice() = 0;
    virtual void stopDevice() = 0;
};

class Vakuum_Manager : public DeviceInterface // nicht voellig Adaptor, noch Singlton
{
private:
    static Vakuum_Manager* instance;
    float currentPressure;
    float targetPressure;
    Vakuum_Manager() : currentPressure(0.0f), targetPressure(0.0f){}
public:
    static Vakuum_Manager* getInstance()
    {
        if(instance == nullptr)
            instance = new Vakuum_Manager();
        return instance;
    }

    void startDevice() override{}
    void stopDevice() override{}

    void startVakuuming(){ startDevice(); }
    void stopVakuuming(){ stopDevice(); }
    float monitorPressure(){ return PressureService::getInstance()->getPressure(); } 
    //noch nicht erfuellt werden

    void setCurrentPressure(float pressure) { currentPressure = pressure;}
    void setTargetPressure(float pressure) { targetPressure = pressure;}
};

Vakuum_Manager* Vakuum_Manager::instance = nullptr;




