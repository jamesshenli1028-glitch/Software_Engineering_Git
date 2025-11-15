#include "System_Manager.h"
#include <iostream>

System_Manager* System_Manager::instance = nullptr;

void System_Manager::startWorkingCycle() // F-START-1
{
    systemRunning = true;
    checkCriticalComponents();
}

void System_Manager::stopSystem() // F-START-2
{
    systemRunning = false;
    std::cout<<"System stopped"<<std::endl;
}

void System_Manager::checkCriticalComponents() // F-START-3
{
    if(systemRunning)
    {
        if( coverOpen || motorBlocked || overTemperature)
        {
            criticalComponentsOK = false;
            std::cout<<"Critical components checked failed."<<std::endl;
        }
        else
        {
            criticalComponentsOK = true;
            std::cout<<"Critical components checked passed."<<std::endl;
        }
    }
    else
    {
        criticalComponentsOK = false;
        std::cout << "System not running. Critical components check skipped." << std::endl;

    }
}
