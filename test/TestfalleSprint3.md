# Sprint 3 – Testfälle

## Unit Tests (UT)

### UT1 – Manueller Start Zyklus
- **Ziel:** Sicherstellen, dass der Arbeitszyklus nach manueller Starttaste korrekt startet  
- **Ausgangszustand:** Systemstatus = READY, cycleActive = false  
- **Ereignis:** Start-Taste gedrückt  
- **Eingabe:** `startWorkingCycle()`  
- **Erwartete Reaktion:** Systemstatus → RUNNING, cycleActive = true  
- **Testschritte:** 
  1. Start-Taste drücken.
  2. Prüfen, ob Systemstatus RUNNING ist.
  3. Prüfen, ob cycleActive = true.
- **Erwarteter Folgezustand:** cycleActive = true, Systemstatus = RUNNING  
- **Klasse:** SystemManager  
- **Requirement:** F-START-1  

### UT2 – Manueller Stopp Zyklus
- **Ziel:** System stoppt korrekt innerhalb von 100 ms nach Stoptaste  
- **Ausgangszustand:** Systemstatus = RUNNING, cycleActive = true  
- **Ereignis:** Stop-Taste gedrückt  
- **Eingabe:** `stopSystem()`  
- **Erwartete Reaktion:** System stoppt ≤100 ms, cycleActive = false  
- **Testschritte:** 
  1. Stop-Taste drücken.
  2. Zeitmessung ≤100 ms prüfen.
  3. Prüfen, ob Systemstatus STOPPED ist.
- **Erwarteter Folgezustand:** cycleActive = false, Systemstatus = STOPPED  
- **Klasse:** SystemManager  
- **Requirement:** F-START-2  

### UT3 – Prüfung kritischer Komponenten
- **Ziel:** Prüfen, dass `checkCriticalComponents()` korrekt arbeitet  
- **Ausgangszustand:** Systemstatus = READY  
- **Ereignis:** Vor Start  
- **Eingabe:** `checkCriticalComponents()`  
- **Erwartete Reaktion:** Status = OK innerhalb 2 s  
- **Testschritte:** 
  1. checkCriticalComponents() aufrufen.
  2. Rückgabestatus prüfen.
- **Erwarteter Folgezustand:** systemCheckPassed = true  
- **Klasse:** SystemManager  
- **Requirement:** F-START-3  

### UT4 – Vakuumprozess starten
- **Ziel:** Start des Vakuumierprozesses  
- **Ausgangszustand:** Arbeitszyklus läuft  
- **Ereignis:** Aufruf von `startVacuuming()`  
- **Eingabe:** `VacuumManager.startVacuuming()`  
- **Erwartete Reaktion:** Vakuumpumpe startet, Drucksensor aktiv  
- **Testschritte:** 
  1. startVacuuming() aufrufen.
  2. Prüfen, ob Pumpe läuft.
  3. Prüfen, ob Drucksensor Daten liefert.
- **Klasse:** VacuumManager  
- **Requirement:** F-VACUUM-1  

### UT5 – Vakuumziel erreicht
- **Ziel:** Erkennen, dass Zielunterdruck erreicht wurde  
- **Ausgangszustand:** Vakuum aktiv  
- **Ereignis:** Drucksensor meldet Zielwert  
- **Eingabe:** `isTargetPressureReached()`  
- **Erwartete Reaktion:** Funktion liefert true, Vakuumprozess endet  
- **Testschritte:** 
  1. Druckwert simulieren.
  2. Prüfen, ob isTargetPressureReached() true liefert.
- **Klasse:** VacuumManager  
- **Requirement:** F-VACUUM-2  

### UT6 – Timer-Funktionalität
- **Ziel:** Prüfen des Timers für Prozesssteuerung  
- **Ausgangszustand:** Timer nicht aktiv  
- **Ereignis:** Timer starten  
- **Eingabe:** `startTimer(duration)`  
- **Erwartete Reaktion:** Callback nach duration aufgerufen  
- **Testschritte:** 
  1. startTimer(200 ms) aufrufen.
  2. Prüfen, ob Callback nach 200 ms ausgeführt wird.
