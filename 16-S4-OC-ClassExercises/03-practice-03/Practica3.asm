en equ P2.2
rs equ P2.0
rw equ P2.1
datos equ P0
ORG 0000H
	
	inicio:
	ACALL iniciar_lcd
	MOV P1,#11111110B
	MOV R1,P1
	CJNE R1,#11111110B,numero
	MOV P1,#11111101B
	MOV R1,P1
	CJNE R1,#11111101B,numero
	MOV P1,#11111011B
	MOV R1,P1
	CJNE R1,#11111011B,numero
	MOV P1,#11110111B
	MOV R1,P1
	CJNE R1,#11110111B,numero
	SJMP inicio
	
	mostrar_lcd:
	;Regreso a casa
	ACALL en_h
	MOV A,#02H
	MOV datos,A
	ACALL en_l
	
	numero:
	MOV P3,P1
	JNB P3.0,F1
	JNB P3.1,F2
	JNB P3.2,F3
	JNB P3.3,F4
	
	continue:
	MOV DPTR,#tabla
	MOVC A,@A+DPTR
	ACALL en_h
	ACALL rs_h
	MOV datos,A
	ACALL en_l
	ACALL delay
	ACALL delay
	SJMP inicio
	
	F1:
	MOV A,#00H
	ACALL compare
	
	F2:
	MOV A,#04H
	ACALL compare
	
	F3:
	MOV A,#08H
	ACALL compare
	
	F4:
	MOV A,#0CH
	ACALL compare
	
	compare:
	MOV P3,R1
	JNB P3.4,C1
	JNB P3.5,C2
	JNB P3.6,C3
	JNB P3.7,C4
	RET
	
	C1:
	ADD A,#00H
	SJMP continue
	
	C2:
	ADD A,#01H
	SJMP continue
	
	C3:
	ADD A,#02H
	SJMP continue
	
	C4:
	ADD A,#03H
	SJMP continue
	
	iniciar_lcd:
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
	ACALL delay
	RET
	
	en_h:
	SETB en
	ACALL delay
	RET
	
	rs_l:
	CLR rs
	ACALL delay
	RET
	
	rs_h:
	SETB rs
	ACALL delay
	RET
	
	rw_l:
	CLR rw
	ACALL delay
	RET
	
	rw_h:
	SETB rw
	ACALL delay
	RET
	
	delay:
	MOV R6,#65H		;1
	d1:
	MOV R7,#49H		;101
	d2:
	DJNZ R7,d2		;2*101*73
	DJNZ R6,d1		;2*101
	RET				;15,052
	
	tabla:
	DB 37H ;7
	DB 38H ;8
	DB 39H ;9
	DB 41H ;A
	
	DB 34H ;4
	DB 35H ;5
	DB 36H ;6
	DB 42H ;B
	
	DB 31H ;1
	DB 32H ;2
	DB 33H ;3
	DB 43H ;C
		
	DB 46H ;F!
	DB 30H ;0
	DB 45H ;E!
	DB 44H ;D!
	
END