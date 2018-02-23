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
    int cap1 = readCapacitivePin( WATER_LVL1_PIN );
    int lvl1 = cap1 >= 4 ? 1 : 0;
    int cap2 = readCapacitivePin( WATER_LVL2_PIN );
    int lvl2 = cap2 >= 4 ? 1 : 0;
    Serial.println( "cap1:" + String( cap1 ) + "  cap2:" + String( cap2 ) + "  lvl:" + String( lvl1 + lvl2 ) );
    return lvl1 + lvl2;
}

void waterLevel0Alert() {
    if( waterLvl == 0 ) {
        Serial.println( "alert0" );
    }
}
