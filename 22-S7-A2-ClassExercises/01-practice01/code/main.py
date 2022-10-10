#%% Portada
'''
                 Centro de Ciencias Básicas
         Departamento de Ciencias de la Computación
                        Autómatas II
                           7° "A"

                         Intérprete

         Profesor: Francisco Javier Ornelas Zapata

         Alumnos:
                  Almeida Ortega Andrea Melissa
                  Espinoza Sánchez Joel Alejandro
                  Flores Fernández Óscar Alonso
                  Gómez Garza Dariana
                  González Arenas Fernando Francisco
                  Orocio García Hiram Efraín

Fecha de Entrega: Aguascalientes, Ags., 3 de octubre de 2021
'''

#%% Desarrollo del archivo
from lexer import Lexer
from parser_ import Parser
from interpreter import Interpreter

while True:
  try:
    text = input("calc > ")
    lexer = Lexer(text)
    tokens = lexer.generate_tokens()
    parser = Parser(tokens)
    tree = parser.parse()
  #print(list(tokens))
  #print(tree)
    if not tree: continue
    interpreter = Interpreter()
    value = interpreter.visit(tree)
    print(value)
  except Exception as e:
    print(e)