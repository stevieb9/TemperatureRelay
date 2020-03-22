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

    public:
        TemperatureRelay(int8_t pin, uint8_t onTemp, uint8_t offTemp);
        TemperatureRelay(uint8_t onTime, uint8_t offTime);

        uint8_t onTemp () { return _onTemp; }
        uint8_t onTemp (uint8_t onTemp) { _onTemp = onTemp; return _onTemp; }

        uint8_t offTemp () { return _offTemp; }
        uint8_t offTemp (uint8_t offTemp) { _offTemp = offTemp; return _offTemp; }

        uint8_t mode () { return _mode; }
        uint8_t mode (uint8_t mode) { _mode = mode; return _mode; }

        void process (float tempF);
};

#endif

