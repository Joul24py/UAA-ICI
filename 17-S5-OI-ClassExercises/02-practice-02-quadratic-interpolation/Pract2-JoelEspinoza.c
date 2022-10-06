/*
    Universidad Autónoma de Aguascalientes

		  Centro de Ciencias Básicas
  Departamento de Ciencias de la Computación
		   Optimización Inteligente

					5° "A"

   Práctica 2: Método de Interpolación Cuadrática

		  Doctora Aurora Torres Soto

   Alumno: Joel Alejandro Espinoza Sánchez

  Fecha de Entrega: 28 de septiembre del 2020

Descripción:
*/
//Cargamos las librerías
#include <stdio.h>
#include <locale.h>
#include <math.h>

//Declaramos las funciones del programa
float f(float x);

//Declaramos la función principal
main()
{
	setlocale(LC_ALL,"");
	
	//Declaramos las variables que usaremos
	int i,j,u;
	float ea,es,x0,x1,x2,x3ant=0,x3sig=0;
	
	printf("=========================== MÉTODO DE INTERPOLACIÓN CUADRADA ===========================\n");
	printf("\n");
	do
	{
		//Pedimos x0, x1, x2, el número máximo de iteraciones y la tolerancia de error
		printf("--------------------------------\n");
		printf("Otorgue x0: ");
		scanf("%f",&x0);
		printf("--------------------------------\n");
		printf("Otorgue x1: ");
		scanf("%f",&x1);
		printf("--------------------------------\n");
		printf("Otorgue x2: ");
		scanf("%f",&x2);
		printf("--------------------------------\n");
		printf("Otorgue el número máximo de iteraciones: ");
		scanf("%d",&i);
		printf("--------------------------------\n");
		printf("Otorgue la tolerancia de error: ");
		scanf("%f",&es);
		printf("--------------------------------\n\n");
		
		//Comienza la tabla de valores
		printf("===============================================================================================================================================\n");
		printf("| i |   x0    |   x1    |  x2   |   x3    |       |  f(x0)  |  f(x1)  | f(x2) |  f(x3)  |       |    ea    |    es    |\n");
		printf("| 0 |  %.3f  |  %.3f  |  %.3f  |   ---   |       |  %.3f  |  %.3f  |  %.3f  |   ---   |       |   ---   |  %.3f  |\n",x0,x1,x2,f(x0),f(x1),f(x2),es);
		
		j = 0;
		//Comienzan las iteraciones
		do
		{
			x3ant = x3sig;
			x3sig = (((f(x0))*((pow(x1,2)) - (pow(x2,2)))) + ((f(x1))*((pow(x2,2)) - (pow(x0,2)))) + ((f(x2)) * ((pow(x0,2)) - (pow(x1,2)))))/((2*(f(x0))*(x1 - x2)) + (2*(f(x1))*(x2 - x0)) + (2*(f(x2))*(x0 - x1)));
			
			ea = 100*fabs((x3sig - x3ant)/(x3sig));
			
			printf("| %d |  %.3f  |  %.3f  |  %.3f  |  %.3f  |       |  %.3f  |  %.3f  |  %.3f  |  %.3f  |       |  %.3f  |  %.3f  |\n",j+1,x0,x1,x2,x3sig,f(x0),f(x1),f(x2),f(x3sig),ea,es);
			
			//Se tomarán caminos según se haya registrado el valor del actual x3
			if(x1 < x3sig && x3sig < x2)
			{
				x2 = x1;
				x1 = x3sig;
			}
			if(x0 < x3sig && x3sig < x1)
			{
				x0 = x1;
				x1 = x3sig;
			}
			
			j++;
		}
		while(j < i && es < ea);
		
		//Resultado final
		printf("===============================================================================================================================================\n\n");
		printf("El programa ha tomado %d iteraciones en encontrar un extremo en x = %.3f el cual equivale a f(x) = %.3f con un error de %0.3f\n\n\n",j,x3sig,f(x3sig),ea);
		
		//Opción para repetir el procedimiento
		printf("¿Desea repetir el procedimiento?\n");
		printf("1. Sí\n");
		printf("2. No\n");
		scanf("%d",&u);
	}
	while(u == 1);
	
	getchar();
}

float f(float x)
{
	return (2*(sin(x))) - (x*x/2);
}
