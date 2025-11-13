#pragma once

// Singleton model

class Safety_Monitor
{
private:
    static Safety_Monitor* instance;
    Safety_Monitor(){};

    Safety_Monitor(const Safety_Monitor&) = delete;
    Safety_Monitor& operator=(const Safety_Monitor&) = delete;

public:
    static Safety_Monitor* getInstance()
    {
        if(instance == nullptr)
            instance = new Safety_Monitor();
        return instance;
    }

    void monitorTemperature(){} // F-SICHERHEIT-1 
    void monitorCover(){} // F-SICHERHEIT-2 
    void monitorMotorBlock(){} // F-SICHERHEIT-3

};

