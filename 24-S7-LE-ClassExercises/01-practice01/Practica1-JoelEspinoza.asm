%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp
    
    ; Suma
    mov eax, 18
    mov ebx, 30
    add eax, ebx
    PRINT_STRING "18 + 30 = "
    PRINT_DEC 1, eax
    NEWLINE
    
    ; Resta
    mov eax, 24
    mov ebx, 7
    sub eax, ebx
    PRINT_STRING "24 + 7 = "
    PRINT_DEC 1, eax
    NEWLINE
    
    ; Multiplicación
    mov eax, 15
    mov ebx, 8
    IMUL eax, ebx
    PRINT_STRING "15 x 8 = "
    PRINT_DEC 1, eax
    NEWLINE
    
    mov edx, 0
    mov eax, 24
    mov ecx, 8
    div ecx
        PRINT_STRING "24 / 8 = "
    PRINT_DEC 1, eax
    
    ret