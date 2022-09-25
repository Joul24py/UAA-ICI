/*
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Inteligencia Artificial
3° "A"

Examen: Resolver problemas mediante búsquedas: Búsqueda con algoritmos A* y MiniMax
Anexo 2.01: Algoritmo A*

Profesor: Miguel Ángel Meza de Luna

Alumno: Espinoza Sánchez Joel Alejandro

Aguascalientes, Ags. 25 de noviembre de 2019
*/
//Las librerías------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
#include <locale.h>
using namespace std;

//Definiciones y tipos definidos-------------------------------------------------------------------------------
#define ROW 9
#define COL 10
typedef pair<int, int> Pair;
typedef pair<double, pair<int, int> > pPair;

//Estructuras--------------------------------------------------------------------------------------------------
struct cell
{
	int parent_i, parent_j;
	double f, g, h;
};

//Funciones----------------------------------------------------------------------------------------------------
bool isValid(int row, int col);
bool isUnBlocked(int grid[][COL], int row, int col);
bool isDestination(int row, int col, Pair dest);
double calculateHValue(int row, int col, Pair dest);
void tracePath(cell cellDetails[][COL], Pair dest);
void aStarSearch(int grid[][COL], Pair src, Pair dest);

//El programa--------------------------------------------------------------------------------------------------
main()
{
    setlocale(LC_ALL,"");
	
	//Definición del tablero-----------------------------------------------------------------------------------
    /*
    1 = La casilla no está bloqueada
    0 = La casilla está bloqueada
    */
	int grid[ROW][COL]=
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
	};
    
	//Comienzo de la búsqueda----------------------------------------------------------------------------------
	Pair src = make_pair(0, 0); //Se establece el nodo de inicio
	Pair dest = make_pair(8, 9); //Se establece el nodo objetivo
	aStarSearch(grid, src, dest); //Función del Algoritmo A*
}

//Verifica si la casilla dada está dentro del tablero----------------------------------------------------------
bool isValid(int row, int col)
{
	return ((row >= 0) && (row < ROW) && (col >= 0) && (col < COL));
}

