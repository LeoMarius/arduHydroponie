void setPump( int intensity ) {
    if( getWaterLevel() == 0 || intensity == LOW ) {
        digitalWrite( PUMP_PIN, LOW );
        pumpIntensity = 0;
    }
    else {
        digitalWrite( PUMP_PIN, HIGH );
        pumpIntensity = 1;
    }
}

void setLeds( int intensity ) {
    ledsIntensity = intensity;

    if( intensity == LOW  ) {
        digitalWrite( COLD_LED_PIN, LOW );
        digitalWrite( WARM_LED_PIN, LOW );
    }
    else if( intensity == HIGH ) {
        digitalWrite( COLD_LED_PIN, HIGH );
        digitalWrite( WARM_LED_PIN, HIGH );
    }
}
