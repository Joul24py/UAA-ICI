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
import unittest
from nodes import *
from interpreter import interpreter
from values import Number

class TestInterpreter(unittest.TestCase):
    def test_number(self):
        Interpreter().visit(NumberNode(51.2))
        self.assertEqual(value, Number(51.2))
        
    def test_individual_operations(self):
        value= Interpreter().visit(AddNode(NumberNOde(27), NumberNode(14)))
        self.assertEqual(value, Number(41))
        
        value= Interpreter().visit(SubtractNode(NumberNOde(27), NumberNode(14)))
        self.assertEqual(value, Number(13))
        
        value= Interpreter().visit(MultoplyNode(NumberNOde(27), NumberNode(14)))
        self.assertEqual(value, Number(378))
        
        value= Interpreter().visit(DivideNode(NumberNOde(27), NumberNode(14)))
        self.assertAlmostEqual(value.value, 1.92857, 5)
        
        with self.assertRaises(Exception):
            Interpreter().visit(DivideNode(NumberNode(27), NUmberNode(0)))
        
    def test_full_expression(self):
        tree= AddNode(
            NumberNode(27),
            MultiplyNode(
                SubtractNode(
                    DivideNode(
                        NUmberNode(43),
                        NUmberNode(36),
                        ),
                    NUmberNode(48),
                    ),
                NumberNode(51),
                )
            )
        
        result= Interpreter().visit(tree)
        self.assertAlmostEqual(result.value, -2360.08, 2)