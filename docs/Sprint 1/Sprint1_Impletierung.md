Requirement-ID | Beschreibung (Kurz) | Sprint | Architektur | Klasse(n) | Methode(n) | Testfall(e)
---|---|---|---|---|---|---
F-START-1 | Startet Arbeitszyklus nach Starttaste | Sprint 1 | Core / Logic | System_Manager | startWorkingCycle() | UT1
F-START-2 | System stoppt innerhalb von 100 ms | Sprint 1 | Core / Logic | System_Manager | stopSystem() | UT2
F-START-3 | Prüft kritische Komponenten in <2 s | Sprint 1 | Core / Logic | System_Manager | checkCriticalComponents() | UT3
F-SICHERHEIT-1 | Temperaturüberwachung >80°C | Sprint 1 | Safety | Safety_Monitor | monitorTemperature() | IT1
F-SICHERHEIT-2 | Abdeckung offen → Alarm | Sprint 1 | Safety | Safety_Monitor | monitorCover() | IT2
F-SICHERHEIT-3 | Motorblockade erkennen | Sprint 1 | Safety | Safety_Monitor | monitorMotorBlock() | IT3
NF-ZEIT-1 | Notabschaltung ≤200 ms | Sprint 1 | Safety / Timing | Safety_Monitor | emergencyShutdown() | IT1


Komponenten Interaktion
1. Datenfluss:
   - Sensoren → Services → Manager → UI
   - (Pressure/Temp) → (Process) → (Display)

2. Kontrollfluss:
   - System_Manager → [Vacuum_Manager, Sealing_Manager] → Motor_Service

3. Sicherheitsüberwachung:
   - Safety_Monitor ← Services → System_Manager → UI_Manager
   - (überwacht)  ←  (Alarm)   →  (Shutdown)   →   (Warnung)