led EQU P1.0
ORG 0000H
	LJMP inicio
	
ORG 0030H
	
	inicio:
	MOV TMOD,#0x20 ;Activamos el modo 2 de ambos timers
	ciclo:
	CPL led
	MOV R0,#250
	
	ciclo1:
	ACALL tim1_delay
	DJNZ R0,ciclo1
	AJMP ciclo
	
	tim1_delay:
	MOV TL1,#54H
	SETB TR1
	JNB TF1,$
	CLR TF1
	CLR TR1	
	RET
	
END