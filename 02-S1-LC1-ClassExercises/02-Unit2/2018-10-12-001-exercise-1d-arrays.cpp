#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

main()
{
	setlocale(LC_ALL, "");
	
	
	printf("\nEjercicios de Vectores\n");
	printf("Por Joel Alejandro Espinoza Sánchez\n");
	printf("\n\nPresione \"Enter\" para continuar");
	getchar();
	
	int V=0;
	do
	{
		system("CLS");
		system("color C0");
		printf("Ejercicios de Vectores: Elija qué ejercicio desea ejecutar\n");
		printf("\n1) Escribir un programa que pida 10 números enteros por teclado y que imprima por pantalla:\n");
		printf("    a) Cuántos de esos on pares\n");
		printf("    b) Cuál es el valor del número máximo\n");
		printf("    c) Cuál es el valor del número mínimo\n");
		printf("2) Escribir un programa que lea 10 número por teclado\n");
		printf("   Luego lea dos más e indique si éstos están entre los anteriores e indicar en qué posición se encuentran\n");
		printf("3) Leer un vector de 10 elementos enteros y ordenarlo de menor a mayor\n");
		printf("4) Leer un vector de 10 elementos enteros y ordenarlo de mayor a menor\n");
		printf("5) Leer 10 números enteros, guardarlos en un vector, elevarlos al cuadrado y guardar el resultado en otro vector\n");
		printf("   Al final, imprimir los dos vectores\n");
		printf("6) Leer 8 numero enteros, guardarlos en un vector, multiplicarlos por 2 y guardar el resultado en otro vector\n");
		printf("   Al final, imprimir los dos vectores\n");
		printf("7) Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en otro vector\n");
		printf("   Sumarlos y el resultado guardarlo en otro vector\n");
		printf("8) Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en otro vector\n");
		printf("   Restarlos y el resultado guardarlo en otro vector\n");
		printf("9) Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en otro vector\n");
		printf("   Multiplicarlos y el resultado guardarlo en otro vector\n");
		printf("10) Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en otro vector\n");
		printf("   Dividirlos y el resultado guardarlo en otro vector\n");
		printf("11) Salir\n");
		scanf("%d",&V);
		
		switch(V)
		{
			case 1:
				{
					//Ejercicio 1
					system("CLS");
					system("color 0C");
					printf("1) Escribir un programa que pida 10 números enteros por teclado y que imprima por pantalla:\n");
					printf("    a) Cuántos de esos on pares\n");
					printf("    b) Cuál es el valor del número máximo\n");
					printf("    c) Cuál es el valor del número mínimo\n\n\n");
					
					int vec[10],cont=0,par=0,may=0,men=10000000;
					
					while(cont<10)
						{
							printf("Otorga el número %d\n",cont+1);
							scanf("%d",&
							vec[cont]);
							if(vec[cont]%2==0)
							{
								par=par+1;
							}
							if(may<vec[cont])
							{
								may=vec[cont];
							}
							if(men>vec[cont])
							{
								men=vec[cont];
							}
							cont=cont+1;
						}
					printf("De los números otorgados, existen %d pares\n",par);
					printf("El número mayor es %d\n",may);
					printf("El número menor es %d",men);
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
					printf("2) Escribir un programa que lea 10 números por teclado\n");
					printf("   Luego lea dos más e indique si éstos están entre los anteriores e indicar en qué posición se encuentran\n\n\n");
					
					int vec[10],cont1=0,num1=0,num2=0,verif1=0,verif2=0;
					do
					{
						printf("Escribe el número %d\n",cont1+1);
						scanf("%d",&vec[cont1]);
						cont1=cont1+1;
					}
					while(cont1<10);
					printf("Escribe algún número y ver si se encuentra en los valores dados previamente\n");
					scanf("%d",&num1);
					printf("Escribe otro número\n");
					scanf("%d",&num2);
					cont1=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",vec[cont1]);
						cont1=cont1+1;
					}
					while(cont1<10);
					cont1=0;
					printf("\n\n");
					do
					{
						if(num1==vec[cont1])
						{
							printf("El número %d se encuentra en la posición %d de los valores dados\n",num1,cont1+1);
							verif1=verif1+1;
						}
						if(num2==vec[cont1])
						{
							printf("El número %d se encuentra en la posición %d de los valores dados\n",num2,cont1+1);
							verif2=verif2+1;
						}
						cont1=cont1+1;
					}
					while(cont1<10);
					if(verif1<1)
					{
						printf("El número %d no se encuentra en los valores dados\n",num1);
					}
					if(verif2<1)
					{
						printf("El número %d no se encuentra en los valores dados\n",num2);
					}
					
					
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
					printf("3) Leer un vector de 10 elementos enteros y ordenarlo de menor a mayor\n\n\n");
					
					int vecin[10],vecord[10],cont=0,A=0;
					do
					{
						printf("Escribe el número %d\n",cont+1);
						scanf("%d",&vecin[cont]);
						cont=cont+1;
					}
					while(cont<10);
					cont=0;
					do
					{
						if(vecin[cont]>vecin[cont+1])
						{
							A=vecin[cont+1];
							vecin[cont+1]=vecin[cont];
							vecin[cont]=A;
							cont=-1;
						}
						cont=cont+1;
					}
					while(cont<9);
					cont=0;
					do
					{
						printf("[%d] ",vecin[cont]);
						cont=cont+1;
					}
					while(cont<10);
					
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
					printf("4) Leer un vector de 10 elementos enteros y ordenarlo de mayor a menor\n\n\n");
					
					int vecin[10],vecord[10],cont=0,A=0;
					do
					{
						printf("Escribe el número %d\n",cont+1);
						scanf("%d",&vecin[cont]);
						cont=cont+1;
					}
					while(cont<10);
					cont=0;
					do
					{
						if(vecin[cont]<vecin[cont+1])
						{
							A=vecin[cont+1];
							vecin[cont+1]=vecin[cont];
							vecin[cont]=A;
							cont=-1;
						}
						cont=cont+1;
					}
					while(cont<9);
					cont=0;
					do
					{
						printf("[%d] ",vecin[cont]);
						cont=cont+1;
					}
					while(cont<10);
					
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
					printf("5) Leer 10 números enteros, guardarlos en un vector, elevarlos al cuadrado y guardar el resultado en otro vector\n");
					printf("   Al final, imprimir los dos vectores\n\n\n");
					
					int vec[10],veccuad[10],cont=0;
					do
					{
						printf("Escribe el número %d\n",cont+1);
						scanf("%d",&vec[cont]);
						cont=cont+1;
					}
					while(cont<10);
					cont=0;
					do
					{
						veccuad[cont]=vec[cont]*vec[cont];
						cont=cont+1;
					}
					while(cont<10);
					cont=0;
					do
					{
						printf("[ %d ]    ",vec[cont]);
						cont=cont+1;
					}
					while(cont<10);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",veccuad[cont]);
						cont=cont+1;
					}
					while(cont<10);
					
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
					printf("6) Leer 8 números enteros, guardarlos en un vector, multiplicarlos por 2 y guardar el resultado en otro vector\n");
					printf("   Al final, imprimir los dos vectores\n\n\n");
					
					int vec[8],veccuad[8],cont=0;
					do
					{
						printf("Escribe el número %d\n",cont+1);
						scanf("%d",&vec[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					do
					{
						veccuad[cont]=vec[cont]*2;
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					do
					{
						printf("[ %d ]    ",vec[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",veccuad[cont]);
						cont=cont+1;
					}
					while(cont<8);
					
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
					printf("7) Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en otro vector\n");
					printf("   Sumarlos y el resultado guardarlo en otro vector\n\n\n");
					
					int vec1[8],vec2[8],vec3[8],cont=0;
					printf("VECTOR 1:\n");
					do
					{
						printf("Escribe el número %d\n",cont+1);
						scanf("%d",&vec1[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("VECTOR 2:\n");
					do
					{
						printf("Escribe el número %d\n",cont+1);
						scanf("%d",&vec2[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					do
					{
						vec3[cont]=vec1[cont]+vec2[cont];
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",vec1[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",vec2[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",vec3[cont]);
						cont=cont+1;
					}
					while(cont<8);
					
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
					printf("8) Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en otro vector\n");
					printf("   Restarlos y el resultado guardarlo en otro vector\n\n\n");
					
					int vec1[8],vec2[8],vec3[8],cont=0;
					printf("VECTOR 1:\n");
					do
					{
						printf("Escribe el número %d\n",cont+1);
						scanf("%d",&vec1[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("VECTOR 2:\n");
					do
					{
						printf("Escribe el número %d\n",cont+1);
						scanf("%d",&vec2[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					do
					{
						vec3[cont]=vec1[cont]-vec2[cont];
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",vec1[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",vec2[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",vec3[cont]);
						cont=cont+1;
					}
					while(cont<8);
					
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
					printf("9) Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en otro vector\n");
					printf("   Multiplicarlos y el resultado guardarlo en otro vector\n\n\n");
					
					int vec1[8],vec2[8],vec3[8],cont=0;
					printf("VECTOR 1:\n");
					do
					{
						printf("Escribe el número %d\n",cont+1);
						scanf("%d",&vec1[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("VECTOR 2:\n");
					do
					{
						printf("Escribe el número %d\n",cont+1);
						scanf("%d",&vec2[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					do
					{
						vec3[cont]=vec1[cont]*vec2[cont];
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",vec1[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",vec2[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",vec3[cont]);
						cont=cont+1;
					}
					while(cont<8);
					
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
					printf("10) Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en otro vector\n");
					printf("   Dividirlos y el resultado guardarlo en otro vector\n\n\n");
					
					int vec1[8],vec2[8],vec3[8],cont=0;
					printf("VECTOR 1:\n");
					do
					{
						printf("Escribe el número %d\n",cont+1);
						scanf("%d",&vec1[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("VECTOR 2:\n");
					do
					{
						printf("Escribe el número %d\n",cont+1);
						scanf("%d",&vec2[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					do
					{
						vec3[cont]=vec1[cont]/vec2[cont];
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",vec1[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",vec2[cont]);
						cont=cont+1;
					}
					while(cont<8);
					cont=0;
					printf("\n");
					do
					{
						printf("[ %d ]    ",vec3[cont]);
						cont=cont+1;
					}
					while(cont<8);
					
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