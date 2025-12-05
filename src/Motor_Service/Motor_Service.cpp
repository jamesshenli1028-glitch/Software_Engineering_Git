#include "Motor_Service.h"
#include <iostream>

Motor_Service::Motor_Service() : pumpRunning(false), heaterRunning(false) {}

void Motor_Service::setPumpe(bool on)
{
    pumpRunning = on;
    std::cout << "[MOTOR] Pump " << (on ? "ON" : "OFF") << std::endl;
}

void Motor_Service::setHeater(bool on)
{
    heaterRunning = on;
    std::cout << "[MOTOR] Heater " << (on ? "ON" : "OFF") << std::endl;
}

bool Motor_Service::isPumpRunning() const 
{ 
    return pumpRunning; 
}

bool Motor_Service::isHeaterRunning() const 
{ 
    return heaterRunning; 
}