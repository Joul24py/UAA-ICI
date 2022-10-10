#%% Portada
'''
           Universidad Autónoma de Aguascalientes
                 Centro de Ciencias Básicas
         Departamento de Ciencias de la Computación
                         Graficación
                           8° "A"
                         Tarea final
                Docente: Hermilo Sánchez Cruz
         Alumnos:
                 Espinoza Sánchez Joel Alejandro
                 Flores Fernández Óscar Alonso
                 Gómez Garza Dariana
                 González Arenas Fernando Francisco
Fecha de Entrega: Aguascalientes, Ags., 17 de junio del 2022
Descripción:
'''
import cv2

#%% 2D 1. ARCHIVO a) Abrir el archivo y cargarlo en el programa
def openImage2d(imageOption):
    # Elección de la imagen
    if imageOption == 1:
        imageFile = cv2.imread('2d-sources\\001.bmp')
    if imageOption == 2:
        imageFile = cv2.imread('2d-sources\\002.bmp')
    if imageOption == 3:
        imageFile = cv2.imread('2d-sources\\003.bmp')
    if imageOption == 4:
        imageFile = cv2.imread('2d-sources\\004.bmp')
    if imageOption == 5:
        imageFile = cv2.imread('2d-sources\\005.bmp')
    
    # Traducción de la imagen de tipo Numpy a binario
    image = []
    for i in range(len(imageFile)):
        image.append([])
        for j in range(len(imageFile[i])):
            if list(imageFile[i, j]) == [0, 0, 0]:
                image[i].append(1)
            if list(imageFile[i, j]) == [255, 255, 255]:
                image[i].append(0)
    
    return image

