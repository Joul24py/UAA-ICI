/*
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Estructuras Computacionales Avanzadas
3° "A"

Algoritmo de Permutaciones

Profesor: Julio César Ponce Gallegos

Alumno: Espinoza Sánchez Joel Alejandro

Aguascalientes, Ags. 3 de septiembre de 2019
*/
//Las librerías-------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

void Permutaciones(char cadena[], int l);
main()
{
	int n=0;
	scanf("%d",&n);
	char cad[n];
	int c=0;
	while(n>0)
	{
		cad[c]=n+48;
		c=c+1;
		--n;
	}
	cad[c]=0;
	printf("%s\n",cad);
	printf("Permutaciones posibles\n");
	Permutaciones(cad,0);
}

void Permutaciones(char cadena[], int l)
{
	char cambio;
	int i,j;
	int n=strlen(cadena);
	
	//Evalúa los cambios de la permutación. Permite hacer todas las evaluaciones de los números
	for(i=0;i<n-l;i++)
	{
		if(n-l>2)
		{
			Permutaciones(cadena,l+1);
		}
		else
		{
			printf("%s\n",cadena);
		}
		cambio=cadena[l];
		cadena[l]=cadena[l+i+1];
		cadena[l+i+1]=cambio;
		if(l+i==n-1)
		{
			for(j=l;j<n;j++)
			{
				cadena[j]=cadena[j+1];
			}
			cadena[n]=0;
		}
	}
}
