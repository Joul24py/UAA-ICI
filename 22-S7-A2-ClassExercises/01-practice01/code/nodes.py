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

@dataclass
class NumberNode:
	value: any

	def __repr__(self):
		return f"{self.value}"

@dataclass
class AddNode:
	node_a: any
	node_b: any

	def __repr__(self):
		return f"({self.node_a}+{self.node_b})"

@dataclass
class SubtractNode:
	node_a: any
	node_b: any

	def __repr__(self):
		return f"({self.node_a}-{self.node_b})"

@dataclass
class MultiplyNode:
	node_a: any
	node_b: any

	def __repr__(self):
		return f"({self.node_a}*{self.node_b})"

@dataclass
class DivideNode:
	node_a: any
	node_b: any

	def __repr__(self):
		return f"({self.node_a}/{self.node_b})"

@dataclass
class PlusNode:
	node: any

	def __repr__(self):
		return f"(+{self.node})"
	
@dataclass
class MinusNode:
	node: any

	def __repr__(self):
		return f"(-{self.node})"