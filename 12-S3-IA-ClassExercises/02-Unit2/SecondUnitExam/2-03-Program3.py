# %% Presentacion
"""
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Inteligencia Artificial
3° "A"

Proyecto/Examen: Implementación de una Red Neuronal en Videojuegos
Anexo 2.03: Programa 3

Profesor: Miguel Ángel Meza de Luna

Alumnos:
	Espinoza Sánchez Joel Alejandro
    González Arenas Fernando Francisco
	Pardo Tinoco Jonathan David
	Pérez Jaime Julio César

Aguascalientes, Ags. 6 de noviembre de 2019
"""
# %% Las libreri­as
import torch
import numpy as np
from libs.perceptron import SLP #Uso del perceptron construido, que es el anexo 2.02 - Programa 2
from utils.decay_schedule import LinearDecaySchedule
import random
import gym
from utils.experience_memory import ExperienceMemory, Experience
# %% Las variables generales de uso
MAX_NUM_EPISODES = 100000
STEPS_PER_EPISODE = 300

# %% La clase Swallow Q-Learner o Agente de Q-Learning Ligero
class SwallowQLearner(object):
    def __init__(self, environment, learning_rate = 0.005, gamma = 0.98):
        self.obs_shape = environment.observation_space.shape
        
        self.action_shape = environment.action_space.n
        self.Q = SLP(self.obs_shape, self.action_shape)
        self.Q_optimizer = torch.optim.Adam(self.Q.parameters(), lr = learning_rate)
        
        self.gamma = gamma
        
        self.epsilon_max = 1.0
        self.epsilon_min = 0.05
        self.epsilon_decay = LinearDecaySchedule(initial_value = self.epsilon_max,
                                                 final_value = self.epsilon_min, 
                                                 max_steps = 0.5 * MAX_NUM_EPISODES * STEPS_PER_EPISODE)
        self.step_num = 0
        self.policy = self.epsilon_greedy_Q
        #Exploracion paso a paso del algoritmo para mejor entendimiento de epsilon
        
        self.memory = ExperienceMemory(capacity = int(1e5))
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

    def get_action(self, obs):
        return self.policy(obs)
    
    def epsilon_greedy_Q(self, obs):
        if random.random() < self.epsilon_decay(self.step_num):
            action = random.choice([a for a in range(self.action_shape)])
        else:
            action = np.argmax(self.Q(obs).data.to(torch.device('cpu')).numpy())   
        return action
        
        
    def learn(self, obs, action, reward, next_obs):
        td_target = reward + self.gamma * torch.max(self.Q(next_obs))
        td_error = torch.nn.functional.mse_loss(self.Q(obs)[action], td_target)
        self.Q_optimizer.zero_grad()
        td_error.backward()
        self.Q_optimizer.step()
        
    def replay_experience(self, batch_size): # Vuelve a jugar con la experiencia aleatoria almacenada
        """
        :param batch_size: Tamaño de la muestra a tomar de la memoria
        :return: 
        """
        experience_batch = self.memory.sample(batch_size)
        self.learn_from_batch_experience(experience_batch)   
      
    def learn_from_batch_experience(self, experiences): # Actualiza la red neuronal con base en lo aprendido y experiencias anteriores
        """
        :param experiences: fragmento de recuerdos anteriores
        :return: 
        """
        batch_xp = Experience(*zip(*experiences))
        obs_batch = np.array(batch_xp.obs)
        action_batch = np.array(batch_xp.action)
        reward_batch = np.array(batch_xp.reward)
        next_obs_batch = np.array(batch_xp.next_obs)
        done_batch = np.array(batch_xp.done)
        
        td_target = reward_batch + ~done_batch * \
                    np.tile(self.gamma, len(next_obs_batch)) * \
                    self.Q(next_obs_batch).detach().max(1)[0].data
        
        td_target = td_target.to(self.device)
        action_idx = torch.from_numpy(action_batch).to(self.device)
        td_error = torch.nn.functional.mse_loss(
                self.Q(obs_batch).gather(1, action_idx.view(-1,1)),
                td_target.float().unsqueeze(1))
        
        self.Q_optimizer.zero_grad()
        td_error.mean().backward()
        self.Q_optimizer.step()
        
        
        
        
        

# %% Ejecucion del programa
if __name__ == "__main__":
    environment = gym.make("CartPole-v0")
    agent = SwallowQLearner(environment)
    first_episode = True
    episode_rewards = list()
    for episode in range(MAX_NUM_EPISODES): # Repite segun el numero de episodios
        obs = environment.reset()
        total_reward = 0.0
        for step in range(STEPS_PER_EPISODE): # Repite un episodio segun el numero de pasos
            action = agent.get_action(obs)
            next_obs, reward, done, info = environment.step(action)
            agent.memory.store(Experience(obs, action, reward, next_obs, done))
            agent.learn(obs, action, reward, next_obs)
            
            obs = next_obs
            total_reward += reward
            
            if done is True: # Verifica finales, recompensas y da informe de ellas
                if first_episode:
                    max_reward = total_reward
                    first_episode = False
                episode_rewards.append(total_reward)
                if total_reward > max_reward:
                    max_reward = total_reward
                print("\nEpisodio#{} finalizado con {} iteraciones. Recompensa = {}, Recompensa media = {}, Mejor recompensa = {}".
                      format(episode, step+1, total_reward, np.mean(episode_rewards), max_reward))
                if agent.memory.get_size()>100:
                    agent.replay_experience(32)
                break
    environment.close()