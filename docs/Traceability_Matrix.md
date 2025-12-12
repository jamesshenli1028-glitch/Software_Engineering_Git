# Traceability Matrix

| Requirement ID | Beschreibung | Komponente | Priorität | Begründung | Schnittstelle | Sprint | Architektur | Methode(n) | Testfall(e) |
|---|---|---|---|---|---|---|---|---|---|
| F-START-1 | System startet Arbeitszyklus nach Drücken der Starttaste | SystemManager | Mittel | Grundfunktionalität | SystemManager.startWorkingCycle() | S1 | Core / Logic | startWorkingCycle() | UT1 |
| F-START-2 | System stoppt innerhalb von 100 ms nach Drücken der Stoptaste | SystemManager | Hoch | Sicherheitsrelevantes Stoppen | SystemManager.stopSystem() | S1 | Core / Logic | stopSystem() | UT2 |
| F-START-3 | System prüft vor Start alle kritischen Komponenten und meldet Status innerhalb von 2 s | SystemManager | Hoch | Vorstart-Sicherheitsprüfung | SystemManager.checkKomponents() | S1 | Core / Logic | checkCriticalComponents() | UT3 |
| F-SICHERHEIT-1 | Abschaltung bei >80 °C (±2 °C Genauigkeit) | SafetyMonitor | Kritisch | Kritische Sicherheitsfunktion | SafetyMonitor.temperaturSafety() | S1 | Safety | monitorTemperature() | IT1 |
| F-SICHERHEIT-2 | Stoppt innerhalb von 200 ms bei geöffneter Abdeckung | SafetyMonitor | Kritisch | Kritische Sicherheitsfunktion | SafetyMonitor.abdeckungSafety() | S1 | Safety | monitorCover() | IT2 |
| F-SICHERHEIT-3 | Abschaltung innerhalb von 200 ms bei Motorblockade | SafetyMonitor | Kritisch | Kritische Sicherheitsfunktion | SafetyMonitor.emergencyShutdown() | S1 | Safety | monitorMotorBlock(), emergencyShutdown() | IT3 |
| F-SICHERHEIT-4 | Visuelle + akustische Warnung | UIManager | Hoch | Sicherheitsfeedback | UIManager.startShowProcess() | S1 | UI | startShowProcess() | — |
| F-BENUTZER-1 | Zustände: Bereit (Grün), In Betrieb (Gelb), Fehler (Rot) | UIManager | Mittel | Grundstatus-Anzeige | UIManager.setLED() | S1 | UI | setLED() | — |
| NF-ZEIT-1 | Reaktionszeit auf Sicherheitsereignisse ≤200 ms bei 25°C | SafetyMonitor | Kritisch | Zeitkritisches Safety | TimerService.getTime() | S1 | Safety / Timing | emergencyShutdown() | IT1 |
| NF-BENUTZER-1 | Akustischer Alarm ≥70 dB in 1 m Entfernung | UIManager | Mittel | Sicherheitsalarm | UIManager.activateAlarm() | S1 | UI | activateAlarm() | — |
| NF-LEISTUNG-1 | Funktion auch bei Spannungsschwankungen | SystemManager | Hoch | Robustheitsanforderung | implemented via SystemManager internal monitoring | S1 | Core | watchDog(), internalMonitoring() | — |
| F-VACUUM-1 | Startet Vakuumprozess | VacuumManager | Hoch | Kernfunktion Verpackung | VacuumManager.startVacuum() | S2 | Application | startVacuum() | UT4 |
| F-VACUUM-2 | Überwacht Kammerdruck / Drucksensor (10 Hz Abtastrate) | VacuumManager | Hoch | Sicherheit / Prozesskontrolle | VacuumManager.monitorPressure() | S2 | Application | monitorPressure() | UT5 |
| F-VACUUM-3 | Beendet Vakuumieren bei Zielunterdruck (100 mbar ±5 mbar) | VacuumManager | Hoch | Automatischer Prozessabschluss | VacuumManager.isTargetPressureReached(), stopVacuum() | S2 | Application | isTargetPressureReached(), stopVacuum() | UT5 |
| F-VACUUM-4 | Benachrichtigt SystemManager nach Vakuumende | VacuumManager → SystemManager | Hoch | Prozesskoordination | notifyVacuumDone(), handleVacuumDone() | S2 | Application | notifyVacuumDone(), handleVacuumDone() | IT4 |
| F-SEAL-1 | Startet Versiegelung nach Vakuumende | SealingManager / SystemManager | Hoch | Prozesskette | SystemManager.startSealingProcess(), SealingManager.startSealing() | S2 | Application | startSealingProcess(), startSealing() | IT4 |
| F-SEAL-2 | Versiegelungszeit: 2,0 s ±50 ms | SealingManager | Hoch | Prozessgenauigkeit | SealingManager.controlSealing() | S2 | Application | controlSealing() | UT7 |
| F-SEAL-3 | Benachrichtigung nach Versiegelungsende | SealingManager → SystemManager | Hoch | Prozesskoordination | notifySealingDone(), handleSealingDone() | S2 | Application | notifySealingDone(), handleSealingDone() | IT5 |
| F-BENUTZER-2 | Visuelle Anzeige aus 5 m Entfernung klar erkennbar | UIManager | Mittel | UI-Optimierung | UIManager.startShowProcess() | S2 | UI | startShowProcess() | — |
| NF-ZEIT-2 | Genauigkeit Versiegelungszeit ±50 ms | TimerService / SealingManager | Hoch | Timing | TimerService.getTimestamp(), controlSealing() | S2 | Timing / Application | getTimestamp(), controlSealing() | UT8 |
| F-TIMER-1 | Timer für zeitkritische Vorgänge | TimerService | Mittel | Ablaufsteuerung | TimerService.startTimer() | S2 | Timing | startTimer() | UT6 |
| F-TIMER-2 | Timer-Callback Ereignis | TimerService | Mittel | Ablaufsteuerung | TimerService.onTimeout() | S2 | Timing | onTimeout() | UT6 |
| F-SAFETY-4 | Sicherheitsüberwachung während Vakuum/Sealing | SafetyMonitor | Kritisch | Vermeidung von Schäden | SafetyMonitor.monitorDuringProcess() | S2 | Safety | monitorDuringProcess() | IT5 |
| F-SAFETY-5 | Notabschaltung ≤200 ms während Prozess | SafetyMonitor | Kritisch | Kritische Sicherheitsfunktion | SafetyMonitor.emergencyShutdown() | S2 | Safety | emergencyShutdown() | IT5 |
| NF-ARCH-1 | Asynchrone Architektur für Vacuum/Sealing/Safety | SystemManager, VacuumManager, SealingManager | Hoch | Parallele Abläufe | Thread-Lifecycle-Management | S2 | System | threadLifecycleManagement() | Review |
