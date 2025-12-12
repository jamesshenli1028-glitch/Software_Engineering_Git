# Sprint 2 – Retrospektive

## Was lief gut?
- Vollständige Umsetzung des Vakuum- und Versiegelungsprozesses mit automatischem Ablauf.
- Asynchrone Architektur etabliert: Threads, TimerService und Callbacks funktionieren zuverlässig.
- SafetyMonitor überwacht kontinuierlich kritische Parameter während Vakuum- und Versiegelungsprozess.
- UIManager zeigt Status korrekt, klar und verständlich (LED/Display für VAKUUM, SEALING, COOLING).
- Integration aller Module (SystemManager, VacuumManager, SealingManager, TimerService, SafetyMonitor, UIManager) erfolgreich.

## Was lief weniger gut?
- Event-Handhabung bei komplexen Prozessketten noch nicht vollständig optimiert; Debugging teilweise schwierig.
- UI-Animationen und Logging für alle Prozesszustände fehlen oder unvollständig.
- Testabdeckung für Cooling-Phase und Randfälle der Sicherheitsüberwachung noch nicht maximal.
- Asynchrone Events stellen weiterhin Herausforderungen bei Race Conditions und Synchronisation dar.

## Verbesserungsvorschläge für Sprint 3
- Erweiterte Integrationstests für Vakuum-, Sealing- und Cooling-Prozesse durchführen.
- Event-Queue und Thread-Synchronisation weiter stabilisieren.
- Logging, Prozessvisualisierung und Alarm-Mechanismen ausbauen.
- UI-Service modularisieren und ggf. Animationen für Statusänderungen ergänzen.
- Dokumentation der Safety-Mechanismen, Timer-Logik und Event-Handling abschließen und standardisieren.
