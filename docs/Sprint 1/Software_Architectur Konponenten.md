# SW Design – Klasse / Methoden Beschreibung

System_Manager
| Methode | Beschreibung | Requirement ID|
|---------------------|----------------| ----------------|
| startWorkingCycle() | Startet den Arbeitszyklus | F-START-1 |
| System_Manager → Vacuum_Manager.stopSystem() | Stoppt alle Prozesse | F-START-2 |
| checkKomponents() | Prüft kritische Komponenten vor Start | F-START-3 |
| System_Manager → Vacuum_Manager.startVakumming() | Startet Vakuumprozess | F-VAKUUM-3 |
| System_Manager → Sealing_Manager.startSealing() | Initialisiert Versiegelung | F-VERSIEGELUNG-1 |


Safety_Monitor
| Methode | Beschreibung | Requirement ID|
|---------------------|----------------| ----------------|
| temperaturSafety() | Prüft Temperatur | F-SICHERHEIT-1 |
| abdeckungSafety() | Prüft Abdeckung | F-SICHERHEIT-2 |
| MotorgSafety() | Prüft Motorblockade | F-SICHERHEIT-3 |
| emergencyShutdown() | Notabschaltung | NF-ZEIT-1 |
| activateAlarm() | Akustischer/visueller Alarm | NF-BENUTZER-1, F-SICHERHEIT-4 |


UI_Manager
| Methode | Beschreibung | Requirement ID|
|---------------------|----------------| ----------------|
| setLED() | Zeigt Systemzustände an | F-BENUTZER-1 |
| activateAlarm() | Akustischer Alarm ≥70 dB | NF-BENUTZER-1 |
| showStatus() | Visuelle Anzeige | F-BENUTZER-2, F-SICHERHEIT-4 |


Vacuum_Manager
| Methode | Beschreibung | Requirement ID|
|---------------------|----------------| ----------------|
| getPressure() | Überwacht Kammerdruck | F-VAKUUM-1 |
| stopVakumming() | Stoppt Vakuumprozess | F-VAKUUM-2 |
| startVakumming() | Startet Vakuumprozess | F-VAKUUM-3 |


Sealing_Manager
| Methode | Beschreibung | Requirement ID|
|---------------------|----------------| ----------------|
| startSealing() | Initialisiert Versiegelung | F-VERSIEGELUNG-1 |
| controlSealing() | Kontrolliert Versiegelungszeit ±50 ms | F-VERSIEGELUNG-2, NF-ZEIT-2 |


Komponenten Interaktion
1. Datenfluss:
   - Sensoren → Services → Manager → UI
   - (Pressure/Temp) → (Process) → (Display)

2. Kontrollfluss:
   - System_Manager → [Vacuum_Manager, Sealing_Manager] → Motor_Service

3. Sicherheitsüberwachung:
   - Safety_Monitor ← Services → System_Manager → UI_Manager
   - (überwacht)  ←  (Alarm)   →  (Shutdown)   →   (Warnung)