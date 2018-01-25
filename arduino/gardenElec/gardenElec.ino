
///// For Adafruit Pro Trinket 5V


//D'après un code init

#include <SimpleTimer.h>  //https://github.com/schinken/SimpleTimer pour gerer les timeout
SimpleTimer timer; // the timer object
unsigned long time;

/// Pins des elements

#define POMPE 13
#define LEDW A0
#define LEDC A1

#define TEMP A2
#define LUM A3

///Les sondes de niveau
#define LVL1 10
#define LVL2 11


///Déclaration des variables globales

/// les valeurs obtenues par les capteurs (entre 0 et 1024?)
int lum, lvl, hum, temp, lvl1, lvl2;

/// l'intensitée des actinneurs (entre 0 et 1)
float lightColdIntensity, lightWarmIntensity, pompeFlowIntensity = 0;

boolean pumpAlert = true;

void setup(){
  //  Serial.begin(19200);      // Initialise la communication avec le PC
    ///Les actionneurs
    pinMode( POMPE, OUTPUT );
    pinMode( LEDW, OUTPUT );
    pinMode( LEDC, OUTPUT );

    ///Les capteurs
    pinMode( TEMP, INPUT );
    pinMode( LUM, INPUT );
    pinMode( LVL1, INPUT );
    pinMode( LVL2, INPUT );

    ///Variables pour le debug
    timer.setInterval(100, debugLoop);

}

void loop(){

 // timer.setInterval(1000, sensorsRead);
 // timer.setInterval(100, inputRead);

timer.run();

  
}




///////////////////////////////////////////////////

///FONCTIONS DISPONIBLES

// updateSensors ()       : Met à jours les relevés de l'ensemble des capteurs

// safetyChecks ()        : Vérifie les données sencibles (le niveau de la pompe uniquement pour le moment) et agis si besoin

// updatePompe(float)     : Controle la pompe, valeure attendue entre 0 et 1, 0 = éteint, 1 = puissance max

// setWarmLeds(float)     : Controle l'allumage de la lampe chaude, valeure attendue entre 0 et 1, 0 = éteint, 1 = puissance max

// setColdLeds(float)     : Controle l'allumage de la lampe chaude, valeure attendue entre 0 et 1, 0 = éteint, 1 = puissance max

// lowWaterAlert()        : Déclanche les mesures à prendre en cas de manque d'eau

////////////////////////////////////////////////////









