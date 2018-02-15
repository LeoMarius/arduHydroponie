#include "config.h"
#include <SoftwareSerial.h>
#include <SimpleTimer.h>

#define RED_LED 0
#define BLUE_LED 2

SoftwareSerial mySerial( 14, 12 );
String inputString = "";
int inputStringLength = 0;

AdafruitIO_Group *group = io.group( "default" );

SimpleTimer timer;
long ts = 0;

void setup() {
    pinMode( RED_LED, OUTPUT );
    digitalWrite( RED_LED, HIGH );
    pinMode( BLUE_LED, OUTPUT );
    digitalWrite( BLUE_LED, HIGH );

    Serial.begin( 9600 );

    // connect to io.adafruit.com
    io.connect();

    // group->onMessage( "pump", handlePumpFeed );
    // group->onMessage( "leds", handleLedsFeed );

    // wait for a connection
    while ( io.status() < AIO_CONNECTED ) {
        Serial.print( "." );
        delay( 500 );
    }
    digitalWrite( BLUE_LED, LOW );

    // we are connected
    Serial.println();
    Serial.println( io.statusText() );

    inputString.reserve( 200 ); // reserve a buffer in memory for 200 chars max
    // mySerial.println( "getValues" );

    timer.setInterval( 60000L, checkWifi );
}

void loop() {
    io.run();
    checkSerial();
}

void checkWifi() {
    if ( io.status() < AIO_CONNECTED ) {
        Serial.print( "Connecting to Adafruit IO" );

        // connect to io.adafruit.com
        io.connect();
        while ( io.status() < AIO_CONNECTED ) {
            Serial.print( "." );
            delay( 500 );
        }
    }
}
