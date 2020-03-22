#ifndef TEMPERATURERELAY_H
#define TEMPERATURERELAY_H

#include "Arduino.h"
#include "../ArduinoRelay/ArduinoRelay.h"

#define MODE_HEAT   true
#define MODE_COOL   false

using namespace std;

class TemperatureRelay : public ArduinoRelay {

    private:
        uint8_t _onTemp  = 0;
        uint8_t _offTemp = 0;
        uint8_t _mode    = false; // false=cool, true=heat
        uint8_t _factor  = 1;

    public:
        TemperatureRelay(int8_t pin, uint8_t temp);
        TemperatureRelay(uint8_t temp);

        uint8_t onTemp () { return _onTemp; }
        uint8_t onTemp (uint8_t onTemp) { _onTemp = onTemp; return _onTemp; }

        uint8_t offTemp () { return _offTemp; }
        uint8_t offTemp (uint8_t offTemp) { _offTemp = offTemp; return _offTemp; }

        uint8_t mode () { return _mode; }
        uint8_t mode (uint8_t mode) { _mode = mode; return _mode; }

        uint8_t factor () { return _factor; }
        uint8_t factor (uint8_t factor) { _factor = factor; return _factor; }

        void process (float tempF);
};

#endif

