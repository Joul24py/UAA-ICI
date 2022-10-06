/*
    Universidad Autónoma de Aguascalientes

		  Centro de Ciencias Básicas
  Departamento de Ciencias de la Computación
		   Optimización Inteligente

					5° "A"

   		Práctica 5: Recocido Simulado

		  Doctora Aurora Torres Soto

   Alumno: Joel Alejandro Espinoza Sánchez

  Fecha de Entrega: 3 de noviembre del 2020

Descripción:
*/
//Cargamos las librerías
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

void setValues1(float alpha, int autom, int K, int qv, float rho, float T, float Tfin, float *alphaP, int *automP, int *KP, int *qvP, float *rhoP, float *TP, float *TfinP);
void setValues2(int qv, int graph[qv][qv], int tour[qv + 1]);
int checkTour(int qv, int graph[qv][qv],int tour[qv + 1]);
void evaluateTour(int qv, int graph[qv][qv],int tour[qv + 1], int ftour, int *ftourP);
void backToTour(int qv, int tour[qv + 1],int newTour[qv + 1]);

main()
{
	setlocale(LC_ALL,"");
	srand(time(NULL));
	
	//1. Declaramos las variables que usaremos
	/*
		alpha: Factor de enfriamiento
		autom: Modo de acción, donde 0 será Manual y 1 Automático, que:
			   Si autom = 0 ejecutará todo el proceso rápidamente
			   Si autom = 1 ejecutará el proceso de uno en uno
		k: Iterador sobre K
		K: Número de iteraciones a cierta T
		qv: Cantidad de vértices
		r1: Un número aleatorio
		r2: Un número aleatorio
		r3: Un número aleatorio
		rho: Factor de reducción de iteraciones
		T: Temperatura actual
		Tfin: Temperatura final
	*/
	int autom, check, i, j, k, K, qv, r1, r2, r3a, repeat;
	float alpha, r3, rho, T, Tfin;
	
	printf("============================== RECOCIDO SIMULADO ==============================\n");
	
	do
	{
		alpha = 0.5;
		autom = 1;
		k = 0;
		K = 30;
		qv = 7;
		rho = 0.5;
		repeat = 0;
		T = 140;
		Tfin = 10;
		
		//2. Calibramos los primeros valores del programa
		setValues1(alpha,autom,K,qv,rho,T,Tfin,&alpha,&autom,&K,&qv,&rho,&T,&Tfin);
		
		//3. Declaramos más variables
		/*
			graph: La matriz de adyacencia del grafo que analizaremos
			tour: Un vector de dimensión qv que representa el viaje i
			ftour: La energía de tour
			newTour: Un vector igual a tour que representa el viaje J
			fnewTour: La energía de newTour
		*/
		int graph[qv][qv], tour[qv + 1], ftour, newTour[qv + 1], fnewTour;
		setValues2(qv,graph,tour);
		getchar();
		
		//4. Comenzamos el Recocido
		do
		{
			printf("\n");
			printf("\n");
			printf("\n");
			printf("Evaluamos con los valores:\n");
			printf("    T = %.4f\n",T);
			printf("    K = %.d\n",K);
			do
			{
				//5. Evaluamos el costo de tour
				evaluateTour(qv,graph,tour,ftour,&ftour);
				
				printf("\n");
				printf("  El tour [%d",tour[0]);
				for(i = 1; i <= qv; i++)
				{
					printf(", %d",tour[i]);
				}
				printf("] genera un costo de: %d\n",ftour);
				if(autom == 0)
				{
					getchar();
				}
				
				//6. Perturbaremos tour
				do
				{
					r1 = 2 + (rand() % ((qv - 1) - 2 + 1));
					r2 = (r1 + 1) + (rand() % (qv - (r1 + 1) + 1));
					
					//Construimos newTour con un subviaje inverso aleatorio de tour
					for(i = 0; i < r1; i++)
					{
						newTour[i] = tour[i];
					}
					
					j = 0;
					for(i = r1 - 1; i < r2; i++)
					{
						newTour[i] = tour[r2 - 1 - j];
						j++;
					}
					
					for(i = r2; i < qv + 1; i++)
					{
						newTour[i] = tour[i];
					}
					
					//No pasaremos a la siguiente fase hasta verificar que newTour sea un tour válido
					check = checkTour(qv,graph,newTour);
				}
				while(check == 0);
				
				//7. Evaluamos newTour
				evaluateTour(qv,graph,newTour,fnewTour,&fnewTour);
				
//				printf("r1 = %d\n",r1);
//				printf("r2 = %d\n",r2);
				printf("  El nuevo tour [%d",newTour[0]);
				for(i = 1; i <= qv; i++)
				{
					printf(", %d",newTour[i]);
				}
				printf("] genera un costo de: %d\n",fnewTour);
				if(autom == 0)
				{
					getchar();
				}
				
				//8. Evaluamos para minimizar (Para maximizar cambiamos el signo del condicional < por >)
				if(fnewTour < ftour)
				{
					printf("    Hemos escogido newTour (fnewTour < ftour)\n");
					if(autom == 0)
					{
						getchar();
					}
					backToTour(qv,tour,newTour);
					ftour = fnewTour;
				}
				else
				{
					printf("    No hemos escogido aún (fnewTour >= ftour)\n");
					if(autom == 0)
					{
						getchar();
					}
					
					r3a = rand() % 100;
					r3 = ((float)r3a)/100;
					if(r3 < (exp((ftour - fnewTour)/T)))
					{
						printf("      Hemos escogido newTour por probabilidad de Boltzmann (r3 = %.4f < %.4f)\n",r3,exp((ftour - fnewTour)/T));
						if(autom == 0)
						{
							getchar();
						}
						
						backToTour(qv,tour,newTour);
						ftour = fnewTour;
					}
					else
					{
						printf("      Hemos descartado newTour por probabilidad de Boltzmann (r3 = %.4f >= %.4f)\n",r3,exp((ftour - fnewTour)/T));
						if(autom == 0)
						{
							getchar();
						}
					}
				}
				
				k++;
			}
			while(k < K);
			
			T = alpha*T;
			K = rho*K;
			k = 0;
		}
		while(T > Tfin);
		
		printf("\n");
		printf("\n");
		printf("\n");
		printf("El tour final fue [%d",tour[0]);
		for(i = 1; i <= qv; i++)
		{
			printf(", %d",tour[i]);
		}
		printf("] que genera un costo de: %d\n",ftour);
		
		printf("\n");
		printf("\n");
		printf("\n");
		printf("¿Desea repetir el código?\n");
		printf("0. No\n");
		printf("1. Sí\n");
		scanf("%d",&repeat);
	}
	while(repeat == 1);
	
	getchar();
}

