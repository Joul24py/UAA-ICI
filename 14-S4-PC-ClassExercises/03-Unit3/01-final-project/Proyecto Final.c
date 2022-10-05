/*                    Universidad autónoma de Aguascalientes
                           Centro de Ciencias Básicas
                   Departamento de Ciencias de la Computación
                        Programación Científica
                      Joel Alejandro Espinoza Sánchez
                           Dariana Gómez Garza
					 Fernando Francisco González Arenas
                     Luis Fernando Guitiérrez Marfileño
			Descripción: Este programa tiene como intención resolver un sistema de ecuaciones al que se le
			proporcionan valores de un circuito dado que se encuentra en el documento del proyecto final.
			Este programa ofrece la oportunidad de calcular por medio de dos vías la solución a este sistema
			de ecuaciones. Uno por un método exacto y otro por un método iterativo
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int op;
float Vt,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10;

void SetValores();
void Cramer();
void GaussSeidel();
void SecretOption();

main()
{
	
	printf("\n-------------------------------------PROYECTO FINAL-------------------------------------\n");
	printf("\n------Solucion de Sistemas de Ecuaciones Lineales aplicadas a circuitos electricos------\n\n");
	
	do
	{
		printf("\n           MENU\n\n");
		printf("1.- Ejecutar la Regla de Cramer\n");
		printf("2.- Ejecutar el Metodo de Gauss-Seidel\n");
		printf("3.- Salir\n");
		printf("Ingrese una opcion: ");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:
				{
					SetValores();
					Cramer();
					printf("Presione ENTER para volver al menu\n");
					getchar();
					break;
				}
			case 2:
				{
					SetValores();
					GaussSeidel();
					printf("Presione ENTER para volver al menu\n");
					getchar();
					break;
				}
			case 3:
				{
					break;
				}
			case 18:
				{
					SetValores();
					SecretOption();
					printf("Presione ENTER para volver al menu\n");
					getchar();
					break;
				}
			default:
				{
					printf("Opcion Invalida\n");
					break;
				}
		}
		getchar();
		printf("\n\n\n\n");
	}
	while(op!=3);
}

void SetValores()
{
	int op1=0;
	Vt = 10;
	R1 = 1000;
	R2 = 3000;
	R3 = 2000;
	R4 = 1000;
	R5 = 3000;
	R6 = 2000;
	R7 = 1000;
	R8 = 3000;
	R9 = 2000;
	R10 = 1000;
	printf("\nLos valores por defecto del problema son los que se encuentran en la Figura 1\n");
	printf("del documento del proyecto, como puede observarse a continuacion:\n\n");
	
	do
	{
		printf("-------------------------------------\n");
		printf("| Opcion | Variable |    Valor \n");
		printf("|   1    |   V1     | %.3f Volts\n",Vt);
		printf("|   2    |   R1     | %.3f Ohms\n",R1);
		printf("|   3    |   R2     | %.3f Ohms\n",R2);
		printf("|   4    |   R3     | %.3f Ohms\n",R3);
		printf("|   5    |   R4     | %.3f Ohms\n",R4);
		printf("|   6    |   R5     | %.3f Ohms\n",R5);
		printf("|   7    |   R6     | %.3f Ohms\n",R6);
		printf("|   8    |   R7     | %.3f Ohms\n",R7);
		printf("|   9    |   R8     | %.3f Ohms\n",R8);
		printf("|   10   |   R9     | %.3f Ohms\n",R9);
		printf("|   11   |   R10    | %.3f Ohms\n",R10);
		printf("-------------------------------------\n\n");
		printf("Seleccione uno de los numeros al comienzo del renglon si quiere cambiar el valor del\n");
		printf("renglon correspondiente. De lo contrario, seleccione 0 para continuar con el programa:\n\n");
		scanf("%d",&op1);
		
		switch(op1)
		{
			case 1:
				{
					printf("Ingrese un nuevo valor para V1:\n");
					scanf("%f",&Vt);
					break;
				}
			case 2:
				{
					printf("Ingrese un nuevo valor para R1:\n");
					scanf("%f",&R1);
					break;
				}
			case 3:
				{
					printf("Ingrese un nuevo valor para R2:\n");
					scanf("%f",&R2);
					break;
				}
			case 4:
				{
					printf("Ingrese un nuevo valor para R3:\n");
					scanf("%f",&R3);
					break;
				}
			case 5:
				{
					printf("Ingrese un nuevo valor para R4:\n");
					scanf("%f",&R4);
					break;
				}
			case 6:
				{
					printf("Ingrese un nuevo valor para R5:\n");
					scanf("%f",&R5);
					break;
				}
			case 7:
				{
					printf("Ingrese un nuevo valor para R6:\n");
					scanf("%f",&R6);
					break;
				}
			case 8:
				{
					printf("Ingrese un nuevo valor para R7:\n");
					scanf("%f",&R7);
					break;
				}
			case 9:
				{
					printf("Ingrese un nuevo valor para R8:\n");
					scanf("%f",&R8);
					break;
				}
			case 10:
				{
					printf("Ingrese un nuevo valor para R9:\n");
					scanf("%f",&R9);
					break;
				}
			case 11:
				{
					printf("Ingrese un nuevo valor para R10:\n");
					scanf("%f",&R10);
					break;
				}
			default:
				{
					if(op1!=0)
					{
						printf("Opcion Invalida\n");
					}
					break;
				}
		}
	}
	while(op1!=0);
	return;
}

void Cramer()
{
	int i=0,j=0;
	float I1,I2,I3,I4,I5,I6,I7,I8,I9,I10,It,R23,R56,R89,Rt;
	float mat[10][10];
	float determinante;
    float determinante1;
    float determinante2;
    float determinante3;
    float x,y,z;
	printf("\n---------------REGLA DE CRAMER---------------\n\n");
	
	/*
	[R1 0  0] [V1]
	[ 0 R2 0] [V2]
	[ 0 0 R2] [V3]
	*/
	
	mat[0][0] = R1;
	mat[0][1] = 0;
	mat[0][2] = 0;
	mat[1][1] = R2;
	mat[1][0] = 0;
	mat[1][2] = 0;
	mat[2][2] = R3;
	mat[2][0] = 0;
	mat[2][1] = 0;
	
	R23 = 1/((1/R2)+(1/R3));
	R56 = 1/((1/R5)+(1/R6));
	R89 = 1/((1/R8)+(1/R9));
	Rt = R1 + R23 + R4 + R56 + R7 + R89 + R10;
	
	mat[0][3] = (Vt*R1)/Rt;
	mat[1][3] = (Vt*R23)/Rt;
	mat[2][3] = (Vt*R23)/Rt;
	
	/*printf("\nMatriz original:\n\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf(" %f ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	
	determinante=((mat[0][0]*mat[1][1]*mat[2][2])+(mat[0][1]*mat[1][2]*mat[2][0])+
	(mat[0][2]*mat[1][0]*mat[2][1]))-((mat[0][2]*mat[1][1]*mat[2][0])+(mat[0][0]*mat[1][2]*mat[2][1])+
	(mat[0][1]*mat[1][0]*mat[2][2]));
	
	determinante1=((mat[0][3]*mat[1][1]*mat[2][2])+(mat[0][1]*mat[1][2]*mat[2][3])+
	(mat[0][2]*mat[1][3]*mat[2][1]))-((mat[0][2]*mat[1][1]*mat[2][3])+(mat[0][3]*mat[1][2]*mat[2][1])+
	(mat[0][1]*mat[1][3]*mat[2][2]));
	
	determinante2=((mat[0][0]*mat[1][3]*mat[2][2])+(mat[0][3]*mat[1][2]*mat[2][0])+
	(mat[0][2]*mat[1][0]*mat[2][3]))-((mat[0][2]*mat[1][3]*mat[2][0])+(mat[0][0]*mat[1][2]*mat[2][3])+
	(mat[0][3]*mat[1][0]*mat[2][2]));
	
	determinante3=((mat[0][0]*mat[1][1]*mat[2][3])+(mat[0][1]*mat[1][3]*mat[2][0])+
	(mat[0][3]*mat[1][0]*mat[2][1]))-((mat[0][3]*mat[1][1]*mat[2][0])+(mat[0][0]*mat[1][3]*mat[2][1])+
	(mat[0][1]*mat[1][0]*mat[2][3]));
	
    printf("\nDeterminante original = %f",determinante);
	printf("\nDeterminante 1 = %f",determinante1);
	printf("\nDeterminante 2 = %f",determinante2);
	printf("\nDeterminante 3 = %f",determinante3);
	
	x=(determinante1)/(determinante);
	y=(determinante2)/(determinante);
	z=(determinante3)/(determinante);
	
	I1 = x;
	I2 = y;
	I3 = z;
	
	mat[0][0] = R4;
	mat[0][1] = 0;
	mat[0][2] = 0;
	mat[1][1] = R5;
	mat[1][0] = 0;
	mat[1][2] = 0;
	mat[2][2] = R6;
	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[0][3] = (Vt*R4)/Rt;
	mat[1][3] = (Vt*R56)/Rt;
	mat[2][3] = (Vt*R56)/Rt;
	
	/*printf("\nMatriz original:\n\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf(" %f ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	
	determinante=((mat[0][0]*mat[1][1]*mat[2][2])+(mat[0][1]*mat[1][2]*mat[2][0])+
	(mat[0][2]*mat[1][0]*mat[2][1]))-((mat[0][2]*mat[1][1]*mat[2][0])+(mat[0][0]*mat[1][2]*mat[2][1])+
	(mat[0][1]*mat[1][0]*mat[2][2]));
	
	determinante1=((mat[0][3]*mat[1][1]*mat[2][2])+(mat[0][1]*mat[1][2]*mat[2][3])+
	(mat[0][2]*mat[1][3]*mat[2][1]))-((mat[0][2]*mat[1][1]*mat[2][3])+(mat[0][3]*mat[1][2]*mat[2][1])+
	(mat[0][1]*mat[1][3]*mat[2][2]));
	
	determinante2=((mat[0][0]*mat[1][3]*mat[2][2])+(mat[0][3]*mat[1][2]*mat[2][0])+
	(mat[0][2]*mat[1][0]*mat[2][3]))-((mat[0][2]*mat[1][3]*mat[2][0])+(mat[0][0]*mat[1][2]*mat[2][3])+
	(mat[0][3]*mat[1][0]*mat[2][2]));
	
	determinante3=((mat[0][0]*mat[1][1]*mat[2][3])+(mat[0][1]*mat[1][3]*mat[2][0])+
	(mat[0][3]*mat[1][0]*mat[2][1]))-((mat[0][3]*mat[1][1]*mat[2][0])+(mat[0][0]*mat[1][3]*mat[2][1])+
	(mat[0][1]*mat[1][0]*mat[2][3]));
	
    printf("\nDeterminante 4 = %f",determinante1);
	printf("\nDeterminante 5 = %f",determinante2);
	printf("\nDeterminante 6 = %f",determinante3);
	
	x=(determinante1)/(determinante);
	y=(determinante2)/(determinante);
	z=(determinante3)/(determinante);
	
	I4 = x;
	I5 = y;
	I6 = z;
	
	mat[0][0] = R7;
	mat[0][1] = 0;
	mat[0][2] = 0;
	mat[1][1] = R8;
	mat[1][0] = 0;
	mat[1][2] = 0;
	mat[2][2] = R9;
	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[0][3] = (Vt*R7)/Rt;
	mat[1][3] = (Vt*R89)/Rt;
	mat[2][3] = (Vt*R89)/Rt;
	
	/*printf("\nMatriz original:\n\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf(" %f ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	
	determinante=((mat[0][0]*mat[1][1]*mat[2][2])+(mat[0][1]*mat[1][2]*mat[2][0])+
	(mat[0][2]*mat[1][0]*mat[2][1]))-((mat[0][2]*mat[1][1]*mat[2][0])+(mat[0][0]*mat[1][2]*mat[2][1])+
	(mat[0][1]*mat[1][0]*mat[2][2]));
	
	determinante1=((mat[0][3]*mat[1][1]*mat[2][2])+(mat[0][1]*mat[1][2]*mat[2][3])+
	(mat[0][2]*mat[1][3]*mat[2][1]))-((mat[0][2]*mat[1][1]*mat[2][3])+(mat[0][3]*mat[1][2]*mat[2][1])+
	(mat[0][1]*mat[1][3]*mat[2][2]));
	
	determinante2=((mat[0][0]*mat[1][3]*mat[2][2])+(mat[0][3]*mat[1][2]*mat[2][0])+
	(mat[0][2]*mat[1][0]*mat[2][3]))-((mat[0][2]*mat[1][3]*mat[2][0])+(mat[0][0]*mat[1][2]*mat[2][3])+
	(mat[0][3]*mat[1][0]*mat[2][2]));
	
	determinante3=((mat[0][0]*mat[1][1]*mat[2][3])+(mat[0][1]*mat[1][3]*mat[2][0])+
	(mat[0][3]*mat[1][0]*mat[2][1]))-((mat[0][3]*mat[1][1]*mat[2][0])+(mat[0][0]*mat[1][3]*mat[2][1])+
	(mat[0][1]*mat[1][0]*mat[2][3]));
	
    printf("\nDeterminante 7 = %f",determinante1);
	printf("\nDeterminante 8 = %f",determinante2);
	printf("\nDeterminante 9 = %f",determinante3);
	
	x=(determinante1)/(determinante);
	y=(determinante2)/(determinante);
	z=(determinante3)/(determinante);
	
	I7 = x;
	I8 = y;
	I9 = z;
	
	mat[0][0] = R10;
	mat[0][1] = 0;
	mat[0][2] = 0;
	mat[1][1] = R8;
	mat[1][0] = 0;
	mat[1][2] = 0;
	mat[2][2] = R9;
	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[0][3] = (Vt*R10)/Rt;
	mat[1][3] = (Vt*R89)/Rt;
	mat[2][3] = (Vt*R89)/Rt;
	
	/*printf("\nMatriz original:\n\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf(" %f ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	
	determinante=((mat[0][0]*mat[1][1]*mat[2][2])+(mat[0][1]*mat[1][2]*mat[2][0])+
	(mat[0][2]*mat[1][0]*mat[2][1]))-((mat[0][2]*mat[1][1]*mat[2][0])+(mat[0][0]*mat[1][2]*mat[2][1])+
	(mat[0][1]*mat[1][0]*mat[2][2]));
	
	determinante1=((mat[0][3]*mat[1][1]*mat[2][2])+(mat[0][1]*mat[1][2]*mat[2][3])+
	(mat[0][2]*mat[1][3]*mat[2][1]))-((mat[0][2]*mat[1][1]*mat[2][3])+(mat[0][3]*mat[1][2]*mat[2][1])+
	(mat[0][1]*mat[1][3]*mat[2][2]));
	
	determinante2=((mat[0][0]*mat[1][3]*mat[2][2])+(mat[0][3]*mat[1][2]*mat[2][0])+
	(mat[0][2]*mat[1][0]*mat[2][3]))-((mat[0][2]*mat[1][3]*mat[2][0])+(mat[0][0]*mat[1][2]*mat[2][3])+
	(mat[0][3]*mat[1][0]*mat[2][2]));
	
	determinante3=((mat[0][0]*mat[1][1]*mat[2][3])+(mat[0][1]*mat[1][3]*mat[2][0])+
	(mat[0][3]*mat[1][0]*mat[2][1]))-((mat[0][3]*mat[1][1]*mat[2][0])+(mat[0][0]*mat[1][3]*mat[2][1])+
	(mat[0][1]*mat[1][0]*mat[2][3]));
	
    printf("\nDeterminante 10 = %f\n\n",determinante1);
	
	x=(determinante1)/(determinante);
	y=(determinante2)/(determinante);
	z=(determinante3)/(determinante);
	
	I10 = x;
	
	
	printf("Valores de las intensidades en cada resistencia:\n\n");
	printf("----------------------------------\n");
	printf("| Resistencia |    Intensidad\n");
	printf("|      1      | %0.6f Amperes\n",I1);
	printf("|      2      | %0.6f Amperes\n",I2);
	printf("|      3      | %0.6f Amperes\n",I3);
	printf("|      4      | %0.6f Amperes\n",I4);
	printf("|      5      | %0.6f Amperes\n",I5);
	printf("|      6      | %0.6f Amperes\n",I6);
	printf("|      7      | %0.6f Amperes\n",I7);
	printf("|      8      | %0.6f Amperes\n",I8);
	printf("|      9      | %0.6f Amperes\n",I9);
	printf("|      10     | %0.6f Amperes\n",I10);
	printf("----------------------------------\n\n");
	return;
}

void GaussSeidel()
{
	int a,b,c,d,dim=10,e=0,i,j;
	float I1,I2,I3,I4,I5,I6,I7,I8,I9,I10,It,R23,R56,R89,Rt;
	printf("\n---------------METODO DE GAUSS-SEIDEL (CAMBIO A GAUSS-JORDAN)---------------\n\n");
	
	R23 = 1/((1/R2)+(1/R3));
	R56 = 1/((1/R5)+(1/R6));
	R89 = 1/((1/R8)+(1/R9));
	Rt = R1 + R23 + R4 + R56 + R7 + R89 + R10;
	
	float mat[10][11] =
	{
		{R1, 0, 0, 0, 0, 0, 0, 0, 0, 0, (Vt*R1)/Rt},
		{0, R2, 0, 0, 0, 0, 0, 0, 0, 0, (Vt*R23)/Rt},
		{0, 0, R3, 0, 0, 0, 0, 0, 0, 0, (Vt*R23)/Rt},
		{0, 0, 0, R4, 0, 0, 0, 0, 0, 0, (Vt*R4)/Rt},
		{0, 0, 0, 0, R5, 0, 0, 0, 0, 0, (Vt*R56)/Rt},
		{0, 0, 0, 0, 0, R6, 0, 0, 0, 0, (Vt*R56)/Rt},
		{0, 0, 0, 0, 0, 0, R7, 0, 0, 0, (Vt*R7)/Rt},
		{0, 0, 0, 0, 0, 0, 0, R8, 0, 0, (Vt*R89)/Rt},
		{0, 0, 0, 0, 0, 0, 0, 0, R9, 0, (Vt*R89)/Rt},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, R10, (Vt*R10)/Rt},
	};
	
	printf("La matriz reducida a Gauss Jordan:\n");
	for(i=0;i<dim;i++)
	{
		for(j=0;j<=dim;j++)
		{
			printf("[%f] ",mat[i][j]);
		}
		printf("\n");
	}
	
	float res[dim];
	
	b=0;
	for(a=dim-1;a>=0;a--)
	{
		c=b;
		while(c!=0)
		{
			mat[a][dim]=mat[a][dim]-(mat[a][dim-c]*res[dim-c]);
			c--;
		}
		b++;
		res[a]=mat[a][dim]/mat[a][a];
	}
	
	I1 = res[0];
	I2 = res[1];
	I3 = res[2];
	I4 = res[3];
	I5 = res[4];
	I6 = res[5];
	I7 = res[6];
	I8 = res[7];
	I9 = res[8];
	I10 = res[9];
	
	
	printf("Valores de las intensidades en cada resistencia:\n\n");
	printf("----------------------------------\n");
	printf("| Resistencia |    Intensidad\n");
	printf("|      1      | %0.6f Amperes\n",I1);
	printf("|      2      | %0.6f Amperes\n",I2);
	printf("|      3      | %0.6f Amperes\n",I3);
	printf("|      4      | %0.6f Amperes\n",I4);
	printf("|      5      | %0.6f Amperes\n",I5);
	printf("|      6      | %0.6f Amperes\n",I6);
	printf("|      7      | %0.6f Amperes\n",I7);
	printf("|      8      | %0.6f Amperes\n",I8);
	printf("|      9      | %0.6f Amperes\n",I9);
	printf("|      10     | %0.6f Amperes\n",I10);
	printf("----------------------------------\n\n");
	return;
}

void SecretOption()
{
	float I1,I2,I3,I4,I5,I6,I7,I8,I9,I10,It,R23,R56,R89,Rt,V23,V56,V89;
	printf("\n---------------OPCION SECRETA---------------\n\n");
	
	R23 = 1/((1/R2)+(1/R3));
	R56 = 1/((1/R5)+(1/R6));
	R89 = 1/((1/R8)+(1/R9));
	Rt = R1 + R23 + R4 + R56 + R7 + R89 + R10;
	It = Vt/Rt;
	I1 = It;
	I4 = It;
	I7 = It;
	I10 = It;
	V23 = R23*It;
	I2 = V23/R2;
	I3 = V23/R3;
	V56 = R56*It;
	I5 = V56/R5;
	I6 = V56/R6;
	V89 = R89*It;
	I8 = V89/R8;
	I9 = V89/R9;
	
	printf("Valores de las intensidades en cada resistencia:\n\n");
	printf("----------------------------------\n");
	printf("| Resistencia |    Intensidad\n");
	printf("|      1      | %0.6f Amperes\n",I1);
	printf("|      2      | %0.6f Amperes\n",I2);
	printf("|      3      | %0.6f Amperes\n",I3);
	printf("|      4      | %0.6f Amperes\n",I4);
	printf("|      5      | %0.6f Amperes\n",I5);
	printf("|      6      | %0.6f Amperes\n",I6);
	printf("|      7      | %0.6f Amperes\n",I7);
	printf("|      8      | %0.6f Amperes\n",I8);
	printf("|      9      | %0.6f Amperes\n",I9);
	printf("|      10     | %0.6f Amperes\n",I10);
	printf("----------------------------------\n\n");
	return;
}
