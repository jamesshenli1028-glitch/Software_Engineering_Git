# Sprint 2 – Komponenten und Schnittstellen

## Komponenten und Verantwortlichkeiten

| Komponente | Rolle | Verantwortlichkeiten |
|------------|------|--------------------|
| VacuumManager | Applikationsschicht | Steuert Vakuumpumpe, überwacht Kammerdruck, Benachrichtigung SystemManager bei Zielvakuum |
| SealingManager | Applikationsschicht | Steuert Versiegelungsprozess, kontrolliert Versiegelungszeit, Benachrichtigung SystemManager nach Abschluss |
| SystemManager | Applikationsschicht | Koordiniert Prozessablauf zwischen VacuumManager, SealingManager und SafetyMonitor |
| TimerService | Core / Timing | Stellt Timer- und Verzögerungsfunktionen für zeitkritische Abläufe bereit |
| SafetyMonitor | Safety Layer | Überwacht Temperatur, Cover, Motor während Vakuum/Sealing, führt Notabschaltung aus |
| UIManager | Präsentationsschicht | Zeigt Vakuum- und Sealingstatus an, steuert LEDs/Summer |

## Schnittstellendefinition

| Ziel | Quelle | Schnittstellen / Methoden |
|------|--------|--------------------------|
| SystemManager | VacuumManager | handleVacuumDone() |
| SystemManager | SealingManager | handleSealingDone() |
| VacuumManager | SystemManager | startVacuum(), isTargetPressureReached(), notifyVacuumDone() |
| SealingManager | SystemManager | startSealingProcess(), controlSealing(), notifySealingDone() |
| SafetyMonitor | SystemManager | monitorDuringProcess(), emergencyShutdown() |
| UIManager | SystemManager / VacuumManager / SealingManager | showVacuumStatus(), showSealingStatus() |
| TimerService | SystemManager / SealingManager | startTimer(), onTimeout() |
