void setWarmLeds(float ledIntensity){
  float lightVal = map(ledIntensity, 0, 1, 0, 255);
  
  ///Pas encore d'analog dans le circuit mais fonctionne quand même
  analogWrite( LEDW , lightVal );
}




void setColdLeds(float ledIntensity){
  float lightVal = map(ledIntensity, 0, 1, 0, 255);
  
  ///Pas encore d'analog dans le circuit mais fonctionne quand même
  analogWrite( LEDC , lightVal );
}

