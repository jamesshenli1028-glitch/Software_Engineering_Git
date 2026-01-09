
# Vacuum- und Versiegelungssystem – README

## 1. Projektübersicht

Dieses Projekt implementiert ein **modulares Software‑Steuerungssystem für eine Vakuum‑ und Versiegelungsmaschine** in C++. Ziel ist es, eine realitätsnahe industrielle Softwarearchitektur zu simulieren, wie sie in automatisierten Verpackungsmaschinen eingesetzt wird.

Der Fokus des Projekts liegt **nicht auf der konkreten Hardwareansteuerung**, sondern auf:

* sauberer Softwarearchitektur
* klarer Trennung von Verantwortlichkeiten
* permanenter Sicherheitsüberwachung
* zeitkritischer Prozesssteuerung

Der vollständige Arbeitszyklus lautet:

> **Start → Sicherheitsprüfung → Vakuumprozess → Versiegelung → Prozessende oder Notabschaltung**

---

## 2. Architekturkonzept

Die Software folgt einem **schichtenorientierten, modularen Architekturansatz**.

### Zentrale Designprinzipien

* Single Responsibility Principle
* Lose Kopplung zwischen Modulen
* Zentrale Koordination, dezentrale Ausführung
* Safety‑First‑Design: Sicherheitslogik ist unabhängig vom Prozess implementiert

---

## 3. Komponentenübersicht

### 3.1 System_Manager

**Rolle:** Zentrale Koordination des Gesamtsystems

**Aufgaben:**

* Starten und Stoppen des Arbeitszyklus
* Prüfung aller sicherheitsrelevanten Komponenten vor Prozessstart
* Verwaltung des Systemzustands

**Wichtige Methoden:**

* `startWorkingCycle()`
* `stopSystem()`
* `checkCriticalComponents()`

Der System_Manager steuert den Ablauf, führt jedoch **keine direkten Sicherheitsabschaltungen** aus.

---

### 3.2 Safety_Monitor

**Rolle:** Unabhängige Sicherheitsüberwachung (Safety Layer)

**Überwachte Parameter:**

* Abdeckung (Cover)
* Motorblockade
* Temperatur

**Eigenschaften:**

* Permanente Überwachung während des gesamten Prozesses
* Zeitkritische Reaktion ≤ 200 ms
* Direkte Auslösung der Notabschaltung

**Zentrale Methoden:**

* `monitorTemperature()`
* `monitorCover()`
* `monitorMotorBlock()`
* `monitorDuringProcess()`
* `emergencyShutdown()`

Die Sicherheitslogik ist bewusst **vom System_Manager entkoppelt**, um maximale Zuverlässigkeit zu gewährleisten.

---

### 3.3 Vakuum_Manager

**Rolle:** Steuerung des Vakuumprozesses

**Funktionen:**

* Starten und Stoppen der Vakuumpumpe
* Überwachung des Kammerdrucks
* Erkennung des Zielunterdrucks

**Technische Details:**

* Periodische Drucküberwachung
* Zielwert: 0,1 bar
* Safety‑Überwachung parallel zum Prozess

**Wichtige Methoden:**

* `startVakuuming()`
* `stopVakuuming()`
* `monitorPressure()`
* `isTargetPressureReached()`

---

### 3.4 SealingManager

**Rolle:** Steuerung des Versiegelungsprozesses

**Eigenschaften:**

* Automatischer Start nach erfolgreichem Vakuumprozess
* Zeitgesteuerte Steuerung des Heizelements

**Zeitvorgabe:**

* Versiegelungszeit: 2,0 s ± 50 ms

---

### 3.5 TimerService

**Rolle:** Zeitkritische Ablaufsteuerung

**Aufgaben:**

* Exakte Zeitsteuerung von Prozessen
* Unterstützung zeitabhängiger Callbacks

---

### 3.6 UIManager

**Rolle:** Benutzerinteraktion und Statusanzeige

**Funktionen:**

* Anzeige des Vakuumstatus
* Anzeige des Versiegelungsstatus
* Akustische und visuelle Rückmeldungen

---

### 3.7 Service‑Klassen

Zur Simulation von Sensoren und Aktoren werden folgende Service‑Klassen verwendet:

* `Pressure_Service` – Drucksensor
* `Temperature_Service` – Temperatursensor
* `Motor_Service` – Pumpe und Heizelement

Diese Klassen kapseln den Zugriff auf physikalische Größen und ermöglichen eine einfache Erweiterung auf reale Hardware.

---

## 4. Systemablauf

1. Benutzer startet den Arbeitszyklus
2. System_Manager prüft kritische Komponenten
3. Start des Vakuumprozesses
4. Permanente Sicherheitsüberwachung
5. Automatischer Start der Versiegelung
6. Prozessende oder Notabschaltung

---

## 5. Sicherheitskonzept

* Sicherheitsüberwachung unabhängig vom Prozess
* Sicherheitsereignisse haben immer höchste Priorität
* Notabschaltung erfolgt direkt im Safety_Monitor
* Reaktionszeit ≤ 200 ms

---

## 6. Testkonzept

**Testarten:**

* Unit‑Tests
* Integrationstests

**Getestete Szenarien:**

* Start/Stop des Systems
* Vakuum‑ und Versiegelungsprozess
* Sicherheitsabschaltungen

Nicht Bestandteil der Tests:

* Reale Hardwareeigenschaften
* Langzeitbetrieb

---

## 7. Erweiterungsmöglichkeiten

* Zustandsmaschine (State Machine)
* Optimierung von Event‑Queue und Thread‑Synchronisation
* Logging aller Prozessschritte
* Erweiterte UI‑Animationen
* Anbindung realer Hardware

---

## 8. Zusammenfassung

Dieses Projekt demonstriert eine **strukturierte, sicherheitsorientierte Softwarearchitektur** für ein automatisiertes Vakuum‑ und Versiegelungssystem und bildet eine solide Grundlage für weiterführende industrielle Anwendungen.



Ich versichere, dass ich die Projektarbeit ohne Hilfe Dritter und ohne Benutzung anderer als die angegebenen Quellen und Hilfsmittel angefertigt habe. Die den benutzten Quellen wörtlich oder inhaltlich entnommenen Inhalte sind als solche kenntlich gemacht. Ich erteile hiermit der TH Deggendorf das Recht, die von mir erstellte Software für hochschulinterne Zwecke verwenden zu dürfen.

Ort: Deggendorf, Datum: [09.01.2026], Name: [ShenLi]
