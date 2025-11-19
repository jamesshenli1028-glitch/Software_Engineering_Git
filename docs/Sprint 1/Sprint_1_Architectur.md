# SW Design – Klasse / Methoden Beschreibung

# System_Manager

| Methode | Beschreibung | Requirement ID | Erweiterte Funktionale Zuordnung |
|---------|--------------|----------------| ---------------------------------|
| startWorkingCycle() | Startet Arbeitszyklus nach Starttaste | F-START-1 | Startet Hauptarbeitszyklus; prüft state==READY; setzt cycleActive=true |
| stopSystem() | Stoppt System normal | F-START-2 | Stoppt System in ≤100ms, setzt cycleActive=false |
| checkCriticalComponents() | Prüft Komponenten in <2s | F-START-3 | Führt Sensorcheck durch und liefert Status innerhalb von 2s |

# Safety_Monitor

| Methode | Beschreibung | Requirement ID | Erweiterte Funktionale Zuordnung |
|---------|--------------|----------------| ---------------------------------|
| monitorTemperature() | Überwacht kontinuierlich Temperatur (>80°C ±2°C) | F-SICHERHEIT-1 | Überwacht Temperatur kontinuierlich, löst shutdown >80°C aus |
| monitorCover() | Überwacht Abdeckung in Echtzeit | F-SICHERHEIT-2 | Überprüft Abdeckung in Echtzeit; aktiviert Alarm bei Offen |
| monitorMotorBlock() | Erkennt Motorblockaden | F-SICHERHEIT-3 | Erkennt Motorblockaden; triggert emergencyShutdown() |
| emergencyShutdown() | Löst Notabschaltung in ≤200ms aus | NF-ZEIT-1 | Gewährleistet Abschaltzeit ≤200ms |



Komponenten Interaktion
1. Datenfluss:
   - Sensoren → Services → Manager → UI
   - (Pressure/Temp) → (Process) → (Display)

2. Kontrollfluss:
   - System_Manager → [Vacuum_Manager, Sealing_Manager] → Motor_Service

3. Sicherheitsüberwachung:
   - Safety_Monitor ← Services → System_Manager → UI_Manager
   - (überwacht)  ←  (Alarm)   →  (Shutdown)   →   (Warnung)