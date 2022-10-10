#%% Presentaci�n
'''
   Universidad Aut�noma de Aguascalientes

         Centro de Ciencias B�sicas
 Departamento de Ciencias de la Computaci�n
              Metaheur�sticas I
                   7� "A"

                 Actividad 5.01

   Profesor: Francisco Javier Luna Rosas

  Alumnos:
      Almeida Ortega Andrea Melissa
      Espinoza S�nchez Joel Alejandro
      Flores Fern�ndez �scar Alonso
      G�mez Garza Dariana
      Gonz�lez Arenas Fernando Francisco
      Orocio Garc�a Hiram Efra�n

  Fecha de Entrega: 19 de noviembre del 2021

Descripci�n: Machine Learning (Random Forest como Aprendizaje Supervisado) para an�lisis de sentimientos
'''

#%% Importamos las librer�as
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

#%% Cargamos los datos de an�lisis de sentimientos
datosRacismo = pd.read_csv("Sentimiento.csv")

#%% Declaramos las categor�as
categories = ['Negativo', 'Neutro', 'Positivo']

#%% Declaramos la variable que mantendr� los datos a lo largo del procedimiento Random Forest
data = []

#%% Se revisa por categor�a cada imagen del directorio
for category in categories:
    label = categories.index(category)
    
    for i in datosRacismo.iloc[:,3]:
        numberData = i.replace(" \'compound\': ","")
        numberData = numberData.replace("} ","")
        data.append([float(numberData),round(float(numberData)) + 1])

#%% Se crea el documento data1 en el mismo directorio de archivos con el an�lisis Random Forest
pick_in = open('data1.pickle', 'wb')
pickle.dump(data, pick_in)
pick_in.close()

#%% Se carga la informaci�n del archivo data1 en la variable data1
pick_in = open('data1.pickle', 'rb')
data1 = pickle.load(pick_in)
pick_in.close()

#%% Se elige un individuo al azar
random.shuffle(data1)
features1 = []
label1 = []

#%% Se llena el arreglo de caracter�sticas de cada individuo
for feature, labelint in data1:
    features1.append([feature,0])
    label1.append(labelint)

#%% Se realiza la clasificaci�n a partir del entrenamiento usando 75% de la poblaci�n
xtrain, xtest, ytrain, ytest = train_test_split(features1, label1, test_size = 0.20, random_state = 0)

sc = StandardScaler()

xtrain = sc.fit_transform(xtrain)
xtest = sc.fit_transform(xtest)

classifier = RandomForestClassifier(n_estimators = 12, random_state = 0)
classifier.fit(xtrain, ytrain)

ypred = classifier.predict(xtest)

print("Matriz de confusi�n:")
print(confusion_matrix(ytest, ypred))

print("Reporte de clasificaci�n:")
print(classification_report(ytest, ypred))

print("Precisi�n:")
print(accuracy_score(ytest, ypred))