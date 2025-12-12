# Sprint 3 – Überblick

In Sprint 3 liegt der Fokus auf der Erweiterung der Systemfunktionalität, insbesondere der vollständigen Implementierung der **Vakuum- und Versiegelungsprozesse**, der **zeitkritischen Prozesssteuerung** und der **erweiterten Sicherheitsüberwachung**.

---

### Sprint Planning
- Auswahl der Anforderungen für Sprint 3: automatische Prozesskette, erweiterte Sicherheitsüberwachung, Timersteuerung  
- Implementierung der Logik in **VacuumManager** und **SealingManager**  
- Integration von **TimerService** für zeitkritische Abläufe  
- Erweiterung des **SafetyMonitor** zur permanenten Überwachung während Prozesse  
- Anpassung des **UIManager**, um Vakuum- und Versiegelungsstatus anzuzeigen  

---

### Requirements
Alle kritischen Funktionen für Sprint 3 auflisten, zugehörige Komponenten und Methoden notieren.

### Sprint 3 – Anforderungen

| Requirement ID | Beschreibung | Komponente |
|----------------|---------------|-------------|
| F-START-1 | Arbeitszyklus starten nach Betätigung der Starttaste | SystemManager |
| F-START-2 | Stoppt Arbeitszyklus innerhalb 100 ms nach Stoptaste | SystemManager |
| F-START-3 | Prüft vor Start alle kritischen Komponenten, Statusmeldung ≤2 s | SystemManager |
| F-VAKUUM-1 | Überwacht Kammerdruck mit 10 Hz Abtastrate | VacuumManager |
| F-VAKUUM-2 | Beendet Vakuumprozess bei Zielunterdruck (100 mbar ±5 mbar) | VacuumManager |
| F-VAKUUM-3 | Startet Versiegelungsprozess automatisch innerhalb 200 ms nach Vakuumende | SystemManager / SealingManager |
| F-VERSIEGELUNG-1 | Vollautomatisches Versiegeln nach Vakuum | SealingManager |
| F-VERSIEGELUNG-2 | Versiegelungszeit 2,0 s ±50 ms | SealingManager |
| F-SICHERHEITABSCHALTUNG-1 | Abschaltung bei >80 °C ±2 °C | SafetyMonitor |
| F-SICHERHEITABSCHALTUNG-2 | Stoppt innerhalb 200 ms bei geöffneter Abdeckung | SafetyMonitor |
| F-SICHERHEITABSCHALTUNG-3 | Abschaltung bei Motorblockade ≤200 ms | SafetyMonitor |
| F-SICHERHEITABSCHALTUNG-4 | Visuelle (2 Hz LED) + akustische Warnung (≥70 dB, ≥5 s) | UIManager |
| F-BENUTZERFEEDBACK-1 | LED-Zustände: Grün (Bereit), Gelb (In Betrieb), Rot (Fehler) | UIManager |
| F-BENUTZERFEEDBACK-2 | Anzeige aus 5 m Entfernung klar erkennbar | UIManager |
| NF-ZEIT-1 | Reaktionszeit Sicherheitsereignisse ≤200 ms | SafetyMonitor |
| NF-ZEIT-2 | Genauigkeit Versiegelungszeit ±50 ms | TimerService / SealingManager |
| NF-BENUTZERFEEDBACK-1 | Akustischer Alarm ≥70 dB bei 1 m Entfernung | UIManager |
| NF-LEISTUNG-1 | Funktion auch bei Spannungsschwankungen | SystemManager |

---

### Design
Skizze der wichtigsten Klassen und wie sie zusammenarbeiten:  
- **SystemManager** koordiniert Arbeitszyklus, Vakuum- und Versiegelungsprozesse  
- **VacuumManager** steuert Vakuumpumpe, überwacht Druck, notify SystemManager  
- **SealingManager** steuert Versiegelung, notify SystemManager  
- **SafetyMonitor** überwacht Temperatur, Cover, Motor und führt Notabschaltungen aus  
- **UIManager** zeigt Statusanzeigen (LED, Display) und akustischen Alarm  
- **TimerService** sorgt für zeitkritische Verzögerungen und periodische Aufrufe  

---

### Implementierung
Erste Methoden implementieren, z. B.  
- `SystemManager.startWorkingCycle()`  
- `SystemManager.stopSystem()`  
- `SystemManager.checkCriticalComponents()`  
- `VacuumManager.startVacuum()`  
- `VacuumManager.monitorPressure()`  
- `SealingManager.startSealing()`  
- `SealingManager.controlSealing()`  
- `SafetyMonitor.monitorTemperature()`  
- `SafetyMonitor.monitorCover()`  
- `SafetyMonitor.monitorMotorBlock()`  
- `UIManager.setLED()` / `UIManager.activateAlarm()`  
- `TimerService.startTimer()` / `TimerService.onTimeout()`

