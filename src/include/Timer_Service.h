#pragma once
#include <thread>
#include <chrono>

class TimerService
{
public:
    static void delayMs(int ms);
};