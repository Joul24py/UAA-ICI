#%% PresentaciÃ³n
'''
   Universidad AutÃ³noma de Aguascalientes

         Centro de Ciencias BÃ¡sicas
 Departamento de Ciencias de la ComputaciÃ³n
          Aprendizaje Inteligente
                   6Â° "A"

                 PrÃ¡ctica 5

   Profesor: Francisco Javier Luna Rosas
  Alumnos:
      Espinoza SÃ¡nchez Joel Alejandro
      GÃ³mez Garza Dariana
      GonzÃ¡lez Arenas Fernando Francisco

  Fecha de Entrega: 7 de abril del 2021

DescripciÃ³n: SVM aplicado
'''

#%% Importamos las librerÃ­as
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
from sklearn.metrics import confusion_matrix

#%% Declaramos el directorio donde estÃ¡n las imÃ¡genes de prueba
dir = 'C:\\Users\\alexe\\Desktop\\Proyecto2\\images'

#%% Declaramos las categorÃ­as
categories = ['adulto', 'anciano', 'bebe', 'joven']

#%% Declaramos la variable que mantendrÃ¡ los datos a lo largo del procedimiento SVM
data = []

#%% Se revisa por categorÃ­a cada imagen del directorio
for category in categories:
    path = os.path.join(dir, category)
    label = categories.index(category)
    
    for img in os.listdir(path):
        imgpath = os.path.join(path,img)
        face_img = cv2.imread(imgpath,0)
        try:
            face_img = cv2.resize(face_img, (100,100))
            image = np.array(face_img).flatten()
        
            data.append([image,label])
        except Exception as e: #ExepciÃ³n de error en resoluciÃ³n de imagen
            pass

#%% Se crea el documento data1 en el mismo directorio de archivos con el anÃ¡lisis SVM
pick_in = open('data1.pickle', 'wb')
pickle.dump(data, pick_in)
pick_in.close()

#%% Se carga la informaciÃ³n del archivo data1 en la variable data1
pick_in = open('data1.pickle', 'rb')
data1 = pickle.load(pick_in)
pick_in.close()

#%% Se elige un individuo al azar
random.shuffle(data1)
features1 = []
label1 = []

#%% Se llena el arreglo de caracterÃ­sticas de cada individuo
for feature, labelint in data1:
    features1.append(feature)
    label1.append(labelint)

#%% Se realiza la clasificaciÃ³n a partir del entrenamiento usando 75% de la población
xtrain, xtest, ytrain, ytest = train_test_split(features1, label1, test_size = 0.20, random_state = 0)

sc = StandardScaler()

xtrain = sc.fit_transform(xtrain)
xtest = sc.transform(xtest)

classifier = GaussianNB()
classifier.fit(xtrain, ytrain)

ypred = classifier.predict(xtest)
cm = confusion_matrix(ytest, ypred)
print(cm)