void setValues1(float alpha, int autom, int K, int qv, float rho, float T, float Tfin, float *alphaP, int *automP, int *KP, int *qvP, float *rhoP, float *TP, float *TfinP)
{
	int aux, done = 0;
	*alphaP = alpha;
	*automP = autom;
	*KP = K;
	*qvP = qv;
	*rhoP = rho;
	*TP = T;
	*TfinP = Tfin;
	
	do
	{
		printf("\n");
		printf("--------------------------------\n");
		printf("|  Calibración del algoritmo:\n");
		printf("|  Seleccione algún número si desea cambiar su valor (o 0 para continuar):\n");
		printf("|  0: Listo. Continuar\n");
		printf("|  1: T0 (Temperatura inicial): %.4f\n",T);
		printf("|  2: Tfin (Temperatura final): %.4f\n",Tfin);
		printf("|  3: alpha (Factor de enfriamiento): %.4f\n",alpha);
		printf("|  4: rho (Factor de reducción de iteraciones): %.4f\n",rho);
		printf("|  5: K (Número de iteraciones en T): %d\n",K);
		printf("|  6: qv (Cantidad de vértices que posee el grafo): %d\n",qv);
		printf("|  7: autom (Modo de acción): %d\n",autom);
		printf("|  ");
		scanf("%d",&aux);
		
		switch (aux)
		{
			case 0:
				{
					//Se continúa con el programa
					done = 1;
					break;
				}
			case 1:
				{
					//Se modifica T
					
					printf("|     Inserte un nuevo valor para T0 (Antiguo valor para T0: T0 = %.4f)\n",T);
					printf("|  ");
					scanf("%f",&T);
					*TP = T;
					
					break;
				}
			case 2:
				{
					//Se modifica Tfin
					
					printf("|     Inserte un nuevo valor para Tfin (Antiguo valor para Tfin: Tfin = %.4f)\n",Tfin);
					printf("|  ");
					scanf("%f",&Tfin);
					*TfinP = Tfin;
					
					break;
				}
			case 3:
				{
					//Se modifica alpha
					
					printf("|     Inserte un nuevo valor para alpha (Antiguo valor para alpha: alpha = %.4f)\n",alpha);
					printf("|  ");
					scanf("%f",&alpha);
					*alphaP = alpha;
					
					break;
				}
			case 4:
				{
					//Se modifica rho
					
					printf("|     Inserte un nuevo valor para rho (Antiguo valor para rho: rho = %.4f)\n",rho);
					printf("|  ");
					scanf("%f",&rho);
					*rhoP = rho;
					
					break;
				}
			case 5:
				{
					//Se modifica K
					
					printf("|     Inserte un nuevo valor para K (Antiguo valor para K: K = %d)\n",K);
					printf("|  ");
					scanf("%d",&K);
					*KP = K;
					
					break;
				}
			case 6:
				{
					//Se modifica qv
					
					printf("|     Inserte un nuevo valor para qv (Antiguo valor para qv: qv = %d)\n",qv);
					printf("|  ");
					scanf("%d",&qv);
					*qvP = qv;
					
					break;
				}
			case 7:
				{
					//Se modifica autom
					
					printf("|     Inserte un nuevo valor para autom (Antiguo valor para autom: autom = %d)\n",autom);
					printf("|  ");
					scanf("%d",&autom);
					*automP = autom;
					
					break;
				}
			default:
				{
					//Valor no válido
					
					printf("|     Ha insertado un número inválido\n");
					
					break;
				}
		}
	}
	while(done == 0);
	
	return;
}

