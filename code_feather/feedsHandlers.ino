void handlePumpStateFeed( AdafruitIO_Data *data ) {
    Serial.print( "received <- " );
    Serial.print( data->feedName() );
    Serial.print( " " );
    Serial.println( data->value() );
}

void handleWarmLedsFeed( AdafruitIO_Data *data ) {
    Serial.print( "received <- " );
    Serial.print( data->feedName() );
    Serial.print( " " );
    Serial.println( data->value() );
}

void handleColdLedsFeed( AdafruitIO_Data *data ) {
    Serial.print( "received <- " );
    Serial.print( data->feedName() );
    Serial.print( " " );
    Serial.println( data->value() );
}
