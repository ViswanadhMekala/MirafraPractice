/* Simple Linker Script Example */
MEMORY
{
    /* Define available memory regions */
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K
    RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    /* Place code and read-only data in Flash */
    .text : {
        *(.text*)
        *(.rodata*)
    } > FLASH

    /* Place initialized data in RAM (loaded from Flash) */
    .data : {
        *(.data*)
    } > RAM AT > FLASH

    /* Place uninitialized data in RAM */
    .bss : {
        *(.bss*)
        *(COMMON)
    } > RAM
}
