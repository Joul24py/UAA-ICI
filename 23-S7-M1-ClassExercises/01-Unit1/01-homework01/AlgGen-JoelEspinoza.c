/*
    Universidad Autónoma de Aguascalientes

		  Centro de Ciencias Básicas
  Departamento de Ciencias de la Computación
		   	   Metaheurísticas I

					7° "A"

   Actividad 2.01: Algoritmo Genético Simple

	 Profesor: Francisco Javier Luna Rosas

    Alumno: Joel Alejandro Espinoza Sánchez

  Fecha de Entrega: 1° de septiembre del 2021
*/
//Cargamos las librerías
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

void setValues(int autom, int pc, int pm, int qe, int qelitism, int qi, int qg, int *automP, int *pcP, int *pmP, int *qeP, int *qelitismP, int *qiP, int *qgP);
void startTest(int qe, int qi, int sample[qi][qe]);
void nullNewSample(int qe, int qi, int newSample[qi][qe]);
void evaluate(int qe, int qi, int sample[qi][qe], int results[qi][2]);
void BubbleSort(int qe, int qi, int sample[qi][qe], int results[qi][2]);
void elitism(int qe, int qi, int qelitism, int ic, int sample[qi][qe], int newSample[qi][qe]);
void crossing(int autom, int qe, int qi, int ic, int pc, int sample[qi][qe], int results[qi][2], int newSample[qi][qe]);
void mutation(int autom, int qe, int qi, int pm, int newSample[qi][qe]);
void backToSample(int qe, int qi, int sample[qi][qe], int newSample[qi][qe]);

