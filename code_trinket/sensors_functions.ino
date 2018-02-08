void readSensors() {
    light = analogRead( LIGHT_PIN );
    temp = getTemperature();
    waterLvl = getWaterLevel();

    safetyChecks( waterLvl );
}

float getTemperature() {
    float voltage = analogRead( TEMP_PIN ) / 1024.0 * 5.0;
    return ( voltage - 0.5 ) * 100.0;
}

int getWaterLevel() {
    int lvl1 = 0;
    int lvl2 = 0;

    if( readCapacitivePin( WATER_LVL1_PIN ) >= 3 ) {
        lvl1 = 1 ;
    } else {
        lvl1 = 0 ;
    }

    if( readCapacitivePin( WATER_LVL2_PIN ) >= 3 ) {
        lvl2 = 1 ;
    } else {
        lvl2 = 0 ;
    }

    return lvl1 + lvl2;
}

void safetyChecks( int lvl ) {
    if( lvl == 0 ){
        setPump( LOW );
    } else {
        setPump( HIGH );
    }
}
