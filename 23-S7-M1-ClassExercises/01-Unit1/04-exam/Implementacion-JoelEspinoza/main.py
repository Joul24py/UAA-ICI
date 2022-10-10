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
Archivo: main
Función: Supervisa el flujo principal del programa

Se utilizarán las siguientes variables:
    set_customization: Modo de personalización del programa
        Si está en 0, usará los parámetros del archivo
        Si está en 1, permitirá edición libre ignorando el archivo
    qe: Cantidad de elementos por individuo
    qi: Cantidad de individuos
    pc: Probabilidad de cruzamiento
    pm: Probabilidad de mutación
    qelitism: Cantidad de individuos a heredar a la siguiente generación por elitismo
    qg: Cantidad de generaciones
    x_min: El intervalo inferior de x
    x_max: El intervalo superior de x
    accuracy: La precisión requerida
    ii: Iterador de los individuos
    random_num: Número aleatorio
    rand_pick: Número aleatorio
    ic: Iterador principal de cruzamiento
    jc: Iterador secundario de cruzamiento
    ig: Iterador de generaciones
    PEC: PreviousExecutionCounter

Con las variables anteriores, se utilizarán las siguientes estructuras:
    sample: En búsqueda de la mayor similitud con el programa en C aquí sample y results se fusionan en la misma estructura
'''

#%% Importación de archivos
import random

#%% Configuración del programa
stream = open("set_program.py", encoding="utf-8")
read_file = stream.read()
exec(read_file)

# Ya se tienen las variables
set_customization, qe, qi, pc, pm, qelitism, qg, x_min, x_max, accuracy, sample = set_values()
ig = 0
finals = []

#%% Preparación y exportación del primer trozo del archivo: La portada del archivo
stream = open("exporting_functions.py", encoding="utf-8")
read_file = stream.read()
exec(read_file)

PEC = PreviousExecutionCounter()
FirstExport(PEC + 1, set_customization, qe, qi, pc, pm, qelitism, qg, x_min, x_max, accuracy, sample)

#%% Ejecución del Algoritmo Genético Simple

# Cargamos el programa de functions
stream = open("functions.py", encoding="utf-8")
read_file = stream.read()
exec(read_file)

while ig <= qg:
    # Cargamos la población al archivo
    ShowPopulation(PEC + 1, qi, sample, ig)
    
    # Evaluamos a todas las muestras junto con sus evaluaciones acumuladas
    sample = evaluate(qe, x_min, x_max, sample, 0)
    finals.append([sample[1], sample[2]])
    Evaluation(PEC + 1, qi, sample)
    
    # Ordenamos
    sample = JoulSort(sample, qi)
    sample = evaluate(qe, x_min, x_max, sample, 1)
    Sorting(PEC + 1, qi, sample)
    
    # Creamos una nueva muestra vacía
    newSample = newSampleCreator(qi)
    ShowNullNewSample(PEC + 1, qi, newSample)
    
    # Buscamos los qelitism mejores
    ii = 0
    while ii < qelitism:
        newSample[0][ii] = sample[0][ii]
        newSample[1][ii] = sample[1][ii]
        newSample[2][ii] = sample[2][ii]
        newSample[3][ii] = sample[3][ii]
        ii = ii + 1
    ShowNewSampleWithElit(PEC + 1, qi, newSample, qelitism, pc)
    
    # Aplicamos cruzamiento
    while ii < qi:
        random_num = random.randint(0,99)
        
        if random_num < pc:
            CrossingTitle(PEC + 1, random_num, pc, 1)
            
            # Seleccionamos por ruleta
            # Padre 1
            random_pick = random.uniform(0, sample[3][ii])
            
            for ic in range(qi):
                if random_pick < sample[3][ic]:
                    c1 = sample[0][ic]
                    RouleteTitle(PEC + 1, random_pick, c1, 1)
                    break
            
            # Padre 2
            random_pick = random.uniform(0, sample[3][ii])
            
            for ic in range(qi):
                if random_pick < sample[3][ic]:
                    c2 = sample[0][ic]
                    RouleteTitle(PEC + 1, random_pick, c2, 2)
                    break
            
            # Seleccionamos aleatoriamente un punto de corte
            random_cut = random.randint(1, qe - 1)
            CutTitle(PEC + 1, random_cut, ii, c1, c2, qe)
            newSample[0][ii] = c1[:random_cut] + c2[random_cut:]
            try:
                newSample[0][ii + 1] = c2[:random_cut] + c1[random_cut:]
            except:
                pass
            
        else:
            CrossingTitle(PEC + 1, random_num, pc, 0)
            
            # Seleccionamos por ruleta
            # Padre 1
            random_pick = random.uniform(0, sample[3][ii])
            
            for ic in range(qi):
                if random_pick < sample[3][ic]:
                    c1 = sample[0][ic]
                    RouleteTitle(PEC + 1, random_pick, c1, 1)
                    break
            
            # Padre 2
            random_pick = random.uniform(0, sample[3][ii])
            
            for ic in range(qi):
                if random_pick < sample[3][ic]:
                    c2 = sample[0][ic]
                    RouleteTitle(PEC + 1, random_pick, c2, 2)
                    break
            
            # No se activó el cruzamiento
            NoCutTitle(PEC + 1, ii, c1, c2, qe)
            newSample[0][ii] = c1
            try:
                newSample[0][ii + 1] = c2
            except:
                pass
        
        ii = ii + 2
    
    ShowPostCrossing(PEC + 1, qi, newSample, pm)
    
    # Aplicamos mutación
    ii = 0
    while ii < qi:
        random_num = random.randint(0,99)
        
        if random_num < pm:
            random_cut = random.randint(0, qe - 1)
            MutationTitle(PEC + 1, random_num, ii, pm, 1, random_cut)
            
            if newSample[0][random_cut] == '1':
                newSample[0][random_cut] = '0'
            if newSample[0][random_cut] == '0':
                newSample[0][random_cut] = '1'
            
        else:
            MutationTitle(PEC + 1, random_num, ii, pm, 0, random_cut)
        
        ii = ii + 1
    
    # Transformamos newSample en sample y se repetiría el procedimiento
    sample = newSample
    ig = ig + 1

#%% Exportación de resultados a formatos visibles
sample = evaluate(qe, x_min, x_max, sample, 1)
#finals.append([sample[1], sample[2]])
FinalResults(PEC + 1, qi, sample)
CreateGraph(PEC + 1, x_min, x_max, finals, qg)
CreateGIF(PEC + 1, x_min, x_max, finals, qg)