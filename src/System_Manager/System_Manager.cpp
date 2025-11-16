#include "System_Manager.h"
#include "Safety_Monitor.h"


System_Manager* System_Manager::instance = nullptr;

void System_Manager::startWorkingCycle() // F-START-1
{
    std::cout << "[SYSTEM] Starting working cycle.\n";
    systemRunning = true;
    checkCriticalComponents();

    if (!criticalComponentsOK)
    {
        std::cout << "[SYSTEM] Start aborted! Critical components not OK.\n";
        systemRunning = false;
    }
}

void System_Manager::stopSystem() // F-START-2
{
    systemRunning = false;
    std::cout << "[SYSTEM] System stopped. \n" << std::endl;
}

void System_Manager::checkCriticalComponents() // F-START-3
{
    auto safety =  Safety_Monitor::getInstance();

    safety->monitorCover();
    safety->monitorMotorBlock();
    safety->monitorTemperature();

    bool coverOK = !safety->isCoverOpenState();
    bool motorOK = !safety->isMotorBlockedState();
    bool temperatureOK= !safety->isOverTempState();

    criticalComponentsOK = coverOK && motorOK && temperatureOK;

    if (criticalComponentsOK)
        std::cout << "[SYSTEM] Critical components OK.\n";
    else
        std::cout << "[SYSTEM] Critical components check FAILED.\n";

}
