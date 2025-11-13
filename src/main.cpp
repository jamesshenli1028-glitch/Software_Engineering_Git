#include "System_Manager.h"

int main()
{
    System_Manager* manager = System_Manager::getInstance();
    
    manager->startWorkingCycle();        
    manager->checkCriticalComponents();   
    manager->stopSystem();                

    return 0;
}