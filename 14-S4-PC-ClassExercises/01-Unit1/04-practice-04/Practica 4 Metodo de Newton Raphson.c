/*                    Universidad autónoma de Aguascalientes
                           Centro de Ciencias Básicas
                   Departamento de Ciencias de la Computación
                        Programación Científica
                      Joel Alejandro Espinoza Sánchez
                           Dariana Gómez Garza
					 Fernando Francisco González Arenas
                     Luis Fernando Guitiérrez Marfileño
                  Descripción: Este programa realiza el cálculo a partir de una función especificada,
                  trabajando con un valor de inicio dado por el usuario. La función está definida dentro
                  del programa así como su derivada y el programa de forma iterativa trabaja para llegar a
                  valores donde la diferencia, es decir, el error sea menor al que se especificó por el
                  usuario
--------------------------------------------------------------------------------------*/ 

#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
	
	setlocale(LC_ALL,"");
	int op,i,j;
	float x0,x1,m,resta;
    do
	{
		printf("\n-----------------------Método de Newton Raphson-----------------------------\n\n");
		printf(" \n    MENU    \n\n");
		printf("1.- Desarrollar el método\n");
		printf("2.- Salir\n\n");
		printf("Ingrese una opción: ");
		
		scanf("%d",&op);
		
		if(op==2)
		{
			break;
		}
		if(op<=0 || op>=3)
		{
			printf("Opción no válida\n");
			printf("Presione ENTER para volver al menú principal\n");
			getchar();
			getchar();
			continue;
		}
		
		switch(op)
		{
			case 1:
				{
					//Entrar al método
					
					printf("Ingresa x0: ");
					scanf("%f",&x0);
					
					printf("Ingresa el número de iteraciones: ");
					scanf("%d",&i);
					
					printf("Ingresa margen de error: ");
					scanf("%f",&m);
					
					j=0;
					do
					{
						if(j>=i)
						{
							break;
						}
						x0=x1;
						x1 = x0 - ((cos(x0) - x0)/((sin(x0)*(-1)) - 1));
						j++;
						printf("El valor de x1 es: %0.9f\n",x1);
						resta = x1 - x0;
						if(resta<0)
						{
							resta = resta*(-1);
						}
					}
					while(resta>m);
					
					break;
				}
		}
		
		getchar();
		getchar();
	}
	while(op!=2);
	
}
