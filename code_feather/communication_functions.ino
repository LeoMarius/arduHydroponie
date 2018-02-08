void checkSerial(){
    while ( Serial.available() && !stringComplete ) {
        char inChar = ( char ) Serial.read();
        if ( inChar != '\n' ) {
            inputString += inChar;
            inputStringLength ++;
        }
        else {
            stringComplete = true;
        }
    }

    if ( stringComplete ) {
        if(
            inputString.startsWith( "waterlevel:" ) ||
            inputString.startsWith( "temp:" ) ||
            inputString.startsWith( "light:" ) ||
            inputString.startsWith( "coldleds:" ) ||
            inputString.startsWith( "warmleds:" ) ||
            inputString.startsWith( "pump:" )
        ){
            int index = inputString.indexOf( ":" );
            String feedName = inputString.substring( 0, index );
            char feedNameAsCharArray[ index + 1 ];
            feedName.toCharArray( feedNameAsCharArray, index + 1 );
            String value = inputString.substring( index + 1 );
            group->set( feedNameAsCharArray, value );
        }
        else {
            group->set( "logs", inputString );
        }
        group->save();

        inputString = "";
        inputStringLength = 0;
        stringComplete = false;
    }
}
