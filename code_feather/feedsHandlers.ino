void handlePumpFeed( AdafruitIO_Data *data ) {
    String value = String( data->value() );
    Serial.print( "setPump:" );
    Serial.println( value.startsWith( "OFF" ) ? "0" : "1" );
}

void handleLedsFeed( AdafruitIO_Data *data ) {
    String value = String( data->value() );
    Serial.print( "setLeds:" );
    Serial.println( value.startsWith( "OFF" ) ? "0" : "1" );
}
