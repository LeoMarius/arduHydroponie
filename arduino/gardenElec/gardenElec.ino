
///// For Adafruit Pro Trinket 5V


//D'après un code init

#include <SimpleTimer.h>  //https://github.com/schinken/SimpleTimer pour gerer les timeout
SimpleTimer timer; // the timer object
unsigned long time;

/// Pins des elements

#define POMPE 3
#define LEDW 5
#define LEDC 6

#define TEMP A0
#define LUM A1

///Les sondes de niveau
#define LVL1 11
#define LVL2 12


///Déclaration des variables globales

/// les valeurs obtenues par les capteurs (entre 0 et 1024?)
int lum, lvl, hum, temp;

/// l'intensitée des actinneurs (entre 0 et 1)
float lightColdIntensity, lightWarmIntensity, pompeFlowIntensity = 0;

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
    lvl = 2;
}

void loop(){

  //timer.setInterval(1000, sensorsRead);
  //timer.setInterval(100, inputRead);

  int value1 = readCapacitivePin( LVL1 );

    if (value1 <= 3 ){
    updatePompe( 0 );                           // les LEDs chaudes s'allument
    delay(1000);
    updatePompe( 0.2 );  
    delay(1000);
    updatePompe( 0.8 );  
    delay(1000);
  } else{
    updatePompe( 1 );  
  }
  
}

/// Pour les capteurs globaux, mise à jours moins fréquentes
void sensorsRead(){
    updateSensors ();
    safetyChecks();
}

/// Pour tout ce qui est input direct, boutons etc...
void inputRead(){

}

///////////////////////////////////////////////////

///FONCTIONS DISPONIBLES

// updateSensors ()       : Met à jours les relevés de l'ensemble des capteurs

// safetyChecks ()        : Vérifie les données sencibles (le niveau de la pompe uniquement pour le moment) et agis si besoin

// updatePompe(float)     : Controle la pompe, valeure attendue entre 0 et 1, 0 = éteint, 1 = puissance max

// setWarmLeds(float)     : Controle l'allumage de la lampe, la 1ere valeure controle les leds chaudes et la 2eme les leds froides, valeure attendue entre 0 et 1, 0 = éteint, 1 = puissance max

// setColdLeds(float)     :

// lowWaterAlert()        : Déclanche les mesures à prendre en cas de manque d'eau

////////////////////////////////////////////////////

void setWarmLeds(float ledIntensity){
  float lightVal = map(ledIntensity, 0, 1, 0, 255);
  ///Pas encore d'analog
  if (lightVal == 0 ){
    digitalWrite( LEDW, LOW );                           // les LEDs chaudes s'allument
  } else{
    digitalWrite( LEDW, HIGH );  
  }
  ///Une fois le problème de PWM réglé
  /*
  analogWrite( LEDW , lightVal );
   */
}

void setColdLeds(float ledIntensity){
  float lightVal = map(ledIntensity, 0, 1, 0, 255);
  ///Pas encore d'analog
  if (lightVal == 0 ){
    digitalWrite( LEDC, LOW );                           // les LEDs chaudes s'allument
  } else{
    digitalWrite( LEDC, HIGH );  
  }
  ///Une fois le problème de PWM réglé
  /*
  analogWrite( LEDC , lightVal );
   */
}


/// Mise à jours de l'ensemble des capteurs
void updateSensors (){

  temp = (int)((analogRead(TEMP)/1024.0)*5.0 - .5)*100;  //lis la pin et convertis convertion en degrès celcius
  lum = analogRead(LUM);    // Mesure la tension sur la broche de la photodiode, valeure en lux

  int value1 = readCapacitivePin( LVL1 );      //  Mesure la tension sur les pin 11,12
  int value2 = readCapacitivePin( LVL2 );      //
  if ((value1 >= 3)&&(value2 >=3)){ lvl = 2 ;}          // cas 1 : les deux capteurs captent de l'eau (pas besoin d'eau)
  else if ((value1 <= 3)&&(value2 >=3)){ lvl = 1 ;}                       // cas 2 : le capteur le plus haut ne capte plus d'eau (l'eau a baisser)
  else if((value1 <= 3)&&(value2 <=3)){ lvl = 0 ;}                  // cas 3 : les capteurs ne captent plus (il y a trés peu d'eau, remplir rapidement)
  else{ lvl = -1 ;}                          // si il y a une erreur au niveau des capteurs
};


/// On vérifie les valeures sensibles et déclenches les mesures nécéssaires.
void safetyChecks (){
  /// On coupe la pompe si le niveau d'eau est faible
  if (lvl < 1){
    updatePompe(0);
  }
};


void updatePompe(float intensity) {
    /// On met à jour les variables globales
    pompeFlowIntensity = intensity;

      float analogPompe = map(pompeFlowIntensity, 0, 1, 0, 255);


  //safety check before run
  if (lvl < 1){
    pompeFlowIntensity = 0;
    lowWaterAlert();    ///On déclanche la fonction d'alerte
  }

      analogWrite( POMPE, analogPompe );


/*
  ///Si l'état de la pompe est false, on eteint la pompe
  if ( pompeFlowIntensity==0 ){
    digitalWrite( POMPE, LOW );
    return;
  }
  ///Sinon on l'allume (pas encore de réglage d'intensitée)
  digitalWrite( POMPE, HIGH );                        
*/
}



int lastWaterAlertTime = 0; //Timer de référence pour les alertes

void lowWaterAlert(){
  if ((millis()-lastWaterAlertTime) < 10000 && lastWaterAlertTime != 0 ){
    return; //la dernière alerte est trop récente, on stope la fonction
  }
  
  lastWaterAlertTime = millis();    //mise à jour du timer
  updatePompe(0);             //couper la pompe
                                    //Passer l'éclairage d'infos en rouge
                                    //Twitter l'agonie (avec un delais plus long)
}   
