#ifndef HV507_H_
#define HV507_H_

#include <stdint.h>
#include "Arduino.h"

class HV507
{
public:
    HV507();
    bool init(int8_t _clockPin, int8_t latchPin, int8_t dataPin, int8_t polarityPin, int8_t blankingPin, int8_t directionPin);
    bool setPins(uint8_t pinsState[]); // state: 0=off, 1=on,
    bool loadSR(uint8_t data);

private:
    int8_t NUMBER_OF_BYTES = 8;

    int8_t _clockPin;
    int8_t _latchPin;
    int8_t _dataPin;
    int8_t _polarityPin;
    int8_t _blankingPin;
    int8_t _directionPin;

    //int8_t _pinsState[8]; // [0]: 0-7, [1]: 8-15, ... , [7]: 56-63

    bool _isInitialized;
};

#endif
