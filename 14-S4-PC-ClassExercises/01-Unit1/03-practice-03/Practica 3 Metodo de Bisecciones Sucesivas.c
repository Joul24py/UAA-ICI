/*                    Universidad autónoma de Aguascalientes
                           Centro de Ciencias Básicas
                   Departamento de Ciencias de la Computación
                        Programación Científica
                      Joel Alejandro Espinoza Sánchez
                           Dariana Gómez Garza
					 Fernando Francisco González Arenas
                     Luis Fernando Guitiérrez Marfileño
                  Descripción: Método que evalúa por el teorema de Bolzano, las raíces de una función dada
                  donde se dividía un intervalo a la mitad y según condiciones específicas, se tomará una
                  u otra mitad
--------------------------------------------------------------------------------------*/ 

#include<stdio.h>
#include<math.h>
#include<locale.h>

float f(float x);

main()
{
	
	setlocale(LC_ALL,"");
	int op,flag1=0,flag2=0;
	float xi,xs,xm,e;
    do
	{
		printf("\n-----------------------Método por Bisecciones Sucesivas-----------------------------\n\n");
		printf(" \n    MENU    \n\n");
		printf("1.- Escribir el intervalo inicial\n");
		printf("2.- Escribir la tolerancia de error\n");
		printf("3.- Salir\n\n");
		printf("Ingrese una opción: ");
		
		scanf("%d",&op);
		
		if(op==3)
		{
			break;
		}
		if(op<=0 || op>=4)
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
					//Establecer intervalo inicial
					printf("Establezca el límite inferior del intervalo:\n");
					scanf("%f",&xi);
					printf("Establezca el límite superior del intervalo:\n");
					scanf("%f",&xs);
					flag1=1;
					break;
				}
				
			case 2:
				{
					//Establecer tolerancia de error
					printf("Establezca La tolerancia de error:\n");
					scanf("%f",&e);
					flag2=1;
					break;
				}
		}
		
		if(flag1==1 && flag2==1)
		{
			do
			{
				xm=(xi+xs)/2;
				
				if(f(xi)*f(xm)<0)
				{
					xs=xm;
				}
				
				if(f(xi)*f(xm)>0)
				{
					xi=xm;
				}
				
				if(f(xm)==0)
				{
					break;
				}
				xm=(xi+xs)/2;
			}
			while((xs-xm)>e);
			
			printf("\n\n");
			printf("La raíz de la función es: %0.9f  \n",xm);
			printf("Con un margen de error de: %0.9f ",e);
			
			getchar();
			getchar();
			
			flag1=0;
			flag2=0;
		}
	}
	while(op!=4);
	
}

float f(float x)
{
	return ((x*(sin(x)))-1);
}
