#include "System_Manager.h"
#include <iostream>

System_Manager::System_Manager() : systemRunning(false), criticalComponentsOK(false) {}

System_Manager* System_Manager::getInstance()
{
    static System_Manager instance;
    return &instance;
}

void System_Manager::startWorkingCycle()
{
    std::cout << "[SYSTEM] Starting working cycle.\n";

    checkCriticalComponents();

    if(!criticalComponentsOK)
    {
        std::cout << "[SYSTEM] ERROR: Cannot start. Critical components NOT OK.\n";
        systemRunning = false;
        return;
    }

    systemRunning = true;
}

void System_Manager::stopSystem()
{
    systemRunning = false;
    std::cout << "[SYSTEM] System stopped.\n";
}

void System_Manager::checkCriticalComponents()
{
    auto safety = Safety_Monitor::getInstance();
    safety->monitorDuringProcess();

    criticalComponentsOK = !safety->isCoverOpen() &&
                           !safety->isMotorBlocked() &&
                           !safety->isOverTemperature();

    std::cout << "[SYSTEM] Critical components "
              << (criticalComponentsOK ? "OK" : "FAILED") << "\n";
}

bool System_Manager::isSystemRunning() const 
{ 
    return systemRunning; 
}
bool System_Manager::areCriticalComponentsOK() const 
{ 
    return criticalComponentsOK; 
}





