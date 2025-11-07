# SW Design – Klasse / Methoden Beschreibung

# System_Manager

| Methode | Beschreibung | Requirement ID |
|---------|--------------|----------------|
| startWorkingCycle() | Startet Arbeitszyklus nach Starttaste | F-START-1 |
| stopSystem() | Stoppt System normal | F-START-2 |
| checkCriticalComponents() | Prüft Komponenten in <2s | F-START-3 |

# Safety_Monitor

| Methode | Beschreibung | Requirement ID |
|---------|--------------|----------------|
| monitorTemperature() | Überwacht kontinuierlich Temperatur (>80°C ±2°C) | F-SICHERHEIT-1 |
| monitorCover() | Überwacht Abdeckung in Echtzeit | F-SICHERHEIT-2 |
| monitorMotorBlock() | Erkennt Motorblockaden | F-SICHERHEIT-3 |
| emergencyShutdown() | Löst Notabschaltung in ≤200ms aus | NF-ZEIT-1 |



Komponenten Interaktion
1. Datenfluss:
   - Sensoren → Services → Manager → UI
   - (Pressure/Temp) → (Process) → (Display)

2. Kontrollfluss:
   - System_Manager → [Vacuum_Manager, Sealing_Manager] → Motor_Service

3. Sicherheitsüberwachung:
   - Safety_Monitor ← Services → System_Manager → UI_Manager
   - (überwacht)  ←  (Alarm)   →  (Shutdown)   →   (Warnung)