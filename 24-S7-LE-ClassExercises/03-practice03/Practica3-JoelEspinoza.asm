%include "io64.inc"
section .text
global CMAIN
CMAIN:
    mov eax, 0
    mov ebx, 1
    mov cx,4
    PRINT_STRING "JLE"
    ;JLE (Jump short if Less or Equal) de 1 a 10
    xor cx,cx
    loop1:
        add eax, ebx
        NEWLINE
        PRINT_DEC 1, eax
        inc cx ; Incremento de cx
        cmp cx,9 ; Comparación para romper el ciclo
        jle loop1
    NEWLINE
    PRINT_STRING "Fin JLE"