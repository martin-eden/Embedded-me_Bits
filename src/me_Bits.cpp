// Bits access

/*
  Author: Martin Eden
  Last mod.: 2024-10-25
*/

#include "me_Bits.h"

#include <me_BaseTypes.h>

using namespace me_Bits;

const TUint_1 BitsInByte = 8;
const TUint_1 MaxOffset = BitsInByte - 1;

/*
  Get bit in byte

  Most callers want to see this function as returning bit value,
  not execution status. Most callers are sure they are passing
  valid bit offset.

  If invalid bit offset is passed, we return false. So there is
  clash between execution status and return value. But I think
  callers will debug their code.
*/
TBool me_Bits::GetBit(
  TUint_1 Value,
  TUint_1 Offset
)
{
  if (Offset > MaxOffset)
    return false;

  TBool Result;

  TUint_1 Mask = (1 << Offset);

  Result = ((Value & Mask) != 0);

  return Result;
}

/*
  Set bit in byte

  We're updating value in place.

  Unlike GetBit() we have freedom to return execution status.
*/
TBool me_Bits::SetBit(
  TUint_1 * Value,
  TUint_1 Offset,
  TBool BitValue
)
{
  if (Offset > MaxOffset)
    return false;

  TUint_1 Mask;

  if (BitValue == false)
  {
    // Clear bit
    Mask = ~(1 << Offset);
    *Value = *Value & Mask;
  }
  else if (BitValue == true)
  {
    // Set bit
    Mask = (1 << Offset);
    *Value = *Value | Mask;
  }

  return true;
}

/*
  2024-10-25
  2024-10-26
*/
