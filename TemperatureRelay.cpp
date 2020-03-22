#include "Arduino.h"
#include "TemperatureRelay.h"

TemperatureRelay::TemperatureRelay (int8_t pin, uint8_t temp) : ArduinoRelay(pin) {
    if (mode() == MODE_COOL) {
        _onTemp = temp;
        _offTemp = temp - factor();
    }
    else if (mode() == MODE_HEAT) {
        _onTemp = temp;
        _offTemp = temp + factor();
    }
}

TemperatureRelay::TemperatureRelay (uint8_t temp) : ArduinoRelay() {
    if (mode() == MODE_COOL) {
        _onTemp = temp;
        _offTemp = temp - factor();
    }
    else if (mode() == MODE_HEAT) {
        _onTemp = temp;
        _offTemp = temp + factor();
    }
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
