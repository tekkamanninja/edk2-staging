This branch "RISC-V-V2" is used to contribute RISC-V architecture to EDK2. Compare to "RISC-V" branch on edk2-staging, this branch is based on edk2/master@37eef910.

The branch owner:
Abner Chang < abner.chang@hpe.com >

## Feature Introduction
```
RISC-V is a new ISA which was designed to support computer architecture research and education. But now it becomes
a standard open architecture for industry implementations. RISC-V edk2 project is to create a new processor binding
in UEFI spec and to have RISC-V edk2 implementation. The goal is to have RISC-V edk2 port as the firmware reference
for RISC-V platforms. Also, this proves the UEFI spec and edk2 implementation are flexible and well deisgned for
adopting any processor architecture.
```
#### Related Modules
The following modules are related to edk2 RISC-V port:
```
RiscVPkg     - RISC-V processor package. This package provides RISC-V processor related protocols/libraries accroding
               to UEFI specification and edk2 implementations.
```
