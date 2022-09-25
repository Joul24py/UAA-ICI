//Ejercicio 3_4: Cola Dinámica
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu,x,y,pos=0;

struct nodo
{
	int num;
	struct nodo *ap;
};

typedef struct nodo *TipoLista;

TipoLista p=NULL;
TipoLista q;
TipoLista r;

void Imprimir();
void Agregar();
void Eliminar();

main()
{
	setlocale(LC_ALL,"");
	
	do
	{
		system("CLS");
		printf("MENÚ\n");
		printf("Seleccione una opción:\n\n");
		printf("1.- Mostrar la Cola\n");
		printf("2.- Agregar dato a la Cola\n");
		printf("3.- Eliminar dato de la Cola\n");
		printf("4.- Salir\n");
		scanf("%d",&menu);
		
		switch (menu)
		{
			case 1:
				{
					system("CLS"); //Mostrar cola
					Imprimir();
					getchar();
					getchar();
					break;
				}
			case 2:
				{
					system("CLS"); //Agregar a la cola
					Agregar();
					getchar();
					break;
				}
			case 3:
				{
					system("CLS"); //Eliminar de la cola
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
					system("CLS"); //Dato no válido
					printf("Dato no válido");
					getchar();
					getchar();
					break;
				}
		}
	}
	while(menu!=4);
	
	getchar();
}

void Imprimir()
{
	TipoLista a;
	int n=0;
	a=p;
	if(pos==0)
	{
		printf("Cola vacía");
	}
	else
	{
		do
		{
			printf("[%d] ",a->num);
			a=a->ap;
			n++;
		}
		while(n<pos);
	}
}

void Agregar()
{
	printf("Escriba el dato a agregar:\n");
	scanf("%d",&x);
	if(p==NULL)
	{
		p=new(struct nodo);
		p->num=x;
		p->ap=NULL;
		q=p;
		r=p;
		pos++;
	}
	else
	{
		r=new(struct nodo);
		r->num=x;
		r->ap=NULL;
		q->ap=r;
		q=r;
		pos++;
	}
}

void Eliminar()
{
	TipoLista a;
	a=p;
	if(pos==0)
	{
		printf("Cola vacía");
	}
	else
	{
		if(pos==1)
		{
			p=NULL;
			pos--;
		}
		else
		{
			p=p->ap;
			pos--;
		}
	}
}
