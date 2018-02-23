void readWaterLevel() {
    int currentWaterLvl = getWaterLevel();

    if( currentWaterLvl != waterLvl ) {
        if( currentWaterLvl == 2 ) {
            Serial.println( "alert2" );
            setLeds( HIGH );
        }
        else if( currentWaterLvl == 1 ) {
            Serial.println( "alert1" );
        }
        else if( currentWaterLvl == 0 ) {
            Serial.println( "alert0" );
        }
    }

    waterLvl = currentWaterLvl;

    if( waterLvl == 2 ) {
        setPump( HIGH );
    }
    else if( waterLvl == 1 ) {
        setPump( activePump ? HIGH : LOW );
        signalWaterLvl_1();
    }
    else if( waterLvl == 0 ) {
        setPump( LOW );
        signalWaterLvl_0();
    }
}

int getWaterLevel() {
    int lvl1 = readCapacitivePin( WATER_LVL1_PIN ) >= 3 ? 1 : 0;
    int lvl2 = readCapacitivePin( WATER_LVL2_PIN ) >= 3 ? 1 : 0;
    return lvl1 + lvl2;
}

void waterLevel0Alert() {
    if( waterLvl == 0 ) {
        Serial.println( "alert0" );
    }
}
