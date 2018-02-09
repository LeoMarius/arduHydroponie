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
            Serial.println( "pump:0" );
        }
        else if( state == '1' ){
            setPump( HIGH );
            Serial.println( "pump:1" );
        }
    }
    else if( inputString.startsWith( "setLeds:" ) ) {
        char state = inputString.charAt( inputStringLength - 1 );
        if( state == '0' ) {
            setLeds( LOW );
            Serial.println( "leds:0" );
        }
        else if( state == '1' ) {
            setLeds( HIGH );
            Serial.println( "leds:1" );
        }
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
    delay( 100 );
    Serial.println( "temp:" + String( temp ) );
    delay( 100 );
    Serial.println( "light:" + String( light ) );
    delay( 100 );
    Serial.println( "leds:" + String( ledsIntensity ) );
    delay( 100 );
    Serial.println( "pump:" + String( pumpIntensity ) );
}
