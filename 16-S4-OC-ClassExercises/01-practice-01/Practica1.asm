ORG 0000H
	inicio:
	MOV R2,#00H ;Limpiar el puerto
	MOV P1,R2
	ciclo:
	JB P1.1,enciende_led
	CLR P1.1
	SJMP ciclo
	
	enciende_led:
	SETB P1.0
	ACALL delay
	ACALL delay
	SJMP apaga_led
	
	apaga_led:
	CLR P1.1
	CLR P1.0
	ACALL delay
	ACALL delay
	SJMP enciende_led
	
	delay: ;Retardo de 1.5 segundos				;2 ciclos				= 2
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