#%% Presentación
'''
   Universidad Autónoma de Aguascalientes

         Centro de Ciencias Básicas
 Departamento de Ciencias de la Computación
          Aprendizaje Inteligente
                   6° "A"

                 Práctica 5

   Profesor: Francisco Javier Luna Rosas
  Alumnos:
      Espinoza Sánchez Joel Alejandro
      Gómez Garza Dariana
      González Arenas Fernando Francisco

  Fecha de Entrega: 7 de abril del 2021

Descripción: SVM aplicado
'''

#%% Importamos las librerías
import os
import numpy as np
import cv2
import matplotlib.pyplot as plt
import pickle
import random
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC

#%% Declaramos el directorio donde están las imágenes de prueba
dir = 'C:\\Users\\alexe\\Desktop\\Proyecto2\\images'

#%% Declaramos las categorías
categories = ['adulto', 'anciano', 'bebe', 'joven']

#%% Declaramos la variable que mantendrá los datos a lo largo del procedimiento SVM
data = []

#%% Se revisa por categoría cada imagen del directorio
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
        except Exception as e: #Exepción de error en resolución de imagen
            pass

#%% Se crea el documento data1 en el mismo directorio de archivos con el análisis SVM
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
    features1.append(feature)
    label1.append(labelint)

#%% Se realiza la clasificación a partir del entrenamiento usando 75% de la poblaci�n
xtrain, xtest, ytrain, ytest = train_test_split(features1, label1, test_size = 0.20)

#%% Se aplica el algoritmo SVC de la librería sklearn con los datos previamente entrenados
model = SVC(C = 1, kernel = 'poly', gamma = 'auto')
model.fit(xtrain, ytrain)

#%% Se crea el documento model con el cual se pasa a la predicción
pick = open('model.sav', 'wb')
pickle.dump(model, pick)
pick.close()

#%% Una vez creado, se carga el documento model a la variable model
pick = open('model.sav', 'rb')
model = pickle.load(pick)
pick.close()

#%% Se calcula la predicción y la precisión del model
prediction = model.predict(xtest)
accuracy = model.score(xtest, ytest)

#%% Definición de las categorías (apartado repetido)
categories = ['adulto', 'anciano', 'bebe', 'joven']

#%% Impresión de los resultados en texto
print(accuracy)
print(categories[prediction[0]])

#%% Impresión de la imagen usada y los píxeles tomados a consideración
my_boy = xtest[0].reshape(100,100)
plt.imshow(my_boy, cmap = 'gray')
plt.show()