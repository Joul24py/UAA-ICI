%include "io64.inc"

section .text
global CMAIN
CMAIN:
    xor rax, rax
    
    ; Enmascaramiento AND
    mov rax, 1110b
    mov rbx, 1011b ; Apagaremos el segundo bit (contando de izquierda a derecha)
    PRINT_STRING "rax antes del enmascaramiento"
    NEWLINE
    PRINT_DEC 1, rax
    NEWLINE
    and rax, rbx
    PRINT_STRING "rax despues del enmascaramiento"
    NEWLINE
    PRINT_DEC 1, rax
    NEWLINE
    NEWLINE
    
    ; Enmascaramiento OR
    mov rax, 1000b
    mov rbx, 0010b ; Encenderemos el tercer bit (contando de izquierda a derecha)
    PRINT_STRING "rax antes del enmascaramiento"
    NEWLINE
    PRINT_DEC 1, rax
    NEWLINE
    or rax, rbx
    PRINT_STRING "rax despues del enmascaramiento"
    NEWLINE
    PRINT_DEC 1, rax
    NEWLINE
    
    ret