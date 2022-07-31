#include "uart.h"

Uart::Uart() : _isInitialized(false), _baudrate(9600), _timeout(1000)
{
}

bool Uart::init(uint32_t baudrate, unsigned long timeout)
{
  _baudrate = baudrate;
  _timeout = timeout;
  Serial.setTimeout(timeout);
  Serial.begin(_baudrate, SERIAL_8N1);

  while (!Serial)
  {
  }

  _isInitialized = true;

  return true;
}

bool Uart::receiveMessage(uint8_t length, String &message)
{
  if (!_isInitialized)
    return false;

  if (0 < Serial.available())
  {
    unsigned long startTime = millis();
    String temp = Serial.readStringUntil('\n');
    unsigned long elapsedTime = millis() - startTime;
    if (_timeout <= elapsedTime)
    {
      Serial.println("Uart: receiveMessage()# timeout");
      return false;
    }
    message = temp;
    return true;
  }
  return false;
}

bool Uart::sendMessage(String message)
{
  if (!_isInitialized)
    return false;

  Serial.println(message);

  return true;
}
