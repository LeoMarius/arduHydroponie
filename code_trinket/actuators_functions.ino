void setPump( int intensity ) {
    if( getWaterLevel() == 0 || intensity == LOW ) {
        digitalWrite( PUMP_PIN, LOW );
        if( pumpIntensity != 0 ) {
            Serial.println( "pump:0" );
        }
        pumpIntensity = 0;
    }
    else {
        digitalWrite( PUMP_PIN, HIGH );
        if( pumpIntensity != 1 ) {
            Serial.println( "pump:1" );
        }
        pumpIntensity = 1;
    }
}

void setLeds( int intensity ) {
    if( ledsIntensity != intensity ) {
        Serial.println( "leds:" + String( intensity ) );
    }
    ledsIntensity = intensity;

    if( intensity == LOW  ) {
        digitalWrite( LED_PIN, LOW );
    }
    else if( intensity == HIGH ) {
        digitalWrite( LED_PIN, HIGH );
    }
}

void togglePump() {
    activePump = !activePump;
}
