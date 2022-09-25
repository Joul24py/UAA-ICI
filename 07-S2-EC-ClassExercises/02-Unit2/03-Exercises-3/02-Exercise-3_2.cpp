//Ejercicio 3_2: Cola Estática
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int pos=0,x;
int cola[10];

void InicializarCola();
void Imprimir();
void Agregar();
void Eliminar();

main()
{
	setlocale(LC_ALL,"");
	
	int menu;
	InicializarCola();
	
	do
	{
		system("CLS");
		printf("MENÚ\n");
		printf("Seleccione una opción:\n");
		printf("1.- Mostrar la Cola\n");
		printf("2.- Agregar un dato a la Cola\n");
		printf("3.- Eliminar un dato de la Cola\n");
		printf("4.- Salir\n");
		scanf("%d",&menu);
		
		switch (menu)
		{
			case 1:
				{
					system("CLS"); //1.- Mostrar la cola
					Imprimir();
					getchar();
					getchar();
					break;
				}
			case 2:
				{
					system("CLS"); //2.- Agregar a la cola
					Agregar();
					getchar();
					break;
				}
			case 3:
				{
					system("CLS"); //3.- Eliminar de la cola
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

void InicializarCola()
{
	int n=0;
	do
	{
		cola[n]=NULL;
		n++;
	}
	while(n<10);
}

void Imprimir()
{
	if(pos==0)
	{
		printf("Cola Vacía");
	}
	else
	{
		int n=0;
		do
		{
			printf("[%d] ",cola[n]);
			n++;
		}
		while(n<pos);
	}
}

void Agregar()
{
	if(pos==10)
	{
		printf("No es posible agregar el dato: La cola está llena");
		getchar();
	}
	else
	{
		printf("Escriba el dato a agregar:\n");
		scanf("%d",&x);
		cola[pos]=x;
		pos++;
	}
}

void Eliminar()
{
	if(pos==0)
	{
		printf("No es posible retirar datos: La cola está vacía");
		getchar();
	}
	else
	{
		int n=0;
		do
		{
			cola[n]=cola[n+1];
			n++;
		}
		while(n<pos);
		pos--;
	}
}
