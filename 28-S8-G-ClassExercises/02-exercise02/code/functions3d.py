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

#%% 3D 1. ARCHIVO a) Abrir el archivo y cargarlo en el programa
def openImage3d(imageOption):
    # Elección de la imagen
    if imageOption == 6:
        imageFile = open('3d-sources\\armadillo.txt')
    if imageOption == 7:
        imageFile = open('3d-sources\\bunny.txt')
    if imageOption == 8:
        imageFile = open('3d-sources\\dragon.txt')
    if imageOption == 9:
        imageFile = open('3d-sources\\drill.txt')
    if imageOption == 10:
        imageFile = open('3d-sources\\happy.txt')
    
    # Carga de la imagen al programa
    image = []
    rowSkipper = 0
    j = 0
    for i in imageFile:
        if rowSkipper >= 5:
            if j == 0:
                image.append([])
            image[-1].append(i[0:256])
            if j == 255:
                j = 0
            else: j = j + 1
        rowSkipper = rowSkipper + 1
    
    return image

#%% 3D 2. EULER a) Característica de Euler (calcular el número de caras)
def calcFaces3d(image):
    faces = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            for k in range(len(image[i][j])):
                if image[i][j][k] == '0':
                    continue
                if image[i][j][k] == '1':
                    faces = faces + 6
                    if i > 0:
                        if image[i - 1][j][k] == '1':
                            faces = faces - 1
                    if (i + 1) < len(image):
                        if image[i + 1][j][k] == '1':
                            faces = faces - 1
                    if j > 0:
                        if image[i][j - 1][k] == '1':
                            faces = faces - 1
                    if (j + 1) < len(image[i]):
                        if image[i][j + 1][k] == '1':
                            faces = faces - 1
                    if k > 0:
                        if image[i][j][k - 1] == '1':
                            faces = faces - 1
                    if (k + 1) < len(image[i][j]):
                        if image[i][j][k + 1] == '1':
                            faces = faces - 1
    return faces

#%% 3D 2. EULER a) Característica de Euler (calcular el número de vértices)
def calcVertexes3d(image):
    vertexes = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            image[i][j] = list(image[i][j])
            for k in range(len(image[i][j])):
                if image[i][j][k] == '0':
                    continue
                if image[i][j][k] == '1':
                    image[i][j][k] = '2'
                    vertexes = vertexes + 8
                    if (i > 0) and (j > 0) and (k > 0):
                        if (image[i - 1][j][k] == '2') or (image[i][j - 1][k] == '2') or (image[i][j][k - 1] == '2'):
                            vertexes = vertexes - 1
                    if (i > 0) and (j > 0) and ((k + 1) < len(image[i][j])):
                        if (image[i - 1][j][k] == '2') or (image[i][j - 1][k] == '2') or (image[i][j][k + 1] == '2'):
                            vertexes = vertexes - 1
                    if (i > 0) and ((j + 1) < len(image[i])) and (k > 0):
                        if (image[i - 1][j][k] == '2') or (image[i][j + 1][k] == '2') or (image[i][j][k - 1] == '2'):
                            vertexes = vertexes - 1
                    if (i > 0) and ((j + 1) < len(image[i])) and ((k + 1) < len(image[i][j])):
                        if (image[i - 1][j][k] == '2') or (image[i][j + 1][k] == '2') or (image[i][j][k + 1] == '2'):
                            vertexes = vertexes - 1
                    if ((i + 1) < len(image)) and (j > 0) and (k > 0):
                        if (image[i + 1][j][k] == '2') or (image[i][j - 1][k] == '2') or (image[i][j][k - 1] == '2'):
                            vertexes = vertexes - 1
                    if ((i + 1) < len(image)) and (j > 0) and ((k + 1) < len(image[i][j])):
                        if (image[i + 1][j][k] == '2') or (image[i][j - 1][k] == '2') or (image[i][j][k + 1] == '2'):
                            vertexes = vertexes - 1
                    if ((i + 1) < len(image)) and ((j + 1) < len(image[i])) and (k > 0):
                        if (image[i + 1][j][k] == '2') or (image[i][j + 1][k] == '2') or (image[i][j][k - 1] == '2'):
                            vertexes = vertexes - 1
                    if ((i + 1) < len(image)) and ((j + 1) < len(image[i])) and ((k + 1) < len(image[i][j])):
                        if (image[i + 1][j][k] == '2') or (image[i][j + 1][k] == '2') or (image[i][j][k + 1] == '2'):
                            vertexes = vertexes - 1
    return vertexes

