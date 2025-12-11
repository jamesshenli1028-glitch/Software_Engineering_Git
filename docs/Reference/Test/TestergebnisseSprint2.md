## Sprint2

## Zweite Testreihe – Ergebnisse

### Unit Tests (UT)

| Testfall | Ergebnis | Status | Requirement |
|----------|----------|--------|-------------|
| UT4 – Vakuumziel erreichen | Zielvakuum korrekt erkannt, `isTargetPressureReached()` liefert true, Benachrichtigung an SystemManager erfolgreich | Bestanden | F-VACUUM-2 |
| UT5 – Timerfunktion Verzögerung | Timer löste nach 200 ms aus, Callback `onTimeout()` korrekt ausgeführt | Bestanden | F-TIMER-1 / NF-ZEIT-2 |
| UT6 – Versiegelungszeit steuern | Versiegelung dauerte 2001 ms, Benachrichtigung an SystemManager korrekt | Bestanden | F-SEAL-1 |

### Integration Tests (IT)

| Testfall | Ergebnis | Status | Requirement |
|----------|----------|--------|-------------|
| IT4 – Prozesskette Vakuum → Versiegelung | Versiegelung gestartet innerhalb <100 ms nach Vakuumende, UI Statusanzeige korrekt | Bestanden | F-VACUUM-3 / F-SEAL-2 / F-UI-2 |
| IT5 – SafetyMonitor während Prozess | Cover offen → LED Rot + akustischer Alarm, Motorblock → Notabschaltung innerhalb 180 ms, Systemstatus = ERROR | Bestanden | F-SAFETY-4 / F-SAFETY-5 |
| IT6 – Zeitkritische Reaktionen überprüfen | Alle Ereignisse korrekt erkannt und verarbeitet, Reaktionszeiten 150–190 ms | Bestanden | NF-ZEIT-2 / F-SAFETY-5 |