// Bits access. Interface implementation

/*
  Author: Martin Eden
  Last mod.: 2026-03-30
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>

using namespace me_Bits;

/*
  Get bit in byte
*/
TBool me_Bits::GetBit(
  TBitValue * BitValue,
  TUint_1 ByteValue,
  TBitOffset BitOffset
)
{
  if (!Freetown::CheckBitOffset(BitOffset))
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
  if (!Freetown::CheckBitOffset(BitOffset))
    return false;

  if (!Freetown::CheckBitValue(BitValue))
    return false;

  if (BitValue == 1)
    Freetown::SetBit(ByteValue, Freetown::GetBitMask(BitOffset));
  else
    Freetown::ClearBit(ByteValue, Freetown::GetBitMask(BitOffset));

  return true;
}

/*
  Init: Set location
*/
TBool TBit::Init(
  TBitLocation Location
)
{
  if (!Freetown::IsValidLocation(Location))
    return false;

  this->Location = Location;
  BitMask = Freetown::GetBitMask(Location.BitOffset);

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
  if (!Freetown::CheckBitValue(BitValue))
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
  2026-03-30
*/
