#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

int data100[100],data200[200],data300[300],data400[400],data500[500],data600[600],data700[700],data800[800],data900[900],data1000[1000],data2000[2000],data3000[3000],data4000[4000],data5000[5000],data6000[6000],data7000[7000],data8000[8000],data9000[9000],data10000[10000],data20000[20000],data30000[30000],data40000[40000],data50000[50000],data60000[60000],data70000[70000],data80000[80000],data90000[90000],data100000[100000],data200000[200000],data300000[300000],data400000[400000],data500000[500000],data600000[600000],data700000[700000],data800000[800000],data900000[900000],data1000000[1000000],data2000000[2000000],data3000000[3000000],data4000000[4000000],data5000000[5000000],data6000000[6000000],data7000000[7000000],data8000000[8000000],data9000000[9000000],data10000000[10000000];
int contador;

void gotoxy(int x,int y);
void CasoMejor(int arreglo[], int tam);
void CasoPromedio(int arreglo[], int tam);
void CasoPeor(int arreglo[], int tam);
void Imprimir(int arreglo[], int tam);
void BubbleSort(int arreglo[], int tam); //100 a 10,000
void InsertionSort(int arreglo[], int tam); //100 a 100,000
void SelectionSort(int arreglo[], int tam); //100 a 100,000
void ShellSort(int arreglo[], int tam); //100 a 10,000,000
void QuickSort(int arreglo[],int first,int last); //100 a 10,000,000
void MergeSort(int arr[], int l, int r); // 100 a 500,000
	void PreMerge(int arr[], int l, int m, int r);
//void DistributionSort(); Radix es un tipo de Distribution
void RadixSort(int arreglo[], int tam); // 100 a 500,000
void HeapSort(int arreglo[], int tam); //100 a 10,000,000
	void heapify(int arreglo[],int tam, int i);

