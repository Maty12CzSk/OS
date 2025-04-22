ENTRY(_start)

MEMORY {
    CODE (rx) : ORIGIN = 0x1000, LENGTH = 4M
    DATA (rw) : ORIGIN = 0x200000, LENGTH = 4M
}

SECTIONS {
    .text : {
        *(.text)
    } > CODE

    .data : {
        *(.data)
    } > DATA

    .bss : {
        *(.bss)
    } > DATA
}
