This branch is used to contribute RISC-V architecture to EDK2

The branch owner:<br>
Abner Chang < abner.chang@hpe.com > <br>
Gilbert Chen < gilbert.chen@hpe.com >

## RISC-V EDK2 Port Introduction
RISC-V is an open ISA which was designed to support research and education of computer architecture, but now it becomes
a standard open Instruction Set Architecture for industry implementations. The RISC-V edk2 project is to create a new processor binding in UEFI spec and have the RISC-V edk2 implementation. The goal is to have RISC-V edk2 port as the firmware reference
for RISC-V platforms.

This branch (RISC-V-V2) on edk2-staging is RISC-V edk2 port with RISC-V OpenSbi (https://github.com/riscv/opensbi) library integrated. RiscVPkg provides the generic and common modules of RISC-V prcessor. The first edk2 RISC-V platform is SiFive U500 FPGA whcih is maintained in U500Pkg under Platform/RiscV/SiFive in edk2-platform repository.

## RISC-V EDK2 Package
```
RiscVPkg     - RISC-V processor package. This package provides RISC-V processor related protocols/libraries accroding
               to UEFI specification and edk2 implementations.
```
## Toolchain of RISC-V EDK2 port
To build edk2 RISC-V platform requires GCC RISC-V toolchain, refer to https://github.com/riscv/riscv-gnu-toolchain for the details. The commit ID 64879b24 of riscv-gnu-toolchain repository is verified to build RISC-V edk2 platform and boot to EFI SHELL successfully. You have to clone the toolchain from above link and check out commit:64879b24 for building RISC-V edk2 port. The commit later than 64879b24 causes system hangs at the PEI phase to DXE phase transition. We are still figuring out the root cause.

## EDK2 Build Target
"RISCV64" ARCH is the RISC-V architecture which currently supported and verified. The verified RISC-V toolchain is https://github.com/riscv/riscv-gnu-toolchain @64879b24 as mentioned above, toolchain tag is "GCC5" which is declared in tools_def.txt.<br>
Below is the edk2 build options for building RISC-V RV64 platform, <br>
```
build -a RISCV64 -p Platform/{Vendor}/{Platform}/{Platform}.dsc -t GCC5
```
For example, <br>
```
build -a RISCV64 -p Platform/SiFive/U500/U500.dsc -t GCC5
```

Make sure RISC-V toolchain is built succesfully and the toolchain binaries are generated in somewhere you specified when building toolchain. 'GCC5_RISCV64_PREFIX' is the cross compilation prefix to toolchain binraries. <br>
For example, set 'GCC5_RISCV64_PREFIX' to '~/RiscVToolchain/riscv64-unknown-elf-' before you build RISC-V edk2 port.
