#%% Presentación
'''
   Universidad Autónoma de Aguascalientes

         Centro de Ciencias Básicas
 Departamento de Ciencias de la Computación
              Metaheurísticas I
                   7° "A"

                 Actividad 5.01

   Profesor: Francisco Javier Luna Rosas

  Alumnos:
      Almeida Ortega Andrea Melissa
      Espinoza Sánchez Joel Alejandro
      Flores Fernández Óscar Alonso
      Gómez Garza Dariana
      González Arenas Fernando Francisco
      Orocio García Hiram Efraín

  Fecha de Entrega: 19 de noviembre del 2021

Descripción: Machine Learning (Random Forest como Aprendizaje Supervisado) para análisis de sentimientos
'''

#%% Importamos las librerías
import pandas as pd
import os
import numpy as np
import cv2
import matplotlib.pyplot as plt
import pickle
import random
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC

from sklearn.preprocessing import StandardScaler
from sklearn.naive_bayes import GaussianNB
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score

#%% Cargamos los datos de análisis de sentimientos
datosRacismo = pd.read_csv("Sentimiento.csv")

#%% Declaramos las categorías
categories = ['Negativo', 'Neutro', 'Positivo']

#%% Declaramos la variable que mantendrá los datos a lo largo del procedimiento Random Forest
data = []

#%% Se revisa por categoría cada imagen del directorio
for category in categories:
    label = categories.index(category)
    
    for i in datosRacismo.iloc[:,3]:
        numberData = i.replace(" \'compound\': ","")
        numberData = numberData.replace("} ","")
        data.append([float(numberData),round(float(numberData)) + 1])

#%% Se crea el documento data1 en el mismo directorio de archivos con el análisis Random Forest
pick_in = open('data1.pickle', 'wb')
pickle.dump(data, pick_in)
pick_in.close()

#%% Se carga la información del archivo data1 en la variable data1
pick_in = open('data1.pickle', 'rb')
data1 = pickle.load(pick_in)
pick_in.close()

#%% Se elige un individuo al azar
random.shuffle(data1)
features1 = []
label1 = []

#%% Se llena el arreglo de características de cada individuo
for feature, labelint in data1:
    features1.append([feature,0])
    label1.append(labelint)

#%% Se realiza la clasificación a partir del entrenamiento usando 75% de la población
xtrain, xtest, ytrain, ytest = train_test_split(features1, label1, test_size = 0.20, random_state = 0)

sc = StandardScaler()

xtrain = sc.fit_transform(xtrain)
xtest = sc.fit_transform(xtest)

classifier = RandomForestClassifier(n_estimators = 12, random_state = 0)
classifier.fit(xtrain, ytrain)

ypred = classifier.predict(xtest)

print("Matriz de confusión:")
print(confusion_matrix(ytest, ypred))

print("Reporte de clasificación:")
print(classification_report(ytest, ypred))

print("Precisión:")
print(accuracy_score(ytest, ypred))