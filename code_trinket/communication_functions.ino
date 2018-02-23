void serialEvent() {
    while( Serial.available() ) {
        char inChar = ( char ) Serial.read();

        if( inChar == '\n' ) {
            parseString();
        }
        else{
            inputString += inChar;
            inputStringLength ++;
        }
    }
}

void parseString() {
    if( inputString.startsWith( "getValues" ) ) {
        readWaterLevel();
        sendStates();
    }
    else if( inputString.startsWith( "setPump:" ) ) {
        char state = inputString.charAt( inputStringLength - 1 );
        setPump( state == '1' ? HIGH : LOW );
    }
    else if( inputString.startsWith( "setLeds:0" ) ) {
        setLeds( LOW );
    }
    else if( inputString.startsWith( "setLeds:1" ) ) {
        setLeds( HIGH );
    }
    else {
        Serial.println( inputString );
    }

    // reset inputString
    inputString = "";
    inputStringLength = 0;
}

void sendStates(){
    Serial.println( "waterlevel:" + String( waterLvl ) );
    delay( 200 );
    Serial.println( "pump:" + String( pumpIntensity ) );
    delay( 200 );
    Serial.println( "leds:" + String( ledsIntensity ) );
}
