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

// Get bit in byte
TBool me_Bits::GetBit(
  TBool * Result,
  TUint_1 Value,
  TUint_1 Offset
)
{
  if (Offset > MaxOffset)
    return false;

  TUint_1 Mask = (1 << Offset);

  *Result = ((Value & Mask) != 0);

  return true;
}

// Set bit in byte
TBool me_Bits::SetBit(
  TUint_1 * Result,
  TUint_1 Value,
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
    *Result = Value & Mask;
  }
  else if (BitValue == true)
  {
    // Set bit
    Mask = (1 << Offset);
    *Result = Value | Mask;
  }

  return true;
}

/*
  2024-10-25
*/
