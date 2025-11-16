#pragma once
#include <iostream>

// Singleton model

class System_Manager
{
private:
    static System_Manager* instance; //einziges Obj, bietet den Klassen Methode an
 
    System_Manager(const System_Manager&) = delete;
    System_Manager& operator=(const System_Manager&) = delete;

    bool systemRunning;
    bool criticalComponentsOK;

    System_Manager(): systemRunning(false), criticalComponentsOK(false){}; // private Konstruktur, darf nicht aussen der Klasse ein Obj erstellen

public:
    static System_Manager* getInstance() // Methode fuer das einzige Obj, koette aufgeruft werden
    {
        if(instance == nullptr)
            instance = new System_Manager();
        return instance;
    }

    bool isSystemRunning() const { return systemRunning; }
    bool areCriticalComponentsOK() const { return criticalComponentsOK; }

    void startWorkingCycle(){} // F-START-1
    void stopSystem(){} // F-START-2
    void checkCriticalComponents(){} // F-START-3
};

