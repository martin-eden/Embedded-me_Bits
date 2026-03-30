// Bits access. Interface implementation

/*
  Author: Martin Eden
  Last mod.: 2026-03-30
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>

using namespace me_Bits;

/*
  Get bit in byte
*/
TBool me_Bits::GetBit(
  TBitValue * BitValue,
  TUint_1 * ByteValue,
  TBitOffset BitOffset
)
{
  if (!Freetown::CheckBitOffset(BitOffset))
    return false;

  Freetown::GetBit(BitValue, ByteValue, Freetown::GetBitMask(BitOffset));

  return true;
}

/*
  Set bit in byte
*/
TBool me_Bits::SetBitTo(
  TUint_1 * ByteValue,
  TUint_1 BitOffset,
  TBitValue BitValue
)
{
  if (!Freetown::CheckBitOffset(BitOffset))
    return false;

  if (!Freetown::CheckBitValue(BitValue))
    return false;

  if (BitValue == 1)
    Freetown::SetBit(ByteValue, Freetown::GetBitMask(BitOffset));
  else
    Freetown::ClearBit(ByteValue, Freetown::GetBitMask(BitOffset));

  return true;
}

/*
  2024 # #
  2025 # # #
  2026-02-17
  2026-02-19
  2026-03-30
*/
