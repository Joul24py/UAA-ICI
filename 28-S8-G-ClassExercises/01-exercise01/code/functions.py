#%% Portada
'''
           Universidad Autónoma de Aguascalientes
                 Centro de Ciencias Básicas
         Departamento de Ciencias de la Computación
                           8° "A"

             Examen / Tarea 1: Código de apoyo
               Archivo de funciones de apoyo

               Docente: Hermilo Sánchez Cruz

           Alumnos:
              Espinoza Sánchez Joel Alejandro
              Flores Fernández Óscar Alonso
              Gómez Garza Dariana
              Gónzalez Arenas Fernando Francisco

Fecha de Entrega: Aguascalientes, Ags., 11 de abril del 2022
'''

#%% Descripción y variables
'''
DESCRIPCIÓN:
VARIABLES:
'''

#%% Importación de librerías
import numpy as np
import cv2

#%% Función para cargar las imágenes
def loadImages():
    return ['043', '057', '079', '033', '030', '074', '076', '081', '054', '092']

#%% Función para obtener ancho y alto de una imagen
def getDimensions(image):
    return len(image), len(image[0]) # Retorna altura, anchura

#%% Función para transformar la matriz de una imagen y darle mejor tratamiento
def transform_data(image, height, width):
    newImage = []
    for i in range(height):
        newImage.append([])
        for j in range(width):
            if list(image[i, j]) == [0, 0, 0]:
                newImage[i].append(1)
            if list(image[i, j]) == [255, 255, 255]:
                newImage[i].append(0)
    return newImage

#%% Función para el ejercicio 2: Calcular la cantidad de 1-píxeles
def calcPixels(image, height, width):
    onePixels = 0
    zeroPixels = 0
    for i in range(height):
        for j in range(width):
            if image[i][j] == 1:
                onePixels = onePixels + 1
            if image[i][j] == 0:
                zeroPixels = zeroPixels + 1
    return onePixels, zeroPixels

#%% Función para el ejercicio 3: Calcular los centros de masa
def calcMassCenter(image, height, width, onePixels):
    # Cálculo del centro Y
    pixelsAbove = 0
    pixelsBelow = onePixels
    for i in range(1, height):
        oldSolution = [pixelsBelow, pixelsAbove]
        pixelsAbove = pixelsAbove + sum(image[i])
        pixelsBelow = pixelsBelow - sum(image[i])
        newSolution = [pixelsBelow, pixelsAbove]
        if pixelsAbove > pixelsBelow:
            break
    if (abs(oldSolution[0] - oldSolution[1])) < (abs(newSolution[0] - newSolution[1])):
        y_sol = oldSolution
        i = i - 1
    else:
        y_sol = newSolution
    y = i
    
    # Cálculo del centro X
    pixelsLeft = 0
    pixelsRight = onePixels
    for i in range(1, width):
        oldSolution = [pixelsLeft, pixelsRight]
        sumPixels = 0
        for j in range(height):
            sumPixels = sumPixels + image[j][i]
        pixelsLeft = pixelsLeft + sumPixels
        pixelsRight = pixelsRight - sumPixels
        newSolution = [pixelsLeft, pixelsRight]
        if pixelsLeft > pixelsRight:
            break
    if (abs(oldSolution[0] - oldSolution[1])) < (abs(newSolution[0] - newSolution[1])):
        x_sol = oldSolution
        i = i - 1
    else:
        x_sol = newSolution
    x = i
    
    return x, y, x_sol, y_sol

