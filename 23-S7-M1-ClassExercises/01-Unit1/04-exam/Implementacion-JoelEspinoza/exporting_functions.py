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
Archivo: exporting_functions
Función: Se encarga de exportar el procedimiento a archivos txt e imagen

Se utilizarán las siguientes variables:
    iPEC: Iterador para PreviousExecutionCounter
    total: Total de ejecuciones existentes en la carpeta
    iFE: Iterador para FirstExport
    iE: Iterador para Evaluation
    
'''

#%% Importación de archivos
import os
import matplotlib.pyplot as plt
import numpy as np
import imageio

#%% Determina el número de ejecuciones que ya hay en la carpeta
def PreviousExecutionCounter():
    for iPEC in os.walk("executions"):
        total = len(iPEC[2])
    
    total = int(total/3)
    return total

#%% Comienza un nuevo archivo para la nueva ejecución
def FirstExport(exec_num, set_customization, qe, qi, pc, pm, qelitism, qg, x_min, x_max, accuracy, sample):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    
    file.write("                   Centro de Ciencias Básicas\n")
    file.write("           Departamento de Ciencias de la Computación\n")
    file.write("                       Metaheurísticas I\n")
    file.write("                            7° “A”\n")
    file.write("\n")
    file.write("                   Primera Evaluación Parcial\n")
    file.write("\n")
    file.write("             Profesor: Francisco Javier Luna Rosas\n")
    file.write("\n")
    file.write("            Alumno: Joel Alejandro Espinoza Sánchez\n")
    file.write("Fecha de Entrega: Aguascalientes, Ags., 15 de septiembre de 2021\n")
    file.write("_____________________________________________________________________\n")
    file.write("\n")
    file.write("Ejecución número " + str(exec_num) +"\n")
    file.write("Algoritmo configurado con las siguientes variables:\n")
    file.write("   Modo de personalización del programa: " + str(set_customization) + "\n")
    file.write("   Cantidad de elementos por individuo: " + str(qe) + "\n")
    file.write("   Cantidad de individuos: " + str(qi) + "\n")
    file.write("   Probabilidad de cruzamiento: " + str(pc) + "%\n")
    file.write("   Probabilidad de mutación: " + str(pm) + "%\n")
    file.write("   Cantidad de individuos a heredar por elitismo: " + str(qelitism) + "\n")
    file.write("   Cantidad de generaciones: " + str(qg) + "\n")
    file.write("   Intervalo inferior en x: " + str(x_min) + "\n")
    file.write("   Intervalo superior en x: " + str(x_max) + "\n")
    file.write("   Precisión: " + str(accuracy) + "\n")
    file.write("_____________________________________________________________________\n")
    file.write("\n")
    
    file.close()
    return

#%% Se muestra la población
def ShowPopulation(exec_num, qi, sample, ig):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    
    file.write("POBLACIÓN " + str(ig) + "\n")
    file.write("La población " + str(ig) + " es la siguiente:\n")
    file.write("\n")
    
    for iFE in range(qi):
        file.write(sample[0][iFE] + "\n")
    
    file.write("_____________________________________________________________________\n")
    file.write("\n")
    
    file.close()
    return

#%% Se realiza una evaluación de cada miembro (la población no está ordenada)
def Evaluation(exec_num, qi, sample):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    
    file.write("EVALUACIÓN DE LOS INDIVIDUOS\n")
    file.write("Al evaluar a los indiviudos, tenemos los siguientes datos:\n")
    file.write("\n")
    file.write("  Cadena binaria      \t\tx                    \tf(x)              f(x) acumulada\n")
    
    for iE in range(qi):
        file.write(str(sample[0][iE]) + "    \t" + str(sample[1][iE]) + "    \t" + str(sample[2][iE]) + "  \t" + str(sample[3][iE]) + "\n")
    
    file.write("_____________________________________________________________________\n")
    file.write("\n")
    
    file.close()
    return

#%% Se ordena a la población para hacer elitismo
def Sorting(exec_num, qi, sample):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    
    file.write("ORDENAMIENTO DE LOS INDIVIDUOS\n")
    file.write("Al ordenar la población de forma descendente (en función de f(x)) obtenemos lo siguiente:\n")
    file.write("\n")
    file.write("  Cadena binaria      \t\tx                    \tf(x)              f(x) acumulada\n")
    
    for iE in range(qi):
        file.write(str(sample[0][iE]) + "    \t" + str(sample[1][iE]) + "    \t" + str(sample[2][iE]) + "  \t" + str(sample[3][iE]) + "\n")
    
    file.write("_____________________________________________________________________\n")
    file.write("\n")
    
    file.close()
    return

#%% Se prepara la estructura para llevar ahí la nueva población
def ShowNullNewSample(exec_num, qi, sample):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    
    file.write("INICIALIZACIÓN DE LA NUEVA POBLACIÓN\n")
    file.write("La estructura para la nueva población ha sido creada:\n")
    file.write("\n")
    file.write("Cadena binaria    x    f(x)    f(x) acumulada\n")
    
    for iE in range(qi):
        file.write("      " + str(sample[0][iE]) + "\t\t  " + str(sample[1][iE]) + "  \t" + str(sample[2][iE]) + "  \t     " + str(sample[3][iE]) + "\n")
    
    file.write("_____________________________________________________________________\n")
    file.write("\n")
    
    file.close()
    return

#%% Se muestra newSample con los miembros añadidos por elitismo
def ShowNewSampleWithElit(exec_num, qi, sample, qelitism, pc):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    
    file.write("REALIZACIÓN DE ELITISMO\n")
    file.write("Se han pasado los " + str(qelitism) + " mejores individuos, teniendo ahora:\n")
    file.write("\n")
    file.write("  Cadena binaria      \t\tx                    \tf(x)              f(x) acumulada\n")
    
    for iE in range(qi):
        if iE < qelitism:
            file.write(str(sample[0][iE]) + "    \t" + str(sample[1][iE]) + "    \t" + str(sample[2][iE]) + "  \t" + str(sample[3][iE]) + "\n")
        else:
            file.write("      " + str(sample[0][iE]) + "\t\t\t\t" + str(sample[1][iE]) + "  \t\t\t " + str(sample[2][iE]) + "  \t\t\t" + str(sample[3][iE]) + "\n")
    
    file.write("_____________________________________________________________________\n")
    file.write("\n")
    
    file.write("EJECUCIÓN DEL CRUZAMIENTO\n")
    file.write("Se realizará la ejecución del cruzamiento con una probabilidad del " + str(int(pc)) + "%:\n")
    file.write("\n")
    
    file.close()
    return

#%% Se reporta la activación del cruzamiento
def CrossingTitle(exec_num, random_num, pc, activated):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    
    if activated == 1:
        file.write("   El cruzamiento se ha activado (Probabilidad: " + str(random_num) + " < " + str(int(pc)) + ")\n")
    if activated == 0:
        file.write("   El cruzamiento no se ha activado (Probabilidad: ! " + str(random_num) + " < " + str(int(pc)) + " !)\n")
    file.write("\n")
    
    file.close()
    return

#%% Se reporta la selección por ruleta
def RouleteTitle(exec_num, random_pick, cross, parent):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    
    if parent == 1:
        file.write("      Aplicamos selección por ruleta para el primer padre obteniendo " + str(random_pick) + "\n")
    if parent == 2:
        file.write("      Aplicamos selección por ruleta para el segundo padre obteniendo " + str(random_pick) + "\n")
    file.write("      Por lo tanto, el cromosoma a escoger será " + str(cross) +"\n")
    file.write("\n")
    
    file.close()
    return

#%% Se reporta el punto de corte
def CutTitle(exec_num, random_cut, ii, c1, c2, qe):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    file.write("      Se ha seleccionado aleatoriamente un punto de corte entre el gen " + str(random_cut) + " y " + str(random_cut + 1) + "\n")
    file.write("      Serán los cromosomas " + str(ii + 1) + " y " + str(ii + 2) + " de la nueva generación\n")
    file.write("\n")
    
    file.write("      ")
    for i in range(qe):
        if i < random_cut:
            file.write("(" + str(c1[i]) + ")")
        else:
            file.write("[" + str(c2[i]) + "]")
    file.write("\n")
    
    file.write("      ")
    for i in range(qe):
        if i < random_cut:
            file.write("[" + str(c2[i]) + "]")
        else:
            file.write("(" + str(c1[i]) + ")")
    file.write("\n")
    
    file.write("\n")
    
    file.close()
    return

#%% Se reporta si no hubo punto de corte
def NoCutTitle(exec_num, ii, c1, c2, qe):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    file.write("      No hay punto de corte\n")
    file.write("      Serán los cromosomas " + str(ii + 1) + " y " + str(ii + 2) + " de la nueva generación\n")
    file.write("\n")
    
    file.write("      ")
    for i in range(qe):
        file.write("(" + str(c1[i]) + ")")
    file.write("\n")
    
    file.write("      ")
    for i in range(qe):
        file.write("[" + str(c2[i]) + "]")
    file.write("\n")
    
    file.write("\n")
    
    file.close()
    return

#%% Se muestra a la población al pasar el cruzamiento
def ShowPostCrossing(exec_num, qi, sample, pm):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    
    file.write("_____________________________________________________________________\n")
    file.write("\n")
    file.write("CRUZAMIENTO FINALIZADO\n")
    file.write("La nueva generación ha pasado la etapa de cruzamiento exitosamente:\n")
    
    for iE in range(qi):
        file.write(str(sample[0][iE]) + "\n")
    
    file.write("_____________________________________________________________________\n")
    file.write("\n")
    
    file.write("EJECUCIÓN DE MUTACIONES\n")
    file.write("Se realizará la ejecución de mutaciones con una probabilidad del " + str(int(pm)) + "%:\n")
    file.write("\n")
    
    file.close()
    return

#%% Se reporta la activación de mutación
def MutationTitle(exec_num, random_num, ii, pm, activated, random_cut):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    
    if activated == 1:
        file.write("   La mutación se ha activado para el cromosoma " + str(ii + 1) + " (Probabilidad: " + str(random_num) + " < " + str(int(pm)) + ")\n")
        file.write("   El gen a mutar será el gen número " + str(random_cut + 1) + "\n")
    if activated == 0:
        file.write("   La mutación no se ha activado para el cromosoma " + str(ii + 1) + " (Probabilidad: ! " + str(random_num) + " < " + str(int(pm)) + " !)\n")
    file.write("\n")
    
    file.close()
    return

#%% Se muestra a la población al pasar la mutación
def ShowPostMutation(exec_num, qi, sample, pm):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    
    file.write("_____________________________________________________________________\n")
    file.write("\n")
    file.write("MUTACIÓN FINALIZADA\n")
    file.write("La nueva generación ha pasado la etapa de mutación exitosamente\n")
    file.write("Quiere decir que se le han aplicado todos los operadores a la nueva generación exitosamente:\n")
    
    for iE in range(qi):
        file.write(str(sample[0][iE]) + "\n")
    
    file.write("_____________________________________________________________________\n")
    file.write("\n")
    
    file.close()
    return

#%% Se mostrarán los resultados finales
def FinalResults(exec_num, qi, sample):
    file = open("executions/execution " + str(exec_num) + ".txt", 'a')
    
    file.write("_____________________________________________________________________\n")
    file.write("\n")
    file.write("RESULTADOS FINALES\n")
    file.write("El algoritmo genético ha terminado con los siguientes resultados:\n")
    file.write("\n")
    file.write("  Cadena binaria      \t\tx                    \tf(x)              f(x) acumulada\n")
    
    for iE in range(qi):
        file.write(str(sample[0][iE]) + "    \t" + str(sample[1][iE]) + "    \t" + str(sample[2][iE]) + "  \t" + str(sample[3][iE]) + "\n")
    
    file.write("_____________________________________________________________________\n")
    file.write("\n")
    file.write("Otra buena forma de visualización del algoritmo es con la ejecución visual adjunta a este procedimiento\n")
    
    file.close()
    return

#%% Finalmente se exportará un gráfico de evolución del algoritmo
def CreateGraph(exec_num, x_min, x_max, finals, qg):
    # Se hace un espacio dividido en 100 separaciones
    x = np.linspace(-1,21,100)
    
    # Se indica la función
    y = x/(1+(x**2))
    
    '''
    # Fijando al centro los ejes
    fig = plt.figure()
    ax = fig.add_subplot(1, 1, 1)
    ax.spines['left'].set_position(0)
    ax.spines['bottom'].set_position('zero')
    ax.spines['right'].set_color('none')
    ax.spines['top'].set_color('none')
    ax.xaxis.set_ticks_position('bottom')
    ax.yaxis.set_ticks_position('left')
    '''
    plt.xlim(-1, 21)
    plt.ylim(0, 0.6)
    
    # Dibujamos la función
    plt.plot(x,y, 'blue')
    
    # Distribuimos los colores
    cmap = plt.get_cmap("RdYlGn")
    colors = [cmap(i) for i in np.linspace(0,1,qg)]
    for i, color in enumerate(colors, start = 0):
        plt.scatter(finals[i][0], finals[i][1], color = color)
    
    # show the plot
    plt.show()
    
    plt.savefig("executions/execution " + str(exec_num) + ".jpg")
    return

#%% Finalmente se exportará un gráfico de evolución del algoritmo
def CreateGIF(exec_num, x_min, x_max, finals, qg):
    # Se hace un espacio dividido en 100 separaciones
    x = np.linspace(-1,21,100)
    
    # Se indica la función
    y = x/(1+(x**2))
    
    plt.xlim(-1, 21)
    plt.ylim(0, 0.6)
    
    # Dibujamos la función
    plt.plot(x,y, 'blue')
    
    frames = []
    
    # Distribuimos los colores
    cmap = plt.get_cmap("RdYlGn")
    colors = [cmap(i) for i in np.linspace(0,1,len(finals))]
    for i in range(len(colors)):
        plt.scatter(finals[i][0], finals[i][1], color = colors[i])
        plt.title(label = "Generación " + str(i))
        plt.show()
        plt.savefig("temporal/" + str(i) + ".jpg")
        frames.append("temporal/" + str(i) + ".jpg")
        plt.clf()
        
        # Se hace un espacio dividido en 100 separaciones
        x = np.linspace(-1,21,100)
        
        # Se indica la función
        y = x/(1+(x**2))
        
        plt.xlim(-1, 21)
        plt.ylim(0, 0.6)
        
        # Dibujamos la función
        plt.plot(x,y, 'blue')
    plt.close()
    
    '''
    # Obtenemos en una lista las imágenes
    images = os.listdir("temporal")
    frames = []
    for i in range(len(finals)):
        frames.append("temporal/" + images[i])
    '''
    
    # Construimos el GIF
    with imageio.get_writer("executions/execution " + str(exec_num) + ".gif", mode = "I", duration = 0.25) as writer:
        for filename in frames:
            image = imageio.imread(filename)
            writer.append_data(image)
    
    # Eliminamos temporal
    for i in range(len(frames)):
        os.remove(frames[i])