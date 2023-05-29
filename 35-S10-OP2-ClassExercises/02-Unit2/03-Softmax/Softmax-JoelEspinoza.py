import numpy as np
import matplotlib.pyplot as plt

# Definimos la función SoftMax
def softmax(x):
    return np.exp(x) / np.sum(np.exp(x))

# Definimos el intervalo en el que queremos graficar la función SoftMax
x = np.arange(-5, 5, 0.1)

# Calculamos los valores de la función SoftMax para el intervalo dado
y = softmax(x)

# Graficamos la función SoftMax
plt.plot(x, y)

# Etiquetamos los ejes
plt.xlabel('x')
plt.ylabel('SoftMax(x)')

# Mostramos la gráfica
plt.show()
