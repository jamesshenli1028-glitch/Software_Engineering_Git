#include "UI_Manager.h"
#include <iostream>

UIManager::UIManager() {}

UIManager* UIManager::getInstance()
{
    static UIManager instance;
    return &instance;
}

void UIManager::showVacuumStatus(const std::string& status)
{
    std::cout << "[UI] Vacuum status: " << status << std::endl;
}

void UIManager::showSealingStatus(const std::string& status)
{
    std::cout << "[UI] Sealing status: " << status << std::endl;
}