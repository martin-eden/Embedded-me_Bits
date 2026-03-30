// TBit class implementation

/*
  Author: Martin Eden
  Last mod.: 2026-03-30
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>

using namespace me_Bits;

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
  2026-03-30
*/
