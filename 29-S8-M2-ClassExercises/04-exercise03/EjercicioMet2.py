# Autor: Joel Alejandro Espinoza Sánchez

import numpy as np

with open('archivo', 'r') as file:
    data = ''.join(file.readlines()).replace('\n', ';')

m = np.matrix(data)

qObjects = m[0,0]
maxWeight = m[0,1]

objects = []

# Ordenamiento por columna 1
for i in range(len(m)):
    if i == 0:
        continue
    else:
        objects.append([m[i,0], m[i,1], m[i,0]])

i = 0
while i < (len(objects) - 1):
    if objects[i][2] < objects[i + 1][2]:
        auxiliar = objects[i]
        objects[i] = objects[i + 1]
        objects[i + 1] = auxiliar
        i = 0
    else:
        i = i + 1

print(objects)
print()

# Ordenamiento por columna 2
for i in range(len(objects)):
    objects[i][2] = objects[i][1]

i = 0
while i < (len(objects) - 1):
    if objects[i][2] < objects[i + 1][2]:
        auxiliar = objects[i]
        objects[i] = objects[i + 1]
        objects[i + 1] = auxiliar
        i = 0
    else:
        i = i + 1

print(objects)
print()

# Ordenamiento por ponderaciones entre ambas columnas
pct1 = 0.5
pct2 = 0.5
for i in range(len(objects)):
    objects[i][2] = (pct1 * objects[i][0]) + (pct2 * objects[i][1])

i = 0
while i < (len(objects) - 1):
    if objects[i][2] < objects[i + 1][2]:
        auxiliar = objects[i]
        objects[i] = objects[i + 1]
        objects[i + 1] = auxiliar
        i = 0
    else:
        i = i + 1

print(objects)