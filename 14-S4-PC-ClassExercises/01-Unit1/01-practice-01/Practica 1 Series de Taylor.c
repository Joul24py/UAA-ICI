/*                    Universidad autónoma de Aguascalientes
                           Centro de Ciencias Básicas
                   Departamento de Ciencias de la Computación
                        Programación Científica
                      Joel Alejandro Espinoza Sánchez
                           Dariana Gómez Garza
					 Fernando Francisco González Arenas
                     Luis Fernando Guitiérrez Marfileño
                  Descripción: Este programa calcula la serie de Taylor de la tangente usando
                  polinomios de grado 2, 4 y 6; permitiéndole al usuario insertar su valor del
                  ángulo que desea calcularle la función tangente en grados y devolviendo una
                  aproximación. Asimismo retorna qué tanto error existe en relación a la
                  solución analítica
--------------------------------------------------------------------------------------*/ 

#include<stdio.h>
#include<math.h>
#include<locale.h>

float convertir(float grad);
int fact(int num,int fac);

main(){
	
	setlocale(LC_ALL,"");
    int op=0,poli=0,confirm=0;
    float grad=0, valor=0,rad=0,pi=3.14159265359;
	
	do{
		system("CLS");
		printf("\n-----------------------Calculadora de la funcion tangente-----------------------------\n\n");
		printf(" \n    MENU    \n\n");
		printf("1.- Calcular la serie hasta grado 2\n");
		printf("2.- Calcular la serie hasta grado 4\n");
		printf("3.- Calcular la serie hasta grado 6\n");
		printf("4.- Salir\n\n");
		printf("Ingrese una opción: ");
		
		scanf("%d",&op);
		
		if(op==4)
		{
			break;
		}
		if(op<=0 || op>=5)
		{
			system("CLS");
			printf("Opción no válida\n");
			printf("Presione ENTER para volver al menú principal\n");
			getchar();
			getchar();
			continue;
		}
		
		system("CLS");
		printf("\nIngrese el valor del ángulo:\n");
		scanf("%f",&grad);
		
		printf("Calculando la tangente de %0.3f grados o %0.3fpi radianes\n\n",grad,grad/180);
		
		rad=convertir(grad);
		
			switch(op){
				
				case 1:
					{
						valor=((1*convertir(grad)/(fact(1,1))));
						//valor=rad;
						printf("SOLUCIÓN NUMÉRICA: tan(%0.2f) = %0.10f\n\n",grad,valor);
						break;
					}
					
				case 2:
					{
						valor=((1*convertir(grad)/(fact(1,1)))) + (2*(pow(convertir(grad),3))/(fact(3,1)));
						//valor=rad+((1/3)*(pow(rad,3)));
						printf("SOLUCIÓN NUMÉRICA: tan(%0.2f) = %0.10f\n\n",grad,valor);
						break;
					}
				case 3:
					{
						valor=((1*convertir(grad)/(fact(1,1)))) + (2*(pow(convertir(grad),3))/(fact(3,1))) + (16*(pow(convertir(grad),5))/(fact(5,1)));
						//valor=rad+((1/3)*(pow(rad,3)))+((2/15)*(pow(rad,5)));
						printf("SOLUCIÓN NUMÉRICA: tan(%0.2f) = %0.10f\n\n",grad,valor);
						break;
					}
		}
		
		printf("SOLUCIÓN analítica: tan(%0.2f) = %0.10f\n\n\n",grad,tan(rad));
		
		float error = valor-tan(rad);
		if(error<0)
		{
			error = error*(-1);
		}
		printf("El error absoluto entre la SOLUCIÓN analítica y NUMÉRICA es de %0.9f\n",error);
		printf("El error relativo entre la SOLUCIÓN analítica y NUMÉRICA es de %0.2f%%\n\n\n",(error/tan(rad))*100);
		printf("Presione ENTER para volver al menú principal\n");
		getchar();
		getchar();
		
	}while(op!=4);
	
}

float convertir(float grad)
{
	float pi=3.14159265359;
	float rad=(grad*pi)/180;
	return rad;
}

int fact(int num,int fac)
{
	if(num!=0)
	{
		fac=num*fact(num-1,fac);
		return fac;
	}
	else
	{
		return 1;
	}
}
