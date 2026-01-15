#include "Vakuum_Manager.h"
#include "Pressure_Service.h"
#include "Safety_Monitor.h"
#include "Motor_Service.h"
#include "UI_Manager.h"
#include "Timer_Service.h"
#include <string>

Vakuum_Manager::Vakuum_Manager() {}
Vakuum_Manager* Vakuum_Manager::getInstance() {
    static Vakuum_Manager instance;
    return &instance;
}

void Vakuum_Manager::startDevice() {
    Motor_Service::getInstance()->setPumpe(true);
}
void Vakuum_Manager::stopDevice() {
    Motor_Service::getInstance()->setPumpe(false);
}

void Vakuum_Manager::startVakuuming() {
    auto ps = Pressure_Service::getInstance();
    auto ui = UIManager::getInstance();
    auto safety = Safety_Monitor::getInstance();

    startDevice();
    while (ps->getPressure() > 0.11f) {

        //if (ps->getPressure() < 0.65f && ps->getPressure() > 0.55f) {
        //    safety->updateCoverState(true);
        //}

        safety->monitorDuringProcess(); // 运行时实时监测

        float currentP = ps->getPressure();
        currentP -= 0.05f;
        ps->setPressure(currentP);

        ui->showVacuumStatus(std::to_string(ps->getPressure()) + " bar");
        TimerService::delayMs(200);
    }
    stopDevice();
}