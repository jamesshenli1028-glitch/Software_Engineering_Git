#include "System_Manager.h"
#include "Safety_Monitor.h"
#include "Vakuum_Manager.h"
#include "SealingManager.h"
#include "UIManager.h"
#include "TimerService.h"
#include "Pressure_Service.h"

int main()
{
    auto safety = Safety_Monitor::getInstance();
    auto manager = System_Manager::getInstance();
    auto vacuum = Vakuum_Manager::getInstance();
    auto sealing = SealingManager::getInstance();
    auto ui = UIManager::getInstance();

    safety->updateCoverState(false);
    safety->updateMotorState(false);
    safety->updateTemperature(40.0f);
    Pressure_Service::getInstance()->setPressure(1.0f);

    manager->startWorkingCycle();

    ui->showVacuumStatus("Starting");
    vacuum->setTargetPressure(0.1f);
    vacuum->startVakuuming();
    ui->showVacuumStatus("Finished");

    TimerService::delayMs(200);
    sealing->startSealing();

    ui->showSealingStatus("Finished");

    manager->stopSystem();

    return 0;
}