void setWarmLeds(float ledIntensity){
  float lightVal = map(ledIntensity, 0, 1, 0, 255);
  lightWarmIntensity = lightVal;

  if ( ledIntensity == 0 ){
    digitalWrite( LEDW, LOW);
  } else if (ledIntensity == 1){
    digitalWrite( LEDW, HIGH);
  } else {
    analogWrite( LEDW , lightVal );  //Si jamais ont a les bons composants pour du PWM avec les leds
  }
}




void setColdLeds(float ledIntensity){
  float lightVal = map(ledIntensity, 0, 1, 0, 255);
  lightColdIntensity = lightVal;

  if ( ledIntensity == 0 ){
    digitalWrite( LEDC, LOW);
  } else if (ledIntensity == 1){
    digitalWrite( LEDC, HIGH);
  } else {
    analogWrite( LEDC , lightVal );  //Si jamais ont a les bons composants pour du PWM avec les leds
  }
}

