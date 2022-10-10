#%% Presentación
'''
   Universidad Autónoma de Aguascalientes

         Centro de Ciencias Básicas
 Departamento de Ciencias de la Computación
          Aprendizaje Inteligente
                   6° "A"

                 Práctica 3

   Profesor: Francisco Javier Luna Rosas
  Alumnos:
      Espinoza Sánchez Joel Alejandro
      Gómez Garza Dariana
      González Arenas Fernando Francisco

  Fecha de Entrega: 15 de marzo del 2021

Descripción: Red neuroonal con Backtracking
'''

#%% Librerías
import pandas
import numpy
import random
import sklearn

#%% Extraer los datos del CSV
datos = pandas.read_csv('iris.csv', sep = ';', decimal = '.')
print("Datos:")
print(datos)

#%% Se segmentan los datos en dos tablas
muestra = random.sample(range(150),50)
ttesting = datos.iloc[muestra]
print("Tabla de pruebas:")
print(ttesting)
taprendizaje = datos.drop(muestra)
print("Tabla de aprendizaje:")
print(taprendizaje)

#%% Se asignan las entradas y salidas
x = datos.iloc[:,:4]
print("Tabla de datos de x:")
print(x)
y = datos.iloc[:,4:5]
print("Tabla del rango de y:")
print(y)

#%% Se separa la población de entrenamiento y de aprendizaje
x_train,x_test,y_train,y_test = sklearn.model_selection.train_test_split(x, y, train_size = 0.7, random_state = 0)
instancia_Knn = sklearn.neighbors.KNeighborsClassifier(n_neighbors = 7)
instancia_Knn.fit(x_train,y_train.iloc[:,0].values)
sklearn.neighbors.KNeighborsClassifier(n_neighbors = 7)

#%% Comienza la etapa de predicción
regression = instancia_Knn.predict(x_test)

#%% Se calcula la matriz de confusión
confussion = sklearn.metrics.confusion_matrix(y_test,regression)

def indexing(confussion,flores = None):
    precision = numpy.sum(confussion.diagonal())/numpy.sum(confussion)
    #error = 1 - precision
    precisionI = pandas.DataFrame(confussion.diagonal()/numpy.sum(confussion,axis=1)).T
    if flores != None:
        precisionI.colums = flores
        return [precision, precisionI, 1 - precision, confussion]

index = indexing(confussion,list(numpy.unique(y)))

print("Precisión Global")
print(index[0])
print("Precisión Individual de cada aspecto")
print(index[1])
print("Error Global")
print(index[2])
print("Matriz de Confusión")
print(index[3])