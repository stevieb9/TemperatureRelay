#include "Arduino.h"
#include "TemperatureRelay.h"

TemperatureRelay::TemperatureRelay (int8_t pin, uint8_t temp) : ArduinoRelay(pin) {
    baseTemp(temp);

    if (mode() == MODE_COOL) {
        onTemp(baseTemp());
        offTemp(baseTemp() - factor());
    }
    else if (mode() == MODE_HEAT) {
        onTemp(baseTemp());
        offTemp(baseTemp() + factor());
    }
}

TemperatureRelay::TemperatureRelay (uint8_t temp) : ArduinoRelay() {
    baseTemp(temp);

    if (mode() == MODE_COOL) {
        onTemp(baseTemp());
        offTemp(baseTemp() - factor());
    }
    else if (mode() == MODE_HEAT) {
        onTemp(baseTemp());
        offTemp(baseTemp() + factor());
    }
}

uint8_t TemperatureRelay::mode () {
    return _mode;
}

uint8_t TemperatureRelay::mode (uint8_t opMode) {
    _mode = opMode;

    if (_mode == MODE_COOL) {
        onTemp(baseTemp());
        offTemp(baseTemp() - factor());
    }
    else if (_mode == MODE_HEAT) {
        onTemp(baseTemp());
        offTemp(baseTemp() + factor());
    }

    return _mode;
}


void TemperatureRelay::process (float tempF) {

    if (pin() == -1) {
        return;
    }

    if (mode() == MODE_COOL) {
        // Turn the outlet on

        if (state() == off() && tempF > (float)onTemp() || !init()) {
            if (!init()) {
                init(true);
            }
            state(on());
            turnOn();
        }

            // Turn the outlet off

        else if (state() == on() && tempF < (float)offTemp()) {
            state(off());
            turnOff();
        }
    }

    else if (mode() == MODE_HEAT) {
        // Turn the outlet on

        if (state() == off() && tempF < (float)onTemp() || !init()) {
            if (!init()) {
                init(true);
            }
            state(on());
            turnOn();
        }

            // Turn the outlet off

        else if (state() == on() && tempF > (float)offTemp()) {
            state(off());
            turnOff();
        }
    }
}
