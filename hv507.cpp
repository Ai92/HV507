#include "hv507.h"

HV507::HV507() : _isInitialized(false)
{
}

bool HV507::init(int8_t clockPin, int8_t latchPin, int8_t dataPin, int8_t polarityPin, int8_t blankingPin, int8_t directionPin)
{
    _clockPin = clockPin;
    _latchPin = latchPin;
    _dataPin = dataPin;
    _polarityPin = polarityPin;
    _blankingPin = blankingPin;
    _directionPin = directionPin;

    pinMode(_clockPin, OUTPUT);
    pinMode(_latchPin, OUTPUT);
    pinMode(_dataPin, OUTPUT);
    pinMode(_polarityPin, OUTPUT);
    pinMode(_blankingPin, OUTPUT);
    pinMode(_directionPin, OUTPUT);
    digitalWrite(_clockPin, 0);
    digitalWrite(_latchPin, 0);
    digitalWrite(_dataPin, 0);
    digitalWrite(_polarityPin, 1);
    digitalWrite(_blankingPin, 0);
    digitalWrite(_directionPin, 0);

    _isInitialized = true;

    return true;
}

bool HV507::setPins(byte pinsState[])
{
    // load SR
    digitalWrite(_latchPin, 0);
    digitalWrite(_blankingPin, 0);
    digitalWrite(_polarityPin, 1);
    for (int i = 0; i < NUMBER_OF_BYTES; i++)
    {
        loadSR(pinsState[i]);
    }

    // store data
    digitalWrite(_latchPin, 1);
    digitalWrite(_blankingPin, 0);
    digitalWrite(_polarityPin, 1);
    digitalWrite(_latchPin, 0);
    digitalWrite(_blankingPin, 0);
    digitalWrite(_polarityPin, 1);

    return true;
}

bool HV507::loadSR(byte data)
{
    if (!_isInitialized)
        return false;

    for (int i = 7; i >= 0; i--)
    {
        digitalWrite(_clockPin, 0);
        if (data & (1 << i))
        {
            digitalWrite(_dataPin, 0);
        }
        else
        {
            digitalWrite(_dataPin, 1);
        }
        digitalWrite(_clockPin, 1);
        digitalWrite(_dataPin, 0);
    }
    digitalWrite(_clockPin, 0);

    return true;
}
