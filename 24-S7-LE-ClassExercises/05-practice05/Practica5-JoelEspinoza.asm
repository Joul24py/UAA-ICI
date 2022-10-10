%include "io64.inc"

section .data
msg db 'texto',0

section .text
global CMAIN
CMAIN:
    xor rax, rax
    
    GET_UDEC 4, eax ; Macro GET_UDEC
    PRINT_UDEC 4, eax ; Macro PRINT_UDEC
    NEWLINE ; Macro NEWLINE
    
    GET_DEC 4, ebx ; Macro GET_DEC
    PRINT_DEC 4, ebx ; Macro PRINT_DEC
    NEWLINE ; Macro NEWLINE
    
    GET_STRING msg, 9 ; Macro GET_STRING
    PRINT_STRING msg ; Macro PRINT_STRING
    NEWLINE ; Macro NEWLINE
    
    GET_CHAR r8B ; Macro GET_CHAR
    PRINT_CHAR R8B ; Macro PRINT_CHAR
    NEWLINE ; Macro NEWLINE

    GET_HEX 1, r9B ; Macro GET_HEX
    PRINT_HEX 1, R9B ; Macro PRINT_HEX
    NEWLINE ; Macro NEWLINE
    
    ret