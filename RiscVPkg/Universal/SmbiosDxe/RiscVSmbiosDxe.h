/** @file
  RISC-V SMBIOS Builder DXE module header file.

  Copyright (c) 2019, Hewlett Packard Enterprise Development LP. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _RISC_V_SMBIOS_DXE_H_
#define _RISC_V_SMBIOS_DXE_H_

#include <PiDxe.h>

#include <Protocol/Cpu.h>
#include <Protocol/Smbios.h>

#include <Library/UefiDriverEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DxeServicesTableLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiLib.h>
#include <Library/HobLib.h>

#include <SmbiosProcessorSpecificData.h>
#include <ProcessorSpecificDataHob.h>

#endif