main()
{
	setlocale(LC_ALL,"");
	srand(time(NULL));
	
	/*printf("Programa Experimental para el Análisis de Eficiencia de Métodos de Ordenamiento\n");
	printf("Investigación perteneciente a la materia de Estructuras Computacionales\n");
	printf("Presione \"ENTER\" para continuar\n");
	getchar();
	system("CLS");
	
	printf("Este programa analizará el tiempo de ejecución de ocho diferentes algoritmos de ordenamiento.\n");
	printf("Cada algoritmo será probado en tres diferentes casos:\n   Caso Peor.\n   Caso Medio.\n   Caso Mejor.\n");
	printf("Los algoritmos (sobre todo, el algoritmo de la burbuja) son muy tardados.\n");
	printf("Por esta misma razón, se pedirá que, para un análisis óptimo de datos, cierre todas las aplicaciones\n");
	printf("que pueda estar usando y deje únicamente el programa en ejecución.\n");
	printf("El programa, según la potencia de su computadora, puede tardar de 20 minutos a media hora.\n");
	printf("Una vez que los datos sean arrojados, favor de mandar una captura de pantalla\n");
	printf("y con ella, enviar las especificaciones del procesador y la Memoria RAM que tiene su ordenador.\n");
	printf("Si ya cerró todas las demás aplicaciones y considera tener el tiempo para realizar experimentación,\n");
	printf("entonces presione \"ENTER\" para iniciar la prueba.\n");
	
	getchar();
	system("CLS");*/
	
	printf("Comenzando evaluación...\n\n");
	
	Sleep(3000);
	
	float tiempoglobal;
	clock_t inicioglobal,finglobal;
	inicioglobal=clock();
	
	//CASO MEJOR
	gotoxy(0,2);
	printf("CASO MEJOR:");
	
	int renglon=3;
	
	//Bubble Evaluar de 100 a 100,000 datos
	
	CasoMejor(data100,100);
	float tiempo;
	clock_t inicio,fin;
	inicio=clock();
	BubbleSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200,200);
	inicio=clock();
	BubbleSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data300,300);
	inicio=clock();
	BubbleSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data400,400);
	inicio=clock();
	BubbleSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data500,500);
	inicio=clock();
	BubbleSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data600,600);
	inicio=clock();
	BubbleSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data700,700);
	inicio=clock();
	BubbleSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data800,800);
	inicio=clock();
	BubbleSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data900,900);
	inicio=clock();
	BubbleSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data1000,1000);
	inicio=clock();
	BubbleSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data2000,2000);
	inicio=clock();
	BubbleSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data3000,3000);
	inicio=clock();
	BubbleSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data4000,4000);
	inicio=clock();
	BubbleSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data5000,5000);
	inicio=clock();
	BubbleSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data6000,6000);
	inicio=clock();
	BubbleSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data7000,7000);
	inicio=clock();
	BubbleSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data8000,8000);
	inicio=clock();
	BubbleSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data9000,9000);
	inicio=clock();
	BubbleSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data10000,10000);
	inicio=clock();
	BubbleSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data20000,20000);
	inicio=clock();
	BubbleSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data30000,30000);
	inicio=clock();
	BubbleSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data40000,40000);
	inicio=clock();
	BubbleSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data50000,50000);
	inicio=clock();
	BubbleSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data60000,60000);
	inicio=clock();
	BubbleSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data70000,70000);
	inicio=clock();
	BubbleSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data80000,80000);
	inicio=clock();
	BubbleSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data90000,90000);
	inicio=clock();
	BubbleSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data100000,100000);
	inicio=clock();
	BubbleSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Insertion Evaluar de 100 a 10,000,000 datos
	
	CasoMejor(data100,100);
	inicio=clock();
	InsertionSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200,200);
	inicio=clock();
	InsertionSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data300,300);
	inicio=clock();
	InsertionSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data400,400);
	inicio=clock();
	InsertionSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data500,500);
	inicio=clock();
	InsertionSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data600,600);
	inicio=clock();
	InsertionSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data700,700);
	inicio=clock();
	InsertionSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data800,800);
	inicio=clock();
	InsertionSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data900,900);
	inicio=clock();
	InsertionSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data1000,1000);
	inicio=clock();
	InsertionSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data2000,2000);
	inicio=clock();
	InsertionSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data3000,3000);
	inicio=clock();
	InsertionSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data4000,4000);
	inicio=clock();
	InsertionSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data5000,5000);
	inicio=clock();
	InsertionSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data6000,6000);
	inicio=clock();
	InsertionSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data7000,7000);
	inicio=clock();
	InsertionSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data8000,8000);
	inicio=clock();
	InsertionSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data9000,9000);
	inicio=clock();
	InsertionSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data10000,10000);
	inicio=clock();
	InsertionSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data20000,20000);
	inicio=clock();
	InsertionSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data30000,30000);
	inicio=clock();
	InsertionSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data40000,40000);
	inicio=clock();
	InsertionSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data50000,50000);
	inicio=clock();
	InsertionSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data60000,60000);
	inicio=clock();
	InsertionSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data70000,70000);
	inicio=clock();
	InsertionSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data80000,80000);
	inicio=clock();
	InsertionSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data90000,90000);
	inicio=clock();
	InsertionSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data100000,100000);
	inicio=clock();
	InsertionSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200000,200000);
	inicio=clock();
	InsertionSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data300000,300000);
	inicio=clock();
	InsertionSort(data300000,300000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data400000,400000);
	inicio=clock();
	InsertionSort(data400000,400000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data500000,500000);
	inicio=clock();
	InsertionSort(data500000,500000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data600000,600000);
	inicio=clock();
	InsertionSort(data600000,600000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para    600,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data700000,700000);
	inicio=clock();
	InsertionSort(data700000,700000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para    700,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data800000,800000);
	inicio=clock();
	InsertionSort(data800000,800000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para    800,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data900000,900000);
	inicio=clock();
	InsertionSort(data900000,900000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para    900,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data1000000,1000000);
	inicio=clock();
	InsertionSort(data1000000,1000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para  1,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data2000000,2000000);
	inicio=clock();
	InsertionSort(data2000000,2000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para  2,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data3000000,3000000);
	inicio=clock();
	InsertionSort(data3000000,3000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para  3,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data4000000,4000000);
	inicio=clock();
	InsertionSort(data4000000,4000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para  4,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data5000000,5000000);
	inicio=clock();
	InsertionSort(data5000000,5000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para  5,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data6000000,6000000);
	inicio=clock();
	InsertionSort(data6000000,6000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para  6,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data7000000,7000000);
	inicio=clock();
	InsertionSort(data7000000,7000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para  7,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data8000000,8000000);
	inicio=clock();
	InsertionSort(data8000000,8000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para  8,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data9000000,9000000);
	inicio=clock();
	InsertionSort(data9000000,9000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para  9,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data10000000,10000000);
	inicio=clock();
	InsertionSort(data10000000,10000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para 10,000,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Selection Evaluar de 100 a 200,000 datos
	
	CasoMejor(data100,100);
	inicio=clock();
	SelectionSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200,200);
	inicio=clock();
	SelectionSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data300,300);
	inicio=clock();
	SelectionSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data400,400);
	inicio=clock();
	SelectionSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data500,500);
	inicio=clock();
	SelectionSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data600,600);
	inicio=clock();
	SelectionSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data700,700);
	inicio=clock();
	SelectionSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data800,800);
	inicio=clock();
	SelectionSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data900,900);
	inicio=clock();
	SelectionSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data1000,1000);
	inicio=clock();
	SelectionSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data2000,2000);
	inicio=clock();
	SelectionSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data3000,3000);
	inicio=clock();
	SelectionSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data4000,4000);
	inicio=clock();
	SelectionSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data5000,5000);
	inicio=clock();
	SelectionSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data6000,6000);
	inicio=clock();
	SelectionSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data7000,7000);
	inicio=clock();
	SelectionSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data8000,8000);
	inicio=clock();
	SelectionSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data9000,9000);
	inicio=clock();
	SelectionSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data10000,10000);
	inicio=clock();
	SelectionSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data20000,20000);
	inicio=clock();
	SelectionSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data30000,30000);
	inicio=clock();
	SelectionSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data40000,40000);
	inicio=clock();
	SelectionSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data50000,50000);
	inicio=clock();
	SelectionSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data60000,60000);
	inicio=clock();
	SelectionSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data70000,70000);
	inicio=clock();
	SelectionSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data80000,80000);
	inicio=clock();
	SelectionSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data90000,90000);
	inicio=clock();
	SelectionSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data100000,100000);
	inicio=clock();
	SelectionSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200000,200000);
	inicio=clock();
	SelectionSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Shell Evaluar de 100 a 10,000,000 datos
	
	CasoMejor(data100,100);
	inicio=clock();
	ShellSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200,200);
	inicio=clock();
	ShellSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data300,300);
	inicio=clock();
	ShellSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data400,400);
	inicio=clock();
	ShellSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data500,500);
	inicio=clock();
	ShellSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data600,600);
	inicio=clock();
	ShellSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data700,700);
	inicio=clock();
	ShellSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data800,800);
	inicio=clock();
	ShellSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data900,900);
	inicio=clock();
	ShellSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data1000,1000);
	inicio=clock();
	ShellSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data2000,2000);
	inicio=clock();
	ShellSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data3000,3000);
	inicio=clock();
	ShellSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data4000,4000);
	inicio=clock();
	ShellSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data5000,5000);
	inicio=clock();
	ShellSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data6000,6000);
	inicio=clock();
	ShellSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data7000,7000);
	inicio=clock();
	ShellSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data8000,8000);
	inicio=clock();
	ShellSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data9000,9000);
	inicio=clock();
	ShellSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data10000,10000);
	inicio=clock();
	ShellSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data20000,20000);
	inicio=clock();
	ShellSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data30000,30000);
	inicio=clock();
	ShellSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data40000,40000);
	inicio=clock();
	ShellSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data50000,50000);
	inicio=clock();
	ShellSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data60000,60000);
	inicio=clock();
	ShellSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data70000,70000);
	inicio=clock();
	ShellSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data80000,80000);
	inicio=clock();
	ShellSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data90000,90000);
	inicio=clock();
	ShellSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data100000,100000);
	inicio=clock();
	ShellSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200000,200000);
	inicio=clock();
	ShellSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data300000,300000);
	inicio=clock();
	ShellSort(data300000,300000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data400000,400000);
	inicio=clock();
	ShellSort(data400000,400000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data500000,500000);
	inicio=clock();
	ShellSort(data500000,500000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data600000,600000);
	inicio=clock();
	ShellSort(data600000,600000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    600,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data700000,700000);
	inicio=clock();
	ShellSort(data700000,700000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    700,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data800000,800000);
	inicio=clock();
	ShellSort(data800000,800000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    800,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data900000,900000);
	inicio=clock();
	ShellSort(data900000,900000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    900,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data1000000,1000000);
	inicio=clock();
	ShellSort(data1000000,1000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  1,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data2000000,2000000);
	inicio=clock();
	ShellSort(data2000000,2000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  2,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data3000000,3000000);
	inicio=clock();
	ShellSort(data3000000,3000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  3,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data4000000,4000000);
	inicio=clock();
	ShellSort(data4000000,4000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  4,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data5000000,5000000);
	inicio=clock();
	ShellSort(data5000000,5000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  5,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data6000000,6000000);
	inicio=clock();
	ShellSort(data6000000,6000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  6,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data7000000,7000000);
	inicio=clock();
	ShellSort(data7000000,7000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  7,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data8000000,8000000);
	inicio=clock();
	ShellSort(data8000000,8000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  8,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data9000000,9000000);
	inicio=clock();
	ShellSort(data9000000,9000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  9,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data10000000,10000000);
	inicio=clock();
	ShellSort(data10000000,10000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para 10,000,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Quick Evaluar de 100 a 30,000 datos
	
	CasoMejor(data100,100);
	inicio=clock();
	QuickSort(data100,0,100-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200,200);
	inicio=clock();
	QuickSort(data200,0,200-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data300,300);
	inicio=clock();
	QuickSort(data300,0,300-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data400,400);
	inicio=clock();
	QuickSort(data400,0,400-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data500,500);
	inicio=clock();
	QuickSort(data500,0,500-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data600,600);
	inicio=clock();
	QuickSort(data600,0,600-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data700,700);
	inicio=clock();
	QuickSort(data700,0,700-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data800,800);
	inicio=clock();
	QuickSort(data800,0,800-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data900,900);
	inicio=clock();
	QuickSort(data900,0,900-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data1000,1000);
	inicio=clock();
	QuickSort(data1000,0,1000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data2000,2000);
	inicio=clock();
	QuickSort(data2000,0,2000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data3000,3000);
	inicio=clock();
	QuickSort(data3000,0,3000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data4000,4000);
	inicio=clock();
	QuickSort(data4000,0,4000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data5000,5000);
	inicio=clock();
	QuickSort(data5000,0,5000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data6000,6000);
	inicio=clock();
	QuickSort(data6000,0,6000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data7000,7000);
	inicio=clock();
	QuickSort(data7000,0,7000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data8000,8000);
	inicio=clock();
	QuickSort(data8000,0,8000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data9000,9000);
	inicio=clock();
	QuickSort(data9000,0,9000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data10000,10000);
	inicio=clock();
	QuickSort(data10000,0,10000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data20000,20000);
	inicio=clock();
	QuickSort(data20000,0,20000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data30000,30000);
	inicio=clock();
	QuickSort(data30000,0,30000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Merge Evaluar de 100 a 500,000 datos
	
	CasoMejor(data100,100);
	inicio=clock();
	MergeSort(data100,0,100-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200,200);
	inicio=clock();
	MergeSort(data200,0,200-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data300,300);
	inicio=clock();
	MergeSort(data300,0,300-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data400,400);
	inicio=clock();
	MergeSort(data400,0,400-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data500,500);
	inicio=clock();
	MergeSort(data500,0,500-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data600,600);
	inicio=clock();
	MergeSort(data600,0,600-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data700,700);
	inicio=clock();
	MergeSort(data700,0,700-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data800,800);
	inicio=clock();
	MergeSort(data800,0,800-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data900,900);
	inicio=clock();
	MergeSort(data900,0,900-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data1000,1000);
	inicio=clock();
	MergeSort(data1000,0,1000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data2000,2000);
	inicio=clock();
	MergeSort(data2000,0,2000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data3000,3000);
	inicio=clock();
	MergeSort(data3000,0,3000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data4000,4000);
	inicio=clock();
	MergeSort(data4000,0,4000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data5000,5000);
	inicio=clock();
	MergeSort(data5000,0,5000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data6000,6000);
	inicio=clock();
	MergeSort(data6000,0,6000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data7000,7000);
	inicio=clock();
	MergeSort(data7000,0,7000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data8000,8000);
	inicio=clock();
	MergeSort(data8000,0,8000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data9000,9000);
	inicio=clock();
	MergeSort(data9000,0,9000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data10000,10000);
	inicio=clock();
	MergeSort(data10000,0,10000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data20000,20000);
	inicio=clock();
	MergeSort(data20000,0,20000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data30000,30000);
	inicio=clock();
	MergeSort(data30000,0,30000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data40000,40000);
	inicio=clock();
	MergeSort(data40000,0,40000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data50000,50000);
	inicio=clock();
	MergeSort(data50000,0,50000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data60000,60000);
	inicio=clock();
	MergeSort(data60000,0,60000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data70000,70000);
	inicio=clock();
	MergeSort(data70000,0,70000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data80000,80000);
	inicio=clock();
	MergeSort(data80000,0,80000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data90000,90000);
	inicio=clock();
	MergeSort(data90000,0,90000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data100000,100000);
	inicio=clock();
	MergeSort(data100000,0,100000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200000,200000);
	inicio=clock();
	MergeSort(data200000,0,200000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data300000,300000);
	inicio=clock();
	MergeSort(data300000,0,300000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data400000,400000);
	inicio=clock();
	MergeSort(data400000,0,400000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data500000,500000);
	inicio=clock();
	MergeSort(data500000,0,500000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Radix Evaluar de 100 a 500,000 datos
	
	CasoMejor(data100,100);
	inicio=clock();
	RadixSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200,200);
	inicio=clock();
	RadixSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data300,300);
	inicio=clock();
	RadixSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data400,400);
	inicio=clock();
	RadixSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data500,500);
	inicio=clock();
	RadixSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data600,600);
	inicio=clock();
	RadixSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data700,700);
	inicio=clock();
	RadixSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data800,800);
	inicio=clock();
	RadixSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data900,900);
	inicio=clock();
	RadixSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data1000,1000);
	inicio=clock();
	RadixSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data2000,2000);
	inicio=clock();
	RadixSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data3000,3000);
	inicio=clock();
	RadixSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data4000,4000);
	inicio=clock();
	RadixSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data5000,5000);
	inicio=clock();
	RadixSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data6000,6000);
	inicio=clock();
	RadixSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data7000,7000);
	inicio=clock();
	RadixSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data8000,8000);
	inicio=clock();
	RadixSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data9000,9000);
	inicio=clock();
	RadixSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data10000,10000);
	inicio=clock();
	RadixSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data20000,20000);
	inicio=clock();
	RadixSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data30000,30000);
	inicio=clock();
	RadixSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data40000,40000);
	inicio=clock();
	RadixSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data50000,50000);
	inicio=clock();
	RadixSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data60000,60000);
	inicio=clock();
	RadixSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data70000,70000);
	inicio=clock();
	RadixSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data80000,80000);
	inicio=clock();
	RadixSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data90000,90000);
	inicio=clock();
	RadixSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data100000,100000);
	inicio=clock();
	RadixSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200000,200000);
	inicio=clock();
	RadixSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data300000,300000);
	inicio=clock();
	RadixSort(data300000,300000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data400000,400000);
	inicio=clock();
	RadixSort(data400000,400000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data500000,500000);
	inicio=clock();
	RadixSort(data500000,500000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Heap Evaluar de 100 a 10,000,000 datos
	
	CasoMejor(data100,100);
	inicio=clock();
	HeapSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200,200);
	inicio=clock();
	HeapSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data300,300);
	inicio=clock();
	HeapSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data400,400);
	inicio=clock();
	HeapSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data500,500);
	inicio=clock();
	HeapSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data600,600);
	inicio=clock();
	HeapSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data700,700);
	inicio=clock();
	HeapSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data800,800);
	inicio=clock();
	HeapSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data900,900);
	inicio=clock();
	HeapSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data1000,1000);
	inicio=clock();
	HeapSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data2000,2000);
	inicio=clock();
	HeapSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data3000,3000);
	inicio=clock();
	HeapSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data4000,4000);
	inicio=clock();
	HeapSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data5000,5000);
	inicio=clock();
	HeapSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data6000,6000);
	inicio=clock();
	HeapSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data7000,7000);
	inicio=clock();
	HeapSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data8000,8000);
	inicio=clock();
	HeapSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data9000,9000);
	inicio=clock();
	HeapSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data10000,10000);
	inicio=clock();
	HeapSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data20000,20000);
	inicio=clock();
	HeapSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data30000,30000);
	inicio=clock();
	HeapSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data40000,40000);
	inicio=clock();
	HeapSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data50000,50000);
	inicio=clock();
	HeapSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data60000,60000);
	inicio=clock();
	HeapSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data70000,70000);
	inicio=clock();
	HeapSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data80000,80000);
	inicio=clock();
	HeapSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data90000,90000);
	inicio=clock();
	HeapSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data100000,100000);
	inicio=clock();
	HeapSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data200000,200000);
	inicio=clock();
	HeapSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data300000,300000);
	inicio=clock();
	HeapSort(data300000,300000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data400000,400000);
	inicio=clock();
	HeapSort(data400000,400000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data500000,500000);
	inicio=clock();
	HeapSort(data500000,500000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data600000,600000);
	inicio=clock();
	HeapSort(data600000,600000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    600,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data700000,700000);
	inicio=clock();
	HeapSort(data700000,700000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    700,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data800000,800000);
	inicio=clock();
	HeapSort(data800000,800000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    800,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data900000,900000);
	inicio=clock();
	HeapSort(data900000,900000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    900,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data1000000,1000000);
	inicio=clock();
	HeapSort(data1000000,1000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  1,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data2000000,2000000);
	inicio=clock();
	HeapSort(data2000000,2000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  2,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data3000000,3000000);
	inicio=clock();
	HeapSort(data3000000,3000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  3,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data4000000,4000000);
	inicio=clock();
	HeapSort(data4000000,4000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  4,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data5000000,5000000);
	inicio=clock();
	HeapSort(data5000000,5000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  5,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data6000000,6000000);
	inicio=clock();
	HeapSort(data6000000,6000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  6,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data7000000,7000000);
	inicio=clock();
	HeapSort(data7000000,7000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  7,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data8000000,8000000);
	inicio=clock();
	HeapSort(data8000000,8000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  8,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data9000000,9000000);
	inicio=clock();
	HeapSort(data9000000,9000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  9,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoMejor(data10000000,10000000);
	inicio=clock();
	HeapSort(data10000000,10000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para 10,000,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//CASO PROMEDIO
	gotoxy(0,renglon);
	printf("CASO PROMEDIO:");
	
	renglon++;
	renglon++;
	
	//Bubble Evaluar de 100 a 5,000 datos
	
	CasoPromedio(data100,100);
	inicio=clock();
	BubbleSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200,200);
	inicio=clock();
	BubbleSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data300,300);
	inicio=clock();
	BubbleSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data400,400);
	inicio=clock();
	BubbleSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data500,500);
	inicio=clock();
	BubbleSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data600,600);
	inicio=clock();
	BubbleSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data700,700);
	inicio=clock();
	BubbleSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data800,800);
	inicio=clock();
	BubbleSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data900,900);
	inicio=clock();
	BubbleSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data1000,1000);
	inicio=clock();
	BubbleSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data2000,2000);
	inicio=clock();
	BubbleSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data3000,3000);
	inicio=clock();
	BubbleSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data4000,4000);
	inicio=clock();
	BubbleSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data5000,5000);
	inicio=clock();
	BubbleSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Insertion Evaluar de 100 a 200,000 datos
	
	CasoPromedio(data100,100);
	inicio=clock();
	InsertionSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200,200);
	inicio=clock();
	InsertionSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data300,300);
	inicio=clock();
	InsertionSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data400,400);
	inicio=clock();
	InsertionSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data500,500);
	inicio=clock();
	InsertionSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data600,600);
	inicio=clock();
	InsertionSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data700,700);
	inicio=clock();
	InsertionSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data800,800);
	inicio=clock();
	InsertionSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data900,900);
	inicio=clock();
	InsertionSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data1000,1000);
	inicio=clock();
	InsertionSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data2000,2000);
	inicio=clock();
	InsertionSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data3000,3000);
	inicio=clock();
	InsertionSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data4000,4000);
	inicio=clock();
	InsertionSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data5000,5000);
	inicio=clock();
	InsertionSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data6000,6000);
	inicio=clock();
	InsertionSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data7000,7000);
	inicio=clock();
	InsertionSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data8000,8000);
	inicio=clock();
	InsertionSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data9000,9000);
	inicio=clock();
	InsertionSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data10000,10000);
	inicio=clock();
	InsertionSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data20000,20000);
	inicio=clock();
	InsertionSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data30000,30000);
	inicio=clock();
	InsertionSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data40000,40000);
	inicio=clock();
	InsertionSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data50000,50000);
	inicio=clock();
	InsertionSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data60000,60000);
	inicio=clock();
	InsertionSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data70000,70000);
	inicio=clock();
	InsertionSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data80000,80000);
	inicio=clock();
	InsertionSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data90000,90000);
	inicio=clock();
	InsertionSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data100000,100000);
	inicio=clock();
	InsertionSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200000,200000);
	inicio=clock();
	InsertionSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Selection Evaluar de 100 a 200,000 datos
	
	CasoPromedio(data100,100);
	inicio=clock();
	SelectionSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200,200);
	inicio=clock();
	SelectionSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data300,300);
	inicio=clock();
	SelectionSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data400,400);
	inicio=clock();
	SelectionSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data500,500);
	inicio=clock();
	SelectionSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data600,600);
	inicio=clock();
	SelectionSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data700,700);
	inicio=clock();
	SelectionSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data800,800);
	inicio=clock();
	SelectionSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data900,900);
	inicio=clock();
	SelectionSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data1000,1000);
	inicio=clock();
	SelectionSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data2000,2000);
	inicio=clock();
	SelectionSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data3000,3000);
	inicio=clock();
	SelectionSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data4000,4000);
	inicio=clock();
	SelectionSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data5000,5000);
	inicio=clock();
	SelectionSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data6000,6000);
	inicio=clock();
	SelectionSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data7000,7000);
	inicio=clock();
	SelectionSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data8000,8000);
	inicio=clock();
	SelectionSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data9000,9000);
	inicio=clock();
	SelectionSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data10000,10000);
	inicio=clock();
	SelectionSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data20000,20000);
	inicio=clock();
	SelectionSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data30000,30000);
	inicio=clock();
	SelectionSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data40000,40000);
	inicio=clock();
	SelectionSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data50000,50000);
	inicio=clock();
	SelectionSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data60000,60000);
	inicio=clock();
	SelectionSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data70000,70000);
	inicio=clock();
	SelectionSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data80000,80000);
	inicio=clock();
	SelectionSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data90000,90000);
	inicio=clock();
	SelectionSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data100000,100000);
	inicio=clock();
	SelectionSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200000,200000);
	inicio=clock();
	SelectionSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Shell Evaluar de 100 a 10,000,000 datos
	
	CasoPromedio(data100,100);
	inicio=clock();
	ShellSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200,200);
	inicio=clock();
	ShellSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data300,300);
	inicio=clock();
	ShellSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data400,400);
	inicio=clock();
	ShellSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data500,500);
	inicio=clock();
	ShellSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data600,600);
	inicio=clock();
	ShellSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data700,700);
	inicio=clock();
	ShellSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data800,800);
	inicio=clock();
	ShellSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data900,900);
	inicio=clock();
	ShellSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data1000,1000);
	inicio=clock();
	ShellSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data2000,2000);
	inicio=clock();
	ShellSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data3000,3000);
	inicio=clock();
	ShellSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data4000,4000);
	inicio=clock();
	ShellSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data5000,5000);
	inicio=clock();
	ShellSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data6000,6000);
	inicio=clock();
	ShellSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data7000,7000);
	inicio=clock();
	ShellSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data8000,8000);
	inicio=clock();
	ShellSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data9000,9000);
	inicio=clock();
	ShellSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data10000,10000);
	inicio=clock();
	ShellSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data20000,20000);
	inicio=clock();
	ShellSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data30000,30000);
	inicio=clock();
	ShellSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data40000,40000);
	inicio=clock();
	ShellSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data50000,50000);
	inicio=clock();
	ShellSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data60000,60000);
	inicio=clock();
	ShellSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data70000,70000);
	inicio=clock();
	ShellSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data80000,80000);
	inicio=clock();
	ShellSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data90000,90000);
	inicio=clock();
	ShellSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data100000,100000);
	inicio=clock();
	ShellSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200000,200000);
	inicio=clock();
	ShellSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data300000,300000);
	inicio=clock();
	ShellSort(data300000,300000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data400000,400000);
	inicio=clock();
	ShellSort(data400000,400000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data500000,500000);
	inicio=clock();
	ShellSort(data500000,500000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data600000,600000);
	inicio=clock();
	ShellSort(data600000,600000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    600,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data700000,700000);
	inicio=clock();
	ShellSort(data700000,700000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    700,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data800000,800000);
	inicio=clock();
	ShellSort(data800000,800000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    800,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data900000,900000);
	inicio=clock();
	ShellSort(data900000,900000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    900,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data1000000,1000000);
	inicio=clock();
	ShellSort(data1000000,1000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  1,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data2000000,2000000);
	inicio=clock();
	ShellSort(data2000000,2000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  2,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data3000000,3000000);
	inicio=clock();
	ShellSort(data3000000,3000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  3,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data4000000,4000000);
	inicio=clock();
	ShellSort(data4000000,4000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  4,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data5000000,5000000);
	inicio=clock();
	ShellSort(data5000000,5000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  5,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data6000000,6000000);
	inicio=clock();
	ShellSort(data6000000,6000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  6,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data7000000,7000000);
	inicio=clock();
	ShellSort(data7000000,7000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  7,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data8000000,8000000);
	inicio=clock();
	ShellSort(data8000000,8000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  8,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data9000000,9000000);
	inicio=clock();
	ShellSort(data9000000,9000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  9,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data10000000,10000000);
	inicio=clock();
	ShellSort(data10000000,10000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para 10,000,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Quick Evaluar de 100 a 10,000,000 datos
	
	CasoPromedio(data100,100);
	inicio=clock();
	QuickSort(data100,0,100-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200,200);
	inicio=clock();
	QuickSort(data200,0,200-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data300,300);
	inicio=clock();
	QuickSort(data300,0,300-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data400,400);
	inicio=clock();
	QuickSort(data400,0,400-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data500,500);
	inicio=clock();
	QuickSort(data500,0,500-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data600,600);
	inicio=clock();
	QuickSort(data600,0,600-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data700,700);
	inicio=clock();
	QuickSort(data700,0,700-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data800,800);
	inicio=clock();
	QuickSort(data800,0,800-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data900,900);
	inicio=clock();
	QuickSort(data900,0,900-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data1000,1000);
	inicio=clock();
	QuickSort(data1000,0,1000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data2000,2000);
	inicio=clock();
	QuickSort(data2000,0,2000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data3000,3000);
	inicio=clock();
	QuickSort(data3000,0,3000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data4000,4000);
	inicio=clock();
	QuickSort(data4000,0,4000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data5000,5000);
	inicio=clock();
	QuickSort(data5000,0,5000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data6000,6000);
	inicio=clock();
	QuickSort(data6000,0,6000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data7000,7000);
	inicio=clock();
	QuickSort(data7000,0,7000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data8000,8000);
	inicio=clock();
	QuickSort(data8000,0,8000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data9000,9000);
	inicio=clock();
	QuickSort(data9000,0,9000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data10000,10000);
	inicio=clock();
	QuickSort(data10000,0,10000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data20000,20000);
	inicio=clock();
	QuickSort(data20000,0,20000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data30000,30000);
	inicio=clock();
	QuickSort(data30000,0,30000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data40000,40000);
	inicio=clock();
	QuickSort(data40000,0,40000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data50000,50000);
	inicio=clock();
	QuickSort(data50000,0,50000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data60000,60000);
	inicio=clock();
	QuickSort(data60000,0,60000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data70000,70000);
	inicio=clock();
	QuickSort(data70000,0,70000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data80000,80000);
	inicio=clock();
	QuickSort(data80000,0,80000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data90000,90000);
	inicio=clock();
	QuickSort(data90000,0,90000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data100000,100000);
	inicio=clock();
	QuickSort(data100000,0,100000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200000,200000);
	inicio=clock();
	QuickSort(data200000,0,200000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data300000,300000);
	inicio=clock();
	QuickSort(data300000,0,300000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data400000,400000);
	inicio=clock();
	QuickSort(data400000,0,400000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data500000,500000);
	inicio=clock();
	QuickSort(data500000,0,500000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data600000,600000);
	inicio=clock();
	QuickSort(data600000,0,600000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para    600,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data700000,700000);
	inicio=clock();
	QuickSort(data700000,0,700000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para    700,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data800000,800000);
	inicio=clock();
	QuickSort(data800000,0,800000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para    800,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data900000,900000);
	inicio=clock();
	QuickSort(data900000,0,900000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para    900,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data1000000,1000000);
	inicio=clock();
	QuickSort(data1000000,0,1000000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para  1,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data2000000,2000000);
	inicio=clock();
	QuickSort(data2000000,0,2000000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para  2,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data3000000,3000000);
	inicio=clock();
	QuickSort(data3000000,0,3000000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para  3,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data4000000,4000000);
	inicio=clock();
	QuickSort(data4000000,0,4000000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para  4,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data5000000,5000000);
	inicio=clock();
	QuickSort(data5000000,0,5000000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para  5,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data6000000,6000000);
	inicio=clock();
	QuickSort(data6000000,0,6000000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para  6,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data7000000,7000000);
	inicio=clock();
	QuickSort(data7000000,0,7000000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para  7,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data8000000,8000000);
	inicio=clock();
	QuickSort(data8000000,0,8000000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para  8,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data9000000,9000000);
	inicio=clock();
	QuickSort(data9000000,0,9000000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para  9,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data10000000,10000000);
	inicio=clock();
	QuickSort(data10000000,0,10000000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para  10,000,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Merge Evaluar de 100 a 500,000 datos
	
	CasoPromedio(data100,100);
	inicio=clock();
	MergeSort(data100,0,100-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200,200);
	inicio=clock();
	MergeSort(data200,0,200-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data300,300);
	inicio=clock();
	MergeSort(data300,0,300-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data400,400);
	inicio=clock();
	MergeSort(data400,0,400-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data500,500);
	inicio=clock();
	MergeSort(data500,0,500-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data600,600);
	inicio=clock();
	MergeSort(data600,0,600-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data700,700);
	inicio=clock();
	MergeSort(data700,0,700-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data800,800);
	inicio=clock();
	MergeSort(data800,0,800-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data900,900);
	inicio=clock();
	MergeSort(data900,0,900-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data1000,1000);
	inicio=clock();
	MergeSort(data1000,0,1000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data2000,2000);
	inicio=clock();
	MergeSort(data2000,0,2000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data3000,3000);
	inicio=clock();
	MergeSort(data3000,0,3000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data4000,4000);
	inicio=clock();
	MergeSort(data4000,0,4000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data5000,5000);
	inicio=clock();
	MergeSort(data5000,0,5000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data6000,6000);
	inicio=clock();
	MergeSort(data6000,0,6000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data7000,7000);
	inicio=clock();
	MergeSort(data7000,0,7000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data8000,8000);
	inicio=clock();
	MergeSort(data8000,0,8000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data9000,9000);
	inicio=clock();
	MergeSort(data9000,0,9000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data10000,10000);
	inicio=clock();
	MergeSort(data10000,0,10000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data20000,20000);
	inicio=clock();
	MergeSort(data20000,0,20000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data30000,30000);
	inicio=clock();
	MergeSort(data30000,0,30000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data40000,40000);
	inicio=clock();
	MergeSort(data40000,0,40000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data50000,50000);
	inicio=clock();
	MergeSort(data50000,0,50000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data60000,60000);
	inicio=clock();
	MergeSort(data60000,0,60000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data70000,70000);
	inicio=clock();
	MergeSort(data70000,0,70000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data80000,80000);
	inicio=clock();
	MergeSort(data80000,0,80000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data90000,90000);
	inicio=clock();
	MergeSort(data90000,0,90000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data100000,100000);
	inicio=clock();
	MergeSort(data100000,0,100000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200000,200000);
	inicio=clock();
	MergeSort(data200000,0,200000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data300000,300000);
	inicio=clock();
	MergeSort(data300000,0,300000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data400000,400000);
	inicio=clock();
	MergeSort(data400000,0,400000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data500000,500000);
	inicio=clock();
	MergeSort(data500000,0,500000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Radix Evaluar de 100 a 500,000 datos
	
	CasoPromedio(data100,100);
	inicio=clock();
	RadixSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200,200);
	inicio=clock();
	RadixSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data300,300);
	inicio=clock();
	RadixSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data400,400);
	inicio=clock();
	RadixSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data500,500);
	inicio=clock();
	RadixSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data600,600);
	inicio=clock();
	RadixSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data700,700);
	inicio=clock();
	RadixSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data800,800);
	inicio=clock();
	RadixSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data900,900);
	inicio=clock();
	RadixSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data1000,1000);
	inicio=clock();
	RadixSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data2000,2000);
	inicio=clock();
	RadixSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data3000,3000);
	inicio=clock();
	RadixSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data4000,4000);
	inicio=clock();
	RadixSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data5000,5000);
	inicio=clock();
	RadixSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data6000,6000);
	inicio=clock();
	RadixSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data7000,7000);
	inicio=clock();
	RadixSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data8000,8000);
	inicio=clock();
	RadixSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data9000,9000);
	inicio=clock();
	RadixSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data10000,10000);
	inicio=clock();
	RadixSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data20000,20000);
	inicio=clock();
	RadixSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data30000,30000);
	inicio=clock();
	RadixSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data40000,40000);
	inicio=clock();
	RadixSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data50000,50000);
	inicio=clock();
	RadixSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data60000,60000);
	inicio=clock();
	RadixSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data70000,70000);
	inicio=clock();
	RadixSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data80000,80000);
	inicio=clock();
	RadixSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data90000,90000);
	inicio=clock();
	RadixSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data100000,100000);
	inicio=clock();
	RadixSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200000,200000);
	inicio=clock();
	RadixSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data300000,300000);
	inicio=clock();
	RadixSort(data300000,300000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data400000,400000);
	inicio=clock();
	RadixSort(data400000,400000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data500000,500000);
	inicio=clock();
	RadixSort(data500000,500000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Heap Evaluar de 100 a 10,000,000 datos
	
	CasoPromedio(data100,100);
	inicio=clock();
	HeapSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200,200);
	inicio=clock();
	HeapSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data300,300);
	inicio=clock();
	HeapSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data400,400);
	inicio=clock();
	HeapSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data500,500);
	inicio=clock();
	HeapSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data600,600);
	inicio=clock();
	HeapSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data700,700);
	inicio=clock();
	HeapSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data800,800);
	inicio=clock();
	HeapSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data900,900);
	inicio=clock();
	HeapSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data1000,1000);
	inicio=clock();
	HeapSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data2000,2000);
	inicio=clock();
	HeapSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data3000,3000);
	inicio=clock();
	HeapSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data4000,4000);
	inicio=clock();
	HeapSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data5000,5000);
	inicio=clock();
	HeapSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data6000,6000);
	inicio=clock();
	HeapSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data7000,7000);
	inicio=clock();
	HeapSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data8000,8000);
	inicio=clock();
	HeapSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data9000,9000);
	inicio=clock();
	HeapSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data10000,10000);
	inicio=clock();
	HeapSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data20000,20000);
	inicio=clock();
	HeapSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data30000,30000);
	inicio=clock();
	HeapSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data40000,40000);
	inicio=clock();
	HeapSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data50000,50000);
	inicio=clock();
	HeapSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data60000,60000);
	inicio=clock();
	HeapSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data70000,70000);
	inicio=clock();
	HeapSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data80000,80000);
	inicio=clock();
	HeapSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data90000,90000);
	inicio=clock();
	HeapSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data100000,100000);
	inicio=clock();
	HeapSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data200000,200000);
	inicio=clock();
	HeapSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data300000,300000);
	inicio=clock();
	HeapSort(data300000,300000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data400000,400000);
	inicio=clock();
	HeapSort(data400000,400000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data500000,500000);
	inicio=clock();
	HeapSort(data500000,500000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data600000,600000);
	inicio=clock();
	HeapSort(data600000,600000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    600,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data700000,700000);
	inicio=clock();
	HeapSort(data700000,700000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    700,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data800000,800000);
	inicio=clock();
	HeapSort(data800000,800000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    800,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data900000,900000);
	inicio=clock();
	HeapSort(data900000,900000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    900,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data1000000,1000000);
	inicio=clock();
	HeapSort(data1000000,1000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  1,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data2000000,2000000);
	inicio=clock();
	HeapSort(data2000000,2000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  2,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data3000000,3000000);
	inicio=clock();
	HeapSort(data3000000,3000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  3,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data4000000,4000000);
	inicio=clock();
	HeapSort(data4000000,4000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  4,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data5000000,5000000);
	inicio=clock();
	HeapSort(data5000000,5000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  5,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data6000000,6000000);
	inicio=clock();
	HeapSort(data6000000,6000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  6,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data7000000,7000000);
	inicio=clock();
	HeapSort(data7000000,7000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  7,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data8000000,8000000);
	inicio=clock();
	HeapSort(data8000000,8000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  8,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data9000000,9000000);
	inicio=clock();
	HeapSort(data9000000,9000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  9,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPromedio(data10000000,10000000);
	inicio=clock();
	HeapSort(data10000000,10000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para 10,000,000 datos: %f\n",tiempo);
	renglon++;
	
	//CASO PEOR
	gotoxy(0,renglon);
	printf("CASO PEOR:");
	
	renglon++;
	renglon++;
	
	//Bubble Evaluar de 100 a 5,000 datos
	
	CasoPeor(data100,100);
	inicio=clock();
	BubbleSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200,200);
	inicio=clock();
	BubbleSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data300,300);
	inicio=clock();
	BubbleSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data400,400);
	inicio=clock();
	BubbleSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data500,500);
	inicio=clock();
	BubbleSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data600,600);
	inicio=clock();
	BubbleSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data700,700);
	inicio=clock();
	BubbleSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data800,800);
	inicio=clock();
	BubbleSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data900,900);
	inicio=clock();
	BubbleSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data1000,1000);
	inicio=clock();
	BubbleSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data2000,2000);
	inicio=clock();
	BubbleSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data3000,3000);
	inicio=clock();
	BubbleSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data4000,4000);
	inicio=clock();
	BubbleSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data5000,5000);
	inicio=clock();
	BubbleSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Bubble Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Insertion Evaluar de 100 a 200,000 datos
	
	CasoPeor(data100,100);
	inicio=clock();
	InsertionSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200,200);
	inicio=clock();
	InsertionSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data300,300);
	inicio=clock();
	InsertionSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data400,400);
	inicio=clock();
	InsertionSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data500,500);
	inicio=clock();
	InsertionSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data600,600);
	inicio=clock();
	InsertionSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data700,700);
	inicio=clock();
	InsertionSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data800,800);
	inicio=clock();
	InsertionSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data900,900);
	inicio=clock();
	InsertionSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data1000,1000);
	inicio=clock();
	InsertionSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data2000,2000);
	inicio=clock();
	InsertionSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data3000,3000);
	inicio=clock();
	InsertionSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data4000,4000);
	inicio=clock();
	InsertionSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data5000,5000);
	inicio=clock();
	InsertionSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data6000,6000);
	inicio=clock();
	InsertionSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data7000,7000);
	inicio=clock();
	InsertionSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data8000,8000);
	inicio=clock();
	InsertionSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data9000,9000);
	inicio=clock();
	InsertionSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data10000,10000);
	inicio=clock();
	InsertionSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data20000,20000);
	inicio=clock();
	InsertionSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data30000,30000);
	inicio=clock();
	InsertionSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data40000,40000);
	inicio=clock();
	InsertionSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data50000,50000);
	inicio=clock();
	InsertionSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data60000,60000);
	inicio=clock();
	InsertionSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data70000,70000);
	inicio=clock();
	InsertionSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data80000,80000);
	inicio=clock();
	InsertionSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data90000,90000);
	inicio=clock();
	InsertionSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data100000,100000);
	inicio=clock();
	InsertionSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200000,200000);
	inicio=clock();
	InsertionSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Insertion Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Selection Evaluar de 100 a 200,000 datos
	
	CasoPeor(data100,100);
	inicio=clock();
	SelectionSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200,200);
	inicio=clock();
	SelectionSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data300,300);
	inicio=clock();
	SelectionSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data400,400);
	inicio=clock();
	SelectionSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data500,500);
	inicio=clock();
	SelectionSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data600,600);
	inicio=clock();
	SelectionSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data700,700);
	inicio=clock();
	SelectionSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data800,800);
	inicio=clock();
	SelectionSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data900,900);
	inicio=clock();
	SelectionSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data1000,1000);
	inicio=clock();
	SelectionSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data2000,2000);
	inicio=clock();
	SelectionSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data3000,3000);
	inicio=clock();
	SelectionSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data4000,4000);
	inicio=clock();
	SelectionSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data5000,5000);
	inicio=clock();
	SelectionSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data6000,6000);
	inicio=clock();
	SelectionSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data7000,7000);
	inicio=clock();
	SelectionSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data8000,8000);
	inicio=clock();
	SelectionSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data9000,9000);
	inicio=clock();
	SelectionSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data10000,10000);
	inicio=clock();
	SelectionSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data20000,20000);
	inicio=clock();
	SelectionSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data30000,30000);
	inicio=clock();
	SelectionSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data40000,40000);
	inicio=clock();
	SelectionSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data50000,50000);
	inicio=clock();
	SelectionSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data60000,60000);
	inicio=clock();
	SelectionSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data70000,70000);
	inicio=clock();
	SelectionSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data80000,80000);
	inicio=clock();
	SelectionSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data90000,90000);
	inicio=clock();
	SelectionSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data100000,100000);
	inicio=clock();
	SelectionSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200000,200000);
	inicio=clock();
	SelectionSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Selection Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Shell Evaluar de 100 a 10,000,000 datos
	
	CasoPeor(data100,100);
	inicio=clock();
	ShellSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200,200);
	inicio=clock();
	ShellSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data300,300);
	inicio=clock();
	ShellSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data400,400);
	inicio=clock();
	ShellSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data500,500);
	inicio=clock();
	ShellSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data600,600);
	inicio=clock();
	ShellSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data700,700);
	inicio=clock();
	ShellSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data800,800);
	inicio=clock();
	ShellSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data900,900);
	inicio=clock();
	ShellSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data1000,1000);
	inicio=clock();
	ShellSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data2000,2000);
	inicio=clock();
	ShellSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data3000,3000);
	inicio=clock();
	ShellSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data4000,4000);
	inicio=clock();
	ShellSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data5000,5000);
	inicio=clock();
	ShellSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data6000,6000);
	inicio=clock();
	ShellSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data7000,7000);
	inicio=clock();
	ShellSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data8000,8000);
	inicio=clock();
	ShellSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data9000,9000);
	inicio=clock();
	ShellSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data10000,10000);
	inicio=clock();
	ShellSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data20000,20000);
	inicio=clock();
	ShellSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data30000,30000);
	inicio=clock();
	ShellSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data40000,40000);
	inicio=clock();
	ShellSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data50000,50000);
	inicio=clock();
	ShellSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data60000,60000);
	inicio=clock();
	ShellSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data70000,70000);
	inicio=clock();
	ShellSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data80000,80000);
	inicio=clock();
	ShellSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data90000,90000);
	inicio=clock();
	ShellSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data100000,100000);
	inicio=clock();
	ShellSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200000,200000);
	inicio=clock();
	ShellSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data300000,300000);
	inicio=clock();
	ShellSort(data300000,300000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data400000,400000);
	inicio=clock();
	ShellSort(data400000,400000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data500000,500000);
	inicio=clock();
	ShellSort(data500000,500000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data600000,600000);
	inicio=clock();
	ShellSort(data600000,600000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    600,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data700000,700000);
	inicio=clock();
	ShellSort(data700000,700000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    700,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data800000,800000);
	inicio=clock();
	ShellSort(data800000,800000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    800,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data900000,900000);
	inicio=clock();
	ShellSort(data900000,900000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para    900,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data1000000,1000000);
	inicio=clock();
	ShellSort(data1000000,1000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  1,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data2000000,2000000);
	inicio=clock();
	ShellSort(data2000000,2000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  2,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data3000000,3000000);
	inicio=clock();
	ShellSort(data3000000,3000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  3,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data4000000,4000000);
	inicio=clock();
	ShellSort(data4000000,4000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  4,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data5000000,5000000);
	inicio=clock();
	ShellSort(data5000000,5000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  5,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data6000000,6000000);
	inicio=clock();
	ShellSort(data6000000,6000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  6,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data7000000,7000000);
	inicio=clock();
	ShellSort(data7000000,7000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  7,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data8000000,8000000);
	inicio=clock();
	ShellSort(data8000000,8000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  8,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data9000000,9000000);
	inicio=clock();
	ShellSort(data9000000,9000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para  9,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data10000000,10000000);
	inicio=clock();
	ShellSort(data10000000,10000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Shell Sort para 10,000,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Quick Evaluar de 100 a 30,000 datos
	
	CasoPeor(data100,100);
	inicio=clock();
	QuickSort(data100,0,100-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200,200);
	inicio=clock();
	QuickSort(data200,0,200-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data300,300);
	inicio=clock();
	QuickSort(data300,0,300-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data400,400);
	inicio=clock();
	QuickSort(data400,0,400-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data500,500);
	inicio=clock();
	QuickSort(data500,0,500-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data600,600);
	inicio=clock();
	QuickSort(data600,0,600-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data700,700);
	inicio=clock();
	QuickSort(data700,0,700-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data800,800);
	inicio=clock();
	QuickSort(data800,0,800-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data900,900);
	inicio=clock();
	QuickSort(data900,0,900-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data1000,1000);
	inicio=clock();
	QuickSort(data1000,0,1000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data2000,2000);
	inicio=clock();
	QuickSort(data2000,0,2000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data3000,3000);
	inicio=clock();
	QuickSort(data3000,0,3000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data4000,4000);
	inicio=clock();
	QuickSort(data4000,0,4000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data5000,5000);
	inicio=clock();
	QuickSort(data5000,0,5000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data6000,6000);
	inicio=clock();
	QuickSort(data6000,0,6000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data7000,7000);
	inicio=clock();
	QuickSort(data7000,0,7000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data8000,8000);
	inicio=clock();
	QuickSort(data8000,0,8000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data9000,9000);
	inicio=clock();
	QuickSort(data9000,0,9000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data10000,10000);
	inicio=clock();
	QuickSort(data10000,0,10000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data20000,20000);
	inicio=clock();
	QuickSort(data20000,0,20000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data30000,30000);
	inicio=clock();
	QuickSort(data30000,0,30000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Quick Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Merge Evaluar de 100 a 500,000 datos
	
	CasoPeor(data100,100);
	inicio=clock();
	MergeSort(data100,0,100-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200,200);
	inicio=clock();
	MergeSort(data200,0,200-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data300,300);
	inicio=clock();
	MergeSort(data300,0,300-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data400,400);
	inicio=clock();
	MergeSort(data400,0,400-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data500,500);
	inicio=clock();
	MergeSort(data500,0,500-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data600,600);
	inicio=clock();
	MergeSort(data600,0,600-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data700,700);
	inicio=clock();
	MergeSort(data700,0,700-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data800,800);
	inicio=clock();
	MergeSort(data800,0,800-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data900,900);
	inicio=clock();
	MergeSort(data900,0,900-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data1000,1000);
	inicio=clock();
	MergeSort(data1000,0,1000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data2000,2000);
	inicio=clock();
	MergeSort(data2000,0,2000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data3000,3000);
	inicio=clock();
	MergeSort(data3000,0,3000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data4000,4000);
	inicio=clock();
	MergeSort(data4000,0,4000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data5000,5000);
	inicio=clock();
	MergeSort(data5000,0,5000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data6000,6000);
	inicio=clock();
	MergeSort(data6000,0,6000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data7000,7000);
	inicio=clock();
	MergeSort(data7000,0,7000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data8000,8000);
	inicio=clock();
	MergeSort(data8000,0,8000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data9000,9000);
	inicio=clock();
	MergeSort(data9000,0,9000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data10000,10000);
	inicio=clock();
	MergeSort(data10000,0,10000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data20000,20000);
	inicio=clock();
	MergeSort(data20000,0,20000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data30000,30000);
	inicio=clock();
	MergeSort(data30000,0,30000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data40000,40000);
	inicio=clock();
	MergeSort(data40000,0,40000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data50000,50000);
	inicio=clock();
	MergeSort(data50000,0,50000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data60000,60000);
	inicio=clock();
	MergeSort(data60000,0,60000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data70000,70000);
	inicio=clock();
	MergeSort(data70000,0,70000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data80000,80000);
	inicio=clock();
	MergeSort(data80000,0,80000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data90000,90000);
	inicio=clock();
	MergeSort(data90000,0,90000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data100000,100000);
	inicio=clock();
	MergeSort(data100000,0,100000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200000,200000);
	inicio=clock();
	MergeSort(data200000,0,200000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data300000,300000);
	inicio=clock();
	MergeSort(data300000,0,300000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data400000,400000);
	inicio=clock();
	MergeSort(data400000,0,400000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data500000,500000);
	inicio=clock();
	MergeSort(data500000,0,500000-1);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Merge Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Radix Evaluar de 100 a 500,000 datos
	
	CasoPeor(data100,100);
	inicio=clock();
	RadixSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200,200);
	inicio=clock();
	RadixSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data300,300);
	inicio=clock();
	RadixSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data400,400);
	inicio=clock();
	RadixSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data500,500);
	inicio=clock();
	RadixSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data600,600);
	inicio=clock();
	RadixSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data700,700);
	inicio=clock();
	RadixSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data800,800);
	inicio=clock();
	RadixSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data900,900);
	inicio=clock();
	RadixSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data1000,1000);
	inicio=clock();
	RadixSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data2000,2000);
	inicio=clock();
	RadixSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data3000,3000);
	inicio=clock();
	RadixSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data4000,4000);
	inicio=clock();
	RadixSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data5000,5000);
	inicio=clock();
	RadixSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data6000,6000);
	inicio=clock();
	RadixSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data7000,7000);
	inicio=clock();
	RadixSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data8000,8000);
	inicio=clock();
	RadixSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data9000,9000);
	inicio=clock();
	RadixSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data10000,10000);
	inicio=clock();
	RadixSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data20000,20000);
	inicio=clock();
	RadixSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data30000,30000);
	inicio=clock();
	RadixSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data40000,40000);
	inicio=clock();
	RadixSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data50000,50000);
	inicio=clock();
	RadixSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data60000,60000);
	inicio=clock();
	RadixSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data70000,70000);
	inicio=clock();
	RadixSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data80000,80000);
	inicio=clock();
	RadixSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data90000,90000);
	inicio=clock();
	RadixSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data100000,100000);
	inicio=clock();
	RadixSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200000,200000);
	inicio=clock();
	RadixSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data300000,300000);
	inicio=clock();
	RadixSort(data300000,300000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data400000,400000);
	inicio=clock();
	RadixSort(data400000,400000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data500000,500000);
	inicio=clock();
	RadixSort(data500000,500000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Radix Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	renglon++;
	
	//Heap Evaluar de 100 a 10,000,000 datos
	
	CasoPeor(data100,100);
	inicio=clock();
	HeapSort(data100,100);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        100 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200,200);
	inicio=clock();
	HeapSort(data200,200);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        200 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data300,300);
	inicio=clock();
	HeapSort(data300,300);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        300 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data400,400);
	inicio=clock();
	HeapSort(data400,400);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        400 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data500,500);
	inicio=clock();
	HeapSort(data500,500);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        500 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data600,600);
	inicio=clock();
	HeapSort(data600,600);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        600 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data700,700);
	inicio=clock();
	HeapSort(data700,700);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        700 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data800,800);
	inicio=clock();
	HeapSort(data800,800);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        800 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data900,900);
	inicio=clock();
	HeapSort(data900,900);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para        900 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data1000,1000);
	inicio=clock();
	HeapSort(data1000,1000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      1,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data2000,2000);
	inicio=clock();
	HeapSort(data2000,2000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      2,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data3000,3000);
	inicio=clock();
	HeapSort(data3000,3000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      3,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data4000,4000);
	inicio=clock();
	HeapSort(data4000,4000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      4,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data5000,5000);
	inicio=clock();
	HeapSort(data5000,5000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      5,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data6000,6000);
	inicio=clock();
	HeapSort(data6000,6000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      6,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data7000,7000);
	inicio=clock();
	HeapSort(data7000,7000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      7,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data8000,8000);
	inicio=clock();
	HeapSort(data8000,8000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      8,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data9000,9000);
	inicio=clock();
	HeapSort(data9000,9000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para      9,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data10000,10000);
	inicio=clock();
	HeapSort(data10000,10000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     10,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data20000,20000);
	inicio=clock();
	HeapSort(data20000,20000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     20,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data30000,30000);
	inicio=clock();
	HeapSort(data30000,30000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     30,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data40000,40000);
	inicio=clock();
	HeapSort(data40000,40000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     40,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data50000,50000);
	inicio=clock();
	HeapSort(data50000,50000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     50,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data60000,60000);
	inicio=clock();
	HeapSort(data60000,60000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     60,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data70000,70000);
	inicio=clock();
	HeapSort(data70000,70000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     70,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data80000,80000);
	inicio=clock();
	HeapSort(data80000,80000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     80,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data90000,90000);
	inicio=clock();
	HeapSort(data90000,90000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para     90,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data100000,100000);
	inicio=clock();
	HeapSort(data100000,100000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    100,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data200000,200000);
	inicio=clock();
	HeapSort(data200000,200000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    200,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data300000,300000);
	inicio=clock();
	HeapSort(data300000,300000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    300,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data400000,400000);
	inicio=clock();
	HeapSort(data400000,400000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    400,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data500000,500000);
	inicio=clock();
	HeapSort(data500000,500000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    500,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data600000,600000);
	inicio=clock();
	HeapSort(data600000,600000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    600,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data700000,700000);
	inicio=clock();
	HeapSort(data700000,700000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    700,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data800000,800000);
	inicio=clock();
	HeapSort(data800000,800000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    800,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data900000,900000);
	inicio=clock();
	HeapSort(data900000,900000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para    900,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data1000000,1000000);
	inicio=clock();
	HeapSort(data1000000,1000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  1,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data2000000,2000000);
	inicio=clock();
	HeapSort(data2000000,2000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  2,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data3000000,3000000);
	inicio=clock();
	HeapSort(data3000000,3000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  3,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data4000000,4000000);
	inicio=clock();
	HeapSort(data4000000,4000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  4,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data5000000,5000000);
	inicio=clock();
	HeapSort(data5000000,5000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  5,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data6000000,6000000);
	inicio=clock();
	HeapSort(data6000000,6000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  6,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data7000000,7000000);
	inicio=clock();
	HeapSort(data7000000,7000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  7,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data8000000,8000000);
	inicio=clock();
	HeapSort(data8000000,8000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  8,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data9000000,9000000);
	inicio=clock();
	HeapSort(data9000000,9000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para  9,000,000 datos: %f\n",tiempo);
	renglon++;
	
	CasoPeor(data10000000,10000000);
	inicio=clock();
	HeapSort(data10000000,10000000);
	fin=clock();
	tiempo=((float)fin-(float)inicio)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo del Heap Sort para 10,000,000 datos: %f\n",tiempo);
	renglon++;
	
	
	finglobal=clock();
	tiempoglobal=((float)finglobal-(float)inicioglobal)/CLK_TCK;
	gotoxy(0,renglon);
	printf("Tiempo Global: %f\n",tiempoglobal);
}

