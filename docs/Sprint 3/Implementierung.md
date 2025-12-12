# Sprint 3 – Implementierung

In Sprint 3 wurde die Implementierung auf Basis der Anforderungen aus Sprint 1 und 2 erweitert. Fokus lag auf der vollständigen Integration der **Vakuum- und Versiegelungsprozesse**, der **zeitkritischen Steuerung** und der **permanenten Sicherheitsüberwachung**.

---

## SystemManager

- **Start/Stop Zyklus:**  
  - `startWorkingCycle()` startet den Arbeitszyklus, prüft vorher kritische Komponenten.  
  - `stopSystem()` stoppt den Zyklus innerhalb von 100 ms.  
- **Prozesskoordination:**  
  - `handleVacuumDone()` startet automatisch den Versiegelungsprozess.  
  - `handleSealingDone()` verwaltet Abschlussaktionen.  
- **Event Handling:**  
  - Callbacks und Events vom VacuumManager und SealingManager werden verarbeitet.  
  - Asynchrone Steuerung teilweise implementiert, Optimierungen folgen Sprint 4.

---

## VacuumManager

- **Start Vakuumprozess:** `startVacuum()` aktiviert die Vakuumpumpe und initialisiert Drucküberwachung.  
- **Drucküberwachung:** `monitorPressure()` liest 10 Hz Sensordaten und prüft Zielunterdruck (100 mbar ±5 mbar).  
- **Prozessende:** `stopVacuum()` wird bei Zielunterdruck aufgerufen.  
- **Benachrichtigung:** `notifyVacuumDone()` sendet Signal an SystemManager.  

---

## SealingManager

- **Start Versiegelung:** `startSealing()` wird automatisch nach Vakuumende ausgelöst.  
- **Versiegelungssteuerung:** `controlSealing()` steuert Heizelement über Timer (2,0 s ±50 ms).  
- **Prozessende:** `notifySealingDone()` informiert SystemManager über Abschluss.  

---

## SafetyMonitor

- **Temperaturüberwachung:** `monitorTemperature()` prüft Temperaturgrenzen (≤80 °C ±2 °C).  
- **Cover-Überwachung:** `monitorCover()` reagiert auf geöffnete Abdeckung innerhalb 200 ms.  
- **Motorblockade:** `monitorMotorBlock()` erkennt Blockade und löst `emergencyShutdown()` aus.  
- **Sicherheitsaktionen:** Alle Notabschaltungen erfolgen innerhalb der geforderten 200 ms.  

---

## UIManager

- **LED-Zustände:** `setLED()` zeigt Status: Grün (Bereit), Gelb (In Betrieb), Rot (Fehler).  
- **Akustischer Alarm:** `activateAlarm()` ≥70 dB bei kritischen Ereignissen.  
- **Prozessanzeigen:** `startShowProcess()` visualisiert Vakuum- und Versiegelungsstatus.  

---

## TimerService

- **Zeitkritische Steuerung:** `startTimer()` startet Timer für Versiegelungs- und andere Abläufe.  
- **Callback-Funktion:** `onTimeout()` wird bei Ablauf des Timers aufgerufen.  
- **Genauigkeit:** ±50 ms bei Versiegelungsprozess eingehalten.  

---

## Zusammenfassung

- Vollständige Implementierung der Kernprozesse (Vakuum → Versiegelung)  
- Zeitkritische Steuerung für Sicherheit und Prozessabläufe gewährleistet  
- Sicherheitsüberwachung permanent aktiv  
- UI zeigt Prozessstatus korrekt an  
- Optimierungen für Event Handling, Logging und UI-Animationen folgen in Sprint 4
