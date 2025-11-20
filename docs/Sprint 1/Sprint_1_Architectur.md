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


# System_Manager – Erweiterte Traceability Matrix

| Methode | Beschreibung | Requirement ID | Erweiterte Funktionale Zuordnung | Testfall-ID | Test-Level | Testergebnis | Bemerkung |
|---------|--------------|----------------|---------------------------------|-------------|------------|--------------|-----------|
| startWorkingCycle() | Startet Arbeitszyklus nach Starttaste | F-START-1 | Startet Hauptarbeitszyklus; prüft state==READY; setzt cycleActive=true | UT1 | Unit | ✔ Bestanden | Zyklus startet korrekt |
| stopSystem() | Stoppt System normal | F-START-2 | Stoppt System in ≤100ms, setzt cycleActive=false | UT2 | Unit | ✔ Bestanden | System stoppt zeitgerecht |
| checkCriticalComponents() | Prüft Komponenten in <2s | F-START-3 | Führt Sensorcheck durch und liefert Status innerhalb von 2s | UT3 | Unit | ✔ Bestanden | Alle kritischen Komponenten geprüft |

# Safety_Monitor – Erweiterte Traceability Matrix

| Methode | Beschreibung | Requirement ID | Erweiterte Funktionale Zuordnung | Testfall-ID | Test-Level | Testergebnis | Bemerkung |
|---------|--------------|----------------|---------------------------------|-------------|------------|--------------|-----------|
| monitorTemperature() | Überwacht kontinuierlich Temperatur (>80°C ±2°C) | F-SICHERHEIT-1 | Überwacht Temperatur kontinuierlich, löst shutdown >80°C aus | IT1 | Integration | ✔ Bestanden | Notabschaltung bei >80°C korrekt |
| monitorCover() | Überwacht Abdeckung in Echtzeit | F-SICHERHEIT-2 | Überprüft Abdeckung in Echtzeit; aktiviert Alarm bei Offen | IT2 | Integration | ✘ Fehlverhalten | LED verzögert, Alarm nicht sofort |
| monitorMotorBlock() | Erkennt Motorblockaden | F-SICHERHEIT-3 | Erkennt Motorblockaden; triggert emergencyShutdown() | IT3 | Integration | ✔ Bestanden | Motorblock korrekt erkannt |
| emergencyShutdown() | Löst Notabschaltung in ≤200ms aus | NF-ZEIT-1 | Gewährleistet Abschaltzeit ≤200ms | IT1, IT2, IT3 | Integration | ✔ / ✘ | Zeitkritische Notabschaltungen geprüft |



Komponenten Interaktion
1. Datenfluss:
   - Sensoren → Services → Manager → UI
   - (Pressure/Temp) → (Process) → (Display)

2. Kontrollfluss:
   - System_Manager → [Vacuum_Manager, Sealing_Manager] → Motor_Service

3. Sicherheitsüberwachung:
   - Safety_Monitor ← Services → System_Manager → UI_Manager
   - (überwacht)  ←  (Alarm)   →  (Shutdown)   →   (Warnung)