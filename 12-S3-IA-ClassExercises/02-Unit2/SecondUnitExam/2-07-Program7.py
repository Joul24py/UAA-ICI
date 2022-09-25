# %% Presentacion
"""
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Inteligencia Artificial
3° "A"

Proyecto/Examen: Implementación de una Red Neuronal en Videojuegos
Anexo 2.07: Programa 7

Profesor: Miguel Ángel Meza de Luna

Alumnos:
	Espinoza Sánchez Joel Alejandro
    González Arenas Fernando Francisco
	Pardo Tinoco Jonathan David
	Pérez Jaime Julio César

Aguascalientes, Ags. 6 de noviembre de 2019
"""
# %% Las librerías
import torch
import numpy as np
from perceptron import SLP
from decay_schedule import LinearDecaySchedule
import random
import gym
from experience_memory import ExperienceMemory, Experience
# %% Definiciones de variables generales
MAX_NUM_EPISODES = 100000
STEPS_PER_EPISODE = 300

# %% La clase Swallow QLearner
class SwallowQLearner(object):
    def __init__(self,environment,learning_rate = 0.005,gamma = 0.98):
        self.obs_shape = environment.observation_space.shape
        
        self.action_shape = environment.action_space.n
        self.Q = SLP(self.obs_shape,self.action_shape)
        self.Q_optimizer = torch.optim.Adam(self.Q.parameters(),lr = learning_rate)
        self.gamma = gamma
        
        self.epsilon_max = 1.0
        self.epsilon_min=0.05
        self.epsilon_decay = LinearDecaySchedule(initial_value = self.epsilon_max, 
                                                 final_value = self.epsilon_min, 
                                                 max_steps = 0.5 * MAX_NUM_EPISODES * STEPS_PER_EPISODE)
        
        self.step_num = 0
        self.policy = self.epsilon_greedy_Q


        self.memory = ExperienceMemory(capacity = int(1e5))
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

    def get_action(self,obs):
        return self.policy(obs)
    def epsilon_greedy_Q(self,obs):
        if random.random() < self.epsilon_decay(self.step_num):
            action = random.choice([a for a in range(self.action_shape)])
        else:
            action = np.argmax(self.Q(obs).data.to(torch.device('cpu')).numpy())
        return action
    
    def learn(self, obs, action, reward, next_obs): #Método de aprendizaje
        td_target = reward + self.gamma * torch.max(self.Q(next_obs))
        td_error = torch.nn.functional.mse_loss(self.Q(obs)[action], td_target)
        self.Q_optimizer.zero_grad()
        td_error.backward()
        self.Q_optimizer.step()
        
    def replay_experience(self, batch_size):
        """
        Vuelve a jugar usando la experiencia aleatoria almacenada
        :param batch_size: Tamaño de la muestra a tomar de la memoria
        :return: 
        """
        experience_batch = self.memory.sample(batch_size)
        self.learn_from_batch_experience(experience_batch)   
      
    def learn_from_batch_experience(self, experiences):
        """
        Actualiza la red neuronal profunda en base a lo aprendido en el conjunto de experiencias anteriores
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
        td_error = torch.nn.functional.mse_loss(self.Q(obs_batch).gather(1, action_idx.view(-1,1)), td_target.float().unsqueeze(1))
        
        self.Q_optimizer.zero_grad()
        td_error.mean().backward()
        self.Q_optimizer.step()
        
        
# %% La funcion de ejecucion
if __name__ == "__main__":
    environment = gym.make("CartPole-v0") #Llamamos el ambiente que se va a intentar resolver
    agent = SwallowQLearner(environment)
    first_episode = True
    episode_rewards = list()
    for episode in range(MAX_NUM_EPISODES):
        obs = environment.reset()
        total_reward = 0.0
        for step in range(STEPS_PER_EPISODE):
            #environment.render()
            action = agent.get_action(obs)
            next_obs, reward, done, info = environment.step(action)
            agent.memory.store(Experience(obs, action, reward, next_obs, done)) #guardamos la experiencia del agente
            agent.learn(obs, action, reward, next_obs)#Llamamos al aprendizaje
            
            obs = next_obs
            total_reward += reward
            
            if done is True:
                if first_episode:
                    max_reward = total_reward
                    first_episode = False
                episode_rewards.append(total_reward)
                if total_reward > max_reward:
                    max_reward = total_reward
                print("\nEpisodio #{} finalizado con {} iteraciones. Recompensa = {}, Recompensa media = {}, Mejor recompensa = {}". #Imprime la información obtenida durante la ejecución
                      format(episode, step+1, total_reward, np.mean(episode_rewards), max_reward))
                if agent.memory.get_size()>100:
                    agent.replay_experience(32)
                break
    environment.close()
