#pragma once

// Singleton model

class System_Manager
{
private:
    static System_Manager* instance; //einziges Obj, bietet den Klassen Methode an
    System_Manager(){}; // private Konstruktur, darf nicht aussen der Klasse ein Obj erstellen
public:
    static System_Manager* getInstance() // Methode fuer das einzige Obj, koette aufgeruft werden
    {
        if(instance == nullptr)
            instance = new System_Manager();
        return instance;

    }

    void startWorkingCycle(){} // F-START-1
    void stopSystem(){} // F-START-2
    void checkCriticalComponents(){} // F-START-3
};

System_Manager* System_Manager::instance = nullptr;

void System_Manager::startWorkingCycle() {}
void System_Manager::stopSystem() {}
void System_Manager::checkCriticalComponents() {}