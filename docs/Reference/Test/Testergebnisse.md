
## Sprint1

### Unit Tests (UT)

| Testfall | Ergebnis | Status | Requirement |
|----------|----------|--------|-------------|
| UT1 – Start Arbeitszyklus | Der Start wurde korrekt ausgelöst. `cycleActive` wurde auf true gesetzt und der Systemstatus wechselte wie erwartet nach RUNNING. | Bestanden | F-START-1 |
| UT2 – Stop System | Das System stoppte innerhalb der geforderten ≤100 ms. `cycleActive` wurde auf false gesetzt und Systemstatus = STOPPED. | Bestanden | F-START-2 |
| UT3 – Prüfen kritischer Komponenten | Die Methode lieferte innerhalb von ≤2 s einen korrekten OK-Status. | Bestanden | F-START-3 |

---

### Integration Tests (IT)

| Testfall | Ergebnis | Status | Requirement |
|----------|----------|--------|-------------|
| IT1 – Temperaturüberwachung & Notabschaltung | Temperaturüberschreitung >82 °C wurde korrekt erkannt. Notabschaltung erfolgte <200 ms, Systemstatus wechselte zu ERROR. | Bestanden | F-SICHERHEIT-1 / NF-ZEIT-1 |
| IT2 – Abdeckung offen → Alarm | Abdeckung „OFFEN“ wurde korrekt erkannt. Rote LED wurde aktiviert und akustischer Alarm (≥70 dB) wurde ausgelöst. | Bestanden | F-SICHERHEIT-2 |
| IT3 – Motorblock & Versiegelung | Motorblock wurde korrekt erkannt und Notabschaltung ausgelöst. Beim Szenario „Vakuumende“ startete die Versiegelung innerhalb der geforderten Reaktionszeit. | Bestanden | F-SICHERHEIT-3 / F-VERSIEGELUNG-1 |



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
