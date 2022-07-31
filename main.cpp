#include "Arduino.h"
#include "config.h"
#include "uart.h"
#include "data_parser.h"
#include "hv507.h"

Uart uart;
HV507 hv507;
String message;
uint16_t frequency;
uint8_t duty;
uint8_t repeat;
uint8_t pincontrol0;
uint8_t pincontrol1;
uint8_t pincontrol2;
uint8_t pincontrol3;
uint8_t pincontrol4;
uint8_t pincontrol5;
uint8_t pincontrol6;
uint8_t pincontrol7;
// uint8_t pincontrol8;
// uint8_t pincontrol9;
// uint8_t pincontrol10;
// uint8_t pincontrol11;
// uint8_t pincontrol12;
// uint8_t pincontrol13;
// uint8_t pincontrol14;
// uint8_t pincontrol15;
// uint8_t pincontrol16;
// uint8_t pincontrol17;
// uint8_t pincontrol18;
// uint8_t pincontrol19;
// uint8_t pincontrol20;
// uint8_t pincontrol21;
// uint8_t pincontrol22;
// uint8_t pincontrol23;
// uint8_t pincontrol24;
// uint8_t pincontrol25;
// uint8_t pincontrol26;
// uint8_t pincontrol27;
// uint8_t pincontrol28;
// uint8_t pincontrol29;
// uint8_t pincontrol30;
// uint8_t pincontrol31;
// uint8_t pincontrol32;
// uint8_t pincontrol33;
// uint8_t pincontrol34;
// uint8_t pincontrol35;
// uint8_t pincontrol36;
// uint8_t pincontrol37;
// uint8_t pincontrol38;
// uint8_t pincontrol39;
// uint8_t pincontrol40;
// uint8_t pincontrol41;
// uint8_t pincontrol42;
// uint8_t pincontrol43;
// uint8_t pincontrol44;
// uint8_t pincontrol45;
// uint8_t pincontrol46;
// uint8_t pincontrol47;
// uint8_t pincontrol48;
// uint8_t pincontrol49;
// uint8_t pincontrol50;
// uint8_t pincontrol51;
// uint8_t pincontrol52;
// uint8_t pincontrol53;
// uint8_t pincontrol54;
// uint8_t pincontrol55;
// uint8_t pincontrol56;
// uint8_t pincontrol57;
// uint8_t pincontrol58;
// uint8_t pincontrol59;
// uint8_t pincontrol60;
// uint8_t pincontrol61;
// uint8_t pincontrol62;
// uint8_t pincontrol63;
// uint8_t pincontrol64;
// uint8_t pincontrol65;
// uint8_t pincontrol66;
// uint8_t pincontrol67;
// uint8_t pincontrol68;
// uint8_t pincontrol69;
// uint8_t pincontrol70;
// uint8_t pincontrol71;

void setup()
{
  uart.init((uint32_t)BAUDRATE, (unsigned long)TIMEOUT);
  hv507.init((int8_t)CLOCK_PIN, (int8_t)LATCH_PIN, (int8_t)DATA_PIN, (int8_t)POLARITY_PIN, (int8_t)BLANKING_PIN, (int8_t)DIRECTION_PIN);
  delay(200);
}

