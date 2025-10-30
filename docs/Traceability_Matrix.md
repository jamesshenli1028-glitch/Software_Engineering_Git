# Traceability Matrix

Requirement: F-START-1
Beschreibung: System startet Arbeitszyklus nach Drücken der Starttaste
Priorität: Mittel
Komponente: System_Manager
----------------------------------
Requirement: F-START-2
Beschreibung: System stoppt innerhalb von 100 ms nach Drücken der Stoptaste
Priorität: Hoch
Komponente: System_Manager
----------------------------------
Requirement: F-START-3
Beschreibung: System prüft vor Start alle kritischen Komponenten und meldet Status innerhalb von 2 s
Priorität: Hoch
Komponente: System_Manager                   	
----------------------------------
Requirement: F-VAKUUM-1
Beschreibung: Überwacht Kammerdruck mit 10 Hz Abtastrate
Priorität: Mittel
Komponente: Vacuum_Manager
----------------------------------
Requirement: F-VAKUUM-2
Beschreibung: Beendet Vakuumieren bei 100 mbar ±5 mbar
Priorität: Hoch
Komponente: Vacuum_Manager
----------------------------------
Requirement: F-VAKUUM-3
Beschreibung: Beginnt Versiegelung innerhalb von 200 ms nach Vakuumende
Priorität: Hoch
Komponente: System_Manager
----------------------------------
Requirement: F-VERSIEGELUNG-1
Beschreibung: Versiegelt Beutel automatisch nach Vakuumieren
Priorität: Hoch
Komponente: Sealing_Manager
----------------------------------
Requirement: F-VERSIEGELUNG-2
Beschreibung: Versiegelungszeit: 2,0 s ±50 ms
Priorität: Hoch
Komponente: Sealing_Manager
----------------------------------
Requirement: F-SICHERHEIT-1
Beschreibung: Abschaltung bei >80 °C (±2 °C Genauigkeit)
Priorität: Kritisch
Komponente: Safety_Monitor
----------------------------------
Requirement: F-SICHERHEIT-2
Beschreibung: Stoppt innerhalb von 200 ms bei geöffneter Abdeckung
Priorität: Kritisch
Komponente: Safety_Monitor
----------------------------------
Requirement: F-SICHERHEIT-3
Beschreibung: Abschaltung innerhalb von 200 ms bei Motorblockade
Priorität: Kritisch
Komponente: Safety_Monitor
----------------------------------
Requirement: F-SICHERHEIT-4
Beschreibung: Visuelle Warnung: 2 Hz blinkende rote LED. Akustischer Alarm: ≥70 dB, ≥5 s
Priorität: Hoch
Komponente: UI_Manager               
----------------------------------
Requirement: F-BENUTZER-1
Beschreibung: Zustände: Bereit (Grün), In Betrieb (Gelb), Fehler (Rot)
Priorität: Mittel
Komponente: UI_Manager
----------------------------------
Requirement: F-BENUTZER-2
Beschreibung: Visuelle Anzeige aus 5 m Entfernung klar erkennbar
Priorität: Mittel
Komponente: UI_Manager
----------------------------------
Requirement: NF-ZEIT-1
Beschreibung: Reaktionszeit auf Sicherheitsereignisse ≤200 ms bei 25°C
Priorität: Kritisch
Komponente: Safety_Monitor
----------------------------------
Requirement: NF-ZEIT-2
Beschreibung: Genauigkeit Versiegelungszeit ±50 ms
Priorität: Hoch
Komponente: Sealing_Manager
----------------------------------
Requirement: NF-BENUTZER-1
Beschreibung: Akustischer Alarm ≥70 dB in 1 m Entfernung
Priorität: Mittel
Komponente: UI_Manager
----------------------------------
Requirement: NF-LEISTUNG-1
Beschreibung: Funktion auch bei Spannungsschwankungen
Priorität: Hoch
Komponente: System_Manager
----------------------------------
