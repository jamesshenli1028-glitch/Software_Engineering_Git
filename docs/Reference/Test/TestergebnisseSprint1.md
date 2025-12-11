
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




