
# Sprint 1 – Überblick

In Sprint 1 kümmern wir uns um die Grundfunktionen der Vakuum- und Versiegelungsmaschine. Das Ziel ist, dass die Maschine überhaupt startet, stoppt und sicher läuft.


### Sprint Planning
Auswahl der dringendsten Anforderungen – Start/Stop-Tasten, Sicherheitsabschaltung bei Übertemperatur, Motorblockade oder geöffneter Abdeckung, grundlegende LED- und akustische Anzeigen.

### Requirements
Alle kritischen Funktionen auflisten, zugehörige Komponenten (System_Manager, Safety_Monitor, UI_Manager) und Methoden notieren.

Req. F-START-1: Arbeitszyklus starten
Req. F-START-2: Schnellstopp per Stopptaste
Req. F-START-3: Vorstart-Komponentenprüfung
Req. F-SICHERHEIT-1: Übertemperaturabschaltung
Req. F-SICHERHEIT-2: Stopp bei geöffneter Abdeckung
Req. F-SICHERHEIT-3: Motorblockadeabschaltung
Req. NF-ZEIT-1: Begrenzte Reaktionszeit für Sicherheitsereignisse ≤200 ms


### Design
Skizze der wichtigsten Klassen und wie sie zusammenarbeiten:  
- **System_Manager** steuert Start/Stop  
- **Safety_Monitor** überwacht Sicherheit  
- **UI_Manager** zeigt Status an

### Implementierung
Erste Methoden implementieren, z. B.  
- `System_Manager.startWorkingCycle()`  
- `Safety_Monitor.temperaturSafety()`  
- `UI_Manager.setLED()`  

Noch keine Vakuum- oder Versiegelungssteuerung, die kommt später in Sprint 2.

## Ziel von Sprint 1
- Maschine startet und stoppt zuverlässig.  
- Sicherheitsabschaltungen funktionieren.  
- Statusanzeigen (LED, Alarm) zeigen korrekte Zustände.  
- Die Basis für spätere Vakuum- und Versiegelungsfunktionen ist gelegt.

