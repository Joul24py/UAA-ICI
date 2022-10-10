%include "io64.inc"

cpu x86-64 ;Elementos únicos de la arquitectura

section .bss ;Declarar variables no inicializadas
var resd 4 ;Uso de 4 bytes

section .data ;Declarar variables inicializadas
cons equ 3 ;Constante
var2 dw 128 ;Variable
cadena db `á é í ó ú` ;Cadena UTF
vector db 18,12,30 ;Vector de 3 valores (byte)
vector2 times 5 dw 0 ;Vector de 5 palabras como 0
var3 dw 10

section .text
global CMAIN
CMAIN:
    mov rbp, rsp
    ;Uso de var
    GET_STRING var, 11
    PRINT_STRING var
    
    ;Uso de var2
    mov eax, [var2]
    NEWLINE
    PRINT_DEC 1, eax
    
    ;Uso de cons y cadena
    add ebx, cons
    NEWLINE
    PRINT_DEC 1, ebx
    PRINT_STRING cadena
    
    ;Uso de vector
    NEWLINE
    mov ecx, vector
    PRINT_DEC 1, ecx
    
    ;Uso de var3
    mov ax, [var3]
    NEWLINE
    control:
    PRINT_DEC 1, ax
    NEWLINE
    dec ax
    jnz control
    ret