main()
{
	setlocale(LC_ALL,"");
	srand(time(NULL));
	
	//1. Declaramos las variables que usaremos
	/*
		autom: Modo de acción, donde 0 será Manual y 1 Automático, que:
			   Si autom = 0 ejecutará todo el proceso rápidamente lo hará qg veces
			   Si autom = 1 ejecutará el proceso de uno en uno y el usuario en cada generación decide si generar otra generación o parar
		ic: Iterador de cromosomas
		ig: Iterador de generaciones
		pc: Probabilidad de cruzamiento (0 < pc < 100)
		pm: Probabilidad de mutación (0 < pm < 100)
		qe: Cantidad de elementos
		qelitism: Cantidad de cromosomas que se herdan automáticamente por elitismo
		qi: Cantidad de individuos
		qg: Cantidad de generaciones
	*/
	int autom, ic, ig, pc, pm, qe, qelitism, qi, qg, repeat, repeat1;
	
	printf("============================== ALGORITMO GENÉTICO ==============================\n");
	
	do
	{
		autom = 0;
		ic = 0;
		ig = 0;
		pc = 80;
		pm = 5;
		qe = 20;
		qelitism = 1;
		qi = 50;
		qg = 10;
		repeat = 0;
		
		//2. Calibramos el programa
		setValues(autom,pc,pm,qe,qelitism,qi,qg,&autom,&pc,&pm,&qe,&qelitism,&qi,&qg);
		
		//3. Declaramos más variables
		/*
			sample: La matriz de muestra que guardará los bits
			newSample: La matriz de muestra que guardará los nuevos bits
			results: Estructura para guardar la cantidad total de bits
		*/
		int sample[qi][qe], results[qi][2], newSample[qi][qe];
		
		//4. Generamos aleatoriamente la población inicial
		startTest(qe,qi,sample);
		
		printf("\n");
		printf("\n");
		printf("\n");
		int i,j;
		if(autom == 0)
		{
			printf("La matriz de muestras en la generación %d:\n",ig);
			for(i = 0; i < qi; i++)
			{
				for(j = 0; j < qe; j++)
				{
					printf("%d  ",sample[i][j]);
				}
				printf("\n");
			}
			getchar();
			getchar();
		}
		
		
		
		do
		{
			ic = 0;
			
			nullNewSample(qe,qi,newSample);
			
			//5. Evaluamos a todas las muestras junto con sus evaluaciones acumuladas
			evaluate(qe,qi,sample,results);
			
			if(autom == 0)
			{
				printf("\n");
				printf("\n");
				printf("La matriz de muestras evaluada en F y Fa de la generación %d:\n",ig);
				for(i = 0; i < qi; i++)
				{
					for(j = 0; j < qe; j++)
					{
						printf("%d  ",sample[i][j]);
					}
					printf("    %d   %d\n",results[i][0],results[i][1]);
				}
				getchar();
			}
			
			//6. Ordenamos
			BubbleSort(qe,qi,sample,results);
			evaluate(qe,qi,sample,results);
			
			if(autom == 0)
			{
				printf("\n");
				printf("\n");
				printf("La matriz de muestras ordenada y evaluada en F y Fa de la generación %d:\n",ig);
				for(i = 0; i < qi; i++)
				{
					for(j = 0; j < qe; j++)
					{
						printf("%d  ",sample[i][j]);
					}
					printf("    %d   %d\n",results[i][0],results[i][1]);
				}
				getchar();
			}
			
			//7. Buscamos los qelitism mejores
			elitism(qe,qi,qelitism,ic,sample,newSample);
			
			ic = qelitism;
			
			if(autom == 0)
			{
				printf("\n");
				printf("\n");
				printf("Se aplica elitismo a qelitism = %d cromosomas:\n",qelitism);
				for(i = 0; i < qelitism; i++)
				{
					for(j = 0; j < qe; j++)
					{
						printf("%d  ",sample[i][j]);
					}
					printf("    %d\n",results[i][0]);
				}
				getchar();
				
				printf("\n");
				printf("\n");
				printf("Comenzamos a construir la nueva generación:\n");
				for(i = 0; i < qi; i++)
				{
					for(j = 0; j < qe; j++)
					{
						printf("%d  ",newSample[i][j]);
					}
					printf("\n");
				}
				getchar();
			}
			
			if (autom == 1)
			{
				printf("\n");
				printf("\n");
				printf("Los %d mejores cromosomas de la generación %d son:\n",qelitism,ig);
				for(i = 0; i < qelitism; i++)
				{
					for(j = 0; j < qe; j++)
					{
						printf("%d  ",sample[i][j]);
					}
					printf("    %d\n",results[i][0]);
				}
			}
			
			//8. Aplicamos cruzamiento
			
			crossing(autom,qe,qi,ic,pc,sample,results,newSample);
			
			if(autom == 0)
			{
				printf("\n");
				printf("\n");
				printf("La nueva generación ha pasado la etapa de cruzamiento exitosamente:\n");
				for(i = 0; i < qi; i++)
				{
					for(j = 0; j < qe; j++)
					{
						printf("%d  ",newSample[i][j]);
					}
					printf("\n");
				}
				getchar();
			}
			
			//9. Aplicamos mutación
			mutation(autom,qe,qi,pm,newSample);
			
			ig++;
			
			if(autom == 0)
			{
				printf("\n");
				printf("\n");
				printf("La nueva generación ha pasado la etapa de mutación exitosamente y todos los operadores han sido aplicados\n");
				printf("De modo que la matriz de muestras en la generación %d es:\n",ig);
				for(i = 0; i < qi; i++)
				{
					for(j = 0; j < qe; j++)
					{
						printf("%d  ",newSample[i][j]);
					}
					printf("\n");
				}
				getchar();
				printf("¿Desea construir una nueva generación?\n");
				printf("0. No\n");
				printf("1. Sí\n");
				scanf("%d",&repeat1);
				if(repeat1 == 1)
				{
					qg++;
					getchar();
				}
				else
				{
					ig = qg + 1;
				}
			}
			
			if(autom == 1 && ig == qg + 1)
			{
				printf("\n");
				printf("\n");
				printf("La matriz final de muestras en la generación %d es:\n",ig - 1);
				for(i = 0; i < qi; i++)
				{
					for(j = 0; j < qe; j++)
					{
						printf("%d  ",newSample[i][j]);
					}
					printf("\n");
				}
				getchar();
			}
			
			//10. Transformamos newSample en sample
			backToSample(qe,qi,sample,newSample);
		}
		while(ig <= qg);
		
		
		printf("\n");
		printf("¿Desea repetir el código?\n");
		printf("0. No\n");
		printf("1. Sí\n");
		scanf("%d",&repeat);
	}
	while(repeat == 1);
	getchar();
}

