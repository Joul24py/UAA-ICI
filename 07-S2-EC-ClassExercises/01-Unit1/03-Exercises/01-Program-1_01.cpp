//Programa 1_01: Implemente un programa de los números de días que tiene cada mes 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int meses[12],x=0;

main()
{
	setlocale(LC_ALL, "");
	
	meses[0]=31;
	meses[1]=28;
	meses[2]=31;
	meses[3]=30;
	meses[4]=31;
	meses[5]=30;
	meses[6]=31;
	meses[7]=31;
	meses[8]=30;
	meses[9]=31;
	meses[10]=30;
	meses[11]=31;
	printf("Inserte un número de mes\n");
	scanf("%d",&x);
	x=x-1;
	printf("La cantidad de días de su mes es: %d\n", meses[x]);
	
	printf("\n\nPresione ENTER para continuar\n");
	getchar();
	
}
