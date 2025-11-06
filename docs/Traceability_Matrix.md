
# Traceability Matrix

| Requirement-ID | Beschreibung | Priorität | Komponente |
|----------------|-------------|-----------|------------|
| F-START-1 | System startet Arbeitszyklus nach Drücken der Starttaste | Mittel | System_Manager |
| F-START-2 | System stoppt innerhalb von 100 ms nach Drücken der Stoptaste | Hoch | System_Manager |
| F-START-3 | System prüft vor Start alle kritischen Komponenten und meldet Status innerhalb von 2 s | Hoch | System_Manager |
| F-VAKUUM-1 | Überwacht Kammerdruck mit 10 Hz Abtastrate | Mittel | Vacuum_Manager |
| F-VAKUUM-2 | Beendet Vakuumieren bei 100 mbar ±5 mbar | Hoch | Vacuum_Manager |
| F-VAKUUM-3 | Beginnt Versiegelung innerhalb von 200 ms nach Vakuumende | Hoch | System_Manager |
| F-VERSIEGELUNG-1 | Versiegelt Beutel automatisch nach Vakuumieren | Hoch | Sealing_Manager |
| F-VERSIEGELUNG-2 | Versiegelungszeit: 2,0 s ±50 ms | Hoch | Sealing_Manager |
| F-SICHERHEIT-1 | Abschaltung bei >80 °C (±2 °C Genauigkeit) | Kritisch | Safety_Monitor |
| F-SICHERHEIT-2 | Stoppt innerhalb von 200 ms bei geöffneter Abdeckung | Kritisch | Safety_Monitor |
| F-SICHERHEIT-3 | Abschaltung innerhalb von 200 ms bei Motorblockade | Kritisch | Safety_Monitor |
| F-SICHERHEIT-4 | Visuelle Warnung: 2 Hz blinkende rote LED, Akustischer Alarm ≥70 dB, ≥5 s | Hoch | UI_Manager |
| F-BENUTZER-1 | Zustände: Bereit (Grün), In Betrieb (Gelb), Fehler (Rot) | Mittel | UI_Manager |
| F-BENUTZER-2 | Visuelle Anzeige aus 5 m Entfernung klar erkennbar | Mittel | UI_Manager |
| NF-ZEIT-1 | Reaktionszeit auf Sicherheitsereignisse ≤200 ms bei 25°C | Kritisch | Safety_Monitor |
| NF-ZEIT-2 | Genauigkeit Versiegelungszeit ±50 ms | Hoch | Sealing_Manager |
| NF-BENUTZER-1 | Akustischer Alarm ≥70 dB in 1 m Entfernung | Mittel | UI_Manager |
| NF-LEISTUNG-1 | Funktion auch bei Spannungsschwankungen | Hoch | System_Manager |
