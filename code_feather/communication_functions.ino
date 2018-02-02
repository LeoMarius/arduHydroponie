void serialEvent(){
    while ( Serial.available() && !stringComplete ) {
        digitalWrite( RED_LED, LOW );
        char inChar = ( char ) mySerial.read();
        if ( inChar != '\n' ) {
            inputString += inChar;
            len++;
        }
        else {
            stringComplete = true;
        }
    }

    if ( stringComplete ) {
        Serial.print( "sending -> " );
        Serial.println( inputString );
        char buf[ len ];
        inputString.toCharArray( buf, len );
        Serial.println( counter->save( buf ) );
        inputString = "";
        len = 0;
        stringComplete = false;
        digitalWrite( RED_LED, HIGH );
    }
}
