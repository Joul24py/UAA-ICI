#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

int pag=2;

main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	
	do
	{
		switch(pag)
		{
		case 0:
			{
				pag=5;
				break;
			}
		case 1:
			{
				//1.- Portada
				system("CLS");
				system("color F0");
				printf("\nUniversidad Autónoma de Aguascalientes\n");
				printf("\nCentro de Ciencias Básicas\n");
				printf("\nDepartamento de Ciencias de la Computación\n");
				printf("\nFundamentos de Estructuras Computacionales\n");
				printf("\n1° E\n");
				printf("\n");
				printf("\n");
				printf("\nProyecto Parcial: Elaboración de Matriz de Adyacencia e Incidencia de Teoría de Grafos\n");
				printf("\n");
				printf("\n");
				printf("\nDoctor en Matemáticas: Alejandro Padilla Díaz\n");
				printf("\n");
				printf("\nAlumno: Joel Alejandro Espinoza Sánchez\n");
				printf("\n");
				printf("\nFecha de Entrega: Aguascalientes, Ags, 26 de octubre del 2018\n");
				printf("\n");
				printf("\n");
				printf("Ingrese un número para continuar\n");
				scanf("%d",&pag);
				break;
			}
		case 2:
			{
				//2.- Instrucciones y Guía
				system("CLS");
				system("color 80");
				printf("\nInstrucciones y Guía\n");
				printf("Instrucciones:\n");
				printf("1.- Crear una matriz mínimo de 6x6 y máximo de 10x10\n");
				printf("2.- Generar números aleatorios (0,1)\n");
				printf("3.- Primero, obtener la matriz de adyacencia\n");
				printf("4.- Segundo, obtener la matriz de incidencia\n"); 
				printf("5.- Una opción de salida\n");
				printf("\n");
				printf("\n");
				printf("Seleccione un número para acudir a la parte deseada del programa\n");
				printf("1) Portada\n");
				printf("2) Instrucciones y Guía\n");
				printf("3) Matriz de Incidencia\n");
				printf("4) Matriz de Adyacencia\n");
				printf("5) Salir del programa (Cualquier otro número que se otorgue que no sean los ya acotados, harán que el programa termine)\n");
				scanf("%d",&pag);
				break;
			}
		case 3:
			{
				//3.- Matriz de Incidencia
				system("CLS");
				system("color 06");
				int f1=0,c1=0,validar=0;
				printf("\nGrafo de Martiz de Incidencia\n\n");
				//3.1.- Validar los valores
				do
				{
					printf("¿De qué tamaño será la matriz?\n");
					printf("Filas: ");
					scanf("%d",&f1);
					if(f1<6||f1>10)
					{
						printf("ERROR: Ha ingresado un valor incorrecto");
						printf("\nPor favor revise que el valor de filas otorgado sea mayor o igual a 6 y menor o igual a 10\n");
					}
					else
					{
						validar=validar+1;
					}
				}
				while(validar<1);
				validar=0;
				do
				{
					printf("Columnas: ");
					scanf("%d",&c1);
					if(c1<6||c1>10)
					{
						printf("ERROR: Ha ingresado un valor incorrecto");
						printf("\nPor favor revise que el valor de columnas otorgado sea mayor o igual a 6 y menor o igual a 10\n");
					}
					else
					{
						validar=validar+1;
					}
				}
				while(validar<1);
				
				//3.2.- Construcción de la primera matriz. Esta, por una restricción, conviene llenarse por columnas (verticalmente)
				int random=0,matinc1[c1+1][f1+1],contcol=0,contfil=0,restrictor=0,sumhor=0,sumvert=0,prob=0,otronumerox=0,otronumeroy=0;
				do
				{
					do
					{
						if(f1>7)
						{
							if(contfil>5)
							{
								prob=rand()%3;
							}
							else
							{
								if(contfil<2)
								{
									prob=rand()%7;
								}
								else
								{
									prob=rand()%6;
								}
							}
						}
						else
						{
							if(contfil<2)
							{
								prob=rand()%7;
							}
							else
							{
								if(contfil>4)
								{
									prob=rand()%5;
								}
								else
								{
									prob=rand()%5;
								}
							}
						}
						if(restrictor<2 && prob<=3) //prob hace que la probabilidad de que salga 1 en un valor sea menor (Para eliminar, quitar línea previa y "&& prob<5" de esta línea)
						{
							random=rand()%2;
						}
						else
						{
							random=rand()%1;
						}
						matinc1[contcol][contfil]=random;
						if(matinc1[contcol][contfil]==1)
						{
							restrictor=restrictor+1;
						}
						contfil=contfil+1;
					}
					while(contfil<f1);
					restrictor=0;
					contfil=0;
					contcol=contcol+1;
				}
				while(contcol<c1);
				//Una vez termine este ciclo, la matriz de incidencia del caso 1 debería haberse llenado con valores de forma exitosa
				
				//3.2.1.- Restrictor para evitar que una columna quede en ceros
				int restrictor1=0;
				contcol=0;
				contfil=0;
				do
				{
					do
					{
						restrictor1=restrictor1+matinc1[contcol][contfil];
						contfil=contfil+1;
					}
					while(contfil<f1);
					if(restrictor1<1)
					{
						matinc1[contcol][contfil-1]=1;
					}
					contfil=0;
					contcol=contcol+1;
					restrictor1=0;
				}
				while(contcol<c1);
				
				//3.3.- Mostrar la Matriz en la Computadora
				contcol=0;
				contfil=0;
				do
				{
					do
					{
						printf("[%d]   ",matinc1[contcol][contfil]);
						contcol=contcol+1;
					}
					while(contcol<c1);
					contcol=0;
					sumhor=0;
					do
					{
						sumhor=sumhor+matinc1[contcol][contfil];
						contcol=contcol+1;
					}
					while(contcol<c1);
					printf(" %d ",sumhor);
					printf("\n");
					contcol=0;
					contfil=contfil+1;
				}
				while(contfil<f1);
				contcol=0;
				contfil=0;
				
				//3.4.1.- Sumas verticales de la matriz (cálculo y desplegado en la pantalla)
				do
				{
					do
					{
						sumvert=sumvert+matinc1[contcol][contfil];
						contfil=contfil+1;
					}
					while(contfil<f1);
					printf(" %d    ",sumvert);
					sumvert=0;
					contfil=0;
					contcol=contcol+1;
				}
				while(contcol<c1);
				
				printf("\n");
				printf("\n");
				printf("Ingrese un número para continuar\n");
				scanf("%d",&pag);
				break;
			}
		case 4:
			{
				//4.- Matriz de Adyacencia
				system("CLS");
				system("color 60");
				int l2=0,validar=0,contfil=0,contcol=0,restrictor=0,sumhor=0,sumvert=0,random=0;
				printf("\nGrafo de Martiz de Adyacencia\n\n");
				//4.1.- Validar los valores
				do
				{
					printf("¿De qué tamaño será la matriz?\n");
					printf("Lados: ");
					scanf("%d",&l2);
					
					if(l2<6||l2>10)
					{
						printf("ERROR: Ha ingresado un valor incorrecto");
						printf("\nPor favor revise que el valor de lados otorgado sea mayor o igual a 6 y menor o igual a 10\n");
					}
					else
					{
						validar=validar+1;
					}
				}
				while(validar<1);
				
				//4.2.- Construcción de la segunda matriz. Esta, por su naturaleza se agrega la variable "contextra" para lograr la simetría buscada
				int matady2[l2+1][l2+1],contlad=0,contextra=0;
				contfil=0;
				contcol=0;
				restrictor=0;
				sumhor=0;
				sumvert=0;
				do
				{
					do
					{
						random=rand()%2;
						matady2[contlad+contcol][contextra]=random;
						matady2[contextra][contlad+contcol]=random;
						contcol=contcol+1;
					}
					while(contcol<l2);
					contcol=0;
					contextra=contextra+1;
					contfil=contfil+1;
				}
				while(contfil<l2);
				//Una vez termine este ciclo, la matriz de incidencia del caso 1 debería haberse llenado con valores de forma exitosa
				
				//4.3.- Mostrar la Matriz en la Computadora
				contcol=0;
				contfil=0;
				do
				{
					do
					{
						printf("[%d]   ",matady2[contcol][contfil]);
						contcol=contcol+1;
					}
					while(contcol<l2);
					contcol=0;
					sumhor=0;
					do
					{
						sumhor=sumhor+matady2[contcol][contfil];
						contcol=contcol+1;
					}
					while(contcol<l2);
					printf(" %d ",sumhor);
					printf("\n");
					contcol=0;
					contfil=contfil+1;
				}
				while(contfil<l2);
				contcol=0;
				contfil=0;
				
				//4.4.1.- Sumas verticales de la matriz (cálculo y desplegado en la pantalla)
				do
				{
					do
					{
						sumvert=sumvert+matady2[contcol][contfil];
						contfil=contfil+1;
					}
					while(contfil<l2);
					printf(" %d    ",sumvert);
					sumvert=0;
					contfil=0;
					contcol=contcol+1;
				}
				while(contcol<l2);
				
				printf("\n");
				printf("\n");
				printf("Ingrese un número para continuar\n");
				scanf("%d",&pag);
				break;
			}
		default:
			{
				//5.- Salir
				break;
			}
		}
	}
	while(pag<5);
}
