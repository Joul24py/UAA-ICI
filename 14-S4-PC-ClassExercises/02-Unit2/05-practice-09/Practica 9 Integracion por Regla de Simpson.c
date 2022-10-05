/*                    Universidad autónoma de Aguascalientes
                           Centro de Ciencias Básicas
                   Departamento de Ciencias de la Computación
                        Programación Científica
                      Joel Alejandro Espinoza Sánchez
                           Dariana Gómez Garza
					 Fernando Francisco González Arenas
                     Luis Fernando Guitiérrez Marfileño
                  Descripción: Este programa obtiene el área aproximada bajo la curva de la
                  función: f(x)= e^(-x^2) por el método de integración por regla de Simpson de 1/3.
--------------------------------------------------------------------------------------*/ 
#include<stdio.h>
#include<math.h>
#include<locale.h>

float f(float x);

main()
{
	setlocale(LC_ALL,"");

	float a=0,b=0,area=0;
	int op;
	
	do
	{
		printf("\n----------------integración por regla de Simpson de 1/3---------------------\n\n");
		printf(" \n    MENU    \n\n");
		printf("1.- Ejecutar el método\n\n");
		printf("2.- Salir\n\n");
		printf("Ingrese una opción: ");
		
		scanf("%d",&op);
	
		switch(op)
		{
			case 1:
				{
					
					printf("\nIngrese el valor del límite inferior : ");
					scanf("%f",&a);
				
					printf("Ingrese el valor del límite superior:  ");
					scanf("%f",&b);
					
					area = ((b-a)/6) * (f(a) + (4*f((a+b)/2)) + f(b));	
					
					printf("El área es: %f \n\n", area);
					
					break;
				}
				
			case 2:
				{
					break;
				}		
		}
		getchar();	
	}
	while(op!=2);
}

float f(float x)
{
	return exp(-pow(x,2));
}
