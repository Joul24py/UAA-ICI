/*
    Universidad Aut�noma de Aguascalientes

		  Centro de Ciencias B�sicas
  Departamento de Ciencias de la Computaci�n
		       Metaheur�sticas I

					7� "A"

   			   Evaluaci�n Final

	 Profesor: Francisco Javier Luna Rosas

     Alumnos:
     		  Almeida Ortega Andrea Melissa
     		  Espinoza S�nchez Joel Alejandro
     		  Flores Fern�ndez �scar Alonso
     		  G�mez Garza Dariana
     		  Gonz�lez Arenas Fernando Francisco
     		  Orocio Garc�a Hiram Efra�n

  Fecha de Entrega: 25 de noviembre del 2021

*/
//Cargamos las librer�as
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

void setValues1(float alpha, int autom, float beta, float Q, int qh, int qv, float rho, float taui,float *alphaP, int *automP, float *betaP, float *QP, int *qhP, int *qvP, float *rhoP, float *tauiP);
void fillMatrix1D(int a, float matrix[a], float n);
void fillMatrix2D(int a, int b, float matrix[a][b], float n);
void fillMatrix3D(int a, int b, int c, float matrix[a][b][c], float n);
void setValues2(int qv, int qh, float graph[qv][qv], float pheromone[qv][qv], float vision[qv][qv], float beginEnd[qh][2]);
void startProcess(int i, int qh, int qv, float tabu[qh][qv], float beginEnd[qh][2], float availableV[qv]);
int acceptVertex(int i, int qh, int qv, int value, float tabu[qh][qv]);
int getL(int i, int qh, int qv, float graph[qv][qv], float tabu[qh][qv], float beginEnd[qh][2]);