//Verifica si la casilla dada no está bloqueada (se puede acceder)---------------------------------------------
bool isUnBlocked(int grid[][COL], int row, int col)
{
	if(grid[row][col] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Verifica que las casillas de salida y objetivo no sean la misma casilla--------------------------------------
bool isDestination(int row, int col, Pair dest)
{
	if(row == dest.first && col == dest.second)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Calcula la distancia euclidiana------------------------------------------------------------------------------
double calculateHValue(int row, int col, Pair dest)
{
	return ((double)sqrt ((row-dest.first)*(row-dest.first) + (col-dest.second)*(col-dest.second)));
}

//Imprime el camino encontrado---------------------------------------------------------------------------------
void tracePath(cell cellDetails[][COL], Pair dest)
{
	printf("\nEl camino es ");
	int row = dest.first;
	int col = dest.second;
	
	stack<Pair> Path;
	
	//Se inserta todo elemento en una lista hasta que se llegue a la casilla de destino
	while(!((cellDetails[row][col].parent_i) == row && (cellDetails[row][col].parent_j) == col))
	{
		Path.push (make_pair (row, col));
		int temp_row = cellDetails[row][col].parent_i;
		int temp_col = cellDetails[row][col].parent_j;
		row = temp_row;
		col = temp_col;
	}
	
	//Se imprime la lista
	Path.push(make_pair (row, col));
	while(!Path.empty())
	{
		pair<int,int> p = Path.top();
		Path.pop();
		printf("-> (%d,%d) ",p.first,p.second);
	}
	
	return;
}

//El Algoritmo A*----------------------------------------------------------------------------------------------
void aStarSearch(int grid[][COL], Pair src, Pair dest)
{
	//Verificaciones iniciales---------------------------------------------------------------------------------
	//Verifica que la casilla de salida sea una casilla dentro del tablero
	if(isValid(src.first, src.second) == false)
	{
		printf("Punto de salida inválido\n");
		return;
	}
	
	//Verifica que la casilla objetivo sea una casilla dentro del tablero
	if(isValid(dest.first, dest.second) == false)
	{
		printf("Punto de llegada inválido\n");
		return;
	}
	
	//Verifica que las casillas de salida y objetivo están disponibles para acceder (no bloqueadas)
	if(isUnBlocked(grid, src.first, src.second)==false || isUnBlocked(grid, dest.first, dest.second)==false)
	{
		printf("El punto de salida o de llegada está bloqueado\n");
		return;
	}
	
	//Verifica que las casillas de salida y objetivo no sean la misma casilla
	if(isDestination(src.first, src.second, dest) == true)
	{
		printf("Ya estamos en el punto de llegada\n");
		return;
	}
	
	//Inicialización de datos----------------------------------------------------------------------------------
	//Comienzo de una lista cerrada que se inicializa para todas las casillas en falso
	bool closedList[ROW][COL];
	memset(closedList, false, sizeof (closedList));
	
	//Crea una nueva tabla que contendrá la información del procedimiento
	cell cellDetails[ROW][COL];
	int i,j;
	for(i=0; i<ROW; i++)
	{
		for(j=0; j<COL; j++)
		{
			//Llena a f, g, h con el máximo valor para una variable float
			cellDetails[i][j].f = FLT_MAX;
			cellDetails[i][j].g = FLT_MAX;
			cellDetails[i][j].h = FLT_MAX;
			//Llena de -1 a las variables ligadas con otras casillas
			cellDetails[i][j].parent_i = -1;
			cellDetails[i][j].parent_j = -1;
		}
	}
	
	//Le da valores a la primera casilla del camino
	i = src.first, j = src.second;
	cellDetails[i][j].f = 0.0;
	cellDetails[i][j].g = 0.0;
	cellDetails[i][j].h = 0.0;
	cellDetails[i][j].parent_i = i;
	cellDetails[i][j].parent_j = j;
	
	//Crea una lista abierta con la información de f, g, h donde f = g + h
	set<pPair> openList;
	
	//La casilla de salida se establece como el comienzo de la lista y se le asigna su valor f = 0
	openList.insert(make_pair (0.0, make_pair (i, j)));
	
	//Se asigna este valor inicialmente como falso (inicialmente no se ha alcanzado el destino)
	bool foundDest = false;
	
	//Recorrido de la lista abierta de datos-------------------------------------------------------------------
	while(!openList.empty())
	{
		pPair p = *openList.begin();
		
		//Se elimina el punto actual de la lista abierta
		openList.erase(openList.begin());
		
		//Se añade este punto a la lista cerrada
		i = p.second.first;
		j = p.second.second;
		closedList[i][j] = true;
		
		//Valida cada vecino de la casilla---------------------------------------------------------------------
		/*
		Para generar la casilla siguiente se toma en cuenta lo siguiente:
		
		NO       N		 NE
		         |
		         |
		         |
		O-----Casilla-----E
		         |
		         |
		         |
		SO       S		 SE
		
		donde sus valores en función de i, j son:
			Casilla Actual:	( i ,  j )
			N:	Norte:		(i-1,  j )
			S:	Sur:		(i+1,  j )
			E:	Este:		( i , j+1)
			O:	Oeste:		( i , j-1)
			NE:	Noreste:	(i-1, j+1)
			NO:	Noroeste:	(i-1, j-1)
			SE:	Sureste:	(i+1, j+1)
			SO:	Suroeste:	(i+1, j-1)
		*/
		
		//Se declaran variables para guardar valores de f, g, h temporales
		double gNew, hNew, fNew;
		
		//Prueba 1: Norte--------------------------------------------------------------------------------------
		if(isValid(i-1, j) == true) //Verifica si la casilla norte es válida para la posición actual
		{
			if(isDestination(i-1, j, dest) == true)
			{
				//Asigna la casilla encontrada a las variables de relación de la casilla anterior
				cellDetails[i-1][j].parent_i = i;
				cellDetails[i-1][j].parent_j = j;
				printf("Punto de llegada encontrado\n");
				tracePath (cellDetails, dest);
				foundDest = true;
				return;
			}
			else //Si la casilla ya está en la lista cerrada o está bloqueada, ignora y realiza lo siguiente
			{
				if(closedList[i-1][j] == false && isUnBlocked(grid, i-1, j) == true)
				{
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calculateHValue (i-1, j, dest);
					fNew = gNew + hNew;
					
					if(cellDetails[i-1][j].f == FLT_MAX || cellDetails[i-1][j].f > fNew)
					{
						openList.insert( make_pair(fNew, make_pair(i-1, j)));
						
						//Se actualizan los detalles de la casilla
						cellDetails[i-1][j].f = fNew;
						cellDetails[i-1][j].g = gNew;
						cellDetails[i-1][j].h = hNew;
						cellDetails[i-1][j].parent_i = i;
						cellDetails[i-1][j].parent_j = j;
					}
				}
			}
		}
		
		//Prueba 2: Sur----------------------------------------------------------------------------------------
		if(isValid(i+1, j) == true) //Verifica si la casilla sur es válida para la posición actual
		{
			if(isDestination(i+1, j, dest) == true)
			{
				//Asigna la casilla encontrada a las variables de relación de la casilla anterior
				cellDetails[i+1][j].parent_i = i;
				cellDetails[i+1][j].parent_j = j;
				printf("Punto de llegada encontrado\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}
			else //Si la casilla ya está en la lista cerrada o está bloqueada, ignora y realiza lo siguiente
			{
				if(closedList[i+1][j] == false && isUnBlocked(grid, i+1, j) == true)
				{
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calculateHValue(i+1, j, dest);
					fNew = gNew + hNew;
					
					if(cellDetails[i+1][j].f == FLT_MAX || cellDetails[i+1][j].f > fNew)
					{
						openList.insert( make_pair (fNew, make_pair (i+1, j)));
						
						//Se actualizan los detalles de la casilla
						cellDetails[i+1][j].f = fNew;
						cellDetails[i+1][j].g = gNew;
						cellDetails[i+1][j].h = hNew;
						cellDetails[i+1][j].parent_i = i;
						cellDetails[i+1][j].parent_j = j;
					}
				}
			}
		}
		  
		//Prueba 3: Este---------------------------------------------------------------------------------------
		if(isValid (i, j+1) == true) //Verifica si la casilla este es válida para la posición actual
		{
			if(isDestination(i, j+1, dest) == true)
			{
				//Asigna la casilla encontrada a las variables de relación de la casilla anterior
				cellDetails[i][j+1].parent_i = i;
				cellDetails[i][j+1].parent_j = j;
				printf("Punto de llegada encontrado\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}
			else //Si la casilla ya está en la lista cerrada o está bloqueada, ignora y realiza lo siguiente
			{
				if(closedList[i][j+1] == false && isUnBlocked (grid, i, j+1) == true)
				{
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calculateHValue (i, j+1, dest);
					fNew = gNew + hNew;
					
					if(cellDetails[i][j+1].f == FLT_MAX || cellDetails[i][j+1].f > fNew)
					{
						openList.insert( make_pair(fNew, make_pair (i, j+1)));
						
						//Se actualizan los detalles de la casilla
						cellDetails[i][j+1].f = fNew;
						cellDetails[i][j+1].g = gNew;
						cellDetails[i][j+1].h = hNew;
						cellDetails[i][j+1].parent_i = i;
						cellDetails[i][j+1].parent_j = j;
					}
				}
			}
		}
		
		//Prueba 4: Oeste--------------------------------------------------------------------------------------
		if(isValid(i, j-1) == true) //Verifica si la casilla oeste es válida para la posición actual
		{
			if(isDestination(i, j-1, dest) == true)
			{
				//Asigna la casilla encontrada a las variables de relación de la casilla anterior
				cellDetails[i][j-1].parent_i = i;
				cellDetails[i][j-1].parent_j = j;
				printf("Punto de llegada encontrado\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}
			else //Si la casilla ya está en la lista cerrada o está bloqueada, ignora y realiza lo siguiente
            {
				if(closedList[i][j-1] == false && isUnBlocked(grid, i, j-1) == true)
				{
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calculateHValue(i, j-1, dest);
					fNew = gNew + hNew;
					
					if(cellDetails[i][j-1].f == FLT_MAX || cellDetails[i][j-1].f > fNew)
					{
						openList.insert( make_pair (fNew, make_pair (i, j-1)));
						
						//Se actualizan los detalles de la casilla
						cellDetails[i][j-1].f = fNew;
						cellDetails[i][j-1].g = gNew;
						cellDetails[i][j-1].h = hNew;
						cellDetails[i][j-1].parent_i = i;
						cellDetails[i][j-1].parent_j = j;
					}
				}
			}
		}
		
		//Prueba 5: Noreste------------------------------------------------------------------------------------
		if(isValid(i-1, j+1) == true) //Verifica si la casilla noreste es válida para la posición actual
		{
			if(isDestination(i-1, j+1, dest) == true)
			{
				//Asigna la casilla encontrada a las variables de relación de la casilla anterior
				cellDetails[i-1][j+1].parent_i = i;
				cellDetails[i-1][j+1].parent_j = j;
				printf("Punto de llegada encontrado\n");
				tracePath (cellDetails, dest);
				foundDest = true;
				return;
			}
			else //Si la casilla ya está en la lista cerrada o está bloqueada, ignora y realiza lo siguiente
			{
				if(closedList[i-1][j+1] == false && isUnBlocked(grid, i-1, j+1) == true)
				{
					gNew = cellDetails[i][j].g + 1.414;
					hNew = calculateHValue(i-1, j+1, dest);
					fNew = gNew + hNew;
	                
					if(cellDetails[i-1][j+1].f == FLT_MAX || cellDetails[i-1][j+1].f > fNew)
					{
						openList.insert( make_pair (fNew, make_pair(i-1, j+1)));
	                    
	                    //Se actualizan los detalles de la casilla
						cellDetails[i-1][j+1].f = fNew;
						cellDetails[i-1][j+1].g = gNew;
						cellDetails[i-1][j+1].h = hNew;
						cellDetails[i-1][j+1].parent_i = i;
						cellDetails[i-1][j+1].parent_j = j;
					}
				}
			}
		}
		
		//Prueba 6: Noroeste-----------------------------------------------------------------------------------
		if(isValid (i-1, j-1) == true) //Verifica si la casilla noroeste es válida para la posición actual
		{
			if(isDestination (i-1, j-1, dest) == true)
			{
				//Asigna la casilla encontrada a las variables de relación de la casilla anterior
				cellDetails[i-1][j-1].parent_i = i;
				cellDetails[i-1][j-1].parent_j = j;
				printf("Punto de llegada encontrado\n");
				tracePath (cellDetails, dest);
				foundDest = true;
				return;
			}
			else //Si la casilla ya está en la lista cerrada o está bloqueada, ignora y realiza lo siguiente
			{
				if(closedList[i-1][j-1] == false && isUnBlocked(grid, i-1, j-1) == true)
				{
					gNew = cellDetails[i][j].g + 1.414;
					hNew = calculateHValue(i-1, j-1, dest);
					fNew = gNew + hNew;
					
					if(cellDetails[i-1][j-1].f == FLT_MAX || cellDetails[i-1][j-1].f > fNew)
					{
						openList.insert(make_pair (fNew,make_pair (i-1, j-1)));
						
						//Se actualizan los detalles de la casilla
						cellDetails[i-1][j-1].f = fNew;
						cellDetails[i-1][j-1].g = gNew;
						cellDetails[i-1][j-1].h = hNew;
						cellDetails[i-1][j-1].parent_i = i;
						cellDetails[i-1][j-1].parent_j = j;
					}
				}
			}
		}
		
		//Prueba 7: Sureste------------------------------------------------------------------------------------
		if(isValid(i+1, j+1) == true) //Verifica si la casilla sureste es válida para la posición actual
		{
			if(isDestination(i+1, j+1, dest) == true)
			{
				//Asigna la casilla encontrada a las variables de relación de la casilla anterior
				cellDetails[i+1][j+1].parent_i = i;
				cellDetails[i+1][j+1].parent_j = j;
				printf("Punto de llegada encontrado\n");
				tracePath (cellDetails, dest);
				foundDest = true;
				return;
			}
			else //Si la casilla ya está en la lista cerrada o está bloqueada, ignora y realiza lo siguiente
			{
            	if(closedList[i+1][j+1] == false && isUnBlocked(grid, i+1, j+1) == true)
	            {
					gNew = cellDetails[i][j].g + 1.414;
					hNew = calculateHValue(i+1, j+1, dest);
					fNew = gNew + hNew;
					
					if(cellDetails[i+1][j+1].f == FLT_MAX || cellDetails[i+1][j+1].f > fNew)
					{
						openList.insert(make_pair(fNew,make_pair (i+1, j+1)));
						
						//Se actualizan los detalles de la casilla
						cellDetails[i+1][j+1].f = fNew;
						cellDetails[i+1][j+1].g = gNew;
						cellDetails[i+1][j+1].h = hNew;
						cellDetails[i+1][j+1].parent_i = i;
						cellDetails[i+1][j+1].parent_j = j;
					}
				}
			}
		}
		
		//Prueba 8: Suroeste-----------------------------------------------------------------------------------
		if(isValid (i+1, j-1) == true) //Verifica si la casilla suroeste es válida para la posición actual
		{
			if(isDestination(i+1, j-1, dest) == true)
			{
				//Asigna la casilla encontrada a las variables de relación de la casilla anterior
				cellDetails[i+1][j-1].parent_i = i;
				cellDetails[i+1][j-1].parent_j = j;
				printf("Punto de llegada encontrado\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}
			else //Si la casilla ya está en la lista cerrada o está bloqueada, ignora y realiza lo siguiente
			{
				if(closedList[i+1][j-1] == false && isUnBlocked(grid, i+1, j-1) == true)
				{
					gNew = cellDetails[i][j].g + 1.414;
					hNew = calculateHValue(i+1, j-1, dest);
					fNew = gNew + hNew;
					
					if(cellDetails[i+1][j-1].f == FLT_MAX || cellDetails[i+1][j-1].f > fNew)
					{
						openList.insert(make_pair(fNew,make_pair(i+1, j-1)));
						
						//Se actualizan los detalles de la casilla
						cellDetails[i+1][j-1].f = fNew;
						cellDetails[i+1][j-1].g = gNew;
						cellDetails[i+1][j-1].h = hNew;
						cellDetails[i+1][j-1].parent_i = i;
						cellDetails[i+1][j-1].parent_j = j;
					}
				}
			}
		}
	}
	
	//Validación final: No es posible generar un camino--------------------------------------------------------
	//Si no se encontró la casilla objetivo y la lista abierta está vacía, se concluye que se falló
	if(foundDest == false)
	{
		printf("Ocurrió un error al tratar de encontrar el punto de llegada\n");
	}
	return;
}
