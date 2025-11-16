#include "System_Manager.h"
#include "Safety_Monitor.h"

int main()
{
    auto safety = Safety_Monitor::getInstance();
    auto manager = System_Manager::getInstance();

    // Sprint1: 模拟输入
    safety->updateCoverState(false);
    safety->updateMotorState(false);
    safety->updateTemperature(40.0f);

    manager->startWorkingCycle();  

    safety->updateTemperature(90.0f); // Unsafe!

    manager->checkCriticalComponents();

    manager->stopSystem();
    return 0;
}