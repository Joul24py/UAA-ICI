import random
import matplotlib.pyplot as plt

qObjects = 10
qBackpacks = 10
weightRange = [1, 100]
utilityRange = [0, 100]
maxWeight = 250

# Armado de la estructura objects
objects = [[], []]
for i in range(qObjects):
    objects[0].append(random.randint(weightRange[0], weightRange[1]))
    objects[1].append(random.randint(utilityRange[0], utilityRange[1]))
print("Objetos:")
print(objects)

# Armado de la estructura backpacks y evaluations
backpacks = []
evaluations = [[], []]
for i in range(qBackpacks):
    while True:
        totalWeight = 0
        totalUtility = 0
        backpack = []
        for j in range(qObjects):
            backpack.append(random.randint(0, 1))
            totalWeight = totalWeight + (backpack[j] * objects[0][j])
            totalUtility = totalUtility + (backpack[j] * objects[1][j])
        if totalWeight < maxWeight:
            break
    backpacks.append(backpack)
    evaluations[0].append(totalWeight)
    evaluations[1].append(totalUtility)
print("Mochilas:")
print(backpacks)
print("Evaluaciones")
print(evaluations)

'''
El Frente de Pareto de este problema es el máximo
de utilidad (tener los mejores objetos) y el máximo
de peso (aprovechar de la mejor manera la mochila)
'''

dominated = []
for i in range(qBackpacks):
    for j in range(qBackpacks):
        if i == j:
            continue
        flag = 0
        if (evaluations[0][i] < evaluations[0][j]) and (evaluations[1][i] < evaluations[1][j]):
            flag = 1
            break
    if flag == 0:
        dominated.append(i + 1)
print("Soluciones no dominadas")
print(dominated)

tags = []
for i in range(qBackpacks):
    tags.append(str(i + 1))
plt.scatter(evaluations[0], evaluations[1], c = 'yellow')
for i, label in enumerate(tags):
    plt.annotate(label, (evaluations[0][i], evaluations[1][i]))
plt.show()