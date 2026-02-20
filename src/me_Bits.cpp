// Bits access. Interface implementation

/*
  Author: Martin Eden
  Last mod.: 2026-02-19
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>
#include <me_WorkMemory.h>

using namespace me_Bits;

/*
  Check bit value: 0 or 1
*/
TBool me_Bits::CheckBitValue(
  TUint_1 BitValue
)
{
  return (BitValue <= 1);
}

/*
  Check bit offset: from 0 to 7
*/
TBool me_Bits::CheckBitOffset(
  TBitOffset BitOffset
)
{
  return (BitOffset <= 7);
}

/*
  Get bit in byte
*/
TBool me_Bits::GetBit(
  TBitValue * BitValue,
  TUint_1 ByteValue,
  TBitOffset BitOffset
)
{
  if (!CheckBitOffset(BitOffset))
    return false;

  Freetown::GetBit(BitValue, ByteValue, Freetown::GetBitMask(BitOffset));

  return true;
}

/*
  Set bit in byte
*/
TBool me_Bits::SetBitTo(
  TUint_1 * ByteValue,
  TUint_1 BitOffset,
  TBitValue BitValue
)
{
  if (!CheckBitOffset(BitOffset))
    return false;

  if (!CheckBitValue(BitValue))
    return false;

  if (BitValue == 1)
    Freetown::SetBit(ByteValue, Freetown::GetBitMask(BitOffset));
  else
    Freetown::ClearBit(ByteValue, Freetown::GetBitMask(BitOffset));

  return true;
}

/*
  Check bit location

  We're checking validity of memory address and bit offset
*/
TBool me_Bits::IsValidLocation(
  TBitLocation Location
)
{
  if (!me_WorkMemory::CheckAddress(Location.Address))
    return false;

  if (!me_Bits::CheckBitOffset(Location.BitOffset))
    return false;

  return true;
}

/*
  Get location
*/
TBitLocation TBit::GetLocation()
{
  return Location;
}

/*
  Set location
*/
TBool TBit::SetLocation(
  TBitLocation Location
)
{
  if (!IsValidLocation(Location))
    return false;

  this->Location = Location;
  BitMask = Freetown::GetBitMask(Location.BitOffset);

  return true;
}

/*
  Get bit (by address and mask)
*/
TBitValue TBit::Get()
{
  return TBitValue((*(TUint_1 *) Location.Address & BitMask) != 0);
}

/*
  Set bit
*/
void TBit::Set()
{
  *(TUint_1 *) Location.Address |= BitMask;
}

/*
  Clear bit
*/
void TBit::Clear()
{
  *(TUint_1 *) Location.Address &= ~BitMask;
}

/*
  Invert/flip/switch/toggle bit
*/
void TBit::Toggle()
{
  *(TUint_1 *) Location.Address ^= BitMask;
}

/*
  Set bit to given value
*/
TBool TBit::SetTo(
  TBitValue BitValue
)
{
  if (!me_Bits::CheckBitValue(BitValue))
    return false;

  if (BitValue == 0)
    Clear();
  else
    Set();

  return true;
}

/*
  2024 # #
  2025 # # #
  2026-02-17
  2026-02-19
*/