void setValues(int autom, int pc, int pm, int qe, int qelitism, int qi, int qg, int *automP, int *pcP, int *pmP, int *qeP, int *qelitismP, int *qiP, int *qgP)
{
	int aux, done = 0;
	*automP = autom;
	*pcP = pc;
	*pmP = pm;
	*qeP = qe;
	*qelitismP = qelitism;
	*qiP = qi;
	*qgP = qg;
	
	do
	{
		printf("\n");
		printf("--------------------------------\n");
		printf("|  Calibración del algoritmo:\n");
		printf("|  Seleccione algún número si desea cambiar su valor (o 0 para continuar):\n");
		printf("|  0: Listo. Continuar\n");
		printf("|  1: qe (Cantidad de elementos por individuo): %d\n",qe);
		printf("|  2: qi (Cantidad de individuos): %d\n",qi);
		printf("|  3: pc (Probabilidad de cruzamiento): %d\n",pc);
		printf("|  4: pm (Probabilidad de mutación): %d\n",pm);
		printf("|  5: qelitism (Individuos a heredar automáticamente por elitismo): %d\n",qelitism);
		printf("|  6: autom (Modo de acción): %d\n",autom);
		printf("|  7: qg (Cantidad de generaciones): %d\n",qg);
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
					//Se modifica qe
					
					printf("|     Inserte un nuevo valor para qe (Antiguo valor para qe: qe = %d)\n",qe);
					printf("|  ");
					scanf("%d",&qe);
					*qeP = qe;
					
					break;
				}
			case 2:
				{
					//Se modifica qi
					
					printf("|     Inserte un nuevo valor para qi (Antiguo valor para qi: qi = %d)\n",qi);
					printf("|  ");
					scanf("%d",&qi);
					*qiP = qi;
					
					break;
				}
			case 3:
				{
					//Se modifica pc
					
					printf("|     Inserte un nuevo valor para pc (Antiguo valor para pc: pc = %d)\n",pc);
					printf("|  ");
					scanf("%d",&pc);
					*pcP = pc;
					
					break;
				}
			case 4:
				{
					//Se modifica pm
					
					printf("|     Inserte un nuevo valor para pm (Antiguo valor para pm: pm = %d)\n",pm);
					printf("|  ");
					scanf("%d",&pm);
					*pmP = pm;
					
					break;
				}
			case 5:
				{
					//Se modifica qelitism
					
					printf("|     Inserte un nuevo valor para qelitism (Antiguo valor para qelitism: qelitism = %d)\n",qelitism);
					printf("|  ");
					scanf("%d",&qelitism);
					*qelitismP = qelitism;
					
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
					//Se modifica qg
					
					printf("|     Inserte un nuevo valor para qg (Antiguo valor para qg: qg = %d)\n",qg);
					printf("|  ");
					scanf("%d",&qg);
					*qgP = qg;
					
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

void startTest(int qe, int qi, int sample[qi][qe])
{
	int aux = 0,i,j;
	
	for(i = 0; i < qi; i++)
	{
		for(j = 0; j < qe; j++)
		{
			aux = rand() % 2;
			sample[i][j] = aux;
		}
	}
	
	return;
}

void nullNewSample(int qe, int qi, int newSample[qi][qe])
{
	int i,j;
	for(i = 0; i < qi; i++)
	{
		for(j = 0; j < qe; j++)
		{
			newSample[i][j] = 0;
		}
	}
	
	return;
}

void evaluate(int qe, int qi, int sample[qi][qe], int results[qi][2])
{
	int i,j;
	
	for(i = 0; i < qi; i++)
	{
		results[i][0] = 0;
		results[i][1] = 0;
		for(j = 0; j < qe; j++)
		{
			results[i][0] = results[i][0] + sample[i][j];
		}
		results[i][1] = results[i][1] + results[i][0];
		if(i > 0)
		{
			results[i][1] = results[i][1] + results[i - 1][1];
		}
	}
	return;
}

void BubbleSort(int qe, int qi, int sample[qi][qe], int results[qi][2])
{
	int a,aux[qe],i,j;
	
	for(i = 0; i < qi - 1; i++)
	{
		if(results[i][0] < results[i + 1][0])
		{
			a = results[i][0];
			results[i][0] = results[i + 1][0];
			results[i + 1][0] = a;
			
			for(j = 0; j < qe; j++)
			{
				aux[j] = sample[i][j];
				sample[i][j] = sample[i + 1][j];
				sample[i + 1][j] = aux[j];
			}
			
			i = -1;
		}
	}
	
	return;
}

void elitism(int qe, int qi, int qelitism, int ic, int sample[qi][qe], int newSample[qi][qe])
{
	int i;
	while(ic < qelitism)
	{
		for(i = 0; i < qe; i++)
		{
			newSample[ic][i] = sample[ic][i];
		}
		ic++;
	}
	
	return;
}

void crossing(int autom, int qe, int qi, int ic, int pc, int sample[qi][qe], int results[qi][2], int newSample[qi][qe])
{
	int c1[qe],c2[qe],i,j,r,random;
	
	if(autom == 0)
	{
		printf("\n");
		printf("\n");
		printf("Se aplicará cruzamiento con una probabilidad de pc = %d%%:\n",pc);
		getchar();
		printf("\n");
		printf("Debido al elitismo, ya existen %d cromosomas en la nueva generación:\n",ic);
		printf("Para denotar mejor el cruzamiento, marcaremos a los individuos \n");
		printf("como: () del primer cromosoma y como [] del segundo cromosoma\n");
	}
	
	do
	{
		random = rand() % 100;
		
		if(random < pc)
		{
			if(autom == 0)
			{
				printf("\n");
				printf("\n");
				printf("  El cruzamiento se ha activado (Probabilidad: %d < %d)\n",random,pc);
			}
			
			//Seleccionamos por ruleta
			r = rand() % (results[qi - 1][1]);
			
			if(autom == 0)
			{
				printf("\n");
				printf("    Aplicamos selección por ruleta para el primer padre obteniendo %d\n",r);
				printf("    Por lo tanto, el cromosoma a escoger será ");
			}
			
			for(i = 0; i < qi; i++)
			{
				if(r < results[i][1])
				{
					for(j = 0; j < qe; j++)
					{
						c1[j] = sample[i][j];
						if(autom == 0)
						{
							printf("%d ",c1[j]);
						}
					}
					if(autom == 0)
					{
						printf("\n");
					}
					break;
				}
			}
			
			r = rand() % (results[qi - 1][1]);
			
			if(autom == 0)
			{
				printf("\n");
				printf("    Aplicamos selección por ruleta para el segundo padre obteniendo %d\n",r);
				printf("    Por lo tanto, el cromosoma a escoger será ");
			}
			
			for(i = 0; i < qi; i++)
			{
				if(r < results[i][1])
				{
					for(j = 0; j < qe; j++)
					{
						c2[j] = sample[i][j];
						if(autom == 0)
						{
							printf("%d ",c2[j]);
						}
					}
					if(autom == 0)
					{
						printf("\n");
					}
					break;
				}
			}
			
			//Seleccionamos una posición aleatoria para hacer el corte
			random = 1 + (rand() % (qe - 1));
			
			if(autom == 0)
			{
				printf("\n");
				printf("    Se ha seleccionado aleatoriamente un punto de corte entre el gen %d y %d\n",random,random + 1);
				printf("    Serán los cromosomas %d y %d de la nueva generación\n",ic + 1, ic + 2);
			}
			
			for(i = 0; i < qe; i++)
			{
				if(i < random)
				{
					newSample[ic][i] = c1[i];
					newSample[ic + 1][i] = c2[i];
					
					if(autom == 0)
					{
						printf("    (%d) [%d]\n",newSample[ic][i],newSample[ic+1][i]);
					}
				}
				else
				{
					newSample[ic][i] = c2[i];
					newSample[ic + 1][i] = c1[i];
					
					if(autom == 0)
					{
						printf("    [%d] (%d)\n",newSample[ic][i],newSample[ic+1][i]);
					}
				}
			}
		}
		else
		{
			if(autom == 0)
			{
				printf("\n");
				printf("\n");
				printf("  El cruzamiento no se ha activado (Probabilidad: !  %d < %d  !)\n",random,pc);
			}
			
			//Seleccionamos por ruleta
			r = rand() % (results[qi - 1][1]);
			
			if(autom == 0)
			{
				printf("\n");
				printf("    Aplicamos selección por ruleta para el primer padre obteniendo %d\n",r);
				printf("    Por lo tanto, el cromosoma a escoger será ");
			}
			
			for(i = 0; i < qi; i++)
			{
				if(r < results[i][1])
				{
					for(j = 0; j < qe; j++)
					{
						c1[j] = sample[i][j];
						if(autom == 0)
						{
							printf("%d ",c1[j]);
						}
					}
					if(autom == 0)
					{
						printf("\n");
					}
					break;
				}
			}
			
			r = rand() % (results[qi - 1][1]);
			
			if(autom == 0)
			{
				printf("\n");
				printf("    Aplicamos selección por ruleta para el segundo padre obteniendo %d\n",r);
				printf("    Por lo tanto, el cromosoma a escoger será ");
			}
			
			for(i = 0; i < qi; i++)
			{
				if(r < results[i][1])
				{
					for(j = 0; j < qe; j++)
					{
						c2[j] = sample[i][j];
						if(autom == 0)
						{
							printf("%d ",c2[j]);
						}
					}
					if(autom == 0)
					{
						printf("\n");
					}
					break;
				}
			}
			
			//No hay cruzamiento, se pasan igual
			if(autom == 0)
			{
				printf("\n");
				printf("    No hay punto de corte\n");
				printf("    Serán los cromosomas %d y %d de la nueva generación\n",ic + 1, ic + 2);
			}
			
			for(i = 0; i < qe; i++)
			{
				newSample[ic][i] = c1[i];
				newSample[ic + 1][i] = c2[i];
				if(autom == 0)
				{
					printf("    (%d) [%d]\n",newSample[ic][i],newSample[ic+1][i]);
				}
			}
			if(autom == 0)
			{
				printf("\n");
			}
		}
		
		ic = ic + 2;
	}
	while(ic<qi);
	
	if(autom == 0)
	{
		printf("\n");
		printf("Cruzamiento finalizado\n");
		getchar();
	}
}

void mutation(int autom, int qe, int qi, int pm, int newSample[qi][qe])
{
	int i,r,random;
	
	if(autom == 0)
	{
		printf("\n");
		printf("\n");
		printf("Se aplicará mutación con una probabilidad de pm = %d%%:\n",pm);
		getchar();
	}
	
	for(i = 0; i < qi; i++)
	{
		random = rand() % 100;
		
		if(random < pm)
		{
			if(autom == 0)
			{
				printf("\n");
				printf("  La mutación se ha activado para el cromosoma %d (Probabilidad: %d < %d)\n",i + 1,random,pm);
			}
			r = rand() % qe;
			newSample[i][r] = (newSample[i][r] + 1) % 2;
		}
		else
		{
			if(autom == 0)
			{
				printf("\n");
				printf("  La mutación no se ha activado para el cromosoma %d (Probabilidad: !  %d < %d  !)\n",i + 1,random,pm);
			}
		}
	}
	
	if(autom == 0)
	{
		printf("\n");
		printf("Mutación finalizada\n");
		getchar();
	}
	
	return;
}

void backToSample(int qe, int qi, int sample[qi][qe], int newSample[qi][qe])
{
	int i,j;
	for(i = 0; i < qi; i++)
	{
		for(j = 0; j < qe; j++)
		{
			sample[i][j] = newSample[i][j];
		}
	}
	return;
}
