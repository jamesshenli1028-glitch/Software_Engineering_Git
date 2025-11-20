
### Unit Tests – Ergebnisse

#### UT1 – Start Arbeitszyklus
- **Ergebnis:** Der Start wurde korrekt ausgelöst. `cycleActive` wurde auf true gesetzt und der Systemstatus wechselte wie erwartet nach RUNNING.  
- **Status:** Bestanden  
- **Requirement:** F-START-1  

#### UT2 – Stop System
- **Ergebnis:** Das System stoppte innerhalb der geforderten ≤100 ms. `cycleActive` wurde auf false gesetzt und Systemstatus = STOPPED.  
- **Status:** Bestanden  
- **Requirement:** F-START-2  

#### UT3 – Prüfen kritischer Komponenten
- **Ergebnis:** Die Methode lieferte innerhalb von ≤2 s einen korrekten OK-Status.  
- **Status:** Bestanden  
- **Requirement:** F-START-3  


---

### Integration Tests – Ergebnisse

#### IT1 – Temperaturüberwachung & Notabschaltung
- **Ergebnis:** Temperaturüberschreitung >82 °C wurde korrekt erkannt. Notabschaltung erfolgte <200 ms, Systemstatus wechselte zu ERROR.  
- **Status:** Bestanden  
- **Requirement:** F-SICHERHEIT-1 / NF-ZEIT-1  

#### IT2 – Abdeckung offen → Alarm
- **Ergebnis:** Abdeckung „OFFEN“ wurde korrekt erkannt. Rote LED wurde aktiviert und akustischer Alarm (≥70 dB) wurde ausgelöst.  
- **Status:** Bestanden  
- **Requirement:** F-SICHERHEIT-2  

#### IT3 – Motorblock & Versiegelung
- **Ergebnis:** Motorblock wurde korrekt erkannt und Notabschaltung ausgelöst. Beim Szenario „Vakuumende“ startete die Versiegelung innerhalb der geforderten Reaktionszeit.  
- **Status:** Bestanden  
- **Requirement:** F-SICHERHEIT-3 / F-VERSIEGELUNG-1  
