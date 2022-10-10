#%% Portada
'''
          Universidad Autónoma de Aguascalientes
                 Centro de Ciencas Básicas
        Departamento de Ciencias de la Computación
                    Metaheurísticas II
                          8° "A"

                Primera Evaluación Parcial:
   Algoritmo Genético aplicado al Problema de la Mochila

              Dr. Julio César Ponce Gallegos

              Alumnos:
              Almeida Ortega Andrea Melissa
              Espinoza Sánchez Joel Alejandro

Fecha de Entrega: Aguascalientes, Ags., 9 de marzo del 2022
'''

#%% Descripción del código y variables
'''
Descripción:

Variables:
    qObjects: Cantidad de objetos de entre los que podremos elegir
    qBackpacks: Cantidad de soluciones o individuos dentro de la matriz de poblaciones
    qg: Cantidad de generaciones que realizará el algoritmo genético
    ig: Iterador de las generaciones
    qelitism: Cantidad de individuos que se heredan por elitismo a la siguiente población
    pCruce: Probabilidad de cruzamiento de 0 a 100
    pMutation: Probabilidad de mutación de 0 a 100
    randomRanges: Arreglo de 4 números que representan, en ese orden:
        El menor peso aleatorio posible que podría ser asignado
        El mayor peso aleatorio posible que podría ser asignado
        La menor utilidad aleatoria posible que podría ser asignada
        La mayor utilidad aleatoria posible que podría ser asignada
    maxWeight: Peso máximo que la mochila puede soportar
    objects: Matriz de todos los objetos posibles dentro del problema de dimensión 2 * qObjects
             Cada columna representa un objeto, que tiene dos renglones, uno para el peso y otro
             para la utilidad
    backpacks: Matriz de población, donde se representan las soluciones de dimensión qBackpacks * qObjects
    newBackpacks: La nueva matriz de población, donde se representan las soluciones de dimensión heredadas de backpacks
'''

#%% Importación de librerías
import random

#%% Creación de la estructura objects
def make_objects(qObjects, randomRanges):
    objects = []
    for i in range(qObjects):
        weight = random.randint(randomRanges[0], randomRanges[1])
        utility = random.randint(randomRanges[2], randomRanges[3])
        objects.append([weight, utility])
    return objects

#%% Inicialización en ceros de las matrices de mochilas
def init_backpacks(qObjects, qBackpacks):
    backpack = []
    for i in range(qBackpacks):
        backpack.append([])
        for j in range(qObjects):
            backpack[i].append(0)
    return backpack

#%% Validación de las mochilas (no sobrepasar el peso máximo)
def validate_weights(backpack, objects, maxWeight):
    weight = 0
    for i in range(len(objects)):
        weight = weight + (objects[i][0] * backpack[i])
    if weight <= maxWeight:
        return weight
    return -1

#%% Evaluando un cromosoma para obtener su fitness
def evaluate_fitness(backpack, objects):
    utility = 0
    for i in range(len(objects)):
        utility = utility + (objects[i][1] * backpack[i])
    return utility

#%% Añadiendo la nueva columna del fitness acumulado
def accumulated_evaluation(f, objects):
    for i in range(len(f[1])):
        if i == 0:
            f[2][i] = f[1][i]
        else:
            f[2][i] = f[1][i] + f[2][i - 1]
    return f

#%% Método de Burbuja
def formacion_batalla(backpacks, fbackpacks):
    i = 0
    while i < (len(backpacks) - 1):
        if fbackpacks[i] < fbackpacks[i+1]:
            aux = backpacks[i]
            backpacks[i] = backpacks[i + 1]
            backpacks[i + 1] = aux
            
            aux = fbackpacks[i]
            fbackpacks[i] = fbackpacks[i + 1]
            fbackpacks[i + 1] = aux
            
            i = 0
        else:
            i = i + 1
    return backpacks

#%% Función main

report = open("reporte.txt", "w", encoding = "utf-8")

report.write("---------------------------------------- ALGORITMO GENÉTICO ----------------------------------------\n\n")

