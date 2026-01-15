#include "System_Manager.h"
#include "Safety_Monitor.h"
#include "Temperature_Service.h"
#include <iostream>

System_Manager::System_Manager() : systemRunning(false) {}
System_Manager* System_Manager::getInstance() {
    static System_Manager instance;
    return &instance;
}

void System_Manager::startWorkingCycle() {
    auto safety = Safety_Monitor::getInstance();
    auto tempService = Temperature_Service::getInstance();

    // 关键：预检前从温度服务同步数据
    safety->updateTemperature(tempService->getTemperature());

    if (safety->isCoverOpen() || safety->isOverTemperature()) {
        std::cout << "[SYSTEM] Pre-check FAILED!" << std::endl;
        systemRunning = false;
    }
    else {
        std::cout << "[SYSTEM] Pre-check OK. System Standby." << std::endl;
        systemRunning = true;
    }
}
void System_Manager::stopSystem() { systemRunning = false; }
bool System_Manager::isSystemRunning() const { return systemRunning; }