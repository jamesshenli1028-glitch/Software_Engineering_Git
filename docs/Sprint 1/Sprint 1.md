
# Sprint 1 – Überblick

In Sprint 1 kümmern wir uns um die Grundfunktionen der Vakuum- und Versiegelungsmaschine. Das Ziel ist, dass die Maschine überhaupt startet, stoppt und sicher läuft.


### Sprint Planning
Auswahl der dringendsten Anforderungen – Start/Stop-Tasten, Sicherheitsabschaltung bei Übertemperatur, Motorblockade oder geöffneter Abdeckung, grundlegende LED- und akustische Anzeigen.

### Requirements
Alle kritischen Funktionen auflisten, zugehörige Komponenten (System_Manager, Safety_Monitor, UI_Manager) und Methoden notieren.

### Sprint 1 – Anforderungen

| Requirement ID | Beschreibung | Komponente |
|----------------|---------------|-------------|
| F-START-1 | Arbeitszyklus starten | System_Manager |
| F-START-2 | Schnellstopp per Stopptaste | System_Manager |
| F-START-3 | Vorstart-Komponentenprüfung | System_Manager |
| F-SICHERHEIT-1 | Übertemperaturabschaltung | Safety_Monitor |
| F-SICHERHEIT-2 | Stopp bei geöffneter Abdeckung | Safety_Monitor |
| F-SICHERHEIT-3 | Motorblockadeabschaltung | Safety_Monitor |
| NF-ZEIT-1 | Begrenzte Reaktionszeit für Sicherheitsereignisse ≤200 ms | Safety_Monitor |

### Design
Skizze der wichtigsten Klassen und wie sie zusammenarbeiten:  
- **System_Manager** steuert Start/Stop  
- **Safety_Monitor** überwacht Sicherheit  
- **UI_Manager** zeigt Status an

### Implementierung
Erste Methoden implementieren, z. B.  
- `System_Manager.startWorkingCycle()`  
- `Safety_Monitor.temperaturSafety()`  
- `UI_Manager.setLED()`  

Noch keine Vakuum- oder Versiegelungssteuerung, die kommt später in Sprint 2.

---

## Ziel von Sprint 1
- Maschine startet und stoppt zuverlässig.  
- Sicherheitsabschaltungen funktionieren.  
- Statusanzeigen (LED, Alarm) zeigen korrekte Zustände.  
- Die Basis für spätere Vakuum- und Versiegelungsfunktionen ist gelegt.

---



## Sprint 1 – Software Architektur, Implementierung und Testbericht

## 1. Vergleich von Architektur, Design und Implementierung

Beim Abgleich der geplanten Software-Architektur und des Software-Designs mit der in Sprint 1 implementierten Lösung ergeben sich mehrere Abweichungen. Diese Abweichungen sind typisch für eine initiale Implementierung.

### 1.1 Abweichungen in der Architektur

| Abweichung | Beschreibung |
|------------|--------------|
| A1 – Hardware-Abstraktion | HAL-Schicht geplant für SensorInterface, HeaterControl, DisplayDriver. Implementiert ist nur DisplayDriver. |
| A2 – SafetyManager | Singleton implementiert, Methoden (`monitorTemperature`, `monitorCover`, `monitorMotorBlock`) teilweise stubben. |
| A3 – UI-Komponente | Modulare UI mit LED, Summer geplant. Aktuell nur Konsolen- oder DisplayController-Ausgabe. |

### 1.2 Abweichungen im Design

| Abweichung | Beschreibung |
|------------|--------------|
| D1 – Sequenzdiagramm | Geplant: Eingabe → Validierung → Anzeige → Bestätigung. Ist: Anzeige direkt nach Sollwertsetzung. |
| D2 – Event-Mechanismus | Geplant: asynchrone Callbacks. Ist: synchrone Funktionsaufrufe. |
| D3 – Validierungsmethoden | Temperaturvalidierung direkt in `Temperature_Service::setTemperature()`, nicht in separater Methode. |

### 1.3 Abweichungen in Traceability

| Abweichung | Beschreibung |
|------------|--------------|
| T1 – Nicht implementierte Requirements | Sicherheitslogik (F-SICHERHEIT-4), Vakuum- und Versiegelungslogik (F-VAKUUM, F-VERSIEGELUNG) und UI-Optimierungen erst in Sprint 2/3. |

---

## 2. Abweichungsanalyse Sprint 1

### 2.1 System_Manager
- Start/Stop Zyklus implementiert
- Prüfung kritischer Komponenten korrekt
- Erweiterung für Vakuum- und Versiegelungssteuerung fehlt

### 2.2 Safety_Monitor
- Singleton implementiert
- Methoden stubben nur Konsolenausgabe
- Asynchrone Reaktionen, visuelle + akustische Warnungen fehlen

### 2.3 Hardware-Abstraktion
- Nur DisplayDriver implementiert
- Sensor- und Heizerweiterungen folgen Sprint 2

### 2.4 Vakuum- und Versiegelungs-Manager
- Singleton-Struktur vorhanden
- Funktionale Logik noch nicht integriert

---

## 3. Erkenntnisse für Sprint 2 / 3

| Erkenntnis | Geplante Änderung |
|------------|-----------------|
| UI modularisieren | Einführung eines UIService zwischen Controller und DisplayDriver |
| Logikschicht erweitern | TemperatureController erhält periodische update()-Routine, Sensorwerte einlesen, Heizleistung regeln |
| SafetyManager kritisch | Implementierung mit Grenzwertkontrollen, Sensorüberwachung, Shutdown-Logik |
| HAL Schnittstellen | Mock-Sensor und Mock-Heater einführen |
| Event-Mechanismus | Asynchrone Callbacks und Observer Pattern für Events einführen |
| Nicht-funktionale Anforderungen | Testkonzept für Reaktionszeiten, akustische Alarmstärke, Lesbarkeit der UI erstellen |

---

## 4. Tests Sprint 1

### Unit Tests
- **UT1 – Start Arbeitszyklus:** Start korrekt ausgelöst, Systemstatus RUNNING, `cycleActive = true`   
- **UT2 – Stop System:** Stop korrekt ≤100 ms, Systemstatus STOPPED, `cycleActive = false`   
- **UT3 – Prüfen kritischer Komponenten:** Status OK ≤2 s 

### Integration Tests
- **IT1 – Temperaturüberwachung & Notabschaltung:** Temperatur >82 °C erkannt, Notabschaltung <200 ms, Systemstatus ERROR   
- **IT2 – Abdeckung offen → Alarm:** LED ROT, akustischer Alarm ≥70 dB   
- **IT3 – Motorblock & Versiegelung:** Motorblock erkannt, Notabschaltung ausgelöst, Versiegelung startet ≤200 ms nach Vakuumende 

---

## 5. Baseline Sprint 1

- Implementiert: System_Manager, Safety_Monitor (Singleton + Methodenstubs), DisplayController, Temperature_Service, Motor_Service, Pressure_Service, Vakuum_Manager (Singleton), DeviceInterface  
- Getestet: Start/Stop, kritische Komponenten, Temperaturüberwachung, Notabschaltung, UI minimal  
- Nicht implementiert: SensorInterface, HeaterControl, vollständige UI, Vakuum-/Sealing-Logik, asynchrone Events, SafetyManager vollständige Logik  
- Dokumentation: Traceability Matrix, Unit- und Integrationstests, Architekturdiagramm

