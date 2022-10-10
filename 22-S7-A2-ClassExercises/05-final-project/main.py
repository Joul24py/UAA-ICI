#%% Portada
'''
                 Centro de Ciencias Básicas
         Departamento de Ciencias de la Computación
                        Autómatas II
                           7° "A"

                      Proyecto Final

         Profesor: Francisco Javier Ornelas Zapata

         Alumnos:
                  Almeida Ortega Andrea Melissa
                  Espinoza Sánchez Joel Alejandro
                  Flores Fernández Óscar Alonso
                  Gómez Garza Dariana
                  González Arenas Fernando Francisco
                  Orocio García Hiram Efraín

Fecha de Entrega: Aguascalientes, Ags., 3 de diciembre de 2021
'''

#%% Simulator
# initial values
import sys

from numpy.core.umath import pi
from numpy.ma import sin

scale = 50  # 1m -> 50 cells
size_x = 6 * scale
size_y = 4 * scale
damping = 0.99
omega = 3 / (2 * pi)

initial_P = 200
vertPos = size_y - 3 * scale
horizPos = 1 * scale
wallTop = size_y - 3 * scale
wall_x_pos = 2 * scale
max_pressure = initial_P / 2
min_presure = -initial_P / 2


class Simulation:
    def __init__(self):
        self.frame = 0
        self.pressure = [[0.0 for x in range(size_x)] for y in range(size_y)]
        # outflow velocities from each cell
        self._velocities = [[[0.0, 0.0, 0.0, 0.0] for x in range(size_x)] for y in range(size_y)]
        self.pressure[vertPos][horizPos] = initial_P

    def updateV(self):
        """Recalculate outflow velocities from every cell basing on preassure difference with each neighbour"""
        V = self._velocities
        P = self.pressure
        for i in range(size_y):
            for j in range(size_x):
                if wall[i][j] == 1:
                    V[i][j][0] = V[i][j][1] = V[i][j][2] = V[i][j][3] = 0.0
                    continue
                cell_pressure = P[i][j]
                V[i][j][0] = V[i][j][0] + cell_pressure - P[i - 1][j] if i > 0 else cell_pressure
                V[i][j][1] = V[i][j][1] + cell_pressure - P[i][j + 1] if j < size_x - 1 else cell_pressure
                V[i][j][2] = V[i][j][2] + cell_pressure - P[i + 1][j] if i < size_y - 1 else cell_pressure
                V[i][j][3] = V[i][j][3] + cell_pressure - P[i][j - 1] if j > 0 else cell_pressure

    def updateP(self):
        for i in range(size_y):
            for j in range(size_x):
                self.pressure[i][j] -= 0.5 * damping * sum(self._velocities[i][j])

    def step(self):
        self.pressure[vertPos][horizPos] = initial_P * sin(omega * self.frame)
        self.updateV()
        self.updateP()
        self.frame += 1


argc = len(sys.argv)
if argc > 1 and sys.argv[1] == '1':
    wall = [[1 if x == wall_x_pos and wallTop < y < size_y else 0
             for x in range(size_x)] for y in range(size_y)]
elif argc > 1 and sys.argv[1] == '2':
    wall = [[1 if (x == wall_x_pos and wallTop + scale < y < size_y) or
                  (wall_x_pos - scale < x < wall_x_pos and
                   x - wall_x_pos == y - wallTop - scale - 1) or
                  (wall_x_pos < x < wall_x_pos + scale and
                   x - wall_x_pos == -y + wallTop + scale + 1)
             else 0
             for x in range(size_x)] for y in range(size_y)]
else:
    wall = [[1 if (x == wall_x_pos and wallTop + scale < y < size_y) or
                  (wall_x_pos - scale < x < wall_x_pos and
                   x - wall_x_pos == y - wallTop - scale - 1) or
                  (wall_x_pos < x < wall_x_pos + scale and
                   x - wall_x_pos == -y + wallTop + scale + 1) or
                  (wall_x_pos - 0.75 * scale < x < wall_x_pos - scale / 2 and
                   x - wall_x_pos == -y + wallTop - scale / 2 + 1) or
                  (wall_x_pos + scale / 2 < x < wall_x_pos + 0.75 * scale and
                   x - wall_x_pos == y - wallTop + scale / 2 - 1)
             else 0
             for x in range(size_x)] for y in range(size_y)]

#%% Main
from sys import argv

import matplotlib
from matplotlib.animation import FuncAnimation, FFMpegWriter
from matplotlib.colors import LinearSegmentedColormap, colorConverter

#from simulation.py import Simulation, min_presure, max_pressure, scale, wall

matplotlib.use('Qt5Agg')
import matplotlib.pyplot as plt

simulation = Simulation()
figure = plt.figure()
ca_plot = plt.imshow(simulation.pressure, cmap='seismic', interpolation='bilinear', vmin=min_presure, vmax=max_pressure)
plt.colorbar(ca_plot)
transparent = colorConverter.to_rgba('black', alpha=0)
wall_colormap = LinearSegmentedColormap.from_list('my_colormap', [transparent, 'green'], 2)
plt.imshow(wall, cmap=wall_colormap, interpolation='bilinear', zorder=2)


def animation_func(i):
    simulation.step()
    ca_plot.set_data(simulation.pressure)
    return ca_plot


if len(argv) > 2 and argv[2] == 'save':
    writer = FFMpegWriter(fps=30)
    frames = 100
    with writer.saving(figure, "writer_test.mp4", 200):
        for i in range(frames):
            animation_func(i)
            writer.grab_frame()
            print(f'\rframe: {i}/{frames}', end='')
else:
    animation = FuncAnimation(figure, animation_func, interval=1)
    mng = plt.get_current_fig_manager()
    mng.window.showMaximized()
    plt.title(f"1 m -> {scale} cells, 1 cell -> {1 / scale}m")
    plt.show()