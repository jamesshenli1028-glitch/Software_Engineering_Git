# Sprint 1 – Retrospektive

## Was lief gut?
- Sicherheitskritische Basisfunktionen (Temperatur, Abdeckung, Motor) wurden erfolgreich implementiert.
- Start/Stop-Logik ist stabil und durch Unit-Tests abgesichert.
- Teamkommunikation und Aufgabenverteilung funktionierten effizient.
- Architekturgrundlagen (Singletons, Manager-Struktur) sind korrekt umgesetzt.

## Was lief weniger gut?
- Hardware-Abstraktion (SensorInterface, HeaterControl) noch nicht vollständig umgesetzt.
- SafetyManager arbeitet bisher nur mit Stub-Methoden, echte Sensorlogik fehlt.
- Event-Mechanismus ist synchron statt wie geplant asynchron.
- UI noch nicht modularisiert, visuelle und akustische Rückmeldungen teilweise unvollständig.

## Verbesserungsvorschläge für Sprint 2
- Einführung eines echten Event/Observer-Systems für Safety- und Prozessereignisse.
- HAL-Schicht vervollständigen (Mock-Sensor, Mock-Heater).
- UI-Service modularisieren und von der Logik entkoppeln.
- Testabdeckung für nicht-funktionale Anforderungen erweitern (Zeitmessung, Alarmpegel, Lesbarkeit).
- Vollständige Implementierung der Vakuum- und Versiegelungsprozesse.