main()
{
	setlocale(LC_ALL,"");
	srand(time(NULL));
	
	//1. Declaramos las variables que usaremos
	/*
		qv: Cantidad de v�rtices del grafo
		qh: Cantidad de hormigas
		tau: Valor de la feromona inicial
		Q: Par�metro
		alpha: Par�metro
		beta: Par�metro
		rho: Par�metro
		autom: Modo de acci�n (Para autom >=1 se tomar� el n�mero de autom como las repeticiones)
		repeat: Sirve para repetir todo el c�digo nuevamente
		repeat1: Sirve para repetir la colonia en modo manual
		r: N�mero aleatorio
		accepted: Bandera de aceptaci�n de v�rtice
		checkIfStuck: Iterador que no tolerar� un n�mero determinado de iteraciones. Si se alcanzan, se interpretar� que la hormiga se encerr�
		L: Longitud del recorrido completo realizado por la hormiga
	*/
	int qv, qh, autom, repeat, repeat1, repeat2, accepted, checkIfStuck, L, h, i, j, k, ip, jp, kp;
	float tau, Q, alpha, beta, rho, r;
	
	printf("============================== COLONIA DE HORMIGAS ==============================\n");
	
	do
	{
		alpha = 0.15;
		autom = 10;
		beta = 0.25;
		Q = 200;
		qh = 5;
		qv = 15;
		repeat = 0;
		rho = 0.01;
		tau = 0.1;
		
		//2. Calibramos los primeros valores del programa
		setValues1(alpha,autom,beta,Q,qh,qv,rho,tau,&alpha,&autom,&beta,&Q,&qh,&qv,&rho,&tau);
		
		//3. Declaramos m�s variables
		/*
			graph: La matriz de adyacencia del grafo que analizaremos														INT
			pheromone: La matriz de feromonas																				FLOAT
			vision: La matriz de visibilidad																				FLOAT
			tabu: La lista tab�																								INT
			beginEnd: Matriz con los valores de inicio y fin de cada hormiga												INT
			availableV: Vector donde cada elemento representa cada v�rtice del grafo (1 est� disponible o 0 no lo est�)		INT
			prob: Probabilidad individual y acumulada de tomar cada nodo													FLOAT
			dtau: La diferencia de tau que hay por hormiga en cada nodo														FLOAT
		*/
		float graph[qv][qv], pheromone[qv][qv], vision[qv][qv], tabu[qh][qv], beginEnd[qh][2], availableV[qv], prob[qv][2], dtau[qh][qv][qv];
		
		//4. Inicializamos las estructuras
		//Limpiamos graph
		fillMatrix2D(qv,qv,graph,0);
		
		//Inicializamos pheromone
		fillMatrix2D(qv,qv,pheromone,tau);
		
		//Limpiamos vision
		fillMatrix2D(qv,qv,vision,0);
		
		//Limpiamos tabu
		fillMatrix2D(qh,qv,tabu,0);
		
		//Limpiamos beginEnd
		fillMatrix2D(qh,2,beginEnd,0);
		
		//Inicializamos availableV
		fillMatrix1D(qv,availableV,1);
		
		//Limpiamos prob
		fillMatrix2D(qv,2,prob,0);
		
		//5. Calibramos los dem�s valores del programa
		setValues2(qv,qh,graph,pheromone,vision,beginEnd);
		
		//Inicializamos vision
		for(i = 0; i < qv; i++)
		{
			for(j = 0; j < qv; j++)
			{
				if(graph[i][j] == 0)
				{
					vision[i][j] = 0;
				}
				else
				{
					vision[i][j] = (pow(pheromone[i][j],alpha))/(pow(graph[i][j],beta));
				}
			}
		}
		
		printf("\n\n\n\n");
		
		if(autom == 0)
		{
			printf("El grafo a evaluar es:\n");
			for(ip = 0; ip < qv; ip++)
			{
				for(jp = 0; jp < qv; jp++)
				{
					printf("[%d] ", (int)graph[ip][jp]);
				}
				printf("\n");
			}
			printf("\n");
			
			printf("La matriz de feromonas antes del comienzo del algoritmo es:\n");
			for(ip = 0; ip < qv; ip++)
			{
				for(jp = 0; jp < qv; jp++)
				{
					printf("[%.4f] ", pheromone[ip][jp]);
				}
				printf("\n");
			}
			printf("\n");
			
			printf("La matriz de visibilidad, entonces, es:\n");
			for(ip = 0; ip < qv; ip++)
			{
				for(jp = 0; jp < qv; jp++)
				{
					printf("[%.4f] ", vision[ip][jp]);
				}
				printf("\n");
			}
			printf("\n");
			getchar();
			getchar();
		}
		
		//6. Comenzamos la colonia de hormigas, la cual se repetir� tantas veces como se haya calibrado autom (si es 0, se decide el paro)
		h = 0;
		repeat2 = 1;
		do
		{
			//Inicializamos dtau
			fillMatrix3D(qh,qv,qv,dtau,0);
			
			if(autom == 0)
			{
				printf("\n");
				printf("\n");
				printf("Comenzamos la %d� iteraci�n\n\n", h + 1);
			}
			
			//El procedimiento de la colonia se har� para cada hormiga
			i = 0;
			do
			{
				if(autom == 0)
				{
					printf("  Comenzamos a trabajar con la hormiga %d\n", i + 1);
					getchar();
				}
				
				//Inicializamos tabu y availableV con los valores proporcionados por beginEnd
				startProcess(i,qh,qv,tabu,beginEnd,availableV);
				
				if(autom == 0)
				{
					printf("    Inicializamos la lista tab� con el valor del nodo de inicio:\n    ");
					for(ip = 0; ip < qh; ip++)
					{
						for(jp = 0; jp < qv; jp++)
						{
							printf("[%d] ", (int)tabu[ip][jp]);
						}
						printf("\n    ");
					}
					printf("\n");
					
					printf("    Inicializamos la lista de nodos disponibles:\n    ");
					for(ip = 0; ip < qv; ip++)
					{
						printf("[%d] ", (int)availableV[ip]);
					}
					printf("\n");
					
					getchar();
				}
				
				//Todav�a, el procedimiento de selecci�n de camino de cada hormiga tiene que hacerse por cada nodo como m�ximo qv - 1 veces
				j = 0;
				do
				{
					if(autom == 0)
					{
						printf("\n");
						printf("      Escogeremos el nodo %d\n", j + 1);
					}
					
					//Debemos repetir este an�lisis hasta que el nodo haya sido reconocido como v�lido
					accepted = 0;
					checkIfStuck = 0;
					do
					{
						//A partir del nodo otorgado, vamos al rengl�n en vision con el que rellenaremos prob y procedemos a rellenar prob
						prob[0][0] = vision[(int)tabu[i][j] - 1][0];
						prob[0][1] = prob[0][0];
						for(k = 1; k < qv; k++)
						{
							prob[k][0] = vision[(int)tabu[i][j] - 1][k];
							prob[k][1] = prob[k][0] + prob[k - 1][1];
						}
						
						//Generamos un n�mero aleatorio y discretizamos el valor entre 10000 posibilidades, todas dentro del rango
						r = rand() % 10000;
						r = r/(10000/prob[qv - 1][1]);
						
						if(autom == 0)
						{
							printf("        Tenemos las probabilidades individuales y acumuladas de que de %d se vaya a\n",(int)tabu[i][j]);
							for(ip = 0; ip < qv; ip++)
							{
								printf("            %d:     ", ip + 1);
								for(jp = 0; jp < 2; jp++)
								{
									printf("[%.4f]     ", prob[ip][jp]);
								}
								printf("\n");
							}
							printf("\n");
						}
						
						//Ubicaremos el nodo seleccionado
						for(k = 0; k < qv; k++)
						{
							if(r < prob[k][1])
							{
								//Encontramos que cay� en k + 1
								break;
							}
						}
						
						if(autom == 0)
						{
							printf("      Hemos escogido el nodo %d (r = %.4f)\n",k + 1,r);
						}
						
						//Ahora toca validar si ese men est� disponible o no
						accepted = acceptVertex(i,qh,qv,k+1,tabu);
						
						if(autom == 0)
						{
							if(accepted == 1)
							{
								printf("      Revisando el nodo %d con tab�, obtuvimos que �ste es aceptado\n", k + 1);
							}
							else
							{
								printf("      Revisando el nodo %d con tab�, obtuvimos que �ste no es aceptado\n", k + 1);
							}
						}
						
						//Tambi�n tenemos que validar si la hormiga no se qued� encerrada
						if(accepted == 0)
						{
							checkIfStuck++;
							
							if(autom == 0)
							{
								printf("      Tendremos que repetir la selecci�n aleatoria por posible encrucijada (La hormiga lleva %d repeticiones)\n", checkIfStuck);
							}
						}
						
						if(checkIfStuck == 100)
						{
							if(autom == 0)
							{
								printf("      Hemos interpretado que la hormiga se qued� atorada\n Reiniciaremos el proceso completo\n");
							}
							
							startProcess(i,qh,qv,tabu,beginEnd,availableV);
							checkIfStuck = 0;
							j = 0;
						}
					}
					while(accepted == 0);
					
					//Hemos aceptado el nodo, vamos a actualizar la lista tab� y availableV
					j++;
					tabu[i][j] = k + 1;
					availableV[(int)tabu[i][j] - 1] = 0;
					
					if(autom == 0)
					{
						printf("      Hemos aceptado el nodo. Ahora tenemos el camino siguiente\n      ");
						for(ip = 0; ip < qh; ip++)
						{
							for(jp = 0; jp < qv; jp++)
							{
								printf("[%d] ", (int)tabu[ip][jp]);
							}
							printf("\n      ");
						}
						for(ip = 0; ip < qv; ip++)
						{
							printf("[%d] ", (int)availableV[ip]);
						}
						printf("\n");
					}
					
					//Chequemos si el nodo aceptado es el definido como el �ltimo. As� la hormiga se sentir� realizada
					if(k + 1 == beginEnd[i][1])
					{
						if(autom == 0)
						{
							printf("      Hemos llegado al nodo objetivo\n");
						}
						break;
					}
				}
				while(j < qv - 1);
				
				L = getL(i,qh,qv,graph,tabu,beginEnd);
				
				if(autom == 0)
				{
					printf("\n");
					printf("    La hormiga produjo un recorrido de L = %d\n",L);
					getchar();
				}
				
				if(autom != 0)
				{
					for(ip = 0; ip < qh; ip++)
					{
						printf("En la iteraci�n %d, la hormiga %d produjo el camino:\n",h + 1, i + 1);
						for(jp = 0; jp < qv; jp++)
						{
							printf("[%d] ", (int)tabu[ip][jp]);
						}
						printf("\n");
						L = getL(ip,qh,qv,graph,tabu,beginEnd);
						printf("Con un recorrido de valor %d\n",L);
					}
				}
				
				for(j = 0; j < qv; j++)
				{
					if((int)tabu[i][j] == (int)beginEnd[i][1])
					{
						break;
					}
					else
					{
						dtau[i][(int)tabu[i][j] - 1][(int)tabu[i][j + 1] - 1] = Q/L;
					}
				}
				
				if(autom == 0)
				{
					printf("    Se ha generado el siguiente incremento de feromonas:\n    ");
					for(jp = 0; jp < qv; jp++)
					{
						for(kp = 0; kp < qv; kp++)
						{
							printf("[%.4f] ", dtau[i][jp][kp]);
						}
						printf("\n    ");
					}
					getchar();
				}
				
				i++;
			}
			while(i < qh);
			
			//Las hormigas han llegado al nodo destino, ahora procedemos a actualizar pheromone
			for(j = 0; j < qv; j++)
			{
				for(k = 0; k < qv; k++)
				{
					for(i = 0; i < qh; i++)
					{
						dtau[0][j][k] = dtau[0][j][k] + dtau[i][j][k];
					}
					pheromone[j][k] = ((1-rho)*(pheromone[j][k])) + dtau[0][j][k];
				}
			}
			
			if(autom == 0)
			{
				printf("    Tras el incremento y evaporaci�n de feromonas, la nueva matriz de feromonas es:\n    ");
				for(jp = 0; jp < qv; jp++)
				{
					for(kp = 0; kp < qv; kp++)
					{
						printf("[%.4f] ", pheromone[jp][kp]);
					}
					printf("\n    ");
				}
				getchar();
			}
			
			
			
			//La colonia de hormigas ha finalizado, preguntamos por una nueva iteraci�n o terminar el programa, seg�n sea el caso
			if(autom == 0)
			{
				printf("�Desea usar un nuevo grupo de hormigas?\n");
				printf("0. No\n");
				printf("1. S�\n");
				scanf("%d",&repeat1);
				if(repeat1 == 0)
				{
					repeat2 = 0;
				}
				if(repeat1 == 1)
				{
					repeat2 = 1;
				}
				h++;
			}
			else
			{
				h++;
				if(h == autom)
				{
					repeat2 = 0;
					printf("\n");
				}
			}
		}
		while(repeat2 == 1);
		
		printf("=============== Reporte Final ===============\n");
		printf("Hemos analizado el grafo:\n");
		for(ip = 0; ip < qv; ip++)
		{
			for(jp = 0; jp < qv; jp++)
			{
				printf("[%d] ", (int)graph[ip][jp]);
			}
			printf("\n");
		}
		printf("\n");
		
		printf("La matriz de feromonas resultante es:\n");
		for(ip = 0; ip < qv; ip++)
		{
			for(jp = 0; jp < qv; jp++)
			{
				printf("[%.4f] ", pheromone[ip][jp]);
			}
			printf("\n");
		}
		printf("\n");
		
		printf("La matriz de visibilidad resultante es:\n");
		for(ip = 0; ip < qv; ip++)
		{
			for(jp = 0; jp < qv; jp++)
			{
				printf("[%.4f] ", vision[ip][jp]);
			}
			printf("\n");
		}
		printf("\n");
		
		
		
		
		printf("\n");
		printf("\n");
		printf("\n");
		printf("�Desea repetir el c�digo?\n");
		printf("0. No\n");
		printf("1. S�\n");
		scanf("%d",&repeat);
	}
	while(repeat == 1);
	
	getchar();
}

