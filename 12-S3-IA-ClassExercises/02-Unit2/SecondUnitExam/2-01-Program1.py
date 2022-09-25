# %% Presentacion
"""
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Inteligencia Artificial
3° "A"

Proyecto/Examen: Implementación de una Red Neuronal en Videojuegos
Anexo 2.01: Programa 1

Profesor: Miguel Ángel Meza de Luna

Alumnos:
	Espinoza Sánchez Joel Alejandro
    González Arenas Fernando Francisco
	Pardo Tinoco Jonathan David
	Pérez Jaime Julio César

Aguascalientes, Ags. 6 de noviembre de 2019
"""
# %% Las librerías
import gym
import numpy as np
# %% Las variables generales de uso

MAX_NUM_EPISODES = 50000 # Numero maximo de iteraciones dispuestos a realizar
STEPS_PER_EPISODE = 200 # Numero maximo de pasos a realizar en cada episodio
EPSILON_MIN = 0.005 # Se aprende mientras el incremento de aprendizaje sea superior a este valor
max_num_steps = MAX_NUM_EPISODES * STEPS_PER_EPISODE
EPSILON_DECAY = 500 * EPSILON_MIN / max_num_steps
ALPHA = 0.05 # Radio de aprendizaje del agente
GAMMA = 0.98 # Factor de descuento del agente
NUM_DISCRETE_BINS = 30 # Numero de divisiones si se discretiza el espacio de estados continuo
# %% La clase Q-Learner

class QLearner(object):
    def __init__(self, environment):
        self.obs_shape = environment.observation_space.shape
        self.obs_high = environment.observation_space.high
        self.obs_low = environment.observation_space.low
        self.obs_bins = NUM_DISCRETE_BINS
        self.bin_width = (self.obs_high-self.obs_low)/self.obs_bins
        
        self.action_shape = environment.action_space.n
        self.Q = np.zeros((self.obs_bins+1, self.obs_bins+1, self.action_shape)) # Matriz de 31 x 31 x 3
        self.alpha = ALPHA
        self.gamma = GAMMA
        self.epsilon = 1.0
        
    def discretize(self, obs):
        return tuple(((obs-self.obs_low)/self.bin_width).astype(int))
        
    def get_action(self, obs):
        discrete_obs = self.discretize(obs)
        # Se escoge la accion con base en Epsilon-Greedy
        if self.epsilon > EPSILON_MIN:
            self.epsilon -= EPSILON_DECAY
        if np.random.random() > self.epsilon:
            return np.argmax(self.Q[discrete_obs]) # Con p = 1-epsilon, se toma la mejor posible
        else:
            return np.random.choice([a for a in range(self.action_shape)])# Con p = epsilon, se toma una al azar
        
    def learn(self, obs, action, reward, next_obs):
        discrete_obs = self.discretize(obs)
        discrete_next_obs = self.discretize(next_obs)
        self.Q[discrete_obs][action] += self.alpha*(reward + self.gamma * np.max(self.Q[discrete_next_obs]) - self.Q[discrete_obs][action])
# %% Metodo para entrenar al agente
def train(agent, environment):
    best_reward = -float('inf')
    for episode in range(MAX_NUM_EPISODES):
        done = False
        obs = environment.reset()
        total_reward = 0.0
        while not done:
            action = agent.get_action(obs)# Accion elegida segun ecuacion de Q-Learning
            next_obs, reward, done, info = environment.step(action)
            agent.learn(obs, action, reward, next_obs)
            obs = next_obs
            total_reward += reward
        if total_reward > best_reward:
            best_reward = total_reward
        print("Episodio número: {} con recompensa: {}, mejor recompensa: {}, epsilon: {}".format(episode, total_reward, best_reward, agent.epsilon))
    
    # De todas las políticas de entrenamiento obtenidas se devuelve la mejor de todas
    return np.argmax(agent.Q, axis = 2)
# %% Test para evaluar la recompensa total        
def test(agent, environment, policy):
    done = False
    obs = environment.reset()
    total_reward = 0.0
    while not done:
        action = policy[agent.discretize(obs)] # Accion que define la politica entrenada
        next_obs, reward, done, info = environment.step(action)
        obs = next_obs
        total_reward += reward
    return total_reward
# %% Ejecucion del programa
if __name__ == "__main__":
    environment = gym.make("MountainCar-v0")
    agent = QLearner(environment)
    learned_policy = train(agent, environment)
    monitor_path = "./monitor_output"
    environment = gym.wrappers.Monitor(environment, monitor_path, force = True)
    for _ in range(1000):
        test(agent, environment, learned_policy)
    environment.close()