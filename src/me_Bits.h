// Bits access

/*
  Author: Martin Eden
  Last mod.: 2025-08-15
*/

#pragma once

#include <me_BaseTypes.h>

/*
  Getting/setting bit in byte
*/
namespace me_Bits
{
  // Get bit
  TBool GetBit(
    TUint_1 * BitValue,
    TUint_1 Value,
    TUint_1 Offset
  );

  // Set bit to zero
  TBool SetBitToZero(
    TUint_1 * Value,
    TUint_1 Offset
  );

  // Set bit to one
  TBool SetBitToOne(
    TUint_1 * Value,
    TUint_1 Offset
  );

  // Set bit to value
  TBool SetBit(
    TUint_1 * Value,
    TUint_1 Offset,
    TUint_1 BitValue
  );

  // Internals for some clients
  namespace Freetown
  {
    TBool CheckBitOffset(TUint_1 BitOffset);
    TBool CheckBitValue(TUint_1 BitValue);
  }
}

/*
  2024-10-25
  2024-10-26
  2025-07-29
  2025-08-15 Checkers are now exposed in Freetown
*/
