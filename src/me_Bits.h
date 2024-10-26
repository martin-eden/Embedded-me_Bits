// Bits access

/*
  Author: Martin Eden
  Last mod.: 2024-10-26
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_Bits
{
  // Get bit in byte
  TBool GetBit(
    TUint_1 Value,
    TUint_1 Offset
  );

  // Set bit in byte
  TBool SetBit(
    TUint_1 * Value,
    TUint_1 Offset,
    TBool BitValue
  );
}

/*
  2024-10-25
  2024-10-26
*/
