leds EQU P0
led EQU P0.0
en equ P2.2
rs equ P2.0
rw equ P2.1
datos equ P1
ORG 0000H ;Reset
	LJMP inicio
	
ORG 0003H ;Interrupción externa 0
	;Código para la interrupción
	CPL led
	
	derecha:
	ACALL print_INTX
	MOV leds,A
	RR A
	ACALL delay
	CJNE A,#01H,derecha
	LJMP wait
	
	wait:
	MOV leds,A
	ACALL delay
	ACALL delay
	ACALL delay
	ACALL delay
	
	RETI
	
ORG 0030H
	inicio:
	ACALL init_LCD
	ACALL init_config
	MOV A,#01H
	izquierda:
	ACALL print_principal
	MOV leds,A
	RL A
	ACALL delay
	SJMP izquierda
	
	aqui:
	AJMP aqui
	
	print_principal:
	ACALL en_h
	ACALL rs_h
	MOV datos,#50H ;P
	ACALL en_l
	
	ACALL en_h
	ACALL rs_h
	MOV datos,#52H ;R
	ACALL en_l
	
	ACALL en_h
	ACALL rs_h
	MOV datos,#49H ;I
	ACALL en_l
	
	ACALL en_h
	ACALL rs_h
	MOV datos,#4EH ;N
	ACALL en_l
	
	ACALL en_h
	ACALL rs_h
	MOV datos,#43H ;C
	ACALL en_l
	
	ACALL en_h
	ACALL rs_h
	MOV datos,#49H ;I
	ACALL en_l
	
	ACALL en_h
	ACALL rs_h
	MOV datos,#50H ;P
	ACALL en_l
	
	ACALL en_h
	ACALL rs_h
	MOV datos,#41H ;A
	ACALL en_l
	
	ACALL en_h
	ACALL rs_h
	MOV datos,#4CH ;L
	ACALL en_l
	RET
	
	print_INTX:
	ACALL en_h
	ACALL rs_h
	MOV datos,#49H ;I
	ACALL en_l
	
	ACALL en_h
	ACALL rs_h
	MOV datos,#4EH ;N
	ACALL en_l
	
	ACALL en_h
	ACALL rs_h
	MOV datos,#54H ;T
	ACALL en_l
	
	ACALL en_h
	ACALL rs_h
	MOV datos,#30H ;0
	ACALL en_l
	RET
	
	init_config:
	SETB EX0
	SETB EA
	SETB led
	RET
	
	init_LCD:
	ACALL rw_l
	ACALL rs_l
	
	;Comienza la configuración de encendido de la LCD
	ACALL en_h
	MOV A,#38H
	MOV datos,A
	ACALL en_l
	
	ACALL en_h
	MOV A,#38H
	MOV datos,A
	ACALL en_l
	
	ACALL en_h
	MOV A,#38H
	MOV datos,A
	ACALL en_l
	
	ACALL en_h
	MOV A,#38H
	MOV datos,A
	ACALL en_l
	
	;Apaga la pantalla
	ACALL en_h
	MOV A,#08H
	MOV datos,A
	ACALL en_l
	
	;Limpiar pantalla
	ACALL en_h
	MOV A,#01H
	MOV datos,A
	ACALL en_l
	
	;Modo de entrada
	ACALL en_h
	MOV A,#06H
	MOV datos,A
	ACALL en_l
	
	;Encender la pantalla
	ACALL en_h
	MOV A,#0FH
	MOV datos,A
	ACALL en_l
	RET
	
	en_l:
	CLR en
	RET
	
	en_h:
	SETB en
	RET
	
	rs_l:
	CLR rs
	RET
	
	rs_h:
	SETB rs
	RET
	
	rw_l:
	CLR rw
	RET
	
	rw_h:
	SETB rw
	RET
	
	delay: ;Retardo de 0.5 segundos				;2 ciclos				= 2
	MOV R6,#0FAH								;1 ciclo				= 1
	d1:
	MOV R7,#0F9H								;1 ciclo	1*250		= 250
	NOP											;1 ciclo	1*250		= 250
	NOP											;1 ciclo	1*250		= 250
	NOP											;1 ciclo	1*250		= 250
	NOP											;1 ciclo	1*250		= 250
	NOP											;1 ciclo	1*250		= 250
	d2:
	NOP											;1 ciclo	1*250		= 250
	NOP											;1 ciclo	1*250		= 250
	NOP											;1 ciclo	1*250		= 250
	NOP											;1 ciclo	1*250		= 250
	NOP											;1 ciclo	1*250		= 250
	NOP											;1 ciclo	1*250		= 250
	DJNZ R7,d2 ;Decrement Jump if Not Zero		;2 ciclos	2*249*250	= 124500
	DJNZ R6,d1									;2 ciclos	2*250		= 500
	RET											;2 ciclos				= 2
												;total					= 500,005
	
END