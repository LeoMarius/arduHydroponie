void readSensors() {
    light = analogRead( LIGHT_PIN );
    temp = getTemperature();
    waterLvl = getWaterLevel();

    if( waterLvl == 2 ) {
        setPump( HIGH );
    }
    else if( waterLvl == 0 ) {
        setPump( LOW );
    }
}

float getTemperature() {
    float voltage = analogRead( TEMP_PIN ) / 1024.0 * 5.0;
    return ( voltage - 0.5 ) * 100.0;
}

int getWaterLevel() {
    int lvl1 = readCapacitivePin( WATER_LVL1_PIN ) >= 3 ? 1 : 0;
    int lvl2 = readCapacitivePin( WATER_LVL2_PIN ) >= 3 ? 1 : 0;
    return lvl1 + lvl2;
}
