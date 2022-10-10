#%% Portada
'''
           Universidad Autónoma de Aguascalientes
                 Centro de Ciencias Básicas
         Departamento de Ciencias de la Computación
                           8° "A"

             Examen / Tarea 1: Código de apoyo
              Archivo solución del ejercicio 9

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
imageName1 = imagesSet[0]

print("----- Ejercicio 9: Calcular invariante de escala al realizar escalamiento -----")
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
for p in range(3):
    for q in range(3):
        mpq = functions.calcCentralMoment(image, height, width, x, y, p, q)
        m00 = functions.calcCentralMoment(image, height, width, x, y, 0, 0)
        npq = mpq/(m00 ** (((p + q)/2) + 1))
        print("m" + str(p) + str(q) + " = " + str(mpq))
        print("m00 = " + str(m00))
        print("n" + str(p) + str(q) + " = " + str(npq))

print("\nAnálisis de la imagen " + imageName1 + ".bmp reducida a la mitad")

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
for p in range(3):
    for q in range(3):
        mpq = functions.calcCentralMoment(image, height, width, x, y, p, q)
        m00 = functions.calcCentralMoment(image, height, width, x, y, 0, 0)
        npq = mpq/(m00 ** (((p + q)/2) + 1))
        print("m" + str(p) + str(q) + " = " + str(mpq))
        print("m00 = " + str(m00))
        print("n" + str(p) + str(q) + " = " + str(npq))

print("\nAnálisis de la imagen original " + imageName1 + ".bmp reducida a la cuarta parte")

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
for p in range(3):
    for q in range(3):
        mpq = functions.calcCentralMoment(image, height, width, x, y, p, q)
        m00 = functions.calcCentralMoment(image, height, width, x, y, 0, 0)
        npq = mpq/(m00 ** (((p + q)/2) + 1))
        print("m" + str(p) + str(q) + " = " + str(mpq))
        print("m00 = " + str(m00))
        print("n" + str(p) + str(q) + " = " + str(npq))

print("\nAnálisis de la imagen original " + imageName1 + ".bmp reducida a la tercera parte")

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
for p in range(3):
    for q in range(3):
        mpq = functions.calcCentralMoment(image, height, width, x, y, p, q)
        m00 = functions.calcCentralMoment(image, height, width, x, y, 0, 0)
        npq = mpq/(m00 ** (((p + q)/2) + 1))
        #print("m" + str(p) + str(q) + " = " + str(mpq))
        #print("m00 = " + str(m00))
        print("n" + str(p) + str(q) + " = " + str(npq))