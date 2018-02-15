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
        setPump( state == '1' ? HIGH : LOW );
    }
    else if( inputString.startsWith( "setLeds:" ) ) {
        char state = inputString.charAt( inputStringLength - 1 );
        setLeds( state == '1' ? HIGH : LOW );
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
    delay( 100 );
    Serial.println( "temp:" + String( temp ) );
    delay( 100 );
    Serial.println( "light:" + String( light ) );
    delay( 100 );
    Serial.println( "leds:" + String( ledsIntensity ) );
    delay( 100 );
    Serial.println( "pump:" + String( pumpIntensity ) );
}