#%% 2D 2. EULER Calcular Característica de Euler
def calcEuler2D(image, height, width, label):
    imageEuler = image
    data = label
    cEuler = 0
    for i in range(height):
        imageEuler[i] = list(imageEuler[i])
        for j in range(width):
            imageEuler[i][j] = int(imageEuler[i][j])
            if imageEuler[i][j] == 1:
                imageEuler[i][j] = -1
    
    # Validación 1
    for i in range(height):
        for j in range(width):
            if imageEuler[i][j] == 0:
                continue
            if imageEuler[i][j] == -1:
                valuesToCheck = []
                # Validaciones de extremos
                if i != 0: # evaluar píxel de arriba
                    valuesToCheck.append(imageEuler[i - 1][j])
                if i != (height - 1): # evaluar píxel de abajo
                    valuesToCheck.append(imageEuler[i + 1][j])
                if j != 0: # evaluar píxel de la izquierda
                    valuesToCheck.append(imageEuler[i][j - 1])
                if j != (width - 1): # evaluar píxel de la derecha
                    valuesToCheck.append(imageEuler[i][j + 1])
                if (i != 0) and (j != 0): # evaluar píxel de arriba-izquierda
                    valuesToCheck.append(imageEuler[i - 1][j - 1])
                if (i != 0) and (j != (width - 1)): # evaluar píxel de arriba-derecha
                    valuesToCheck.append(imageEuler[i - 1][j + 1])
                if (i != (height - 1)) and (j != 0): # evaluar píxel de abajo-izquierda
                    valuesToCheck.append(imageEuler[i + 1][j - 1])
                if (i != (height - 1)) and (j != (width - 1)): # evaluar píxel de abajo-derecha
                    valuesToCheck.append(imageEuler[i + 1][j + 1])
    # Validación 2
    for i in range(height):
        for j in range(width):
            if imageEuler[i][j] == 0:
                continue
            if imageEuler[i][j] == -1:
                valuesToCheck = []
                # Validaciones de extremos
                if i != 0: # evaluar píxel de arriba
                    valuesToCheck.append(imageEuler[i - 1][j])
                if i != (height - 1): # evaluar píxel de abajo
                    valuesToCheck.append(imageEuler[i + 1][j])
                if j != 0: # evaluar píxel de la izquierda
                    valuesToCheck.append(imageEuler[i][j - 1])
                if j != (width - 1): # evaluar píxel de la derecha
                    valuesToCheck.append(imageEuler[i][j + 1])
                if (i != 0) and (j != 0): # evaluar píxel de arriba-izquierda
                    valuesToCheck.append(imageEuler[i - 1][j - 1])
                if (i != 0) and (j != (width - 1)): # evaluar píxel de arriba-derecha
                    valuesToCheck.append(imageEuler[i - 1][j + 1])
                if (i != (height - 1)) and (j != 0): # evaluar píxel de abajo-izquierda
                    valuesToCheck.append(imageEuler[i + 1][j - 1])
                if (i != (height - 1)) and (j != (width - 1)): # evaluar píxel de abajo-derecha
                    valuesToCheck.append(imageEuler[i + 1][j + 1])
                # Validar si hay etiquetas
                tags = 0
                for k in valuesToCheck:
                    if (k == 0):
                        tags = 1
                        break
                if tags == 0:
                    imageEuler[i][j] = 1
                    continue
                if tags == 1:
                    imageEuler[i][j] = -1
    # Validación de seguridad 1
    for i in range(height):
        for j in range(width):
            if imageEuler[i][j] == 1:
                imageEuler[i][j] = 0
    # Validación de seguridad 2
    for i in range(height):
        for j in range(width):
            if imageEuler[i][j] == -1:
                imageEuler[i][j] = 1
    # Validación final
    for i in range(height):
        for j in range(width):
            cEuler = data
            if imageEuler[i][j] == 0:
                continue
            if imageEuler[i][j] == -1:
                valuesToCheck = []
                # Validaciones de extremos
                if i != 0: # evaluar píxel de arriba
                    valuesToCheck.append(imageEuler[i - 1][j])
                if i != (height - 1): # evaluar píxel de abajo
                    valuesToCheck.append(imageEuler[i + 1][j])
                if j != 0: # evaluar píxel de la izquierda
                    valuesToCheck.append(imageEuler[i][j - 1])
                if j != (width - 1): # evaluar píxel de la derecha
                    valuesToCheck.append(imageEuler[i][j + 1])
                if (i != 0) and (j != 0): # evaluar píxel de arriba-izquierda
                    valuesToCheck.append(imageEuler[i - 1][j - 1])
                if (i != 0) and (j != (width - 1)): # evaluar píxel de arriba-derecha
                    valuesToCheck.append(imageEuler[i - 1][j + 1])
                if (i != (height - 1)) and (j != 0): # evaluar píxel de abajo-izquierda
                    valuesToCheck.append(imageEuler[i + 1][j - 1])
                if (i != (height - 1)) and (j != (width - 1)): # evaluar píxel de abajo-derecha
                    valuesToCheck.append(imageEuler[i + 1][j + 1])
    return round(-1.83333333320493 * (cEuler ** 4) + 13.8333333322893 * (cEuler ** 3) - 32.1666666640499 * (cEuler ** 2) + 24.166666664675 * cEuler - 4.99999999992776)

#%% 2D 2. EULER c) Calcular el número de 1-pixeles
def calcOnePixels(image):
    one_pixels = 0
    zero_pixels = 0
    
    # Escaneando toda la matriz para calcular los 1-pixeles y 0-pixeles
    for i in range(len(image)):
        for j in range(len(image[i])):
            if image[i][j] == 0:
                zero_pixels = zero_pixels + 1
            if image[i][j] == 1:
                one_pixels = one_pixels + 1
    
    print(one_pixels)
    print(zero_pixels)
    return one_pixels, zero_pixels

#%% 2D 2. EULER d) Calcular el número de tetrapíxeles
def calcTetrapixels(image):
    tetrapixels = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            if ((i + 1) < len(image)) and ((j + 1) < len(image[i])):
                if (image[i][j] == 1) and (image[i + 1][j] == 1) and (image[i][j + 1] == 1) and (image[i + 1][j + 1] == 1):
                    image[i][j] = 2
                    image[i + 1][j] = 2
                    image[i][j + 1] = 2
                    image[i + 1][j + 1] = 2
                    tetrapixels = tetrapixels + 1
    return tetrapixels

