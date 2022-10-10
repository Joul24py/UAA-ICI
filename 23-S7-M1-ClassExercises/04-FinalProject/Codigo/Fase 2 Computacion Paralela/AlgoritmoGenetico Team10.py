#%% Portada
'''
                   Centro de Ciencias Básicas
           Departamento de Ciencias de la Computación
                       Metaheurísticas I
                            7° “A”

          Segunda Evaluación Parcial (Algoritmo Genético)

             Profesor: Francisco Javier Luna Rosas

            Alumnos: 
                     Almeida Ortega Andrea Melissa
                     Espinoza Sánchez Joel Alejandro
                     Flores Fernández Óscar Alonso
                     Gómez Garza Dariana
                     González Arenas Fernando Francisco
                     Orocio García Hiram Efraín

Fecha de Entrega: Aguascalientes, Ags., 31 de octubre de 2021
'''

#%% Descripción

#%% Importación de librerías
import numpy as np
import random

#%% Funciones de apoyo
# Función FirstSample
def FirstSample(qe,qi,total_tweets):
    sample = []
    for i in range(qi):
        sample.append([])
        remaining_tweets = total_tweets
        for j in range(qe):
            sample[i].append(random.randint(0, remaining_tweets))
            remaining_tweets = remaining_tweets - sample[i][j]
        if remaining_tweets != 0:
            assignment = random.randint(1,6)
            sample[i][assignment - 1] = sample[i][assignment - 1] + remaining_tweets
    return sample

# Función PrintSample
def PrintSample(qi,sample):
    for i in range(qi):
        try:
            print(str(sample[0][i]) + " = " + str(sum(sample[0][i])) + " \t\t " + str(sample[1][i]) + " \t " + str(sample[2][i]))
        except:
            try:
                print(str(sample[0][i]) + " = " + str(sum(sample[0][i])) + " \t\t " + str(sample[1][i]) + " \t " + str(sample[2]))
            except:
                print(str(sample[0][i]) + " = " + str(sum(sample[0][i])) + " \t\t " + str(sample[1]) + " \t " + str(sample[2]))
    return

# Función evaluate
def evaluate(qi,sample,power_process):
    evaluation = []
    for i in range(qi):
        function = -(np.abs(sample[0][i][0] - 1752929) + np.abs(sample[0][i][1] - 1752929) + np.abs(sample[0][i][2] - 2188458) + np.abs(sample[0][i][3] - 179704) + np.abs(sample[0][i][4] - 1013759) + np.abs(sample[0][i][5] - 709446)) + 34710105
        
        print("Función objetivo " + str(i))
        print(function)
        
        evaluation.append(function)
    return evaluation

# Función evaluateA
def evaluateA(qi,sample):
    evaluation = []
    evaluation.append(sample[1][0])
    i = 1
    while i < qi:
        evaluation.append(evaluation[i - 1] + sample[1][i])
        i = i + 1
    return evaluation

# Función Sorting
def Sorting(sample, qi):
    i = 0
    while i < qi - 1:
        if sample[1][i] < sample[1][i + 1]:
            for j in range(3):
                aux = sample[j][i]
                sample[j][i] = sample[j][i + 1]
                sample[j][i + 1] = aux
            i = 0
            continue
        i = i + 1
    return sample

# Función nullNewSample
def newSampleCreator(qi):
    nullCreator = []
    for i in range(qi):
        nullCreator.append(0)
    nullNewSample = []
    nullNewSample.append(nullCreator[:])
    nullNewSample.append(nullCreator[:])
    nullNewSample.append(nullCreator[:])
    return nullNewSample

#%% Calibrar variables
total_tweets = 6942021
qe = 6 # Inamovible
qi = 60 # Movible
pc = 75 # Movible
pm = 40 # Movible
qelitism = 5 # Movible
qg = 10
sample = [[], [], []]
power_process = [9.311, 14.8685, 7.458, 90.8248, 16.1, 23.006] # Orden alfabético: Melissa, Joel, Óscar, Dariana, Fernando, Hiram
ig = 0

