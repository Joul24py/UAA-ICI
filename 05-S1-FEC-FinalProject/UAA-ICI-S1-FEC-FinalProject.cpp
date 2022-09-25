#include <stdio.h>
#include <stdlib.h>
#include <locale.h>	
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <conio.h>

/*
PROYECTO FINAL
Desarrollar un Menú con las Siguientes Opciones:
1) Sistemas Numéricos (Tener un menú con varias opciones)
2) Grafos
3) Lógica Proposicional (Pedir una expresión y generar su tabla de verdad)
4) Matriz de Incidencia y Adyacencia
5) Salir

Equipo: César, Joul, David, Choche y Zúñiga
Fecha de Entrega: ???

Autores:
		Cardona Rivera José Luis
		Espinoza Sánchez Joel Alejandro
		Pardo Tinoco Jonathan David
		Pérez Jaime Julio César
		Zúñiga Elizondo Carlos Martín
*/

char dA[25][25];
int df, dc, di, dj, dciudades, dac, dres, dopcion, dx, dy, da, db, dfin=0;
void Reiniciar();
void Asignar();
void Unir();
void Unir2();
void Imprimir();

main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	
	//Menú Principal
	int menu=0, repetir=3;
	do
	{
		do
		{
			system("CLS");
			printf("Elija una opción:\n");
			printf("1) Sistemas Numéricos\n");
			printf("2) Grafos\n");
			printf("3) Lógica Proposicional\n");
			printf("4) Generación de Matriz de Incidencia y Adyacencia\n");
			printf("5) Salir del programa\n");
			scanf("%d",&menu);
			
			if(menu<1||menu>5)
			{
				printf("\n Tu opción no es válida, por favor ingresa un número correcto");
			}
		}
		while(menu<1||menu>5);
		
		switch (menu)
		{
			case 1:
				{
					do
					{
						//1.- Sistemas Numéricos
						system("CLS");
						int num=0,opc=0,mod=0,div=0,result=0,vector[21];
						
						printf("Has escogido la opción: Sistemas Numéricos\n");
						printf("\n¿A qué sistema lo quieres convertir?");
						printf("\n1) Binario");
						printf("\n2) Octal");
						printf("\n3) Hexadecimal");
						printf("\n4) Maya");
						printf("\n5) Selección libre de base cualquiera entre 2 y 16");
						//printf("\n6) A la inversa: Convertir de alguna base (Binario, Octal, Hexadecimal) a Decimal\n");
						scanf("%d",&opc);
						switch (opc)
						{
							case 1:
								{
									int num=0,opc=0,mod=0,divs=0,result=0,vector[21],i=0,j=0;
									
									printf("Otorga un número no mayor que 2,097,151\n");
									scanf("%d",&num);
									printf("\n");
									
									do
									{
										divs=num/2;
										mod=num % 2;
										vector[i]=mod;
										i=i+1;
										num=divs;
										if(num==1)
										{
											vector[i]=1;
										}
									}
								while(num>1);
									do
									{
										printf("%d",vector[i]);
										i=i-1;
									}
									while(i>=0);
									
									printf("\n");
									printf("\n");
									printf("\n");
									printf("\n");
									printf("Proceso terminado\n");
									printf("¿Qué desea hacer ahora?\n");
									printf("1) Volver al menú principal\n");
									printf("2) Repetir este proceso (Sistemas Numéricos)\n");
									printf("3) Salir\n");
									scanf("%d",&repetir);
									break;
								}
							case 2:
								{
									int num=0,opc=0,mod=0,divs=0,result=0,vector[21],i=0,j=0;
									
									printf("Otorga un número no mayor que 2,097,151\n");
									scanf("%d",&num);
									printf("\n");
									
									do
									{
										divs=num/8;
										mod=num % 8;
										vector[i]=mod;
										i=i+1;
										num=divs;
										if(num==1)
										{
											vector[i]=1;
										}
									}
									while(num>1);
									do
									{
										printf("%d",vector[i]);
										i=i-1;
									}
									while(i>=0);
									
									printf("\n");
									printf("\n");
									printf("\n");
									printf("\n");
									printf("Proceso terminado\n");
									printf("¿Qué desea hacer ahora?\n");
									printf("1) Volver al menú principal\n");
									printf("2) Repetir este proceso (Sistemas Numéricos)\n");
									printf("3) Salir\n");
									scanf("%d",&repetir);
									break;
								}
							case 3:
								{
									int num=0,opc=0,mod=0,divs=0,result=0,vector[21],i=0,j=0;
									
									printf("Otorga un número no mayor que 2,097,151\n");
									scanf("%d",&num);
									printf("\n");
									
									do
									{
										divs=num/16;
										mod=num % 16;
										vector[i]=mod;
										i=i+1;
										num=divs;
										if(num==1)
										{
											vector[i]=1;
										}
									}
									while(num>1);
									do{
										switch(vector[i]){
											case 10:
												printf("A");
												i=i-1;
												break;
											case 11:
												printf("B");
												i=i-1;
												break;
											case 12:
												printf("C");
												i=i-1;
												break;
											case 13:
												printf("D");
												i=i-1;
												break;
											case 14:
												printf("F");
												i=i-1;
												break;
											case 15:
												printf("E");
												i=i-1;
												break;
											default:
												printf("%d",vector[i]);
												i=i-1;
												break;
										}
										
									}while(i>=0);
									
									printf("\n");
									printf("\n");
									printf("\n");
									printf("\n");
									printf("Proceso terminado\n");
									printf("¿Qué desea hacer ahora?\n");
									printf("1) Volver al menú principal\n");
									printf("2) Repetir este proceso (Sistemas Numéricos)\n");
									printf("3) Salir\n");
									scanf("%d",&repetir);
									break;
								}
							case 4:
								{
									int num=0,pot=7,verif1=0,verif2=0,prod=0,rest=0,i=0,asig=0,vector[8];
									char mun;
									//Graficos de numero maya
										char cero[] = "| © |", uno[] = "|*   |", dos[]="|**  |", tres[] = "|*** |", cuatro[] = "|****|", cinco[] = "|----|";
										char seis[] = "|*   |\n|----|", siete[] = "|**  |\n|----|", ocho[] ="|*** |\n|----|", nueve[] = "|****|\n|----|", diez[] = "|----|\n|----|";
										char once[] = "|*   |\n|----|\n|----|", doce[] = "|**  |\n|----|\n|----|", trece[] = "|*** |\n|----|\n|----|", catorce[] = "|****|\n|----|\n|----|", quince[] = "|----|\n|----|\n|----|";
										char dieciseis[] = "|*   |\n|----|\n|----|\n|----|", diecisiete[] ="|**  |\n|----|\n|----|\n|----|", dieciocho[] = "|*** |\n|----|\n|----|\n|----|", diecinueve[] = "|****|\n|----|\n|----|\n|----|";
									
									printf("Otorga un número no mayor que 1,279,999,999\n");
									scanf("%d",&num);
									printf("\n");
									
									pot=7;
									do
									{
										verif1=num/(pow(20,pot));
										if(verif1>=1)
										{
											verif2=verif2+1;
										}
										else
										{
											pot=pot-1;
										}
									}
									while(verif2<1);
									
									//Impresion del numero (De querer mostrarlo en maya y en numeros normales quitar las dos diagonales de ambos comentarios)
									i=0;
									do
									{
										prod=num/(pow(20,pot));
										vector[i]=prod; //Numeros normales
										asig=prod;
										if(asig==0){
										printf( "%s", cero);
										}
											else if (asig==1){
												printf("%s", uno);
											}
											else if (asig==2){
												printf("%s", dos);
											}
											else if (asig==3){
												printf("%s", tres);
											}
											else if (asig==4){
												printf("%s", cuatro);
											}
											else if (asig==5){
												printf("%s", cinco);
											}
											else if (asig==6){
												printf("%s", seis);
											}
											else if (asig==7){
												printf("%s", siete);
											}
											else if (asig==8){
												printf("%s", ocho);
											}
											else if (asig==9){
												printf("%s", nueve);
											}
											else if (asig==10){
												printf("%s", diez);
											}
											else if (asig==11){
												printf("%s", once);
											}
											else if (asig==12){
												printf("%s", doce);
											}
											else if (asig==13){
												printf("%s", trece);
											}
											else if (asig==14){
												printf("%s", catorce);
											}
											else if (asig==15){
												printf("%s", quince);
											}
											else if (asig==16){
												printf("%s", dieciseis);
											}
											else if (asig==17){
												printf("%s", diecisiete);
											}
											else if (asig==18){
												printf("%s", dieciocho);
											}
											else if (asig==19){
												printf("%s", diecinueve);
											}	
										printf("%d\n",vector[i]); //Numeros normales
										rest=(pow(20,pot))*prod;
										num=num-rest;
										pot=pot-1;
										i=i+1;//Numeros normales
										printf("\n\n");
									} while(pot>=0);
									
									printf("\n");
									printf("\n");
									printf("\n");
									printf("\n");
									printf("Proceso terminado\n");
									printf("¿Qué desea hacer ahora?\n");
									printf("1) Volver al menú principal\n");
									printf("2) Repetir este proceso (Sistemas Numéricos)\n");
									printf("3) Salir\n");
									scanf("%d",&repetir);
									break;
								}
							case 5:
								{
									int a=0,b=0,c=0,m=0,t=0, divs=0, mod=0, num=0, vector[21];
									char A[100];
								    char Aux[2];
								    int  i=0, Error;
								    int my=0,r=0;
								    int vec[10];
								    
								    while(t!=1){
									system("cls");
									printf("Elije que base tiene el numero que quieres covertir a decimal");
									printf("\n1) Binario");
									printf("\n2) Tres");
									printf("\n3) Cuatro");
									printf("\n4) Cinco");
									printf("\n5) Seis");
									printf("\n6) Siete");
									printf("\n7) Ocho");
									printf("\n8) Nueve");
									printf("\n9) Once");
									printf("\n10) Doce");
									printf("\n11) Trece");
									printf("\n12) Catorce");
									printf("\n13) Quince");
									printf("\n14) Hexadecimal");
									printf("\n15) Salir\n");
									scanf("%i",&m);
									a=0;
									b=0;
									c=0;
									system("cls");
									switch(m){
										case 1:{
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											while(a!=0){
												b=b+(a%2)*pow(10,c++);
												a=a/2;
											}
											printf("\nEl resultado es: %i\n",b);
											break;
										}
										case 2:{
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											while(a!=0){
												b=b+(a%3)*pow(10,c++);
												a=a/3;
											}
											printf("\nEl resultado es: %i\n",b);
											break;
										}
										case 3:{
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											while(a!=0){
												b=b+(a%4)*pow(10,c++);
												a=a/4;
											}
											printf("\nEl resultado es: %i\n",b);
											break;
										}
										case 4:{
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											while(a!=0){
												b=b+(a%5)*pow(10,c++);
												a=a/5;
											}
											printf("\nEl resultado es: %i\n",b);
											break;
										}
										case 5:{
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											while(a!=0){
												b=b+(a%6)*pow(10,c++);
												a=a/6;
											}
											printf("\nEl resultado es: %i\n",b);
											break;
										}
										case 6:{
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											while(a!=0){
												b=b+(a%7)*pow(10,c++);
												a=a/7;
											}
											printf("\nEl resultado es: %i\n",b);
											break;
										}
										case 7:{
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											while(a!=0){
												b=b+(a%8)*pow(10,c++);
												a=a/8;
											}
											printf("\nEl resultado es: %i\n",b);
											break;
										}
										case 8:{
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											while(a!=0){
												b=b+(a%9)*pow(10,c++);
												a=a/9;
											}
											printf("\nEl resultado es: %i\n",b);
											break;
										}
										case 9:{
											i=0;
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											do{
											divs=a/11;
									        mod=a % 11;
									        vector[i]=mod;
									        i=i+1;
									        a=divs;
									        if(a==1)
									        {
										    vector[i]=1;
									        }
									        }while(a>1);
									        printf("El resultado es: ");
									        do{
									        	switch(vector[i]){
										    case 10:
											   printf("A");
											   i=i-1;
											   break;
										    default:
											   printf("%d",vector[i]);
											   i=i-1;
											   break;
										       }
											}while(i>=0);
											printf("\n");
											break;
									    }
										case 10:{
											i=0;
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											do{
											divs=a/12;
									        mod=a % 12;
									        vector[i]=mod;
									        i=i+1;
									        a=divs;
									        if(a==1)
									        {
										    vector[i]=1;
									        }
									        }while(a>1);
									        printf("El resultado es: ");
									        do{
									        	switch(vector[i]){
										    case 10:
											   printf("A");
											   i=i-1;
											   break;
										    case 11:
											   printf("B");
											   i=i-1;
											   break;
										    default:
											   printf("%d",vector[i]);
											   i=i-1;
											   break;
										     }
											}while(i>=0);
											printf("\n");
											break;
										}
										case 11:{
											i=0;
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											do{
											divs=a/13;
									        mod=a % 13;
									        vector[i]=mod;
									        i=i+1;
									        a=divs;
									        if(a==1)
									        {
										    vector[i]=1;
									        }
									        }while(a>1);
									        printf("El resultado es: ");
									        do{
									        	switch(vector[i]){
										    case 10:
											   printf("A");
											   i=i-1;
											   break;
										    case 11:
											   printf("B");
											   i=i-1;
											   break;
										    case 12:
											   printf("C");
											   i=i-1;
											   break;
										    default:
											   printf("%d",vector[i]);
											   i=i-1;
											   break;
										     }
											}while(i>=0);
											printf("\n");
											break;
										}
										case 12:{
											i=0;
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											do{
											divs=a/14;
									        mod=a % 14;
									        vector[i]=mod;
									        i=i+1;
									        a=divs;
									        if(a==1)
									        {
										    vector[i]=1;
								      	    }
								      	    }while(a>1);
								      	    printf("El resultado es: ");
								      	    do{
									        	switch(vector[i]){
										    case 10:
											   printf("A");
											   i=i-1;
											   break;
										    case 11:
											   printf("B");
											   i=i-1;
											   break;
										    case 12:
											   printf("C");
											   i=i-1;
											   break;
										    case 13:
											   printf("D");
											   i=i-1;
											   break;
										    default:
											   printf("%d",vector[i]);
											   i=i-1;
											   break;
										     }
											}while(i>=0);
											printf("\n");
											break;
										}
										case 13:{
											i=0;
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											do{
											divs=a/15;
									        mod=a % 15;
									        vector[i]=mod;
									        i=i+1;
									        a=divs;
									        if(a==1)
									        {
										    vector[i]=1;
									        }
									        }while(a>1);
									        printf("El resultado es: ");
									        do{
									        	switch(vector[i]){
										    case 10:
											   printf("A");
											   i=i-1;
											   break;
										    case 11:
											   printf("B");
											   i=i-1;
											   break;
										    case 12:
											   printf("C");
											   i=i-1;
											   break;
										    case 13:
											   printf("D");
											   i=i-1;
											   break;
										    case 14:
											   printf("E");
											   i=i-1;
											   break;
										    default:
											   printf("%d",vector[i]);
											   i=i-1;
											   break;
									          }
											}while(i>=0);
											printf("\n");
											break;
										}
										case 14:{
											i=0;
											printf("Ingresa un numero decimal\n");
											scanf("%i",&a);
											do{
											divs=a/16;
								        	mod=a % 16;
									        vector[i]=mod;
									        i=i+1;
									        a=divs;
									        if(a==1)
									        {
										    vector[i]=1;
									        }
									        }while(a>1);
									        printf("El resultado es: ");
									        do{
									        	switch(vector[i]){
										    case 10:
											    printf("A");
											    i=i-1;
											    break;
										    case 11:
											    printf("B");
											    i=i-1;
											    break;
										    case 12:
											   printf("C");
											   i=i-1;
											   break;
										    case 13:
											   printf("D");
											   i=i-1;
											   break;
										    case 14:
											    printf("E");
											    i=i-1;
											    break;
										    case 15:
											    printf("F");
											    i=i-1;
											    break;
										    default:
											    printf("%d",vector[i]);
											    i=i-1;
											    break;
									         }
											}while(i>=0);
											printf("\n");
											break;
										}
										case 15:{
											printf("sale bai\n");
											t=1;
											break;
										}
										default:{
											printf("numero invalido");
											break;
										}
							
									}
								system("pause");
								system("cls");
								}
									
									printf("\n");
									printf("\n");
									printf("\n");
									printf("\n");
									printf("Proceso terminado\n");
									printf("¿Qué desea hacer ahora?\n");
									printf("1) Volver al menú principal\n");
									printf("2) Repetir este proceso (Sistemas Numéricos)\n");
									printf("3) Salir\n");
									scanf("%d",&repetir);
									break;
								}
							/*case 6:
								{
									int a=0,b=0,c=0,m=0,t=0;
									char A[100];
								    char Aux[2];
								    int  i, Error;
								    int my=0,r=0;
								    int vec[10];
								    
								    while(t!=1){
									system("cls");
									printf("Elije que base tiene el numero que quieres covertir a decimal");
									printf("\n1) Binario");
									printf("\n2) Octal");
									printf("\n3) Hexadecimal");
									printf("\n4) Maya");
									printf("\n5) Salir\n");
									scanf("%i",&m);
									a=0;
									b=0;
									c=0;
									system("cls");
									switch(m){
										case 1:{
											printf("Ingresa un numero binario\n");
											scanf("%i",&a);
											while(a!=0){
												b=b+(a%10)*pow(2,c++);
												a=a/10;
											}
											printf("\nEl resultado es: %i\n",b);
											break;
										}
										case 2:{
											printf("Ingresa un numero octal\n");
											scanf("%i",&a);
											while(a!=0){
												b=b+(a%10)*pow(8,c++);
												a=a/10;
											}
											printf("\nEl resultado es: %i\n",b);
											break;
										}
										case 3:{
											printf( "Ingrese su numero Hexadecimal: " );
										    gets( A );
										    strupr(A);
										    for( Error = 0, i = strlen(A) - 1; i>=0; i--)
										        {
										        if( !( ( A[i] >= 'A' && A[i] <= 'F' ) ||
										               ( A[i] >= '0' && A[i] <= '9' ) ) )
										            {
										            Error = 1;
										            break;
										            }
										        }
										 
										    if( !Error )
										        {
										        for( b = 0, i = strlen(A) - 1; i>=0; i--)
										            {
										            c = (int)pow( 16, (strlen(A) - 1 - i) );
										            if( c == 0 )
										                c = 1;
										            switch( A[i] )
										                {
										                case 'A':
										                    b += 10 * c;
										                    break;
										                case 'B':
										                    b += 11 * c;
										                    break;
										                case 'C':
										                    b += 12 * c;
										                    break;
										                case 'D':
										                    b += 13 * c;
										                    break;
										                case 'E':
										                    b += 14 * c;
										                    break;
										                case 'F':
										                    b += 15 * c;
										                    break;
										                default:
										                    Aux[0] = A[i];
										                    Aux[1] = '\0';
										                    b += atoi( Aux ) * c;
										                    break;
										                }
										            }
										        printf( "El numero %s en decimal es %ld\n", A, b );
										        }
										    else
										        printf( "El numero ingresado no es hexadecimal\n" );
										    getchar();
											break;
										}
										case 4:{
											printf("Ingresa cuantos digitos tiene tu numero maya, que sean 10 o menos\n");
											scanf("%i",&my);
											printf("Ahora pon mucha atencion, vas a poner el equivalente en decimal de cada digito\n");
											printf("por ejemplo :||=12, |||=15");
											printf("ahora tambien vas a escribir los digitos del ultimo al primero\n");
											printf("por ejemplo: si tu numero es :|| |||\n");
											printf("vas a escribir 15 primero y despues 12\n");
											for(r=0;r<my;r++){
												printf("pon el digito numero %i\n",r+1);
												scanf("%i",&vec[r]);
												system("cls");
											}
											for(r=0;r<my;r++){
												a=a+vec[r]*pow(20,c++);	
											}
											b=a;
											printf("\nEl resultado es: %i\n",b);
											break;
										}
										case 5:{
											printf("sale bai\n");
											t=1;
											break;
										}
										default:{
											printf("numero invalido");
											break;
										}
									}
								system("pause");
								system("cls");
								}
									
									printf("\n");
									printf("\n");
									printf("\n");
									printf("\n");
									printf("Proceso terminado\n");
									printf("¿Qué desea hacer ahora?\n");
									printf("1) Volver al menú principal\n");
									printf("2) Repetir este proceso (Sistemas Numéricos)\n");
									printf("3) Salir\n");
									scanf("%d",&repetir);
									break;
								}*/
						}
					}
					while(repetir>1 && repetir<3);
					break;
				}
			case 2:
				{
					//2.- Grafos
					do
					{
						system("CLS");
						printf("Ingrese el tamaño de la matriz cuadrada:\t");
						scanf("%d",&df);
					}
					while(df<2||df>25);
					system("CLS");
					do
					{
						system("CLS");
						//Menú
						printf("¿Cuántas ciudades desea generar?\nCiudades:\t");
						scanf("%d",&dciudades);
					}
					while(dciudades>df*df||dciudades<=0);
					do
					{
						Reiniciar();
						Asignar();
						Unir ();
						Imprimir ();
						getch();
						do
						{
							system("CLS");
							printf("¿Desea modificar la cantidad de ciudades o el tamaño de la matriz?\n1) Si\n0) No\n");
							scanf("%d",&dopcion);
						}
						while(dopcion>1||dopcion<0);
						if(dopcion!=0)
						{
							do
							{
								system("CLS");
								printf("¿Qué desea modificar?\n1) Tamaño de la matriz\n2) Cantidad de ciudades\n0) Salir\n");
								scanf("%d",&dopcion);
							}
							while(dopcion<0||dopcion>2);
							if(dopcion==1)
							{
								do
								{
									system("CLS");
									printf("Ingrese el tamaño de la matriz cuadrada: \t");
									scanf("%d",&df);
								}
								while(df<2||df>20);
							}
							if(dopcion==2)
							{
								do
								{
									system("CLS");
									printf("¿Cuántas ciudades desea generar?\nCiudades:\t");
									scanf("%d",&dciudades);
								}
								while(dciudades>=df*df||dciudades<=0);
							}
							system("CLS");
						}
					}
					while(dopcion!=0);
					getchar();
					break;
				}
			case 3:
				{
					do
					{
						//3.- Lógica Proposicional
						system("CLS");
						char expresion[20],expresion1[20],expresion2[20],expresion3[20],f[20],g[20],h[20],i[20],j[20],k[20],l[20],m[20],n[20],o[20],z[20];
						char fa[20],ga[20],ha[20],ia[20],ja[20],ka[20];
						int valid=0,cont=0,cont1=0,cont2=1,cont3=0,pos1=0,pos2=0,totvar=0,totagrup=0,columnas=0,filas=0,existp=0,existq=0,existr=0,exists=0,existap=0,existaq=0,existar=0,existas=0,existparentesis=0,existcorchete=0,parentycorch=0,existllave=0,casossimples=0,casosaevaluar=0,contpar=0,contcor=0,contlla=0;
						
						cont=0;
						do
						{
							expresion[cont]='0';
							//expresion1[cont]='0';
							//expresion2[cont]='0';
							//expresion3[cont]='0';
							cont=cont+1;
						}
						while(cont<20);
						cont=0;
						
						//1.- Instrucciones y escribir la expresión
						printf("Escribe una expresión lógica:\n\n");
						printf("Los caracteres a usar son:\n");
						printf("Proposiciones: p, q, r, s\n");
						printf("Negación: a\n");
						printf("Unión: b\n");
						printf("Intersección: c\n");
						printf("Implicación: d\n");
						printf("Equivalencia: e\n\n");
						printf("Reglas de sintaxis:\n");
						printf("La expresión lógica no puede sobrepasar los 20 caracters\n");
						printf("Haga un uso correcto de los paréntesis\n");
						printf("No pueden haber más de 6 paréntesis en la expresión\n\t(Se considera un paréntesis como abrir y cerrar éste\n\tpor lo que el máximo de paréntesis que se pueden abrir son 6)\n");
						printf("No deben escribirse espacios\n");
						printf("El único operador que se escribe antes de la variable es la negación: ¬p\n");
						printf("Todos los demás operadores se escriben entre las variables que se ven involucradas: pvq, p^q, p->q, p<->q\n");
						scanf("%s",&expresion);
						
						//1.1.-PONER AQUI TODAS LAS RESTRICCIONES NECESARIAS PARA QUE NO SE ESCRIBA ALGO NO VÁLIDO
						
						//2.- Detectar qué variables existen
						cont=0;
						do
						{
							if(expresion[cont]=='p')
							{
								existp=1;
							}
							if(expresion[cont]=='q')
							{
								existq=1;
							}
							if(expresion[cont]=='r')
							{
								existr=1;
							}
							if(expresion[cont]=='s')
							{
								exists=1;
							}
							cont=cont+1;
						}
						while(cont<20);
						
						//3.- Detectar qué negaciones existen. Las negaciones serán los vectores
						cont=0;
						do
						{
							if(expresion[cont]=='a'&&expresion[cont+1]=='p')
							{
								existap=1;
							}
							if(expresion[cont]=='a'&&expresion[cont+1]=='q')
							{
								existaq=1;
							}
							if(expresion[cont]=='a'&&expresion[cont+1]=='r')
							{
								existar=1;
							}
							if(expresion[cont]=='a'&&expresion[cont+1]=='s')
							{
								existas=1;
							}
							cont=cont+1;
						}
						while(cont<20);
						
						//4.- Detectar cuántos paréntesis, corchetes y llaves existen
						cont=0;
						do
						{
							if(expresion[cont]=='(')
							{
								existparentesis=existparentesis+1;
							}
							if(expresion[cont]=='[')
							{
								existcorchete=existcorchete+1;
							}
							if(expresion[cont]=='{')
							{
								existllave=existllave+1;
							}
							cont=cont+1;
						}
						while(cont<20);
						totagrup=existparentesis+existcorchete+existllave;
						parentycorch=existparentesis+existcorchete;
						
						//5.- Guardar cada negación en un vector distinto
						
						//7.- Guardar cada paréntesis en un vector distinto y en su vector contraparte
						cont=0;
						do
						{
							if(expresion[cont]=='(')
							{
								cont=cont+1;
								cont1=0;
								switch (cont2)
								{
									case 1:
										{
											while(expresion[cont]!=')')
											{
												f[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 2:
										{
											while(expresion[cont]!=')')
											{
												g[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 3:
										{
											while(expresion[cont]!=')')
											{
												h[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 4:
										{
											while(expresion[cont]!=')')
											{
												i[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 5:
										{
											while(expresion[cont]!=')')
											{
												j[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 6:
										{
											while(expresion[cont]!=')')
											{
												k[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
								}
								cont2=cont2+1;
							}
							cont=cont+1;
						}
						while(cont2<=existparentesis);
						
						//8.- Guardar cada corchete en un vector distinto
						cont=0;
						do
						{
							if(expresion[cont]=='[')
							{
								cont=cont+1;
								cont1=0;
								switch (cont2)
								{
									case 1:
										{
											while(expresion[cont]!=']')
											{
												f[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 2:
										{
											while(expresion[cont]!=']')
											{
												g[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 3:
										{
											while(expresion[cont]!=']')
											{
												h[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 4:
										{
											while(expresion[cont]!=']')
											{
												i[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 5:
										{
											while(expresion[cont]!=']')
											{
												j[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 6:
										{
											while(expresion[cont]!=']')
											{
												k[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
								}
								cont2=cont2+1;
							}
							cont=cont+1;
						}
						while(cont2<=parentycorch);
						
						//9.- Guardar cada llave en un vector distinto
						cont=0;
						do
						{
							if(expresion[cont]=='{')
							{
								cont=cont+1;
								cont1=0;
								switch (cont2)
								{
									case 1:
										{
											while(expresion[cont]!='}')
											{
												f[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
									case 2:
										{
											while(expresion[cont]!='}')
											{
												g[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
									case 3:
										{
											while(expresion[cont]!='}')
											{
												h[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
									case 4:
										{
											while(expresion[cont]!='}')
											{
												i[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
									case 5:
										{
											while(expresion[cont]!='}')
											{
												j[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
									case 6:
										{
											while(expresion[cont]!='}')
											{
												k[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
								}
								cont2=cont2+1;
							}
							cont=cont+1;
						}
						while(cont2<=totagrup);
						cont2=cont2-1;
						
						//10.- Guardar toda la expresión en un vector distinto y guardar también lo que corresponde a expresion1. expresion2 y expresion3
						cont=0;
						cont1=0;
						while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}')
						{
							z[cont1]=expresion[cont];
							cont=cont+1;
							cont1=cont1+1;
						}
						
						cont=0;
						cont1=0;
						cont2=1;
						while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}'||expresion[cont]=='f'||expresion[cont]=='g'||expresion[cont]=='h'||expresion[cont]=='i'||expresion[cont]=='j'||expresion[cont]=='k')
						{
							if(expresion[cont]=='(')
							{
								switch (cont2)
								{
									case 1:
										{
											expresion1[cont1]='f';
											do
											{
												cont=cont+1;
											}
											while(expresion[cont]!=')');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 2:
										{
											expresion1[cont1]='g';
											do
											{
												cont=cont+1;
											}
											while(expresion[cont]!=')');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 3:
										{
											expresion1[cont1]='h';
											do
											{
												cont=cont+1;
											}
											while(expresion[cont]!=')');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 4:
										{
											expresion1[cont1]='i';
											do
											{
												cont=cont+1;
											}
											while(expresion[cont]!=')');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 5:
										{
											expresion1[cont1]='j';
											do
											{
												cont=cont+1;
											}
											while(expresion[cont]!=')');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 6:
										{
											expresion1[cont1]='k';
											do
											{
												cont=cont+1;
											}
											while(expresion[cont]!=')');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
								}
								cont2=cont2+1;
							}
							else
							{
								expresion1[cont1]=expresion[cont];
								cont=cont+1;
								cont1=cont1+1;
							}
						}
						cont=0;
						cont1=0;
						while(expresion1[cont]=='p'||expresion1[cont]=='q'||expresion1[cont]=='r'||expresion1[cont]=='s'||expresion1[cont]=='a'||expresion1[cont]=='b'||expresion1[cont]=='c'||expresion1[cont]=='d'||expresion1[cont]=='e'||expresion1[cont]=='('||expresion1[cont]==')'||expresion1[cont]=='['||expresion1[cont]==']'||expresion1[cont]=='{'||expresion1[cont]=='}'||expresion1[cont]=='f'||expresion1[cont]=='g'||expresion1[cont]=='h'||expresion1[cont]=='i'||expresion1[cont]=='j'||expresion1[cont]=='k')
						{
							if(expresion1[cont]=='[')
							{
								switch (cont2)
								{
									case 1:
										{
											expresion2[cont1]='f';
											do
											{
												cont=cont+1;
											}
											while(expresion1[cont]!=']');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 2:
										{
											expresion2[cont1]='g';
											do
											{
												cont=cont+1;
											}
											while(expresion1[cont]!=']');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 3:
										{
											expresion2[cont1]='h';
											do
											{
												cont=cont+1;
											}
											while(expresion1[cont]!=']');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 4:
										{
											expresion2[cont1]='i';
											do
											{
												cont=cont+1;
											}
											while(expresion1[cont]!=']');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 5:
										{
											expresion2[cont1]='j';
											do
											{
												cont=cont+1;
											}
											while(expresion1[cont]!=']');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 6:
										{
											expresion2[cont1]='k';
											do
											{
												cont=cont+1;
											}
											while(expresion1[cont]!=']');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
								}
								cont2=cont2+1;
							}
							else
							{
								expresion2[cont1]=expresion1[cont];
								cont=cont+1;
								cont1=cont1+1;
							}
						}
						cont=0;
						cont1=0;
						while(expresion2[cont]=='p'||expresion2[cont]=='q'||expresion2[cont]=='r'||expresion2[cont]=='s'||expresion2[cont]=='a'||expresion2[cont]=='b'||expresion2[cont]=='c'||expresion2[cont]=='d'||expresion2[cont]=='e'||expresion2[cont]=='('||expresion2[cont]==')'||expresion2[cont]=='['||expresion2[cont]==']'||expresion2[cont]=='{'||expresion2[cont]=='}'||expresion2[cont]=='f'||expresion2[cont]=='g'||expresion2[cont]=='h'||expresion2[cont]=='i'||expresion2[cont]=='j'||expresion2[cont]=='k')
						{
							if(expresion2[cont]=='{')
							{
								switch (cont2)
								{
									case 1:
										{
											expresion3[cont1]='f';
											do
											{
												cont=cont+1;
											}
											while(expresion2[cont]!='}');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 2:
										{
											expresion3[cont1]='g';
											do
											{
												cont=cont+1;
											}
											while(expresion2[cont]!='}');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 3:
										{
											expresion3[cont1]='h';
											do
											{
												cont=cont+1;
											}
											while(expresion2[cont]!='}');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 4:
										{
											expresion3[cont1]='i';
											do
											{
												cont=cont+1;
											}
											while(expresion2[cont]!='}');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 5:
										{
											expresion3[cont1]='j';
											do
											{
												cont=cont+1;
											}
											while(expresion2[cont]!='}');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
									case 6:
										{
											expresion3[cont1]='k';
											do
											{
												cont=cont+1;
											}
											while(expresion2[cont]!='}');
											cont=cont+1;
											cont1=cont1+1;
											break;
										}
								}
								cont2=cont2+1;
							}
							else
							{
								expresion3[cont1]=expresion2[cont];
								cont=cont+1;
								cont1=cont1+1;
							}
						}
						printf("Expresion Original: %s\n",expresion);
						printf("Expresion 1: %s\n",expresion1);
						printf("Expresion 2: %s\n",expresion2);
						printf("Expresion 3: %s\n",expresion3);
							
						//11.- Contar total de variables, negaciones y signos de agrupación existen
						columnas=existp+existq+existr+exists+existap+existaq+existar+existas+totagrup+1;
						totvar=existp+existq+existr+exists;
						filas=(pow(2,totvar))+1;
						//Las operaciones siguientes son importantes para ubicar las columnas de las proposiciones a evaluar
						casossimples=existp+existq+existr+exists+existap+existaq+existar+existas;
						casosaevaluar=columnas-casossimples;
						
						//12.- Generar una matriz con las dimensiones anteriores (aquí también aparece un llenado de ceros a la matriz)
						char mat[columnas][filas];
						
						cont=0;
						cont1=0;
						do
						{
							do
							{
								mat[cont1][cont]='0';
								cont1=cont1+1;
							}
							while(cont1<columnas);
							cont1=0;
							cont=cont+1;
						}
						while(cont<filas);
						
						//13.- Llenar los títulos de la tabla de verdad
						cont=0;
						if (existp==1)
						{
							mat[cont][0]='p';
							cont=cont+1;
						}
						if (existq==1)
						{
							mat[cont][0]='q';
							cont=cont+1;
						}
						if (existr==1)
						{
							mat[cont][0]='r';
							cont=cont+1;
						}
						if (exists==1)
						{
							mat[cont][0]='s';
							cont=cont+1;
						}
						if (existap==1)
						{
							mat[cont][0]='l';
							cont=cont+1;
						}
						if (existaq==1)
						{
							mat[cont][0]='m';
							cont=cont+1;
						}
						if (existar==1)
						{
							mat[cont][0]='n';
							cont=cont+1;
						}
						if (existas==1)
						{
							mat[cont][0]='o';
							cont=cont+1;
						}
						cont1=1;
						do
						{
							switch (cont1)
							{
								case 1:
									{
										mat[cont][0]='f';
										break;
									}
								case 2:
									{
										mat[cont][0]='g';
										break;
									}
								case 3:
									{
										mat[cont][0]='h';
										break;
									}
								case 4:
									{
										mat[cont][0]='i';
										break;
									}
								case 5:
									{
										mat[cont][0]='j';
										break;
									}
								case 6:
									{
										mat[cont][0]='k';
										break;
									}
							}
							cont=cont+1;
							cont1=cont1+1;
						}
						while(cont<columnas);
						cont=0;
						if(mat[columnas-1][0]=='f')
						{
							while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}')
							{
								f[cont]=z[cont];
								cont=cont+1;
							}
						}
						if(mat[columnas-1][0]=='g')
						{
							while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}')
							{
								g[cont]=z[cont];
								cont=cont+1;
							}
						}
						if(mat[columnas-1][0]=='h')
						{
							while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}')
							{
								h[cont]=z[cont];
								cont=cont+1;
							}
						}
						if(mat[columnas-1][0]=='i')
						{
							while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}')
							{
								i[cont]=z[cont];
								cont=cont+1;
							}
						}
						if(mat[columnas-1][0]=='j')
						{
							while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}')
							{
								j[cont]=z[cont];
								cont=cont+1;
							}
						}
						if(mat[columnas-1][0]=='k')
						{
							while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}')
							{
								k[cont]=z[cont];
								cont=cont+1;
							}
						}
						
						//14.- Llenar los espacios pertenecientes a las variables simples
						cont=0;
						do
						{
							cont1=1;
							switch (cont)
							{
								case 0:
									{
										do
										{
											valid=cont1%2;
											if(valid==1)
											{
												mat[0][cont1]='1';
												//cont1=cont1+1;
											}
											if(valid==0)
											{
												mat[0][cont1]='0';
												//cont1=cont1+1;
											}
										cont1=cont1+1;
										}
										while(cont1<filas);
										break;
									}
								case 1:
									{
										do
										{
											valid=cont1%4;
											if(valid==1||valid==2)
											{
												mat[1][cont1]='1';
												//cont1=cont1+1;
											}
											if(valid==0||valid==3)
											{
												mat[1][cont1]='0';
												//cont1=cont1+1;
											}
										cont1=cont1+1;
										}
										while(cont1<filas);
										break;
									}
								case 2:
									{
										do
										{
											valid=cont1%8;
											if(valid==1||valid==2||valid==3||valid==4)
											{
												mat[2][cont1]='1';
												//cont1=cont1+1;
											}
											if(valid==0||valid==5||valid==6||valid==7)
											{
												mat[2][cont1]='0';
												//cont1=cont1+1;
											}
										cont1=cont1+1;
										}
										while(cont1<filas);
										break;
									}
								case 3:
									{
										do
										{
											valid=cont1%16;
											if(valid==1||valid==2||valid==3||valid==4||valid==5||valid==6||valid==7||valid==8)
											{
												mat[3][cont1]='1';
												//cont1=cont1+1;
											}
											if(valid==0||valid==9||valid==10||valid==11||valid==12||valid==13||valid==14||valid==15)
											{
												mat[3][cont1]='0';
												//cont1=cont1+1;
											}
										cont1=cont1+1;
										}
										while(cont1<filas);
										break;
									}
							}
							cont=cont+1;
						}
						while(cont<totvar);
						
						//15.- Llenar las negaciones
						cont=0;
						cont1=0;
						cont2=1;
						do
						{
							if(mat[cont][0]=='l')
							{
								if(mat[cont1][0]=='p')
								{
									do
									{
										if(mat[cont1][cont2]=='1')
										{
											mat[cont][cont2]='0';
										}
										if(mat[cont1][cont2]=='0')
										{
											mat[cont][cont2]='1';
										}
										cont2=cont2+1;
									}
									while(cont2<=filas);
									break;
								}
								else
								{
									cont1=cont1+1;
								}
							}
							else
							{
								cont=cont+1;
							}
						}
						while(cont<columnas);
						cont=0;
						cont1=0;
						cont2=1;
						do
						{
							if(mat[cont][0]=='m')
							{
								if(mat[cont1][0]=='q')
								{
									do
									{
										if(mat[cont1][cont2]=='1')
										{
											mat[cont][cont2]='0';
										}
										if(mat[cont1][cont2]=='0')
										{
											mat[cont][cont2]='1';
										}
										cont2=cont2+1;
									}
									while(cont2<=filas);
									break;
								}
								else
								{
									cont1=cont1+1;
								}
							}
							else
							{
								cont=cont+1;
							}
						}
						while(cont<columnas);
						cont=0;
						cont1=0;
						cont2=1;
						do
						{
							if(mat[cont][0]=='n')
							{
								if(mat[cont1][0]=='r')
								{
									do
									{
										if(mat[cont1][cont2]=='1')
										{
											mat[cont][cont2]='0';
										}
										if(mat[cont1][cont2]=='0')
										{
											mat[cont][cont2]='1';
										}
										cont2=cont2+1;
									}
									while(cont2<=filas);
									break;
								}
								else
								{
									cont1=cont1+1;
								}
							}
							else
							{
								cont=cont+1;
							}
						}
						while(cont<columnas);
						cont=0;
						cont1=0;
						cont2=1;
						do
						{
							if(mat[cont][0]=='o')
							{
								if(mat[cont1][0]=='s')
								{
									do
									{
										if(mat[cont1][cont2]=='1')
										{
											mat[cont][cont2]='0';
										}
										if(mat[cont1][cont2]=='0')
										{
											mat[cont][cont2]='1';
										}
										cont2=cont2+1;
									}
									while(cont2<=filas);
									break;
								}
								else
								{
									cont1=cont1+1;
								}
							}
							else
							{
								cont=cont+1;
							}
						}
						while(cont<columnas);
						
						//16.- Evaluar los casos con operadores. Pero antes, llenar los vectores fa, ga... del contenido respectivo que deben tener
						//Llenar los vectores fa, ga...
						cont=0;
						cont2=1;
						do
						{
							if(expresion[cont]=='(')
							{
								cont=cont+1;
								cont1=0;
								switch (cont2)
								{
									case 1:
										{
											while(expresion[cont]!=')')
											{
												fa[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 2:
										{
											while(expresion[cont]!=')')
											{
												ga[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 3:
										{
											while(expresion[cont]!=')')
											{
												ha[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
									case 4:
										{
											while(expresion[cont]!=')')
											{
												ia[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
									case 5:
										{
											while(expresion[cont]!=')')
											{
												ja[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
									case 6:
										{
											while(expresion[cont]!=')')
											{
												ka[cont1]=expresion[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
								}
								cont2=cont2+1;
							}
							cont=cont+1;
						}
						while(cont2<=existparentesis);
						cont=0;
						do
						{
							if(expresion1[cont]=='[')
							{
								cont=cont+1;
								cont1=0;
								switch (cont2)
								{
									case 1:
										{
											while(expresion1[cont]!=']')
											{
												fa[cont1]=expresion1[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 2:
										{
											while(expresion1[cont]!=']')
											{
												ga[cont1]=expresion1[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 3:
										{
											while(expresion1[cont]!=']')
											{
												ha[cont1]=expresion1[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 4:
										{
											while(expresion1[cont]!=']')
											{
												ia[cont1]=expresion1[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 5:
										{
											while(expresion[cont]!=']')
											{
												ja[cont1]=expresion1[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
									case 6:
										{
											while(expresion1[cont]!=']')
											{
												ka[cont1]=expresion1[cont];
												cont=cont+1;
												cont1=cont1+1;
												//valid=1;
											}
											break;
										}
								}
								cont2=cont2+1;
							}
							cont=cont+1;
						}
						while(cont2<=parentycorch);
						cont=0;
						do
						{
							if(expresion[cont]=='{')
							{
								cont=cont+1;
								cont1=0;
								switch (cont2)
								{
									case 1:
										{
											while(expresion2[cont]!='}')
											{
												fa[cont1]=expresion2[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
									case 2:
										{
											while(expresion2[cont]!='}')
											{
												ga[cont1]=expresion2[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
									case 3:
										{
											while(expresion2[cont]!='}')
											{
												ha[cont1]=expresion2[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
									case 4:
										{
											while(expresion2[cont]!='}')
											{
												ia[cont1]=expresion2[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
									case 5:
										{
											while(expresion2[cont]!='}')
											{
												ja[cont1]=expresion2[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
									case 6:
										{
											while(expresion2[cont]!='}')
											{
												ka[cont1]=expresion2[cont];
												cont=cont+1;
												cont1=cont1+1;
												valid=1;
											}
											break;
										}
								}
								cont2=cont2+1;
							}
							cont=cont+1;
						}
						while(cont2<=totagrup);
						cont=0;
						do
						{
							cont1=0;
							switch (cont2)
							{
								case 1:
									{
										while(cont<3)
										{
											fa[cont1]=expresion3[cont];
											cont=cont+1;
											cont1=cont1+1;
											valid=1;
										}
										break;
									}
								case 2:
									{
										while(cont<3)
										{
											ga[cont1]=expresion3[cont];
											cont=cont+1;
											cont1=cont1+1;
											valid=1;
										}
										break;
									}
								case 3:
									{
										while(cont<3)
										{
											ha[cont1]=expresion3[cont];
											cont=cont+1;
											cont1=cont1+1;
											valid=1;
										}
										break;
									}
								case 4:
									{
										while(cont<3)
										{
											ia[cont1]=expresion3[cont];
											cont=cont+1;
											cont1=cont1+1;
											valid=1;
										}
										break;
									}
								case 5:
									{
										while(cont<3)
										{
											ja[cont1]=expresion3[cont];
											cont=cont+1;
											cont1=cont1+1;
											valid=1;
										}
										break;
									}
								case 6:
									{
										while(cont<3)
										{
											ka[cont1]=expresion3[cont];
											cont=cont+1;
											cont1=cont1+1;
											valid=1;
										}
										break;
									}
							}
							cont2=cont2+1;
						}
						while(cont2<12);
						
						
						printf("fa = %s\n",fa);
						printf("ga = %s\n",ga);
						printf("ha = %s\n",ha);
						printf("ia = %s\n",ia);
						printf("ja = %s\n",ja);
						printf("ka = %s\n",ka);
						//Hacer las evaluaciones
						cont=0;
						do
						{
							cont1=0;
							switch (cont)
							{
								case 0:
									{
										cont2=1;
										valid=0;
										pos1=0;
										pos2=0;
										do
										{
											if(fa[cont1]=='c'||fa[cont1]=='b'||fa[cont1]=='d'||fa[cont1]=='e') //Busca un operador
											{
												if(fa[cont1-2]=='a') //Al hallarlo, busca si a la izquierda hay una negación
												{
													if(fa[cont1-1]=='p')
													{
														pos1=0;
														while(mat[pos1][0]!='l')
														{
															pos1=pos1+1;
														}
													}
													if(fa[cont1-1]=='q')
													{
														pos1=0;
														while(mat[pos1][0]!='m')
														{
															pos1=pos1+1;
														}
													}
													if(fa[cont1-1]=='r')
													{
														pos1=0;
														while(mat[pos1][0]!='n')
														{
															pos1=pos1+1;
														}
													}
													if(fa[cont1-1]=='s')
													{
														pos1=0;
														while(mat[pos1][0]!='o')
														{
															pos1=pos1+1;
														}
													}
												}
												else //De no hallar negaciones, busca variables normales
												{
													if(fa[cont1-1]=='p')
													{
														pos1=0;
														while(mat[pos1][0]!='p')
														{
															pos1=pos1+1;
														}
													}
													if(fa[cont1-1]=='q')
													{
														pos1=0;
														while(mat[pos1][0]!='q')
														{
															pos1=pos1+1;
														}
													}
													if(fa[cont1-1]=='r')
													{
														pos1=0;
														while(mat[pos1][0]!='r')
														{
															pos1=pos1+1;
														}
													}
													if(fa[cont1-1]=='s')
													{
														pos1=0;
														while(mat[pos1][0]!='s')
														{
															pos1=pos1+1;
														}
													}
													if(fa[cont1-1]=='f')
													{
														pos1=0;
														while(mat[pos1][0]!='f')
														{
															pos1=pos1+1;
														}
													}
													if(fa[cont1-1]=='g')
													{
														pos1=0;
														while(mat[pos1][0]!='g')
														{
															pos1=pos1+1;
														}
													}
													if(fa[cont1-1]=='h')
													{
														pos1=0;
														while(mat[pos1][0]!='h')
														{
															pos1=pos1+1;
														}
													}
													if(fa[cont1-1]=='i')
													{
														pos1=0;
														while(mat[pos1][0]!='i')
														{
															pos1=pos1+1;
														}
													}
													if(fa[cont1-1]=='j')
													{
														pos1=0;
														while(mat[pos1][0]!='j')
														{
															pos1=pos1+1;
														}
													}
													if(fa[cont1-1]=='k')
													{
														pos1=0;
														while(mat[pos1][0]!='k')
														{
															pos1=pos1+1;
														}
													}
												}
												if(fa[cont1+1]=='a') //Al hallarlo, busca si a la derecha hay una negación
												{
													if(fa[cont1+2]=='p')
													{
														pos2=0;
														while(mat[pos2][0]!='l')
														{
															pos2=pos2+1;
														}
													}
													if(fa[cont1+2]=='q')
													{
														pos2=0;
														while(mat[pos2][0]!='m')
														{
															pos2=pos2+1;
														}
													}
													if(fa[cont1+2]=='r')
													{
														pos2=0;
														while(mat[pos2][0]!='n')
														{
															pos2=pos2+1;
														}
													}
													if(fa[cont1+2]=='s')
													{
														pos2=0;
														while(mat[pos2][0]!='o')
														{
															pos2=pos2+1;
														}
													}
												}
												else //De no hallar negaciones, busca variables normales
												{
													if(fa[cont1+1]=='p')
													{
														pos2=0;
														while(mat[pos2][0]!='p')
														{
															pos2=pos2+1;
														}
													}
													if(fa[cont1+1]=='q')
													{
														pos2=0;
														while(mat[pos2][0]!='q')
														{
															pos2=pos2+1;
														}
													}
													if(fa[cont1+1]=='r')
													{
														pos2=0;
														while(mat[pos2][0]!='r')
														{
															pos2=pos2+1;
														}
													}
													if(fa[cont1+1]=='s')
													{
														pos2=0;
														while(mat[pos2][0]!='s')
														{
															pos2=pos2+1;
														}
													}
													if(fa[cont1+1]=='f')
													{
														pos2=0;
														while(mat[pos2][0]!='f')
														{
															pos2=pos2+1;
														}
													}
													if(fa[cont1+1]=='g')
													{
														pos2=0;
														while(mat[pos2][0]!='g')
														{
															pos2=pos2+1;
														}
													}
													if(fa[cont1+1]=='h')
													{
														pos2=0;
														while(mat[pos2][0]!='h')
														{
															pos2=pos2+1;
														}
													}
													if(fa[cont1+1]=='i')
													{
														pos2=0;
														while(mat[pos2][0]!='i')
														{
															pos2=pos2+1;
														}
													}
													if(fa[cont1+1]=='j')
													{
														pos2=0;
														while(mat[pos2][0]!='j')
														{
															pos2=pos2+1;
														}
													}
													if(fa[cont1+1]=='k')
													{
														pos2=0;
														while(mat[pos2][0]!='k')
														{
															pos2=pos2+1;
														}
													}
												}
												do
												{
													if(fa[cont1]=='c')
													{
														do
														{
															if(mat[pos1][cont2]=='1'&&mat[pos2][cont2]=='1')
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(fa[cont1]=='b')
													{
														do
														{
															if(mat[pos1][cont2]=='0'&&mat[pos2][cont2]=='0')
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(fa[cont1]=='d')
													{
														do
														{
															if(mat[pos1][cont2]=='1'&&mat[pos2][cont2]=='0')
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(fa[cont1]=='e')
													{
														do
														{
															if(mat[pos1][cont2]==mat[pos2][cont2])
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
												}
												while(cont2<filas);
											}
											cont1=cont1+1;
										}
										while(cont1<20); //&&valid==0
										break;
									}
								case 1:
									{
										cont2=1;
										valid=0;
										pos1=0;
										pos2=0;
										do
										{
											if(ga[cont1]=='c'||ga[cont1]=='b'||ga[cont1]=='d'||ga[cont1]=='e') //Busca un operador
											{
												if(ga[cont1-2]=='a') //Al hallarlo, busca si a la izquierda hay una negación
												{
													if(ga[cont1-1]=='p')
													{
														pos1=0;
														while(mat[pos1][0]!='l')
														{
															pos1=pos1+1;
														}
													}
													if(ga[cont1-1]=='q')
													{
														pos1=0;
														while(mat[pos1][0]!='m')
														{
															pos1=pos1+1;
														}
													}
													if(ga[cont1-1]=='r')
													{
														pos1=0;
														while(mat[pos1][0]!='n')
														{
															pos1=pos1+1;
														}
													}
													if(ga[cont1-1]=='s')
													{
														pos1=0;
														while(mat[pos1][0]!='o')
														{
															pos1=pos1+1;
														}
													}
												}
												else //De no hallar negaciones, busca variables normales
												{
													if(ga[cont1-1]=='p')
													{
														pos1=0;
														while(mat[pos1][0]!='p')
														{
															pos1=pos1+1;
														}
													}
													if(ga[cont1-1]=='q')
													{
														pos1=0;
														while(mat[pos1][0]!='q')
														{
															pos1=pos1+1;
														}
													}
													if(ga[cont1-1]=='r')
													{
														pos1=0;
														while(mat[pos1][0]!='r')
														{
															pos1=pos1+1;
														}
													}
													if(ga[cont1-1]=='s')
													{
														pos1=0;
														while(mat[pos1][0]!='s')
														{
															pos1=pos1+1;
														}
													}
													if(ga[cont1-1]=='f')
													{
														pos1=0;
														while(mat[pos1][0]!='f')
														{
															pos1=pos1+1;
														}
													}
													if(ga[cont1-1]=='g')
													{
														pos1=0;
														while(mat[pos1][0]!='g')
														{
															pos1=pos1+1;
														}
													}
													if(ga[cont1-1]=='h')
													{
														pos1=0;
														while(mat[pos1][0]!='h')
														{
															pos1=pos1+1;
														}
													}
													if(ga[cont1-1]=='i')
													{
														pos1=0;
														while(mat[pos1][0]!='i')
														{
															pos1=pos1+1;
														}
													}
													if(ga[cont1-1]=='j')
													{
														pos1=0;
														while(mat[pos1][0]!='j')
														{
															pos1=pos1+1;
														}
													}
													if(ga[cont1-1]=='k')
													{
														pos1=0;
														while(mat[pos1][0]!='k')
														{
															pos1=pos1+1;
														}
													}
												}
												if(ga[cont1+1]=='a') //Al hallarlo, busca si a la derecha hay una negación
												{
													if(ga[cont1+2]=='p')
													{
														pos2=0;
														while(mat[pos2][0]!='l')
														{
															pos2=pos2+1;
														}
													}
													if(ga[cont1+2]=='q')
													{
														pos2=0;
														while(mat[pos2][0]!='m')
														{
															pos2=pos2+1;
														}
													}
													if(ga[cont1+2]=='r')
													{
														pos2=0;
														while(mat[pos2][0]!='n')
														{
															pos2=pos2+1;
														}
													}
													if(ga[cont1+2]=='s')
													{
														pos2=0;
														while(mat[pos2][0]!='o')
														{
															pos2=pos2+1;
														}
													}
												}
												else //De no hallar negaciones, busca variables normales
												{
													if(ga[cont1+1]=='p')
													{
														pos2=0;
														while(mat[pos2][0]!='p')
														{
															pos2=pos2+1;
														}
													}
													if(ga[cont1+1]=='q')
													{
														pos2=0;
														while(mat[pos2][0]!='q')
														{
															pos2=pos2+1;
														}
													}
													if(ga[cont1+1]=='r')
													{
														pos2=0;
														while(mat[pos2][0]!='r')
														{
															pos2=pos2+1;
														}
													}
													if(ga[cont1+1]=='s')
													{
														pos2=0;
														while(mat[pos2][0]!='s')
														{
															pos2=pos2+1;
														}
													}
													if(ga[cont1+1]=='f')
													{
														pos2=0;
														while(mat[pos2][0]!='f')
														{
															pos2=pos2+1;
														}
													}
													if(ga[cont1+1]=='g')
													{
														pos2=0;
														while(mat[pos2][0]!='g')
														{
															pos2=pos2+1;
														}
													}
													if(ga[cont1+1]=='h')
													{
														pos2=0;
														while(mat[pos2][0]!='h')
														{
															pos2=pos2+1;
														}
													}
													if(ga[cont1+1]=='i')
													{
														pos2=0;
														while(mat[pos2][0]!='i')
														{
															pos2=pos2+1;
														}
													}
													if(ga[cont1+1]=='j')
													{
														pos2=0;
														while(mat[pos2][0]!='j')
														{
															pos2=pos2+1;
														}
													}
													if(ga[cont1+1]=='k')
													{
														pos2=0;
														while(mat[pos2][0]!='k')
														{
															pos2=pos2+1;
														}
													}
												}
												do
												{
													if(ga[cont1]=='c')
													{
														do
														{
															if(mat[pos1][cont2]=='1'&&mat[pos2][cont2]=='1')
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ga[cont1]=='b')
													{
														do
														{
															if(mat[pos1][cont2]=='0'&&mat[pos2][cont2]=='0')
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ga[cont1]=='d')
													{
														do
														{
															if(mat[pos1][cont2]=='1'&&mat[pos2][cont2]=='0')
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ga[cont1]=='e')
													{
														do
														{
															if(mat[pos1][cont2]==mat[pos2][cont2])
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
												}
												while(cont2<filas);
											}
											cont1=cont1+1;
										}
										while(cont1<20&&valid==0);
										break;
									}
								case 2:
									{
										cont2=1;
										valid=0;
										pos1=0;
										pos2=0;
										do
										{
											if(ha[cont1]=='c'||ha[cont1]=='b'||ha[cont1]=='d'||ha[cont1]=='e') //Busca un operador
											{
												if(ha[cont1-2]=='a') //Al hallarlo, busca si a la izquierda hay una negación
												{
													if(ha[cont1-1]=='p')
													{
														pos1=0;
														while(mat[pos1][0]!='l')
														{
															pos1=pos1+1;
														}
													}
													if(ha[cont1-1]=='q')
													{
														pos1=0;
														while(mat[pos1][0]!='m')
														{
															pos1=pos1+1;
														}
													}
													if(ha[cont1-1]=='r')
													{
														pos1=0;
														while(mat[pos1][0]!='n')
														{
															pos1=pos1+1;
														}
													}
													if(ha[cont1-1]=='s')
													{
														pos1=0;
														while(mat[pos1][0]!='o')
														{
															pos1=pos1+1;
														}
													}
												}
												else //De no hallar negaciones, busca variables normales
												{
													if(ha[cont1-1]=='p')
													{
														pos1=0;
														while(mat[pos1][0]!='p')
														{
															pos1=pos1+1;
														}
													}
													if(ha[cont1-1]=='q')
													{
														pos1=0;
														while(mat[pos1][0]!='q')
														{
															pos1=pos1+1;
														}
													}
													if(ha[cont1-1]=='r')
													{
														pos1=0;
														while(mat[pos1][0]!='r')
														{
															pos1=pos1+1;
														}
													}
													if(ha[cont1-1]=='s')
													{
														pos1=0;
														while(mat[pos1][0]!='s')
														{
															pos1=pos1+1;
														}
													}
													if(ha[cont1-1]=='f')
													{
														pos1=0;
														while(mat[pos1][0]!='f')
														{
															pos1=pos1+1;
														}
													}
													if(ha[cont1-1]=='g')
													{
														pos1=0;
														while(mat[pos1][0]!='g')
														{
															pos1=pos1+1;
														}
													}
													if(ha[cont1-1]=='h')
													{
														pos1=0;
														while(mat[pos1][0]!='h')
														{
															pos1=pos1+1;
														}
													}
													if(ha[cont1-1]=='i')
													{
														pos1=0;
														while(mat[pos1][0]!='i')
														{
															pos1=pos1+1;
														}
													}
													if(ha[cont1-1]=='j')
													{
														pos1=0;
														while(mat[pos1][0]!='j')
														{
															pos1=pos1+1;
														}
													}
													if(ha[cont1-1]=='k')
													{
														pos1=0;
														while(mat[pos1][0]!='k')
														{
															pos1=pos1+1;
														}
													}
												}
												if(ha[cont1+1]=='a') //Al hallarlo, busca si a la derecha hay una negación
												{
													if(ha[cont1+2]=='p')
													{
														pos2=0;
														while(mat[pos2][0]!='l')
														{
															pos2=pos2+1;
														}
													}
													if(ha[cont1+2]=='q')
													{
														pos2=0;
														while(mat[pos2][0]!='m')
														{
															pos2=pos2+1;
														}
													}
													if(ha[cont1+2]=='r')
													{
														pos2=0;
														while(mat[pos2][0]!='n')
														{
															pos2=pos2+1;
														}
													}
													if(ha[cont1+2]=='s')
													{
														pos2=0;
														while(mat[pos2][0]!='o')
														{
															pos2=pos2+1;
														}
													}
												}
												else //De no hallar negaciones, busca variables normales
												{
													if(ha[cont1+1]=='p')
													{
														pos2=0;
														while(mat[pos2][0]!='p')
														{
															pos2=pos2+1;
														}
													}
													if(ha[cont1+1]=='q')
													{
														pos2=0;
														while(mat[pos2][0]!='q')
														{
															pos2=pos2+1;
														}
													}
													if(ha[cont1+1]=='r')
													{
														pos2=0;
														while(mat[pos2][0]!='r')
														{
															pos2=pos2+1;
														}
													}
													if(ha[cont1+1]=='s')
													{
														pos2=0;
														while(mat[pos2][0]!='s')
														{
															pos2=pos2+1;
														}
													}
													if(ha[cont1+1]=='f')
													{
														pos2=0;
														while(mat[pos2][0]!='f')
														{
															pos2=pos2+1;
														}
													}
													if(ha[cont1+1]=='g')
													{
														pos2=0;
														while(mat[pos2][0]!='g')
														{
															printf("%c\n",mat[pos2][0]);
															printf("%d\n",pos2);
															pos2=pos2+1;
														}
													}
													if(ha[cont1+1]=='h')
													{
														pos2=0;
														while(mat[pos2][0]!='h')
														{
															pos2=pos2+1;
														}
													}
													if(ha[cont1+1]=='i')
													{
														pos2=0;
														while(mat[pos2][0]!='i')
														{
															pos2=pos2+1;
														}
													}
													if(ha[cont1+1]=='j')
													{
														pos2=0;
														while(mat[pos2][0]!='j')
														{
															pos2=pos2+1;
														}
													}
													if(ha[cont1+1]=='k')
													{
														pos2=0;
														while(mat[pos2][0]!='k')
														{
															pos2=pos2+1;
														}
													}
												}
												printf("%d\n",cont);
												printf("%d\n",cont1);
												printf("%d\n",cont2);
												printf("%d\n",pos1);
												printf("%d\n",pos2);
												do
												{
													if(ha[cont1]=='c')
													{
														do
														{
															if(mat[pos1][cont2]=='1'&&mat[pos2][cont2]=='1')
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ha[cont1]=='b')
													{
														do
														{
															if(mat[pos1][cont2]=='0'&&mat[pos2][cont2]=='0')
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ha[cont1]=='d')
													{
														do
														{
															if(mat[pos1][cont2]=='1'&&mat[pos2][cont2]=='0')
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ha[cont1]=='e')
													{
														do
														{
															if(mat[pos1][cont2]==mat[pos2][cont2])
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
												}
												while(cont2<filas);
											}
											cont1=cont1+1;
										}
										while(cont1<20&&valid==0);
										break;
									}
								case 3:
									{
										cont2=1;
										valid=0;
										pos1=0;
										pos2=0;
										do
										{
											if(ia[cont1]=='c'||ia[cont1]=='b'||ia[cont1]=='d'||ia[cont1]=='e') //Busca un operador
											{
												if(ia[cont1-2]=='a') //Al hallarlo, busca si a la izquierda hay una negación
												{
													if(ia[cont1-1]=='p')
													{
														pos1=0;
														while(mat[pos1][0]!='l')
														{
															pos1=pos1+1;
														}
													}
													if(ia[cont1-1]=='q')
													{
														pos1=0;
														while(mat[pos1][0]!='m')
														{
															pos1=pos1+1;
														}
													}
													if(ia[cont1-1]=='r')
													{
														pos1=0;
														while(mat[pos1][0]!='n')
														{
															pos1=pos1+1;
														}
													}
													if(ia[cont1-1]=='s')
													{
														pos1=0;
														while(mat[pos1][0]!='o')
														{
															pos1=pos1+1;
														}
													}
												}
												else //De no hallar negaciones, busca variables normales
												{
													if(ia[cont1-1]=='p')
													{
														pos1=0;
														while(mat[pos1][0]!='p')
														{
															pos1=pos1+1;
														}
													}
													if(ia[cont1-1]=='q')
													{
														pos1=0;
														while(mat[pos1][0]!='q')
														{
															pos1=pos1+1;
														}
													}
													if(ia[cont1-1]=='r')
													{
														pos1=0;
														while(mat[pos1][0]!='r')
														{
															pos1=pos1+1;
														}
													}
													if(ia[cont1-1]=='s')
													{
														pos1=0;
														while(mat[pos1][0]!='s')
														{
															pos1=pos1+1;
														}
													}
													if(ia[cont1-1]=='f')
													{
														pos1=0;
														while(mat[pos1][0]!='f')
														{
															pos1=pos1+1;
														}
													}
													if(ia[cont1-1]=='g')
													{
														pos1=0;
														while(mat[pos1][0]!='g')
														{
															pos1=pos1+1;
														}
													}
													if(ia[cont1-1]=='h')
													{
														pos1=0;
														while(mat[pos1][0]!='h')
														{
															pos1=pos1+1;
														}
													}
													if(ia[cont1-1]=='i')
													{
														pos1=0;
														while(mat[pos1][0]!='i')
														{
															pos1=pos1+1;
														}
													}
													if(ia[cont1-1]=='j')
													{
														pos1=0;
														while(mat[pos1][0]!='j')
														{
															pos1=pos1+1;
														}
													}
													if(ia[cont1-1]=='k')
													{
														pos1=0;
														while(mat[pos1][0]!='k')
														{
															pos1=pos1+1;
														}
													}
												}
												if(ia[cont1+1]=='a') //Al hallarlo, busca si a la derecha hay una negación
												{
													if(ia[cont1+2]=='p')
													{
														pos2=0;
														while(mat[pos2][0]!='l')
														{
															pos2=pos2+1;
														}
													}
													if(ia[cont1+2]=='q')
													{
														pos2=0;
														while(mat[pos2][0]!='m')
														{
															pos2=pos2+1;
														}
													}
													if(ia[cont1+2]=='r')
													{
														pos2=0;
														while(mat[pos2][0]!='n')
														{
															pos2=pos2+1;
														}
													}
													if(ia[cont1+2]=='s')
													{
														pos2=0;
														while(mat[pos2][0]!='o')
														{
															pos2=pos2+1;
														}
													}
												}
												else //De no hallar negaciones, busca variables normales
												{
													if(ia[cont1+1]=='p')
													{
														pos2=0;
														while(mat[pos2][0]!='p')
														{
															pos2=pos2+1;
														}
													}
													if(ia[cont1+1]=='q')
													{
														pos2=0;
														while(mat[pos2][0]!='q')
														{
															pos2=pos2+1;
														}
													}
													if(ia[cont1+1]=='r')
													{
														pos2=0;
														while(mat[pos2][0]!='r')
														{
															pos2=pos2+1;
														}
													}
													if(ia[cont1+1]=='s')
													{
														pos2=0;
														while(mat[pos2][0]!='s')
														{
															pos2=pos2+1;
														}
													}
													if(ia[cont1+1]=='f')
													{
														pos2=0;
														while(mat[pos2][0]!='f')
														{
															pos2=pos2+1;
														}
													}
													if(ia[cont1+1]=='g')
													{
														pos2=0;
														while(mat[pos2][0]!='g')
														{
															pos2=pos2+1;
														}
													}
													if(ia[cont1+1]=='h')
													{
														pos2=0;
														while(mat[pos2][0]!='h')
														{
															pos2=pos2+1;
														}
													}
													if(ia[cont1+1]=='i')
													{
														pos2=0;
														while(mat[pos2][0]!='i')
														{
															pos2=pos2+1;
														}
													}
													if(ia[cont1+1]=='j')
													{
														pos2=0;
														while(mat[pos2][0]!='j')
														{
															pos2=pos2+1;
														}
													}
													if(ia[cont1+1]=='k')
													{
														pos2=0;
														while(mat[pos2][0]!='k')
														{
															pos2=pos2+1;
														}
													}
												}
												do
												{
													if(ia[cont1]=='c')
													{
														do
														{
															if(mat[pos1][cont2]=='1'&&mat[pos2][cont2]=='1')
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ia[cont1]=='b')
													{
														do
														{
															if(mat[pos1][cont2]=='0'&&mat[pos2][cont2]=='0')
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ia[cont1]=='d')
													{
														do
														{
															if(mat[pos1][cont2]=='1'&&mat[pos2][cont2]=='0')
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ia[cont1]=='e')
													{
														do
														{
															if(mat[pos1][cont2]==mat[pos2][cont2])
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
												}
												while(cont2<filas);
											}
											cont1=cont1+1;
										}
										while(cont1<20&&valid==0);
										break;
									}
								case 4:
									{
										cont2=1;
										valid=0;
										pos1=0;
										pos2=0;
										do
										{
											if(ja[cont1]=='c'||ja[cont1]=='b'||ja[cont1]=='d'||ja[cont1]=='e') //Busca un operador
											{
												if(ja[cont1-2]=='a') //Al hallarlo, busca si a la izquierda hay una negación
												{
													if(ja[cont1-1]=='p')
													{
														pos1=0;
														while(mat[pos1][0]!='l')
														{
															pos1=pos1+1;
														}
													}
													if(ja[cont1-1]=='q')
													{
														pos1=0;
														while(mat[pos1][0]!='m')
														{
															pos1=pos1+1;
														}
													}
													if(ja[cont1-1]=='r')
													{
														pos1=0;
														while(mat[pos1][0]!='n')
														{
															pos1=pos1+1;
														}
													}
													if(ja[cont1-1]=='s')
													{
														pos1=0;
														while(mat[pos1][0]!='o')
														{
															pos1=pos1+1;
														}
													}
												}
												else //De no hallar negaciones, busca variables normales
												{
													if(ja[cont1-1]=='p')
													{
														pos1=0;
														while(mat[pos1][0]!='p')
														{
															pos1=pos1+1;
														}
													}
													if(ja[cont1-1]=='q')
													{
														pos1=0;
														while(mat[pos1][0]!='q')
														{
															pos1=pos1+1;
														}
													}
													if(ja[cont1-1]=='r')
													{
														pos1=0;
														while(mat[pos1][0]!='r')
														{
															pos1=pos1+1;
														}
													}
													if(ja[cont1-1]=='s')
													{
														pos1=0;
														while(mat[pos1][0]!='s')
														{
															pos1=pos1+1;
														}
													}
													if(ja[cont1-1]=='f')
													{
														pos1=0;
														while(mat[pos1][0]!='f')
														{
															pos1=pos1+1;
														}
													}
													if(ja[cont1-1]=='g')
													{
														pos1=0;
														while(mat[pos1][0]!='g')
														{
															pos1=pos1+1;
														}
													}
													if(ja[cont1-1]=='h')
													{
														pos1=0;
														while(mat[pos1][0]!='h')
														{
															pos1=pos1+1;
														}
													}
													if(ja[cont1-1]=='i')
													{
														pos1=0;
														while(mat[pos1][0]!='i')
														{
															pos1=pos1+1;
														}
													}
													if(ja[cont1-1]=='j')
													{
														pos1=0;
														while(mat[pos1][0]!='j')
														{
															pos1=pos1+1;
														}
													}
													if(ja[cont1-1]=='k')
													{
														pos1=0;
														while(mat[pos1][0]!='k')
														{
															pos1=pos1+1;
														}
													}
												}
												if(ja[cont1+1]=='a') //Al hallarlo, busca si a la derecha hay una negación
												{
													if(ja[cont1+2]=='p')
													{
														pos2=0;
														while(mat[pos2][0]!='l')
														{
															pos2=pos2+1;
														}
													}
													if(ja[cont1+2]=='q')
													{
														pos2=0;
														while(mat[pos2][0]!='m')
														{
															pos2=pos2+1;
														}
													}
													if(ja[cont1+2]=='r')
													{
														pos2=0;
														while(mat[pos2][0]!='n')
														{
															pos2=pos2+1;
														}
													}
													if(ja[cont1+2]=='s')
													{
														pos2=0;
														while(mat[pos2][0]!='o')
														{
															pos2=pos2+1;
														}
													}
												}
												else //De no hallar negaciones, busca variables normales
												{
													if(ja[cont1+1]=='p')
													{
														pos2=0;
														while(mat[pos2][0]!='p')
														{
															pos2=pos2+1;
														}
													}
													if(ja[cont1+1]=='q')
													{
														pos2=0;
														while(mat[pos2][0]!='q')
														{
															pos2=pos2+1;
														}
													}
													if(ja[cont1+1]=='r')
													{
														pos2=0;
														while(mat[pos2][0]!='r')
														{
															pos2=pos2+1;
														}
													}
													if(ja[cont1+1]=='s')
													{
														pos2=0;
														while(mat[pos2][0]!='s')
														{
															pos2=pos2+1;
														}
													}
													if(ja[cont1+1]=='f')
													{
														pos2=0;
														while(mat[pos2][0]!='f')
														{
															pos2=pos2+1;
														}
													}
													if(ja[cont1+1]=='g')
													{
														pos2=0;
														while(mat[pos2][0]!='g')
														{
															pos2=pos2+1;
														}
													}
													if(ja[cont1+1]=='h')
													{
														pos2=0;
														while(mat[pos2][0]!='h')
														{
															pos2=pos2+1;
														}
													}
													if(ja[cont1+1]=='i')
													{
														pos2=0;
														while(mat[pos2][0]!='i')
														{
															pos2=pos2+1;
														}
													}
													if(ja[cont1+1]=='j')
													{
														pos2=0;
														while(mat[pos2][0]!='j')
														{
															pos2=pos2+1;
														}
													}
													if(ja[cont1+1]=='k')
													{
														pos2=0;
														while(mat[pos2][0]!='k')
														{
															pos2=pos2+1;
														}
													}
												}
												do
												{
													if(ja[cont1]=='c')
													{
														do
														{
															if(mat[pos1][cont2]=='1'&&mat[pos2][cont2]=='1')
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ja[cont1]=='b')
													{
														do
														{
															if(mat[pos1][cont2]=='0'&&mat[pos2][cont2]=='0')
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ja[cont1]=='d')
													{
														do
														{
															if(mat[pos1][cont2]=='1'&&mat[pos2][cont2]=='0')
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ja[cont1]=='e')
													{
														do
														{
															if(mat[pos1][cont2]==mat[pos2][cont2])
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
												}
												while(cont2<filas);
											}
											cont1=cont1+1;
										}
										while(cont1<20&&valid==0);
										break;
									}
								case 5:
									{
										cont2=1;
										valid=0;
										pos1=0;
										pos2=0;
										do
										{
											if(ka[cont1]=='c'||ka[cont1]=='b'||ka[cont1]=='d'||ka[cont1]=='e') //Busca un operador
											{
												if(ka[cont1-2]=='a') //Al hallarlo, busca si a la izquierda hay una negación
												{
													if(ka[cont1-1]=='p')
													{
														pos1=0;
														while(mat[pos1][0]!='l')
														{
															pos1=pos1+1;
														}
													}
													if(ka[cont1-1]=='q')
													{
														pos1=0;
														while(mat[pos1][0]!='m')
														{
															pos1=pos1+1;
														}
													}
													if(ka[cont1-1]=='r')
													{
														pos1=0;
														while(mat[pos1][0]!='n')
														{
															pos1=pos1+1;
														}
													}
													if(ka[cont1-1]=='s')
													{
														pos1=0;
														while(mat[pos1][0]!='o')
														{
															pos1=pos1+1;
														}
													}
												}
												else //De no hallar negaciones, busca variables normales
												{
													if(ka[cont1-1]=='p')
													{
														pos1=0;
														while(mat[pos1][0]!='p')
														{
															pos1=pos1+1;
														}
													}
													if(ka[cont1-1]=='q')
													{
														pos1=0;
														while(mat[pos1][0]!='q')
														{
															pos1=pos1+1;
														}
													}
													if(ka[cont1-1]=='r')
													{
														pos1=0;
														while(mat[pos1][0]!='r')
														{
															pos1=pos1+1;
														}
													}
													if(ka[cont1-1]=='s')
													{
														pos1=0;
														while(mat[pos1][0]!='s')
														{
															pos1=pos1+1;
														}
													}
													if(ka[cont1-1]=='f')
													{
														pos1=0;
														while(mat[pos1][0]!='f')
														{
															pos1=pos1+1;
														}
													}
													if(ka[cont1-1]=='g')
													{
														pos1=0;
														while(mat[pos1][0]!='g')
														{
															pos1=pos1+1;
														}
													}
													if(ka[cont1-1]=='h')
													{
														pos1=0;
														while(mat[pos1][0]!='h')
														{
															pos1=pos1+1;
														}
													}
													if(ka[cont1-1]=='i')
													{
														pos1=0;
														while(mat[pos1][0]!='i')
														{
															pos1=pos1+1;
														}
													}
													if(ka[cont1-1]=='j')
													{
														pos1=0;
														while(mat[pos1][0]!='j')
														{
															pos1=pos1+1;
														}
													}
													if(ka[cont1-1]=='k')
													{
														pos1=0;
														while(mat[pos1][0]!='k')
														{
															pos1=pos1+1;
														}
													}
												}
												if(ka[cont1+1]=='a') //Al hallarlo, busca si a la derecha hay una negación
												{
													if(ka[cont1+2]=='p')
													{
														pos2=0;
														while(mat[pos2][0]!='l')
														{
															pos2=pos2+1;
														}
													}
													if(ka[cont1+2]=='q')
													{
														pos2=0;
														while(mat[pos2][0]!='m')
														{
															pos2=pos2+1;
														}
													}
													if(ka[cont1+2]=='r')
													{
														pos2=0;
														while(mat[pos2][0]!='n')
														{
															pos2=pos2+1;
														}
													}
													if(ka[cont1+2]=='s')
													{
														pos2=0;
														while(mat[pos2][0]!='o')
														{
															pos2=pos2+1;
														}
													}
												}
												else //De no hallar negaciones, busca variables normales
												{
													if(ka[cont1+1]=='p')
													{
														pos2=0;
														while(mat[pos2][0]!='p')
														{
															pos2=pos2+1;
														}
													}
													if(ka[cont1+1]=='q')
													{
														pos2=0;
														while(mat[pos2][0]!='q')
														{
															pos2=pos2+1;
														}
													}
													if(ka[cont1+1]=='r')
													{
														pos2=0;
														while(mat[pos2][0]!='r')
														{
															pos2=pos2+1;
														}
													}
													if(ka[cont1+1]=='s')
													{
														pos2=0;
														while(mat[pos2][0]!='s')
														{
															pos2=pos2+1;
														}
													}
													if(ka[cont1+1]=='f')
													{
														pos2=0;
														while(mat[pos2][0]!='f')
														{
															pos2=pos2+1;
														}
													}
													if(ka[cont1+1]=='g')
													{
														pos2=0;
														while(mat[pos2][0]!='g')
														{
															pos2=pos2+1;
														}
													}
													if(ka[cont1+1]=='h')
													{
														pos2=0;
														while(mat[pos2][0]!='h')
														{
															pos2=pos2+1;
														}
													}
													if(ka[cont1+1]=='i')
													{
														pos2=0;
														while(mat[pos2][0]!='i')
														{
															pos2=pos2+1;
														}
													}
													if(ka[cont1+1]=='j')
													{
														pos2=0;
														while(mat[pos2][0]!='j')
														{
															pos2=pos2+1;
														}
													}
													if(ka[cont1+1]=='k')
													{
														pos2=0;
														while(mat[pos2][0]!='k')
														{
															pos2=pos2+1;
														}
													}
												}
												do
												{
													if(ka[cont1]=='c')
													{
														do
														{
															if(mat[pos1][cont2]=='1'&&mat[pos2][cont2]=='1')
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ka[cont1]=='b')
													{
														do
														{
															if(mat[pos1][cont2]=='0'&&mat[pos2][cont2]=='0')
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ka[cont1]=='d')
													{
														do
														{
															if(mat[pos1][cont2]=='1'&&mat[pos2][cont2]=='0')
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
													if(ka[cont1]=='e')
													{
														do
														{
															if(mat[pos1][cont2]==mat[pos2][cont2])
															{
																mat[casossimples+cont][cont2]='1';
																valid=1;
															}
															else
															{
																mat[casossimples+cont][cont2]='0';
																valid=1;
															}
															cont2=cont2+1;
														}
														while(cont2<filas);
													}
												}
												while(cont2<filas);
											}
											cont1=cont1+1;
										}
										while(cont1<20&&valid==0);
										break;
									}
							}
							cont=cont+1;
						}
						while(cont<totagrup+1);
						
						//13.- Llenar los títulos de la tabla de verdad otra vez :v
						cont=0;
						if (existp==1)
						{
							mat[cont][0]='p';
							cont=cont+1;
						}
						if (existq==1)
						{
							mat[cont][0]='q';
							cont=cont+1;
						}
						if (existr==1)
						{
							mat[cont][0]='r';
							cont=cont+1;
						}
						if (exists==1)
						{
							mat[cont][0]='s';
							cont=cont+1;
						}
						if (existap==1)
						{
							mat[cont][0]='l';
							cont=cont+1;
						}
						if (existaq==1)
						{
							mat[cont][0]='m';
							cont=cont+1;
						}
						if (existar==1)
						{
							mat[cont][0]='n';
							cont=cont+1;
						}
						if (existas==1)
						{
							mat[cont][0]='o';
							cont=cont+1;
						}
						cont1=1;
						do
						{
							switch (cont1)
							{
								case 1:
									{
										mat[cont][0]='f';
										break;
									}
								case 2:
									{
										mat[cont][0]='g';
										break;
									}
								case 3:
									{
										mat[cont][0]='h';
										break;
									}
								case 4:
									{
										mat[cont][0]='i';
										break;
									}
								case 5:
									{
										mat[cont][0]='j';
										break;
									}
								case 6:
									{
										mat[cont][0]='k';
										break;
									}
							}
							cont=cont+1;
							cont1=cont1+1;
						}
						while(cont<columnas);
						cont=0;
						if(mat[columnas-1][0]=='f')
						{
							while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}')
							{
								f[cont]=z[cont];
								cont=cont+1;
							}
						}
						if(mat[columnas-1][0]=='g')
						{
							while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}')
							{
								g[cont]=z[cont];
								cont=cont+1;
							}
						}
						if(mat[columnas-1][0]=='h')
						{
							while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}')
							{
								h[cont]=z[cont];
								cont=cont+1;
							}
						}
						if(mat[columnas-1][0]=='i')
						{
							while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}')
							{
								i[cont]=z[cont];
								cont=cont+1;
							}
						}
						if(mat[columnas-1][0]=='j')
						{
							while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}')
							{
								j[cont]=z[cont];
								cont=cont+1;
							}
						}
						if(mat[columnas-1][0]=='k')
						{
							while(expresion[cont]=='p'||expresion[cont]=='q'||expresion[cont]=='r'||expresion[cont]=='s'||expresion[cont]=='a'||expresion[cont]=='b'||expresion[cont]=='c'||expresion[cont]=='d'||expresion[cont]=='e'||expresion[cont]=='('||expresion[cont]==')'||expresion[cont]=='['||expresion[cont]==']'||expresion[cont]=='{'||expresion[cont]=='}')
							{
								k[cont]=z[cont];
								cont=cont+1;
							}
						}
						
						//17.- Imprimir la matriz
						printf("\n\nTabla de Verdad\n");
						printf("f = %s\n",f);
						printf("g = %s\n",g);
						printf("h = %s\n",h);
						printf("i = %s\n",i);
						printf("j = %s\n",j);
						printf("k = %s\n",k);
						printf("z = %s\n",z);
						printf("\n");
						cont=0;
						cont1=0;
						do
						{
							do
							{
								printf("[%c]   ",mat[cont1][cont]);
								cont1=cont1+1;
							}
							while(cont1<columnas);
							printf("\n");
							cont1=0;
							cont=cont+1;
						}
						while(cont<filas);
						
						printf("\n");
						printf("\n");
						printf("\n");
						printf("\n");
						printf("Proceso terminado\n");
						printf("¿Qué desea hacer ahora?\n");
						printf("1) Volver al menú principal\n");
						printf("2) Repetir este proceso (Lógica Proposicional)\n");
						printf("3) Salir\n");
						scanf("%d",&repetir);
					}
					while(repetir>1 && repetir<3);
					break;
				}
			case 4:
				{
					do
					{
						//4.- Matriz de Adyacencia e Incidencia
						system("CLS");
						int pag=0;
						printf("¿Qué matriz desea generar?\n");
						printf("1) Matriz de Incidencia\n");
						printf("2) Matriz de Adyacencia\n");
						scanf("%d",&pag);
						switch (pag)
						{
							case 1:
								{
									//4.1.- Matriz de Incidencia
									system("CLS");
									int f1=0,c1=0,validar=0;
									printf("\nGrafo de Martiz de Incidencia");
									printf("\nSe generará una matriz con mínimo de 6 y máximo de 10, tanto filas como columnas\n\n");
									//4.1.1.- Validar los valores
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
									
									//4.1.2.- Construcción de la primera matriz. Esta, por una restricción, conviene llenarse por columnas (verticalmente)
									int random=0,matinc1[c1+1][f1+1],contcol=0,contfil=0,restrictor=0,sumhor=0,sumvert=0,prob=0;
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
									
									//4.1.2.1.- Restrictor para evitar que una columna quede en ceros
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
									
									//4.1.3.- Mostrar la Matriz en la Computadora
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
									
									//4.1.4.1.- Sumas verticales de la matriz (cálculo y desplegado en la pantalla)
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
									printf("\n");
									printf("\n");
									printf("Proceso terminado\n");
									printf("¿Qué desea hacer ahora?\n");
									printf("1) Volver al menú principal\n");
									printf("2) Repetir este proceso (Generación de Matriz de Incidencia y Adyacencia)\n");
									printf("3) Salir\n");
									scanf("%d",&repetir);
									break;
								}
							case 2:
								{
									//4.2.- Matriz de Adyacencia
									system("CLS");
									int l2=0,validar=0,contfil=0,contcol=0,restrictor=0,sumhor=0,sumvert=0,random=0;
									printf("\nGrafo de Martiz de Adyacencia");
									printf("\nSe generará una matriz cuadrada con mínimo de 6 y máximo de 10\n\n");
									//4.2.1.- Validar los valores
									do
									{
										printf("¿De qué tamaño será la matriz?\n");
										printf("Lados: ");
										scanf("%d",&l2);
										validar=validar+1;
										
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
									
									//4.2.2.- Construcción de la segunda matriz. Esta, por su naturaleza se agrega la variable "contextra" para lograr la simetría buscada
									int matady2[l2+1][l2+1],contlad=0,contextra=0;
									contfil=0;
									contcol=0;
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
									
									//4.2.3.- Mostrar la Matriz en la Computadora
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
										//printf(" %d ",sumhor); //Renglón que desplega las sumas horizontales
										printf("\n");
										contcol=0;
										contfil=contfil+1;
									}
									while(contfil<l2);
									contcol=0;
									contfil=0;
									
									//4.2.4.1.- Sumas verticales de la matriz (cálculo y desplegado en la pantalla)
									/*do
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
									while(contcol<l2);*/
									
									printf("\n");
									printf("\n");
									printf("Proceso terminado\n");
									printf("¿Qué desea hacer ahora?\n");
									printf("1) Volver al menú principal\n");
									printf("2) Repetir este proceso (Generación de Matriz de Incidencia y Adyacencia)\n");
									printf("3) Salir\n");
									scanf("%d",&repetir);
									break;
								}
						}
					}
					while(repetir>1 && repetir<3);
					break;
				}
			case 5:
				{
					break;
				}
		}
	}
	while(repetir<2);
}

//Funciones para Grafos
void Reiniciar()
{
	for(di=0;di<df;di++)
	{
		for(dj=0;dj<df;dj++)
		{
			dA[di][dj]='\0';
		}
	}
	dres=0;
	dfin=0;
}

void Asignar()
{
	do
	{
		Reiniciar();
		for(di=0;di<df;di++)
		{
			for(dj=0;dj<df;dj++)
			{
				if(dres<dciudades)
				{
					dac=rand()%4;
					if(dac==1)
					{
						dac=rand()%2;
						if(dac==1)
						{
							dA[di][dj]='*';
							dres++;
						}
					}
				}
			}
		}
	}
	while(dres!=dciudades);
}

void Unir()
{
	for(di=0;di<df;di++)
	{
		for(dj=0;dj<df;dj++)
		{
			if(dA[di][dj]=='*')
			{
				for(dx=di;dx<df;dx++)
				{
					if(dx==di)
					{
						for(dy=dj+1;dy<df;dy++)
						{
							if(dA[dx][dy]=='*')
							{
								Unir2();
							}
						}
					}
					else if (dx!=di)
					{
						for(dy=0;dy<df;dy++)
						{
							if(dA[dx][dy]=='*')
							{
								Unir2();
							}
						}
					}
					dfin=0;
				}
			}
		}
	}
}
void Unir2()
{
	for(da=di;da<=dx;da++)
	{
		if(dfin==0)
		{
			if(dj!=dy)
			{
				if(dj<dy)
				{
					for(db=dj;db<=dy;db++)
					{
						if(dA[da][db]!='*'&&dA[da][db]!='|')
						{
							dA[da][db]='-';
						}
						if(db==dy)
						{
							dfin=1;
							break;
						}
					}
				}
				else if(dj>dy)
				{
					for(db=dj;db>=dy;db--)
					{
						if(dA[da][db]!='*'&&dA[da][db]!='|')
						{
							dA[da][db]='-';
						}
						if(db==dy)
						{
							dfin=1;
							break;
						}
					}
				}
			}
		}
		if(dA[da][dy]!='*'&&da>=di)
		{
			dA[da][dy]='|';
		}
		else if(dA[da][dy]!='*'&&da<=di)
		{
			for(da=dx;da>=di;da--)
			{
				dA[da][dy]='|';
			}
		}
	}
}

void Imprimir()
{
	for(di=0;di<df;di++)
	{
		for(dj=0;dj<df;dj++)
		{
			printf("[%c]\t",dA[di][dj]);
				
		}
		printf("\n");
	}
}
