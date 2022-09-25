# %% Presentacion
"""
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Inteligencia Artificial
3° "A"

Proyecto/Examen: Implementación de una Red Neuronal en Videojuegos
Anexo 2.04: Programa 4

Profesor: Miguel Ángel Meza de Luna

Alumnos:
	Espinoza Sánchez Joel Alejandro
    González Arenas Fernando Francisco
	Pardo Tinoco Jonathan David
	Pérez Jaime Julio César

Aguascalientes, Ags. 6 de noviembre de 2019
"""
# %% La clase Linear Decay Schedule o Progresion Lineal de Decreciemiento
class LinearDecaySchedule(object):#Se crea una clase con  un objeto generico de python
    def __init__(self, initial_value, final_value, max_steps):#Se crea el metodo init para inicial los valores
        assert initial_value > final_value, "El valor inicial debe ser estríctamente mayor que el valor final." #Condicion para los valores
        #Aqui se le asignan valores a las variables del objeto
        self.initial_value = initial_value 
        self.final_value = final_value
        self.decay_factor = (initial_value - final_value)/max_steps #Se crea el valor de decarimiento
        
    def __call__(self, step_num): #Con esta funcion se va restando con el factor de decarimiento a cada nuevo estado del agente
        current_value = self.initial_value - step_num * self.decay_factor
        if current_value < self.final_value:
            current_value = self.final_value
        return current_value
    #Con esta funcion podemos ver en tiempo real todas las acciones de la funcion de decarimiento para epsilon
# %% La funcion de ejecucion
if __name__ == "__main__": 
    import matplotlib.pyplot as plt
    epsilon_initial = 1.0 #Valor del cual iniciará
    epsilon_final = 0.005 #Valor de destino
    MAX_NUM_EPISODES = 10000
    STEPS_PER_EPISODE = 300
    #Aqui podemos opservar como se va reduciendo el epsilon desde su valor inicial "1.0" hasta el minimo "0.05"
    linear_schedule = LinearDecaySchedule(initial_value = epsilon_initial,
                                          final_value = epsilon_final, 
                                          #Antes del valor que se de "0.5" el agente estará en modo de aprendizaje, despues de ello aprendera
                                          max_steps = 0.5 * MAX_NUM_EPISODES * STEPS_PER_EPISODE)
    epsilons = [linear_schedule(step) for step in range(MAX_NUM_EPISODES * STEPS_PER_EPISODE)]
    #Aqui generamos en diagrama y lo mostramos en pantalla
    plt.plot(epsilons)
    plt.show()