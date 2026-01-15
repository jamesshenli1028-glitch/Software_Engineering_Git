#include "Safety_Monitor.h"
#include <iostream>
#include <cstdlib>

Safety_Monitor::Safety_Monitor() : coverOpen(false), motorBlocked(false), temperature(25.0f) {}

Safety_Monitor* Safety_Monitor::getInstance() {
    static Safety_Monitor instance;
    return &instance;
}

void Safety_Monitor::updateCoverState(bool v) { coverOpen = v; }
void Safety_Monitor::updateTemperature(float t) { temperature = t; }

bool Safety_Monitor::isCoverOpen() const { return coverOpen; }
bool Safety_Monitor::isOverTemperature() const { return temperature > 80.0f; }

void Safety_Monitor::monitorDuringProcess() {
    if (isOverTemperature() || isCoverOpen()) emergencyShutdown();
}

void Safety_Monitor::emergencyShutdown() {
    std::cout << "[SAFETY] Cause: " << (isCoverOpen() ? "Cover Opened" : "Overheating") << std::endl;
    std::cout << "[SAFETY] *** EMERGENCY SHUTDOWN ***" << std::endl;
    std::exit(1);
}