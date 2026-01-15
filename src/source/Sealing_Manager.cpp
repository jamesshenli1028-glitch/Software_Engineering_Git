#include "Sealing_Manager.h"
#include "Motor_Service.h"
#include "UI_Manager.h"
#include "Timer_Service.h"

Sealing_Manager::Sealing_Manager() {}
Sealing_Manager* Sealing_Manager::getInstance() {
    static Sealing_Manager instance;
    return &instance;
}

void Sealing_Manager::startDevice() {
    Motor_Service::getInstance()->setHeater(true);
}
void Sealing_Manager::stopDevice() {
    Motor_Service::getInstance()->setHeater(false);
}

void Sealing_Manager::startSealing() {
    auto ui = UIManager::getInstance();
    startDevice();
    ui->showSealingStatus("Sealing in progress...");
    TimerService::delayMs(2000);
    stopDevice();
}