/*
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Estructuras Computacionales Avanzadas
3° "A"

Algoritmo de Grafos Dirigidos (Profundidad)

Profesor: Julio César Ponce Gallegos

Alumno: Espinoza Sánchez Joel Alejandro

Aguascalientes, Ags. 28 de noviembre de 2019
*/
//Las librerías------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define Nodo struct nodo
#define Arista struct arista
#define Lista struct pila

//Estructuras--------------------------------------------------------------------------------------------------
Nodo
{
	char dato;
	Nodo* siguiente;
	Arista* adyacencia; 
	int visitado,terminado;
	int monto;
	char anterior;
};

Arista
{
	Nodo*vrt; 
	Arista*siguiente;
	int peso;
};

Lista
{
	Nodo* dato;
	Lista*siguiente;
};

Nodo*inicio=NULL;
Lista*ini=NULL;
Lista*final=NULL; 

//Funciones----------------------------------------------------------------------------------------------------
void insertarNodo();
void agregarArista(Nodo*aux,Nodo*aux2,Arista*nuevo);
void insertarArista();
void visualizarGrafo();
void recorridos();
void recorridoAnchura();
void recorridoProfundidad(Nodo* aux);
void insertarPila(Nodo* aux);
void insertarCola(Nodo* aux);
Nodo*desencolar();
void reiniciar();
void dijkstra();

//La función main----------------------------------------------------------------------------------------------
int main()
{
    setlocale(LC_ALL,"");
	
	int opcion,N,i;
	printf("Ingrese n�mero de vertices:");
    scanf("%i",&N);
    for(i=0;i<N;i++)
	{
    	insertarNodo();
	}
	system("cls");
    do
	{
    	printf("-----------\n");
        printf(" 1. Insertar Vertice                 \n");
        printf(" 2. Insertar Arista                  \n");
        printf(" 3. Mostrar Listas                   \n");
        printf(" 4. Recorrer Grafo                   \n");
        printf(" 5. Salir                            \n");
        printf("------------\n");
        printf("Escoge opcion:");
        scanf("%i",&opcion);
        switch(opcion)
		{
            case 1:
                    insertarNodo();
                    break;
            case 2: insertarArista();
                    break;
            case 3: visualizarGrafo();
                    break;
            case 4: recorridos();
                    break;
            case 5: break;
            default: printf("Opcion no valida...!!!\n");
                     break;
        }
        system("pause");
        system("cls");
    }
	while(opcion!=5);
    return 1;
}

