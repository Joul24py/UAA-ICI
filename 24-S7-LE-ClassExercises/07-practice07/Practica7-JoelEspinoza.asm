%include "io64.inc"

section .data
    val: dq 3.1416
    ten: dd 10

section .bss
    leftdigits: resd 1
    rightdigits: resb 100
    temp: resd 1
    control_word: resw 1

section .text
global CMAIN
CMAIN:
    mov ebp, esp ; Correct debugging
    
    fld qword[val]
    ;fsqrt
    
    ; Modificar modo de redondeo
    fstcw [control_word]
    mov ax, [control_word]
    or ah, 0b00001100 ; Modo de redondeo: Truncar
    mov [temp], ax
    fldcw [temp] ; Cargar nuevo modo de redondeo
    
    fist dword [leftdigits] ; Guardar parte entera
    fisub dword [leftdigits] ; Limpiar parte entera
    
    ; Cargar 10 y mover a st(1)
    fild dword [ten]
    fxch
    
    ; Isolatear dígitos de la parte fraccionaria y guardarlos ASCII
    mov edi, rightdigits ; Apuntador al buffer ASCIIZ
    .get_fractional:
    fmul st0, st1 ; On dígito decimal a entero
    fist dword [temp] ; Guardar dígito
    fisub dword [temp] ; Limpia parte entera
    mov al, byte [temp] ; Carga dígito
    or al, 0x30 ; Convierte a ASCII
    mov byte [edi], al ; Guarda en rightdigits
    add edi, 1 ; Incrementa el apuntador al string
    fxam ; st0 == 0.0?
    fstsw ax
    fwait
    sahf
    jnz .get_fractional ; No: Itera
    mov byte [edi], 0 ; Multi-termination para ASCIIZ
    
    ; Limpia FPU
    ffree st0 ; Vacía st(0)
    ffree st1 ; Vacía st(1)
    fldcw [control_word] ; Restaura el modo de redondeo anterior
    
    PRINT_DEC 4, leftdigits
    PRINT_CHAR '.' ; Punto decimal
    PRINT_STRING rightdigits
    
    xor eax, eax
    ret