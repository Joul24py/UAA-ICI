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

Descripci�n: KMeans orientado al VIH
'''

#%% Ejecuci�n de c�digo
import pandas as pd
#import seaborn as sns
import sklearn.cluster as cluster

df = pd.read_csv('C:/Users/alexe/Desktop/Examen/TablaAnS.csv')

#sns.pairplot(df[['Masa', 'HPScale', 'Surface', 'Alpha', 'BStrand', 'Turn', 'MolWeight']])

kmeans = cluster.KMeans(n_clusters = 2)

kmeans = kmeans.fit(df[['PI', 'Negativo', 'Positivo', 'C', 'H', 'N', 'O', 'S', 'NumAtomos', 'Alifatico',
                        'Hidrofatico', 'Volumen', 'Masa', 'HPScale', 'Surface', 'Alpha', 'BStrand',
                        'Turn', 'MolWeight']])

print(kmeans.cluster_centers_)

df['Clusters'] = kmeans.labels_

df['Clusters'].value_counts()

print(df.head)

df.to_csv('TablaAS.csv', index = False)