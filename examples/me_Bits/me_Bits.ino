// [me_Bits] test/demo

/*
  Author: Martin Eden
  Last mod.: 2024-12-19
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>
#include <me_Uart.h>
#include <me_Console.h>

void setup()
{
  me_Uart::Init(me_Uart::Speed_115k_Bps);
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
