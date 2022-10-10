#%% Portada
'''
           Universidad Autónoma de Aguascalientes
                 Centro de Ciencias Básicas
         Departamento de Ciencias de la Computación
                           8° "A"

             Examen / Tarea 1: Código de apoyo
              Archivo solución del ejercicio 2

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

print("----- Ejercicio 2: Calcular 1-píxeles -----")
for i in range(10):
    print("\nAnálisis de la imagen " + imagesSet[i] + ".bmp:")
    
    # Se carga la imagen al programa
    image = cv2.imread("images\\bilevel_images\\" + imagesSet[i] + ".bmp")
    
    # Se obtiene el ancho y alto de la imagen
    height, width = functions.getDimensions(image)
    print("  Ancho de la imagen: " + str(width))
    print("  Alto de la imagen: " + str(height))
    
    # Se transforma la imagen para mejor tratamiento
    image = functions.transform_data(image, height, width)
    
    # Se obtienen los 0-píxeles y los 1-píxeles
    onePixels, zeroPixels = functions.calcPixels(image, height, width)
    print("  0-píxeles: " + str(zeroPixels))
    print("  1-píxeles: " + str(onePixels))