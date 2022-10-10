#%% Portada
'''
                   Centro de Ciencias Básicas
           Departamento de Ciencias de la Computación
                       Metaheurísticas I
                            7° “A”

                   Primera Evaluación Parcial

             Profesor: Francisco Javier Luna Rosas

            Alumno: Joel Alejandro Espinoza Sánchez

Fecha de Entrega: Aguascalientes, Ags., 15 de septiembre de 2021
'''

#%% Descripción
'''
Archivo: functions
Función: Realiza otras funciones de apoyo para el Algoritmo Genético

Se utilizarán las siguientes variables:
    qi:
    qe:
    x_min:
    x_max:
    ii:
    x:
    bin_ent:
    overwrite: Variable para sobrescribir o crear espacios en sample
        Si overwrite = 0 no se sobrescribe, se crean espacios
        Si overwrite = 1 se sobrescriben los espacios
    ijs: Iterador de JoulSort
    auxijs: Auxiliar Iterador de JoulSort
    auxjs: Auxiliar de JoulSort
    nullCreator:
    nullNewSample:

Con variables anteriores, se utilizarán las siguientes estructuras:
    sample:
'''

#%% Funciones para evaluación de muestras
def evaluate(qe, x_min, x_max, sample, overwrite = 0):
    for ii in range(len(sample[0])):
        bin_ent = int(sample[0][ii], 2)
        x = x_min + (bin_ent *((x_max - x_min)/((2**qe) - 1)))
        if overwrite == 0:
            sample[1].append(x)
            sample[2].append(f(x))
            if ii == 0:
                sample[3].append(f(x))
            else:
                sample[3].append(sample[3][ii - 1] + f(x))
        if overwrite == 1:
            sample[1][ii] = x
            sample[2][ii] = f(x)
            if ii == 0:
                sample[3][ii] = f(x)
            else:
                sample[3][ii] = sample[3][ii - 1] + f(x)
    return sample

def f(x):
    return (x)/(1+(x**2))

#%% Funciones para ordenar en la preparación para el elitismo
def JoulSort(sample, qi, order_by = 2):
    ijs = 0
    while ijs < qi - 1:
        if sample[2][ijs] < sample[2][ijs + 1]:
            for auxijs in range(4):
                auxjs = sample[auxijs][ijs]
                sample[auxijs][ijs] = sample[auxijs][ijs + 1]
                sample[auxijs][ijs + 1] = auxjs
            ijs = 0
            continue
        ijs = ijs + 1
    return sample

#%% Funciones para crear la nueva muestra vacía
def newSampleCreator(qi):
    nullCreator = []
    for ii in range(qi):
        nullCreator.append(0)
    nullNewSample = []
    nullNewSample.append(nullCreator[:])
    nullNewSample.append(nullCreator[:])
    nullNewSample.append(nullCreator[:])
    nullNewSample.append(nullCreator[:])
    return nullNewSample