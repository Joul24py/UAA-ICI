#%% Descripción
'''
Descripción del código
'''

#%% Importación de librerías y otros archivos
import random
import funciones
import exportar

#%% Ejecución del NSGA-II

# Definición de variables (puede personalizarse el código cambiando estos valores)
pCruce = 60
pMutacion = 15
cObjetos = 15
cMochilas = 100
rangos = [1, 150, 0, 150]
pesoMax = 500
cGeneraciones = 50
cElitismo = 12

# Se crean los objetos
objetos = funciones.crea_objetos(cObjetos, rangos)

# Se crea la matriz de poblaciones y medición de fitness
mochilas = funciones.inicia_matriz(cObjetos, cMochilas)
mochilasNuevo = funciones.inicia_matriz(cObjetos, cMochilas)
fmochilas = funciones.inicia_matriz(cMochilas, 3)
fmochilasNuevo = funciones.inicia_matriz(cMochilas, 3)

# Se crea la población inicial
for i in range(cMochilas):
  while True:
    for j in range(cObjetos):
      mochilas[i][j] = random.randint(0, 1)
    if funciones.valida_pesos(mochilas[i], objetos, pesoMax) != -1:
      fmochilas[0][i] = funciones.valida_pesos(mochilas[i], objetos, pesoMax)
      fmochilas[1][i] = funciones.evalua_fitness(mochilas[i], objetos)
      break

# Añade la nueva columna de fitness acumulado
fmochilas = funciones.f_acumulado(fmochilas, objetos)

exportar.inicia_exportacion(cMochilas, cObjetos, pesoMax, rangos, cGeneraciones, cElitismo, pCruce, pMutacion, objetos, mochilas, fmochilas)

# Comienza el proceso iterativo
for iGen in range(cGeneraciones):
  
  exportar.inicio_iteracion(iGen)
  exportar.pre_ordenamiento()
  
  # Se ordena fmochilas para posteriormente hacer elitismo
  mochilas = funciones.ordena_no_domin(mochilas, fmochilas, cMochilas) # mochilas = funciones.ordena(mochilas, fmochilas[1])
  cMochilas = len(mochilas)

  # Se reacomoda fmochilas tras el procedimiento anterior
  fmochilas = funciones.inicia_matriz(cMochilas, 3)
  fmochilasNuevo = funciones.inicia_matriz(cMochilas, 3)
  for i in range(cMochilas):
    fmochilas[0][i] = funciones.valida_pesos(mochilas[i], objetos, pesoMax)
    fmochilas[1][i] = funciones.evalua_fitness(mochilas[i], objetos)
  fmochilas = funciones.f_acumulado(fmochilas, objetos)
  
  exportar.post_ordenamiento(mochilas, cMochilas, fmochilas)
  
  # Elitismo
  mochilasNuevo = funciones.elitismo(mochilasNuevo, mochilas, cElitismo)
  
  exportar.post_elitismo(cElitismo, cMochilas, mochilasNuevo)
  
  # Selección y cruzamiento
  mochilasNuevo, fmochilasNuevo = funciones.sel_y_cruz(mochilas, fmochilas, mochilasNuevo, fmochilasNuevo, objetos, cMochilas, pesoMax, pCruce, cElitismo)
  
  exportar.sel_y_cruz3(cMochilas, mochilasNuevo)

  # Mutación
  mochilasNuevo, fmochilasNuevo = funciones.mutacion(mochilasNuevo, fmochilasNuevo, objetos, cMochilas, cObjetos, pesoMax, pMutacion)
  
  exportar.mutacion3(cMochilas, mochilas)

  # Se reinicia el procedimiento para volver a repetir el proceso iterativo
  mochilas = mochilasNuevo
  for i in range(cMochilas):
    fmochilasNuevo[0][i] = funciones.valida_pesos(mochilasNuevo[i], objetos, pesoMax)
    fmochilasNuevo[1][i] = funciones.evalua_fitness(mochilasNuevo[i], objetos)
  fmochilasNuevo = funciones.f_acumulado(fmochilasNuevo, objetos)
  mochilasNuevo = funciones.inicia_matriz(cObjetos, cMochilas)

exportar.final(cMochilas, mochilas, fmochilasNuevo)