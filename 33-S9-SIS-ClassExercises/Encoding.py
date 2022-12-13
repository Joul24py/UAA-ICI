#%% Portada
'''
           Universidad Autónoma de Aguascalientes
                 Centro de Ciencias Básicas
            Departamento de Sistemas Electrónicos
             Seguridad e Integridad de Sistemas
                           9° "A"

               Tarea: Primeros Pasos Cifrando

                Profesor: Arturo Ocampo Silva

            Alumnos:
                Almeida Ortega Andrea Melissa
                Espinoza Sánchez Joel Alejandro

Fecha de entrega: Aguascalientes, Ags., 26 de agosto del 2022
'''

#%% Función para hacer cifrado César
def cesar(cadena, cesar):
  newCadena = ''
  for i in range(len(cadena)):
    # Pasar el caracter de espacio
    if cadena[i] == ' ':
      newCadena = newCadena + ' '
    # Mayúsculas
    if (ord(cadena[i]) >= 65) and (ord(cadena[i]) <= 90):
      x = ord(cadena[i])
      y = x + cesar
      if y < 65:
        y = 90 - (65 - y) + 1
      if y > 90:
        y = 65 + (y - 90) - 1
      newCadena = newCadena + chr(y)
    # Minúsculas
    if (ord(cadena[i]) >= 97) and (ord(cadena[i]) <= 122):
      x = ord(cadena[i])
      y = x + cesar
      if y < 97:
        y = 122 - (97 - y) + 1
      if y > 122:
        y = 97 + (y - 122) - 1
      newCadena = newCadena + chr(y)
    
  return newCadena

#%% Función para hacer cifrado Atbash
def atbash(cadena):
  newCadena = ''
  for i in range(len(cadena)):
    # Pasar el caracter de espacio
    if cadena[i] == ' ':
      newCadena = newCadena + ' '
    # Mayúsculas
    if (ord(cadena[i]) >= 65) and (ord(cadena[i]) <= 90):
      x = ord(cadena[i])
      y = 155 - x
      newCadena = newCadena + chr(y)
    # Minúsculas
    if (ord(cadena[i]) >= 97) and (ord(cadena[i]) <= 122):
      x = ord(cadena[i])
      y = 219 - x
      newCadena = newCadena + chr(y)
  return newCadena