report.write("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░░░░░░▄█▀▀▀▀▀▀▄▄░░░░░░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░░░░▄█░░░░░░░░░░▀▄░░░░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░░░█░░░░░░░░██░░░░▌░░░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░░█░▄▄▄▄▒▒░░██░░░░▐░░░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░░██░░░▀█▒▒░░░░░░░░▌░░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░█▀░░░░▒▒█▒▒▒▒░░░░░█░░░░░░░░░░░░░\n")
report.write("░░░░░░░░▄▄▄█░░░░▒▒▒██▀█▄▒▒▒░░░▒█░░░░░░░░░░░░\n")
report.write("▀▀▀▀▀▀▀█░░█░░░▒▒▒▄▀▀▀▀▀▀▌▌▒▒░░▒█░░░░░░░░░░░░\n")
report.write("▄▄▄▄█▀▀█▄█▒▒▒▒▒▄█▒▒▒▒▒▒▒█▌▒▒░░▒▌░░░░░░░░░░░░\n")
report.write("░░░░░░░░░▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▐▒▒░░░▒▌░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░░░░░░░░░░░░░▌▒░░░░▒▌░░░░▄▄▄▄░░░░\n")
report.write("░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░▒█▄█▀▀▒▒▒▒▀▀█▄\n")
report.write("░░░░░░░░░░░░░░░░░░░░░░░▌▒░░░░░░▀▒▒▒░░░░░░░▒▒\n")
report.write("░░░░░░░░░░░░░░░░░░░░░░█▒░░░░░░░░░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░░░░░░░░░░█▒▒░░░░░░░░░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░░░░░░░░░░█▒▒░░░░░░░░░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░░░░░░░░░░▌▒░░░░░░░░░░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░░░░░░░░░░█▒▒▒░░░░░░░░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░░░░░░░░░░░▀█▒▒▒░░░░░░░░░░░░░░░░░\n")
report.write("░░░░░░░░░░░░░░░░░░░░░░░░█▄▒░░░░░░░░░░░░░░░░░\n\n")

report.write("-------------------- Generación inicial --------------------\n\n")

# Se definen los parámetros del algoritmo genético
pCruce = 60
pMutation = 15
qObjects = 10
qBackpacks = 30
randomRanges = [1, 100, 0, 100]
maxWeight = 100
qg = 50
qelitism = 12
    
# Se crean los valores de cada objeto con los que se van a trabajar
objects = make_objects(qObjects, randomRanges)

# Se crea la matriz de poblaciones y de medición de fitness
backpacks = init_backpacks(qObjects, qBackpacks)
newBackpacks = init_backpacks(qObjects, qBackpacks)
fbackpacks = init_backpacks(qBackpacks, 3)
fnewBackpacks = init_backpacks(qBackpacks, 3)
data_graph = []

# Se crea la población inicial
for i in range(qBackpacks):
    while True:
        for j in range(qObjects):
            backpacks[i][j] = random.randint(0, 1)
        if validate_weights(backpacks[i], objects, maxWeight) != -1:
            fbackpacks[0][i] = validate_weights(backpacks[i], objects, maxWeight)
            fbackpacks[1][i] = evaluate_fitness(backpacks[i], objects)
            break
fbackpacks = accumulated_evaluation(fbackpacks, objects)

#data_graph.append(fbackpacks[1])
for i in range(qBackpacks):
        data_graph.append([fbackpacks[1][i]])

report.write("Objetos generados aleatoriamente:\n")
for i in range(qObjects):
    report.write(str(objects[i]) + "\n")
    
report.write("\nMatriz de poblaciones inicial generada aleatoriamente:\n")
for i in range(qBackpacks):
    report.write(str(backpacks[i]) + "\n")
report.write("\n")