#%% 3D 2. EULER a) Característica de Euler (calcular el número de aristas)
def calcEdges3d(image):
    edges = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            image[i][j] = list(image[i][j])
            for k in range(len(image[i][j])):
                if image[i][j][k] == '0':
                    continue
                if image[i][j][k] == '1':
                    image[i][j][k] = '2'
                    edges = edges + 12
                    if (i > 0) and (j > 0):
                        if (image[i - 1][j][k] == '2') or (image[i][j - 1][k] == '2'):
                            edges = edges - 1
                    if (i > 0) and (k > 0):
                        if (image[i - 1][j][k] == '2') or (image[i][j][k - 1] == '2'):
                            edges = edges - 1
                    if (i > 0) and ((j + 1) < len(image[i])):
                        if (image[i - 1][j][k] == '2') or (image[i][j + 1][k] == '2'):
                            edges = edges - 1
                    if (i > 0) and ((k + 1) < len(image[i][j])):
                        if (image[i - 1][j][k] == '2') or (image[i][j][k + 1] == '2'):
                            edges = edges - 1
                    if ((i + 1) < len(image)) and (j > 0):
                        if (image[i + 1][j][k] == '2') or (image[i][j - 1][k] == '2'):
                            edges = edges - 1
                    if ((i + 1) < len(image)) and (k > 0):
                        if (image[i + 1][j][k] == '2') or (image[i][j][k - 1] == '2'):
                            edges = edges - 1
                    if ((i + 1) < len(image)) and ((j + 1) < len(image[i])):
                        if (image[i + 1][j][k] == '2') or (image[i][j + 1][k] == '2'):
                            edges = edges - 1
                    if ((i + 1) < len(image)) and ((k + 1) < len(image[i][j])):
                        if (image[i + 1][j][k] == '2') or (image[i][j][k + 1] == '2'):
                            edges = edges - 1
                    if (j > 0) and (k > 0):
                        if (image[i][j - 1][k] == '2') or (image[i][j][k - 1] == '2'):
                            edges = edges - 1
                    if (j > 0) and ((k + 1) < len(image[i][j])):
                        if (image[i][j - 1][k] == '2') or (image[i][j][k + 1] == '2'):
                            edges = edges - 1
                    if ((j + 1) < len(image[i])) and (k > 0):
                        if (image[i][j + 1][k] == '2') or (image[i][j][k - 1] == '2'):
                            edges = edges - 1
                    if ((j + 1) < len(image[i])) and ((k + 1) < len(image[i][j])):
                        if (image[i][j + 1][k] == '2') or (image[i][j][k + 1] == '2'):
                            edges = edges - 1
    return edges

