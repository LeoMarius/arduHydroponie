void handlePumpStateFeed( AdafruitIO_Data *data ) {
    Serial.print( "setPump:" );
    String value = String( data->value() );
    Serial.println( value.equals( "OFF" ) ? "0" : "1" );
}

void handleWarmLedsFeed( AdafruitIO_Data *data ) {
    Serial.print( "setWarmLight:" );
    String value = String( data->value() );
    Serial.println( value.equals( "OFF" ) ? "0" : "1" );
}

void handleColdLedsFeed( AdafruitIO_Data *data ) {
    Serial.print( "setColdLight:" );
    String value = String( data->value() );
    Serial.println( value.equals( "OFF" ) ? "0" : "1" );
}
