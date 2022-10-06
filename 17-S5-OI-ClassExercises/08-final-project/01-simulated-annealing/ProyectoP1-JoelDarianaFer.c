/*
    Universidad Autónoma de Aguascalientes

		  Centro de Ciencias Básicas
  Departamento de Ciencias de la Computación
		   Optimización Inteligente

					5° "A"

   	  Proyecto Parte 1: Recocido Simulado

		  Doctora Aurora Torres Soto

   				  Alumnos:
   		Espinoza Sánchez Joel Alejandro
   		Gómez Garza Dariana
   		González Arenas Fernando Francisco

  Fecha de Entrega: 23 de noviembre del 2020
*/

//Cargamos las librerías
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <string.h>

//Definimos las funciones que usaremos
void setValues1(float alpha, int autom, int disturbance, int instance, int K, float p, int qv, float rho, float T, float Tfin, float *alphaP, int *automP, int *disturbanceP, int *instanceP, int *KP, float *pP, int *qvP, float *rhoP, float *TP, float *TfinP);
void setValues2(int qv, int graph[qv][qv], int tour[qv + 1]);
void fillMatrix1D(int a, int matrix[a], int n);
void setInstance21(int qv, float graph[qv][qv]);
void setInstance100(int qv, float graph[qv][qv]);
void setTour(int qv, int tour[qv + 1], int availableV[qv]);
int checkTour(int qv, float graph[qv][qv],int tour[qv + 1]);
void evaluateTour(int qv, float graph[qv][qv],int tour[qv + 1], float ftour, float *ftourP);
void backToTour(int qv, int tour[qv + 1],int newTour[qv + 1]);

