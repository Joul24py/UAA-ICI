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
from nodes import *
from values import Number

class Interpreter:
  def __init__(self):
    pass
  def visit(self, node):
    method_name = f'visit_{type(node).__name__}'
    method = getattr(self, method_name)
    return method(node)

  def visit_NumberNode(self, node):
    return Number(node.value) 

  def visit_AddNode(self, node):
    return Number(self.visit(node.node_a).value + self.visit(node.node_b).value)

  def visit_SubtractNode(self, node):
    return Number(self.visit(node.node_a).value - self.visit(node.node_b).value)

  def visit_MultiplyNode(self, node):
    return Number(self.visit(node.node_a).value * self.visit(node.node_b).value)

  def visit_DivideNode(self, node):
    try:
      return Number(self.visit(node.node_a).value / self.visit(node.node_b).value)
    except:
      raise Exception("Runtime math error")
  
  def visit_MinusNode(self,node):
      return Number(0-self.visit(node.node).value)
    
  def visit_PlusNode(self, node):
      return Number(0+self.visit(node.node).value)