#%% 3D 2. EULER a) Calcular la característica de Euler (superficie visible)
def calcSurface(image):
    faces = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            for k in range(len(image[i][j])):
                if image[i][j][k] == '0':
                    continue
                if image[i][j][k] == '1':
                    # Validación para todas las capas que no son los extremos
                    if i > 0:
                        if image[i - 1][j][k] == '0':
                            faces = faces + 1
                    if (i + 1) < len(image):
                        if image[i + 1][j][k] == '0':
                            faces = faces + 1
                    if j > 0:
                        if image[i][j - 1][k] == '0':
                            faces = faces + 1
                    if (j + 1) < len(image[i]):
                        if image[i][j + 1][k] == '0':
                            faces = faces + 1
                    if k > 0:
                        if image[i][j][k - 1] == '0':
                            faces = faces + 1
                    if (k + 1) < len(image[i][j]):
                        if image[i][j][k + 1] == '0':
                            faces = faces + 1
                    # Validación para todas las capas que son los extremos
                    if i == 0:
                        faces = faces + 1
                    if (i + 1) == len(image):
                        faces = faces + 1
                    if j == 0:
                        faces = faces + 1
                    if (j + 1) == len(image[i]):
                        faces = faces + 1
                    if k == 0:
                        faces = faces + 1
                    if (k + 1) == len(image[i][j]):
                        faces = faces + 1
    return faces

