// Bits access. Core

/*
  Author: Martin Eden
  Last mod.: 2026-03-30
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>
#include <me_WorkMemory.h>

using namespace me_Bits;

/*
  Check bit value: 0 or 1
*/
TBool Freetown::CheckBitValue(
  TUint_1 BitValue
)
{
  return (BitValue <= 1);
}

/*
  Check bit offset: from 0 to 7
*/
TBool Freetown::CheckBitOffset(
  TBitOffset BitOffset
)
{
  return (BitOffset <= 7);
}

/*
  Check bit location

  We're checking validity of memory address and bit offset
*/
TBool Freetown::IsValidLocation(
  TBitLocation Location
)
{
  if (!me_WorkMemory::Freetown::CheckAddress(Location.Address))
    return false;

  if (!Freetown::CheckBitOffset(Location.BitOffset))
    return false;

  return true;
}

/*
  Get bit's mask
*/
TUint_1 Freetown::GetBitMask(
  TBitOffset BitOffset
)
{
  return (1 << BitOffset);
}

/*
  Get bit in byte
*/
TBitValue Freetown::GetBit(
  TUint_1 * ByteValue,
  TUint_1 BitMask
)
{
  return TBitValue((*ByteValue & BitMask) != 0);
}

/*
  Set bit to one
*/
void Freetown::SetBit(
  TUint_1 * ByteValue,
  TUint_1 BitMask
)
{
  *ByteValue |= BitMask;
}

/*
  Set bit to zero
*/
void Freetown::ClearBit(
  TUint_1 * ByteValue,
  TUint_1 BitMask
)
{
  *ByteValue &= ~BitMask;
}

/*
  Toggle bit
*/
void Freetown::ToggleBit(
  TUint_1 * ByteValue,
  TUint_1 BitMask
)
{
  *ByteValue ^= BitMask;
}

/*
  2024 # #
  2025 # # #
  2026-02-19
  2026-02-20
*/
