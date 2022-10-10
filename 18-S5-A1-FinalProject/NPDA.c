#include <stdio.h>

char cadena[];

main()
{
	int i,j,k,n;
	printf("Escribe la cadena:\n");
	scanf("%s",&cadena);
	n=0;
	do
	{
		n++;
	}
	while(cadena[n]);
	printf("\n\n%d\n",n);
	
	char pila[n+1];
	pila[0] = 'Z';
	i=0;
	j=1;
	do
	{
		printf("Estamos leyendo el elemento %d: %c con pila %s y borde de pila: %c\n",i,cadena[i],pila,pila[j-1]);
		if(cadena[i] == 'A')
		{
			pila[j] = 'T';
			j++;
		}
		if(cadena[i] == 'C')
		{
			pila[j] = 'G';
			j++;
		}
		if(cadena[i] == 'G')
		{
			pila[j] = 'C';
			j++;
		}
		if(cadena[i] == 'T')
		{
			pila[j] = 'A';
			j++;
		}
		i++;
	}
	while(cadena[i] != '1');
	
	printf("\n");
	i++;
	
	do
	{
		printf("Estamos leyendo el elemento %d: %c con pila %s y borde de pila: %c\n",i,cadena[i],pila,pila[j-1]);
		if((cadena[i] == 'A') && (pila[j-1] == 'A'))
		{
			pila[j-1] = '0';
			j--;
		}
		if((cadena[i] == 'C') && (pila[j-1] == 'C'))
		{
			pila[j-1] = '0';
			j--;
		}
		if((cadena[i] == 'G') && (pila[j-1] == 'G'))
		{
			pila[j-1] = '0';
			j--;
		}
		if((cadena[i] == 'T') && (pila[j-1] == 'T'))
		{
			pila[j-1] = '0';
			j--;
		}
		i++;
		if(pila[j-1] == 'Z')
		{
			printf("Estamos leyendo el elemento %d: %c con pila %s y borde de pila: %c\n",i,cadena[i],pila,pila[j-1]);
			printf("Aceptamos la cadena");
		}
	}
	while((pila[j-1] != 'Z') && (i < n));
}
