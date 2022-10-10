#%% Descripción
'''
Descripción del código
'''

#%% Importación de librerías y otros archivos
import random
import exportar

#%% Función para crear los objetos posibles para ser seleccionados
def crea_objetos(cObjetos, rangos):
  objetos = []
  for i in range(cObjetos):
    peso = random.randint(rangos[0], rangos[1])
    utilidad = random.randint(rangos[2], rangos[3])
    objetos.append([peso, utilidad])
  return objetos

#%% Función para crear una matriz cero
def inicia_matriz(dim1, dim2):
  matriz = []
  for i in range(dim2):
    matriz.append([])
    for j in range(dim1):
      matriz[i].append(0)
  return matriz

#%% Validación de las mochilas (no sobrepasar el peso máximo)
def valida_pesos(mochila, objetos, pesoMax):
  peso = 0
  for i in range(len(objetos)):
    peso = peso + (objetos[i][0] * mochila[i])
  if peso <= pesoMax:
    return peso
  return -1

#%% Evaluando una solución para obtener su fitness
def evalua_fitness(mochila, objetos):
  utilidad = 0
  for i in range(len(objetos)):
    utilidad = utilidad + (objetos[i][1] * mochila[i])
  return utilidad

#%% Calcula el fitness acumulado para futuros operadores del AG
def f_acumulado(matrizFitness, objetos):
  for i in range(len(matrizFitness[0])):
    if i == 0: # Caso: Renglón 1, donde el fitness acumulado es el mismo fitness de este renglón
      matrizFitness[2][i] = matrizFitness[1][i]
    else: # Caso: Otro renglón donde se suma el fitness de ese renglón más el acumulado en el renglón anterior
      matrizFitness[2][i] = matrizFitness[1][i] + matrizFitness[2][i - 1] 
  return matrizFitness

#%% Ordena las matrices de fitness (método de la burbuja)
def ordena(mochilas, fmochilas):
    i = 0
    while i < (len(mochilas) - 1):
        if fmochilas[i] < fmochilas[i + 1]:
            aux = mochilas[i]
            mochilas[i] = mochilas[i + 1]
            mochilas[i + 1] = aux
            
            aux = fmochilas[i]
            fmochilas[i] = fmochilas[i + 1]
            fmochilas[i + 1] = aux
            
            i = 0
        else:
            i = i + 1
    return mochilas

#%% Obtiene las soluciones no dominadas en el ordenamiento multiobjetivo
def calc_no_dominadas(fmochilas, cMochilas):
  noDominadas = []
  if (len(fmochilas) == 0) or cMochilas == 0:
    return noDominadas
  else:
    for i in range(cMochilas):
      flag = 0
      for j in range (cMochilas):
        if i == j:
          continue
        if (fmochilas[0][i] < fmochilas[0][j]) and (fmochilas[1][i] < fmochilas[1][j]):
          flag = 1
          break
      if flag == 0:
        noDominadas.append(i)
    return noDominadas

#%% Ordenamiento mutiobjetivo
def ordena_no_domin(mochilas, fmochilas, cMochilas):
  '''
  El Frente de Pareto de este problema es el máximo
  de utilidad (tener los mejores objetos) y el máximo
  de peso (aprovechar de la mejor manera la mochila)
  '''

  mochilasOrdenado = []
  capa = 0
  
  while True:
    noDominadas = calc_no_dominadas(fmochilas, cMochilas)
    capa = capa + 1
    exportar.ordenamiento(noDominadas, capa)
    for i in reversed(noDominadas):
      mochilasOrdenado.append(mochilas[i])
      del mochilas[i]
      del fmochilas[0][i]
      del fmochilas[1][i]
      del fmochilas[2][i]
    cMochilas = cMochilas - len(noDominadas)
    if len(mochilas) == 0:
      break
  
  return mochilasOrdenado

#%% Elitismo
def elitismo(mochilasNuevo, mochilas, cElitismo):
  for i in range(cElitismo):
    mochilasNuevo[i] = mochilas[i]
  return mochilasNuevo

#%% Selección y cruzamiento
def sel_y_cruz(mochilas, fmochilas, mochilasNuevo, fmochilasNuevo, objetos, cMochilas, pesoMax, pCruce, i):
  i = i + 1
  while i < cMochilas:
    # Elegimos a los cromosomas
    prob1 = random.randint(0, fmochilas[2][-1])
    prob2 = random.randint(0, fmochilas[2][-1])
    
    # Se busca dónde cayó el número aleatorio dentro del fitness acumulado
    for j in range(len(fmochilas[2])):
      if ((prob1) >= (fmochilas[2][j])):
        padre1 = mochilas[j]
      else:
        padre1 = mochilas[j]
        break
    for j in range(len(fmochilas[2])):
      if ((prob2) >= (fmochilas[2][j])):
        padre2 = mochilas[j]
      else:
        padre2 = mochilas[j] # !!! Aquí puse padre1 ???
        break
    
    exportar.sel_y_cruz1(i, prob1, prob2, padre1, padre2)
    
    # Recombinación en un punto
    probabilidad = random.randint(0, 100)
    if probabilidad < pCruce:
      while True:
        corte = random.randint(0, len(padre1))
        hijo1 = padre1[:corte] + padre2[corte:]
        hijo2 = padre2[:corte] + padre1[corte:]
        if (valida_pesos(hijo1, objetos, pesoMax) != -1) and (valida_pesos(hijo2, objetos, pesoMax) != -1):
          exportar.sel_y_cruz2(1, corte, hijo1, hijo2)
          break # Los hijos cumplen el criterio de no sobrepasar el peso límite
    else:
      hijo1 = padre1
      hijo2 = padre2
      exportar.sel_y_cruz2(0, 0, hijo1, hijo2)
    
    # Se añaden a la población
    mochilasNuevo[i] = hijo1
    i = i + 1
    if i < cMochilas:
      mochilasNuevo[i] = hijo2
      i = i + 1

  # Cálculo de pesos y fitness (sólo para asegurarse que todo funciona bien)
  for i in range(cMochilas):
    fmochilasNuevo[0][i] = valida_pesos(mochilasNuevo[i], objetos, pesoMax)
    fmochilasNuevo[1][i] = evalua_fitness(mochilasNuevo[i], objetos)
  fmochilasNuevo = f_acumulado(fmochilasNuevo, objetos)
  
  return mochilasNuevo, fmochilasNuevo

#%% Mutación
def mutacion(mochilasNuevo, fmochilasNuevo, objetos, cMochilas, cObjetos, pesoMax, pMutacion):
  for i in range(cMochilas):
    pm = random.randint(0, 100)
    if pm <= pMutacion:
      exportar.mutacion1(i)
      while True:
        num = random.randint(0, (cObjetos - 1))
        if mochilasNuevo[i][num] == 0:
          mochilasNuevo[i][num] = 1
        else:
          mochilasNuevo[i][num] = 0
        if valida_pesos(mochilasNuevo[i], objetos, pesoMax) != -1:
          exportar.mutacion2(mochilasNuevo[i])
          break
  
  return mochilasNuevo, fmochilasNuevo