//Se inserta un vértice----------------------------------------------------------------------------------------
void insertarNodo()
{
    Nodo* aux;
	Nodo* nuevo=(Nodo*)malloc(sizeof(Nodo));
	fflush(stdin);
	printf("Ingrese vertice:");
	scanf("%c",&nuevo->dato);
	nuevo->siguiente=NULL;
    nuevo->adyacencia=NULL;
    nuevo->visitado=nuevo->terminado=0;
    nuevo->monto=-1;
    nuevo->anterior=0;
    if(inicio==NULL)
	{
        inicio=nuevo;
    }
	else
	{
        aux=inicio;
        while(aux->siguiente!=NULL)
		{
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
      }
 
 }

//Se inserta una arista (una unión entre dos vértices)---------------------------------------------------------
void insertarArista()
{
    char ini, fin;
    Arista* nuevo=(Arista*)malloc(sizeof(Arista));
    nuevo->siguiente=NULL;
    Nodo* aux;
	Nodo* aux2;
    if(inicio==NULL)
	{
         printf("Error: El grafo está vacio\n");
         return;
    }
    fflush(stdin);
    printf("Ingresar Nodo Inicial y final :");
    scanf("%c %c",&ini,&fin);
    printf("Ingresar Peso de la arista:");
    scanf("%i",&nuevo->peso);
    aux=inicio;
    aux2=inicio;
    while(aux2!=NULL)
	{
        if(aux2->dato==fin)
		{
            break;
        }
        aux2=aux2->siguiente;
    }
    if(aux2==NULL)
	{
    	printf("Error:Vertice no encontrado\n");
    	return;
	}
    while(aux!=NULL)
	{
        if(aux->dato==ini)
		{
            agregarArista(aux,aux2,nuevo);
            return;
        }
        aux = aux->siguiente;
    }
    if(aux==NULL)
    {
    	printf("Error:Vertice no encontrado\n");
	}
}

//Función auxiliar de insertarArista para unir por los datos del struct----------------------------------------
void agregarArista(Nodo* aux,Nodo* aux2,Arista* nuevo)
{
    Arista* a;
    if(aux->adyacencia==NULL)
	{
	    aux->adyacencia=nuevo;
        nuevo->vrt=aux2;
    }
	else
	{
	    a=aux->adyacencia;
        while(a->siguiente!=NULL)
            a=a->siguiente;
        nuevo->vrt=aux2;
        a->siguiente=nuevo;
    }
}

//Imprime el grafo---------------------------------------------------------------------------------------------
void visualizarGrafo()
{
    Nodo*aux=inicio;
    Arista* ar;
    printf("Nodos\n");
    while(aux!=NULL)
	{
	    printf("%c:    ",aux->dato);
        if(aux->adyacencia!=NULL)
		{
            ar=aux->adyacencia;
            while(ar!=NULL)
			{
			    printf(" %c",ar->vrt->dato);
                ar=ar->siguiente;
            }
        }
        printf("\n");
        aux=aux->siguiente;
    }
    printf("\n");
}

//Comienza a hacer los recorridos (pide el vértice de inicio) y comienza ambas búsquedas-----------------------
void recorridos()
{
	char vertice;
	Nodo*aux=inicio,*aux2=inicio;
  	if(inicio!=NULL)
  	{
  	 	fflush(stdin);
  	 	printf("Escoger vertice inicial:");
     	scanf("%c",&vertice);	
     	while(aux!=NULL)
		{
  	    	if(aux->dato==vertice)
  	    	{
  	    		break;
			}
	    	aux=aux->siguiente;
     	}
     	if(aux==NULL)
	 	{
     		printf("Error: Vertice no encontrado\n");
	 	}
		else
		{
			printf("\nRecorrido por profundidad: ");
			recorridoProfundidad(aux);
			while(aux2!=NULL)
			{
				if(aux2->terminado==0)
				{
					recorridoProfundidad(aux2);
				}
				aux2=aux2->siguiente;
			}
			while(ini!=NULL)
			{
				printf("%c ",desencolar()->dato);
			}
			reiniciar();
			printf("\n");
	 	}
   	}
}

//Búsqueda de profundidad. Función auxiliar de recorridos------------------------------------------------------
void recorridoProfundidad(Nodo* aux)
{
	Arista*a;
	aux->visitado=1;
    if(aux->adyacencia!=NULL)
	{
        a=aux->adyacencia;
        while(a!=NULL)
		{
			if(a->vrt->visitado==0)
			{
				recorridoProfundidad(a->vrt);
			}
            a=a->siguiente;
        }
    }
    aux->terminado=1;
    insertarPila(aux);
}

//Pila auxiliar para el recorrido en profundidad---------------------------------------------------------------
void insertarPila(Nodo* aux)
{
	Lista*nuevo=(Lista*)malloc(sizeof(Lista));
	nuevo->dato=aux;
	nuevo->siguiente=NULL;
	if(ini==NULL)
	{
		ini=nuevo;
		final=nuevo;
	}
	else
	{
	   nuevo->siguiente=ini;
	   ini=nuevo;    	
	}
}

//Eliminación de elemento de la cola---------------------------------------------------------------------------
Nodo*desencolar()
{
	Lista*aux;
	if(ini==NULL)
	{
		return NULL;
	}
	else
	{
		aux=ini;
		ini=ini->siguiente;
		aux->siguiente=NULL;
		if(ini==NULL)
		final=NULL;
	}
	Nodo*resultado=aux->dato;
	free(aux);
	return resultado;
}

//Reinicia los valores apra comenzar nuevamente----------------------------------------------------------------
void reiniciar()
{
	if(inicio!=NULL)
	{
		Nodo*aux=inicio;
		while(aux!=NULL)
		{
			aux->visitado=aux->terminado=0;
		    aux=aux->siguiente;
		}
	}
}