#%% AG: Creación de la población aleatoria
sample[0] = FirstSample(qe,qi,total_tweets)
PrintSample(qi, sample)

#%% AG: Procedimiento de cada generación
while ig < qg:
    print("Población " + str(ig))
    print("")
    
    # Evaluamos a todas las muestras
    sample[1] = evaluate(qi,sample,power_process)
    
    print("Población " + str(ig) + " al ser evaluada")
    PrintSample(qi,sample)
    print("")
    
    # Evaluamos la suma acumulada
    sample[2] = evaluateA(qi,sample)
    
    print("Población " + str(ig) + " al ser evaluada con acumulación")
    PrintSample(qi,sample)
    print("")
    
    # Ordenamos por valor de f(x) es decir, por sample[1]
    sample = Sorting(sample, qi)
    
    print("Población " + str(ig) + " al ser ordenada")
    PrintSample(qi,sample)
    print("")
    
    # Reevaluamos la suma acumulada
    sample[2] = evaluateA(qi,sample)
    
    print("Población " + str(ig) + " al ser reevaluada")
    PrintSample(qi,sample)
    print("")
    
    # Creamos una nueva muestra vacía
    newSample = newSampleCreator(qi)
    
    print("Nueva muestra " + str(ig + 1) + " vacía")
    print(newSample)
    print("")
    
    print("Se aplicará elitismo")
    x = input()
    
    # Se aplica elitismo
    ii = 0
    while ii < qelitism:
        newSample[0][ii] = sample[0][ii]
        #newSample[1][ii] = sample[1][ii]
        #newSample[2][ii] = sample[2][ii]
        ii = ii + 1
    
    print("Nueva muestra " + str(ig + 1) + " después de elitismo")
    for i in range(qi):
        try:
            print(str(newSample[0][i]) + " = " + str(sum(newSample[0][i])))
        except:
            pass
    print("")
    print("Se aplicará cruzamiento")
    x = input()
    
    # Se aplicará cruzamiento
    while ii < qi:
        # Seleccionamos por ruleta
        # Padre 1
        random_pick = random.uniform(0, sample[2][qi - 1])
        
        for ic in range(qi):
            if random_pick < sample[2][ic]:
                c1 = sample[0][ic]
                print("Se elige como padre 1 el individuo " + str(ic) + "(random_pick = " + str(random_pick) + ")")
                break
        
        # Padre 2
        random_pick = random.uniform(0, sample[2][qi - 1])
        
        for ic in range(qi):
            if random_pick < sample[2][ic]:
                c2 = sample[0][ic]
                print("Se elige como padre 2 el individuo " + str(ic) + "(random_pick = " + str(random_pick) + ")")
                break
        
        # Se evalúa si se aplicará cruzamiento
        random_num = random.randint(0,99)
        if random_num < pc:
            print("Los cromosomas " + str(ii) + " y " + str(ii + 1) + " han activado cruzamiento (Probabilidad: " + str(random_num) + " < " + str(pc) + ")")
            print("")
            
            # Mezclamos los 6 números de una tupla
            processors = [0, 1, 2, 3, 4, 5]
            random.shuffle(processors) # Se mezclarán y se harán sumas balanceadas de par en par
            
            print("Tupla mezclada: " + str(processors))
            print("")
            
            print("Valores antes del cruzamiento: ")
            print(c1)
            print(c2)
            print("")
            
            for i in [0, 2, 4]:
                # Sumas equilibradas
                min_value = min(c1[processors[i]], c1[processors[i + 1]], c2[processors[i]], c2[processors[i + 1]])
                operation = random.randint(0, 1) # Elige la operación con la que empezará la suma equilibrada
                addition = random.randint(0, min_value)
                
                print("Tuplas " + str(processors[i] + 1) + " y " + str(processors[i + 1] + 1))
                print("min_value = " + str(min_value))
                print("addition = " + str(addition))
                print("")
                
                if operation == 0:
                    c2[processors[i + 1]] = c2[processors[i + 1]] - addition
                    c1[processors[i + 1]] = c1[processors[i + 1]] + addition
                    c1[processors[i]] = c1[processors[i]] - addition
                    c2[processors[i]] = c2[processors[i]] + addition
                else:
                    c2[processors[i + 1]] = c2[processors[i + 1]] + addition
                    c1[processors[i + 1]] = c1[processors[i + 1]] - addition
                    c1[processors[i]] = c1[processors[i]] + addition
                    c2[processors[i]] = c2[processors[i]] - addition
                
            print("Valores después del cruzamiento: ")
            print(c1)
            print(c2)
            print("")
            
        else:
            print("Los cromosomas " + str(ii) + " y " + str(ii + 1) + " no han activado cruzamiento (Probabilidad: !" + str(random_num) + " < " + str(pc) + "!)")
            
        newSample[0][ii] = c1
        try:
            newSample[0][ii + 1] = c2
        except:
            pass
        
        ii = ii + 2
        
    print("Nueva muestra " + str(ig + 1) + " después del cruzamiento")
    for i in range(qi):
        try:
            print(str(newSample[0][i]) + " = " + str(sum(newSample[0][i])))
        except:
            pass
    print("")
    print("Se aplicará mutación")
    x = input()
    
    # Se aplica mutación
    ii = 0
    while ii < qi:
        # Se evalúa si se aplicará mutación
        random_num = random.randint(0,99)
        if random_num < pm:
            print("El cromosoma " + str(ii) + " ha activado mutación (Probabilidad: " + str(random_num) + " < " + str(pm) + ")")
            print("")
            
            processors = [0, 1, 2, 3, 4, 5]
            random.shuffle(processors) # Se mezclarán y se hará una sumas balanceadas cíclica
            
            print("Tupla mezclada: " + str(processors))
            print("")
            
            print("Valores antes de la mutación: ")
            print(newSample[0][ii])
            print("")
            
            min_value = min(newSample[0][ii])
            operation = random.randint(0, 1) # Elige la operación con la que empezará la suma equilibrada
            addition = random.randint(0, min_value)
            
            print("Tupla " + str(processors))
            print("min_value = " + str(min_value))
            print("addition = " + str(addition))
            print("")
            
            if operation == 0:
                newSample[0][ii][processors[0]] = newSample[0][ii][processors[0]] - addition
                newSample[0][ii][processors[1]] = newSample[0][ii][processors[1]] + addition
                newSample[0][ii][processors[2]] = newSample[0][ii][processors[2]] - addition
                newSample[0][ii][processors[3]] = newSample[0][ii][processors[3]] + addition
                newSample[0][ii][processors[4]] = newSample[0][ii][processors[4]] - addition
                newSample[0][ii][processors[5]] = newSample[0][ii][processors[5]] + addition
            else:
                newSample[0][ii][processors[0]] = newSample[0][ii][processors[0]] + addition
                newSample[0][ii][processors[1]] = newSample[0][ii][processors[1]] - addition
                newSample[0][ii][processors[2]] = newSample[0][ii][processors[2]] + addition
                newSample[0][ii][processors[3]] = newSample[0][ii][processors[3]] - addition
                newSample[0][ii][processors[4]] = newSample[0][ii][processors[4]] + addition
                newSample[0][ii][processors[5]] = newSample[0][ii][processors[5]] - addition
            
            print("Valores después de la mutación: ")
            print(newSample[0][ii])
            print("")
            
        else:
            print("El cromosoma " + str(ii) + " no ha activado mutación (Probabilidad: !" + str(random_num) + " < " + str(pm) + "!)")
            print("")
        ii = ii + 1
    
    print("Nueva muestra " + str(ig + 1) + " después de la mutación")
    for i in range(qi):
        try:
            print(str(newSample[0][i]) + " = " + str(sum(newSample[0][i])))
        except:
            pass
    print("")
    print("Se tratará una nueva generación")
    x = input()
    
    sample = newSample
    ig = ig + 1