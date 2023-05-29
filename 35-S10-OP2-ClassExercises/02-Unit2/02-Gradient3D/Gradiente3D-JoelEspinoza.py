# Importar librerías necesarias
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Definición de funciones
def f(x,y):
    return x**2 + y**3

def g(x,y):
    return np.array([2*x, 3*y*y])

# Definición de parámetros
alpha = 0.1  # tasa de aprendizaje
num_iters = 100  # número de iteraciones
x0 = np.array([2,2])  # punto inicial

# Descenso del gradiente
def grad_desc_3d(f, g, alpha, num_iters, x0):
    x = np.zeros((num_iters+1,2))
    x[0,:] = x0
    for i in range(num_iters):
        x[i+1,:] = x[i,:] - alpha*g(x[i,0], x[i,1])
    return x

# Ejecución del descenso del gradiente
coords = grad_desc_3d(f, g, alpha, num_iters, x0)

# Graficación del resultado
x = np.linspace(-5, 5, 50)
y = np.linspace(-5, 5, 50)
X, Y = np.meshgrid(x, y)
Z = f(X,Y)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.plot(coords[:,0], coords[:,1], f(coords[:,0], coords[:,1]), color='r')
ax.plot_surface(X, Y, Z, cmap='coolwarm', alpha=0.7)

plt.show()