void setValues2(int qv, int graph[qv][qv], int tour[qv + 1])
{
	int aux, done = 0,i,j;
	do
	{
		printf("\n");
		printf("--------------------------------\n");
		printf("|  Calibración del algoritmo:\n");
		printf("|  Seleccione algún número si desea cambiar su valor (o 0 para continuar):\n");
		printf("|  0: Listo. Continuar\n");
		printf("|  1: graph (El grafo a evaluar):\n");
		for(i = 0; i < qv; i++)
		{
			printf("|     ");
			for(j = 0; j < qv; j++)
			{
				printf("[%d] ",graph[i][j]);
			}
			printf("\n");
		}
		printf("|  2: tour (El viaje inicial):\n");
		printf("|     ");
		for(i = 0; i <= qv; i++)
		{
			printf("[%d] ",tour[i]);
		}
		printf("\n");
		printf("|  ");
		scanf("%d",&aux);
		
		switch (aux)
		{
			case 0:
				{
					//Se continúa con el programa
					done = 1;
					break;
				}
			case 1:
				{
					//Se modifica graph
					
					for(i = 0; i < qv; i++)
					{
						for(j = 0; j < qv; j++)
						{
							printf("|     Inserte el peso de la arista que une al vértice %d con el vértice %d (0 para indicar que no existe tal unión)\n",i + 1, j + 1);
							printf("|  ");
							scanf("%d",&graph[i][j]);
						}
					}
					
					break;
				}
			case 2:
				{
					//Se modifica tour
					
					for(i = 0; i <= qv; i++)
					{
						printf("|     Inserte el vértice que se visitará en la parada %d\n",i);
						printf("|  ");
						scanf("%d",&tour[i]);
					}
					
					break;
				}
			default:
				{
					//Valor no válido
					
					printf("|     Ha insertado un número inválido\n");
					
					break;
				}
		}
	}
	while(done == 0);
	
	return;
}

int checkTour(int qv, int graph[qv][qv],int tour[qv + 1])
{
	int i;
	for(i = 0; i < qv; i++)
	{
		if(graph[tour[i] - 1][tour[i + 1] - 1] == 0)
		{
			return 0;
		}
	}
	
	return 1;
}

void evaluateTour(int qv, int graph[qv][qv],int tour[qv + 1], int ftour, int *ftourP)
{
	int i;
	*ftourP = ftour;
	
	ftour = 0;
	for(i = 0; i < qv; i++)
	{
		ftour = ftour + graph[tour[i] - 1][tour[i + 1] - 1];
	}
	
	*ftourP = ftour;
	return;
}

void backToTour(int qv, int tour[qv + 1],int newTour[qv + 1])
{
	int i;
	for(i = 0; i <=qv; i++)
	{
		tour[i] = newTour[i];
	}
	return;
}
