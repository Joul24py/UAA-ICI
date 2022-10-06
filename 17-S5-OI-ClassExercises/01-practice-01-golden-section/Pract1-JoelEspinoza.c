/*
    Universidad Autónoma de Aguascalientes

		  Centro de Ciencias Básicas
  Departamento de Ciencias de la Computación
		   Optimización Inteligente

					5° "A"

   Práctica 1: Método de la Sección Dorada

		  Doctora Aurora Torres Soto

   Alumno: Joel Alejandro Espinoza Sánchez

  Fecha de Entrega: 24 de septiembre del 2020

Descripción:
*/
//Cargamos las librerías
#include <stdio.h>
#include <locale.h>
#include <math.h>

//Declaramos las funciones del programa
float f(float x);
void Maximizar(float xL, float xU, int i, float es);
void Minimizar(float xL, float xU, int i, float es);

//Declaramos la función principal
main()
{
	setlocale(LC_ALL,"");
	
	/*
	Declaramos las variables que usaremos
		i: El número máximo de iteraciones
		es: Valor de la tolerancia de error
		xL: El límite inferior del intervalo
		xU: El límite superior del intervalo
		u: Uso distinto para pedir maximización o minimización
	*/
	int i,u;
	float es,xL,xU;
	
	printf("=========================== MÉTODO DE LA SECCIÓN DORADA ===========================\n");
	do
	{
		printf("\n");
		do
		{
			//Pedimos el límite inferior, el límite superior, el número máximo de iteraciones y la tolerancia de error
			printf("--------------------------------\n");
			printf("Otorgue el límite inferior: ");
			scanf("%f",&xL);
			printf("--------------------------------\n");
			printf("Otorgue el límite superior: ");
			scanf("%f",&xU);
			printf("--------------------------------\n");
			printf("Otorgue el número máximo de iteraciones: ");
			scanf("%d",&i);
			printf("--------------------------------\n");
			printf("Otorgue la tolerancia de error: ");
			scanf("%f",&es);
			printf("--------------------------------\n\n");
			
			//Para darle mayor generalidad al programa, él mismo tratará de buscar la concavidad de la curva (de no conseguirlo, pregunta al usuario)
			if((f(xL) < f(xL + ((xU - xL)/100))) && (f(xU) < f(xU - ((xU - xL)/100)))) //Si la función es identificable como cóncava hacia abajo
			{
				Maximizar(xL,xU,i,es); //El programa ha identificado que en el intervalo hay un máximo, así que se maximizará
				break;
			}
			if((f(xL + ((xU - xL)/100)) < f(xL)) && (f(xU - ((xU - xL)/100)) < f(xU))) //Si la función es identificable como cóncava hacia arriba
			{
				Minimizar(xL,xU,i,es); //El programa ha identificado que en el intervalo hay un mínimo, así que se minimizará
				break;
			}
			//El programa llega hasta aquí si no consiguió clasificar la función en cóncava o convexa, por lo que se le pedirá al usuario definir
			printf("!  -----------------------------------------------  !\n");
			printf("No se ha logrado determinar la concavidad de la curva\n");
			printf("!  -----------------------------------------------  !\n");
			printf("Defina si se va a maximizar o minimizar:\n");
			printf("1. Maximizar\n");
			printf("2. Minimizar\n");
			scanf("%d",&u);
			printf("\n");
			if(u == 1)
			{
				Maximizar(xL,xU,i,es); //Se maximizará
				break;
			}
			if(u == 2)
			{
				Minimizar(xL,xU,i,es); //Se minimizará
				break;
			}
		}
		while(i == i);
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
	return (-x*x);
	//return (2*(sin(x))) - (x*x/2);
}

void Maximizar(float xL, float xU, int i, float es)
{
	//Declaramos más variables
	int j;
	float d,ea,R,x1,x2,xopt=(xU + xL)/2;
	
	//Damos valor a R y a d
	R =(sqrt(5) - 1)/2;
	d = R * (xU - xL);
	
	//Se eligen dos puntos interiores de acuerdo a la proporción áurea
	x1 = xL + d;
	x2 = xU - d;
	
	printf("===============================================================================================================================================\n");
	printf("| i |   xL    |   x2    |  xopt   |   x1    |   xU    |       |  f(xL)  |  f(x2)  | f(xopt) |  f(x1)  |  f(xU)  |       |    ea    |    es    |\n");
	printf("| 0 |  %.3f  |  %.3f  |   ---   |  %.3f  |  %.3f  |       |  %.3f  |  %.3f  |   ---   |  %.3f  |  %.3f  |       |   ---   |  %.3f  |\n",xL,x2,x1,xU,f(xL),f(x2),f(x1),f(xU),es);
	
	//Comenzamos a iterar
	for(j = 0; j<i; j++)
	{
		//Evaluamos la función en esos puntos y comparamos
		xopt = (xU + xL)/2;
		if(f(x1) > f(x2)) //Si f(x1) es mayor a f(x2)
		{
			//Se elimina la sección a la izquierda de x2 por lo tanto actualizamos como sigue los valores
			xL = x2;
		}
		else //Si f(x2) es mayor a f(x1)
		{
			//Se elimina la sección a la derecha de x1 por lo tanto actualizamos como sigue los valores
			xU = x1;
		}
		
		d = R * (xU - xL);
		x1 = xL + d;
		x2 = xU - d;
		ea = 100 * (1 - R) * fabs(((xU - xL)/(xopt)));
		
		printf("| %d |  %.3f  |  %.3f  |  %.3f  |  %.3f  |  %.3f  |       |  %.3f  |  %.3f  |  %.3f  |  %.3f  |  %.3f  |       |  %.3f  |  %.3f  |\n",j+1,xL,x2,xopt,x1,xU,f(xL),f(x2),f(xopt),f(x1),f(xU),ea,es);
		
		if(ea<=es) //Terminará el ciclo en caso de que se alcance la tolerancia de error
		{
			break;
		}
	}
	printf("===============================================================================================================================================\n\n");
	printf("El programa ha tomado %d iteraciones en encontrar un máximo en x = %.3f el cual equivale a f(x) = %.3f con un error de %0.3f\n\n\n",j,xopt,f(xopt),ea);
	return;
}
void Minimizar(float xL, float xU, int i, float es)
{
	//Declaramos más variables
	int j;
	float d,ea,R,x1,x2,xopt=(xU + xL)/2;
	
	//Damos valor a R y a d
	R =(sqrt(5) - 1)/2;
	d = R * (xU - xL);
	
	//Se eligen dos puntos interiores de acuerdo a la proporción áurea
	x1 = xL + d;
	x2 = xU - d;
	
	printf("===============================================================================================================================================\n");
	printf("| i |   xL    |   x2    |  xopt   |   x1    |   xU    |       |  f(xL)  |  f(x2)  | f(xopt) |  f(x1)  |  f(xU)  |       |    ea    |    es    |\n");
	printf("| 0 |  %.3f  |  %.3f  |   ---   |  %.3f  |  %.3f  |       |  %.3f  |  %.3f  |   ---   |  %.3f  |  %.3f  |       |   ---   |  %.3f  |\n",xL,x2,x1,xU,f(xL),f(x2),f(x1),f(xU),es);
	
	//Comenzamos a iterar
	for(j = 0; j<i; j++)
	{
		//Evaluamos la función en esos puntos y comparamos
		xopt = (xU + xL)/2;
		if(f(x1) < f(x2)) //Si f(x1) es menor a f(x2)
		{
			//Se elimina la sección a la izquierda de x2 por lo tanto actualizamos como sigue los valores
			xL = x2;
		}
		else //Si f(x2) es menor a f(x1)
		{
			//Se elimina la sección a la derecha de x1 por lo tanto actualizamos como sigue los valores
			xU = x1;
		}
		
		d = R * (xU - xL);
		x1 = xL + d;
		x2 = xU - d;
		ea = 100 * (1 - R) * fabs(((xU - xL)/(xopt)));
		
		printf("| %d |  %.3f  |  %.3f  |  %.3f  |  %.3f  |  %.3f  |       |  %.3f  |  %.3f  |  %.3f  |  %.3f  |  %.3f  |       |  %.3f  |  %.3f  |\n",j+1,xL,x2,xopt,x1,xU,f(xL),f(x2),f(xopt),f(x1),f(xU),ea,es);
		
		if(ea<=es) //Terminará el ciclo en caso de que se alcance la tolerancia de error
		{
			break;
		}
	}
	printf("===============================================================================================================================================\n\n");
	printf("El programa ha tomado %d iteraciones en encontrar un mínimo en x = %.3f el cual equivale a f(x) = %.3f con un error de %0.3f\n\n\n",j,xopt,f(xopt),ea);
	return;
}
