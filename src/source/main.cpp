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
    // 1. 获取所有单例实例 (Singletons)
    auto ui = UIManager::getInstance();
    auto tempService = Temperature_Service::getInstance();
    auto sysManager = System_Manager::getInstance();
    auto safety = Safety_Monitor::getInstance();
    auto pressService = Pressure_Service::getInstance();

    // 2. 界面开机显示
    ui->showVacuumStatus("=== VAKUUMIERER SYSTEM STARTING ===");

    // 3. 模拟环境物理参数 (演示时可以改这里来触发报错)
    // 默认设置为安全状态：盖子关好(false)，温度25度
    safety->updateCoverState(false);
    tempService->setTemperature(25.0f);
    pressService->setPressure(1.0f);    // 重置为大气压

    // 4. 环节一：安全预检 (Sprint 1 逻辑整合)
    // sysManager 内部现在会自动从 tempService 同步温度并判断
    sysManager->startWorkingCycle();

    if (sysManager->isSystemRunning()) {

        // 5. 环节二：自动抽真空 (Sprint 2 逻辑整合)
        ui->showVacuumStatus("PRE-CHECK OK. STARTING VACUUM...");
        Vakuum_Manager::getInstance()->startVakuuming();
        // 注意：Vakuum_Manager 内部现在会调用 UIManager 每一跳显示压力

        // 6. 环节三：物理稳定缓冲 (工程亮点)
        // 使用你写的 TimerService 替代 std::this_thread
        ui->showVacuumStatus("TARGET REACHED. STABILIZING...");
        TimerService::delayMs(200);

        // 7. 环节四：自动封口 (Sprint 3 逻辑整合)
        // Sealing_Manager 内部会调用 Motor_Service 开启加热丝并由 UI 显示
        Sealing_Manager::getInstance()->startSealing();

        // 8. 流程结束
        ui->showSealingStatus("ALL PROCESSES COMPLETED. STANDBY.");
    }
    else {
        // 如果预检失败
        ui->showVacuumStatus("SYSTEM HALTED DUE TO SAFETY VIOLATION.");
    }

    return 0;
}