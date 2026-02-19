// Bits access. Interface implementation

/*
  Author: Martin Eden
  Last mod.: 2026-02-19
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>

using namespace me_Bits;

/*
  Check bit value: 0 or 1
*/
TBool me_Bits::CheckBitValue(
  TUint_1 BitValue
)
{
  return (BitValue <= 1);
}

/*
  Check bit offset: from 0 to 7
*/
TBool me_Bits::CheckBitOffset(
  TBitOffset BitOffset
)
{
  return (BitOffset <= 7);
}

/*
  Get bit in byte
*/
TBool me_Bits::GetBit(
  TBitValue * BitValue,
  TUint_1 ByteValue,
  TBitOffset BitOffset
)
{
  if (!CheckBitOffset(BitOffset))
    return false;

  Freetown::GetBit(BitValue, ByteValue, BitOffset);

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
  if (!CheckBitOffset(BitOffset))
    return false;

  if (!CheckBitValue(BitValue))
    return false;

  if (BitValue == 1)
    Freetown::SetBit(ByteValue, BitOffset);
  else
    Freetown::ClearBit(ByteValue, BitOffset);

  return true;
}

/*
  2024 # #
  2025 # # #
  2026-02-19
*/
