import gym
import numpy as np
env = gym.make('FrozenLake-v0')

#Inicializa la tabla en ceros.

Q = np.zeros([env.observation_space.n,env.action_space.n])

#Se establecen los parametros de aprendizaje

lr = .8
y = .95
num_episodes = 2000

#Se crea una lista que contenga el total de recompensas y pasos por episodio 
#jList = []

rList = []
for i in range(num_episodes):

    #Se resetea el entorno y obtiene una nueva observacion

    s = env.reset()
    rAll = 0
    d = False
    j = 0

    #El algoritmo de aprendizaje Q-Table

    while j < 99:
        j+=1

        #Escoge una accion por el metodo greedily, se selecciona de la Q table

        a = np.argmax(Q[s,:] + np.random.randn(1,env.action_space.n)*(1./(i+1)))

        #Se obiene un nuevo estado y una recompensa del entorno

        s1,r,d,_ = env.step(a)

        #Actualiza la Q-Table con nuevos conocimientos

        Q[s,a] = Q[s,a] + lr*(r + y*np.max(Q[s1,:]) - Q[s,a])
        rAll += r
        s = s1
        if d == True:
            break

    #jList.append(j)

    rList.append(rAll)
    
    print ("Score over time: " +  str(sum(rList)/num_episodes))
    print ("Final Q-Table Values")
    print (Q)