#%% Función para exportar como imagen los resultados del ejercicio 3
def exportImg_ej3(image, height, width, x, y, imageName):
    
    # Primero se transforma image a un numpy array
    for i in range(height):
        for j in range(width):
            if(image[i][j] == 0):
                image[i][j] = [255,255,255]
            if(image[i][j] == 1):
                image[i][j] = [0,0,0]
    
    # Colorear el centro de masa de rojo
    image[y][x] = [0,0,255]
    image[y][x + 1] = [0,0,255]
    image[y][x - 1] = [0,0,255]
    image[y + 1][x] = [0,0,255]
    image[y - 1][x] = [0,0,255]
    image[y + 1][x + 1] = [0,0,255]
    image[y - 1][x + 1] = [0,0,255]
    image[y + 1][x - 1] = [0,0,255]
    image[y - 1][x - 1] = [0,0,255]
    
    image = np.array(image)
    
    cv2.imwrite('results\\ex-03\\exercise-03-' + str(imageName) + '.jpeg', image)
    return

#%% Función para el ejercicio 4: Calcular los componentes conectados en vecindad 4
def calcConnected_4(image, height, width, imageName):
    imageEj4 = image
    for i in range(height):
        for j in range(width):
            if imageEj4[i][j] == 1:
                imageEj4[i][j] = -1
    print("    Transformación de datos para diferenciar entre píxel y etiqueta, hecho")
    
    tag = 1 # Etiqueta disponible
    equivalencias = []
    for i in range(height):
        for j in range(width):
            if imageEj4[i][j] == 0:
                continue
            if imageEj4[i][j] == -1:
                valuesToCheck = []
                # Validaciones de extremos
                if i != 0: # no estamos en un píxel del primer renglón
                    valuesToCheck.append(imageEj4[i - 1][j])
                if i != (height - 1): # no estamos en un píxel del último renglón
                    valuesToCheck.append(imageEj4[i + 1][j])
                if j != 0: # no estamos en un píxel de la primera columna
                    valuesToCheck.append(imageEj4[i][j - 1])
                if j != (width - 1): # no estamos en un píxel de la última columna
                    valuesToCheck.append(imageEj4[i][j + 1])
                
                # Validar si hay etiquetas
                tags = 0
                for k in valuesToCheck:
                    if (k != 0) and (k != -1):
                        tags = 1
                        break
                if tags == 0:
                    imageEj4[i][j] = tag
                    tag = tag + 1
                    continue
                if tags == 1:
                    imageEj4[i][j] = []
                    for k in valuesToCheck:
                        if (k != 0) and (k != -1):
                            imageEj4[i][j].append(k)
                    equivalencias.append(imageEj4[i][j]) # Juntar equivalencias
                    imageEj4[i][j] = min(imageEj4[i][j])
                    continue
    print("    Etiquetado de cada píxel, hecho")
    
    # Eliminar equivalencias repetidas
    newEq = []
    for i in equivalencias:
        if (i not in newEq) and (len(i) > 1):
            newEq.append(i)
    equivalencias = newEq
    print("    Eliminación de etiquetas repetidas, hecho")
    
    # Aplicar transitividad de equivalencias
    for h in range(5):
        for i in reversed(range(len(equivalencias))):
            for j in range(height):
                for k in range(width):
                    if imageEj4[j][k] in equivalencias[i]:
                        imageEj4[j][k] = min(equivalencias[i])
        print("    Revisión " + str(h + 1) + " de 5 al aplicar transitividad de equivalencias")
    print("    Aplicación de transitividad de equivalencias, hecho, fin")
    
    report = open("results\\ex-04\\conn-comp-4-" + str(imageName) + ".txt", 'w')
    for i in range(height):
        report.write(str(imageEj4[i]))
        report.write("\n")
    report.close()
    
    # Revisión de los distintos elementos dentro de la matriz de componentes conectados
    connected_matrix = []
    for i in range(height):
        for j in range(width):
            connected_matrix.append(imageEj4[i][j])
    connected_matrix = list(dict.fromkeys(connected_matrix))
    
    return len(connected_matrix) - 1, connected_matrix

