#%% Portada
'''
           Universidad Autónoma de Aguascalientes
                 Centro de Ciencias Básicas
         Departamento de Ciencias de la Computación
                           8° "A"

             Examen / Tarea 1: Código de apoyo
              Archivo solución del ejercicio 4

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

print("----- Ejercicio 4: Calcular componentes conectados -----")
for i in range(10):
    print("\nAnálisis de la imagen " + imagesSet[i] + ".bmp:")
    
    # Se carga la imagen al programa
    image = cv2.imread("images\\bilevel_images\\" + imagesSet[i] + ".bmp")
    
    # Se obtiene el ancho y alto de la imagen
    height, width = functions.getDimensions(image)
    
    # Se transforma la imagen para mejor tratamiento
    image = functions.transform_data(image, height, width)
    
    # Se calculan los componentes conectados
    print("  Cálculo de componentes conectados por vecindad 4")
    components, connected_matrix = functions.calcConnected_4(image, height, width, imagesSet[i])
    print("  Cantidad de componentes: " + str(components) + " (" + str(connected_matrix) + ")")
    functions.exportImg_ej4_4(image, height, width, connected_matrix, imagesSet[i])
    
    # Se carga la imagen al programa
    image = cv2.imread("images\\bilevel_images\\" + imagesSet[i] + ".bmp")
    
    # Se obtiene el ancho y alto de la imagen
    height, width = functions.getDimensions(image)
    
    # Se transforma la imagen para mejor tratamiento
    image = functions.transform_data(image, height, width)
    
    print("\n  Cálculo de componentes conectados por vecindad 8")
    components, connected_matrix = functions.calcConnected_8(image, height, width, imagesSet[i])
    print("  Cantidad de componentes: " + str(components) + " (" + str(connected_matrix) + ")")
    functions.exportImg_ej4_8(image, height, width, connected_matrix, imagesSet[i])