#%% 3D 2. EULER b) Calcular túneles
def calcTunnels(image, tunels):
    # Validación en dimensión 1
    tunnels = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            image[i][j] = list(image[i][j])
            for k in range(len(image[i][j])):
                if image[i][j][k] == '0':
                    continue
                if image[i][j][k] == '1':
                    image[i][j][k] = '2'
                    tunnels = tunnels + 9
                    if (i > 0) and (j > 0):
                        if (image[i - 1][j][k] == '2') or (image[i][j - 1][k] == '2'):
                            tunnels = tunnels - 1
                    if (i > 0) and (k > 0):
                        if (image[i - 1][j][k] == '2') or (image[i][j][k - 1] == '2'):
                            tunnels = tunnels - 1
                    if (i > 0) and ((j + 1) < len(image[i])):
                        if (image[i - 1][j][k] == '2') or (image[i][j + 1][k] == '2'):
                            tunnels = tunnels - 1
                    if (i > 0) and ((k + 1) < len(image[i][j])):
                        if (image[i - 1][j][k] == '2') or (image[i][j][k + 1] == '2'):
                            tunnels = tunnels - 1
                    if ((i + 1) < len(image)) and (j > 0):
                        if (image[i + 1][j][k] == '2') or (image[i][j - 1][k] == '2'):
                            tunnels = tunnels - 1
                    if ((i + 1) < len(image)) and (k > 0):
                        if (image[i + 1][j][k] == '2') or (image[i][j][k - 1] == '2'):
                            tunnels = tunnels - 1
                    if ((i + 1) < len(image)) and ((j + 1) < len(image[i])):
                        if (image[i + 1][j][k] == '2') or (image[i][j + 1][k] == '2'):
                            tunnels = tunnels - 1
                    if ((i + 1) < len(image)) and ((k + 1) < len(image[i][j])):
                        if (image[i + 1][j][k] == '2') or (image[i][j][k + 1] == '2'):
                            tunnels = tunnels - 1
                    if (j > 0) and (k > 0):
                        if (image[i][j - 1][k] == '2') or (image[i][j][k - 1] == '2'):
                            tunnels = tunnels - 1
                    if (j > 0) and ((k + 1) < len(image[i][j])):
                        if (image[i][j - 1][k] == '2') or (image[i][j][k + 1] == '2'):
                            tunnels = tunnels - 1
                    if ((j + 1) < len(image[i])) and (k > 0):
                        if (image[i][j + 1][k] == '2') or (image[i][j][k - 1] == '2'):
                            tunnels = tunnels - 1
                    if ((j + 1) < len(image[i])) and ((k + 1) < len(image[i][j])):
                        if (image[i][j + 1][k] == '2') or (image[i][j][k + 1] == '2'):
                            tunnels = tunnels - 1
    
    # Validación en dimensión 2
    tunnels = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            image[i][j] = list(image[i][j])
            for k in range(len(image[i][j])):
                if image[i][j][k] == '0':
                    continue
                if image[i][j][k] == '1':
                    image[i][j][k] = '2'
                    tunnels = tunnels + 9
                    if (i > 0) and (j > 0):
                        if (image[i - 1][j][k] == '2') or (image[i][j - 1][k] == '2'):
                            tunnels = tunnels - 1
                    if (i > 0) and (k > 0):
                        if (image[i - 1][j][k] == '2') or (image[i][j][k - 1] == '2'):
                            tunnels = tunnels - 1
                    if (i > 0) and ((j + 1) < len(image[i])):
                        if (image[i - 1][j][k] == '2') or (image[i][j + 1][k] == '2'):
                            tunnels = tunnels - 1
                    if (i > 0) and ((k + 1) < len(image[i][j])):
                        if (image[i - 1][j][k] == '2') or (image[i][j][k + 1] == '2'):
                            tunnels = tunnels - 1
                    if ((i + 1) < len(image)) and (j > 0):
                        if (image[i + 1][j][k] == '2') or (image[i][j - 1][k] == '2'):
                            tunnels = tunnels - 1
                    if ((i + 1) < len(image)) and (k > 0):
                        if (image[i + 1][j][k] == '2') or (image[i][j][k - 1] == '2'):
                            tunnels = tunnels - 1
                    if ((i + 1) < len(image)) and ((j + 1) < len(image[i])):
                        if (image[i + 1][j][k] == '2') or (image[i][j + 1][k] == '2'):
                            tunnels = tunnels - 1
                    if ((i + 1) < len(image)) and ((k + 1) < len(image[i][j])):
                        if (image[i + 1][j][k] == '2') or (image[i][j][k + 1] == '2'):
                            tunnels = tunnels - 1
                    if (j > 0) and (k > 0):
                        if (image[i][j - 1][k] == '2') or (image[i][j][k - 1] == '2'):
                            tunnels = tunnels - 1
                    if (j > 0) and ((k + 1) < len(image[i][j])):
                        if (image[i][j - 1][k] == '2') or (image[i][j][k + 1] == '2'):
                            tunnels = tunnels - 1
                    if ((j + 1) < len(image[i])) and (k > 0):
                        if (image[i][j + 1][k] == '2') or (image[i][j][k - 1] == '2'):
                            tunnels = tunnels - 1
                    if ((j + 1) < len(image[i])) and ((k + 1) < len(image[i][j])):
                        if (image[i][j + 1][k] == '2') or (image[i][j][k + 1] == '2'):
                            tunnels = tunnels - 1
    
    # Validación en dimensión 3
    tunnels = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            image[i][j] = list(image[i][j])
            for k in range(len(image[i][j])):
                if image[i][j][k] == '0':
                    continue
                if image[i][j][k] == '1':
                    image[i][j][k] = '2'
                    tunnels = tunnels + 9
                    if (i > 0) and (j > 0):
                        if (image[i - 1][j][k] == '2') or (image[i][j - 1][k] == '2'):
                            tunnels = tunnels - 1
                    if (i > 0) and (k > 0):
                        if (image[i - 1][j][k] == '2') or (image[i][j][k - 1] == '2'):
                            tunnels = tunnels - 1
                    if (i > 0) and ((j + 1) < len(image[i])):
                        if (image[i - 1][j][k] == '2') or (image[i][j + 1][k] == '2'):
                            tunnels = tunnels - 1
                    if (i > 0) and ((k + 1) < len(image[i][j])):
                        if (image[i - 1][j][k] == '2') or (image[i][j][k + 1] == '2'):
                            tunnels = tunnels - 1
                    if ((i + 1) < len(image)) and (j > 0):
                        if (image[i + 1][j][k] == '2') or (image[i][j - 1][k] == '2'):
                            tunnels = tunnels - 1
                    if ((i + 1) < len(image)) and (k > 0):
                        if (image[i + 1][j][k] == '2') or (image[i][j][k - 1] == '2'):
                            tunnels = tunnels - 1
                    if ((i + 1) < len(image)) and ((j + 1) < len(image[i])):
                        if (image[i + 1][j][k] == '2') or (image[i][j + 1][k] == '2'):
                            tunnels = tunnels - 1
                    if ((i + 1) < len(image)) and ((k + 1) < len(image[i][j])):
                        if (image[i + 1][j][k] == '2') or (image[i][j][k + 1] == '2'):
                            tunnels = tunnels - 1
                    if (j > 0) and (k > 0):
                        if (image[i][j - 1][k] == '2') or (image[i][j][k - 1] == '2'):
                            tunnels = tunnels - 1
                    if (j > 0) and ((k + 1) < len(image[i][j])):
                        if (image[i][j - 1][k] == '2') or (image[i][j][k + 1] == '2'):
                            tunnels = tunnels - 1
                    if ((j + 1) < len(image[i])) and (k > 0):
                        if (image[i][j + 1][k] == '2') or (image[i][j][k - 1] == '2'):
                            tunnels = tunnels - 1
                    if ((j + 1) < len(image[i])) and ((k + 1) < len(image[i][j])):
                        if (image[i][j + 1][k] == '2') or (image[i][j][k + 1] == '2'):
                            tunnels = tunnels - 1
    
    return round(0.458333333304903*(tunels**4)-3.24999999976881*(tunels**3)+7.04166666608704*(tunels**2)-4.24999999955852*tunels-1.61218749988386*(10**(-11)))

