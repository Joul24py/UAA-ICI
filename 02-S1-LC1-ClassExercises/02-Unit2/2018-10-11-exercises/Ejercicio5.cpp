#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Programa que pida el nombre de 2 personas, su edad e indicar cuál es el mayor de los dos

char n1[10],n2[10];
int e1, e2;

main()
{
	setlocale(LC_ALL, "");
	
	printf("Persona 1: Escribe tu nombre\n");
	scanf("%s",&n1);
	printf("Dame tu edad\n");
	scanf("%d",&e1);
	printf("Persona 2: Escribe tu nombre\n");
	scanf("%s",&n2);
	printf("Dame tu edad\n");
	scanf("%d",&e2);
	if (e1>e2)
	{
		printf("%s es mayor que %s\n",n1,n2);
	}
	else
	{
		if (e2>e1)
		{
			printf("%s es mayor que %s\n",n2,n1);
		}
		else
		{
			printf("Ambos tienen la misma edad\n");
		}
	}
		
	getchar();
}
