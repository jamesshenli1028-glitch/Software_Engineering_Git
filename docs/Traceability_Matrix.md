
# Traceability Matrix


| Requirement ID | Beschreibung | Komponente | Priorität | Begründung | Klasse | Sprint 1 |
|----------------|--------------|------------|-----------|------------|--------|----------|
| F-START-1 | System startet Arbeitszyklus nach Drücken der Starttaste | System_Manager | Mittel | Grundfunktionalität | System_Manager.startWorkingCycle() | JA |
| F-START-2 | System stoppt innerhalb von 100 ms nach Drücken der Stoptaste | System_Manager | Hoch | Sicherheitsrelevantes Stoppen | System_Manager.stopSystem() | JA |
| F-START-3 | System prüft vor Start alle kritischen Komponenten und meldet Status innerhalb von 2 s | System_Manager | Hoch | Vorstart-Sicherheitsprüfung | System_Manager.checkKomponents() | JA |
| F-SICHERHEIT-1 | Abschaltung bei >80 °C (±2 °C Genauigkeit) | Safety_Monitor | Kritisch | Kritische Sicherheitsfunktion | Safety_Monitor.temperaturSafety() | JA |
| F-SICHERHEIT-2 | Stoppt innerhalb von 200 ms bei geöffneter Abdeckung | Safety_Monitor | Kritisch | Kritische Sicherheitsfunktion | Safety_Monitor.abdeckungSafety() | JA |
| F-SICHERHEIT-3 | Abschaltung innerhalb von 200 ms bei Motorblockade | Safety_Monitor | Kritisch | Kritische Sicherheitsfunktion | Safety_Monitor.emergencyShutdown() | JA |
| F-SICHERHEIT-4 | Visuelle + akustische Warnung | UI_Manager | Hoch | Sicherheitsfeedback | UI_Manager.startShowProcess() | |
| F-BENUTZER-1 | Zustände: Bereit (Grün), In Betrieb (Gelb), Fehler (Rot) | UI_Manager | Mittel | Grundstatus-Anzeige | UI_Manager.setLED() | |
| NF-ZEIT-1 | Reaktionszeit auf Sicherheitsereignisse ≤200 ms bei 25°C | Safety_Monitor | Kritisch | Zeitkritisches Safety | Timer_Service.getTime() | JA |
| NF-BENUTZER-1 | Akustischer Alarm ≥70 dB in 1 m Entfernung | UI_Manager | Mittel | Sicherheitsalarm | UI_Manager.activateAlarm() | |
| NF-LEISTUNG-1 | Funktion auch bei Spannungsschwankungen | System_Manager | Hoch | Robustheitsanforderung | implemented via System_Manager internal monitoring / Watchdog | |
| F-VAKUUM-1 | Überwacht Kammerdruck mit 10 Hz Abtastrate | Vacuum_Manager | Mittel | Nach Safety in Sprint 2 | Vakuum_Manager.monitorPressure() | |
| F-VAKUUM-2 | Beendet Vakuumieren bei 100 mbar ±5 mbar | Vacuum_Manager | Hoch | Nach Safety in Sprint 2 | Vakuum_Manager.stopVakumming() | |
| F-VAKUUM-3 | Beginnt Versiegelung innerhalb von 200 ms nach Vakuumende | System_Manager | Hoch | Abhängig von Vakuum | Vakuum_Manager.startVakumming() | |
| F-VERSIEGELUNG-1 | Versiegelt Beutel automatisch nach Vakuumieren | Sealing_Manager | Hoch | Abhängig von Vakuum | Sealing_Manager.startSeeling() | |
| F-VERSIEGELUNG-2 | Versiegelungszeit: 2,0 s ±50 ms | Sealing_Manager | Hoch | Abhängig von Vakuum | Sealing_Manager.controlSealing() | |
| F-BENUTZER-2 | Visuelle Anzeige aus 5 m Entfernung klar erkennbar | UI_Manager | Mittel | UI-Optimierung später | UI_Manager.startShowProcess() |  |
| NF-ZEIT-2 | Genauigkeit Versiegelungszeit ±50 ms | Sealing_Manager | Hoch | Abhängig von Sealing | Sealing_Manager.start() / control() |  |


---