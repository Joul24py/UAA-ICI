# -*- coding: utf-8 -*-
import gym
from gym.spaces import *
import sys

def print_spaces(space):
  print(space)
  if isinstance (space, Box):
    print("\n Cota inferior: ",space.low)
    print("\n Cota superior: ",space.high)
    
if __name__ == "__main__":
  amb = gym.make(sys.argv[1])
  print("\n espacio de observaciones")
  print_spaces(amb.observation_space)
  print("\n espacio de acciones")
  print_spaces(amb.action_space)
  try:
    print("Descripcion de las acciones", amb.unwrapped.get_action_meanings())
  except AttributeError:
    pass