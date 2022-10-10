#%% Portada
'''
           Universidad Autónoma de Aguascalientes
                 Centro de Ciencias Básicas
         Departamento de Ciencias de la Computación
                           8° "A"

             Examen / Tarea 1: Código de apoyo
              Archivo solución del ejercicio 5

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

print("----- Ejercicio 5: Obtener contorno -----")
for i in range(10):
    print("\nAnálisis de la imagen " + imagesSet[i] + ".bmp:")
    
    # Se carga la imagen al programa
    image = cv2.imread("images\\bilevel_images\\" + imagesSet[i] + ".bmp")
    
    # Se obtiene el ancho y alto de la imagen
    height, width = functions.getDimensions(image)
    
    # Se transforma la imagen para mejor tratamiento
    image = functions.transform_data(image, height, width)
    
    # Se calcula el contorno
    functions.calcPerimeter_4(image, height, width, imagesSet[i])
    print("Se calculó con vecindad 4 el contorno para " + imagesSet[i])
    print("Puede consultarse el resultado en el archivo perimeter-4-" + imagesSet[i] + ".txt")
    functions.exportImg_ej5_4(image, height, width, imagesSet[i])
    
    # Se carga la imagen al programa
    image = cv2.imread("images\\bilevel_images\\" + imagesSet[i] + ".bmp")
    
    # Se obtiene el ancho y alto de la imagen
    height, width = functions.getDimensions(image)
    
    # Se transforma la imagen para mejor tratamiento
    image = functions.transform_data(image, height, width)
    
    functions.calcPerimeter_8(image, height, width, imagesSet[i])
    print("Se calculó con vecindad 8 el contorno para " + imagesSet[i])
    print("Puede consultarse el resultado en el archivo perimeter-8-" + imagesSet[i] + ".txt")
    functions.exportImg_ej5_8(image, height, width, imagesSet[i])