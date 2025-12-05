#include "TimerService.h"
#include <thread>

void TimerService::delayMs(int ms, std::function<void()> callback)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}