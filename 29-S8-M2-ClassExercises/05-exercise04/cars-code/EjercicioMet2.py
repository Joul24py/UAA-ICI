import random
import matplotlib.pyplot as plt

qBackpacks = 7

evaluations = [[130, 310, 105, 106, 169, 174, 271],
               [17.5, 14, 17.5, 17.5, 14.5, 25, 11.5],
               [615000, 880000, 272000, 235900, 450000, 404990, 779000]]

print("Evaluaciones")
print(evaluations)

'''
El Frente de Pareto de este problema es el máximo
de utilidad (tener los mejores objetos) y el máximo
de peso (aprovechar de la mejor manera la mochila)

El Frente de Pareto de este problema
es el máximo de motor (tener los
mejores objetos), el mínimo de consumo
de gasolina y el mínimo de precio
'''

dominated = []
for i in range(qBackpacks):
    for j in range(qBackpacks):
        if i == j:
            continue
        flag = 0
        if (evaluations[0][i] < evaluations[0][j]) and (evaluations[1][i] > evaluations[1][j]) and (evaluations[2][i] > evaluations[2][j]):
            flag = 1
            break
    if flag == 0:
        dominated.append(i + 1)
print("Soluciones no dominadas")
print(dominated)

fig = plt.figure()
ax = fig.add_subplot(projection='3d')

tags = []
for i in range(qBackpacks):
    tags.append(str(i + 1))
ax.scatter(evaluations[0], evaluations[1], evaluations[2], c = 'blue')
ax.set_xlabel("Caballos de fuerza")
ax.set_ylabel("Consumo de gasolina")
ax.set_zlabel("Precio")
plt.show()