#%% 3D 2. EULER c) Calcular el número de 1-voxeles
def calcOneVoxels(image):
    one_voxels = 0
    zero_voxels = 0
    
    # Escaneando toda la matriz para calcular los 1-voxeles y 0-voxeles
    for i in range(len(image)):
        for j in range(len(image[i])):
            for k in range(len(image[i][j])):
                if image[i][j][k] == '0':
                    zero_voxels = zero_voxels + 1
                if image[i][j][k] == '1':
                    one_voxels = one_voxels + 1
    
    return one_voxels, zero_voxels

#%% 3D 2. EULER d) Calcular el número de tetravoxeles
def calcTetravoxels(image):
    tetravoxels = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            image[i][j] = list(image[i][j])
            if ((j + 1) < len(image[i])):
                image[i][j + 1] = list(image[i][j + 1])
            for k in range(len(image[i][j])):
                if ((j + 1) < len(image[i])) and ((k + 1) < len(image[i][j])):
                    if (image[i][j][k] == '1') and (image[i][j + 1][k] == '1') and (image[i][j][k + 1] == '1') and (image[i][j + 1][k + 1] == '1'):
                        image[i][j][k] = '2'
                        image[i][j + 1][k] = '2'
                        image[i][j][k + 1] = '2'
                        image[i][j + 1][k + 1] = '2'
                        tetravoxels = tetravoxels + 1
    return tetravoxels

#%% 3D 2. EULER d) Calcular el número de octavoxeles
def calcOctavoxels(image):
    octavoxels = 0
    for i in range(len(image)):
        for j in range(len(image[i])):
            image[i][j] = list(image[i][j])
            if ((i + 1) < len(image)):
                image[i + 1][j] = list(image[i + 1][j])
            if ((j + 1) < len(image[i])):
                image[i][j + 1] = list(image[i][j + 1])
            if ((i + 1) < len(image)) and ((j + 1) < len(image[i])):
                image[i + 1][j + 1] = list(image[i + 1][j + 1])
            for k in range(len(image[i][j])):
                if ((i + 1) < len(image)) and ((j + 1) < len(image[i])) and ((k + 1) < len(image[i][j])):
                    if (image[i][j][k] == '1') and (image[i][j + 1][k] == '1') and (image[i][j][k + 1] == '1') and (image[i][j + 1][k + 1] == '1') and (image[i + 1][j][k] == '1') and (image[i + 1][j + 1][k] == '1') and (image[i + 1][j][k + 1] == '1') and (image[i + 1][j + 1][k + 1] == '1'):
                        image[i][j][k] = '2'
                        image[i][j + 1][k] = '2'
                        image[i][j][k + 1] = '2'
                        image[i][j + 1][k + 1] = '2'
                        image[i + 1][j][k] = '2'
                        image[i + 1][j + 1][k] = '2'
                        image[i + 1][j][k + 1] = '2'
                        image[i + 1][j + 1][k + 1] = '2'
                        octavoxels = octavoxels + 1
    return octavoxels

