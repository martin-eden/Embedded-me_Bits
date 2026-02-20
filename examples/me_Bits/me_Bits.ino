// [me_Bits] test/demo

/*
  Author: Martin Eden
  Last mod.: 2026-02-20
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>
#include <me_Console.h>
#include <me_Delays.h>

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
  me_Bits::TBitOffset BitOffset,
  TUint_1 ByteValue
)
{
  me_Bits::TBitValue BitValue;

  Console.Write("Bit");
  Console.Print(BitOffset);
  Console.Write("is");

  if (!me_Bits::GetBit(&BitValue, ByteValue, BitOffset))
    Console.Print("( Failed to get bit )");

  Console.Print(BitValue);
  Console.EndLine();
}

void RunArgBitTest()
{
  TUint_1 Byte;

  // Filling byte with ones
  {
    Console.Print("( Filling byte with ones");
    Console.Indent();

    GetByte(&Byte);
    PrintByte(Byte);

    for (me_Bits::TBitOffset BitOffset = 0; BitOffset < 8; ++BitOffset)
    {
      if (!me_Bits::SetBitTo(&Byte, BitOffset, 1))
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

void RunFixedBitTest()
{
  // Set output LED to ON, delay, set to OFF, check it's off
  {
    const me_Bits::TBitLocation
      PinModeBitLoc = { Address: 36, BitOffset: 5 },
      PinDriveBitLoc = { Address: 37, BitOffset: 5 };

    me_Bits::TBit PinModeBit;
    me_Bits::TBit PinDriveBit;

    PinModeBit.SetLocation(PinModeBitLoc);
    PinDriveBit.SetLocation(PinDriveBitLoc);

    PinModeBit.Set();

    // Blink LED several times
    {
      const TUint_1 NumRuns = 3;

      for (TUint_1 RunNumber = 1; RunNumber <= NumRuns; ++RunNumber)
      {
        Console.Print("LED blink");

        PinDriveBit.Clear();
        me_Delays::Delay_Ms(1000);
        PinDriveBit.Set();
        me_Delays::Delay_Ms(1000);
      }
    }

    if (PinDriveBit.Get() != 1)
      Console.Print("Unexpected bit value");
  }
}

void setup()
{
  Console.Init();
  Console.Print("[me_Bits] Start.");
  RunArgBitTest();
  RunFixedBitTest();
  Console.Print("[me_Bits] Done.");
}

void loop()
{
}

/*
  2024-10-25
  2025-07-29
  2025-08-19
  2026-02-20
*/
