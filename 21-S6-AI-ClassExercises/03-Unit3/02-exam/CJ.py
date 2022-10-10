#%% Presentación
'''
   Universidad Autónoma de Aguascalientes

         Centro de Ciencias Básicas
 Departamento de Ciencias de la Computación
          Aprendizaje Inteligente
                   6° "A"

         Tercera Evaluación Parcial

   Profesor: Francisco Javier Luna Rosas
  Alumnos:
      Espinoza Sánchez Joel Alejandro
      Gómez Garza Dariana
      González Arenas Fernando Francisco

  Fecha de Entrega: 6 de junio del 2021

Descripción: CJ orientado al VIH
'''

#%% Ejecución de código
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import AgglomerativeClustering

df = pd.read_csv('C:/Users/alexe/Desktop/Examen/TablaAnS.csv')

X = df.iloc[:,[3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21]].values

#dendrogram = sch.dendrogram(sch.linkage(X, method = 'ward'))

# Acomodar CJ al dataset

CJ = AgglomerativeClustering(n_clusters = 2, affinity = 'euclidean', linkage = 'ward')
y_CJ = CJ.fit_predict(X)

# Visualizar los clusters
plt.scatter(X[y_CJ == 0,0], X[y_CJ == 0,1], s = 100, c = 'red', label = 'Clúster 1')
plt.scatter(X[y_CJ == 1,0], X[y_CJ == 1,1], s = 100, c = 'green', label = 'Clúster 2')
plt.title('CJ')
plt.legend()
plt.show()