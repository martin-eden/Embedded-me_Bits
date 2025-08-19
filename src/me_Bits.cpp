// Bits access. Interface implementation

/*
  Author: Martin Eden
  Last mod.: 2025-08-19
*/

#include "me_Bits.h"

#include <me_BaseTypes.h>

using namespace me_Bits;

/*
  Check bit value
*/
TBool me_Bits::CheckBitValue(
  TUint_1 BitValue
)
{
  return (BitValue <= 1);
}

/*
  Check bit offset
*/
TBool me_Bits::CheckBitOffset(
  TUint_1 BitOffset
)
{
  return (BitOffset <= 7);
}

/*
  Get bit in byte
*/
TBool me_Bits::GetBit(
  TUint_1 * BitValue,
  TUint_1 ByteValue,
  TUint_1 BitOffset
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
  TUint_1 BitValue
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
  2024-10 # #
  2025-07-29
  2025-08-15
  2025-08-19
*/