#%% Función para el ejercicio 4: Calcular los componentes conectados en vecindad 8
def calcConnected_8(image, height, width, imageName):
    imageEj4 = image
    for i in range(height):
        for j in range(width):
            if imageEj4[i][j] == 1:
                imageEj4[i][j] = -1
    print("    Transformación de datos para diferenciar entre píxel y etiqueta, hecho")
    
    tag = 1 # Etiqueta disponible
    equivalencias = []
    for i in range(height):
        for j in range(width):
            if imageEj4[i][j] == 0:
                continue
            if imageEj4[i][j] == -1:
                valuesToCheck = []
                # Validaciones de extremos
                if i != 0: # evaluar píxel de arriba
                    valuesToCheck.append(imageEj4[i - 1][j])
                if i != (height - 1): # evaluar píxel de abajo
                    valuesToCheck.append(imageEj4[i + 1][j])
                if j != 0: # evaluar píxel de la izquierda
                    valuesToCheck.append(imageEj4[i][j - 1])
                if j != (width - 1): # evaluar píxel de la derecha
                    valuesToCheck.append(imageEj4[i][j + 1])
                if (i != 0) and (j != 0): # evaluar píxel de arriba-izquierda
                    valuesToCheck.append(imageEj4[i - 1][j - 1])
                if (i != 0) and (j != (width - 1)): # evaluar píxel de arriba-derecha
                    valuesToCheck.append(imageEj4[i - 1][j + 1])
                if (i != (height - 1)) and (j != 0): # evaluar píxel de abajo-izquierda
                    valuesToCheck.append(imageEj4[i + 1][j - 1])
                if (i != (height - 1)) and (j != (width - 1)): # evaluar píxel de abajo-derecha
                    valuesToCheck.append(imageEj4[i + 1][j + 1])
                
                # Validar si hay etiquetas
                tags = 0
                for k in valuesToCheck:
                    if (k != 0) and (k != -1):
                        tags = 1
                        break
                if tags == 0:
                    imageEj4[i][j] = tag
                    tag = tag + 1
                    continue
                if tags == 1:
                    imageEj4[i][j] = []
                    for k in valuesToCheck:
                        if (k != 0) and (k != -1):
                            imageEj4[i][j].append(k)
                    equivalencias.append(imageEj4[i][j]) # Juntar equivalencias
                    imageEj4[i][j] = min(imageEj4[i][j])
                    continue
    print("    Etiquetado de cada píxel, hecho")
    
    # Eliminar equivalencias repetidas
    newEq = []
    for i in equivalencias:
        if (i not in newEq) and (len(i) > 1):
            newEq.append(i)
    equivalencias = newEq
    print("    Eliminación de etiquetas repetidas, hecho")
    
    # Aplicar transitividad de equivalencias
    for h in range(5):
        for i in reversed(range(len(equivalencias))):
            for j in range(height):
                for k in range(width):
                    if imageEj4[j][k] in equivalencias[i]:
                        imageEj4[j][k] = min(equivalencias[i])
        print("    Revisión " + str(h + 1) + " de 5 al aplicar transitividad de equivalencias")
    print("    Aplicación de transitividad de equivalencias, hecho, fin")
    
    report = open("results\\ex-04\\conn-comp-8-" + str(imageName) + ".txt", 'w')
    for i in range(height):
        report.write(str(imageEj4[i]))
        report.write("\n")
    report.close()
    
    # Revisión de los distintos elementos dentro de la matriz de componentes conectados
    connected_matrix = []
    for i in range(height):
        for j in range(width):
            connected_matrix.append(imageEj4[i][j])
    connected_matrix = list(dict.fromkeys(connected_matrix))
    
    return len(connected_matrix) - 1, connected_matrix

#%% Función para exportar como imagen los resultados del ejercicio 4 vecindad-4
def exportImg_ej4_4(image, height, width, connectedMatrix, imageName):
    
    colorsSet = [[255,255,255],[0,0,255],[0,255,0],[255,0,0],
                 [8,160,255],[8,255,255],[251,255,8],
                 [255,8,247],[127,255,8],[255,8,168],
                 [0,0,0]]
    
    # Primero se transforma image a un numpy array
    for i in range(len(connectedMatrix)):
        for j in range(height):
            for k in range(width):
                if(image[j][k] == connectedMatrix[i]):
                    image[j][k] = colorsSet[i]
    
    image = np.array(image)
    
    cv2.imwrite('results\\ex-04\\exercise-04-4-' + str(imageName) + '.jpeg', image)
    return

