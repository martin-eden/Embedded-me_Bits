// Getting/setting bits in argument's byte

/*
  Author: Martin Eden
  Last mod.: 2026-02-19
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_Bits
{
  // Bit value: 0/1
  typedef TUint_1 TBitValue;

  // Check bit value
  TBool CheckBitValue(TBitValue);

  // Bit offset: 0..7
  typedef TUint_1 TBitOffset;

  // Check bit offset
  TBool CheckBitOffset(TBitOffset);

  // Get bit
  TBool GetBit(TBitValue *, TUint_1, TBitOffset);

  // Set bit to value
  TBool SetBitTo(TUint_1 *, TBitOffset, TBitValue);

  // Core functions
  namespace Freetown
  {
    void GetBit(TBitValue *, TUint_1, TBitOffset);
    void SetBit(TUint_1 *, TBitOffset);
    void ClearBit(TUint_1 *, TBitOffset);
    void ToggleBit(TUint_1 *, TBitOffset);
  }
}

/*
  2024 # #
  2025 # # #
  2026-02-19
*/
