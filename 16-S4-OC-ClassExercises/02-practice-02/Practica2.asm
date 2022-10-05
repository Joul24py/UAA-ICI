leds equ P0
ORG 0000H
	
	MOV A,#01H
	
	izquierda:
	MOV leds,A
	RLC A
	ACALL delay
	JC derecha
	SJMP izquierda
	
	derecha:
	MOV leds,A
	RRC A
	ACALL delay
	JC izquierda
	SJMP derecha
	
	
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