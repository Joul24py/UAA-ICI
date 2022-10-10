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

Descripción: Random Forest orientado al VIH
'''

#%% Ejecución de código
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import precision_score
from sklearn.metrics import confusion_matrix
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier

df = pd.read_csv('C:/Users/alexe/Desktop/Examen/TablaAS.csv')

X = df.drop(['Tipo', 'Virus', 'Aminoacido', 'Clusters'], axis = 1)
Y = df['Clusters']

xtrain, xtest, ytrain, ytest = train_test_split(X, Y, test_size = 0.25)

sc = StandardScaler()
xtrain = sc.fit_transform(xtrain)
xtest = sc.fit_transform(xtest)

classifier = RandomForestClassifier(n_estimators = 4)
classifier.fit(xtrain, ytrain)

ypred = classifier.predict(xtest)

matriz = confusion_matrix(ytest, ypred)
print('Matriz de Confusión')
print(matriz)

precision = precision_score(ytest, ypred)
print('Precisión del modelo')
print(precision)