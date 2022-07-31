#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "Arduino.h"

class Uart
{
public:
  Uart();
  bool init(uint32_t baudrate, unsigned long timeout);
  bool receiveMessage(uint8_t length, String &message);
  bool sendMessage(String message);

private:
  bool _isInitialized;
  uint32_t _baudrate;
  unsigned long _timeout;
};

#endif
