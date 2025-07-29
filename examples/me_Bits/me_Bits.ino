// [me_Bits] test/demo

/*
  Author: Martin Eden
  Last mod.: 2025-07-29
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>
#include <me_Uart.h>
#include <me_Console.h>

/*
  Get byte

  We need non-fixed value. Else gcc just hardcodes result output.
*/
void GetByte(
  TUint_1 * Byte
)
{
  *Byte = analogRead(A0);
}

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

  TUint_1 BitValue;

  Console.Write("Bit");
  Console.Print(BitOffset);
  Console.Write("is");

  if (!GetBit(&BitValue, Byte, BitOffset))
    Console.Print("( Failed to get bit )");

  Console.Print(BitValue);
  Console.EndLine();
}

void RunTest()
{
  using
    me_Bits::SetBitToOne,
    me_Bits::SetBitToZero;

  TUint_1 Byte;

  // Filling byte with ones
  {
    Console.Print("( Filling byte with ones");
    Console.Indent();

    GetByte(&Byte);
    PrintByte(Byte);

    for (TUint_1 Offset = 0; Offset < 8; ++Offset)
    {
      if (!SetBitToOne(&Byte, Offset))
        Console.Print("Failed to set bit.");

      PrintByte(Byte);
    }

    Console.Unindent();
    Console.Print(")");
  }

  // Filling byte with zeroes
  {
    Console.Print("( Filling byte with zeroes");
    Console.Indent();

    GetByte(&Byte);
    PrintByte(Byte);

    for (TSint_1 Offset = 7; Offset >= 0; --Offset)
    {
      if (!SetBitToZero(&Byte, Offset))
        Console.Print("Failed to set bit.");

      PrintByte(Byte);
    }

    Console.Unindent();
    Console.Print(")");
  }

  // Getting bits of some byte value
  {
    Console.Print("( Getting bits of byte");
    Console.Indent();

    GetByte(&Byte);
    PrintByte(Byte);

    for (TSint_1 Offset = 7; Offset >= 0; --Offset)
      PrintBit(Offset, Byte);

    Console.Unindent();
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
