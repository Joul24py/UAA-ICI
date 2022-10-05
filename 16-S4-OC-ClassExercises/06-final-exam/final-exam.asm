ORG 0000H
	LJMP inicio
	
ORG 0023H
	ACALL recibir_datos
	ACALL transmitir_datos
	CLR RI
	CLR TI
	RETI
	
ORG 0030H
	inicio:
	MOV R0,#1EH
	MOV R1,#00H
	inicio2:
	ACALL init_int
	ACALL init_uart
	aqui:
	CJNE R7,#01H,aqui1
	AJMP inicio2
	aqui1:
	CJNE R0,#00H,aqui
	CLR EA
	CLR ES
	MOV SBUF,#30H
	AJMP ProgramaBubbleSort
	
	;Frankenstein: Bubble Sort---------------------------------------------------------------------------------------------------
	
	ProgramaBubbleSort:
	
	;Comienza el método------------------------------------------------------------------
	;Fase 1 (Ordenar los 8 elementos más altos de la pila)-------------------------------
	POP 0
	POP 1
	POP 2
	POP 3
	POP 4
	POP 5
	POP 6
	POP 7
	ACALL BubbleSort
	
	;Fase 2 (Mover los dos números más pequeños (ubicados en R0 y R1) a la pila)---------
	MOV A,R0
	POP 0
	MOV B,R0
	MOV R0,A
	MOV A,R1
	POP 1
	PUSH 0
	MOV R0,A
	PUSH 0
	MOV R0,B
	
	;Fase 3 (Ordenar nuevamente los registros 0 a 7)-------------------------------------
	ACALL BubbleSort
	
	;Fase 4 (Introducir los dos números más grandes (ubicados en R6 Y R7) a la pila)-----
	MOV A,R7
	POP 7
	MOV B,R7
	MOV R7,A
	MOV A,R6
	POP 6
	PUSH 7
	MOV R7,A
	PUSH 7
	MOV R7,B
	;Fase 6 (Ordenar nuevamente los registros 0 a 7)-------------------------------------
	ACALL BubbleSort
	
	;Fase 7 (Introducimos todos los valores a la pila)-----------------------------------
	PUSH 7
	PUSH 6
	PUSH 5
	PUSH 4
	PUSH 3
	PUSH 2
	PUSH 1
	PUSH 0
	;Fin
	
	;Fase 8 (Verificamos el orden)-------------------------------------------------------
	POP 7
	MOV SBUF,R7
	MOV SBUF,#10
	POP 7
	MOV SBUF,R7
	MOV SBUF,#10
	POP 7
	MOV SBUF,R7
	MOV SBUF,#10
	POP 7
	MOV SBUF,R7
	MOV SBUF,#10
	POP 7
	MOV SBUF,R7
	MOV SBUF,#10
	POP 7
	MOV SBUF,R7
	MOV SBUF,#10
	POP 7
	MOV SBUF,R7
	MOV SBUF,#10
	POP 7
	MOV SBUF,R7
	MOV SBUF,#10
	POP 7
	MOV SBUF,R7
	MOV SBUF,#10
	POP 7
	MOV SBUF,R7
	MOV SBUF,#10
	AJMP Final
	;M�todo de la Burbuja----------------------------------------------------------------
	BubbleSort:
	Compare1:
	MOV A,R0
	MOV B,R1
	Compare1_1:
	DEC R0
	DEC R1
	CJNE R0,#00H,Compare1_2
	MOV R0,A
	MOV R1,B
	AJMP Compare2
	Compare1_2:
	CJNE R1,#00H,Compare1_1
	MOV R0,B
	MOV R1,A
	AJMP Compare1 ;Este siempre debe ser Compare1
	
	Compare2:
	MOV A,R1
	MOV B,R2
	Compare2_1:
	DEC R1
	DEC R2
	CJNE R1,#00H,Compare2_2
	MOV R1,A
	MOV R2,B
	AJMP Compare3
	Compare2_2:
	CJNE R2,#00H,Compare2_1
	MOV R1,B
	MOV R2,A
	AJMP Compare1 ;Este siempre debe ser Compare1
	
	Compare3:
	MOV A,R2
	MOV B,R3
	Compare3_1:
	DEC R2
	DEC R3
	CJNE R2,#00H,Compare3_2
	MOV R2,A
	MOV R3,B
	AJMP Compare4
	Compare3_2:
	CJNE R3,#00H,Compare3_1
	MOV R2,B
	MOV R3,A
	AJMP Compare1 ;Este siempre debe ser Compare1
	
	Compare4:
	MOV A,R3
	MOV B,R4
	Compare4_1:
	DEC R3
	DEC R4
	CJNE R3,#00H,Compare4_2
	MOV R3,A
	MOV R4,B
	AJMP Compare5
	Compare4_2:
	CJNE R4,#00H,Compare4_1
	MOV R3,B
	MOV R4,A
	AJMP Compare1 ;Este siempre debe ser Compare1
	
	Compare5:
	MOV A,R4
	MOV B,R5
	Compare5_1:
	DEC R4
	DEC R5
	CJNE R4,#00H,Compare5_2
	MOV R4,A
	MOV R5,B
	AJMP Compare6
	Compare5_2:
	CJNE R5,#00H,Compare5_1
	MOV R4,B
	MOV R5,A
	AJMP Compare1 ;Este siempre debe ser Compare1
	
	Compare6:
	MOV A,R5
	MOV B,R6
	Compare6_1:
	DEC R5
	DEC R6
	CJNE R5,#00H,Compare6_2
	MOV R5,A
	MOV R6,B
	AJMP Compare7
	Compare6_2:
	CJNE R6,#00H,Compare6_1
	MOV R5,B
	MOV R6,A
	AJMP Compare1 ;Este siempre debe ser Compare1
	
	Compare7:
	MOV A,R6
	MOV B,R7
	Compare7_1:
	DEC R6
	DEC R7
	CJNE R6,#00H,Compare7_2
	MOV R6,A
	MOV R7,B
	AJMP EndSort
	Compare7_2:
	CJNE R7,#00H,Compare7_1
	MOV R6,B
	MOV R7,A
	AJMP Compare1 ;Este siempre debe ser Compare1
	
	EndSort:
	RET
	
	Final:
	AJMP Final
	
	;Frankenstein: Bubble Sort---------------------------------------------------------------------------------------------------
	
	init_int:
	SETB EA
	SETB ES
	RET
	
	init_uart:
	MOV TMOD,#20H
	MOV TH1,#0FDH
	MOV SCON,#50H
	SETB TR1
	RET
	
	MOV SBUF,#01H
	recibir_datos:
	JNB RI,$ ;Indica que el buffer de interrupci�n est� lleno
	CLR RI ;Limpia el buffer de interrupci�n
	MOV A,SBUF ;Lee el caracter
	MOV P0,SBUF
	DEC R0
	
	Comprobar1:
	CJNE R1,#00H,Comprobar2
	;Significa que es el primer dato
	MOV B,#0AH
	MOV R4,#30H
	MOV R3,A
	Ajuste1:
	DEC A
	DJNZ R4,Ajuste1
	MUL AB
	MOV R2,A
	INC R1
	MOV A,R3
	RET
	Comprobar2:
	CJNE R1,#01H,FinalComprobar
	;Significa que es el segundo dato
	MOV R4,#30H
	MOV R3,A
	Ajuste2:
	DEC A
	DJNZ R4,Ajuste2
	ADD A,R2
	MOV R2,A
	PUSH 2
	MOV R1,#00H
	MOV A,R3
	FinalComprobar:
	RET
	
	transmitir_datos:
	MOV SBUF,A ;Regresa al buffer la lectura anterior
	JNB TI,$ ;Verifica que el buffer de transmisi�n est� vac�o
	CLR TI ;Limpia el buffer de transmisi�n
	CJNE R1,#00H,fin ; Si A no es igual a 13 (o sea a Enter) salta a fin
	MOV SBUF,#10 ;Salto de l�nea despu�s de Enter
	JNB TI,$ ;Verifica que el buffer de transmisi�n est� vac�o
	CLR TI ;Limpia el buffer de transmisi�n
	RET
	fin:
	INC R7
	RET
END