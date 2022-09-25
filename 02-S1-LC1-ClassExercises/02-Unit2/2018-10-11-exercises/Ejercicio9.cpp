#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Programa que solicite la edad de 10 personas y que muestre cuántos son mayores y cuántos son menores de edad

int cont=0,e,men=0,may=0;

main()
{
	setlocale(LC_ALL, "");
	
	while(cont<10)
	{
		printf("¿Cuál es tu edad?\n");
		scanf("%d",&e);
		if (e<18)
		{
			men=men+1;
			cont=cont+1;
		}
		else
		{
			may=may+1;
			cont=cont+1;
		}
	}
	printf("\nLa cantidad total de mayores de edad es de %d\n",may);
	printf("La cantidad total de menores de edad es de %d\n",men);
		
	getchar();
}
