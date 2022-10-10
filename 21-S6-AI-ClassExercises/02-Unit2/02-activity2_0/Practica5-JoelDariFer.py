#%% Presentación
'''
   Universidad Autónoma de Aguascalientes

         Centro de Ciencias Básicas
 Departamento de Ciencias de la Computación
          Aprendizaje Inteligente
                   6° "A"

                 Práctica 4

   Profesor: Francisco Javier Luna Rosas
  Alumnos:
      Espinoza Sánchez Joel Alejandro
      Gómez Garza Dariana
      González Arenas Fernando Francisco

  Fecha de Entrega: 24 de marzo del 2021

Descripción: Práctica de K-Means
'''

#Configuraciones de Python
import pandas as pd
pd.options.display.max_rows = 10

#Paquetes usados en la presentación
import os
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
import numpy as np

#Función para graficar los gráficos de barras para la interpretación de clústeres
def bar_plot(centros, labels, cluster = None, var = None):
    from math import ceil, floor
    from seaborn import color_palette
    colores = color_palette()
    minimo = floor(centros.min()) if floor(centros.min()) < 0 else 0
    def inside_plot(valores, labels, titulo):
        plt.barh(range(len(valores)), valores, 1/1.5, color = colores)
        plt.xlim(minimo,ceil(centros.max()))
        plt.title(titulo)
    if var is not None:
        centros = np.array([n[[x in var for x in labels]] for n in centros])
        colores = [colores[x % len(colores)] for x, i in enumerate(labels) if i in var]
        labels = labels[[x in var for x in labels]]
    if cluster is None:
        for i in range(centros.shape[0]):
            plt.subplot(1, centros.shape[0], i + 1)
            inside_plot(centros[i].tolist(), labels, ('Cluster' + str(i)))
            plt.yticks(range(len(labels)), labels) if i == 0 else plt.yticks([])
    else:
        pos = 1
        for i in cluster:
            plt.subplot(1, len(cluster), pos)
            inside_plot(centros[i].tolist(), labels, ('Cluster' + str(i)))
            plt.yticks(range(len(labels)), labels) if i == 1 else plt.yticks([])
            pos += 1
            
#Función para graficar los gráficos tipo radar para la interpretación de clústeres
def radar_plot(centros, labels):
    from math import pi
    centros = np.array([((n - min(n)) / (max(n) - min(n)) * 100) if
                        max(n) != min(n) else (n/n * 50) for n in centros.T])
    angulos = [n / float(len(labels)) * 2 * pi for n in range(len(labels))]
    angulos += angulos[:1]
    ax = plt.subplot(111, polar = True)
    ax.set_theta_offset(pi / 2)
    ax.set_theta_direction(-1)
    
    plt.xticks(angulos[:-1], labels)
    ax.set_rlabel_position(0)
    plt.yticks([10, 20, 30, 40, 50, 60, 70, 80, 90, 100],
               ["10%", "20%", "30%", "40%", "50%", "60%", "70%", "80%", "90%", "100%"],
               color = "grey", size = 8)
    plt.ylim(-10, 100)
    for i in range(centros.shape[1]):
        valores = centros[:,i].tolist()
        valores += valores[:1]
        ax.plot(angulos, valores, linewidth = 1, linestyle = 'solid',
                label = 'Cluster' + str(i))
        ax.fill(angulos, valores, alpha = 0.3)
        plt.legend(loc = 'upper right', bbox_to_anchor = (0.1, 0.1))

#Estudiantes
import pandas as pd
os.chdir("C:/Users/Dell/Desktop/KMeans") #Ruta a cambiar donde se ubica tanto el .py como el .csv

datos = pd.read_csv('EjemploEstudiantes.csv', delimiter = ';', decimal = ",", index_col = 0)
print(datos)
print(datos.shape)

#Ejecuta k-medias con 3 clusters
kmedias = KMeans(n_clusters = 3)
kmedias.fit(datos)
print(kmedias.predict(datos))
centros = np.array(kmedias.cluster_centers_)
print(centros)

#%% Gráfica Bar plot para la interpretación

#Interpretación con 3 clústeres - Graficación de barras
plt.figure(1, figsize = (12, 8))
bar_plot(centros, datos.columns)
plt.show()

#Interpretación con 3 clústeres - Graficación radar plot
plt.figure(1, figsize = (10, 10))
radar_plot(centros, datos.columns)
plt.show()