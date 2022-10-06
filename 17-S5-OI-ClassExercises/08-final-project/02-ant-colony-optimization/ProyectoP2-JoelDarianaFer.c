/*
    Universidad Autónoma de Aguascalientes

		  Centro de Ciencias Básicas
  Departamento de Ciencias de la Computación
		   Optimización Inteligente

					5° "A"

   	  Proyecto Parte 2: Colonia de Hormigas

		  Doctora Aurora Torres Soto

   				  Alumnos:
   		Espinoza Sánchez Joel Alejandro
   		Gómez Garza Dariana
   		González Arenas Fernando Francisco

  Fecha de Entrega: 14 de diciembre del 2020
*/

//Cargamos las librerías
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <string.h>

void setValues1(float alpha, int autom, float beta, int instance, float Q, int qh, int qv, float rho, float taui,float *alphaP, int *automP, float *betaP, int *instanceP, float *QP, int *qhP, int *qvP, float *rhoP, float *tauiP);
void fillMatrix1D(int a, float matrix[a], float n);
void fillMatrix2D(int a, int b, float matrix[a][b], float n);
void fillMatrix3D(int a, int b, int c, float matrix[a][b][c], float n);
void setInstance21(int qv, float graph[qv][qv]);
void setInstance100(int qv, float graph[qv][qv]);
void setValues2(int qv, int qh, float graph[qv][qv], float pheromone[qv][qv], float vision[qv][qv], float beginEnd[qh][2]);
void startProcess(int i, int qh, int qv, float tabu[qh][qv], float beginEnd[qh][2], float availableV[qv]);
int acceptVertex(int i, int qh, int qv, int value, float tabu[qh][qv]);
float getL(int i, int qh, int qv, float graph[qv][qv], float tabu[qh][qv], float beginEnd[qh][2]);

