// Bits access. Core

/*
  Author: Martin Eden
  Last mod.: 2026-02-19
*/

#include <me_Bits.h>

#include <me_BaseTypes.h>

using namespace me_Bits;

/*
  Get bit in byte
*/
void Freetown::GetBit(
  TBitValue * BitValue,
  TUint_1 ByteValue,
  TBitOffset BitOffset
)
{
  *BitValue = (ByteValue >> BitOffset) & 1;
}

/*
  Set bit to one
*/
void Freetown::SetBit(
  TUint_1 * ByteValue,
  TBitOffset BitOffset
)
{
  *ByteValue = *ByteValue | (1 << BitOffset);
}

/*
  Set bit to zero
*/
void Freetown::ClearBit(
  TUint_1 * ByteValue,
  TBitOffset BitOffset
)
{
  *ByteValue = *ByteValue & (~(1 << BitOffset));
}

/*
  Toggle bit
*/
void Freetown::ToggleBit(
  TUint_1 * ByteValue,
  TBitOffset BitOffset
)
{
  *ByteValue = *ByteValue ^ (1 << BitOffset);
}

/*
  2024 # #
  2025 # # #
  2026-02-19
*/
