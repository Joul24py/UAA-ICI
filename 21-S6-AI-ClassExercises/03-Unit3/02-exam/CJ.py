#%% Presentaci�n
'''
   Universidad Aut�noma de Aguascalientes

         Centro de Ciencias B�sicas
 Departamento de Ciencias de la Computaci�n
          Aprendizaje Inteligente
                   6� "A"

         Tercera Evaluaci�n Parcial

   Profesor: Francisco Javier Luna Rosas
  Alumnos:
      Espinoza S�nchez Joel Alejandro
      G�mez Garza Dariana
      Gonz�lez Arenas Fernando Francisco

  Fecha de Entrega: 6 de junio del 2021

Descripci�n: CJ orientado al VIH
'''

#%% Ejecuci�n de c�digo
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
plt.scatter(X[y_CJ == 0,0], X[y_CJ == 0,1], s = 100, c = 'red', label = 'Cl�ster 1')
plt.scatter(X[y_CJ == 1,0], X[y_CJ == 1,1], s = 100, c = 'green', label = 'Cl�ster 2')
plt.title('CJ')
plt.legend()
plt.show()