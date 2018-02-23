///// For Adafruit Pro Trinket 5V
///////////////////////////////////////////////////

#define READ_WATERLEVEL_INTERVAL 5000
#define WATERLEVEL0_ALERT_INTERVAL 86400000L
#define SEND_STATES_INTERVAL 300000L
#define TOGGLE_PUMP_INTERVAL 3600000L

#define WATER_LVL1_PIN 9
#define WATER_LVL2_PIN 10
#define PUMP_PIN A0
#define LED_PIN 11

// https://github.com/schinken/SimpleTimer
#include <SimpleTimer.h>
SimpleTimer timer;

int waterLvl = 0,
    ledsIntensity = 0,
    pumpIntensity = 0;

// for pump toggle, if waterLvl == 1
boolean activePump = true;

// Serial communication
String inputString = "";
int inputStringLength = 0;

void setup() {
    // init pins
    pinMode( WATER_LVL1_PIN, INPUT );
    pinMode( WATER_LVL2_PIN, INPUT );

    pinMode( PUMP_PIN, OUTPUT );
    setPump( LOW );

    pinMode( LED_PIN, OUTPUT );

    setLeds( HIGH );

    // Init Serial communication
    Serial.begin( 9600 );
    // reserve 200 bytes for the inputString
    inputString.reserve( 200 );

    // init timed loops
    timer.setInterval( READ_WATERLEVEL_INTERVAL, readWaterLevel );
    timer.setInterval( WATERLEVEL0_ALERT_INTERVAL, waterLevel0Alert );
    timer.setInterval( SEND_STATES_INTERVAL, sendStates );
    timer.setInterval( TOGGLE_PUMP_INTERVAL, togglePump );

    waterLvl = getWaterLevel();
}

void loop() {
    timer.run();
    //getWaterLevel(); // uncomment for testing water level sensors + comment timer.run();
    delay( 100 );
}
