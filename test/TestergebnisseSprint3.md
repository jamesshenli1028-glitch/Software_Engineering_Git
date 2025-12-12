# Sprint 3 – Testergebnisse

## Unit Tests (UT)

| Testfall | Ergebnis | Status | Requirement |
|----------|----------|--------|-------------|
| UT1 – Manueller Start Zyklus | Start wurde korrekt ausgelöst. `cycleActive` wurde auf true gesetzt, Systemstatus → RUNNING. | Bestanden | F-START-1 |
| UT2 – Manueller Stopp Zyklus | Stop innerhalb ≤100 ms, `cycleActive` = false, Systemstatus → STOPPED. | Bestanden | F-START-2 |
| UT3 – Prüfen kritischer Komponenten | `checkCriticalComponents()` lieferte OK innerhalb ≤2 s. | Bestanden | F-START-3 |
| UT4 – Vakuumprozess starten | Vakuumpumpe aktiviert, Drucksensor liefert Daten. | Bestanden | F-VACUUM-1 |
| UT5 – Vakuumziel erreicht | Zielunterdruck erkannt, Vakuumprozess korrekt beendet. | Bestanden | F-VACUUM-2 |
| UT6 – Timer-Funktionalität | Timer-Callback nach 200 ms korrekt ausgelöst. | Bestanden | F-TIMER-1 / F-TIMER-2 |
| UT7 – Versiegelungszeit präzise steuern | Heizelement für 2,0 s ±50 ms aktiviert, Zeitgenauigkeit eingehalten. | Bestanden | F-SEAL-2 |

---

## Integration Tests (IT)

| Testfall | Ergebnis | Status | Requirement |
|----------|----------|--------|-------------|
| IT1 – Sicherheitsabschaltung bei Temperatur | Temperatur >80 °C erkannt, Notabschaltung ≤200 ms, Systemstatus → ERROR. | Bestanden | F-SICHERHEITABSCHALTUNG-1 / NF-ZEIT-1 |
| IT2 – Abdeckung offen während Prozess | Abdeckung OFFEN erkannt, LED ROT + akustischer Alarm ≥70 dB, Stopp ≤200 ms. | Bestanden | F-SICHERHEITABSCHALTUNG-2 / F-BENUTZERFEEDBACK-1 |
| IT3 – Motorblockade während Prozess | Motorblock erkannt, Notabschaltung ≤200 ms ausgelöst, Alarm aktiviert. | Bestanden | F-SICHERHEITABSCHALTUNG-3 |
| IT4 – Vakuum Ende → Start Sealing | Versiegelung startet automatisch ≤200 ms nach Vakuumende. | Bestanden | F-SEAL-1 / F-SEAL-2 |
| IT5 – Prozessüberwachung & Notabschaltung | SafetyMonitor überwacht kontinuierlich, Notabschaltung ≤200 ms, Statusanzeigen korrekt. | Bestanden | F-SAFETY-4 / F-SAFETY-5 |
