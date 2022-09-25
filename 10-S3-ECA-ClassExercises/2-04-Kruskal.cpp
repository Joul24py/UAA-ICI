/*
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Estructuras Computacionales Avanzadas
3° "A"

Algoritmo de Kruskal

Profesor: Julio César Ponce Gallegos

Alumno: Espinoza Sánchez Joel Alejandro

Aguascalientes, Ags. 22 de noviembre de 2019
*/
//Las librerías------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include<stdio.h>
#include<conio.h>
#define DEBUG
#define REP(i,a)  for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define ii pair<int,int>
using namespace std;

//Variables globales-------------------------------------------------------------------------------------------
vector<int> pset;
vector<pair<int,ii> >grafo;

//Funciones de apoyo del algoritmo de Kruskal------------------------------------------------------------------
void initSet(int size)
{
	int i;
    pset.resize(size);
    REP(i,size+1)
    {
    	pset[i]=i;
	}
}

int findSet(int i)
{
    return (pset[i]==i)? i:(pset[i]=findSet(pset[i]));
}

void unionSet(int i,int j)
{
    pset[findSet(i)]=findSet(j);
}

bool isSameSet(int i,int j)
{
    if(findSet(i) == findSet(j))
    {
    	return true;
	}
    return false;
}

//El algoritmo de Kruskal--------------------------------------------------------------------------------------
void kruskal(int N)
{
	int sum=0,i;
	initSet(N);
	sort(grafo.begin(),grafo.end());

	for(i=0;i<grafo.size();i++)
	{      
		pair<int,ii>aux=grafo[i];
	    if(!isSameSet(aux.second.first,aux.second.second))
	    {    
			cout<<"Pasa en: "<<aux.second.first<<","<<aux.second.second<<endl;
	        sum=aux.first+sum;
	        unionSet(aux.second.first,aux.second.second);
	    }
	}
	cout<<"El peso: "<<sum;
}

//La función main----------------------------------------------------------------------------------------------
int main()
{
	int V,A,i,a,b,w;
	cout<<"\t\tAlgoritmo de Kruskal"<<endl;
	printf("\n");
	cout<<"Ingrese la cantidad de aristas"<<endl;
	cin>>A;
	cout<<"Ingrese la cantidad de vertices"<<endl;
	cin>>V;
	cout<<"Ingrese desde que vertice a que vertice: "<<endl;
	for(i=0;i<A;i++)
	{
		cout<<"Del vertice: "; cin>>a; cout<<"Al vertice: ";cin>>b;
		cout<<"Con peso: "; cin>>w;
		printf("\n\n");
		grafo.push_back(pair<int,ii>(w,ii(a,b)));
	}
	
	kruskal(V);
	getch();
	return 0;
}