#%% 3D 4. MORFOLOGÍA MATEMÁTICA a) Erosión
def erosion3d(image1, image2):
    # Situarnos en la posición del pixel más arriba, más a la izquierda
    for i in range(len(image1)):
        for j in range(len(image1[i])):
            image1[i][j] = list(image1[i][j])
            image2[i][j] = list(image2[i][j])
            for k in range(len(image1[i][2])):
                image1[i][j][k] = int(image1[i][j][k])
                image2[i][j][k] = int(image2[i][j][k])
            if image1[i][j][k] == 1:
                if (i > 0) and (j > 0) and (k > 0) and ((i + 1) < len(image1)) and ((j + 1) < len(image1[i])) and ((k + 1) < len(image1[i][j])):
                    if (image1[i - 1][j - 1][k - 1] == 0) or (image1[i - 1][j - 1][k] == 0) or (image1[i - 1][j - 1][k + 1] == 0) or (image1[i - 1][j][k - 1] == 0) or (image1[i - 1][j][k] == 0) or (image1[i - 1][j][k + 1] == 0) or (image1[i - 1][j + 1][k - 1] == 0) or (image1[i - 1][j + 1][k] == 0) or (image1[i - 1][j + 1][k + 1] == 0) or (image1[i][j - 1][k - 1] == 0) or (image1[i][j - 1][k] == 0) or (image1[i][j - 1][k + 1] == 0) or (image1[i][j][k - 1] == 0) or (image1[i][j][k + 1] == 0) or (image1[i][j + 1][k - 1] == 0) or (image1[i][j + 1][k] == 0) or (image1[i][j + 1][k + 1] == 0) or (image1[i + 1][j - 1][k - 1] == 0) or (image1[i + 1][j - 1][k] == 0) or (image1[i + 1][j - 1][k + 1] == 0) or (image1[i + 1][j][k - 1] == 0) or (image1[i + 1][j][k] == 0) or (image1[i + 1][j][k + 1] == 0) or (image1[i + 1][j + 1][k - 1] == 0) or (image1[i + 1][j + 1][k] == 0) or (image1[i + 1][j + 1][k + 1] == 0):
                        image2[i][j][k] = 0
                        image1[i - 1][j - 1][k - 1] = 0
                        image1[i - 1][j - 1][k] = 0
                        image1[i - 1][j - 1][k + 1] = 0
                        image1[i - 1][j][k - 1] = 0
                        image1[i - 1][j][k] = 0
                        image1[i - 1][j][k + 1] = 0
                        image1[i - 1][j + 1][k - 1] = 0
                        image1[i - 1][j + 1][k] = 0
                        image1[i - 1][j + 1][k + 1] = 0
                        image1[i][j - 1][k - 1] = 0
                        image1[i][j - 1][k] = 0
                        image1[i][j - 1][k + 1] = 0
                        image1[i][j][k - 1] = 0
                        image1[i][j][k + 1] = 0
                        image1[i][j + 1][k - 1] = 0
                        image1[i][j + 1][k] = 0
                        image1[i][j + 1][k + 1] = 0
                        image1[i + 1][j - 1][k - 1] = 0
                        image1[i + 1][j - 1][k] = 0
                        image1[i + 1][j - 1][k + 1] = 0
                        image1[i + 1][j][k - 1] = 0
                        image1[i + 1][j][k] = 0
                        image1[i + 1][j][k + 1] = 0
                        image1[i + 1][j + 1][k - 1] = 0
                        image1[i + 1][j + 1][k] = 0
                        image1[i + 1][j + 1][k + 1] = 0
    
    report = open("result.txt", 'w')
    for i in range(len(image2)):
        report.write(str(image2[i]))
        report.write("\n")
    report.close()
    
    return image2

