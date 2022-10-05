/*                    Universidad autónoma de Aguascalientes
                           Centro de Ciencias Básicas
                   Departamento de Ciencias de la Computación
                        Programación Científica
                      Joel Alejandro Espinoza Sánchez
                           Dariana Gómez Garza
					 Fernando Francisco González Arenas
                     Luis Fernando Guitiérrez Marfileño
                  Descripción: 
--------------------------------------------------------------------------------------*/ 

#include <stdio.h>
#include <math.h>
#define e 2.718281828

int main ()
{
	int i=0,op,flag1=0,flag2=0;
	float dato=100,x=0,xi=0,temporal=0,error;
	printf("---------------------------------Metodo de iteracion de punto fijo-----------------------------------\n");
	printf("Encontrar la raiz para la funcion:  f(x) = e^(-x) - x\n");
	printf(" \n    MENU");
	do
	{
		printf("\n\n");
		printf("1.- Ingresar el valor inicial de x\n");
		printf("2.- Ingresar la tolerancia de error\n");
		printf("3.- Salir\n\n");
		printf("Ingrese una opcion: ");
		scanf("%d",&op);
		
		if(op==3)
		{
			break;
		}
		if(op<=0 || op>=4)
		{
			printf("\n\n");
			printf("Opcion no valida\n");
			printf("Presione ENTER para volver al menu principal\n");
			getchar();
			getchar();
			continue;
		}
		
		switch(op)
		{
			case 1:
				{
					printf("\n\n");
					printf("Inserte el valor inicial:\n");
					scanf("%f",&x);
					flag1=1;
					break;
				}
			case 2:
				{
					printf("\n\n");
					printf("Inserte la tolerancia de error:\n");
					scanf("%f",&error);
					flag2=1;
					break;
				}
		}
		
		if(flag1==1 && flag2==1)
		{
			printf("x(i)         x(i+1)            x(i+1)-x(i) \n\n\n");
			do
			{
				printf("%d    ",i);  //x(i)    
				printf("%.9f",x);   //x(i+1)       
				xi = pow(e,(-x));  //despeje    
				if (i==0) //si x(i) es igual a 0
				{
					printf("           *************"); 
				}     
				else
				{
				 	dato = fabs(((x-temporal)/x)*100);
				 	printf("           %.9f",dato);
				}      
				temporal=x;      
				x=xi;      
				i++;      
				printf("\n");      
			}
			while(dato > error);  
				
			printf("\n"); 
			printf("La raiz de la funcion es: %.9f",temporal);  
			getchar();
			flag1=0;
			flag2=0;
		}
	}
	while(op!=3);
}