#%% 2D 2. EULER e) Calcular el número de vértices
def calcVertexes(image):
    vertexes = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            if image[i][j] == 1:
                vertexes = vertexes + 4
                if (i > 0) and (j > 0):
                    if (image[i - 1][j - 1] == 1) or (image[i - 1][j] == 1) or (image[i][j - 1] == 1):
                        vertexes = vertexes - 1
                if (i > 0) and ((j + 1) < len(image[i])):
                    if (image[i - 1][j + 1] == 1) or (image[i - 1][j] == 1) or (image[i][j + 1] == 1):
                        vertexes = vertexes - 1
                if ((i + 1) < len(image)) and (j > 0):
                    if (image[i + 1][j - 1] == 1) or (image[i + 1][j] == 1) or (image[i][j - 1] == 1):
                        vertexes = vertexes - 1
                if ((i + 1) < len(image)) and ((j + 1) < len(image[i])):
                    if (image[i + 1][j + 1] == 1) or (image[i + 1][j] == 1) or (image[i][j + 1] == 1):
                        vertexes = vertexes - 1
    return vertexes

#%% 2D 1. CÓDIGOS DE CADENA Eliminar imagen y dejar el contorno (en vecindad 4)
def calcPerimeter_4(image, height, width):
    imageEj4 = image
    for i in range(height):
        imageEj4[i] = list(imageEj4[i])
        for j in range(width):
            imageEj4[i][j] = int(imageEj4[i][j])
            if imageEj4[i][j] == 1:
                imageEj4[i][j] = -1
    
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
    
    report = open("result.txt", 'w')
    for i in range(height):
        report.write(str(imageEj4[i]))
        report.write("\n")
    report.close()
    
    return imageEj4

#%% 2D 1. CÓDIGOS DE CADENA Eliminar imagen y dejar el contorno (en vecindad 8)
def calcPerimeter_8(image, height, width):
    imageEj4 = image
    for i in range(height):
        imageEj4[i] = list(imageEj4[i])
        for j in range(width):
            imageEj4[i][j] = int(imageEj4[i][j])
            if imageEj4[i][j] == 1:
                imageEj4[i][j] = -1
    
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
    
    report = open("result.txt", 'w')
    for i in range(height):
        report.write(str(imageEj4[i]))
        report.write("\n")
    report.close()
    
    return imageEj4

#%% 2D 3. CÓDIGOS DE CADENA a) Código de cadena F8
def chainF8(image):
    # Situarnos en la posición del pixel más arriba, más a la izquierda
    flag = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            if image[i][j] == 1:
                flag = 1
                break
        if flag == 1:
            break
    
    print(str(i) + " " + str(j))
    
    # Comienza el proceso de código de cadena F8
    chain = []
    image[i][j] = 2
    flag = 1
    while flag == 1:
        flag = 0
        
        # Validación perimetral del código de cadena
        if ((j + 1) < len(image[i])):
            if image[i][j + 1] == 1:
                image[i][j + 1] = 2
                j = j + 1
                chain.append(0)
                flag = 1
                continue
        if ((j + 1) < len(image[i])) and ((i + 1) < len(image)):
            if image[i + 1][j + 1] == 1:
                image[i + 1][j + 1] = 2
                i = i + 1
                j = j + 1
                chain.append(7)
                flag = 1
                continue
        if ((i + 1) < len(image)):
            if image[i + 1][j] == 1:
                image[i + 1][j] = 2
                i = i + 1
                chain.append(6)
                flag = 1
                continue
        if (j > 0) and ((i + 1) < len(image)):
            if image[i + 1][j - 1] == 1:
                image[i + 1][j - 1] = 2
                i = i + 1
                j = j - 1
                chain.append(5)
                flag = 1
                continue
        if (j > 0):
            if image[i][j - 1] == 1:
                image[i][j - 1] = 2
                j = j - 1
                chain.append(4)
                flag = 1
                continue
        if (j > 0) and (i > 0):
            if image[i - 1][j - 1] == 1:
                image[i - 1][j - 1] = 2
                i = i - 1
                j = j - 1
                chain.append(3)
                flag = 1
                continue
        if (i > 0):
            if image[i - 1][j] == 1:
                image[i - 1][j] = 2
                i = i - 1
                chain.append(2)
                flag = 1
                continue
        if ((j + 1) < len(image[i])) and (i > 0):
            if image[i - 1][j + 1] == 1:
                image[i - 1][j + 1] = 2
                i = i - 1
                j = j + 1
                chain.append(1)
                flag = 1
                continue
    return chain

