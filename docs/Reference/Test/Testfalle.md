### Unit Tests

#### UT1 – Start Arbeitszyklus
- **Ziel:** Sicherstellen, dass der Arbeitszyklus korrekt startet  
- **Ausgangszustand:** Systemstatus = READY, cycleActive = false  
- **Ereignis:** Start-Taste gedrückt  
- **Eingabe:** `startWorkingCycle()`  
- **Erwartete Reaktion:** Systemstatus → RUNNING, cycleActive = true  
- **Testschritte:** 
1. Rufen Sie startWorkingCycle() auf. 
2. Überprüfen Sie den neuen Systemstatus. 
3. Überprüfen Sie den cycleActive-Wert.
- **Erwarteter Folgezustand:** cycleActive = true, Systemstatus = RUNNING  
- **Klasse:** System_Manager  
- **Requirement:** F-START-1  
- **Ergebnis:** Der Start wurde korrekt ausgelöst. `cycleActive` wurde auf true gesetzt und der Systemstatus wechselte wie erwartet nach RUNNING.  
- **Status:** Bestanden 

#### UT2 – Stop System
- **Ziel:** Sicherstellen, dass das System korrekt stoppt  
- **Ausgangszustand:** Systemstatus = RUNNING, cycleActive = true  
- **Ereignis:** Stop-Taste gedrückt  
- **Eingabe:** `stopSystem()`  
- **Erwartete Reaktion:** System stoppt ≤100 ms, cycleActive = false  
- **Testschritte:** 
1. Starten Sie eine Zeitmessung.
2. Rufen Sie stopSystem() auf.
- **Erwarteter Folgezustand:** cycleActive = false, Systemstatus = STOPPED  
- **Klasse:** System_Manager  
- **Requirement:** F-START-2 
- **Ergebnis:** Das System stoppte innerhalb der geforderten ≤100 ms. `cycleActive` wurde auf false gesetzt und Systemstatus = STOPPED.  
- **Status:** Bestanden   

#### UT3 – Prüfen kritischer Komponenten
- **Ziel:** Prüfen, ob `checkCriticalComponents()` korrekt arbeitet  
- **Ausgangszustand:** Systemstatus = READY  
- **Ereignis:** Vor Start  
- **Eingabe:** `checkCriticalComponents()`  
- **Erwartete Reaktion:** Status = OK in ≤2 s  
- **Testschritte:** 
1. Rufen Sie checkCriticalComponents() auf.
2. Überprüfen Sie die Zeitmessung.
3. Überprüfen Sie den Rückgabestatus (systemCheckPassed).
- **Erwarteter Folgezustand:** systemCheckPassed = true  
- **Klasse:** System_Manager  
- **Requirement:** F-START-3 
- **Ergebnis:** Die Methode lieferte innerhalb von ≤2 s einen korrekten OK-Status.  
- **Status:** Bestanden  


---

### Integration Tests

#### IT1 – Temperaturüberwachung & Notabschaltung
- **Ziel:** Notabschaltung bei Temperatur >80 °C  
- **Ausgangszustand:** Systemstatus = RUNNING  
- **Ereignis:** Temperatur >82 °C  
- **Eingabe:** `monitorTemperature()`  
- **Erwartete Reaktion:** Notabschaltung ≤200 ms, Systemstatus = ERROR  
- **Testschritte:** 
1. Starten Sie eine Zeitmessung.
2. Simulieren Sie einen Temperaturwert von >82 °C.
3. Stoppen Sie die Zeitmessung bei Systemreaktion.
4. Überprüfen Sie die Zeit und den Systemstatus.
- **Klasse:** Safety_Monitor  
- **Requirement:** F-SICHERHEIT-1 / NF-ZEIT-1  
- **Ergebnis:** Temperaturüberschreitung >82 °C wurde korrekt erkannt. Notabschaltung erfolgte <200 ms, Systemstatus wechselte zu ERROR.  
- **Status:** Bestanden 

#### IT2 – Abdeckung offen → Alarm
- **Ziel:** Auslösen eines optischen & akustischen Alarms  
- **Ausgangszustand:** Systemstatus = RUNNING  
- **Ereignis:** Abdeckung OFFEN  
- **Eingabe:** `monitorCover()`  
- **Erwartete Reaktion:** LED ROT, akustischer Alarm ≥70 dB  
- **Testschritte:** 
1. Simulieren Sie das Ereignis "Abdeckung OFFEN".
2. Überprüfen Sie die LED-Farbe (ROT).
3. Messen Sie den akustischen Alarm (Dezibel).
4. Überprüfen Sie den Alarm-Status (≥70 dB).
- **Klasse:** Safety_Monitor → UI_Manager  
- **Requirement:** F-SICHERHEIT-2  
- **Ergebnis:** Abdeckung „OFFEN“ wurde korrekt erkannt. Rote LED wurde aktiviert und akustischer Alarm (≥70 dB) wurde ausgelöst.  
- **Status:** Bestanden 

#### IT3 – Motorblock & Versiegelung
- **Ziel:** Ereignisbehandlung bei Motorblock bzw. Start der Versiegelung nach Vakuum  
- **Ausgangszustand:** Motor normal, Vakuum beendet  
- **Ereignis:** Motorblock / Vakuumende  
- **Eingabe:** `monitorMotorBlock()`, `startSealing()`  
- **Erwartete Reaktion:** Notabschaltung bzw. Sealing startet ≤200 ms  
- **Testschritte:** 
1. Simulieren Sie das Ereignis "Motorblock".
2. Überprüfen Sie die Notabschaltung.
3. Simulieren Sie das Ereignis "Vakuumende".
4. Überprüfen Sie den Start der Versiegelung.
- **Klasse:** Safety_Monitor → System_Manager → Sealing_Manager  
- **Requirement:** F-SICHERHEIT-3 / F-VERSIEGELUNG-1
- **Ergebnis:** Motorblock wurde korrekt erkannt und Notabschaltung ausgelöst. Beim Szenario „Vakuumende“ startete die Versiegelung innerhalb der geforderten Reaktionszeit.  
- **Status:** Bestanden  