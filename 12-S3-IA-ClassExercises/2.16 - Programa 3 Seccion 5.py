# -*- coding: utf-8 -*-
import gym 
environment = gym.make("Qbert-v0")
maxnep = 10
maxspe = 500
for episode in range(maxnep):
  obs = environment.reset()
  for step in range(maxspe):
    environment.render()
    action = environment.action_space.sample()
    next_state, reward, done, info = environment.step(action)
    obs = next_state
    
    if done is True:
      print("\n Episodio #{} terminado en #{} pasos".format(episode+1, step+1))
      break
    
environment.close()