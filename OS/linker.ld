ENTRY(kernel_main)

SECTIONS {
    . = 0x1000;    /* Začátek kernelu po bootloaderu */
    .text : {
        *(.text)   /* Zde umístíme kód */
    }
    .data : {
        *(.data)   /* Zde umístíme data */
    }
    .bss : {
        *(.bss)    /* Zde umístíme ne-inicializované proměnné */
    }
}