void gotoxy(int x,int y)
{
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos); 
}

void CasoMejor(int arreglo[], int tam)
{
	int cont=0;
	do
	{
		arreglo[cont]=cont+1;
		cont++;
		if(cont==tam-2)
		{
			arreglo[tam-2]=tam;
			arreglo[tam-1]=tam-1;
			break;
		}
	}
	while(cont<tam);
}

void CasoPromedio(int arreglo[], int tam)
{
	int cont=0;
	srand(time(NULL));
	do
	{
		arreglo[cont]=1+rand()%(10000000);
		cont++;
	}
	while(cont<tam);
}

void CasoPeor(int arreglo[], int tam)
{
	int cont=0;
	do
	{
		arreglo[cont]=tam-cont;
		cont++;
	}
	while(cont<tam);
}

void Imprimir(int arreglo[], int tam)
{
	int cont=0;
	do
	{
		printf("[%d]\n",arreglo[cont]);
		cont++;
	}
	while(cont<tam);
}

void BubbleSort(int arreglo[], int tam)
{
	int cont=0,aux;
	
	do
	{
		if(arreglo[cont]>arreglo[cont+1])
		{
			aux=arreglo[cont];
			arreglo[cont]=arreglo[cont+1];
			arreglo[cont+1]=aux;
			cont=0;
		}
		else
		{
			cont++;
		}
	}
	while(cont<tam);
}

