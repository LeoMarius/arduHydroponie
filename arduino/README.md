# arduHydroponie

# Electronique

L'électronique est faites avec des modules [Pro Trinkets 5V](https://learn.adafruit.com/introducing-pro-trinket/overview) de adafruit.
Une conectivitée en wifi est prévue via l'ajout d'une [Feather Huzzah](https://www.adafruit.com/product/2821) par la suite.

 > Le circuit comprend une pompe et deux lampes LED, suivre le shéma ci dessou pour le montage.
 > [Exemple de montage des transistors](https://www.tinkercad.com/things/7Uf0n2DrO2y)


# library to install

[SimpleTimer](https://playground.arduino.cc/Code/SimpleTimer#Download) librairie arduino utilisée


# Functions recap

 - The main loop

    1 - Basics sensors (slow update)
 >  Call the function every "to be defined" seconds
 > >  Update sensors
 > >  With sensors updated, do safety checks (mostly water level)
 > >  Apply programed actions depending of sensors
 
    2 - Check local events (quick)
 >  Wait for outside events.
 > > Can be physical buttons, IFTT events etc...
 
    3 - Check remote events (medium update speed)
 >  Check the online datas
 
 - Tools available

1- 

