#%% Presentación
'''
            Universidad Autónoma de Aguascalientes
                  Centro de Ciencias Básicas
          Departamento de Ciencias de la Computación
                       Metaheurísticas 2
                             8° A

                    Algoritmo Genético EDA

                Dr. Julio César Ponce Gallegos

                           Alumnos:
                 Almeida Ortega Andrea Melissa
                Espinoza Sánchez Joel Alejandro

Fecha de Entrega: Aguascalientes, Ags., 21 de febrero del 2022.

Descripción: Algoritmo Genético para resolver el OneMax con las siguientes especificaciones:
- Tamaño de población: 30
- Longitud de la cadena: 10
- Selección elitista: 50%
- Iteraciones: 20
'''

#%% Librerías
import numpy as np
import random

#%% Función para iniciar la población
def IniciarPoblacion(tamPob = 30, Long = 10):
  lista = []
  for i in range(tamPob):
    lista.append([])
    for j in range(Long):
      lista[i].append(random.random())
  return lista

#%% Comienza el algoritmo
contador = 0
M = np.matrix(IniciarPoblacion())
tamPob,Long = M.shape
for i in range(tamPob):
  for j in range(Long):
    if (M[i,j]<=0.5):
      M[i,j]=int(0)
    else:
      M[i,j]=int(1)
print("GENERACIÓN 0")
print("Población inicial:")
print(M)

while(contador<22):
  #%% Se calcula la nueva columna con la cantidad de 1's por renglón
  fx = []
  for i in range(tamPob):
    fx.append([])
    suma = 0
    for j in range(Long):
      if M[i,j] == 1:
        suma = suma + 1
    fx[i].append(suma)
  M = np.append(M, fx, axis = 1)
  print("")
  print("Cálculo de la función objetivo por cada individuo")
  print(M)
  
  #%% Ordenamos por mejor renglón
  i = 0
  while i < tamPob - 1:
    if M[i, 10] < M[i + 1, 10]:
      aux = M[i]
      M[i] = M[i + 1]
      M[i + 1] = aux
      i = 0
    else:
      i = i + 1
  print("")
  print("La matriz después de ordenarse de mejor a peor:")
  print(M)
  
  #%% Seleccionamos los mejores 15
  newM = np.matrix(M[0:15,:])
  print("")
  print("Aplicación de elitismo. Sobrevivientes:")
  print(newM)
  
  #%% Se calculan los 0's por columna
  ceros = []
  porc0 = []
  for j in range(Long):
    suma = 0
    for i in range(15):
      if newM[i,j] == 0:
        suma = suma + 1
    ceros.append(suma)
    porc0.append(suma/15)
  print("")
  print("Cantidad de ceros por columna:")
  print(ceros)
  print("Porcentaje de ocurrencia de ceros:")
  print(porc0)
  
  #%% Se genera una nueva población con los valores de porc0
  contador = contador + 1
  newnewM = np.matrix(IniciarPoblacion())
  tamPob,Long = newnewM.shape
  for i in range(tamPob):
    for j in range(Long):
      if (newnewM[i,j]<=porc0[j]):
        newnewM[i,j]=int(0)
      else:
        newnewM[i,j]=int(1)
  if contador < 21:
    print("")
    print("GENERACIÓN " + str(contador))
    print("Nueva población:")
    print(newnewM)
    M = newnewM