void InsertionSort(int arreglo[], int tam)
{
	for(int cont=1; cont<tam; cont++)
	{
		int aux1 = arreglo[cont];
		int aux2 = cont;
		while(aux2>0&&arreglo[aux2-1]>aux1)
		{
			arreglo[aux2] = arreglo[aux2-1];
			aux2--;
		}
		arreglo[aux2]=aux1;
	}
}

void SelectionSort(int arreglo[], int tam)
{
	int aux,min;
	for(int cont1=0; cont1<tam; cont1++)
	{
		min=cont1;
		for(int cont2=cont1+1; cont2<tam; cont2++)
		{
			if(arreglo[cont2]<arreglo[min])
			{
				min=cont2;
			}
		}
		aux=arreglo[cont1];
		arreglo[cont1]=arreglo[min];
		arreglo[min]=aux;
	}
}

void ShellSort(int arreglo[], int tam)
{
	int saltos, aux;
    saltos=tam/2;

    	while(saltos>0)
    	{
	    	for(int i=saltos+1;i<=tam;i++)
		   	{
		   		int j=i-saltos;
            	while(j>=0)
            	{
             		if(arreglo[j]>=arreglo[j+saltos])
					{
        	    		aux=arreglo[j];
                    	arreglo[j]=arreglo[j+saltos];
                    	arreglo[j+saltos]=aux;
					}
					else
					{
						j=0;
					}
					j=j-saltos;
			 	}
		   	}
			saltos=saltos/2;
	  	}	
}

