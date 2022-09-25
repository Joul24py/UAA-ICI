/*
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Estructuras Computacionales Avanzadas
3° "A"

Algoritmo de Combinaciones Binarias

Profesor: Julio César Ponce Gallegos

Alumno: Espinoza Sánchez Joel Alejandro

Aguascalientes, Ags. 26 de agosto de 2019
*/
//Las librerías-------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>

//Algoritmo funcional para 0 <= n <= 16
main()
{
	int n;
	scanf("%d",&n);
	int n2=pow(2,n),c1=0,c2=0,cont,valid,cont1,cont2=0,cont3;
	char tabla[n][n2];
	
	cont=n;
	//Llena la matriz de 1 y 0 según la columna-----------------------------------------------------------------
	do
	{
		cont1=0;
		do
		{
			cont3=pow(2,cont);
			valid=cont1%cont3;
			if(valid<pow(2,cont-1))
			{
				tabla[cont2][cont1]='0';
			}
			else
			{
				tabla[cont2][cont1]='1';
			}
			cont1=cont1+1;
		}
		while(cont1<n2);
		cont--;
		cont2++;
	}
	while(cont>0);
	
	c1=0;
	c2=0;
	//Imprime la matriz-----------------------------------------------------------------------------------------
	do
	{
		do
		{
			printf("%c ",tabla[c1][c2]);
			c1++;
		}
		while(c1<n);
		printf("\n");
		c1=0;
		c2++;
	}
	while(c2<n2);
	
	getchar();
}