# Comienza el proceso iterativo
for ig in range (qg):
    
    # Ordenamiento para hacer elitismo
    backpacks = formacion_batalla(backpacks, fbackpacks[1])
    fbackpacks = accumulated_evaluation(fbackpacks, objects) # Actualizamos el fitness acumulado
    
    # Elitismo
    for i in range(qelitism):
        newBackpacks[i] = backpacks[i]
    
    # Selección y cruzamiento
    i = i + 1
    while i < qBackpacks:
        
        # Elegimos a los cromosomas
        prob1 = random.randint(0, fbackpacks[2][-1])
        prob2 = random.randint(0, fbackpacks[2][-1])
        
        # Se busca dónde cayó el número aleatorio dentro del fitness acumulado
        for j in range(len(fbackpacks[2])):
            if ((prob1) >= (fbackpacks[2][j])):
                parent1 = backpacks[j]
            else:
                parent1 = backpacks[j]
                break
        for j in range(len(fbackpacks[2])):
            if ((prob2) >= (fbackpacks[2][j])):
                parent2 = backpacks[j]
            else:
                parent1 = backpacks[j]
                break
        
        # Recombinación en un punto
        probability = random.randint(0, 100)
        if probability < pCruce:
            while True:
                random_cut = random.randint(0, len(parent1))
                son1 = parent1[:random_cut] + parent2[random_cut:]
                son2 = parent2[:random_cut] + parent1[random_cut:]
                if (validate_weights(son1, objects, maxWeight) != -1) and (validate_weights(son2, objects, maxWeight) != -1):
                    break # Los hijos cumplen el criterio de no sobrepasar el peso límite
        else:
            son1 = parent1
            son2 = parent2
        
        # Se añaden a la población
        newBackpacks[i] = son1
        i = i + 1
        if i < qBackpacks:
            newBackpacks[i] = son2
            i = i + 1
    
    # Cálculo de pesos y fitness (sólo para asegurarse que todo funciona bien)
    for i in range(qBackpacks):
        fnewBackpacks[0][i] = validate_weights(newBackpacks[i], objects, maxWeight)
        fnewBackpacks[1][i] = evaluate_fitness(newBackpacks[i], objects)
    fnewBackpacks = accumulated_evaluation(fnewBackpacks, objects)
    
    # Mutación
    for i in range(qBackpacks):
        pm = random.randint(0, 100)
        if pm <= pMutation:
            while True:
                num = random.randint(0, (qObjects - 1))
                if newBackpacks[i][num] == 0:
                    newBackpacks[i][num] = 1
                else:
                    newBackpacks[i][num] = 0
                if validate_weights(newBackpacks[i], objects, maxWeight) != -1:
                    break
    
    # Restart
    backpacks = newBackpacks
    for i in range(qBackpacks):
        fbackpacks[0][i] = validate_weights(backpacks[i], objects, maxWeight)
        fbackpacks[1][i] = evaluate_fitness(backpacks[i], objects)
    
    backpacks = formacion_batalla(backpacks, fbackpacks[1])
    fbackpacks = accumulated_evaluation(fbackpacks, objects)
    
    #data_graph.append(fbackpacks[1])
    for i in range(qBackpacks):
        data_graph[i].append(fbackpacks[1][i])
    
    report.write("-------------------- Generación " + str(ig + 1) + " --------------------\n\n\n")
    report.write("\nMatriz de poblaciones:\n")
    for i in range(qBackpacks):
        report.write(str(backpacks[i]) + "\n")
    report.write("\n")
    report.write("\nValores de peso y fitness:\n")
    for i in range(qBackpacks):
        report.write(str(fbackpacks[0][i]) + " " + str(fbackpacks[1][i]) + " " + str(fbackpacks[2][i]) + "\n")
    report.write("\n")

# Para presentar más bonitos los resultados, los ordenaremos nuevamente
backpacks = formacion_batalla(backpacks, fbackpacks[1])
fbackpacks = accumulated_evaluation(fbackpacks, objects) # Actualizamos el fitness acumulado
report.close()

#%% Sección de Prueba
import matplotlib.pyplot as plt

'''
plt.violinplot(data_graph)
plt.show()
print(fbackpacks)
print("")
print("")
print("")
print(data_graph)
'''

for i in range(len(data_graph)):
    plt.plot(data_graph[i])
plt.show()