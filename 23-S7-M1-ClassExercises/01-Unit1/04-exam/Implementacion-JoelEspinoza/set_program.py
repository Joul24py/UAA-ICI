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
Archivo: set_program
Función: Obtiene los valores con los que se calibrará el Algoritmo Genético

Se utilizarán las siguientes variables:
    values_file: Variable que guardará el contenido del archivo "values.txt"
    population_file: Variable que guardará el contenido del archivo "population.txt"
    line_counter: Iterador de archivo para contar los individuos dentro de "population.txt"
    length_aux: Guarda la primera línea de "population.txt"
    length_counter: Guarda un número de identificación para obtener el número de elementos por individuo
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
    ii: Iterador para los individuos
    ie: Iterador para los elementos de cada individuo
    individual: Variable usada para la construcción aleatoria de individuos
    gen: Número 0 o 1 insertado a individual
    L:
    input_aux:

Con las variables anteriores, se utilizarán las siguientes estructuras:
    sample: Matriz donde se guarda la población
'''

#%%
import random
import math

#%%
def set_values():
    sample = [[], [] ,[], []]
    values_file = open("files/values.txt","r")
    
    # Se obtiene el modo de personalización
    set_customization = int(get_value(values_file.readline()))
    
    # La personalización se hará parcialmente por values.txt junto con population.txt
    if set_customization == 0:
        # Se ignoran dos renglones en values.txt
        pc = float(get_value(values_file.readline()))
        pc = float(get_value(values_file.readline()))
        
        # Se abre population.txt
        population_file = open("files/population.txt","r")
        
        # Se obtendrá qe contando la longitud de un renglón
        length_aux = population_file.readline()
        length_counter = length_aux.find("\n")
        if length_counter != -1:
            qe = length_counter
        else:
            qe = len(length_aux)
        
        # Reset: Se cierra y se abre el archivo nuevamente para lectura completa
        population_file.close()
        population_file = open("files/population.txt","r")
        
        # Se obtendrá qi contando la cantidad de renglones
        qi = 0
        for line_counter in population_file:
            if line_counter != "\n":
                qi = qi + 1
            
            # Se formará la población del archivo population.txt
            length_counter = line_counter.find("\n")
            if length_counter != -1:
                sample[0].append(line_counter[:length_counter])
            else:
                sample[0].append(line_counter)
        
        population_file.close()
    
    # La personalización se hará enteramente por values.txt
    if set_customization == 1:
        qe = int(get_value(values_file.readline()))
        qi = int(get_value(values_file.readline()))
                
    pc = float(get_value(values_file.readline()))
    pm = float(get_value(values_file.readline()))
    qelitism = int(get_value(values_file.readline()))
    qg = int(get_value(values_file.readline()))
    x_min = float(get_value(values_file.readline()))
    x_max = float(get_value(values_file.readline()))
    accuracy = float(get_value(values_file.readline()))
    
    values_file.close()
    
    # Se sugerirá un qe según los valores de x_min, x_max y accuracy
    L = round(math.log((1 + ((x_max - x_min)/(accuracy))), 2) + 0.00000001)
    
    # Lo anterior implica que si L y qe no son iguales, se pedirá al usuario elegir
    if (qe != L) and (set_customization == 1):
        print("Para conseguir una precisión de " + str(accuracy) + " es recomendable usar una cantidad de elementos por individuo de " + str(L) + " y usted especificó una cantidad de " + str(qe))
        print("¿Desea cambiar el valor?")
        print("0: No, haré los cálculos con el valor " + str(qe) + " que es el que especifiqué en el archivo")
        print("1: Acepto la recomendación y tomaré " + str(L) + " para hacer los cálculos con este valor")
        input_aux = int(input())
        if input_aux == 1:
            qe = L
    
    # Ahora se construirá una población aleatoria
    if set_customization == 1:
        for ii in range(qi):
            individual = ""
            for ie in range(qe):
                gen = random.randint(0, 1)
                individual = individual + str(gen)
            sample[0].append(individual)
    
    return set_customization, qe, qi, pc, pm, qelitism, qg, x_min, x_max, accuracy, sample

# Función para obtener los valores de cada renglón del archivo values.txt
def get_value(line):
    initial_position = line.find(":")
    if line[initial_position + 1] == " ":
        initial_position = initial_position + 1
    final_position = line.find("\n")
    return line[initial_position + 1:final_position]