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

Descripción: PCA orientado al VIH
'''

#%% Ejecución de código
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA

df = pd.read_csv('C:/Users/alexe/Desktop/Examen/TablaAS.csv')

features = ['PI', 'Negativo', 'Positivo', 'C', 'H', 'N', 'O', 'S', 'NumAtomos', 'Alifatico',
            'Hidrofatico', 'Volumen', 'Masa', 'HPScale', 'Surface', 'Alpha', 'BStrand',
            'Turn', 'MolWeight']

# Separando features
x = df.loc[:,features].values

# Separando el objetivo
y = df.loc[:,'Clusters'].values

# Estandarizando features
x = StandardScaler().fit_transform(x)

# Proyección PCA
pca = PCA(n_components = 2)
principalComponents = pca.fit_transform(x)
principalDf = pd.DataFrame(data = principalComponents, columns = ['PC1', 'PC2'])
finalDf = pd.concat([principalDf, df[['Clusters']]], axis = 1)

# Visualizar Proyección 2D
fig = plt.figure(figsize = (8,8))
ax = fig.add_subplot(1,1,1)
ax.set_xlabel('PC1')
ax.set_ylabel('PC2')
ax.set_title('PCA')

targets = [0, 1]
colors = ['r', 'g']

for target, color in zip(targets, colors):
    index = finalDf['Clusters'] == target
    ax.scatter(finalDf.loc[index, 'PC1'], finalDf.loc[index, 'PC2'], c = color, s = 50)
ax.grid