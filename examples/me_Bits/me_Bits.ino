// [me_Bits] test/demo

/*
  Author: Martin Eden
  Last mod.: 2025-07-29
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>
#include <me_Uart.h>
#include <me_Console.h>

void PrintByte(
  TUint_1 Byte
)
{
  Console.Write("Byte is");
  Console.Print(Byte);
  Console.EndLine();
}

void PrintBit(
  TUint_1 BitOffset,
  TUint_1 Byte
)
{
  using
    me_Bits::GetBit;

  Console.Write("Bit");
  Console.Print(BitOffset);
  Console.Write("is ");

  if (GetBit(Byte, BitOffset))
    Console.Write("1");
  else
    Console.Write("0");

  Console.EndLine();
}

void RunTest()
{
  using
    me_Bits::SetBit;

  TUint_1 Byte;

  // Filling 0x00 with ones
  {
    Console.Print("( Filling 0x00 with ones");

    Byte = 0;

    PrintByte(Byte);

    for (TUint_1 Offset = 0; Offset < 8; ++Offset)
    {
      SetBit(&Byte, Offset, true);
      PrintByte(Byte);
    }

    Console.Print(")");
  }

  // Filling 0xFF with zeroes
  {
    Console.Print("( Filling 0xFF with zeroes");

    Byte = 0xFF;

    PrintByte(Byte);

    for (TUint_1 Offset = 0; Offset < 8; ++Offset)
    {
      SetBit(&Byte, Offset, false);
      PrintByte(Byte);
    }

    Console.Print(")");
  }

  // Getting bits of some byte value
  {
    Console.Print("( Getting bits of byte 01101001");

    Byte = B01101001;

    for (TSint_1 Offset = 7; Offset >= 0; --Offset)
      PrintBit(Offset, Byte);

    Console.Print(")");
  }
}

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

/*
  2024-10-25
  2025-07-29
*/
