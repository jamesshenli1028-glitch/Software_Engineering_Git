#pragma once
class Safety_Monitor {
private:
    bool coverOpen;
    bool motorBlocked;
    float temperature;
    Safety_Monitor();
public:
    static Safety_Monitor* getInstance();
    void updateCoverState(bool v);
    void updateMotorState(bool v);
    void updateTemperature(float t);
    bool isCoverOpen() const;
    bool isOverTemperature() const;
    void monitorDuringProcess();
    void emergencyShutdown();
};