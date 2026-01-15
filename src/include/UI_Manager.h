#pragma once
#include <string>

class UIManager
{
private:
    UIManager();
public:
    static UIManager* getInstance();

    void showVacuumStatus(const std::string& status);
    void showSealingStatus(const std::string& status);
};