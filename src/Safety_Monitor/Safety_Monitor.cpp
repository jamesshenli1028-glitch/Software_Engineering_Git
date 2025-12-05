#include "Safety_Monitor.h"
#include <iostream>
#include <cstdlib>

Safety_Monitor::Safety_Monitor() : coverOpen(false), motorBlocked(false), temperature(25.0f) {}

Safety_Monitor* Safety_Monitor::getInstance()
{
    static Safety_Monitor instance;
    return &instance;
}

void Safety_Monitor::updateCoverState(bool v) 
{ 
    coverOpen = v; 
}
void Safety_Monitor::updateMotorState(bool v) 
{ 
    motorBlocked = v; 
}
void Safety_Monitor::updateTemperature(float t) 
{ 
    temperature = t; 
}

bool Safety_Monitor::isCoverOpen() const 
{
    return coverOpen; 
}
bool Safety_Monitor::isMotorBlocked() const 
{ 
    return motorBlocked; 
}
bool Safety_Monitor::isOverTemperature() const 
{ 
    return temperature > 80.0f; 
}

void Safety_Monitor::monitorTemperature()
{
    if(isOverTemperature()) 
    { 
        std::cout << "[SAFETY] OVER-TEMPERATURE!\n"; emergencyShutdown(); 
    }
}

void Safety_Monitor::monitorCover()
{
    if(coverOpen) 
    { 
        std::cout << "[SAFETY] Cover OPEN!\n"; emergencyShutdown(); 
    }
}

void Safety_Monitor::monitorMotorBlock()
{
    if(motorBlocked) 
    { 
        std::cout << "[SAFETY] Motor BLOCK!\n"; emergencyShutdown(); 
    }
}

void Safety_Monitor::monitorDuringProcess()
{
    monitorTemperature();
    monitorCover();
    monitorMotorBlock();
}

void Safety_Monitor::emergencyShutdown()
{
    std::cout << "[SAFETY] *** EMERGENCY SHUTDOWN TRIGGERED ***\n";
    std::exit(1);
}