#%% Función para exportar como imagen los resultados del ejercicio 4 vecindad-8
def exportImg_ej4_8(image, height, width, connectedMatrix, imageName):
    
    colorsSet = [[255,255,255],[0,0,255],[0,255,0],[255,0,0],
                 [8,160,255],[8,255,255],[251,255,8],
                 [255,8,247],[127,255,8],[255,8,168],
                 [0,0,0]]
    
    # Primero se transforma image a un numpy array
    for i in range(len(connectedMatrix)):
        for j in range(height):
            for k in range(width):
                if(image[j][k] == connectedMatrix[i]):
                    image[j][k] = colorsSet[i]
    
    image = np.array(image)
    
    cv2.imwrite('results\\ex-04\\exercise-04-8-' + str(imageName) + '.jpeg', image)
    return

#%% Función para el ejercicio 5: Obtener el contorno en vecindad 4
def calcPerimeter_4(image, height, width, imageName):
    imageEj4 = image
    for i in range(height):
        for j in range(width):
            if imageEj4[i][j] == 1:
                imageEj4[i][j] = -1
    print("Transformación de datos para diferenciar entre píxel y contorno, hecho")
    
    for i in range(height):
        for j in range(width):
            if imageEj4[i][j] == 0:
                continue
            if imageEj4[i][j] == -1:
                valuesToCheck = []
                # Validaciones de extremos
                if i != 0: # no estamos en un píxel del primer renglón
                    valuesToCheck.append(imageEj4[i - 1][j])
                if i != (height - 1): # no estamos en un píxel del último renglón
                    valuesToCheck.append(imageEj4[i + 1][j])
                if j != 0: # no estamos en un píxel de la primera columna
                    valuesToCheck.append(imageEj4[i][j - 1])
                if j != (width - 1): # no estamos en un píxel de la última columna
                    valuesToCheck.append(imageEj4[i][j + 1])
                
                # Validar si hay etiquetas
                tags = 0
                for k in valuesToCheck:
                    if (k == 0):
                        tags = 1
                        break
                if tags == 0:
                    imageEj4[i][j] = 1
                    continue
                if tags == 1:
                    imageEj4[i][j] = -1
    
    for i in range(height):
        for j in range(width):
            if imageEj4[i][j] == 1:
                imageEj4[i][j] = 0
    
    for i in range(height):
        for j in range(width):
            if imageEj4[i][j] == -1:
                imageEj4[i][j] = 1
    
    report = open("results\\ex-05\\perimeter-4-" + str(imageName) + ".txt", 'w')
    for i in range(height):
        report.write(str(imageEj4[i]))
        report.write("\n")
    report.close()
    
    return

