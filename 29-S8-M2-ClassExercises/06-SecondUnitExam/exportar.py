#%% Descripción
'''
Descripción del código
'''

#%% Función inicial de exportación txt
def inicia_exportacion(cMochilas, cObjetos, pesoMax, rangos, cGeneraciones, cElitismo, pCruce, pMutacion, objetos, mochilas, fmochilas):
  archivo = open("reporte.txt", "w")

  archivo.write("-------------------- Reporte del NSGA-II --------------------")
  archivo.write("\n")
  archivo.write("Las configuraciones fueron las siguientes:\n")
  archivo.write("- Cantidad de mochilas: " + str(cMochilas) + "\n")
  archivo.write("- Cantidad de objetos para elegir: " + str(cObjetos) + "\n")
  archivo.write("- Peso máximo de la mochila: " + str(pesoMax) + "\n")
  archivo.write("- Rango de pesos para generar aleatoriamente: Desde " + str(rangos[0]) + " hasta " + str(rangos[1]) + "\n")
  archivo.write("- Rango de utilidades para generar aleatoriamente: Desde " + str(rangos[2]) + " hasta " + str(rangos[3]) + "\n")
  archivo.write("- Cantidad de generaciones: " + str(cGeneraciones) + "\n")
  archivo.write("- Cantidad de individuos que se heredarán por elitismo: " + str(cElitismo) + "\n")
  archivo.write("- Probabilidad de cruzamiento: " + str(pCruce) + "%\n")
  archivo.write("- Probabilidad de mutación: " + str(pMutacion) + "%\n")
  archivo.write("\n")

  archivo.write("Se creó el siguiente conjunto de objetos:\n")
  archivo.write("   Pesos   Utilidades\n")
  for i in range(cObjetos):
    archivo.write(str(i + 1) + ": [" + str(objetos[i][0]) + ",      " + str(objetos[i][1]) + "]\n")
  archivo.write("\n")

  archivo.write("Se creó el siguiente conjunto de posibles soluciones como generación inicial:\n")
  for i in range(cMochilas):
    archivo.write(str(i + 1) + ".  " + str(mochilas[i]) + "\n")
  archivo.write("\n")
  
  archivo.write("La matriz de utilidades de cada solución es la siguiente:\n")
  archivo.write("[Peso, Utilidad, Utilidad acumulada]\n")
  for i in range(cMochilas):
    archivo.write(str(i + 1) + ".  [" + str(fmochilas[0][i]) + ", " + str(fmochilas[1][i]) + ", " + str(fmochilas[2][i]) + "]\n")
  archivo.write("\n")

  archivo.close()
  return

#%% Función de exportación txt para el inicio de cada iteración
def inicio_iteracion(i):
  archivo = open("reporte.txt", "a")

  archivo.write("-------------------- Generación " + str(i + 1) + " --------------------\n")
  
  archivo.close()
  return

#%% Función de exportación txt para datos antes del ordenamiento no dominado
def pre_ordenamiento():  
  archivo = open("reporte.txt", "a")
  
  archivo.write("Se realizó un ordenamiento de las soluciones no dominadas por capas.\n")
  archivo.write("Se presenta el resultado a continuación:\n")
  
  archivo.close()
  return

#%% Función de exportación txt para datos en el ordenamiento no dominado
def ordenamiento(noDominadas, capa):
  archivo = open("reporte.txt", "a")
  
  archivo.write("Capa " + str(capa) + " de soluciones no dominadas\n")
  archivo.write("Soluciones: " + str(noDominadas) + "\n\n")
  
  archivo.close()
  return

#%% Función de exportación txt para datos después del ordenamiento no dominado
def post_ordenamiento(mochilas, cMochilas, fmochilas):
  archivo = open("reporte.txt", "a")
  
  archivo.write("La matriz de soluciones después del ordenamiento no dominado:\n")
  for i in range(cMochilas):
    archivo.write(str(i + 1) + ".  " + str(mochilas[i]) + "\n")
  archivo.write("\n")
  
  archivo.write("La matriz de utilidades después del ordenamiento no dominado:\n")
  archivo.write("[Peso, Utilidad, Utilidad acumulada]\n")
  for i in range(cMochilas):
    archivo.write(str(i + 1) + ".  [" + str(fmochilas[0][i]) + ", " + str(fmochilas[1][i]) + ", " + str(fmochilas[2][i]) + "]\n")
  archivo.write("\n")
  
  archivo.close()
  return

