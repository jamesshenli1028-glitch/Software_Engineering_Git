#pragma once
#include "Safety_Monitor.h"

class System_Manager
{
private:
    bool systemRunning;
    bool criticalComponentsOK;

    System_Manager();
public:
    static System_Manager* getInstance();

    void startWorkingCycle();
    void stopSystem();
    void checkCriticalComponents();

    bool isSystemRunning() const;
    bool areCriticalComponentsOK() const;
};