#%% Función para el ejercicio 5: Obtener el contorno en vecindad 8
def calcPerimeter_8(image, height, width, imageName):
    imageEj4 = image
    for i in range(height):
        for j in range(width):
            if imageEj4[i][j] == 1:
                imageEj4[i][j] = -1
    print("Transformación de datos para diferenciar entre píxel y contorno, hecho")
    
    for i in range(height):
        for j in range(width):
            if imageEj4[i][j] == 0:
                continue
            if imageEj4[i][j] == -1:
                valuesToCheck = []
                # Validaciones de extremos
                if i != 0: # evaluar píxel de arriba
                    valuesToCheck.append(imageEj4[i - 1][j])
                if i != (height - 1): # evaluar píxel de abajo
                    valuesToCheck.append(imageEj4[i + 1][j])
                if j != 0: # evaluar píxel de la izquierda
                    valuesToCheck.append(imageEj4[i][j - 1])
                if j != (width - 1): # evaluar píxel de la derecha
                    valuesToCheck.append(imageEj4[i][j + 1])
                if (i != 0) and (j != 0): # evaluar píxel de arriba-izquierda
                    valuesToCheck.append(imageEj4[i - 1][j - 1])
                if (i != 0) and (j != (width - 1)): # evaluar píxel de arriba-derecha
                    valuesToCheck.append(imageEj4[i - 1][j + 1])
                if (i != (height - 1)) and (j != 0): # evaluar píxel de abajo-izquierda
                    valuesToCheck.append(imageEj4[i + 1][j - 1])
                if (i != (height - 1)) and (j != (width - 1)): # evaluar píxel de abajo-derecha
                    valuesToCheck.append(imageEj4[i + 1][j + 1])
                
                # Validar si hay etiquetas
                tags = 0
                for k in valuesToCheck:
                    if (k == 0):
                        tags = 1
                        break
                if tags == 0:
                    imageEj4[i][j] = 1
                    continue
                if tags == 1:
                    imageEj4[i][j] = -1
    
    for i in range(height):
        for j in range(width):
            if imageEj4[i][j] == 1:
                imageEj4[i][j] = 0
    
    for i in range(height):
        for j in range(width):
            if imageEj4[i][j] == -1:
                imageEj4[i][j] = 1
    
    report = open("results\\ex-05\\perimeter-8-" + str(imageName) + ".txt", 'w')
    for i in range(height):
        report.write(str(imageEj4[i]))
        report.write("\n")
    report.close()
    
    return

#%% Función para exportar como imagen los resultados del ejercicio 5 vecindad-4
def exportImg_ej5_4(image, height, width, imageName):
    
    # Primero se transforma image a un numpy array
    for i in range(height):
        for j in range(width):
            if(image[i][j] == 0):
                image[i][j] = [255,255,255]
            if(image[i][j] == 1):
                image[i][j] = [0,0,0]
    
    image = np.array(image)
    
    cv2.imwrite('results\\ex-05\\exercise-05-4-' + str(imageName) + '.jpeg', image)
    return

#%% Función para exportar como imagen los resultados del ejercicio 5 vecindad-8
def exportImg_ej5_8(image, height, width, imageName):
    
    # Primero se transforma image a un numpy array
    for i in range(height):
        for j in range(width):
            if(image[i][j] == 0):
                image[i][j] = [255,255,255]
            if(image[i][j] == 1):
                image[i][j] = [0,0,0]
    
    image = np.array(image)
    
    cv2.imwrite('results\\ex-05\\exercise-05-8-' + str(imageName) + '.jpeg', image)
    return

