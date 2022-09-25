# -*- coding: utf-8 -*-

import gym
env = gym.make("MountainCar-v0")
maxep=1000 #numero maximo de episodios
for episode in range(maxep): #ciclo para realizar los x episodios
  done = False #declara el done como falso
  obs = env.reset()#ejecuta el observador
  total_reward = 0.0 #el valor de recompensa
  step = 0#el contador de pasos
  while not done:#mientras done sea falso se hara lo siguiente
    env.render()#es para pintar en pantalla el estado del agente
    action = env.action_space.sample()#se selecciona una accion aleatoria entre las posibles
    next_state, reward, done, info = env.step(action)#se realiza la accion la cual regresa 4 valores
    total_reward += reward#el contador de recompensa
    step += 1#contador de pasos
    obs = next_state#El observador de iguala al valor regresado por la ejecucion de la accion next_state
  print("\nEpisodio numero {} finalizado con {} iteraciones. recompensa final {}".format(episode, step+1, total_reward) )
env.close()