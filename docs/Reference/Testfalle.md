
### Unit Tests

#### UT1 – Start Arbeitszyklus
- **Ziel:** Sicherstellen, dass der Arbeitszyklus korrekt startet  
- **Ausgangszustand:** Systemstatus = READY, cycleActive = false  
- **Ereignis:** Start-Taste gedrückt  
- **Eingabe:** `startWorkingCycle()`  
- **Erwartete Reaktion:** Systemstatus → RUNNING, cycleActive = true  
- **Erwarteter Folgezustand:** cycleActive = true, Systemstatus = RUNNING  
- **Klasse:** System_Manager  
- **Requirement:** F-START-1  

#### UT2 – Stop System
- **Ziel:** Sicherstellen, dass das System korrekt stoppt  
- **Ausgangszustand:** Systemstatus = RUNNING, cycleActive = true  
- **Ereignis:** Stop-Taste gedrückt  
- **Eingabe:** `stopSystem()`  
- **Erwartete Reaktion:** System stoppt ≤100 ms, cycleActive = false  
- **Erwarteter Folgezustand:** cycleActive = false, Systemstatus = STOPPED  
- **Klasse:** System_Manager  
- **Requirement:** F-START-2  

#### UT3 – Prüfen kritischer Komponenten
- **Ziel:** Prüfen, ob `checkCriticalComponents()` korrekt arbeitet  
- **Ausgangszustand:** Systemstatus = READY  
- **Ereignis:** Vor Start  
- **Eingabe:** `checkCriticalComponents()`  
- **Erwartete Reaktion:** Status = OK in ≤2 s  
- **Erwarteter Folgezustand:** systemCheckPassed = true  
- **Klasse:** System_Manager  
- **Requirement:** F-START-3  


---

### Integration Tests

#### IT1 – Temperaturüberwachung & Notabschaltung
- **Ziel:** Notabschaltung bei Temperatur >80 °C  
- **Ausgangszustand:** Systemstatus = RUNNING  
- **Ereignis:** Temperatur >82 °C  
- **Eingabe:** `monitorTemperature()`  
- **Erwartete Reaktion:** Notabschaltung ≤200 ms, Systemstatus = ERROR  
- **Klasse:** Safety_Monitor  
- **Requirement:** F-SICHERHEIT-1 / NF-ZEIT-1  

#### IT2 – Abdeckung offen → Alarm
- **Ziel:** Auslösen eines optischen & akustischen Alarms  
- **Ausgangszustand:** Systemstatus = RUNNING  
- **Ereignis:** Abdeckung OFFEN  
- **Eingabe:** `monitorCover()`  
- **Erwartete Reaktion:** LED ROT, akustischer Alarm ≥70 dB  
- **Klasse:** Safety_Monitor → UI_Manager  
- **Requirement:** F-SICHERHEIT-2  

#### IT3 – Motorblock & Versiegelung
- **Ziel:** Ereignisbehandlung bei Motorblock bzw. Start der Versiegelung nach Vakuum  
- **Ausgangszustand:** Motor normal, Vakuum beendet  
- **Ereignis:** Motorblock / Vakuumende  
- **Eingabe:** `monitorMotorBlock()`, `startSealing()`  
- **Erwartete Reaktion:** Notabschaltung bzw. Sealing startet ≤200 ms  
- **Klasse:** Safety_Monitor → System_Manager → Sealing_Manager  
- **Requirement:** F-SICHERHEIT-3 / F-VERSIEGELUNG-1