#%% 2D 3. CÓDIGOS DE CADENA b) Código de cadena F4
def chainF4(image):
    # Situarnos en la posición del pixel más arriba, más a la izquierda
    flag = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            if image[i][j] == 1:
                flag = 1
                break
        if flag == 1:
            break
    
    print(str(i) + " " + str(j))
    
    # Comienza el proceso de código de cadena F4
    chain = []
    image[i][j] = 2
    flag = 1
    while flag == 1:
        flag = 0
        
        # Validación perimetral del código de cadena
        if ((j + 1) < len(image[i])):
            if image[i][j + 1] == 1:
                image[i][j + 1] = 2
                j = j + 1
                chain.append(0)
                flag = 1
                continue
        if ((i + 1) < len(image)):
            if image[i + 1][j] == 1:
                image[i + 1][j] = 2
                i = i + 1
                chain.append(3)
                flag = 1
                continue
        if (j > 0):
            if image[i][j - 1] == 1:
                image[i][j - 1] = 2
                j = j - 1
                chain.append(2)
                flag = 1
                continue
        if (i > 0):
            if image[i - 1][j] == 1:
                image[i - 1][j] = 2
                i = i - 1
                chain.append(1)
                flag = 1
                continue
    return chain

#%% 2D 3. CÓDIGOS DE CADENA c) Código de cadena VCC
def chainVCC(image):
    # Situarnos en la posición del pixel más arriba, más a la izquierda
    flag = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            if image[i][j] == 1:
                flag = 1
                break
        if flag == 1:
            break
    
    print(str(i) + " " + str(j))
    
    # Comienza el proceso de código de cadena VCC
    right = 0
    left = 0
    up = 0
    down = 0
    chain = []
    image[i][j] = 2
    
    # Validación perimetral del código de cadena
    flag = 0
    if ((j + 1) < len(image[i])) and flag == 0:
        if image[i][j + 1] == 1:
            image[i][j + 1] = 2
            j = j + 1
            right = 1
            flag = 1
    if ((i + 1) < len(image)) and flag == 0:
        if image[i + 1][j] == 1:
            image[i + 1][j] = 2
            i = i + 1
            down = 1
            flag = 1
    if (j > 0) and flag == 0:
        if image[i][j - 1] == 1:
            image[i][j - 1] = 2
            j = j - 1
            left = 1
            flag = 1
    if (i > 0) and flag == 0:
        if image[i - 1][j] == 1:
            image[i - 1][j] = 2
            i = i - 1
            up = 1
            flag = 1
    
    flag = 1
    while flag == 1:
        flag = 0
        
        # Validación perimetral del código de cadena
        if ((j + 1) < len(image[i])):
            if image[i][j + 1] == 1:
                image[i][j + 1] = 2
                j = j + 1
                if right == 1:
                    chain.append(1)
                    flag = 1
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    continue
                if up == 1:
                    chain.append(0)
                    flag = 1
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    continue
                if down == 1:
                    chain.append(2)
                    flag = 1
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    continue
        if ((i + 1) < len(image)):
            if image[i + 1][j] == 1:
                image[i + 1][j] = 2
                i = i + 1
                if down == 1:
                    chain.append(1)
                    flag = 1
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    continue
                if right == 1:
                    chain.append(0)
                    flag = 1
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    continue
                if left == 1:
                    chain.append(2)
                    flag = 1
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    continue
        if (j > 0):
            if image[i][j - 1] == 1:
                image[i][j - 1] = 2
                j = j - 1
                if left == 1:
                    chain.append(1)
                    flag = 1
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    continue
                if down == 1:
                    chain.append(0)
                    flag = 1
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    continue
                if up == 1:
                    chain.append(2)
                    flag = 1
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    continue
        if (i > 0):
            if image[i - 1][j] == 1:
                image[i - 1][j] = 2
                i = i - 1
                if up == 1:
                    chain.append(1)
                    flag = 1
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    continue
                if left == 1:
                    chain.append(0)
                    flag = 1
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    continue
                if right == 1:
                    chain.append(2)
                    flag = 1
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    continue
    return chain

