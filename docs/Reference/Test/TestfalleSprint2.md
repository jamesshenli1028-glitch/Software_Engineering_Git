## Sprint2

### Unit Tests (UT)

**UT4 – Vakuumziel erreichen**  
- **Ziel:** Sicherstellen, dass der `VacuumManager` das Zielvakuum korrekt erreicht  
- **Ausgangszustand:** Systemstatus = RUNNING, Vakuum aktiv  
- **Eingabe:** `startVacuuming()` + simulierte Druckwerte  
- **Erwartete Reaktion:** Zielvakuum erreicht → `isTargetPressureReached()` liefert true, SystemManager wird benachrichtigt  

**UT5 – Timerfunktion Verzögerung**  
- **Ziel:** Sicherstellen, dass TimerService Verzögerungen korrekt ausführt  
- **Ausgangszustand:** Systemstatus = RUNNING, Timer inaktiv  
- **Eingabe:** `startTimer(200 ms)`  
- **Erwartete Reaktion:** Timer löst nach 200 ms aus → `onTimeout()` wird aufgerufen  

**UT6 – Versiegelungszeit steuern**  
- **Ziel:** Sicherstellen, dass der `SealingManager` die Versiegelung exakt für 2000 ±50 ms steuert  
- **Ausgangszustand:** Vakuum beendet, Systemstatus = RUNNING  
- **Eingabe:** `controlSealing()`  
- **Erwartete Reaktion:** Versiegelung läuft genau 2000 ms ±50 ms, SystemManager wird nach Abschluss benachrichtigt  

---

### Integration Tests (IT)

**IT4 – Prozesskette Vakuum → Versiegelung**  
- **Ziel:** Überprüfung der vollständigen Prozesskette nach Vakuumende  
- **Ausgangszustand:** Vakuum beendet, Systemstatus = RUNNING  
- **Eingabe:** Ereignis `handleVacuumDone()` → Start `startSealingProcess()`  
- **Erwartete Reaktion:** Versiegelung startet automatisch, UI zeigt Status korrekt an  

**IT5 – SafetyMonitor während Prozess**  
- **Ziel:** Sicherstellen, dass SafetyMonitor Temperatur, Cover und Motor kontinuierlich überwacht  
- **Ausgangszustand:** Prozess läuft (Vakuum oder Versiegelung)  
- **Eingabe:** Simulierte Sensorwerte: Temperatur normal, Cover offen, Motor blockiert  
- **Erwartete Reaktion:** Sicherheitsereignisse → Notabschaltung / UI Alarm innerhalb ≤200 ms  

**IT6 – Zeitkritische Reaktionen überprüfen**  
- **Ziel:** Überprüfung, dass alle zeitkritischen Aktionen (Vakuum, Sealing, Safety) innerhalb geforderter Reaktionszeit erfolgen  
- **Ausgangszustand:** Prozess läuft, Timer aktiv  
- **Eingabe:** Simulierte Events: Vakuumende, Temperaturüberschreitung, Motorblock  
- **Erwartete Reaktion:** Alle Aktionen ≤200 ms  