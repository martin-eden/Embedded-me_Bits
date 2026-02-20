// Bits access. Core

/*
  Author: Martin Eden
  Last mod.: 2026-02-20
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>

using namespace me_Bits;

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
void Freetown::GetBit(
  TBitValue * BitValue,
  TUint_1 ByteValue,
  TUint_1 BitMask
)
{
  *BitValue = TBitValue((ByteValue & BitMask) != 0);
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
