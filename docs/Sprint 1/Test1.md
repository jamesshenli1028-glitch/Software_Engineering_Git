## **1. Ziel der Tests** 
Das Ziel der Tests ist die Verifikation und Validierung der Hauptfunktionen des Systems System_Manager und Safety_Monitor hinsichtlich funktionaler Korrektheit, Sicherheit und Benutzerinteraktion. Die Tests stellen sicher, dass:
- Arbeitszyklus korrekt gestartet und gestoppt wird
- Kritische Komponenten vor Start geprüft werden
- Sicherheitsrelevante Ereignisse (Temperatur, Abdeckung, Motorblockade) korrekt erkannt werden
- Zeitkritische Sicherheitsaktionen innerhalb ≤200 ms ausgeführt werden
- UI-Feedback visuell und akustisch korrekt angezeigt wird


## **2. Testarten und Abdeckung** 
### 2.1 Unit Tests
Ziel: Prüfung der kleinsten Testeinheiten (Methoden in System_Manager und Safety_Monitor)

***Beispielsweise getestet:***
- Start/Stop Zyklus (startWorkingCycle, stopSystem)
- Prüfung kritischer Komponenten (checkCriticalComponents)
- Notabschaltung (emergencyShutdown)

### 2.2 Integration Tests
Ziel: Überprüfung der Zusammenarbeit mehrerer Module und korrekter Abläufe bei Sicherheits- und Systemfunktionen

***Beispielsweise getestet:***
- Temperaturüberschreitung → Safety_Monitor → Notabschaltung → System_Manager stoppt Zyklus
- Abdeckung offen → Safety_Monitor → UI_Manager Alarm (LED + akustisch)
- Motorblock → Safety_Monitor → System_Manager → Sealing_Manager startet Versiegelung
- Zeitkritische Reaktionen ≤200 ms bei Sicherheitsereignissen

## **3. Teststrategie**
- Kombination aus automatisierten Unit-Tests und manuellen Tests für Integration
- Iterative Tests nach jeder Änderung der Kernlogik
- Regressionstests nach Anpassungen der Sicherheitsüberwachung

***Testumgebung:***
- Simulierte Sensoren für Temperatur, Abdeckung, Motorblock
- Timer-Service zur Messung zeitkritischer Reaktionen
- JUnit für automatisierte Unit-Tests
- Logging- und Timing-Tools zur Überprüfung der Reaktionszeiten

## **4. Testumfang**
***In-Scope***
Start/Stop Zyklus
- Prüfung kritischer Komponenten
- Sicherheitsüberwachung (Temperatur, Abdeckung, Motorblock)
- UI: visuelle + akustische Rückmeldung

***Out-of-Scope***
- Vakuum- und Sealing-Manager
- Hardware-Eigenschaften außerhalb Softwarebereich
- Langzeitverhalten der Maschine