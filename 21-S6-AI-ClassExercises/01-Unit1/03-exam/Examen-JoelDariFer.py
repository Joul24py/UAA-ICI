#%% Presentación
'''
   Universidad Autónoma de Aguascalientes

         Centro de Ciencias Básicas
 Departamento de Ciencias de la Computación
          Aprendizaje Inteligente
                   6° "A"

                 Primera Evaluación Parcial

   Profesor: Francisco Javier Luna Rosas
  Alumnos:
      Espinoza Sánchez Joel Alejandro
      Gómez Garza Dariana
      González Arenas Fernando Francisco

  Fecha de Entrega: 2 de marzo del 2021

Descripción: Código correspondiente a la primera evaluación parcial de una red neuronal
'''

#%% Inicio del código y preparación de la red
import numpy

'''
Los valores de enter son:
    x1 x2 x3 w14 w15 w24 w25 w34 w35 w46 w56 t4 t5 t6
'''

enter = [1, 0, 1, 0.2, -0.3, 0.4, 0.1, -0.5, 0.2, -0.3, -0.2, -0.4, 0.2, 0-1]
Tj = 1
l = 0.9
O6 = 0

print(enter)
print(O6)

while (O6 < 1):
    #%% Calcular la red de entrada y salida
    
    # Calculamos para la unidad 4
    I4 = (enter[3] * enter[0]) + (enter[5] * enter[1]) + (enter[7] * enter[2]) + enter[11]
    O4 = 1/(1 + numpy.exp(-I4))
    
    # Calculamos para la unidad 5
    I5 = (enter[4] * enter[0]) + (enter[6] * enter[1]) + (enter[8] * enter[2]) + enter[12]
    O5 = 1/(1 + numpy.exp(-I5))
    
    # Calculamos para la unidad 6
    I6 = (enter[9] * O4) + (enter[10] * O5) + enter[13]
    O6 = 1/(1 + numpy.exp(-I6))
    
    #%% Calcular el error
    
    # Calculamos para la unidad 6
    E6 = O6 * (1 - O6) * (Tj - O6)
    
    # Calculamos para la unidad 5
    E5 = O5 * E6 * enter[10]
    
    # Calculamos para la unidad 4
    E4 = O4 * E6 * enter[9]
    
    #%% Actualizamos pesos y bias
    enter[10] = enter[10] + (l * E6 * O5)
    enter[9] = enter[9] + (l * E6 * O4)
    enter[8] = enter[8] + (l * E5 * enter[2])
    enter[7] = enter[7] + (l * E4 * enter[2])
    enter[6] = enter[6] + (l * E5 * enter[1])
    enter[5] = enter[5] + (l * E4 * enter[1])
    enter[4] = enter[4] + (l * E5 * enter[0])
    enter[3] = enter[3] + (l * E4 * enter[0])
    enter[13] = enter[13] + (l * E6)
    enter[12] = enter[12] + (l * E5)
    enter[11] = enter[11] + (l * E4)
    
    print(enter)
    print(O6)