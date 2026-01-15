#pragma once
class System_Manager {
private:
    bool systemRunning;
    System_Manager();
public:
    static System_Manager* getInstance();
    void startWorkingCycle();
    void stopSystem();
    bool isSystemRunning() const;
};