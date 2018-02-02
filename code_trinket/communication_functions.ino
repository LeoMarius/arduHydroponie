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
    if( inputString.equals( "getValues" ) ){
        readSensors();
        sendStates();
    }
    else if( inputString.startsWith( "setPump:" ) ) {
        char state = inputString.charAt( inputStringLength );
        if( state == '0' ){
            setPump( LOW );
        }
        else if( state == '1' ){
            setPump( HIGH );
        }
    }
    else if( inputString.startsWith( "setWarmLight:" ) ) {
        char state = inputString.charAt( inputStringLength );
        if( state == '0' ){
            setLeds( WARM_LED_PIN, LOW );
        }
        else if( state == '1' ){
            setLeds( WARM_LED_PIN, HIGH );
        }
    }
    else if( inputString.startsWith( "setColdLight:" ) ) {
        char state = inputString.charAt( inputStringLength );
        if( state == '0' ){
            setLeds( COLD_LED_PIN, LOW );
        }
        else if( state == '1' ){
            setLeds( COLD_LED_PIN, HIGH );
        }
    }

    // reset inputString
    inputString = "";
    inputStringLength = 0;
}

void sendStates(){
    Serial.println( "waterLvl:" + String( waterLvl ) );
    Serial.println( "temp:" + String( temp ) );
    Serial.println( "light:" + String( light ) );
    Serial.println( "coldLightIntensity" + String( coldLightIntensity ) );
    Serial.println( "warmLightIntensity" + String( warmLightIntensity ) );
    Serial.println( "pumpIntensity" + String( pumpIntensity ) );
}
