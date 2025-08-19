// Bits access

/*
  Author: Martin Eden
  Last mod.: 2025-08-19
*/

#pragma once

#include <me_BaseTypes.h>

/*
  Getting/setting bit in byte

  Common sequence of arguments is

    byte value, bit offset
*/
namespace me_Bits
{
  // Check bit value
  TBool CheckBitValue(
    TUint_1 BitValue
  );

  // Check bit offset
  TBool CheckBitOffset(
    TUint_1 BitOffset
  );

  // Get bit
  TBool GetBit(
    TUint_1 * BitValue,
    TUint_1 ByteValue,
    TUint_1 BitOffset
  );

  // Set bit to value
  TBool SetBitTo(
    TUint_1 * ByteValue,
    TUint_1 BitOffset,
    TUint_1 BitValue
  );

  // Core implementation
  namespace Freetown
  {
    void GetBit(
      TUint_1 * BitValue,
      TUint_1 ByteValue,
      TUint_1 BitOffset
    );

    void SetBit(
      TUint_1 * ByteValue,
      TUint_1 BitOffset
    );

    void ClearBit(
      TUint_1 * ByteValue,
      TUint_1 BitOffset
    );
  }
}

/*
  2024-10-25
  2024-10-26
  2025-07-29
  2025-08-15 Checkers are now exposed in Freetown
  2025-08-19 Core in Freetown, checkers in main, renamed functions
*/
