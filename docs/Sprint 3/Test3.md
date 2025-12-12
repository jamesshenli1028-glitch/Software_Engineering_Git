# Test3 – Software Test Sprint 3

## 1. Ziel der Tests
Das Ziel der Tests ist die Verifikation und Validierung der Hauptfunktionen des Systems **SystemManager**, **VacuumManager**, **SealingManager** und **SafetyMonitor** hinsichtlich funktionaler Korrektheit, Sicherheit und Benutzerinteraktion.  

Die Tests stellen sicher, dass:
- Arbeitszyklus korrekt gestartet und gestoppt wird
- Vakuum- und Versiegelungsprozesse korrekt ablaufen
- Sicherheitsrelevante Ereignisse (Temperatur, Cover, Motorblockade) korrekt erkannt werden
- Zeitkritische Sicherheitsaktionen innerhalb ≤200 ms ausgeführt werden
- UI-Feedback visuell und akustisch korrekt angezeigt wird

---

## 2. Testarten und Abdeckung

### 2.1 Unit Tests (UT)
Ziel: Prüfung einzelner Methoden und Komponenten

**Beispiele:**
- Start/Stop Zyklus (`SystemManager.startWorkingCycle()`, `SystemManager.stopSystem()`)
- Vakuumsteuerung (`VacuumManager.startVacuum()`, `VacuumManager.monitorPressure()`)
- Versiegelungssteuerung (`SealingManager.startSealing()`, `SealingManager.controlSealing()`)
- Sicherheitsmethoden (`SafetyMonitor.monitorTemperature()`, `SafetyMonitor.monitorCover()`, `SafetyMonitor.monitorMotorBlock()`)
- Timerfunktionen (`TimerService.startTimer()`, `TimerService.onTimeout()`)

### 2.2 Integration Tests (IT)
Ziel: Überprüfung der Zusammenarbeit mehrerer Module und korrekter Ablauf der Prozessketten

**Beispiele:**
- Vakuum erreicht → SystemManager startet Versiegelung automatisch
- Überwachung von Temperatur, Cover und Motorblock während Vakuum- und Versiegelungsprozess
- Notabschaltung bei kritischen Ereignissen ≤200 ms
- UI zeigt Status LED/Display korrekt an

---

## 3. Teststrategie
- Kombination aus automatisierten Unit-Tests und manuellen Integrationstests
- Iterative Tests nach jeder Änderung der Kernlogik
- Regressionstests nach Anpassungen der Prozess- und Sicherheitsüberwachung
- Testumgebung:
  - Simulierte Sensoren für Druck, Temperatur, Abdeckung, Motorblock
  - TimerService zur Messung zeitkritischer Reaktionen
  - JUnit für Unit-Tests
  - Logging- und Timing-Tools zur Überprüfung der Reaktionszeiten

---

## 4. Testumfang

### In-Scope
| Bereich | Getestete Funktion | Beschreibung |
|---------|-----------------|-------------|
| Start/Stop Zyklus | `startWorkingCycle()`, `stopSystem()` | Überprüfung, dass der Arbeitszyklus korrekt gestartet und beendet wird |
| Vakuumprozess | `startVacuum()`, `monitorPressure()` | Vakuumprozess startet, überwacht Druck, beendet korrekt bei Zielunterdruck |
| Versiegelungsprozess | `startSealing()`, `controlSealing()` | Versiegelungszeit eingehalten, Prozess korrekt beendet |
| Sicherheitsüberwachung | `monitorDuringProcess()`, `emergencyShutdown()` | Temperatur, Cover, Motorblock permanent überwacht, Notabschaltung ≤200 ms |
| UI Feedback | `setLED()`, `activateAlarm()`, `startShowProcess()` | Visuelle und akustische Rückmeldung der Prozesszustände |

### Out-of-Scope
- Hardwaresteuerung der Pumpe oder des Heizelements
- Langzeitbetrieb über mehrere Zyklen
- Optimierte Event-Queue und Logging (folgt Sprint 4)

---
