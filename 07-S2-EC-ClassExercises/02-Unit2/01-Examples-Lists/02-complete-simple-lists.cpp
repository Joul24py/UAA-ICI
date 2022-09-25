#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <locale.h>

int menu,x,n;

struct nodo
{
	int num;
	struct nodo *sig;
};

typedef struct nodo *TipoLista;

void Insertar (TipoLista &lista, int valor);
void MostrarLista(TipoLista lista);
void Modificar(TipoLista lista, int v, int m);
void EliminarRegistro(TipoLista &lista, int y);

main()
{
	setlocale(LC_ALL, "");
	
	TipoLista lista=NULL;
	TipoLista p;
	
	do
	{
		system("CLS");
		printf("Menú:\n");
		printf("1: Agregar Dato\n");
		printf("2: Mostrar Datos\n");
		printf("3: Modificar Dato\n");
		printf("4: Eliminar Dato\n");
		printf("5: Vaciar Lista\n");
		printf("6: Salir\n");
		printf("Seleccione la opción:\n");
		scanf("%d",&menu);
		
		switch (menu)
		{
			case 1:
				{
					system("CLS"); //Agregar Dato
					
					do //Se crea una lista hasta que el usuario presione 0
					{
						system ("CLS");
						printf("Escriba el dato a agregar (0 para salir):\n");
						scanf("%d",&x);
						if(x!=0)
						{
							Insertar(lista,x);
						}
					}
					while(x!=0);
					
					getchar();
					break;
				}
			case 2:
				{
					system("CLS"); //Mostrar Datos
					MostrarLista(lista);
					
					getchar();
					getchar();
					break;
				}
			case 3:
				{
					system("CLS"); //Modificar Dato
					MostrarLista(lista);
					printf("Escriba el dato que desea modificar:\n");
					scanf("%d",&x);
					printf("Escriba el dato que lo reemplazará:\n");
					scanf("%d",&n);
					Modificar(lista,x,n);
					
					getchar();
					getchar();
					break;
				}
			case 4:
				{
					system("CLS"); //Eliminar Datos
					MostrarLista(lista);
					printf("Escriba el dato a eliminar:\n");
					scanf("%d",&x);
					EliminarRegistro(lista,x);
					
					getchar();
					getchar();
					break;
				}
			case 5:
				{
					system("CLS"); //Vaciar Lista
					
					break;
				}
			default:
				{
					if(menu!=6)
					{
						printf("Opción no válida\n");
					}
					else
					{
						break;
					}
					getchar();
					getchar();
				}
		}
	}
	while(menu!=6);
}

void Insertar(TipoLista &lista, int valor)
{
	TipoLista nuevo;
	nuevo=new(struct nodo);
	nuevo->num=valor;
	nuevo->sig=lista;
	lista=nuevo;
}

void MostrarLista(TipoLista lista)
{
	TipoLista nodo=lista;
	
	if(lista==NULL)
	{
		printf("Lista Vacía");
	}
	else
	{
		do
		{
			printf("%d\n",nodo->num);
			nodo=nodo->sig;
		}
		while(nodo);
	}
}

void Modificar(TipoLista lista, int y, int m)
{
	TipoLista nodo;
	int flag=0;
	nodo=lista;
	
	do
	{
		if(nodo->num==y)
		{
			nodo->num=m;
			flag=1;
			printf("Registro Modificado\n");
			MostrarLista(lista);
		}
		nodo=nodo->sig;
	}
	while(nodo);
	if(flag==0)
	{
		printf("No se encontró el registro");
	}
}

void EliminarRegistro(TipoLista &lista, int y)
{
	TipoLista nodo;
	TipoLista anterior;	
	
	nodo=lista;
	
	int flag=0;
	
	if(lista!=NULL)
	{
		do
		{
			if(nodo->num==y)
			{
				flag=1;
				if(nodo==lista)
				{
					lista=lista->sig;
				}
				else
				{
					anterior->sig=nodo->sig;
				}
				delete(nodo);
				printf("Registro Eliminado");
				return;
			}
			anterior=nodo;
			nodo=nodo->sig;
		}
		while(nodo!=NULL);
	}
	else
	{
		printf("Lista vacía\n");
	}
	
	if(flag==0)
	{
		printf("No se encontró el registro\n");
	}
}
