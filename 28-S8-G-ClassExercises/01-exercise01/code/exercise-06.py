#%% Portada
'''
           Universidad Autónoma de Aguascalientes
                 Centro de Ciencias Básicas
         Departamento de Ciencias de la Computación
                           8° "A"

             Examen / Tarea 1: Código de apoyo
              Archivo solución del ejercicio 6

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
imageName1 = '043'
imageName2 = '057'

print("----- Ejercicio 6: Superponer dos objetos -----")

print("\nAnálisis de las imágenes " + imageName1 + ".bmp y " + imageName2 + ".bmp:")

# Se cargan las imágenes al programa
image1 = cv2.imread("images\\bilevel_images\\" + imageName1 + ".bmp")
image2 = cv2.imread("images\\bilevel_images\\" + imageName2 + ".bmp")

# Se obtienen los anchos y altos de las imágenes
height1, width1 = functions.getDimensions(image1)
height2, width2 = functions.getDimensions(image2)

# Se transforman las imágenes para mejor tratamiento
image1 = functions.transform_data(image1, height1, width1)
image2 = functions.transform_data(image2, height2, width2)

# Se obtienen los 0-píxeles y los 1-píxeles
onePixels1, zeroPixels1 = functions.calcPixels(image1, height1, width1)
onePixels2, zeroPixels2 = functions.calcPixels(image2, height2, width2)

# Se calcula el centro de masa
x1, y1, x_sol1, y_sol1 = functions.calcMassCenter(image1, height1, width1, onePixels1)
x2, y2, x_sol2, y_sol2 = functions.calcMassCenter(image2, height2, width2, onePixels2)

# Se superponen las imágenes
newImage, zeros, onesImg1, onesImg2, bothOnes = functions.overlap(image1, height1, width1, x1, y1, imageName1, image2, height2, width2, x2, y2, imageName2)
functions.exportImg_ej6(newImage, len(newImage), len(newImage[0]), imageName1 + "-" + imageName2)
print("Píxeles en común: " + str(bothOnes))
print("Píxeles no comunes de la imagen 1: " + str(onesImg1))
print("Píxeles no comunes de la imagen 2: " + str(onesImg2))