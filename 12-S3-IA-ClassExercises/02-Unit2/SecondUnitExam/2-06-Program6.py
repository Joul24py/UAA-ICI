# %% Presentacion
"""
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Inteligencia Artificial
3° "A"

Proyecto/Examen: Implementación de una Red Neuronal en Videojuegos
Anexo 2.06: Programa 6

Profesor: Miguel Ángel Meza de Luna

Alumnos:
	Espinoza Sánchez Joel Alejandro
    González Arenas Fernando Francisco
	Pardo Tinoco Jonathan David
	Pérez Jaime Julio César

Aguascalientes, Ags. 6 de noviembre de 2019
"""
# %% Las libreri­as
from collections import namedtuple
import random
# %% Definicion de la variable Experience
Experience = namedtuple("Experience", ['obs', 'action', 'reward', 'next_obs', 'done'])
# %% La clase Experience Memory
class ExperienceMemory(object):
    """
    Un buffer que simula la memoria, experiencia del agente
    """
    def __init__(self, capacity = int(1e6)):
        """
        :param capacity: Capacidad total de la memoria cíclica (número máximo de experiencias almacenables)
        :return:
        """
        self.capacity = capacity
        self.memory_idx = 0 #identificador que sabe la experiencia actual
        self.memory = []
        
    def sample(self, batch_size):
        """
        :param batch_size: Tamaño de la memoria a recuperar
        :return: Una muestra aleatoria del tamaño batch_size de experiencias de la memoria
        """
        assert batch_size <= self.get_size(), "El tamaño de la muestra es superior a la memoria disponible"
        return random.sample(self.memory, batch_size)
    
    def get_size(self):
        """
        :return: Número de experiencias almacenadas en memoria
        """
        return len(self.memory)
    
    def store(self, exp):
        """
        :param experience: Objeto experiencia a ser almacenado en memoria
        :return:
        """
        self.memory.insert(self.memory_idx % self.capacity, exp)
        self.memory_idx += 1