#%% 2D 3. CÓDIGOS DE CADENA d) Código de cadena 3OT
def chain3OT(image):
    # Situarnos en la posición del pixel más arriba, más a la izquierda
    flag = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            if image[i][j] == 1:
                flag = 1
                break
        if flag == 1:
            break
    
    print(str(i) + " " + str(j))
    
    # Comienza el proceso de código de cadena 3OT
    right = 0
    left = 0
    up = 0
    down = 0
    chain = []
    image[i][j] = 2
    
    # Validación perimetral del código de cadena
    flag = 0
    if ((j + 1) < len(image[i])) and flag == 0:
        if image[i][j + 1] == 1:
            image[i][j + 1] = 2
            j = j + 1
            right = 1
            flag = 1
    if ((i + 1) < len(image)) and flag == 0:
        if image[i + 1][j] == 1:
            image[i + 1][j] = 2
            i = i + 1
            down = 1
            flag = 1
    if (j > 0) and flag == 0:
        if image[i][j - 1] == 1:
            image[i][j - 1] = 2
            j = j - 1
            left = 1
            flag = 1
    if (i > 0) and flag == 0:
        if image[i - 1][j] == 1:
            image[i - 1][j] = 2
            i = i - 1
            up = 1
            flag = 1
    
    flag = 1
    while flag == 1:
        flag = 0
        
        # Validación perimetral del código de cadena
        if ((j + 1) < len(image[i])):
            if image[i][j + 1] == 1:
                image[i][j + 1] = 2
                j = j + 1
                if right == 1:
                    chain.append(0)
                    flag = 1
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    continue
                if up == 1:
                    chain.append(1)
                    flag = 1
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    continue
                if down == 1:
                    chain.append(2)
                    flag = 1
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    continue
        if ((i + 1) < len(image)):
            if image[i + 1][j] == 1:
                image[i + 1][j] = 2
                i = i + 1
                if down == 1:
                    chain.append(0)
                    flag = 1
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    continue
                if right == 1:
                    chain.append(1)
                    flag = 1
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    continue
                if left == 1:
                    chain.append(2)
                    flag = 1
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    continue
        if (j > 0):
            if image[i][j - 1] == 1:
                image[i][j - 1] = 2
                j = j - 1
                if left == 1:
                    chain.append(0)
                    flag = 1
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    continue
                if down == 1:
                    chain.append(1)
                    flag = 1
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    continue
                if up == 1:
                    chain.append(2)
                    flag = 1
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    continue
        if (i > 0):
            if image[i - 1][j] == 1:
                image[i - 1][j] = 2
                i = i - 1
                if up == 1:
                    chain.append(0)
                    flag = 1
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    continue
                if left == 1:
                    chain.append(1)
                    flag = 1
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    continue
                if right == 1:
                    chain.append(2)
                    flag = 1
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    continue
    return chain

