// [me_Bits] test/demo

/*
  Author: Martin Eden
  Last mod.: 2024-10-25
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>
#include <me_UartSpeeds.h>
#include <me_Console.h>

void setup()
{
  Serial.begin(me_UartSpeeds::Arduino_Normal_Bps);
  Console.Print("[me_Bits] Start.");
  RunTest();
  Console.Print("[me_Bits] Done.");
}

void loop()
{
}

// --

void RunTest()
{
}

/*
  2024-10-25
*/
