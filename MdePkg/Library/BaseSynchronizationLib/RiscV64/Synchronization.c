/** @file
  Implementation of synchronization functions on RISC-V

  Copyright (c) 2016 - 2019, Hewlett Packard Enterprise Development LP. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <Library/DebugLib.h>

UINT32
SyncCompareExchange32 (
  IN volatile UINT32           *Value,
  IN UINT32                    CompareValue,
  IN UINT32                    ExchangeValue
);

UINT64
SyncCompareExchange64 (
  IN volatile UINT64           *Value,
  IN UINT64                    CompareValue,
  IN UINT64                    ExchangeValue
);

UINT32
SyncSyncIncrement32 (
  IN volatile UINT32           *Value
  );

UINT32
SyncSyncDecrement32 (
  IN volatile UINT32           *Value
  );

/**
  Performs an atomic compare exchange operation on a 16-bit
  unsigned integer.

  Performs an atomic compare exchange operation on the 16-bit
  unsigned integer specified by Value.  If Value is equal to
  CompareValue, then Value is set to ExchangeValue and
  CompareValue is returned.  If Value is not equal to
  CompareValue, then Value is returned. The compare exchange
  operation must be performed using MP safe mechanisms.

  @param  Value         A pointer to the 16-bit value for the
                        compare exchange operation.
  @param  CompareValue  16-bit value used in compare operation.
  @param  ExchangeValue 16-bit value used in exchange operation.

  @return The original *Value before exchange.

**/
UINT16
EFIAPI
InternalSyncCompareExchange16 (
  IN      volatile UINT16           *Value,
  IN      UINT16                    CompareValue,
  IN      UINT16                    ExchangeValue
  )
{
  DEBUG((DEBUG_ERROR, "%a:RISC-V does not support 16-bit AMO operation\n", __FUNCTION__));
  ASSERT (FALSE);
  return 0;
}

/**
  Performs an atomic compare exchange operation on a 32-bit
  unsigned integer.

  Performs an atomic compare exchange operation on the 32-bit
  unsigned integer specified by Value.  If Value is equal to
  CompareValue, then Value is set to ExchangeValue and
  CompareValue is returned.  If Value is not equal to
  CompareValue, then Value is returned. The compare exchange
  operation must be performed using MP safe mechanisms.

  @param  Value         A pointer to the 32-bit value for the
                        compare exchange operation.
  @param  CompareValue  32-bit value used in compare operation.
  @param  ExchangeValue 32-bit value used in exchange operation.

  @return The original *Value before exchange.

**/
UINT32
EFIAPI
InternalSyncCompareExchange32 (
  IN      volatile UINT32           *Value,
  IN      UINT32                    CompareValue,
  IN      UINT32                    ExchangeValue
  )
{

  if (((UINTN)Value % sizeof (UINT32)) != 0) {
      DEBUG((DEBUG_ERROR, "%a:Value pointer must aligned at natural address.\n", __FUNCTION__));
      ASSERT (FALSE);
  }
  return SyncCompareExchange32(Value, CompareValue, ExchangeValue);
}

/**
  Performs an atomic compare exchange operation on a 64-bit unsigned integer.

  Performs an atomic compare exchange operation on the 64-bit unsigned integer specified
  by Value.  If Value is equal to CompareValue, then Value is set to ExchangeValue and
  CompareValue is returned.  If Value is not equal to CompareValue, then Value is returned.
  The compare exchange operation must be performed using MP safe mechanisms.

  @param  Value         A pointer to the 64-bit value for the compare exchange
                        operation.
  @param  CompareValue  64-bit value used in compare operation.
  @param  ExchangeValue 64-bit value used in exchange operation.

  @return The original *Value before exchange.

**/
UINT64
EFIAPI
InternalSyncCompareExchange64 (
  IN      volatile UINT64           *Value,
  IN      UINT64                    CompareValue,
  IN      UINT64                    ExchangeValue
  )
{
  if (((UINTN)Value % sizeof (UINT64)) != 0) {
      DEBUG((DEBUG_ERROR, "%a:Value pointer must aligned at natural address.\n", __FUNCTION__));
      ASSERT (FALSE);
  }
  return SyncCompareExchange64 (Value, CompareValue, ExchangeValue);
}

/**
  Performs an atomic increment of an 32-bit unsigned integer.

  Performs an atomic increment of the 32-bit unsigned integer specified by
  Value and returns the incremented value. The increment operation must be
  performed using MP safe mechanisms. The state of the return value is not
  guaranteed to be MP safe.

  @param  Value A pointer to the 32-bit value to increment.

  @return The incremented value.

**/
UINT32
EFIAPI
InternalSyncIncrement (
  IN volatile UINT32 *Value
  )
{
  if (((UINTN)Value % sizeof (UINT32)) != 0) {
      DEBUG((DEBUG_ERROR, "%a:Value pointer must aligned at natural address.\n", __FUNCTION__));
      ASSERT (FALSE);
  }
  return SyncSyncIncrement32 (Value);
}

/**
  Performs an atomic decrement of an 32-bit unsigned integer.

  Performs an atomic decrement of the 32-bit unsigned integer specified by
  Value and returns the decrement value. The decrement operation must be
  performed using MP safe mechanisms. The state of the return value is not
  guaranteed to be MP safe.

  @param  Value A pointer to the 32-bit value to decrement.

  @return The decrement value.

**/
UINT32
EFIAPI
InternalSyncDecrement (
  IN volatile UINT32 *Value
  )
{
  if (((UINTN)Value % sizeof (UINT32)) != 0) {
      DEBUG((DEBUG_ERROR, "%a:Value pointer must aligned at natural address.\n", __FUNCTION__));
      ASSERT (FALSE);
  }
  return SyncSyncDecrement32 (Value);
}
