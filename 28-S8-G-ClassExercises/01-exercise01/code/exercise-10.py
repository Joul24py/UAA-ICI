#%% Portada
'''
           Universidad Autónoma de Aguascalientes
                 Centro de Ciencias Básicas
         Departamento de Ciencias de la Computación
                           8° "A"

             Examen / Tarea 1: Código de apoyo
             Archivo solución del ejercicio 10

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
import cv2
import functions

#%% Función main

# Elección de imágenes
imagesSet = functions.loadImages()
imageName1 = imagesSet[9]

print("----- Ejercicio 10: Calcular los tres momentos en Hu -----")
print("\nAnálisis de la imagen original " + imageName1 + ".bmp")

# Se carga la imagen al programa
image = cv2.imread("images\\bilevel_images\\" + imageName1 + ".bmp")

# Se obtiene el ancho y alto de la imagen
height, width = functions.getDimensions(image)

# Se transforma la imagen para mejor tratamiento
image = functions.transform_data(image, height, width)

# Se obtienen los 0-píxeles y los 1-píxeles
onePixels, zeroPixels = functions.calcPixels(image, height, width)

# Se calcula el centro de masa
x, y, x_sol, y_sol = functions.calcMassCenter(image, height, width, onePixels)

# Se calcula el momento central
m20 = functions.calcCentralMoment(image, height, width, x, y, 2, 0)
m02 = functions.calcCentralMoment(image, height, width, x, y, 0, 2)
fi1 = m20 + m02

m11 = functions.calcCentralMoment(image, height, width, x, y, 1, 1)
fi2 = ((m20 - m02) ** 2) + 4 * (m11 ** 2)

m30 = functions.calcCentralMoment(image, height, width, x, y, 3, 0)
m12 = functions.calcCentralMoment(image, height, width, x, y, 1, 2)
m21 = functions.calcCentralMoment(image, height, width, x, y, 2, 1)
m03 = functions.calcCentralMoment(image, height, width, x, y, 0, 3)
fi3 = ((m30 - 3 * m12) ** 2) + ((3 * m21 - m03) ** 2)

print("fi1 = " + str(fi1))
print("fi2 = " + str(fi2))
print("fi3 = " + str(fi3))

print("\nAnálisis de la imagen rotada 1 " + imageName1 + ".bmp")

# Se carga la imagen al programa
image = cv2.imread("images\\rotation\\" + imageName1 + "_1.bmp")

# Se obtiene el ancho y alto de la imagen
height, width = functions.getDimensions(image)

# Se transforma la imagen para mejor tratamiento
image = functions.transform_data(image, height, width)

# Se obtienen los 0-píxeles y los 1-píxeles
onePixels, zeroPixels = functions.calcPixels(image, height, width)

# Se calcula el centro de masa
x, y, x_sol, y_sol = functions.calcMassCenter(image, height, width, onePixels)

# Se calcula el momento central
m20 = functions.calcCentralMoment(image, height, width, x, y, 2, 0)
m02 = functions.calcCentralMoment(image, height, width, x, y, 0, 2)
fi1 = m20 + m02

m11 = functions.calcCentralMoment(image, height, width, x, y, 1, 1)
fi2 = ((m20 - m02) ** 2) + 4 * (m11 ** 2)

m30 = functions.calcCentralMoment(image, height, width, x, y, 3, 0)
m12 = functions.calcCentralMoment(image, height, width, x, y, 1, 2)
m21 = functions.calcCentralMoment(image, height, width, x, y, 2, 1)
m03 = functions.calcCentralMoment(image, height, width, x, y, 0, 3)
fi3 = ((m30 - 3 * m12) ** 2) + ((3 * m21 - m03) ** 2)

print("fi1 = " + str(fi1))
print("fi2 = " + str(fi2))
print("fi3 = " + str(fi3))

print("\nAnálisis de la imagen rotada 2 " + imageName1 + ".bmp")

# Se carga la imagen al programa
image = cv2.imread("images\\rotation\\" + imageName1 + "_2.bmp")

# Se obtiene el ancho y alto de la imagen
height, width = functions.getDimensions(image)

# Se transforma la imagen para mejor tratamiento
image = functions.transform_data(image, height, width)

# Se obtienen los 0-píxeles y los 1-píxeles
onePixels, zeroPixels = functions.calcPixels(image, height, width)

# Se calcula el centro de masa
x, y, x_sol, y_sol = functions.calcMassCenter(image, height, width, onePixels)

# Se calcula el momento central
m20 = functions.calcCentralMoment(image, height, width, x, y, 2, 0)
m02 = functions.calcCentralMoment(image, height, width, x, y, 0, 2)
fi1 = m20 + m02

m11 = functions.calcCentralMoment(image, height, width, x, y, 1, 1)
fi2 = ((m20 - m02) ** 2) + 4 * (m11 ** 2)

m30 = functions.calcCentralMoment(image, height, width, x, y, 3, 0)
m12 = functions.calcCentralMoment(image, height, width, x, y, 1, 2)
m21 = functions.calcCentralMoment(image, height, width, x, y, 2, 1)
m03 = functions.calcCentralMoment(image, height, width, x, y, 0, 3)
fi3 = ((m30 - 3 * m12) ** 2) + ((3 * m21 - m03) ** 2)

print("fi1 = " + str(fi1))
print("fi2 = " + str(fi2))
print("fi3 = " + str(fi3))

print("\nAnálisis de la imagen rotada 3 " + imageName1 + ".bmp")

# Se carga la imagen al programa
image = cv2.imread("images\\rotation\\" + imageName1 + "_3.bmp")

# Se obtiene el ancho y alto de la imagen
height, width = functions.getDimensions(image)

# Se transforma la imagen para mejor tratamiento
image = functions.transform_data(image, height, width)

# Se obtienen los 0-píxeles y los 1-píxeles
onePixels, zeroPixels = functions.calcPixels(image, height, width)

# Se calcula el centro de masa
x, y, x_sol, y_sol = functions.calcMassCenter(image, height, width, onePixels)

# Se calcula el momento central
m20 = functions.calcCentralMoment(image, height, width, x, y, 2, 0)
m02 = functions.calcCentralMoment(image, height, width, x, y, 0, 2)
fi1 = m20 + m02

m11 = functions.calcCentralMoment(image, height, width, x, y, 1, 1)
fi2 = ((m20 - m02) ** 2) + 4 * (m11 ** 2)

m30 = functions.calcCentralMoment(image, height, width, x, y, 3, 0)
m12 = functions.calcCentralMoment(image, height, width, x, y, 1, 2)
m21 = functions.calcCentralMoment(image, height, width, x, y, 2, 1)
m03 = functions.calcCentralMoment(image, height, width, x, y, 0, 3)
fi3 = ((m30 - 3 * m12) ** 2) + ((3 * m21 - m03) ** 2)

print("fi1 = " + str(fi1))
print("fi2 = " + str(fi2))
print("fi3 = " + str(fi3))