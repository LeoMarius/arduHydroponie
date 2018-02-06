#include "config.h"

#define RED_LED 0
#define BLUE_LED 2

String inputString = "";
int inputStringLength = 0;
boolean stringComplete = false;

AdafruitIO_Feed *logsFeed = io.feed( "logs" );

AdafruitIO_Feed *tempFeed = io.feed( "temp" );
AdafruitIO_Feed *lightFeed = io.feed( "light" );
AdafruitIO_Feed *waterLvlFeed = io.feed( "waterlevel" );

AdafruitIO_Feed *pumpStateFeed = io.feed( "pumpstate" );
AdafruitIO_Feed *warmLedsFeed = io.feed( "warmleds" );
AdafruitIO_Feed *coldLedsFeed = io.feed( "coldleds" );

void setup() {
    pinMode( RED_LED, OUTPUT );
    digitalWrite( RED_LED, HIGH );
    pinMode( BLUE_LED, OUTPUT );
    digitalWrite( BLUE_LED, HIGH );

    Serial.begin( 9600 );
    Serial.print( "Connecting to Adafruit IO" );

    // connect to io.adafruit.com
    io.connect();

    // wait for a connection
    while ( io.status() < AIO_CONNECTED ) {
        Serial.print( "." );
        delay( 500 );
    }
    digitalWrite( BLUE_LED, LOW );

    // we are connected
    Serial.println();
    Serial.println( io.statusText() );

    pumpStateFeed->onMessage( handlePumpStateFeed );
    warmLedsFeed->onMessage( handleWarmLedsFeed );
    coldLedsFeed->onMessage( handleColdLedsFeed );

    Serial.println( "Waiting for data..." );
    inputString.reserve( 200 ); // reserve a buffer in memory for 200 chars max
}

void loop() {
    io.run();
    serialEvent();
}