main()
{
	setlocale(LC_ALL,"");
	srand(time(NULL));
	
	//1. Declaramos las variables que usaremos
	/*
		qv: Cantidad de vértices del grafo
		qh: Cantidad de hormigas
		tau: Valor de la feromona inicial
		Q: Parámetro
		alpha: Parámetro
		beta: Parámetro
		instance: Instancia que se usará en el recocido, donde:
				  Si instance = 0 ejecutará un proceso personalizado
				  Si instance = 1 ejecutará el proceso de la instancia pequeña
				  Si instance = 2 ejecutará el proceso de la instancia grande
		rho: Parámetro
		autom: Modo de acción (Para autom >=1 se tomará el número de autom como las repeticiones)
		repeat: Sirve para repetir todo el código nuevamente
		repeat1: Sirve para repetir la colonia en modo manual
		r: Número aleatorio
		accepted: Bandera de aceptación de vértice
		checkIfStuck: Iterador que no tolerará un número determinado de iteraciones. Si se alcanzan, se interpretará que la hormiga se encerrá
		L: Longitud del recorrido completo realizado por la hormiga
	*/
	int qv, qh, autom, instance, repeat, repeat1, repeat2, accepted, checkIfStuck, h, i, j, k, ip, jp, kp;
	float tau, Q, alpha, beta, rho, L, r;
	
	printf("============================== COLONIA DE HORMIGAS ==============================\n");
	
	do
	{
		alpha = 1;
		autom = 8;
		beta = 1;
		Q = 1;
		qh = 1;
		qv = 7;
		repeat = 0;
		rho = 0.01;
		tau = 0.1;
		
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
		
		//2. Calibramos los primeros valores del programa
		setValues1(alpha,autom,beta,instance,Q,qh,qv,rho,tau,&alpha,&autom,&beta,&instance,&Q,&qh,&qv,&rho,&tau);
		
		//3. Declaramos más variables
		/*
			graph: La matriz de adyacencia del grafo que analizaremos														INT
			pheromone: La matriz de feromonas																				FLOAT
			vision: La matriz de visibilidad																				FLOAT
			tabu: La lista tabú																								INT
			beginEnd: Matriz con los valores de inicio y fin de cada hormiga												INT
			availableV: Vector donde cada elemento representa cada vértice del grafo (1 está disponible o 0 no lo está)		INT
			prob: Probabilidad individual y acumulada de tomar cada nodo													FLOAT
			dtau: La diferencia de tau que hay por hormiga en cada nodo														FLOAT
		*/
		float graph[qv][qv], pheromone[qv][qv], vision[qv][qv], tabu[qh][qv], beginEnd[qh][2], availableV[qv], prob[qv][2], dtau[qh][qv][qv];
		
		//5. Calibramos este segundo conjunto de valores del algoritmo
		if(instance == 1)
		{
			setInstance21(qv,graph);
		}
		if(instance == 2)
		{
			setInstance100(qv,graph);
		}
		
		//4. Inicializamos las estructuras
		if(instance == 0)
		{
			//Limpiamos graph
			fillMatrix2D(qv,qv,graph,0);
		}
		
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
		
		//5. Calibramos los demás valores del programa
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
		
		//6. Comenzamos la colonia de hormigas, la cual se repetirá tantas veces como se haya calibrado autom (si es 0, se decide el paro)
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
				printf("Comenzamos la %d iteración\n\n", h + 1);
			}
			
			//El procedimiento de la colonia se hará para cada hormiga
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
					printf("    Inicializamos la lista tabú con el valor del nodo de inicio:\n    ");
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
				
				//Todavía, el procedimiento de selección de camino de cada hormiga tiene que hacerse por cada nodo como máximo qv - 1 veces
				j = 0;
				do
				{
					if(autom == 0)
					{
						printf("\n");
						printf("      Escogeremos el nodo %d\n", j + 1);
					}
					
					//Debemos repetir este análisis hasta que el nodo haya sido reconocido como válido
					accepted = 0;
					checkIfStuck = 0;
					do
					{
						//A partir del nodo otorgado, vamos al renglón en vision con el que rellenaremos prob y procedemos a rellenar prob
						prob[0][0] = vision[(int)tabu[i][j] - 1][0];
						prob[0][1] = prob[0][0];
						for(k = 1; k < qv; k++)
						{
							prob[k][0] = vision[(int)tabu[i][j] - 1][k];
							prob[k][1] = prob[k][0] + prob[k - 1][1];
						}
						
						//Generamos un número aleatorio y discretizamos el valor entre 10000 posibilidades, todas dentro del rango
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
								//Encontramos que cayó en k + 1
								break;
							}
						}
						
						if(autom == 0)
						{
							printf("      Hemos escogido el nodo %d (r = %.4f)\n",k + 1,r);
						}
						
						//Ahora toca validar si ese men está disponible o no
						accepted = acceptVertex(i,qh,qv,k+1,tabu);
						
						if(autom == 0)
						{
							if(accepted == 1)
							{
								printf("      Revisando el nodo %d con tabú, obtuvimos que éste es aceptado\n", k + 1);
							}
							else
							{
								printf("      Revisando el nodo %d con tabú, obtuvimos que éste no es aceptado\n", k + 1);
							}
						}
						
						//También tenemos que validar si la hormiga no se quedó encerrada
						if(accepted == 0)
						{
							checkIfStuck++;
							
							if(autom == 0)
							{
								printf("      Tendremos que repetir la selección aleatoria por posible encrucijada (La hormiga lleva %d repeticiones)\n", checkIfStuck);
							}
						}
						
						if(checkIfStuck == 100)
						{
							if(autom == 0)
							{
								printf("      Hemos interpretado que la hormiga se quedó atorada\n Reiniciaremos el proceso completo\n");
							}
							
							startProcess(i,qh,qv,tabu,beginEnd,availableV);
							checkIfStuck = 0;
							j = 0;
						}
					}
					while(accepted == 0);
					
					//Hemos aceptado el nodo, vamos a actualizar la lista tabú y availableV
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
						printf("\n");
						for(ip = 0; ip < qv; ip++)
						{
							printf("[%d] ", (int)availableV[ip]);
						}
						printf("\n");
					}
					
					//Chequemos si el nodo aceptado es el definido como el último. Así la hormiga se sentirá realizada
					/*
					if(k + 1 == beginEnd[i][1])
					{
						if(autom == 0)
						{
							printf("      Hemos llegado al nodo objetivo\n");
						}
						break;
					}
					*/
				}
				while(j < qv - 1);
				
				L = getL(i,qh,qv,graph,tabu,beginEnd);
				
				if(autom == 0)
				{
					printf("\n");
					printf("    La hormiga produjo un recorrido de L = %.4f\n",L);
					getchar();
				}
				
				if(autom != 0)
				{
					printf("En la iteración %d, la hormiga %d produjo el camino:\n",h + 1, i + 1);
					for(jp = 0; jp < qv; jp++)
					{
						printf("[%d] ", (int)tabu[ip][jp]);
					}
					printf("\n");
					printf("Con un recorrido de valor %.4f\n",L);
				}
				
				for(j = 0; j < qv; j++)
				{
					if((j != 0) && ((int)tabu[i][j] == (int)beginEnd[i][1]))
					{
						dtau[i][(int)tabu[i][j] - 1][(int)tabu[i][0] - 1] = Q/L;
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
				printf("    Tras el incremento y evaporación de feromonas, la nueva matriz de feromonas es:\n    ");
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
			
			
			
			//La colonia de hormigas ha finalizado, preguntamos por una nueva iteración o terminar el programa, según sea el caso
			if(autom == 0)
			{
				printf("¿Desea usar un nuevo grupo de hormigas?\n");
				printf("0. No\n");
				printf("1. Sí\n");
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
		printf("¿Desea repetir el código?\n");
		printf("0. No\n");
		printf("1. Sí\n");
		scanf("%d",&repeat);
	}
	while(repeat == 1);
	
	getchar();
}

void setValues1(float alpha, int autom, float beta, int instance, float Q, int qh, int qv, float rho, float taui,float *alphaP, int *automP, float *betaP, int *instanceP, float *QP, int *qhP, int *qvP, float *rhoP, float *tauiP)
{
	int aux, done = 0;
	*alphaP = alpha;
	*automP = autom;
	*betaP = beta;
	*instanceP = instance;
	*QP = Q;
	*qhP = qh;
	*qvP = qv;
	*rhoP = rho;
	*tauiP = taui;
	
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
		printf("|  1: taui (Tau inicial): %.4f\n",taui);
		printf("|  2: alpha (a): %.4f\n",alpha);
		printf("|  3: beta (a): %.4f\n",beta);
		printf("|  4: rho (a): %.4f\n",rho);
		printf("|  5: Q (a): %.4f\n",Q);
		printf("|  6: qh (Cantidad de hormigas): %d\n",qh);
		printf("|  7: autom (Modo de acción): %d\n",autom);
		if(instance == 0)
		{
			printf("|  8: qv (Cantidad de vértices que posee el grafo): %d\n",qv);
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
					//Se modifica autom
					
					printf("|     Inserte un nuevo valor para autom (Antiguo valor para autom: autom = %d)\n",autom);
					printf("|  ");
					scanf("%d",&autom);
					*automP = autom;
					
					break;
				}
			case 8:
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

void setValues2(int qv, int qh, float graph[qv][qv], float pheromone[qv][qv], float vision[qv][qv], float beginEnd[qh][2])
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
						printf("|     Inserte el nodo inicial y final de la hormiga %d:\n",i + 1);
						printf("|  ");
						scanf("%f",&beginEnd[i][0]);
						beginEnd[i][1] = beginEnd[i][0];
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
	tabu[i][qv] = (int)beginEnd[i][0];
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

float getL(int i, int qh, int qv, float graph[qv][qv], float tabu[qh][qv], float beginEnd[qh][2])
{
	int j;
	float L = 0;
	for(j = 0; j < qv; j++)
	{
		if((j != 0) && ((int)tabu[i][j] == (int)beginEnd[i][1]))
		{
			L = L + graph[(int)tabu[i][j] - 1][(int)tabu[i][0] - 1];
			return L;
		}
		else
		{
			L = L + graph[(int)tabu[i][j] - 1][(int)tabu[i][j + 1] - 1];
		}
	}
}