main()
{
	setlocale(LC_ALL,"");
	srand(time(NULL));
	
	//1. Declaramos las variables que usaremos
	/*
		alpha: Factor de enfriamiento del recocido
		autom: Modo de acción del recocido, donde 0 será Manual y 1 Automático, que:
			   Si autom = 0 ejecutará todo el proceso rápidamente
			   Si autom = 1 ejecutará el proceso de uno en uno
		check: Variable de verificación para los tours del recocido
		disturbance: Modo del mecanismo de perturbación, donde:
					 Si disturbance = 1 se realizará como mecanismo de perturbación el subviaje inverso
					 Si disturbance = 2 se realizará como mecanismo de perturbación la elección e inversión de dos nodos aleatorios
		i: Iterador general
		instance: Instancia que se usará en el recocido, donde:
				  Si instance = 0 ejecutará un proceso personalizado
				  Si instance = 1 ejecutará el proceso de la instancia pequeña
				  Si instance = 2 ejecutará el proceso de la instancia grande
		j: Iterador general
		k: Iterador sobre K del recocido
		K: Número de iteraciones a cierta T del recocido
		p: Probabilidad de perturbar los nodos de inicio y fin
		qv: Cantidad de vértices del grafo
		r1: Un número aleatorio para el recocido
		r2: Un número aleatorio para el recocido
		r3: Un número aleatorio para el recocido
		r3a: Auxiliar entero de r3
		repeat: Verificador para repetir el código del recocido nuevamente
		rho: Factor de reducción de iteraciones del recocido
		T: Temperatura actual del recocido
		Tfin: Temperatura final del recocido
	*/
	int autom, check, disturbance, i, instance, j, k, K, qv, r1, r2, r3a, repeat;
	float alpha, p, r3, rho, T, Tfin;
	
	printf("============================== RECOCIDO SIMULADO ==============================\n");
	
	do
	{
		//2. Establecemos algunos valores estándares (algunos podrán ser modificados más adelante, otros son variables de control)
		alpha = 0.5;
		autom = 1;
		disturbance = 1;
		k = 0;
		K = 30;
		p = 0.5;
		qv = 7;
		rho = 0.5;
		repeat = 0;
		T = 140;
		Tfin = 10;
		
		//3. Calibramos este primer conjunto de valores del algoritmo
		printf("\n");
		printf("--------------------------------\n");
		printf("|  Calibración del algoritmo:\n");
		printf("|  Seleccione la instancia a trabajar:\n");
		printf("|    0: Grafo Personalizado\n");
		printf("|    1: Instancia pequeña (gr21.tsp)\n");
		printf("|    2: Instancia grande (kroD100.tsp)\n");
		printf("|  ");
		scanf("%d",&instance);
		
		setValues1(alpha,autom,disturbance,instance,K,p,qv,rho,T,Tfin,&alpha,&autom,&disturbance,&instance,&K,&p,&qv,&rho,&T,&Tfin);
		
		//4. Declaramos más variables
		/*
			availableV: Vector que tendrá los vértices disponibles para hacer un tour aleatorio
			graph: La matriz de adyacencia del grafo que analizaremos
			tour: Un vector de dimensión qv que representa el viaje i
			ftour: La energía de tour
			newTour: Un vector igual a tour que representa el viaje J
			fnewTour: La energía de newTour
		*/
		int availableV[qv], tour[qv + 1], newTour[qv + 1];
		float graph[qv][qv], ftour, fnewTour;
		
		//5. Calibramos este segundo conjunto de valores del algoritmo
		if(instance == 1)
		{
			setInstance21(qv,graph);
		}
		if(instance == 2)
		{
			setInstance100(qv,graph);
		}
		
		//6. Construimos un tour inicial aleatorio
		do
		{
			fillMatrix1D(qv,availableV,1);
			setTour(qv,tour,availableV);
			//No pasaremos a la siguiente fase hasta verificar que newTour sea un tour válido
			check = checkTour(qv,graph,tour);
		}
		while(check == 0);
		
		if(instance == 0)
		{
			setValues2(qv,graph,tour);
		}
		
		//7. El programa ha terminado de calibrarse, ahora comenzamos el recocido
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
				//8. Evaluamos el costo de tour
				evaluateTour(qv,graph,tour,ftour,&ftour);
				
				printf("\n");
				printf("  El tour [%d",tour[0]);
				for(i = 1; i <= qv; i++)
				{
					printf(", %d",tour[i]);
				}
				printf("] genera un costo de: %.4f\n",ftour);
				if(autom == 0)
				{
					getchar();
				}
				
				//9. Perturbaremos tour
				r3a = rand() % 100;
				r3 = ((float)r3a)/100;
				if(r3 < p)
				{
					//9.1 Perturbación: Modificación de los nodos de inicio y fin
					do
					{
						r1 = rand() % qv;
						
						for(i = 0; i < qv; i++)
						{
							if(tour[i] == r1)
							{
								newTour[i] = tour[qv];
							}
							else
							{
								newTour[i] = tour[i];
							}
						}
						newTour[0] = r1;
						newTour[qv] = r1;
						
						//No pasaremos a la siguiente fase hasta verificar que newTour sea un tour válido
						check = checkTour(qv,graph,newTour);
					}
					while(check == 0);
					printf("  Ocurrió una perturbación en los nodos de inicio y fin del tour\n");
				}
				else
				{
					//9.2 Perturbación: Subviaje inverso
					if(disturbance == 1)
					{
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
						printf("  Ocurrió una perturbación del tipo subviaje inverso\n");
					}
					
					//9.3 Perturbación: Elección e inversión de dos nodos aleatorios
					if(disturbance == 2)
					{
						do
						{
							r1 = 2 + (rand() % ((qv - 1) - 2 + 1));
							r2 = (r1 + 1) + (rand() % (qv - (r1 + 1) + 1));
							
							//Construimos newTour invirtiendo dos nodos aleatorios de tour
							for(i = 0; i < qv + 1; i++)
							{
								newTour[i] = tour[i];
							}
							
							newTour[r2 - 1] = tour[r1 - 1];
							newTour[r1 - 1] = tour[r2 - 1];
							
							//No pasaremos a la siguiente fase hasta verificar que newTour sea un tour válido
							check = checkTour(qv,graph,newTour);
						}
						while(check == 0);
						printf("  Ocurrió una perturbación del tipo elección e inversión de dos nodos aleatorios\n");
					}
				}
				
				//10. Evaluamos newTour
				evaluateTour(qv,graph,newTour,fnewTour,&fnewTour);
				
				//Debugging: Revisión de que r1 y r2 trabajen bien (Se pueden eliminar las dos diagonales para que se muestre la información)
//				printf("r1 = %d\n",r1);
//				printf("r2 = %d\n",r2);
				printf("  El nuevo tour [%d",newTour[0]);
				for(i = 1; i <= qv; i++)
				{
					printf(", %d",newTour[i]);
				}
				printf("] genera un costo de: %.4f\n",fnewTour);
				if(autom == 0)
				{
					getchar();
				}
				
				//11. Evaluamos para minimizar (Para maximizar cambiamos el signo del condicional < por >)
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
					
					//Se discretiza la generación de entero aleatorios a decimales
					r3a = rand() % 100;
					r3 = ((float)r3a)/100;
					if(r3 < (exp((ftour - fnewTour)/T)))
					{
						printf("      Hemos escogido newTour por probabilidad de Boltzmann (r3 = %.4f < %.4f)\n",r3,exp((ftour - fnewTour)/T));
						if(autom == 0)
						{
							getchar();
						}
						
						//Preparamos tour para una nueva iteración
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
		
		//12. El programa ha terminado, preguntamos si el usuario quiere volver a hacer el procedimiento
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

//Calibramos los valores simples del programa
void setValues1(float alpha, int autom, int disturbance, int instance, int K, float p, int qv, float rho, float T, float Tfin, float *alphaP, int *automP, int *disturbanceP, int *instanceP, int *KP, float *pP, int *qvP, float *rhoP, float *TP, float *TfinP)
{
	int aux, done = 0;
	*alphaP = alpha;
	*automP = autom;
	*disturbanceP = disturbance;
	*instanceP = instance;
	*KP = K;
	*pP = p;
	*qvP = qv;
	*rhoP = rho;
	*TP = T;
	*TfinP = Tfin;
	
	//Cargamos la información necesaria de la instancia gr21.tsp
	if(instance == 1)
	{
		qv = 21;
		*qvP = qv;
	}
	
	//Cargamos la información necesaria de la instancia kroD100.tsp
	if(instance == 2)
	{
		qv = 100;
		*qvP = qv;
	}
	
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
		printf("|  6: autom (Modo de acción): %d\n",autom);
		printf("|  7: disturbance (Modo en el que operará el mecanismo de perturbación): %d\n",disturbance);
		printf("|  8: p (Probabilidad de perturbar los nodos de inicio y fin): %.4f\n",p);
		if(instance == 0)
		{
			printf("|  9: qv (Cantidad de vértices que posee el grafo): %d\n",qv);
		}
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
					//Se modifica autom
					
					printf("|     Inserte un nuevo valor para autom (Antiguo valor para autom: autom = %d)\n",autom);
					printf("|  ");
					scanf("%d",&autom);
					*automP = autom;
					
					break;
				}
			case 7:
				{
					//Se modifica disturbance
					
					printf("|     Inserte un nuevo valor para disturbance (Antiguo valor para disturbance: disturbance = %d)\n",disturbance);
					printf("|  ");
					scanf("%d",&disturbance);
					*disturbanceP = disturbance;
					
					break;
				}
			case 8:
				{
					//Se modifica p
					
					printf("|     Inserte un nuevo valor para p (Antiguo valor para p: p = %.4f)\n",p);
					printf("|  ");
					scanf("%f",&p);
					*pP = p;
					
					break;
				}
			case 9:
				{
					//Se modifica qv
					
					if(instance == 0)
					{
						printf("|     Inserte un nuevo valor para qv (Antiguo valor para qv: qv = %d)\n",qv);
						printf("|  ");
						scanf("%d",&qv);
					}
					*qvP = qv;
					
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

//Calibramos los valores de las estructuras generadas por las configuraciones de setValues1
void setValues2(int qv, int graph[qv][qv], int tour[qv + 1])
{
	int aux, done = 0, i, j;
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

//Llena AvailableV
void fillMatrix1D(int a, int matrix[a], int n)
{
	int i,j;
	for(i = 0; i < a; i++)
	{
		matrix[i] = n;
	}
	return;
}

//Prepara el programa con las configuraciones necesarias y a graph con los valores que se obtengan del archivo gr21.tsp
void setInstance21(int qv, float graph[qv][qv])
{
	//1. Declaramos las variables que usaremos para leer el archivo
	/*
		filetxt: Variable FILE de tipo apuntador a un archivo
		h: Iterador general
		i: Iterador general
		j: Iterador general
		k: Iterador general
		line: Vector que extrae una línea del archivo
		n: Auxiliar para guardar de uno en uno los números que se obtengan del archivo
		reachedgraph: Detecta la línea en la que la matriz comienza (usado en las funciones setInstance21 y setInstance100)
	*/
	int h = 0,i,j,k = 0, reachedgraph = 0;
	float n;
	FILE *filetxt;
	char line[200];
	
	//2. Abrimos el archivo
	filetxt = fopen("gr21.tsp.txt","r");
	
	//3. Procesamos el archivo y en caso de error regresamos notificándolo al usuario
	if(filetxt == NULL)
	{
		printf("Problemas para abrir el archivo");
		return;
	}
	
	//4. Leemos el archivo hasta llegar al EOF (End Of File)
	h = 0;
	j = 0;
	k = 1;
	while(feof(filetxt) == 0)
	{
		if(reachedgraph == 0)
		{
			fscanf(filetxt,"%s",line);
			
			//Encontramos la línea anterior al comienzo del grafo
			if(strcmp(line, "EDGE_WEIGHT_SECTION") == 0)
			{
				//Marcamos entonces que hemos alcanzado el grafo y comenzaremos a obtener su información
				reachedgraph = 1;
			}
		}
		else
		{
			//Comenzamos a obtener la información del grafo
			if(h != 21)
			{
				fscanf(filetxt,"%f",&n);
				graph[h][j] = n;
				graph[j][h] = n;
				
				if(j == k - 1)
				{
					h++;
					j = 0;
					k++;
				}
				else
				{
					j++;
				}
			}
			else
			{
				fscanf(filetxt,"%s",line);
			}
		}
	}
	
	//Imprimimos lo que obtuvimos de la lectura de archivos
	printf("El grafo leído del archivo es el siguiente:\n");
	for(i = 0; i < 21; i++)
	{
		for(j = 0; j < 21; j++)
		{
			printf("[%d] ",(int)graph[i][j]);
		}
		printf("\n");
	}
	
	fclose(filetxt);
	
	return;
}

//Prepara el programa con las configuraciones necesarias y a graph con los valores que se obtengan del archivo kroD100.tsp
void setInstance100(int qv, float graph[qv][qv])
{
	//1. Declaramos las variables que usaremos para leer el archivo
	/*
		filetxt: Variable FILE de tipo apuntador a un archivo
		h: Iterador general
		i: Iterador general
		j: Iterador general
		k: Iterador general
		line: Vector que extrae una línea del archivo
		list: Matriz auxiliar donde se guardan en un primer momento los datos previo al cálculo de las distancias entre nodos
		n: Auxiliar para guardar de uno en uno los números que se obtengan del archivo
		reachedgraph: Detecta la línea en la que la matriz comienza (usado en las funciones setInstance21 y setInstance100)
	*/
	int h = 0, i, j, k = 0, list[100][3], n, reachedgraph = 0;
	FILE *filetxt;
	char line[200];
	
	//2. Abrimos el archivo
	filetxt = fopen("kroD100.tsp.txt","r");
	
	//3. Procesamos el archivo y en caso de error regresamos notificándolo al usuario
	if(filetxt == NULL)
	{
		printf("Problemas para abrir el archivo");
		return ;
	}
	
	//4. Leemos el archivo hasta llegar al EOF (End Of File)
	h = 0;
	j = 0;
	k = 1;
	while(feof(filetxt) == 0)
	{
		if(reachedgraph == 0)
		{
			fscanf(filetxt,"%s",line);
			
			//Encontramos la línea anterior al comienzo del grafo
			if(strcmp(line, "NODE_COORD_SECTION") == 0)
			{
				//Marcamos entonces que hemos alcanzado el grafo y comenzaremos a obtener su información
				reachedgraph = 1;
			}
		}
		else
		{
			//Comenzamos a obtener la información del grafo
			if(h != 100)
			{
				fscanf(filetxt,"%d",&n);
				list[h][j] = n;
				j++;
				
				if(j == 3)
				{
					j = 0;
					h++;
				}
			}
			else
			{
				fscanf(filetxt,"%s",line);
			}
		}
	}
	
	//Imprimimos lo que obtuvimos de la lectura de archivos
	printf("La lista leída del archivo es la siguiente:\n");
	for(i = 0; i < 100; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("[%d] ",list[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//Calculamos las distancias entre los nodos y éstas serán guardadas en graph
	for(i = 0; i < 100; i++)
	{
		for(j = 0; j < 100; j++)
		{
			graph[i][j] = sqrt((pow((list[i][1] - list[j][1]),2))+(pow((list[i][2] - list[j][2]),2)));
		}
	}
	
	//Imprimimos el grafo con el que trabajaremos
	printf("Procesando las distancias, el grafo obtenido es el siguiente:\n");
	for(i = 0; i < 100; i++)
	{
		for(j = 0; j < 100; j++)
		{
			printf("[%.4f] ",graph[i][j]);
		}
		printf("\n");
	}
	
	fclose(filetxt);
}

//Prepara un tour estándar en la estructura tour
void setTour(int qv, int tour[qv + 1], int availableV[qv])
{
	int i,r;
	for(i = 0; i < qv; i++)
	{
		r = rand() % qv;
		if(availableV[r] == 1)
		{
			tour[i] = r + 1;
			availableV[r] = 0;
		}
		else
		{
			i--;
		}
	}
	tour[qv] = tour[0];
	
	return;
}

//Valida si el tour que se pasó a esta función es un tour válido según la información que tengamos en graph
int checkTour(int qv, float graph[qv][qv],int tour[qv + 1])
{
	int i;
	for(i = 0; i < qv; i++)
	{
		//Si la información que posee tour de un nodo a otro es 0 en graph significa que no hay conexión, por lo tanto no es un viaje válido
		if(graph[tour[i] - 1][tour[i + 1] - 1] == 0)
		{
			return 0;
		}
	}
	
	//El llegar aquí implica que nunca encontramos un viaje inválido, si todas las conexiones son válidas, el viaje es válido
	return 1;
}

//Evalúa el costo del tour que se le pasa a esta función
void evaluateTour(int qv, float graph[qv][qv],int tour[qv + 1], float ftour, float *ftourP)
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

//Como tour se perturba y su producto se guarda en newTour, para repetir esto muchas veces, newTour debe ahora pasar a ser tour
void backToTour(int qv, int tour[qv + 1],int newTour[qv + 1])
{
	int i;
	for(i = 0; i <=qv; i++)
	{
		//Cargamos newTour en tour
		tour[i] = newTour[i];
	}
	return;
}