void setValues1(float alpha, int autom, float beta, float Q, int qh, int qv, float rho, float taui,float *alphaP, int *automP, float *betaP, float *QP, int *qhP, int *qvP, float *rhoP, float *tauiP)
{
	int aux, done = 0;
	*alphaP = alpha;
	*automP = autom;
	*betaP = beta;
	*QP = Q;
	*qhP = qh;
	*qvP = qv;
	*rhoP = rho;
	*tauiP = taui;
	
	do
	{
		printf("\n");
		printf("--------------------------------\n");
		printf("|  Calibraci�n del algoritmo:\n");
		printf("|  Seleccione alg�n n�mero si desea cambiar su valor (o 0 para continuar):\n");
		printf("|  0: Listo. Continuar\n");
		printf("|  1: taui (Tau inicial): %.4f\n",taui);
		printf("|  2: alpha (a): %.4f\n",alpha);
		printf("|  3: beta (a): %.4f\n",beta);
		printf("|  4: rho (a): %.4f\n",rho);
		printf("|  5: Q (a): %.4f\n",Q);
		printf("|  6: qh (Cantidad de hormigas): %d\n",qh);
		printf("|  7: qv (Cantidad de v�rtices que posee el grafo): %d\n",qv);
		printf("|  8: autom (Modo de acci�n): %d\n",autom);
		printf("|  ");
		scanf("%d",&aux);
		
		switch (aux)
		{
			case 0:
				{
					//Se contin�a con el programa
					done = 1;
					break;
				}
			case 1:
				{
					//Se modifica taui
					
					printf("|     Inserte un nuevo valor para taui (Antiguo valor para taui: T0 = %.4f)\n",taui);
					printf("|  ");
					scanf("%f",&taui);
					*tauiP = taui;
					
					break;
				}
			case 2:
				{
					//Se modifica alpha
					
					printf("|     Inserte un nuevo valor para alpha (Antiguo valor para alpha: alpha = %.4f)\n",alpha);
					printf("|  ");
					scanf("%f",&alpha);
					*alphaP = alpha;
					
					break;
				}
			case 3:
				{
					//Se modifica beta
					
					printf("|     Inserte un nuevo valor para alpha (Antiguo valor para beta: beta = %.4f)\n",beta);
					printf("|  ");
					scanf("%f",&beta);
					*betaP = beta;
					
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
					//Se modifica Q
					
					printf("|     Inserte un nuevo valor para K (Antiguo valor para Q: Q = %.4f)\n",Q);
					printf("|  ");
					scanf("%f",&Q);
					*QP = Q;
					
					break;
				}
			case 6:
				{
					//Se modifica qh
					
					printf("|     Inserte un nuevo valor para qh (Antiguo valor para qh: qh = %d)\n",qh);
					printf("|  ");
					scanf("%d",&qh);
					*qhP = qh;
					
					break;
				}
			case 7:
				{
					//Se modifica qv
					
					printf("|     Inserte un nuevo valor para qv (Antiguo valor para qv: qv = %d)\n",qv);
					printf("|  ");
					scanf("%d",&qv);
					*qvP = qv;
					
					break;
				}
			case 8:
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
					//Valor no v�lido
					
					printf("|     Ha insertado un n�mero inv�lido\n");
					
					break;
				}
		}
	}
	while(done == 0);
	
	return;
}

