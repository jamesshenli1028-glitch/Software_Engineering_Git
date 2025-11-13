#include "System_Manager.h"

System_Manager* System_Manager::instance = nullptr;

void System_Manager::startWorkingCycle() // F-START-1
{
    systemRunning = true;
    criticalComponentsOK = false;
}

void System_Manager::stopSystem() // F-START-2
{
    systemRunning = false;
}

void System_Manager::checkCriticalComponents() // F-START-3
{
    if(systemRunning)
    {
        criticalComponentsOK = true;
    }
    else
    {
        criticalComponentsOK = false;
        //will do it in Sprint2
    }
}
