// [me_Bits] test/demo

/*
  Author: Martin Eden
  Last mod.: 2026-02-20
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>
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
  TUint_1 ByteValue
)
{
  using
    me_Bits::GetBit;

  TUint_1 BitValue;

  Console.Write("Bit");
  Console.Print(BitOffset);
  Console.Write("is");

  if (!GetBit(&BitValue, ByteValue, BitOffset))
    Console.Print("( Failed to get bit )");

  Console.Print(BitValue);
  Console.EndLine();
}

void RunTest()
{
  TUint_1 Byte;

  // Filling byte with ones
  {
    Console.Print("( Filling byte with ones");
    Console.Indent();

    GetByte(&Byte);
    PrintByte(Byte);

    for (TUint_1 BitOffs = 0; BitOffs < 8; ++BitOffs)
    {
      if (!me_Bits::SetBitTo(&Byte, BitOffs, 1))
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

    for (TSint_1 BitOffs = 7; BitOffs >= 0; --BitOffs)
    {
      if (!me_Bits::SetBitTo(&Byte, BitOffs, 0))
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

    for (TSint_1 BitOffs = 7; BitOffs >= 0; --BitOffs)
      PrintBit(BitOffs, Byte);

    Console.Unindent();
    Console.Print(")");
  }
}

void setup()
{
  Console.Init();
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
  2025-08-19
*/
