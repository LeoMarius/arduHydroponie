void updatePompe(float intensity) {
  
    /// On met à jour les variables globales
    pompeFlowIntensity = intensity;

    float analogPompe = map(intensity, 0, 1, 0, 255);

    //safety check before run
    if (pumpAlert == true || intensity == 0 ){
      //analogWrite( POMPE, 0 );
      digitalWrite( POMPE, 0 );
    } else {
     // analogWrite( POMPE, analogPompe );
      digitalWrite( POMPE, 1 );

    }
}


int lastWaterAlertTime = 0; //Timer de référence pour les alertes
void lowWaterAlert(){
  
  pumpAlert = true;
  if ((millis()-lastWaterAlertTime) < 10000 && lastWaterAlertTime != 0 ){
    return; //la dernière alerte est trop récente, on stope la fonction
  }
  
  lastWaterAlertTime = millis();    //mise à jour du timer
  updatePompe(0);                   //couper la pompe
                                    //Passer l'éclairage d'infos en rouge
                                    //Twitter l'agonie (avec un delais plus long)
}   
