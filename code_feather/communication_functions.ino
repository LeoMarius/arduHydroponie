void checkSerial() {
    while( Serial.available() ) {
        char inChar = ( char ) Serial.read();
        mySerial.print( inChar );
    }

    while( mySerial.available() ) {
        char inChar = ( char ) mySerial.read();
        if( inChar != '\n' ) {
            inputString += inChar;
            inputStringLength ++;
        }
        else {
            if(
                inputString.startsWith( "waterlevel:" ) ||
                inputString.startsWith( "leds:" ) ||
                inputString.startsWith( "pump:" )
            ){
                int index = inputString.indexOf( ":" );
                String feedName = inputString.substring( 0, index );
                char feedNameAsCharArray[ index + 1 ];
                feedName.toCharArray( feedNameAsCharArray, index + 1 );
                String value = inputString.substring( index + 1 );

                Serial.print( feedNameAsCharArray );
                Serial.print( "->" );
                Serial.println( value );

                group->set( feedNameAsCharArray, value );
            }
            else if( inputString.startsWith( "alert1" ) ) {
                group->set( "alert1", 1 );
            }
            else if( inputString.startsWith( "alert0" ) ) {
                group->set( "alert0", 1 );
            }
            else {
                Serial.print( "logs" );
                Serial.print( "->" );
                Serial.println( inputString );
            }
            group->save();

            inputString = "";
            inputStringLength = 0;
        }
    }
}
