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
from dataclasses import dataclass
from enum import Enum

class TokenType(Enum):
	NUMBER    = 0
	PLUS      = 1
	MINUS     = 2
	MULTIPLY  = 3
	DIVIDE    = 4
	LPAREN    = 5
	RPAREN    = 6

@dataclass
class Token:
	type: TokenType
	value: any = None

	def __repr__(self):
		return self.type.name + (f":{self.value}" if self.value != None else "")