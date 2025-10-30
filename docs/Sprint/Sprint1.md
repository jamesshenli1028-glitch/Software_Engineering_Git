# Sprint 1 Requirements Traceability Matrix

| Requirement ID | Beschreibung | Priorität | Komponente | Sprint 1 | Begründung |
|---------------|--------------|-----------|------------|----------|------------|
| F-START-1 | System startet Arbeitszyklus nach Drücken der Starttaste | Mittel | System_Manager | JA | Grundfunktionalität |
| F-START-2 | System stoppt innerhalb von 100 ms nach Drücken der Stoptaste | Hoch | System_Manager | A | Sicherheitsrelevantes Stoppen |
| F-START-3 | System prüft vor Start alle kritischen Komponenten und meldet Status innerhalb von 2 s | Hoch | System_Manager | JA | Vorstart-Sicherheitsprüfung |
| F-SICHERHEIT-1 | Abschaltung bei >80 °C (±2 °C Genauigkeit) | Kritisch | Safety_Monitor |  JA | Kritische Sicherheitsfunktion |
| F-SICHERHEIT-2 | Stoppt innerhalb von 200 ms bei geöffneter Abdeckung | Kritisch | Safety_Monitor | JA | Kritische Sicherheitsfunktion |
| F-SICHERHEIT-3 | Abschaltung innerhalb von 200 ms bei Motorblockade | Kritisch | Safety_Monitor | JA | Kritische Sicherheitsfunktion |
| F-SICHERHEIT-4 | Visuelle + akustische Warnung | Hoch | UI_Manager |  JA | Sicherheitsfeedback |
| F-BENUTZER-1 | Zustände: Bereit (Grün), In Betrieb (Gelb), Fehler (Rot) | Mittel | UI_Manager | JA | Grundstatus-Anzeige |
| NF-ZEIT-1 | Reaktionszeit auf Sicherheitsereignisse ≤200 ms bei 25°C | Kritisch | Safety_Monitor | JA | Zeitkritisches Safety |
| NF-BENUTZER-1 | Akustischer Alarm ≥70 dB in 1 m Entfernung | Mittel | UI_Manager | JA | Sicherheitsalarm |
| NF-LEISTUNG-1 | Funktion auch bei Spannungsschwankungen | Hoch | System_Manager | JA | Robustheitsanforderung |
| F-VAKUUM-1 | Überwacht Kammerdruck mit 10 Hz Abtastrate | Mittel | Vacuum_Manager | NEIN | Nach Safety in Sprint 2 |
| F-VAKUUM-2 | Beendet Vakuumieren bei 100 mbar ±5 mbar | Hoch | Vacuum_Manager | NEIN | Nach Safety in Sprint 2 |
| F-VAKUUM-3 | Beginnt Versiegelung innerhalb von 200 ms nach Vakuumende | Hoch | System_Manager | NEIN | Abhängig von Vakuum |
| F-VERSIEGELUNG-1 | Versiegelt Beutel automatisch nach Vakuumieren | Hoch | Sealing_Manager | NEIN | Abhängig von Vakuum |
| F-VERSIEGELUNG-2 | Versiegelungszeit: 2,0 s ±50 ms | Hoch | Sealing_Manager | NEIN | Abhängig von Vakuum |
| F-BENUTZER-2 | Visuelle Anzeige aus 5 m Entfernung klar erkennbar | Mittel | UI_Manager | NEIN | UI-Optimierung später |
| NF-ZEIT-2 | Genauigkeit Versiegelungszeit ±50 ms | Hoch | Sealing_Manager | NEIN | Abhängig von Sealing |

---
