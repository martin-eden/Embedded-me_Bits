// Bits access

/*
  Author: Martin Eden
  Last mod.: 2024-10-25
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_Bits
{
  // Set bit in byte
  TBool SetBit(
    TUint_1 * Result,
    TUint_1 Value,
    TUint_1 Offset,
    TBool BitValue
  );

  // Get bit in byte
  TBool GetBit(
    TBool * Result,
    TUint_1 Value,
    TUint_1 Offset
  );
}

/*
  2024-10-25
*/
