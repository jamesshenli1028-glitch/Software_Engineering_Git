#pragma once
#include <iostream>

// Singleton model

class Safety_Monitor
{
private:
    static Safety_Monitor* instance;
    Safety_Monitor(){};

    Safety_Monitor(const Safety_Monitor&) = delete;
    Safety_Monitor& operator=(const Safety_Monitor&) = delete;

    bool coverOpen = false;         
    bool motorBlocked = false;      
    float temperature = 25.0f;

public:
    static Safety_Monitor* getInstance()
    {
        if(instance == nullptr)
            instance = new Safety_Monitor();
        return instance;
    }

    bool isCoverOpen() const { return coverOpen; }
    bool isMotorBlocked() const { return motorBlocked; }
    bool isOverTemperature() const { return temperature > 80.0f; }

    void updateCoverState(bool v) { coverOpen = v; }
    void updateMotorState(bool v) { motorBlocked = v; }
    void updateTemperature(float t) { temperature = t; }

    void monitorTemperature(){} // F-SICHERHEIT-1 
    void monitorCover(){} // F-SICHERHEIT-2 
    void monitorMotorBlock(){} // F-SICHERHEIT-3
    void emergencyShutdown();

};