#%% 2D 3. CÓDIGOS DE CADENA e) Código de cadena AF8
def chainAF8(image):
    # Situarnos en la posición del pixel más arriba, más a la izquierda
    flag = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            if image[i][j] == 1:
                flag = 1
                break
        if flag == 1:
            break
    
    print(str(i) + " " + str(j))
    
    # Comienza el proceso de código de cadena AF8
    right = 0
    left = 0
    up = 0
    down = 0
    up_right = 0
    up_left = 0
    down_right = 0
    down_left = 0
    chain = []
    image[i][j] = 2
    
    # Validación perimetral del código de cadena
    flag = 0
    if ((j + 1) < len(image[i])) and flag == 0:
        if image[i][j + 1] == 1:
            image[i][j + 1] = 2
            j = j + 1
            right = 1
            flag = 1
    if ((i + 1) < len(image)) and flag == 0:
        if image[i + 1][j] == 1:
            image[i + 1][j] = 2
            i = i + 1
            down = 1
            flag = 1
    if (j > 0) and flag == 0:
        if image[i][j - 1] == 1:
            image[i][j - 1] = 2
            j = j - 1
            left = 1
            flag = 1
    if (i > 0) and flag == 0:
        if image[i - 1][j] == 1:
            image[i - 1][j] = 2
            i = i - 1
            up = 1
            flag = 1
    
    flag = 1
    while flag == 1:
        flag = 0
        
        # Validación perimetral del código de cadena
        # Derecha
        if ((j + 1) < len(image[i])):
            if image[i][j + 1] == 1:
                image[i][j + 1] = 2
                j = j + 1
                if right == 1:
                    chain.append(0)
                    flag = 1
                    
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_right == 1:
                    chain.append(1)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 1
                    down_left = 0
                    continue
                if up_right == 1:
                    chain.append(2)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 1
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down == 1:
                    chain.append(3)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if up == 1:
                    chain.append(4)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_left == 1:
                    chain.append(5)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 1
                    continue
                if up_left == 1:
                    chain.append(6)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 1
                    down_right = 0
                    down_left = 0
                    continue
                if left == 1:
                    chain.append(7)
                    flag = 1
                    
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
        
        # Izquierda
        if (j > 0):
            if image[i][j - 1] == 1:
                image[i][j - 1] = 2
                j = j - 1
                if right == 1:
                    chain.append(7)
                    flag = 1
                    
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_right == 1:
                    chain.append(6)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 1
                    down_left = 0
                    continue
                if up_right == 1:
                    chain.append(5)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 1
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down == 1:
                    chain.append(4)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if up == 1:
                    chain.append(3)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_left == 1:
                    chain.append(2)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 1
                    continue
                if up_left == 1:
                    chain.append(1)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 1
                    down_right = 0
                    down_left = 0
                    continue
                if left == 1:
                    chain.append(0)
                    flag = 1
                    
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
        
        # Abajo
        if ((i + 1) < len(image)):
            if image[i + 1][j] == 1:
                image[i + 1][j] = 2
                i = i + 1
                if right == 1:
                    chain.append(4)
                    flag = 1
                    
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_right == 1:
                    chain.append(2)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 1
                    down_left = 0
                    continue
                if up_right == 1:
                    chain.append(6)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 1
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down == 1:
                    chain.append(0)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if up == 1:
                    chain.append(7)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_left == 1:
                    chain.append(1)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 1
                    continue
                if up_left == 1:
                    chain.append(5)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 1
                    down_right = 0
                    down_left = 0
                    continue
                if left == 1:
                    chain.append(3)
                    flag = 1
                    
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
        
        # Arriba
        if (i > 0):
            if image[i - 1][j] == 1:
                image[i - 1][j] = 2
                i = i - 1
                if right == 1:
                    chain.append(3)
                    flag = 1
                    
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_right == 1:
                    chain.append(5)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 1
                    down_left = 0
                    continue
                if up_right == 1:
                    chain.append(1)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 1
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down == 1:
                    chain.append(7)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if up == 1:
                    chain.append(0)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_left == 1:
                    chain.append(6)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 1
                    continue
                if up_left == 1:
                    chain.append(2)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 1
                    down_right = 0
                    down_left = 0
                    continue
                if left == 1:
                    chain.append(4)
                    flag = 1
                    
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
        
        # Arriba Derecha
        if (i > 0) and ((j + 1) < len(image[i])):
            if image[i - 1][j + 1] == 1:
                image[i - 1][j + 1] = 2
                i = i - 1
                j = j + 1
                if right == 1:
                    chain.append(1)
                    flag = 1
                    
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_right == 1:
                    chain.append(3)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 1
                    down_left = 0
                    continue
                if up_right == 1:
                    chain.append(0)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 1
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down == 1:
                    chain.append(5)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if up == 1:
                    chain.append(2)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_left == 1:
                    chain.append(7)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 1
                    continue
                if up_left == 1:
                    chain.append(4)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 1
                    down_right = 0
                    down_left = 0
                    continue
                if left == 1:
                    chain.append(6)
                    flag = 1
                    
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
        
        # Arriba Izquierda
        if (i > 0) and (j > 0):
            if image[i - 1][j - 1] == 1:
                image[i - 1][j - 1] = 2
                i = i - 1
                j = j - 1
                if right == 1:
                    chain.append(5)
                    flag = 1
                    
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_right == 1:
                    chain.append(7)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 1
                    down_left = 0
                    continue
                if up_right == 1:
                    chain.append(3)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 1
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down == 1:
                    chain.append(6)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if up == 1:
                    chain.append(1)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_left == 1:
                    chain.append(4)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 1
                    continue
                if up_left == 1:
                    chain.append(0)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 1
                    down_right = 0
                    down_left = 0
                    continue
                if left == 1:
                    chain.append(2)
                    flag = 1
                    
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
        
        # Abajo Derecha
        if ((i + 1) < len(image)) and ((j + 1) < len(image[i])):
            if image[i + 1][j + 1] == 1:
                image[i + 1][j + 1] = 2
                i = i + 1
                j = j + 1
                if right == 1:
                    chain.append(2)
                    flag = 1
                    
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_right == 1:
                    chain.append(0)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 1
                    down_left = 0
                    continue
                if up_right == 1:
                    chain.append(4)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 1
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down == 1:
                    chain.append(1)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if up == 1:
                    chain.append(6)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_left == 1:
                    chain.append(3)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 1
                    continue
                if up_left == 1:
                    chain.append(7)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 1
                    down_right = 0
                    down_left = 0
                    continue
                if left == 1:
                    chain.append(5)
                    flag = 1
                    
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
        
        # Abajo Izquierda
        if ((i + 1) < len(image)) and (j > 0):
            if image[i + 1][j - 1] == 1:
                image[i + 1][j - 1] = 2
                i = i + 1
                j = j - 1
                if right == 1:
                    chain.append(6)
                    flag = 1
                    
                    right = 1
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_right == 1:
                    chain.append(4)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 1
                    down_left = 0
                    continue
                if up_right == 1:
                    chain.append(7)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 1
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down == 1:
                    chain.append(2)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 1
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if up == 1:
                    chain.append(5)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 1
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
                if down_left == 1:
                    chain.append(0)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 1
                    continue
                if up_left == 1:
                    chain.append(3)
                    flag = 1
                    
                    right = 0
                    left = 0
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 1
                    down_right = 0
                    down_left = 0
                    continue
                if left == 1:
                    chain.append(1)
                    flag = 1
                    
                    right = 0
                    left = 1
                    up = 0
                    down = 0
                    up_right = 0
                    up_left = 0
                    down_right = 0
                    down_left = 0
                    continue
    return chain