#%% Función de exportación txt para la nueva población y elitismo
def post_elitismo(cElitismo, cMochilas, mochilas):
  archivo = open("reporte.txt", "a")
  
  archivo.write("La nueva generación empezará a formarse.\n")
  archivo.write("Primeramente descenderán por elitismo la cantidad de individuos indicados en la configuración del código:\n\n")
  archivo.write("Cantidad de individuos que pasan por elitismo: " + str(cElitismo) + "\n")
  archivo.write("La matriz de soluciones de la nueva generación:\n")
  for i in range(cMochilas):
    archivo.write(str(i + 1) + ".  " + str(mochilas[i]) + "\n")
  archivo.write("\n")
  archivo.write("Comienza la etapa de selección y cruzamiento.\n")
  
  archivo.close()
  return

#%% Función selección y cruzamiento: parte 1 (selección)
def sel_y_cruz1(i, prob1, prob2, padre1, padre2):
  archivo = open("reporte.txt", "a")
  
  archivo.write("Soluciones: " + str(i) + " y " + str(i + 1) + "\n")
  archivo.write("Probabilidades al azar generadas: " + str(prob1) + " y " + str(prob2) + "\n")
  archivo.write("La probabilidad 1 indicó que el padre 1 es: " + str(padre1) + "\n")
  archivo.write("La probabilidad 2 indicó que el padre 2 es: " + str(padre2) + "\n\n")
  
  archivo.close()
  return

#%% Función selección y cruzamiento: parte 2 (cruzamiento)
def sel_y_cruz2(activado, corte, hijo1, hijo2):
  archivo = open("reporte.txt", "a")
  
  if(activado == 1):
      archivo.write("Cruzamiento activado (punto de corte en " + str(corte) + ")\n")
      archivo.write("Hijo 1: " + str(hijo1) + "\n")
      archivo.write("Hijo 2: " + str(hijo2) + "\n")
  if(activado == 0):
      archivo.write("Cruzamiento no activado\n")
      archivo.write("Hijo 1: " + str(hijo1) + "\n")
      archivo.write("Hijo 2: " + str(hijo2) + "\n\n")
  
  archivo.close()
  return

#%% Función selección y cruzamiento: parte 3 (post-cruzamiento)
def sel_y_cruz3(cMochilas, mochilas):
  archivo = open("reporte.txt", "a")
  
  archivo.write("La matriz de soluciones después de selección y cruzamiento:\n")
  for i in range(cMochilas):
    archivo.write(str(i + 1) + ".  " + str(mochilas[i]) + "\n")
  archivo.write("\n")
  archivo.write("Comienza la etapa de mutación.\n")
  
  archivo.close()
  return

#%% Función mutación: parte 1 (validación de la existencia de la mutación)
def mutacion1(i):
  archivo = open("reporte.txt", "a")
  
  archivo.write("Mutación activada para la solución " + str(i) + "\n")
  
  archivo.close()
  return

#%% Función mutación: parte 2 (nueva solución tras la mutación)
def mutacion2(solucion):
  archivo = open("reporte.txt", "a")
  
  archivo.write("La solución resultante es " + str(solucion) + "\n\n")
  
  archivo.close()
  return

#%% Función mutación: parte 3 (post-mutación)
def mutacion3(cMochilas, mochilas):
  archivo = open("reporte.txt", "a")
  
  archivo.write("La matriz de soluciones después de la mutación:\n")
  for i in range(cMochilas):
    archivo.write(str(i + 1) + ".  " + str(mochilas[i]) + "\n")
  archivo.write("\n")
  archivo.write("Generación terminada.\n\n")
  
  archivo.close()
  return

#%% Función de datos finales
def final(cMochilas, mochilas, fmochilas):
  archivo = open("reporte.txt", "a")
  
  archivo.write("-------------------- Fin del algoritmo --------------------\n")
  archivo.write("La matriz de soluciones final:\n")
  for i in range(cMochilas):
    archivo.write(str(i + 1) + ".  " + str(mochilas[i]) + "\n")
  archivo.write("\n")
  
  archivo.write("La matriz de utilidades final:\n")
  archivo.write("[Peso, Utilidad, Utilidad acumulada]\n")
  for i in range(cMochilas):
    archivo.write(str(i + 1) + ".  [" + str(fmochilas[0][i]) + ", " + str(fmochilas[1][i]) + ", " + str(fmochilas[2][i]) + "]\n")
  archivo.write("\n")