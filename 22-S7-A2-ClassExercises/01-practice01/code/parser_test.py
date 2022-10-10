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
from tokens import Token, TokenType
from parser_ import Parser
from nodes import *

class TestParser(unittest.TestCase):
    def test_empty(self):
        tokens=[]
        node= Parser(tokens).parse()
        self.assertEqual(node, None)
        
    def test_numbers(self):
        tokens= [Token(TokenType.NUMBER, 51.2)]
        node= Parser(tokens).parse()
        self.assertEqual(node, NUmberNode(51.20))
        
        
    def test_individual_operations(self):
        token= [
            Token(TokenType.NUMBER, 27),
            Token(TokenType.PLUS),
            Token(TokenType.NUMBER, 14),
            ]
        
        
        
        node= Parser(tokens).parse()
        self.assertEqual(node, AddNode(NumberNode(27), NumberNode(14)))
       
        token= [
            Token(TokenType.NUMBER, 27),
            Token(TokenType.MINUS),
            Token(TokenType.NUMBER, 14),
            ]
        
        node= Parser(tokens).parse()
        self.assertEqual(node, SubtractNode(NumberNode(27), NumberNode(14))) 
        
        token= [
            Token(TokenType.NUMBER, 27),
            Token(TokenType.MULTIPLY),
            Token(TokenType.NUMBER, 14),
            ]
        
        node= Parser(tokens).parse()
        self.assertEqual(node, MultiplyNode(NumberNode(27), NumberNode(14)))
        
        token= [
            Token(TokenType.NUMBER, 27),
            Token(TokenType.DIVIDE),
            Token(TokenType.NUMBER, 14),
            ]
        
        node= Parser(tokens).parse()
        self.assertEqual(node, DivideNode(NumberNode(27), NumberNode(14)))
        
    def test_full_expression(self):
        tokens=[
            Token(TokenType.NUMBER, 27),
            Token(TokenType.PLUS),
            Token(TokenType.LPAREN),
            Token(TokenType.NUMBER, 43),
            Token(TokenType.DIVIDE),
            Token(TokenType.NUMBER, 36),
            Token(TokenType.MINUS),
            Token(TokenType.NUMBER, 48),
            Token(TokenType.RPAREN),
            Token(TokenType.MULTIPLY),
            Token(TokenType.NUMBER, 51),
            ]
        node= Parser(tokens).parse()
        self.assertEqual(node, AddNode(
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
            ))