/// Pour les capteurs globaux, mise à jours moins fréquentes
void sensorsRead(){
    updateSensors ();
    safetyChecks();
}

/// Mise à jours de l'ensemble des capteurs
void updateSensors (){

  temp = (int)((analogRead(TEMP)/1024.0)*5.0 - .5)*100;  //lis la pin et convertis convertion en degrès celcius
  lum = analogRead(LUM);    // Mesure la tension sur la broche de la photodiode, valeure en lux

  int value1 = readCapacitivePin( LVL1 );      //  Mesure la tension sur les pin 11,12
  int value2 = readCapacitivePin( LVL2 );      //
  
  if (value1 >= 3) {  lvl1 = 1 ;} else { lvl1 = 0 ;};
  if (value2 >= 3) {  lvl2 = 1 ;} else { lvl2 = 0 ;};

  lvl = lvl1 + lvl2;


};


/// On vérifie les valeures sensibles et déclenches les mesures nécéssaires.
void safetyChecks (){
  /// On coupe la pompe si le niveau d'eau est faible

  if( lvl > 0 ){
    pumpAlert = false ;
  } else{
    lowWaterAlert();
  }
};
