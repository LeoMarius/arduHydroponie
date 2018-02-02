void setPump( int intensity ) {
    if( getWaterLevel() == 0 || intensity == LOW ) {
        pumpIntensity = intensity;
        digitalWrite( PUMP_PIN, LOW );
    }
    else {
        pumpIntensity = intensity;
        digitalWrite( PUMP_PIN, HIGH );
    }
}

void setLeds( int pin, int intensity ) {
    if( pin == WARM_LED_PIN ) {
        warmLightIntensity = intensity;
    }
    else if( pin == COLD_LED_PIN ) {
        coldLightIntensity = intensity;
    }

    if( pin == WARM_LED_PIN || pin == COLD_LED_PIN ) {
        if( intensity == LOW  ){
            digitalWrite( pin, LOW);
        }
        else if( intensity == HIGH ) {
            digitalWrite( pin, HIGH);
        }
        else {
            analogWrite( pin , intensity );
        }
    }
}
