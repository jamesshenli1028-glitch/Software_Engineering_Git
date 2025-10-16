Funktion 1: Manuelle Startfunktion
Eine entprelle Schaltung muss bereits sein, wenn der Benutzer die Taste drückt.
Vor dem Start werden alle Bestandteile geprüft, z. B. Sensor für geöffnete Abdeckung, Licht…
Das Startsignal wird nicht zweimal wirken, wenn das Gerät arbeitet.


Funktion 2: Vakuumierprozess-Überwachung
Ein Drucksensor wird benutzt, den innere Druck zu überwachen, dabei muss DMA ständig die Daten übertragen, damit der Druck unter Kontrolle wird, falls erreicht, wird VStop() aufgerufen.
Anschließend setzt die Steuerung ein Steuersignal, das direkt den Versiegelungsprozess startet.


Funktion 3: Versiegelungsprozess-Steuerung 
Das Heizelement wird für die eingestellte Dauer aktiviert. Wenn es scheitert ist, muss sofort Alarm() aufrufen. 
Nach Ablauf der Zeit wird das Heizelement automatisch deaktiviert.
Der Zähler muss immer im Betrieb sein, falls der Prozess die Zeit überschreitet, muss sofort Alarm senden. Die Zeitgenauigkeit soll unter 50ms sein, ohne große Abweichung. 


Funktion 4: Sicherheitsabschaltung
Das System wird immer die 80-Temperatur durch Sensor und ADC-Schaltung überwachen, bei der Überschreitung wird Shutdown() Funktion aufgerufen.
Wenn die Bedeckung Fehler durch Hardware Schaltung erkannt wird, die Shutdown() wird aufgerufen, nebenbei wird die Störungslicht aktiviert.
Ein Stromsensor überwacht den Stromverbrauch des Motors. Ein plötzlicher starker Anstieg deutet auf eine Blockade hin. 
Der Mikrocontroller erkennt dies und schaltet die Motorleistungsstufe sofort ab. Zusätzlich kann ein Hardware-Interrupt für eine schnellste Reaktion sorgen. 
Bei jeder Abschaltung aktiviert der Mikrocontroller eine rote LED und einen Piezo-Lautsprecher


Funktion 5: Benutzerfeedback
Grünlicht beim normalen Zustand.
Rotlicht beim blockierenden Zustand.
Gelblicht beim anderen Zustand.
Ein Summer gibt im Fehlerfall einen akustischen Alarm aus.
Zur Verstärkung des Signals kommt eine einfache Transistor-Verstärkerschaltung zum Einsatz.
Der Schalldruckpegel muss am Gerät mindestens 70 dB betragen.
