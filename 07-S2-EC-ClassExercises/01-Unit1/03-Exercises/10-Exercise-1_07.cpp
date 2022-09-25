#include <stdio.h>

int noest=0,cont=0;

struct estructura
{
	int numero;
	int *ap;
};

main()
{
	printf("Elija el número de estructuras que desea tener: \n");
	scanf("%d",&noest);
	
	struct estructura est[noest];
	do
	{
		est[cont].numero=cont;
		est[cont].ap=&est[cont+1].numero;
		cont++;
	}
	while(cont<noest-1);
	est[cont].numero=cont;
	est[cont].ap=NULL;
	
	cont=0;
	do
	{
		printf("Valor del numero de la estructura %d: %d\n",cont+1,est[cont].numero);
		printf("Valor del apuntador de la estructura %d: %d\n",cont+1,est[cont].ap);
		cont++;
	}
	while(cont<noest);
}