Noch keine vollständigen Optimierungen für Event-Handling, Logging und UI-Animationen.

---

## Ziel von Sprint 3
- Vollautomatische Vakuum- und Versiegelungsprozesse  
- Zeitkritische Abläufe präzise gesteuert  
- Sicherheitsüberwachung permanent aktiv  
- Statusanzeigen und akustischer Alarm korrekt angezeigt  
- Basis für spätere Optimierungen der asynchronen Events und UI-Visualisierung  

---

## Sprint 3 – Software Architektur, Implementierung und Testbericht

## 1. Vergleich von Architektur, Design und Implementierung

Beim Abgleich der geplanten Software-Architektur und des Software-Designs mit der in Sprint 3 implementierten Lösung ergeben sich folgende Punkte:

### 1.1 Abweichungen in der Architektur

| Abweichung | Beschreibung |
|------------|--------------|
| A1 – Event-Mechanismus | Callbacks implementiert, Optimierung der Event Queue noch offen |
| A2 – SafetyMonitor | Erweiterte Sicherheitsüberwachung implementiert, weitere Feineinstellungen folgen |
| A3 – UI-Komponente | Grundlegende Statusanzeigen und Alarm aktiv, Animationen fehlen |

### 1.2 Abweichungen im Design

| Abweichung | Beschreibung |
|------------|--------------|
| D1 – Prozesskoordination | Sequenz korrekt implementiert, aber Timer-Genauigkeit noch im Feintuning |
| D2 – Vakuum/Sealing-Logik | Vollständig implementiert, Logging fehlt noch |
| D3 – Thread-Synchronisation | Basis vorhanden, Optimierung für Stabilität offen |

### 1.3 Abweichungen in Traceability

| Abweichung | Beschreibung |
|------------|--------------|
| T1 – Nicht implementierte Anforderungen | Optimierung von asynchronen Events, Logging, UI-Animationen noch offen |

---

## 2. Abweichungsanalyse Sprint 3

### 2.1 SystemManager
- Prozesskoordination Vakuum → Versiegelung implementiert  
- Start/Stop Zyklus korrekt  
- Event-Handling teilweise noch optimierungsbedürftig  

### 2.2 SafetyMonitor
- Permanente Überwachung implementiert  
- Notabschaltung funktioniert zeitkritisch  

### 2.3 VacuumManager / SealingManager
- Vollständige Prozesssteuerung implementiert  
- Timer-gesteuerte Abläufe für Versiegelung vorhanden  

### 2.4 UIManager / TimerService
- Statusanzeigen korrekt, Alarm funktional  
- TimerService liefert Verzögerungen und periodische Aufrufe  

---

## 3. Erkenntnisse für Sprint 4

| Erkenntnis | Geplante Änderung |
|------------|-----------------|
| Event-Handling optimieren | Thread-Synchronisation und Event Queue stabilisieren |
| Logging erweitern | Alle Prozessschritte sollen protokolliert werden |
| UI-Visualisierung | Animationen für Prozessstatus integrieren |
| Timer-Feinjustierung | Genauigkeit und Synchronisation verbessern |

---

## 4. Tests Sprint 3

### Unit Tests
- **UT1 – Start Arbeitszyklus:** Start korrekt ausgelöst, Systemstatus RUNNING, `cycleActive = true`  
- **UT2 – Stop System:** Stop korrekt ≤100 ms, Systemstatus STOPPED, `cycleActive = false`  
- **UT3 – Prüfen kritischer Komponenten:** Status OK ≤2 s  
- **UT4 – Vakuumstart / Drucküberwachung**  
- **UT5 – Vakuumende bei Zielunterdruck**  
- **UT6 – Versiegelungsstart nach Vakuum**  
- **UT7 – Versiegelungszeit-Steuerung**  
- **UT8 – Timer-Genauigkeit / Versiegelungszeit**

### Integration Tests
- **IT1 – Temperatur >80 °C → Notabschaltung**  
- **IT2 – Cover offen → Notabschaltung / Alarm**  
- **IT3 – Motorblock → Notabschaltung**  
- **IT4 – Benachrichtigung SystemManager / Start Versiegelung**  
- **IT5 – Sicherheitsüberwachung während Prozess**

---

## 5. Baseline Sprint 3

- Implementiert: SystemManager, VacuumManager, SealingManager, SafetyMonitor, UIManager, TimerService  
- Getestet: Start/Stop, Vakuum- und Versiegelungsprozess, Sicherheitsüberwachung, Timersteuerung  
- Nicht implementiert: Optimierung asynchroner Events, Logging, UI-Animationen  
- Dokumentation: Traceability Matrix, Unit- und Integrationstests, UML-Diagramme

