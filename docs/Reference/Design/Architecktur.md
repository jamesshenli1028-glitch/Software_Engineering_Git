```md
+-------------------------------------------------------+
|      Präsentationsschicht (UI Layer)                  |
|                                                       |
|  - Anzeige-Controller (Display Controller)            |
|    • Steuert LEDs                                     |
|    • Steuert Summer                                   |
+-------------------------▲---------------------------+
                           ⇵ Benutzerfeedback
+-------------------------▼---------------------------+
|      Applikationsschicht (Application Layer)          |
|  (Implementiert die Geschäftslogik aus dem Lastenheft)|
|                                                       |
|  - Prozess-Koordinator (Process Coordinator)          |
|  - Vakuum-Regler (Vacuum Controller)                  |
|  - Versiegelungs-Ablauf (Sealing Sequencer)           |
|  - Sicherheits-Wächter (Safety Guardian)              |
+-------------------------▲---------------------------+
                           ⇵ Steuerbefehle
+-------------------------▼---------------------------+
|      Hardware-Abstraktionsschicht (HAL)               |
| (Kapselt hardwarenahe Operationen für die Applikation)|
|                                                       |
|  - Druck-Messkette (Pressure Measurement Chain)       |
|  - Temperatur-Erfasser (Temperature Acquisition)      |
|  - Antriebs-Ansteuerung (Actuator Drive)              |
|  - Zeitgeber-Basis (Timing Base)                      |
+-------------------------▲---------------------------+
                           ⇵ Registerzugriffe
+-------------------------▼---------------------------+
|      Treiberschicht (Driver Layer)                    |
|  (Direkte Kommunikation mit der Hardware)             |
|                                                       |
|  - ADC_Konfigurator (ADC Configurator)                |
|  - DMA_Dispatcher (DMA Dispatcher)                    |
|  - Timer_Steuerung (Timer Control)                    |
|  - Port_Treiber (Port Driver)                         |
+-------------------------▲---------------------------+
                           ⇵ Elektrische Signale
+-------------------------▼---------------------------+
|      Hardware (Hardware Layer)                        |
|                                                       |
|  - Sensoren: Drucksensor, NTC-Temperatursensor,       |
|              Stromsensor, Abdeckungssensor            |
|  - Aktoren: Vakuumpumpe, Heizelement (MOSFET),        |
|             LEDs (RGB), Summer                        |
|  - Eingabe: Start/Stop-Tasten (mit Entprellung)       |
+-------------------------------------------------------+
```