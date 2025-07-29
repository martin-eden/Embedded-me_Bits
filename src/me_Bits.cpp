// Bits access

/*
  Author: Martin Eden
  Last mod.: 2024-10-25
*/

#include "me_Bits.h"

#include <me_BaseTypes.h>

using namespace me_Bits;

const TUint_1
  BitsInByte = 8,
  MaxOffset = BitsInByte - 1;

/*
  Check bit offset

  Internal.
*/
TBool CheckBitOffset(
  TUint_1 BitOffset
)
{
  return (BitOffset <= MaxOffset);
}

/*
  Check bit value

  Internal.
*/
TBool CheckBitValue(
  TUint_1 BitValue
)
{
  return (BitValue <= 1);
}

/*
  Get bit in byte
*/
TBool me_Bits::GetBit(
  TUint_1 * BitValue,
  TUint_1 Value,
  TUint_1 Offset
)
{
  if (!CheckBitOffset(Offset))
    return false;

  *BitValue = (Value >> Offset) & 1;

  return true;
}

/*
  Set bit to zero
*/
TBool me_Bits::SetBitToZero(
  TUint_1 * Value,
  TUint_1 Offset
)
{
  if (!CheckBitOffset(Offset))
    return false;

  *Value = *Value & (~(1 << Offset));

  return true;
}

/*
  Set bit to one
*/
TBool me_Bits::SetBitToOne(
  TUint_1 * Value,
  TUint_1 Offset
)
{
  if (!CheckBitOffset(Offset))
    return false;

  *Value = *Value | (1 << Offset);

  return true;
}

/*
  Set bit in byte
*/
TBool me_Bits::SetBit(
  TUint_1 * Value,
  TUint_1 Offset,
  TUint_1 BitValue
)
{
  if (!CheckBitValue(BitValue))
    return false;

  if (BitValue == 1)
    return SetBitToOne(Value, Offset);
  else
    return SetBitToZero(Value, Offset);
}

/*
  2024-10 # #
  2025-07-29
*/
