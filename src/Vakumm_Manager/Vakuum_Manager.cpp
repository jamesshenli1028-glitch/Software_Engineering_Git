#include "Vakuum_Manager.h"
#include "Pressure_Service.h"
#include "Safety_Monitor.h"
#include <iostream>
#include <thread>
#include <chrono>

Vakuum_Manager::Vakuum_Manager() : currentPressure(1.0f), targetPressure(0.1f) {}

Vakuum_Manager* Vakuum_Manager::getInstance()
{
    static Vakuum_Manager instance;
    return &instance;
}

void Vakuum_Manager::startDevice() 
{ 
    std::cout << "[VACUUM] Pump started\n"; 
}
void Vakuum_Manager::stopDevice() 
{ 
    std::cout << "[VACUUM] Pump stopped\n"; 
}

void Vakuum_Manager::startVakuuming()
{
    startDevice();
    auto pressureService = Pressure_Service::getInstance();
    currentPressure = pressureService->getPressure();

    while(currentPressure > targetPressure)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        currentPressure -= 0.02f;
        pressureService->setPressure(currentPressure);
        std::cout << "[VACUUM] Current pressure: " << currentPressure << " bar\n";

        Safety_Monitor::getInstance()->monitorDuringProcess();
    }

    stopVakuuming();
}

void Vakuum_Manager::stopVakuuming() 
{ 
    stopDevice(); 
}
void Vakuum_Manager::setTargetPressure(float p) 
{ 
    targetPressure = p; 
}
float Vakuum_Manager::monitorPressure() const 
{ 
    return currentPressure; 
}
bool Vakuum_Manager::isTargetPressureReached() const 
{ 
    return currentPressure <= targetPressure; 
}
