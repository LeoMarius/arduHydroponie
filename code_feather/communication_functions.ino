void serialEvent(){
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
        digitalWrite( RED_LED, LOW );
        Serial.print( "sending -> " );
        Serial.println( inputString );
        logsFeed->save( inputString );

        inputString = "";
        inputStringLength = 0;
        stringComplete = false;
        digitalWrite( RED_LED, HIGH );
    }
}
