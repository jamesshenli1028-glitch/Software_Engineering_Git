#include "Safety_Monitor.h"

Safety_Monitor* Safety_Monitor::instance = nullptr;

void Safety_Monitor::monitorTemperature()
{
    if (temperature > 80.0f)
    {
        std::cout << "[SAFETY] OVER-TEMPERATURE (" << temperature << " C)\n";
        emergencyShutdown();
    }

}

void Safety_Monitor::monitorCover()
{
        if (coverOpen)
    {
        std::cout << "[SAFETY] Cover OPEN detected!\n";
        emergencyShutdown();
    }
}

void Safety_Monitor::monitorMotorBlock()
{
        if (motorBlocked)
    {
        std::cout << "[SAFETY] Motor BLOCK detected!\n";
        emergencyShutdown();
    }
}

void Safety_Monitor::emergencyShutdown()
{
    std::cout << "[SAFETY] *** EMERGENCY SHUTDOWN TRIGGERED ***\n";
}
