# Test2 – Software Test und Retrospective Sprint 2

## 1. Ziel der Tests
Das Ziel der Tests ist die Verifikation und Validierung der Hauptfunktionen des Systems **System_Manager** und **Safety_Monitor** hinsichtlich funktionaler Korrektheit, Sicherheit und Benutzerinteraktion. Die Tests stellen sicher, dass:

- Arbeitszyklus korrekt gestartet und gestoppt wird
- Kritische Komponenten vor Start geprüft werden
- Sicherheitsrelevante Ereignisse (Temperatur, Abdeckung, Motorblockade) korrekt erkannt werden
- Zeitkritische Sicherheitsaktionen innerhalb ≤200 ms ausgeführt werden
- UI-Feedback visuell und akustisch korrekt angezeigt wird

---

## 2. Testarten und Abdeckung

### 2.1 Unit Tests (UT)
Ziel: Prüfung der kleinsten Testeinheiten (Methoden in `System_Manager` und `Safety_Monitor`)

**Beispiele:**
- Start/Stop Zyklus (`startWorkingCycle()`, `stopSystem()`)
- Prüfung kritischer Komponenten (`checkCriticalComponents()`)
- Notabschaltung (`emergencyShutdown()`)

### 2.2 Integration Tests (IT)
Ziel: Überprüfung der Zusammenarbeit mehrerer Module und korrekter Abläufe bei Sicherheits- und Systemfunktionen

**Beispiele:**
- Temperaturüberschreitung → Safety_Monitor → Notabschaltung → System_Manager stoppt Zyklus
- Cover offen → Safety_Monitor → UI_Manager Alarm (LED + akustisch)
- Motorblock → Safety_Monitor → System_Manager → Sealing_Manager startet Versiegelung
- Zeitkritische Reaktionen ≤200 ms bei Sicherheitsereignissen

---

## 3. Teststrategie
- Kombination aus automatisierten Unit-Tests und manuellen Integrationstests
- Iterative Tests nach jeder Änderung der Kernlogik
- Regressionstests nach Anpassungen der Sicherheitsüberwachung
- Testumgebung:
  - Simulierte Sensoren für Temperatur, Abdeckung, Motorblock
  - TimerService zur Messung zeitkritischer Reaktionen
  - JUnit für automatisierte Unit-Tests
  - Logging- und Timing-Tools zur Überprüfung der Reaktionszeiten

---

## 4. Testumfang

### In-Scope
| Bereich | Getestete Funktion | Beschreibung |
|---------|-----------------|-------------|
| Start/Stop Zyklus | `startWorkingCycle()`, `stopSystem()` | Überprüfung, dass der Arbeitszyklus korrekt gestartet und beendet wird |
| Kritische Komponenten | `checkCriticalComponents()` | Sicherstellung, dass alle Sicherheitskomponenten vor Prozessstart geprüft werden |
| Sicherheitsüberwachung | `monitorDuringProcess()` | Überwachung von Temperatur, Abdeckung und Motorblock während des Vakuum- und Versiegelungsprozesses |
| Notabschaltung | `emergencyShutdown()` | Reaktionszeit ≤200 ms bei kritischen Sicherheitsereignissen |
| UI Feedback | `showVacuumStatus()`, `showSealingStatus()` | Visuelle (LED/Display) und akustische Rückmeldung der Prozesszustände |

### Out-of-Scope
- Steuerung der Vakuum- und Versiegelungsprozesse durch Hardware-Controller  
- Hardware-Eigenschaften (Pumpenleistung, Heizelemente, mechanische Toleranzen)  
- Langzeitverhalten der Maschine über mehrere Betriebszyklen  

---

## 5. Implementierte Komponenten

| Komponente       | Rolle                  | Verantwortlichkeiten |
|-----------------|-----------------------|--------------------|
| VacuumManager    | Application Layer     | Vakuumpumpe steuern, Druck überwachen, notify SystemManager |
| SealingManager   | Application Layer     | Versiegelungsprozess steuern, notify SystemManager |
| SystemManager    | Applikationsschicht    | Prozesskoordination, Timer starten, Event Handling |
| TimerService     | Core / Timing         | Verzögerungen, periodische Aufrufe |
| SafetyMonitor    | Safety Layer          | Temperatur, Cover, Motor überwachen, Notstopp |
| UIManager        | Präsentationsschicht   | Prozessstatus anzeigen (LED/Display) |

---

## 6. Traceability Matrix (Auszug Sprint 2)

| Requirement-ID | Beschreibung | Klasse/Methode | Testfall(e) |
|----------------|-------------|----------------|-------------|
| F-VACUUM-1     | Startet Vakuumprozess | VacuumManager.startVacuum() | UT4 |
| F-VACUUM-2     | Überwacht Drucksensor | VacuumManager.monitorPressure() | UT5 |
| F-SEAL-1       | Startet Versiegelung nach Vakuum | SealingManager.startSealing() | UT6 / IT4 |
| F-TIMER-1      | Timerfunktion | TimerService.startTimer() | UT7 |
| F-TIMER-2      | Timer-Callback | TimerService.onTimeout() | UT8 |
| F-SAFETY-4     | Safety während Prozesse | SafetyMonitor.monitorDuringProcess() | IT5 |

---

## 8. Retrospective Sprint 2

**Gut gelaufen:**
- Vollständige Umsetzung des Vakuum- und Versiegelungsprozesses
- Asynchrone Architektur etabliert (Threads, Timer, Callbacks)
- UI zeigt Status korrekt

**Probleme:**
- Optimierung der Event-Handhabung noch offen
- UI Animationen und Logging fehlen

**Verbesserungspotential:**
- Thread-Synchronisation und Event Queue stabilisieren
- Logging und Visualisierung weiter ausbauen