void QuickSort(int arreglo[],int first,int last)
{
	int cont1,cont2,pivot,aux;

   	if(first<last)
   	{
      	pivot=first;
      	cont1=first;
      	cont2=last;

      	while(cont1<cont2)
	  	{
         	while(arreglo[cont1]<=arreglo[pivot]&&cont1<last)
         	{
         		cont1++;
		 	}
         	while(arreglo[cont2]>arreglo[pivot])
         	{
         		cont2--;
		 	}
         	if(cont1<cont2)
		 	{
            	aux=arreglo[cont1];
            	arreglo[cont1]=arreglo[cont2];
            	arreglo[cont2]=aux;
         	}
      	}
      	
      	aux=arreglo[pivot];
      	arreglo[pivot]=arreglo[cont2];
      	arreglo[cont2]=aux;
      	QuickSort(arreglo,first,cont2-1);
      	QuickSort(arreglo,cont2+1,last);
   	}
}

void MergeSort(int arr[], int l, int r) 
{
	if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        MergeSort(arr, l, m); 
        MergeSort(arr, m+1, r); 
  
        PreMerge(arr, l, m, r); 
    }
}

void PreMerge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void RadixSort(int arreglo[], int tam)
{
	int max = arreglo[0];
	for (int i=1;i<tam;i++)
	{
    	if (arreglo[i] > max)
    	{
    		max = arreglo[i];
		}
	}
	int m=max;
	
    for (int exp=1;m/exp>0;exp*=10)
	{
		int salida[tam];
		int i,count[10]={0}; 
	  
	    for (i=0;i<tam;i++)
	    {
	    	count[(arreglo[i]/exp)%10]++; 
		}
	  
	    for (i=1;i<10;i++)
	    {
	    	count[i]+=count[i-1]; 
		}
		
	    for (i=tam-1;i>=0;i--) 
	    { 
	        salida[count[(arreglo[i]/exp)%10]-1]=arreglo[i]; 
	        count[(arreglo[i]/exp)%10]--; 
	    } 
	   
	    for (i=0;i<tam;i++) 
	    {
	    	arreglo[i]=salida[i]; 
		}
	}
}

void HeapSort(int arreglo[], int tam)
{
	int aux;
	for (int i = tam / 2 - 1; i >= 0; i--)
		heapify(arreglo,tam, i);

	for (int i=tam-1; i>=0; i--)
	{
		aux=arreglo[0];
		arreglo[0]=arreglo[i];
		arreglo[i]=aux;

		heapify(arreglo,i, 0);
	}
}

void heapify(int arreglo[],int tam, int i)
{
	int largest = i,aux;
	int d = 2*i + 1;
	int iz = 2*i + 2;

	if (iz < tam && arreglo[iz] > arreglo[largest])
		largest = iz;

	if (d < tam && arreglo[d] > arreglo[largest])
		largest = d;

	if (largest != i)
	{
		aux=arreglo[i];
		arreglo[i]=arreglo[largest];
		arreglo[largest]=aux;

		heapify(arreglo,tam, largest);
	}
}
