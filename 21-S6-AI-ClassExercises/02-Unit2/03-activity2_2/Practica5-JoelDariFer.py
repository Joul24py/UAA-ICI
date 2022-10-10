#%% Presentación
'''
   Universidad Autónoma de Aguascalientes

         Centro de Ciencias Básicas
 Departamento de Ciencias de la Computación
          Aprendizaje Inteligente
                   6° "A"

                 Práctica 5

   Profesor: Francisco Javier Luna Rosas
  Alumnos:
      Espinoza Sánchez Joel Alejandro
      Gómez Garza Dariana
      González Arenas Fernando Francisco

  Fecha de Entrega: 7 de abril del 2021

Descripción: CJ
'''

#%% Librerías
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy.cluster.hierarchy as sch
from scipy.cluster.hierarchy import dendrogram, linkage, fcluster

#%% Lee datos
Estudiantes = pd.read_csv('C:/Users/Dell/Desktop/wenas/EjemploEstudiantes.csv',
                          engine = 'python', index_col = 0, sep=';', decimal=',')

print(Estudiantes.head())

#%% Procesa calificaciones
calificaciones = Estudiantes.iloc[:,[0,1,2,3,4]].values

print(calificaciones)

#%% Realiza CJ
CJ = linkage(calificaciones, 'ward')

#%% Procesa el dendrograma
dendrogram = sch.dendrogram(CJ)

clusters = fcluster(CJ, t = 2, criterion = 'distance')

#%% Actualiza datos
Estudiantes['CJ'] = clusters

print(Estudiantes)

Estudiantes.to_csv('C:/Users/Dell/Desktop/wenas/EjemploEstudiantesConCJ.csv')