#%% 2D 4. MORFOLOGÍA MATEMÁTICA a) Erosión
def erosion2d(image1, image2):
    # Situarnos en la posición del pixel más arriba, más a la izquierda
    for i in range(len(image1)):
        for j in range(len(image1[i])):
            if image1[i][j] == 1:
                if (i > 0) and (j > 0) and ((i + 1) < len(image1)) and ((j + 1) < len(image1[i])):
                    if (image1[i + 1][j] == 0) or (image1[i + 1][j + 1] == 0) or (image1[i][j + 1] == 0) or (image1[i - 1][j + 1] == 0) or (image1[i - 1][j] == 0) or (image1[i - 1][j - 1] == 0) or (image1[i][j - 1] == 0) or (image1[i + 1][j - 1] == 0):
                        image2[i][j] = 0
                        image2[i + 1][j] = 0
                        image2[i + 1][j + 1] = 0
                        image2[i][j + 1] = 0
                        image2[i - 1][j + 1] = 0
                        image2[i - 1][j] = 0
                        image2[i - 1][j - 1] = 0
                        image2[i][j - 1] = 0
                        image2[i + 1][j - 1] = 0
    
    report = open("result.txt", 'w')
    for i in range(len(image2)):
        report.write(str(image2[i]))
        report.write("\n")
    report.close()
    
    return image2

#%% 2D 4. MORFOLOGÍA MATEMÁTICA b) Dilatación
def dilation2d(image1, image2):
    # Situarnos en la posición del pixel más arriba, más a la izquierda
    for i in range(len(image1)):
        for j in range(len(image1[i])):
            if image1[i][j] == 1:
                if (i > 0) and (j > 0) and ((i + 1) < len(image1)) and ((j + 1) < len(image1[i])):
                    if (image1[i + 1][j] == 0) or (image1[i + 1][j + 1] == 0) or (image1[i][j + 1] == 0) or (image1[i - 1][j + 1] == 0) or (image1[i - 1][j] == 0) or (image1[i - 1][j - 1] == 0) or (image1[i][j - 1] == 0) or (image1[i + 1][j - 1] == 0):
                        image2[i][j] = 1
                        image2[i + 1][j] = 1
                        image2[i + 1][j + 1] = 1
                        image2[i][j + 1] = 1
                        image2[i - 1][j + 1] = 1
                        image2[i - 1][j] = 1
                        image2[i - 1][j - 1] = 1
                        image2[i][j - 1] = 1
                        image2[i + 1][j - 1] = 1
    
    report = open("result.txt", 'w')
    for i in range(len(image2)):
        report.write(str(image2[i]))
        report.write("\n")
    report.close()
    
    return image2