void fillMatrix1D(int a, float matrix[a], float n)
{
	int i,j;
	for(i = 0; i < a; i++)
	{
		matrix[i] = n;
	}
	return;
}

void fillMatrix2D(int a, int b, float matrix[a][b], float n)
{
	int i,j;
	for(i = 0; i < a; i++)
	{
		for(j = 0; j < b; j++)
		{
			matrix[i][j] = n;
		}
	}
	return;
}

void fillMatrix3D(int a, int b, int c, float matrix[a][b][c], float n)
{
	int i,j,k;
	for(i = 0; i < a; i++)
	{
		for(j = 0; j < b; j++)
		{
			for(k = 0; k < c; k++)
			{
				matrix[i][j][k] = n;
			}
		}
	}
	return;
}

void setValues2(int qv, int qh, float graph[qv][qv], float pheromone[qv][qv], float vision[qv][qv], float beginEnd[qh][2])
{
	int aux, done = 0,i,j;
	do
	{
		printf("\n");
		printf("--------------------------------\n");
		printf("|  Calibraci�n del algoritmo:\n");
		printf("|  Seleccione alg�n n�mero si desea cambiar su valor (o 0 para continuar):\n");
		printf("|  0: Listo. Continuar\n");
		printf("|  1: graph (El grafo a evaluar):\n");
		for(i = 0; i < qv; i++)
		{
			printf("|     ");
			for(j = 0; j < qv; j++)
			{
				printf("[%d] ",(int)graph[i][j]);
			}
			printf("\n");
		}
		printf("|  2: BeginEnd (Los puntos de inicio y final de cada hormiga):\n");
		for(i = 0; i < qh; i++)
		{
			printf("|     ");
			for(j = 0; j < 2; j++)
			{
				printf("[%d] ",(int)beginEnd[i][j]);
			}
			printf("\n");
		}
		printf("|  ");
		scanf("%d",&aux);
		
		switch (aux)
		{
			case 0:
				{
					//Se contin�a con el programa
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
							printf("|     Inserte el peso de la arista que une al v�rtice %d con el v�rtice %d (0 para indicar que no existe tal uni�n)\n",i + 1, j + 1);
							printf("|  ");
							scanf("%f",&graph[i][j]);
						}
					}
					
					break;
				}
			case 2:
				{
					//Se modifican los puntos de arranque y fin de cada hormiga (tabu)
					
					for(i = 0; i < qh; i++)
					{
						printf("|     Inserte el nodo inicial de la hormiga %d:\n",i + 1);
						printf("|  ");
						scanf("%f",&beginEnd[i][0]);
						printf("|     Inserte el nodo final de la hormiga %d:\n",i + 1);
						printf("|  ");
						scanf("%f",&beginEnd[i][1]);
					}
					
					break;
				}
		}
	}
	while(done == 0);
}

void startProcess(int i, int qh, int qv, float tabu[qh][qv], float beginEnd[qh][2], float availableV[qv])
{
	int j;
	
	for(j = 0; j < qv; j++)
	{
		tabu[i][j] = 0;
		availableV[j] = 1;
	}
	
	tabu[i][0] = (int)beginEnd[i][0];
	availableV[(int)tabu[i][0] - 1] = 0;
	
	return;
}

int acceptVertex(int i, int qh, int qv, int value, float tabu[qh][qv])
{
	int j;
	for(j = 0; j < qv; j++)
	{
		if((int)tabu[i][j] == value)
		{
			return 0;
		}
	}
	return 1;
}

int getL(int i, int qh, int qv, float graph[qv][qv], float tabu[qh][qv], float beginEnd[qh][2])
{
	int j, L = 0;
	for(j = 0; j < qv; j++)
	{
		if((int)tabu[i][j] == (int)beginEnd[i][1])
		{
			return L;
		}
		else
		{
			L = L + graph[(int)tabu[i][j] - 1][(int)tabu[i][j + 1] - 1];
		}
	}
}