void loop()
{
  bool result;
  result = uart.receiveMessage(7, message);
  // result = uart.receiveMessage(81, message);
  if (result == false)
    return; // processing is nothing because any command is not received.

  result = GetHv507Parameters(message, pincontrol0, pincontrol1, pincontrol2, pincontrol3, pincontrol4, pincontrol5, pincontrol6, pincontrol7);
  // result = GetHv507Parameters(message, pincontrol0, pincontrol1, pincontrol2, pincontrol3, pincontrol4, pincontrol5, pincontrol6, pincontrol7, pincontrol8, pincontrol9, pincontrol10, pincontrol11, pincontrol12, pincontrol13, pincontrol14, pincontrol15, pincontrol16, pincontrol17, pincontrol18, pincontrol19, pincontrol20, pincontrol21, pincontrol22, pincontrol23, pincontrol24, pincontrol25, pincontrol26, pincontrol27, pincontrol28, pincontrol29, pincontrol30, pincontrol31, pincontrol32, pincontrol33, pincontrol34, pincontrol35, pincontrol36, pincontrol37, pincontrol38, pincontrol39, pincontrol40, pincontrol41, pincontrol42, pincontrol43, pincontrol44, pincontrol45, pincontrol46, pincontrol47, pincontrol48, pincontrol49, pincontrol50, pincontrol51, pincontrol52, pincontrol53, pincontrol54, pincontrol55, pincontrol56, pincontrol57, pincontrol58, pincontrol59, pincontrol60, pincontrol61, pincontrol62, pincontrol63, pincontrol64, pincontrol65, pincontrol66, pincontrol67, pincontrol68, pincontrol69, pincontrol70, pincontrol71);

  if (result == false)
  {
    uart.sendMessage("Main: loop()# received command is invalid");
    uart.sendMessage(message);
    return;
  }

  uint8_t temp = 0;

  uint8_t pinsState[8];
  //pinsState[0] = 0b00000000;
  //pinsState[1] = 0b00000000;
  //pinsState[2] = 0b00000000;
  //pinsState[3] = 0b00000000;
  //pinsState[4] = 0b00000000;
  //pinsState[5] = 0b10000000;
  //pinsState[6] = 0b00000000;
  //pinsState[7] = 0b00000000;

  if (temp == 0)
  {
    //255,0,0,0,0,0,0,0
    pinsState[0] = pincontrol0;
    pinsState[1] = pincontrol1;
    pinsState[2] = pincontrol2;
    pinsState[3] = pincontrol3;
    pinsState[4] = pincontrol4;
    pinsState[5] = pincontrol5;
    pinsState[6] = pincontrol6;
    pinsState[7] = pincontrol7;
    hv507.setPins(pinsState);

    // pinsState[0] = pincontrol8;
    // pinsState[1] = pincontrol9;
    // pinsState[2] = pincontrol10;
    // pinsState[3] = pincontrol11;
    // pinsState[4] = pincontrol12;
    // pinsState[5] = pincontrol13;
    // pinsState[6] = pincontrol14;
    // pinsState[7] = pincontrol15;
    // hv507.setPins(pinsState);

    // pinsState[0] = pincontrol16;
    // pinsState[1] = pincontrol17;
    // pinsState[2] = pincontrol18;
    // pinsState[3] = pincontrol19;
    // pinsState[4] = pincontrol20;
    // pinsState[5] = pincontrol21;
    // pinsState[6] = pincontrol22;
    // pinsState[7] = pincontrol23;
    // hv507.setPins(pinsState);

    // pinsState[0] = pincontrol24;
    // pinsState[1] = pincontrol25;
    // pinsState[2] = pincontrol26;
    // pinsState[3] = pincontrol27;
    // pinsState[4] = pincontrol28;
    // pinsState[5] = pincontrol29;
    // pinsState[6] = pincontrol30;
    // pinsState[7] = pincontrol31;
    // hv507.setPins(pinsState);

    // pinsState[0] = pincontrol32;
    // pinsState[1] = pincontrol33;
    // pinsState[2] = pincontrol34;
    // pinsState[3] = pincontrol35;
    // pinsState[4] = pincontrol36;
    // pinsState[5] = pincontrol37;
    // pinsState[6] = pincontrol38;
    // pinsState[7] = pincontrol39;
    // hv507.setPins(pinsState);

    // pinsState[0] = pincontrol40;
    // pinsState[1] = pincontrol41;
    // pinsState[2] = pincontrol42;
    // pinsState[3] = pincontrol43;
    // pinsState[4] = pincontrol44;
    // pinsState[5] = pincontrol45;
    // pinsState[6] = pincontrol46;
    // pinsState[7] = pincontrol47;
    // hv507.setPins(pinsState);

    // pinsState[0] = pincontrol48;
    // pinsState[1] = pincontrol49;
    // pinsState[2] = pincontrol50;
    // pinsState[3] = pincontrol51;
    // pinsState[4] = pincontrol52;
    // pinsState[5] = pincontrol53;
    // pinsState[6] = pincontrol54;
    // pinsState[7] = pincontrol55;
    // hv507.setPins(pinsState);

    // pinsState[0] = pincontrol56;
    // pinsState[1] = pincontrol57;
    // pinsState[2] = pincontrol58;
    // pinsState[3] = pincontrol59;
    // pinsState[4] = pincontrol60;
    // pinsState[5] = pincontrol61;
    // pinsState[6] = pincontrol62;
    // pinsState[7] = pincontrol63;
    // hv507.setPins(pinsState);

    // pinsState[0] = pincontrol64;
    // pinsState[1] = pincontrol65;
    // pinsState[2] = pincontrol66;
    // pinsState[3] = pincontrol67;
    // pinsState[4] = pincontrol68;
    // pinsState[5] = pincontrol69;
    // pinsState[6] = pincontrol70;
    // pinsState[7] = pincontrol71;
    // hv507.setPins(pinsState);

    //Serial.print("stop");
    //Serial.println(timeb,DEC);
  }
}