#%% Función para el ejercicio 6: Superposición de dos objetos haciendo coincidir el centro de masa
def overlap(image1, height1, width1, x1, y1, imageName1, image2, height2, width2, x2, y2, imageName2):
    # Recorremos la imagen que necesita ser llevada hasta los puntos del centro de masa mayor
    
    # Caso x
    if(x1 < x2):
        diff = x2 - x1
        pixelsAdded = [0] * diff
        for i in range(height1):
            image1[i] = pixelsAdded + image1[i]
        width1 = width1 + diff
    if(x1 > x2):
        diff = x1 - x2
        pixelsAdded = [0] * diff
        for i in range(height2):
            image2[i] = pixelsAdded + image2[i]
        width2 = width2 + diff
    
    # Caso y
    if(y1 < y2):
        diff = y2 - y1
        row = [0] * width1
        newImage1 = []
        for i in range(diff):
            newImage1.append(row)
        for i in range(height1):
            newImage1.append(image1[i])
        height1 = height1 + diff
        image1 = newImage1
    if(y1 < y2):
        diff = y1 - y2
        row = [0] * width2
        newImage2 = []
        for i in range(diff):
            newImage2.append(row)
        for i in range(height2):
            newImage2.append(image2[i])
        height2 = height2 + diff
        image2 = newImage2
    
    # Completamos ambas imágenes para que tengan las mismas dimensiones
    
    # Caso x
    if (width1 < width2):
        diff = width2 - width1
        pixelsAdded = [0] * diff
        for i in range(height1):
            image1[i] = image1[i] + pixelsAdded
        width1 = width1 + diff
    if (width1 > width2):
        diff = width1 - width2
        pixelsAdded = [0] * diff
        for i in range(height2):
            image2[i] = image2[i] + pixelsAdded
        width2 = width2 + diff
    
    # Caso y
    if(height1 < height2):
        diff = height2 - height1
        row = [0] * width1
        newImage1 = []
        for i in range(height1):
            newImage1.append(image1[i])
        for i in range(diff):
            newImage1.append(row)
        height1 = height1 + diff
        image1 = newImage1
    if(y1 < y2):
        diff = height1 - height2
        row = [0] * width2
        newImage2 = []
        for i in range(height2):
            newImage2.append(image2[i])
        for i in range(diff):
            newImage2.append(row)
        height2 = height2 + diff
        image2 = newImage2
    
    # Juntamos ambas imágenes
    zeros = 0
    onesImg1 = 0
    onesImg2 = 0
    bothOnes = 0
    newImage = []
    for i in range(height1):
        newImage.append([])
        for j in range(width1):
            if(image1[i][j] == 0) and (image2[i][j] == 0):
                zeros = zeros + 1
                newImage[i].append(0)
            if(image1[i][j] == 1) and (image2[i][j] == 0):
                onesImg1 = onesImg1 + 1
                newImage[i].append(1)
            if(image1[i][j] == 0) and (image2[i][j] == 1):
                onesImg2 = onesImg2 + 1
                newImage[i].append(2)
            if(image1[i][j] == 1) and (image2[i][j] == 1):
                bothOnes = bothOnes + 1
                newImage[i].append(3)
    
    # Exportamos a txt
    report = open("results\\ex-06\\overlap-" + str(imageName1) + "-" + str(imageName2) + ".txt", 'w')
    for i in range(height1):
        report.write(str(newImage[i]))
        report.write("\n")
    report.close()
    
    return newImage, zeros, onesImg1, onesImg2, bothOnes

#%% Función para exportar como imagen los resultados del ejercicio 6
def exportImg_ej6(image, height, width, imageName):
    
    # Primero se transforma image a un numpy array
    for i in range(height):
        for j in range(width):
            if(image[i][j] == 0):
                image[i][j] = [255,255,255]
            if(image[i][j] == 1):
                image[i][j] = [220,116,232]
            if(image[i][j] == 2):
                image[i][j] = [115,250,248]
            if(image[i][j] == 3):
                image[i][j] = [163,219,246]
    
    image = np.array(image)
    
    cv2.imwrite('results\\ex-06\\exercise-06-' + str(imageName) + '.jpeg', image)
    return

#%% Función para exportar como imagen los resultados del ejercicio 7
def exportImg_ej7(image, height, width, imageName):
    
    # Primero se transforma image a un numpy array
    for i in range(height):
        for j in range(width):
            if(image[i][j] == 0):
                image[i][j] = [255,255,255]
            if(image[i][j] == 1):
                image[i][j] = [3,189,7]
            if(image[i][j] == 2):
                image[i][j] = [149,56,242]
            if(image[i][j] == 3):
                image[i][j] = [131,120,188]
    
    image = np.array(image)
    
    cv2.imwrite('results\\ex-07\\exercise-07-' + str(imageName) + '.jpeg', image)
    return

#%% Función para el ejercicio 8: Trasladar y calcular los momentos centrales
def calcCentralMoment(image, height, width, x, y, p, q):
    m = 0
    for i in range(height):
        for j in range(width):
            m = m + (image[i][j] * ((x ** p) * (y ** q))) # Momento estándar
            m = m + (image[i][j] * ((abs(j + 1 - x) ** p) * (abs(i + 1 - y) ** q))) # Momento central
    return m