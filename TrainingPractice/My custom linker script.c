// My custom linker script 

ENTRY(_start)

MEMORY{
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 512K
  RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS{
  .text : {
  . = ALIGN(4);
  *(.text)
  *(.rodata)
  . = ALIGN(4);
  } > FLASH
  
  /* Add this to know where to find the source in Flash */
  _sidata = LOADADDR(.data); 
  .data : {
   _sdata = .;
   *(.data)
   . = ALIGN(4); /* Ensure _edata is on a 4-byte boundary */
   _edata = .;
  } > RAM AT > FLASH
  
  .bss : {
  _sbss = .;
  *(.bss)
  *(COMMON)
  _ebss = .;
  } > RAM
}
