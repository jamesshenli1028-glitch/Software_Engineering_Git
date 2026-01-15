#include "System_Manager.h"
#include "UI_Manager.h"
#include "Temperature_Service.h"
#include "Vakuum_Manager.h"
#include "Sealing_Manager.h"
#include "Timer_Service.h"
#include "Safety_Monitor.h"
#include "Pressure_Service.h"
#include <iostream>

int main() {
    auto ui = UIManager::getInstance();
    auto tempService = Temperature_Service::getInstance();
    auto sysManager = System_Manager::getInstance();
    auto safety = Safety_Monitor::getInstance();
    auto pressService = Pressure_Service::getInstance();

    ui->showVacuumStatus("=== VAKUUMIERER SYSTEM STARTING ===");

    safety->updateCoverState(false);
    tempService->setTemperature(25.0f);
    pressService->setPressure(1.0f);   

    sysManager->startWorkingCycle();

    if (sysManager->isSystemRunning()) {

        ui->showVacuumStatus("PRE-CHECK OK. STARTING VACUUM...");
        Vakuum_Manager::getInstance()->startVakuuming();

        ui->showVacuumStatus("TARGET REACHED. STABILIZING...");
        TimerService::delayMs(200);

        Sealing_Manager::getInstance()->startSealing();

        ui->showSealingStatus("ALL PROCESSES COMPLETED. STANDBY.");
    }
    else {
        ui->showVacuumStatus("SYSTEM HALTED DUE TO SAFETY VIOLATION.");
    }

    return 0;
}