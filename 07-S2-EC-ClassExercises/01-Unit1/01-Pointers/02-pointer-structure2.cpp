#include <stdio.h>

main()
{
	int u1, u2;
	int v=3;
	int *pv;  //Apuntador a un entero
	
	u1=2*(v+5); //Expresión ordinaria
	pv=&v;
	u2=2*(*pv+5); //Expresión equivalente
	
	printf("u1 = %d \n",u1);
	printf("u2 = %d \n",u2);
}

