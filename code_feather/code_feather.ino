#include "config.h"

#define RED_LED 0
#define BLUE_LED 2

String inputString = "";
int inputStringLength = 0;
boolean stringComplete = false;

AdafruitIO_Group *group = io.group( "default" );

long ts = 0;

void setup() {
    pinMode( RED_LED, OUTPUT );
    digitalWrite( RED_LED, HIGH );
    pinMode( BLUE_LED, OUTPUT );
    digitalWrite( BLUE_LED, HIGH );

    Serial.begin( 9600 );

    // connect to io.adafruit.com
    io.connect();

    group->onMessage( "pump", handlePumpFeed );
    group->onMessage( "leds", handleLedsFeed );

    // wait for a connection
    while ( io.status() < AIO_CONNECTED ) {
        Serial.print( "." );
        delay( 500 );
    }
    digitalWrite( BLUE_LED, LOW );

    // we are connected
    Serial.println();
    Serial.println( io.statusText() );

    Serial.println( "getValues" );
    inputString.reserve( 200 ); // reserve a buffer in memory for 200 chars max
}

void loop() {
    io.run();
    checkSerial();
}
