#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int cont=0,T;

main()
{
	setlocale(LC_ALL, "");
	
	//Registro de calificaciones
	printf("¿Cuántas calificaciones quieres?\n");
	scanf("%d",&T);
	
	int cal[T];
	
	while (cont<T)
	{
		printf("\nREGISTRO: Calificación %d\n",cont+1);
		scanf("%d",&cal[cont]);
		cont=cont+1;
	}
	printf("\nLas calificaciones registradas son las siguientes: ");
	cont=0;
	
	while (cont<T)
	{
		printf("\nCalificación %d: ",cont+1);
		printf("%d",cal[cont]);
		cont=cont+1;
	}
	
	//Comparar qué calificación es la mayor
	int con1=0,con2=1,marc=T;
	while(con1<T)
	{
		if(cal[con1]>cal[con2])
		{
			marc=marc-1;
			con1=con1+1;
			con2=con2+1;
		}
		else
		{
			con1=con1+1;
			con2=con2+1;
		}
		if(marc=1)
		{
			printf("\n\nLa calificación más alta es %d",cal[con1-1]);
			break;
		}
	}
}
