//Ejercicio 3_1: Pila Estática
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int pos=0,x;
int pila[10];

void InicializarPila();
void Imprimir();
void Agregar();
void Eliminar();

main()
{
	setlocale(LC_ALL,"");
	
	int menu;
	InicializarPila();
	
	do
	{
		system("CLS");
		printf("MENÚ\n");
		printf("Seleccione una opción:\n");
		printf("1.- Mostrar la Pila\n");
		printf("2.- Agregar un dato a la Pila\n");
		printf("3.- Eliminar un dato de la Pila\n");
		printf("4.- Salir\n");
		scanf("%d",&menu);
		
		switch (menu)
		{
			case 1:
				{
					system("CLS"); //1.- Mostrar la pila
					Imprimir();
					getchar();
					getchar();
					break;
				}
			case 2:
				{
					system("CLS"); //2.- Agregar a la pila
					Agregar();
					getchar();
					break;
				}
			case 3:
				{
					system("CLS"); //3.- Eliminar de la pila
					Eliminar();
					getchar();
					break;
				}
			case 4:
				{
					break;
				}
			default:
				{
					system("CLS"); //Caso indeterminado
					
					printf("La opción que proporcionó no es válida\n");
					
					getchar();
					getchar();
					break;
				}
			
		}
		
	}
	while(menu!=4);
	
	getchar();
}

void InicializarPila()
{
	int n=0;
	do
	{
		pila[n]=NULL;
		n++;
	}
	while(n<10);
}

void Imprimir()
{
	if(pos==0)
	{
		printf("Pila Vacía");
	}
	else
	{
		int n=0;
		do
		{
			printf("[%d] ",pila[n]);
			n++;
		}
		while(n<pos);
	}
}

void Agregar()
{
	if(pos==10)
	{
		printf("No es posible agregar el dato: La pila está llena");
		getchar();
	}
	else
	{
		printf("Escriba el dato a agregar:\n");
		scanf("%d",&x);
		pila[pos]=x;
		pos++;
	}
}

void Eliminar()
{
	if(pos==0)
	{
		printf("No es posible retirar datos: La pila está vacía");
		getchar();
	}
	else
	{
		pila[pos]=NULL;
		pos--;
	}
}
