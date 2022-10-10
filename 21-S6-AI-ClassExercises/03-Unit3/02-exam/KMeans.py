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

Descripción: KMeans orientado al VIH
'''

#%% Ejecución de código
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