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
    // do parsing
    if( inputString.startsWith( "getValues" ) ) {
        readSensors();
        sendStates();
    }
    else if( inputString.startsWith( "setPump:" ) ) {
        char state = inputString.charAt( inputStringLength - 1 );
        if( state == '0' ){
            setPump( LOW );
            Serial.println( "OK: PUMP OFF" );
        }
        else if( state == '1' ){
            setPump( HIGH );
            Serial.println( "OK: PUMP ON" );
        }

        readSensors();
        sendStates();
    }
    else if( inputString.startsWith( "setLeds:" ) ) {
        char state = inputString.charAt( inputStringLength - 1 );
        if( state == '0' ){
            setLeds( LOW );
            Serial.println( "OK: LEDS OFF" );
        }
        else if( state == '1' ) {
            setLeds( HIGH );
            Serial.println( "OK: LEDS ON" );
        }

        readSensors();
        sendStates();
    }
    else {
        Serial.print( "LOG:" );
        Serial.println( inputString );
    }

    // reset inputString
    inputString = "";
    inputStringLength = 0;
}

void sendStates(){
    Serial.println( "waterlevel:" + String( waterLvl ) );
    Serial.println( "temp:" + String( temp ) );
    Serial.println( "light:" + String( light ) );
    Serial.println( "leds:" + String( ledsIntensity ) );
    Serial.println( "pump:" + String( pumpIntensity ) );
}
