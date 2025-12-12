```mermaid
%% Klassendiagramm Sprint 3
classDiagram
    class ProcessCoordinator {
        +startProcess()
        +handleEvent()
        +manageThreads()
    }
    class VacuumManager {
        +startVacuuming()
        +monitorPressure()
        +notifyDone()
    }
    class SealingManager {
        +startSealing()
        +controlSealing()
        +notifyDone()
    }
    class SafetyMonitor {
        +monitorTemp()
        +monitorCover()
        +emergencyShutdown()
    }
    class UIManager {
        +animateStatus()
        +showProcessStatus()
    }
    class Logger {
        +logEvent()
    }

    ProcessCoordinator --> VacuumManager
    ProcessCoordinator --> SealingManager
    ProcessCoordinator --> UIManager
    VacuumManager --> SafetyMonitor
    SealingManager --> SafetyMonitor
    SafetyMonitor --> ProcessCoordinator
    Logger --> UIManager



```mermaid
%% Sequenzdiagramm Sprint 3 kompakt
sequenceDiagram
    User->>UIManager: startCycle()
    UIManager->>ProcessCoordinator: startProcess()
    ProcessCoordinator->>VacuumManager: startVacuuming()
    VacuumManager->>PressureService: readPressure()
    VacuumManager-->>ProcessCoordinator: notifyDone()
    ProcessCoordinator->>SealingManager: startSealing()
    SealingManager->>TimerService: startTimeout()
    SafetyMonitor->>VacuumManager: monitorParams()
    SafetyMonitor->>SealingManager: monitorParams()
    SafetyMonitor-->>ProcessCoordinator: emergencyShutdown()
    ProcessCoordinator->>CoolingManager: startCooling()
    UIManager->>User: displayStatus()


%% Aktivitätsdiagramm Sprint 3 vertikal kompakt
flowchart LR
    Start([Start])
    CheckSafety{Sicherheitscheck?}
    StartVacuum[Vakuum starten]
    MonitorPressure[Druck prüfen]
    VacuumDone{Ziel erreicht?}
    StartSealing[Versiegelung starten]
    ControlSealing[Sealing Timer]
    Cooling[Cooling Phase]
    Error{Fehler?}
    Shutdown[Notabschaltung]
    End([Ende])

    Start --> CheckSafety
    CheckSafety -->|ok| StartVacuum
    CheckSafety -->|Fehler| Shutdown
    StartVacuum --> MonitorPressure
    MonitorPressure --> VacuumDone
    VacuumDone -->|nein| MonitorPressure
    VacuumDone -->|ja| StartSealing
    StartSealing --> ControlSealing
    ControlSealing --> Cooling
    Cooling --> End
    Error --> Shutdown
