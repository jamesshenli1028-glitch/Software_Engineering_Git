# Traceability Matrix – Sprint 2

| Requirement ID | Beschreibung | Komponente | Priorität | Begründung | Schnittstelle | Sprint 2 | Architektur | Methode(n) | Testfall(e) |
|----------------|--------------|------------|-----------|------------|---------------|----------|-------------|------------|-------------|
| F-VACUUM-1 | Startet Vakuumprozess | VacuumManager | Hoch | Kernfunktion für Verpackung | VacuumManager.startVacuum() | JA | Application | startVacuum() | UT4 |
| F-VACUUM-2 | Überwacht Drucksensor während Vakuum | VacuumManager | Hoch | Sicherheit und Prozesskontrolle | VacuumManager.monitorPressure() | JA | Application | monitorPressure() | UT5 |
| F-VACUUM-3 | Beendet Vakuum bei Zielunterdruck | VacuumManager | Hoch | Automatischer Prozessabschluss | VacuumManager.isTargetPressureReached() | JA | Application | isTargetPressureReached() | UT5 |
| F-VACUUM-4 | Benachrichtigung SystemManager nach Vakuumende | VacuumManager → SystemManager | Hoch | Prozesskoordination | VacuumManager.notifyVacuumDone() / SystemManager.handleVacuumDone() | JA | Application | notifyVacuumDone(), handleVacuumDone() | IT4 |
| F-SEAL-1 | Startet Versiegelung nach Vakuum | SystemManager → SealingManager | Hoch | Abhängig von Vakuum | SystemManager.startSealingProcess() | JA | Application | startSealingProcess() | IT4 |
| F-SEAL-2 | Versiegelungszeit 2,0 s ±50 ms | SealingManager | Hoch | Prozessgenauigkeit | SealingManager.controlSealing() | JA | Application | controlSealing() | UT7 |
| F-SEAL-3 | Benachrichtigung SystemManager nach Versiegelung | SealingManager → SystemManager | Hoch | Prozesskoordination | SealingManager.notifySealingDone() / SystemManager.handleSealingDone() | JA | Application | notifySealingDone(), handleSealingDone() | IT5 |
| F-TIMER-1 | Timer für zeitkritische Vorgänge | TimerService | Mittel | Steuerung von Verzögerungen | TimerService.startTimer() | JA | Timing | startTimer() | UT6 |
| F-TIMER-2 | Timer-Callback Ereignis | TimerService | Mittel | Steuerung von Prozessen | TimerService.onTimeout() | JA | Timing | onTimeout() | UT6 |
| F-SAFETY-4 | Sicherheitsüberwachung während Vakuum/Sealing | SafetyMonitor | Kritisch | Vermeidung von Schäden | SafetyMonitor.monitorDuringProcess() | JA | Safety | monitorDuringProcess() | IT5 |
| F-SAFETY-5 | Notabschaltung ≤200 ms möglich | SafetyMonitor | Kritisch | Kritische Sicherheitsfunktion | SafetyMonitor.emergencyShutdown() | JA | Safety | emergencyShutdown() | IT5 |
| F-UI-2 | Anzeige Vakuum- und Sealingstatus | UIManager | Mittel | Prozessvisualisierung | UIManager.showVacuumStatus(), UIManager.showSealingStatus() | JA | Presentation | showVacuumStatus(), showSealingStatus() | IT4 |
| NF-ZEIT-2 | Timer/Versiegelungsgenauigkeit ±10 ms / ±50 ms | TimerService / SealingManager | Hoch | Prozessgenauigkeit | TimerService.getTimestamp(), SealingManager.controlSealing() | JA | Timing / Application | getTimestamp(), controlSealing() | UT8 |
| NF-ARCH-1 | Asynchrone Architektur für Vakuum/Sealing/Safety | SystemManager, VacuumManager, SealingManager | Hoch | Unterstützt parallele Abläufe | Thread-Lifecycle-Management | JA | System | Thread-Lifecycle-Management | Review |
