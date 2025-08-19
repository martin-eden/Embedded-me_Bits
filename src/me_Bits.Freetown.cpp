// Bits access. Core

/*
  Author: Martin Eden
  Last mod.: 2025-08-19
*/

#include "me_Bits.h"

#include <me_BaseTypes.h>

using namespace me_Bits;

/*
  Get bit in byte
*/
void Freetown::GetBit(
  TUint_1 * BitValue,
  TUint_1 ByteValue,
  TUint_1 BitOffset
)
{
  *BitValue = (ByteValue >> BitOffset) & 1;
}

/*
  Set bit to one
*/
void Freetown::SetBit(
  TUint_1 * ByteValue,
  TUint_1 BitOffset
)
{
  *ByteValue = *ByteValue | (1 << BitOffset);
}

/*
  Set bit to zero
*/
void Freetown::ClearBit(
  TUint_1 * ByteValue,
  TUint_1 BitOffset
)
{
  *ByteValue = *ByteValue & (~(1 << BitOffset));
}

/*
  2024-10 # #
  2025-07-29
  2025-08-15
  2025-08-19
*/
