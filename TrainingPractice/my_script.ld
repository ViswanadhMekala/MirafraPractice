ENTRY(main)  /* Defines where the OS should start executing */

SECTIONS
{
    /* Start the program at a standard Linux offset (e.g., 0x400000) */
    . = 0x400000;

    .text : { *(.text) }    /* Executable code */
    .rodata : { *(.rodata) } /* Your "Hello World" string */
    .data : { *(.data) }    /* Global variables */
    .bss : { *(.bss) }      /* Uninitialized variables */
}
