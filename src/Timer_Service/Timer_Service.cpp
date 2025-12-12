#include "TimerService.h"

void TimerService::delayMs(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
