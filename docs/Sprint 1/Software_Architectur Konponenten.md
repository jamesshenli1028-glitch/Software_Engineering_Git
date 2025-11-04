Software-Architektur Komponenten

1. System_Manager (Kernsteuerung)
   | startWorkingCycle() | Startet den Arbeitszyklus | F-START-1 |
   | stopSystem() | Stoppt alle Prozesse | F-START-2 |
   | checkKomponents() | Prüft kritische Komponenten vor Start | F-START-3 |
   | startVacuum() | Startet Vakuumprozess | F-VAKUUM-3 |
   | startSealing() | Initialisiert Versiegelung | F-VERSIEGELUNG-1 |

2. Safety_Monitor (Sicherheitsüberwachung)
   - Temperaturüberwachung (F-SICHERHEIT-1)
   - Abdeckungssensor (F-SICHERHEIT-2)
   - Motorblockierungserkennung (F-SICHERHEIT-3)
   - Notabschaltung (NF-ZEIT-1)

3. UI_Manager (Benutzerschnittstelle)
   - LED-Steuerung (F-BENUTZER-1, F-BENUTZER-2)
   - Alarmsteuerung (F-SICHERHEIT-4, NF-BENUTZER-1)
   - Statusanzeige

4. Vacuum_Manager (Vakuumsteuerung)
   - Kammerdruck-Überwachung (F-VAKUUM-1)
   - Vakuumieren-Beendigung (F-VAKUUM-2)
   - Druckmessung mit 10 Hz

5. Sealing_Manager (Versiegelungssteuerung)
   - Automatische Versiegelung (F-VERSIEGELUNG-1)
   - Versiegelungszeit-Steuerung (F-VERSIEGELUNG-2, NF-ZEIT-2)



Service Komponenten

1. Pressure_Service (Druckmessung)
   - Sensor-Datenerfassung
   - Datenkalibrierung
   - DMA-Datenübertragung
   - Druckwert-Bereitstellung

2. Temperature_Service (Temperaturmessung)
   - NTC-Sensor-Auslesen
   - Temperaturberechnung
   - Genauigkeitskontrolle ±2°C
   - Kalibrierte Temperaturwerte

3. Motor_Service (Aktorik)
   - Vakuumpumpen-Steuerung
   - Heizelement-Steuerung
   - Motorstrom-Überwachung
   - Blockade-Erkennung

4. Timer_Service (Zeitbasis)
   - Präzise Zeitmessung
   - Blinkfrequenz-Generierung (2 Hz)
   - Prozesszeit-Steuerung
   - Versiegelungszeit-Kontrolle ±50 ms


Komponenten Interaktion
1. Datenfluss:
   - Sensoren → Services → Manager → UI
   - (Pressure/Temp) → (Process) → (Display)

2. Kontrollfluss:
   - System_Manager → [Vacuum_Manager, Sealing_Manager] → Motor_Service

3. Sicherheitsüberwachung:
   - Safety_Monitor ← Services → System_Manager → UI_Manager
   - (überwacht)  ←  (Alarm)   →  (Shutdown)   →   (Warnung)