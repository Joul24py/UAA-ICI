#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

main()
{
	setlocale(LC_ALL, "");
	
	
	printf("\nEjercicios de Matrices\n");
	printf("Por Joel Alejandro Espinoza Sánchez\n");
	printf("\n\nPresione \"Enter\" para continuar");
	getchar();
	
	int V=0;
	do
	{
		system("CLS");
		system("color C0");
		printf("Ejercicios de Matrices: Elija del 1 al 10 (11 para salir)\n");
		scanf("%d",&V);
		
		switch(V)
		{
			case 1:
				{
					//Ejercicio 1
					system("CLS");
					system("color 0C");
					printf("1) Escribir un programa que cree una matriz de 4*4 con números enteros y que imprima en pantalla:\n");
					printf("   a) La Matriz\n");
					printf("   b) La suma de todos los elementos de la matriz\n\n\n");
					
					int mat[4][4],contcol=0,contfil=0,sum=0;
					contcol=0;
					contfil=0;
					//Algoritmo para insertar valores a la matriz
					do
					{
						do
						{
							printf("Otorga un número: ");
							scanf("%d",&mat[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<4);
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<4);
					//Algoritmo para mostrar la matriz
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							printf("[%d]   ",mat[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<4);
						printf("\n");
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<4);
					
					//Mostrar su suma
					sum=0;
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							sum=sum+mat[contcol][contfil];
							contcol=contcol+1;
						}
						while(contcol<4);
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<4);
					printf("La suma de los elementos de la matriz es: %d",sum);
					
					printf("\nPresiona \"ENTER\" para continuar\n");
					getchar();
					getchar();
				}
				break;
			case 2:
				{
					//Ejercicio 2
					system("CLS");
					system("color 0E");
					printf("2) Escribir un programa que cree una matriz de 4*4 con números enteros y que imprima en pantalla:\n");
					printf("   a) La matriz\n");
					printf("   b) La suma de los elementos por fila\n\n\n");
					
					int mat[4][4],contcol=0,contfil=0,sumhor=0;
					contcol=0;
					contfil=0;
					//Algoritmo para insertar valores a la matriz
					do
					{
						do
						{
							printf("Otorga un número: ");
							scanf("%d",&mat[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<4);
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<4);
					//Algoritmo para mostrar la matriz
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							printf("[%d]   ",mat[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<4);
						contcol=0;
						sumhor=0;
						do
						{
							sumhor=sumhor+mat[contcol][contfil];
							contcol=contcol+1;
						}
						while(contcol<4);
						printf(" %d ",sumhor);
						printf("\n");
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<4);
					
					printf("\nPresiona \"ENTER\" para continuar\n");
					getchar();
					getchar();
				}
				break;
			case 3:
				{
					//Ejercicio 3
					system("CLS");
					system("color 0A");
					printf("3) Escribir un programa que cree una matriz de 4*4 con números enteros y que imprima en pantalla:\n");
					printf("   La matriz\n");
					printf("   La suma de los elementos por columna\n\n\n");
					
					int mat[4][4],contcol=0,contfil=0,sumvert=0;
					contcol=0;
					contfil=0;
					//Algoritmo para insertar valores a la matriz
					do
					{
						do
						{
							printf("Otorga un número: ");
							scanf("%d",&mat[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<4);
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<4);
					//Algoritmo para mostrar la matriz
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							printf("[%d]   ",mat[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<4);
						printf("\n");
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<4);
					
					//Mostrar su suma
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							sumvert=sumvert+mat[contcol][contfil];
							contfil=contfil+1;
						}
						while(contfil<4);
						printf(" %d    ",sumvert);
						sumvert=0;
						contfil=0;
						contcol=contcol+1;
					}
					while(contcol<4);
					
					printf("\nPresiona \"ENTER\" para continuar\n");
					getchar();
					getchar();
				}
				break;
			case 4:
				{
					//Ejercicio 4
					system("CLS");
					system("color 0B");
					printf("4) Mulitplicación de una matriz de n x n por un escalar\n\n\n");
					
					int x=0,esc=0,contcol=0,contfil=0;
					printf("¿De qué tamaño quieres tu matriz? ");
					scanf("%d",&x);
					if(x>4)
					{
						printf("ADVERTENCIA: La cantidad que ha ingresado corresponde a llenar muchos valores que hará por su cuenta\n");
					}
					int mat[x][x],matesc[x][x];
					contcol=0;
					contfil=0;
					//Algoritmo para insertar valores a la matriz
					do
					{
						do
						{
							printf("Otorga un número: ");
							scanf("%d",&mat[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					printf("¿Por qué escalar quiere multiplicar su matriz? ");
					scanf("%d",&esc);
					printf("\n");
					//Multiplicaci�n por el escalar
					contfil=0;
					contcol=0;
					do
					{
						do
						{
							matesc[contcol][contfil]=mat[contcol][contfil]*esc;
							contcol=contcol+1;
						}
						while(contcol<x);
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					printf("Matriz Original:\n");
					//Algoritmo para mostrar la matriz
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							printf("[%d]   ",mat[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						printf("\n");
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					printf("\n\nMatriz Multiplicada por %d:\n",esc);
					//Algoritmo para mostrar la matriz
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							printf("[%d]   ",matesc[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						printf("\n");
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					
					
					printf("\nPresiona \"ENTER\" para continuar\n");
					getchar();
					getchar();
				}
				break;
			case 5:
				{
					//Ejercicio 5
					system("CLS");
					system("color 09");
					printf("5) Suma de dos matrices cuadradas\n\n\n");
					
					int x,contcol=0,contfil=0;
					printf("¿De qué tamaño quieres tu matriz? ");
					scanf("%d",&x);
					if(x>4)
					{
						printf("ADVERTENCIA: La cantidad que ha ingresado corresponde a llenar muchos valores que hará por su cuenta\n");
					}
					int mat1[x][x],mat2[x][x],summat[x][x];
					//Algoritmo para insertar valores a la matriz 1
					printf("Para la matriz 1:\n");
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							printf("Otorga un número: ");
							scanf("%d",&mat1[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					//Algoritmo para insertar valores a la matriz 2
					printf("Para la matriz 2:\n");
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							printf("Otorga un número: ");
							scanf("%d",&mat2[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					//Suma
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							summat[contcol][contfil]=mat1[contcol][contfil]+mat2[contcol][contfil];
							contcol=contcol+1;
						}
						while(contcol<x);
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					//Algoritmo para mostrar la matriz 1
					contcol=0;
					contfil=0;
					printf("Matriz 1:\n");
					do
					{
						do
						{
							printf("[%d]   ",mat1[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						printf("\n");
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					//Algoritmo para mostrar la matriz 2
					contcol=0;
					contfil=0;
					printf("\n\nMatriz 2:\n");
					do
					{
						do
						{
							printf("[%d]   ",mat2[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						printf("\n");
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					//Algoritmo para mostrar la suma de matrices
					contcol=0;
					contfil=0;
					printf("\n\nSuma de las Matrices:\n");
					do
					{
						do
						{
							printf("[%d]   ",summat[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						printf("\n");
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					
					printf("\nPresiona \"ENTER\" para continuar\n");
					getchar();
					getchar();
				}
				break;
			case 6:
				{
					//Ejercicio 6
					system("CLS");
					system("color 0D");
					printf("6) Ordenar una matriz de menor a mayor\n\n\n");
					
					//int x;
					
					printf("\nPrograma sin funcionamiento correcto\n");
					printf("\nPresiona \"ENTER\" para continuar\n");
					getchar();
					getchar();
				}
				break;
			case 7:
				{
					//Ejercicio 7
					system("CLS");
					system("color 0F");
					printf("7) Ordenar una matriz de mayor a menor\n\n\n");
					
					//int x;
					
					printf("\nPrograma sin funcionamiento correcto\n");
					printf("\nPresiona \"ENTER\" para continuar\n");
					getchar();
					getchar();
				}
				break;
			case 8:
				{
					//Ejercicio 8
					system("CLS");
					system("color 08");
					printf("8) Crear una matriz identidad (debe ser cuadrada)\n\n\n");
					
					int x,contcol=0,contfil=0,contextra=0,otro=0,z=0;
					printf("¿De qué tamaño quieres la matriz? ");
					scanf("%d",&x);
					int mat[x][x];
					//Algoritmo para llenar la matriz
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							if(contcol==contextra)
							{
								z=1;
							}
							else
							{
								z=0;
							}
							mat[contcol][contextra]=z;
							mat[contextra][contcol]=z;
							contcol=contcol+1;
						}
						while(contcol<x);
						contcol=0;
						contextra=contextra+1;
						contfil=contfil+1;
					}
					while(contfil<x);
					//Algoritmo para mostrar la matriz
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							printf("[%d]   ",mat[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						printf("\n");
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					
					printf("\nPresiona \"ENTER\" para continuar\n");
					getchar();
					getchar();
				}
				break;
			case 9:
				{
					//Ejercicio 9
					system("CLS");
					system("color 70");
					printf("9) Sumar 2 matrices\n\n\n");
					
					int x,contcol=0,contfil=0;
					printf("¿De qué tamaño quieres tu matriz? ");
					scanf("%d",&x);
					if(x>4)
					{
						printf("ADVERTENCIA: La cantidad que ha ingresado corresponde a llenar muchos valores que hará por su cuenta\n");
					}
					int mat1[x][x],mat2[x][x],summat[x][x];
					//Algoritmo para insertar valores a la matriz 1
					printf("Para la matriz 1:\n");
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							printf("Otorga un número: ");
							scanf("%d",&mat1[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					//Algoritmo para insertar valores a la matriz 2
					printf("Para la matriz 2:\n");
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							printf("Otorga un número: ");
							scanf("%d",&mat2[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					//Suma
					contcol=0;
					contfil=0;
					do
					{
						do
						{
							summat[contcol][contfil]=mat1[contcol][contfil]+mat2[contcol][contfil];
							contcol=contcol+1;
						}
						while(contcol<x);
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					//Algoritmo para mostrar la matriz 1
					contcol=0;
					contfil=0;
					printf("Matriz 1:\n");
					do
					{
						do
						{
							printf("[%d]   ",mat1[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						printf("\n");
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					//Algoritmo para mostrar la matriz 2
					contcol=0;
					contfil=0;
					printf("\n\nMatriz 2:\n");
					do
					{
						do
						{
							printf("[%d]   ",mat2[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						printf("\n");
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					//Algoritmo para mostrar la suma de matrices
					contcol=0;
					contfil=0;
					printf("\n\nSuma de las Matrices:\n");
					do
					{
						do
						{
							printf("[%d]   ",summat[contcol][contfil]);
							contcol=contcol+1;
						}
						while(contcol<x);
						printf("\n");
						contcol=0;
						contfil=contfil+1;
					}
					while(contfil<x);
					
					printf("\nPresiona \"ENTER\" para continuar\n");
					getchar();
					getchar();
				}
				break;
			case 10:
				{
					//Ejercicio 10
					system("CLS");
					system("color 71");
					printf("10) Multiplicar 2 matrices\n\n\n");
					
					/*int x1=0,x2=0,x3=0,x4=0,i=0,j=0,k=0,contcol=0,contfil=0;
					do
					{
						printf("\n¿De qué tamaño quieres tu matriz?\n");
						printf("PRIMERA MATRIZ Filas: ");
						scanf("%d",&x1);
						printf("\nPRIMERA MATRIZ Columnas: ");
						scanf("%d",&x2);
						printf("\nSEGUNDA MATRIZ Filas: ");
						scanf("%d",&x3);
						printf("\nSEGUNDA MATRIZ Columnas: ");
						scanf("%d",&x4);
						if (x2!=x3)
						{
							printf("\nRevisa los datos. Las columnas de la primera matriz deben ser iguales a las filas de la segunda");
						}
					}
					while(x2!=x3);
					int mat1[x1][x2],mat2[x3][x4],mat3[x1][x4];
					i=0;
					do
					{
						j=0;
						do
						{
							k=0;
							mat3[i][j]=0;
							do
							{
								mat3[i][j]=mat3[i][j]+(mat1[i][k]*mat2[k][j]);
								k=k+1;
							}
							while(k<x2);
							j=j+1;
						}
						while(j<x4);
						i=i+1;
					}
					while(i<x4);
					//Algoritmo para mostrar la matriz 1
					contcol=0;
					contfil=0;
					printf("\nMatriz 1:\n");
					do
					{
						do
						{
							printf("[%d]   ",mat1[contfil][contcol]);
							contfil=contfil+1;
						}
						while(contfil<x1);
						printf("\n");
						contfil=0;
						contcol=contcol+1;
					}
					while(contfil<x2);
					//Algoritmo para mostrar la matriz 1
					contcol=0;
					contfil=0;
					printf("\nMatriz 2:\n");
					do
					{
						do
						{
							printf("[%d]   ",mat2[contfil][contcol]);
							contfil=contfil+1;
						}
						while(contfil<x3);
						printf("\n");
						contfil=0;
						contcol=contcol+1;
					}
					while(contfil<x4);
					//Algoritmo para mostrar la matriz 1
					contcol=0;
					contfil=0;
					printf("\nMatriz 3:\n");
					do
					{
						do
						{
							printf("[%d]   ",mat3[contfil][contcol]);
							contfil=contfil+1;
						}
						while(contfil<x1);
						printf("\n");
						contfil=0;
						contcol=contcol+1;
					}
					while(contfil<x4);*/
					
					
					printf("\nPrograma sin funcionamiento correcto\n");
					printf("\nPresiona \"ENTER\" para continuar\n");
					getchar();
					getchar();
				}
				break;
			case 11:
				{
					//Salir
				}
				break;
		}
	}
	while(V<11);
}