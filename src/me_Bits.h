// Getting/setting bits

/*
  Author: Martin Eden
  Last mod.: 2026-03-30
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_Bits
{
  // Bit value: 0/1
  typedef TUint_1 TBitValue;

  // Bit offset: 0..7
  typedef TUint_1 TBitOffset;

  // Get bit
  TBool GetBit(TBitValue *, TUint_1 *, TBitOffset);

  // Set bit to value
  TBool SetBitTo(TUint_1 *, TBitOffset, TBitValue);

  // Bit location: address and bit offset
  struct TBitLocation
  {
    TAddress Address;
    TBitOffset BitOffset;
  };

  // Bit in memory: implementing operations using mask byte
  class TBit
  {
    public:
      TBool Init(TBitLocation);
      TBitLocation GetLocation();

      TBitValue Get();
      void Set();
      void Clear();
      void Toggle();

      TBool SetTo(TBitValue);

    protected:
      TBitLocation Location;
      TUint_1 BitMask;
  };

  // Core functions
  namespace Freetown
  {
    TBool CheckBitValue(TBitValue);
    TBool CheckBitOffset(TBitOffset);
    TBool IsValidLocation(TBitLocation);

    TUint_1 GetBitMask(TBitOffset);

    TBitValue GetBit(TUint_1 *, TUint_1 BitMask);
    void SetBit(TUint_1 *, TUint_1 BitMask);
    void ClearBit(TUint_1 *, TUint_1 BitMask);
    void ToggleBit(TUint_1 *, TUint_1 BitMask);
  }
}

/*
  2024 # #
  2025 # # #
  2026-02-17
  2026-02-19
  2026-02-20
  2026-03-17
  2026-03-30
*/
