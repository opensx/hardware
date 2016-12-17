# Weichen-/Signaldekoder mit dem ATtiny2313

mehr dazu bei <a href="http://opensx.net/"> OpenSX.net</a> 

(ursprüngliche Version wie in den Zeitschriftenartikelen in der Digitalen
Modellbahn beschrieben, siehe  <a href="http://opensx.net/downloads">
 opensx.net/downloads.</a> )
 
##Vorteile:
 
sehr preiswert, einfache Platine, günstiger Controller ATtiny2313,
universeller Output Treiber mit SN754410 (entweder Schalten gegen Masse oder
+10V (oder auch 12V, wenn anderer Regler IC7 verwendet wird).
 
##Nachteile:
 
Die verwendete Software, zusammen mit der niedrigen internen Clock des
ATtiny2313 von 8MHz, führt offensichtlich dazu, dass das Schreiben auf den 
SX-Bus (was man allerding nur zur Programmierung der Adresse des Dekoders
braucht) für einige Zentralen zu langsam ist (Messungen von Frank Keil). Auf
jeden Fall funktioniert das Schreiben bei Rautenhaus-Zentralen und bei der
alten Trix-Zentrale.
  
Daher (und weil sich Arduinos leicht mit der Arduino-IDE, also ohne speziellen
"Programmer", programmieren lassen) verwenden wir jetzt hauptsächlich den 
Arduino Pro Mini, der einen 16Mhz Quartz hat, also doppelt so schnell läuft.
 
Ausserdem ist der SN754410 zwar universell zu verwenden, braucht aber viel 
Strom. Für Tortoise Weichenantriebe ist der LB1909MC optimal, der keine 5V 
Spannungsversorgung braucht und einfacher (1 Leitung) anzusteuern ist. Für
Doppelspulen-Antriebe kann man den IRF7103 (Doppel-)Mosfet verwenden, wie im
Gleis-Bettungs-Dekoder sx-wdec84-1.2.
  
 

![OSH Logo](../oshw-logo-100-px.png)


<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
