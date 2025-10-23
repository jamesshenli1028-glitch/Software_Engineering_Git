Requirement	        Beschreibung	                                                    Priorität	    Verifikationsmethode	    Komponente

F-START-1	          System startet Arbeitszyklus nach Drücken der Starttaste 	        Mittel 	      Funktionstest 	          System_Manager
F-START-2	          System stoppt innerhalb von 100 ms nach Drücken der Stoptaste 	  Hoch	        Leistungstest	            System_Manager
F-START-3	          System prüft vor Start alle kritischen Komponenten                Hoch	        Funktionstest 	          System_Manager
                    und meldet Status innerhalb von 2 s	
F-VAKUUM-1	        Überwacht Kammerdruck mit 10 Hz Abtastrate 	                      Mittel	      Leistungstest	            Vacuum_Manager
F-VAKUUM-2	        Beendet Vakuumieren bei 100 mbar ±5 mbar 	                        Hoch	        Funktionstest 	          Vacuum_Manager
F-VAKUUM-3	        Beginnt Versiegelung innerhalb von 200 ms nach Vakuumende	        Hoch	        Leistungstest	            System_Manager
F-VERSIEGELUNG-1	  Versiegelt Beutel automatisch nach Vakuumieren 	                  Hoch	        Funktionstest 	          Sealing_Manager
F-VERSIEGELUNG-2	  Versiegelungszeit: 2,0 s ±50 ms	                                  Hoch	        Leistungstest	            Sealing_Manager
F-SICHERHEIT-1	    Abschaltung bei >80 °C (±2 °C Genauigkeit)	                      Kritisch 	    Sicherheitstest	          Safety_Monitor
F-SICHERHEIT-2	    Stoppt innerhalb von 200 ms bei geöffneter Abdeckung 	            Kritisch	    Sicherheitstest	          Safety_Monitor
F-SICHERHEIT-3	    Abschaltung innerhalb von 200 ms bei Motorblockade	              Kritisch 	    Sicherheitstest	          Safety_Monitor
F-SICHERHEIT-4	    Visuelle Warnung: 2 Hz blinkende rote LED.                        Hoch 	        Funktionstest 	          UI_Manager
                    Akustischer Alarm: ≥70 dB, ≥5 s	
F-BENUTZER-1	      Zustände: Bereit (Grün), In Betrieb (Gelb), Fehler (Rot)         	Mittel 	      Funktionstest 	          UI_Manager
F-BENUTZER-2	      Visuelle Anzeige aus 5 m Entfernung klar erkennbar 	              Mittel	      Sichtprüfung	            UI_Manager
NF-ZEIT-1	          Reaktionszeit auf Sicherheitsereignisse ≤200 ms bei 25°C 	        Kritisch	    Leistungstest	            Safety_Monitor
NF-ZEIT-2	          Genauigkeit Versiegelungszeit ±50 ms 	                            Hoch	        Leistungstest	            Sealing_Manager
NF-BENUTZER-1	      Akustischer Alarm ≥70 dB in 1 m Entfernung 	                      Mittel	      HWTest	                  UI_Manager
NF-LEISTUNG-1	      Funktion auch bei Spannungsschwankungen	                          Hoch	        Robustheitstest 	        System
