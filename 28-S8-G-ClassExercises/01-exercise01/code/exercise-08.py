#%% Portada
'''
           Universidad Autónoma de Aguascalientes
                 Centro de Ciencias Básicas
         Departamento de Ciencias de la Computación
                           8° "A"

             Examen / Tarea 1: Código de apoyo
              Archivo solución del ejercicio 8

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

print("----- Ejercicio 8: Calcular momentos centrales -----")
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
m00 = functions.calcCentralMoment(image, height, width, x, y, 0, 0)
m11 = functions.calcCentralMoment(image, height, width, x, y, 1, 1)
m22 = functions.calcCentralMoment(image, height, width, x, y, 2, 2)
print("m00: " + str(m00))
print("m11: " + str(m11))
print("m22: " + str(m22))

print("\nAnálisis de la imagen trasladada 1 " + imageName1 + ".bmp")

# Se carga la imagen al programa
image = cv2.imread("images\\translation\\" + imageName1 + "_1.bmp")

# Se obtiene el ancho y alto de la imagen
height, width = functions.getDimensions(image)

# Se transforma la imagen para mejor tratamiento
image = functions.transform_data(image, height, width)

# Se obtienen los 0-píxeles y los 1-píxeles
onePixels, zeroPixels = functions.calcPixels(image, height, width)

# Se calcula el centro de masa
x, y, x_sol, y_sol = functions.calcMassCenter(image, height, width, onePixels)

# Se calcula el momento central
m00 = functions.calcCentralMoment(image, height, width, x, y, 0, 0)
m11 = functions.calcCentralMoment(image, height, width, x, y, 1, 1)
m22 = functions.calcCentralMoment(image, height, width, x, y, 2, 2)
print("m00: " + str(m00))
print("m11: " + str(m11))
print("m22: " + str(m22))

print("\nAnálisis de la imagen trasladada 2 " + imageName1 + ".bmp")

# Se carga la imagen al programa
image = cv2.imread("images\\translation\\" + imageName1 + "_2.bmp")

# Se obtiene el ancho y alto de la imagen
height, width = functions.getDimensions(image)

# Se transforma la imagen para mejor tratamiento
image = functions.transform_data(image, height, width)

# Se obtienen los 0-píxeles y los 1-píxeles
onePixels, zeroPixels = functions.calcPixels(image, height, width)

# Se calcula el centro de masa
x, y, x_sol, y_sol = functions.calcMassCenter(image, height, width, onePixels)

# Se calcula el momento central
m00 = functions.calcCentralMoment(image, height, width, x, y, 0, 0)
m11 = functions.calcCentralMoment(image, height, width, x, y, 1, 1)
m22 = functions.calcCentralMoment(image, height, width, x, y, 2, 2)
print("m00: " + str(m00))
print("m11: " + str(m11))
print("m22: " + str(m22))

print("\nAnálisis de la imagen trasladada 3 " + imageName1 + ".bmp")

# Se carga la imagen al programa
image = cv2.imread("images\\translation\\" + imageName1 + "_3.bmp")

# Se obtiene el ancho y alto de la imagen
height, width = functions.getDimensions(image)

# Se transforma la imagen para mejor tratamiento
image = functions.transform_data(image, height, width)

# Se obtienen los 0-píxeles y los 1-píxeles
onePixels, zeroPixels = functions.calcPixels(image, height, width)

# Se calcula el centro de masa
x, y, x_sol, y_sol = functions.calcMassCenter(image, height, width, onePixels)

# Se calcula el momento central
m00 = functions.calcCentralMoment(image, height, width, x, y, 0, 0)
m11 = functions.calcCentralMoment(image, height, width, x, y, 1, 1)
m22 = functions.calcCentralMoment(image, height, width, x, y, 2, 2)
print("m00: " + str(m00))
print("m11: " + str(m11))
print("m22: " + str(m22))