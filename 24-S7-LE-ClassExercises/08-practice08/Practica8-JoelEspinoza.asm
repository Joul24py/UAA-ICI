%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp ; Correct debugging
    
    PRINT_STRING "Hola. Mensaje antes de la INT 21H"
    int 21h
    PRINT_STRING "Hola. Mensaje después de la INT 21H"
    
    xor eax, eax
    ret