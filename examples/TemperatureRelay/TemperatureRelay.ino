#include "TemperatureRelay.h"

#define RELAY_PIN   2
#define ON_TEMP   78
#define OFF_TEMP  77

/* Normal constructor */
TemperatureRelay ctr(RELAY_PIN, ON_TEMP, OFF_TEMP);

/* No pin constructor */
//TemperatureRelay ctr(ON_TEMP, OFF_TEMP);

void setup() {
    /* Optionally set a name for the object */
    ctr.name("CTR");

    /* Reverse: On = LOW, Off = HIGH */
    //ctr.reverse(true);

    /* Mode: 0 = Cool, 1 = Heat; Default Cool */
    //ctr.mode(MODE_HEAT);
}

void loop() {
    float tempF = 77.28;

    /* Signal the timer on each pass of loop() */
    ctr.process(tempF);

    /* Check the current state of the pin */
    bool state = ctr.state();

    /* Check reverse state */
    bool reversed = ctr.reverse();
    
    /* Get the name of the object */
    char* name = ctr.name();

    /* Get the on or off temp */
    unsigned long onTemp  = ctr.onTemp();
    unsigned long offTemp = ctr.offTemp();

    /* Set the on and off temps */
    ctr.onTemp(ON_TEMP);
    ctr.offTemp(OFF_TEMP);

    /* Get/set the relay pin */
    int8_t = ctr.pin();
    //ctr.pin(RELAY_PIN);

    /* Disable the relay */
    //ctr.pin(-1);
}
