#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu,x,n;

struct nodo
{
	int num;
	struct nodo *ap;
};

typedef struct nodo *TipoLista;

TipoLista p=NULL;
TipoLista q=NULL;
TipoLista r=NULL;

void Insertar();
void MostrarLista(TipoLista p);

main()
{
	setlocale(LC_ALL, "");
	
	do
	{
		system("CLS");
		printf("Menú\n");
		printf("1: Agregar Dato\n");
		printf("2: Mostrar Datos\n");
		/*printf("3: Modificar Dato\n");
		printf("4: Eliminar Dato\n");
		printf("5: Vaciar Lista\n");*/
		printf("6: Salir\n");
		printf("Seleccione una opción\n");
		scanf("%d",&menu);
		
		switch (menu)
		{
			case 1:
				{
					system("CLS"); //Agregar datos
					
					do
					{
						system("CLS");
						printf("Escriba el dato a agregar (0 para salir):\n");
						scanf("%d",&x);
						if(x!=0)
						{
							Insertar();
						}
					}
					while(x!=0);
					
					getchar();
					break;
				}
			case 2:
				{
					system("CLS"); //Mostrar lista
					MostrarLista(p);
					
					getchar();
					getchar();
					break;
				}
			default:
				{
					
				}
		}
	}
	while(menu!=6);
	
	getchar();
}

void Insertar()
{
	if(p==NULL)
	{
		p=new(struct nodo);
		q=p;
		r=p;
		p->num=x;
		p->ap=NULL;
	}
	else
	{
		r=new(struct nodo);
		q->ap=r;
		q=r;
		r->num=x;
		r->ap=NULL;
	}
}

void MostrarLista(TipoLista p)
{
	TipoLista a=p;
	if(p==NULL)
	{
		printf("Lista Vacía");
	}
	else
	{
		do
		{
			printf("%d   ",a->num);
			a=a->ap;
		}
		while(a);
	}
}
