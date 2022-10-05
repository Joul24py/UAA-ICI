/*                    Universidad autónoma de Aguascalientes
                           Centro de Ciencias Básicas
                   Departamento de Ciencias de la Computación
                        Programación Científica
                      Joel Alejandro Espinoza Sánchez
                           Dariana Gómez Garza
					 Fernando Francisco González Arenas
                     Luis Fernando Guitiérrez Marfileño
                  Descripción: Este programa obtiene el área aproximada bajo la curva de la
                  función: f(x)= 2^x por el método de integración por aproximaciones rectangulares.
--------------------------------------------------------------------------------------*/ 
#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
	setlocale(LC_ALL,"");


	float a=0,b=0,step=0,area=0;
	int op, n=0,i=0;
	
	do
	{
		
		printf("\n----------------integración por aproximaciones rectangulares ---------------------\n\n");
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
					
					printf("Ingrese el número de subintervalos: ");
					scanf("%d",&n);
					
					step=((b-a)/n);
					
					for(i=0; i<n; i++)
					{
						area = area + (step * (pow(2,a + (i*step)))); 
					}
					
					printf("El área es: %f ", area);
					
					break;
				
			case 2:
				{
					break;
				}		
		}
		getchar();
		
	}
		
  }while(op!=2);
}
