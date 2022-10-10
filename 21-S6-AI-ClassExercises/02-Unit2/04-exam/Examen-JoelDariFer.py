#%% Presentación
'''
   Universidad Autónoma de Aguascalientes

         Centro de Ciencias Básicas
 Departamento de Ciencias de la Computación
          Aprendizaje Inteligente
                   6° "A"

                 Segunda Evaluación Parcial

   Profesor: Francisco Javier Luna Rosas
  Alumnos:
      Espinoza Sánchez Joel Alejandro
      Gómez Garza Dariana
      González Arenas Fernando Francisco

  Fecha de Entrega: 11 de abril del 2021

Descripción: Código correspondiente a la segunda evaluación parcial de la implementación del PCA
'''

#%% Importamos las librerías
import os
import pandas as pd
import numpy as np
import scipy.linalg as la

#%% APARTADO DE LA CREACIÓN DE LA CLASE
#   Se crea la clase de PCA
class ACP():
    
    #%% Se inicializa la clase
    def __init__(self, DF = pd.DataFrame()):
        self.filas = DF.shape[0]
        self.columnas = DF.shape[1]
        self.DF = DF
        
        def filas(self):
            return self.filas
        
        def columnas(self):
            return self.columnas
        
        def DF(self):
            return self.DF
        
    #%% Se define el método para hacer el cálculo del Centrado Reducido
    def CentradoReducido(self):
        MatrizLista = np.empty([self.filas, self.columnas])
        for i in range(self.filas):
            for j in range(self.columnas):
                a = self.DF.iloc[i,j]
                media = np.mean(self.DF.iloc[:,j])
                desviacion = np.std(self.DF.iloc[:,j])
                r = (a - media) / desviacion
                MatrizLista[i,j] = r
        return MatrizLista
    
    #%% Se calcula la Matriz de Individuos
    def MatrizRIndividuos(self, matriz):
        A = np.matrix(matriz)
        B = np.matrix(matriz)
        T = np.transpose(A)
        TB = T * B
        R = TB / self.filas
        return R
    
    #%% Se hacen los cálculos de las matrices para los Componentes Principales
    def Componentes(self, X, V):
        ComponentesPrincipales = X * V
        return ComponentesPrincipales
    
    #%% Se hacen los cálculos para los cosenos de cada individuo
    def CosenosIndividuos(self, comp, matrizX):
        matriz_cosenos = np.empty([self.filas, self.columnas])
        cuadradoX = np.power(matrizX,2)
        sumarenglones = cuadradoX.sum(axis = 1)
        for i in range(self.filas):
            for j in range(self.columnas):
                componente_cuadrado = np.power(comp, 2)
                matriz_cosenos[i,j] = componente_cuadrado[i,j] / sumarenglones[i]
        return matriz_cosenos
    
    #%% Se realizan los cálculos de Álgebra Lineal para los eigenvalores
    def Eigenvalores(self, matriz):
        valores_propios, vectores_propios = la.eig(matriz)
        
        valores_propios = valores_propios.real
        vectores_propios = vectores_propios.real
        indice_fila, indice_columna = vectores_propios.shape
        
        cuadrado_vectores = np.power(vectores_propios, 2)
        
        print("Lambda1")
        lambda1 = valores_propios[0]
        print(lambda1.real)
        
        print("Vectores propios al cuadrado")
        print(cuadrado_vectores)
        cuadrado = pd.DataFrame(cuadrado_vectores)
        print(cuadrado)
        
        v1 = cuadrado_vectores[:,0] * valores_propios[0]
        df_v1 = pd.DataFrame(v1)
        print("v1 * lambda")
        print(df_v1)
        
    #%% Se calcula la Matriz de Variables
    def matrizRVariables(self, matriz):
        A = np.matrix(matriz)
        B = np.matrix(matriz)
        T = np.transpose(B)
        producto = A * T
        R = producto / self.filas
        return R

#%% APARTADO DEL PROCESO DEL PCA
#   Se comienza el procedimiento PCA

#%% Se extraen los datos del archivo y se crea el objeto PCA
os.chdir("C:/Users/Dell/Desktop/datos") #Dirección del archivo
datos_est = pd.read_csv('EjemploEstudiantes.csv', delimiter = ';', decimal = ',', index_col = 0)
datos = ACP(datos_est)
print(datos.DF)

#%% Procedimiento para centrar y reducir datos de matriz
matrizX = datos.CentradoReducido()
centrado_reducido = pd.DataFrame(matrizX)
print(centrado_reducido)

#%% Se crea la matriz de correlaciones
MatrizRind = datos.MatrizRIndividuos(matrizX)
MatrizR = pd.DataFrame(MatrizRind)
print(MatrizR)

#%% Se crea la matriz de componentes principales
ComponentesPrincipales = datos.Componentes(matrizX, MatrizRind)
print(ComponentesPrincipales)
mi_df = pd.DataFrame(ComponentesPrincipales)
print(mi_df)

#%% Se crea la matriz de cosenos cuadrados
cosenos = datos.CosenosIndividuos(ComponentesPrincipales, matrizX)
mi_df_cosenos = pd.DataFrame(cosenos)
print(mi_df_cosenos)

#%% Se crea el círculo de correlaciones
matrizX = datos.CentradoReducido()
print("Matriz X de variables")
print(matrizX)

#%% Se crea la matriz de correlaciones
print("Matriz real de variables")
matrizRvar = datos.matrizRVariables(matrizX)
print(MatrizR)

#%% Se calculan los valores propios y se imprimen los datos finales del procedimiento PCA
datos.Eigenvalores(matrizRvar)