- **Klasse:** TimerService  
- **Requirement:** F-TIMER-1 / F-TIMER-2  

### UT7 – Versiegelungszeit präzise steuern
- **Ziel:** Versiegelungsdauer = 2,0 s ±50 ms  
- **Ausgangszustand:** Sealing Prozess inaktiv  
- **Ereignis:** Aufruf von controlSealing()  
- **Eingabe:** `SealingManager.controlSealing()`  
- **Erwartete Reaktion:** Heizelement aktiviert für genau 2,0 s ±50 ms  
- **Testschritte:** 
  1. controlSealing() aufrufen.
  2. Zeitmessung starten.
  3. Prüfen, ob Heizelement exakt für 2,0 s ±50 ms aktiv ist.
- **Klasse:** SealingManager  
- **Requirement:** F-SEAL-2  

## Integration Tests (IT)

### IT1 – Sicherheitsabschaltung bei Temperatur
- **Ziel:** Notabschaltung bei >80 °C  
- **Ausgangszustand:** Systemstatus = RUNNING  
- **Ereignis:** Temperatur überschreitet 80 °C  
- **Eingabe:** `monitorDuringProcess()`  
- **Erwartete Reaktion:** Notabschaltung ≤200 ms, Systemstatus = ERROR  
- **Klasse:** SafetyMonitor  
- **Requirement:** F-SICHERHEITABSCHALTUNG-1 / NF-ZEIT-1  

### IT2 – Abdeckung offen während Prozess
- **Ziel:** System stoppt innerhalb 200 ms bei geöffneter Abdeckung  
- **Ausgangszustand:** Vakuum/Sealing aktiv  
- **Ereignis:** Abdeckung OFFEN  
- **Eingabe:** `monitorDuringProcess()`  
- **Erwartete Reaktion:** Stopp ≤200 ms, LED ROT + akustischer Alarm ≥70 dB  
- **Klasse:** SafetyMonitor → UIManager  
- **Requirement:** F-SICHERHEITABSCHALTUNG-2 / F-BENUTZERFEEDBACK-1  

### IT3 – Motorblockade während Prozess
- **Ziel:** Notabschaltung bei Motorblock ≤200 ms  
- **Ausgangszustand:** Sealing in Arbeit  
- **Ereignis:** Motorblock  
- **Eingabe:** `monitorDuringProcess()`  
- **Erwartete Reaktion:** Motorstopp ≤200 ms, Alarm ausgelöst  
- **Klasse:** SafetyMonitor → SystemManager  
- **Requirement:** F-SICHERHEITABSCHALTUNG-3  

### IT4 – Vakuum Ende → Start Sealing
- **Ziel:** Nach Vakuumprozess Start Versiegelung  
- **Ausgangszustand:** Vakuum beendet  
- **Ereignis:** notifyVacuumDone()  
- **Eingabe:** SystemManager.startSealingProcess()  
- **Erwartete Reaktion:** Versiegelung startet automatisch ≤200 ms  
- **Klasse:** SystemManager → SealingManager  
- **Requirement:** F-VSEAL-2 / F-VSEAL-1  

### IT5 – Prozessüberwachung & Notabschaltung
- **Ziel:** SafetyMonitor überwacht während Vakuum/Sealing  
- **Ausgangszustand:** Arbeitszyklus läuft  
- **Ereignis:** Übertemperatur / Cover offen / Motorblock  
- **Eingabe:** `monitorDuringProcess()`  
- **Erwartete Reaktion:** Notabschaltung ≤200 ms, Statusänderung korrekt angezeigt  
- **Klasse:** SafetyMonitor → SystemManager → UIManager  
- **Requirement:** F-SAFETY-4 / F-SAFETY-5
