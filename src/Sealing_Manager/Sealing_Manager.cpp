#include "SealingManager.h"
#include "Motor_Service.h"
#include "Safety_Monitor.h"
#include <iostream>
#include <thread>
#include <chrono>

SealingManager::SealingManager() : sealingActive(false), sealingTimeMs(2000.0f) {}

SealingManager* SealingManager::getInstance()
{
    static SealingManager instance;
    return &instance;
}

void SealingManager::startDevice() 
{
    std::cout << "[SEALING] Heater started\n";
    Motor_Service motor;
    motor.setHeater(true);
    sealingActive = true;
}

void SealingManager::stopDevice()
{
    std::cout << "[SEALING] Heater stopped\n";
    Motor_Service motor;
    motor.setHeater(false);
    sealingActive = false;
}

void SealingManager::startSealing()
{
    startDevice();
    controlSealing();
    stopSealing();
}

void SealingManager::stopSealing()
{
    stopDevice();
}

void SealingManager::controlSealing()
{
    float elapsed = 0;
    const int step = 100; // 100 ms
    while(elapsed < sealingTimeMs)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(step));
        elapsed += step;
        std::cout << "[SEALING] Time elapsed: " << elapsed << " ms\n";
        Safety_Monitor::getInstance()->monitorDuringProcess();
    }
}