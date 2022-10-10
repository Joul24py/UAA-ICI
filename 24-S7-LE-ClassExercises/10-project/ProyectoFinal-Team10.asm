%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    mov cx,1
    PRINT_STRING "Hola, ingrese un numero: "
    GET_DEC 2,ax
    NEWLINE
    PRINT_DEC 2,ax
    NEWLINE
    PRINT_STRING "Su valor en binario es: 1"
    JMP binario
    
    binario:
    cmp ax,1
    jz termino
    jnz division

    
    division:
    mov bx,2
    mov dx,0
    div bx
    ;NEWLINE
    ;PRINT_DEC 2,dx
    ;NEWLINE
    ;PRINT_DEC 2,ax
    push dx
    inc cx
    JMP binario
    
    termino:
    cmp cx,1
    jnz sacar
    jz fin
    
    sacar:
    pop ax
    PRINT_DEC 2,ax
    dec cx
    jmp termino
    
    fin:
    NEWLINE
    ret