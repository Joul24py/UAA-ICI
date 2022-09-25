# %% Presentacion
"""
UNIVERSIDAD AUTÓNOMA DE AGUASCALIENTES

Centro de Ciencias Básicas
Departamento de Ciencas de la Computación
Inteligencia Artificial
3° "A"

Proyecto/Examen: Implementación de una Red Neuronal en Videojuegos
Anexo 2.02: Programa 2

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
# %% La clase SLP (Single Layer Perceptron)
class SLP(torch.nn.Module):
    
    def __init__(self, input_shape, output_shape, device = torch.device("cpu")):
        """
        :param input_shape: Longitud o forma de los datos de entrada
        :param output_shape: Longitud o forma de los datos de salida
        :param device: El dispositivo ('cpu' o 'cuda') que la SLP debe utilizar para almacenar los inputs a cada iteracion
        """
        super(SLP, self).__init__()
        self.device = device
        self.input_shape = input_shape[0]
        self.hidden_shape = 40
        self.linear1 = torch.nn.Linear(self.input_shape, self.hidden_shape)
        self.out = torch.nn.Linear(self.hidden_shape, output_shape)
        
        
    def forward(self, x):
        x = torch.from_numpy(x).float().to(self.device)
        x = torch.nn.functional.relu(self.linear1(x))##Funcion de activacion RELU
        x = self.out(x)
        return x