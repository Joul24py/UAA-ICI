%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    ; Desplazamiento izquierdo
    mov eax, 10110011b
    PRINT_DEC 1, eax
    sal eax, 1
    PRINT_STRING " = "
    PRINT_DEC 1, eax
    NEWLINE
    
    ; Desplazamiento derecho
    mov eax, 11000101b
    PRINT_DEC 1, eax
    sar eax, 1
    PRINT_STRING " = "
    PRINT_DEC 1, eax
    NEWLINE
    
    ; Rotación izquierda
    mov eax, 10101010b
    PRINT_DEC 1, eax
    rol eax, 1
    PRINT_STRING " = "
    PRINT_DEC 1, eax
    NEWLINE
    
    ; Rotación derecha
    mov eax, 11000011b
    PRINT_DEC 1, eax
    ror eax, 1
    PRINT_STRING " = "
    PRINT_DEC 1, eax
    NEWLINE
    ret