#%% 3D 4. MORFOLOGÍA MATEMÁTICA b) Dilatación
def dilation3d(image1, image2):
    # Situarnos en la posición del pixel más arriba, más a la izquierda
    for i in range(len(image1)):
        for j in range(len(image1[i])):
            image1[i][j] = list(image1[i][j])
            image2[i][j] = list(image2[i][j])
            for k in range(len(image1[i][2])):
                image1[i][j][k] = int(image1[i][j][k])
                image2[i][j][k] = int(image2[i][j][k])
            if image1[i][j][k] == 1:
                if (i > 0) and (j > 0) and (k > 0) and ((i + 1) < len(image1)) and ((j + 1) < len(image1[i])) and ((k + 1) < len(image1[i][j])):
                    if (image1[i - 1][j - 1][k - 1] == 0) or (image1[i - 1][j - 1][k] == 0) or (image1[i - 1][j - 1][k + 1] == 0) or (image1[i - 1][j][k - 1] == 0) or (image1[i - 1][j][k] == 0) or (image1[i - 1][j][k + 1] == 0) or (image1[i - 1][j + 1][k - 1] == 0) or (image1[i - 1][j + 1][k] == 0) or (image1[i - 1][j + 1][k + 1] == 0) or (image1[i][j - 1][k - 1] == 0) or (image1[i][j - 1][k] == 0) or (image1[i][j - 1][k + 1] == 0) or (image1[i][j][k - 1] == 0) or (image1[i][j][k + 1] == 0) or (image1[i][j + 1][k - 1] == 0) or (image1[i][j + 1][k] == 0) or (image1[i][j + 1][k + 1] == 0) or (image1[i + 1][j - 1][k - 1] == 0) or (image1[i + 1][j - 1][k] == 0) or (image1[i + 1][j - 1][k + 1] == 0) or (image1[i + 1][j][k - 1] == 0) or (image1[i + 1][j][k] == 0) or (image1[i + 1][j][k + 1] == 0) or (image1[i + 1][j + 1][k - 1] == 0) or (image1[i + 1][j + 1][k] == 0) or (image1[i + 1][j + 1][k + 1] == 0):
                        image2[i][j][k] = 1
                        image1[i - 1][j - 1][k - 1] = 1
                        image1[i - 1][j - 1][k] = 1
                        image1[i - 1][j - 1][k + 1] = 1
                        image1[i - 1][j][k - 1] = 1
                        image1[i - 1][j][k] = 1
                        image1[i - 1][j][k + 1] = 1
                        image1[i - 1][j + 1][k - 1] = 1
                        image1[i - 1][j + 1][k] = 1
                        image1[i - 1][j + 1][k + 1] = 1
                        image1[i][j - 1][k - 1] = 1
                        image1[i][j - 1][k] = 1
                        image1[i][j - 1][k + 1] = 1
                        image1[i][j][k - 1] = 1
                        image1[i][j][k + 1] = 1
                        image1[i][j + 1][k - 1] = 1
                        image1[i][j + 1][k] = 1
                        image1[i][j + 1][k + 1] = 1
                        image1[i + 1][j - 1][k - 1] = 1
                        image1[i + 1][j - 1][k] = 1
                        image1[i + 1][j - 1][k + 1] = 1
                        image1[i + 1][j][k - 1] = 1
                        image1[i + 1][j][k] = 1
                        image1[i + 1][j][k + 1] = 1
                        image1[i + 1][j + 1][k - 1] = 1
                        image1[i + 1][j + 1][k] = 1
                        image1[i + 1][j + 1][k + 1] = 1
    
    report = open("result.txt", 'w')
    for i in range(len(image2)):
        report.write(str(image2[i]))
        report.write("\n")
    report.close()
    
    return image2