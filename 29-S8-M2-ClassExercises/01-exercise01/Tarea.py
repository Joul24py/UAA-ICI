#%% Instrucciones
'''
Realizar un programa que genere aleatoriamente 10 cadenas de 10 bits (unos y
ceros) cada cadena, y que en una segunda lista genere al azar el intercambio
de la primera con la última cadena generando dos nuevas cadenas y poner así
las 10 nuevas cadenas mezclando 1-10, 2-9, 3-8, 4-7 y 5-6
'''
#%% Se incluyen las librerías
import random
import math

#%% Función para construir una cadena de bits :O
def CreateString(length):
    # Se construye la cadena de bits
    top = (2**length) - 1
    string = random.randint(0, top)
    string = bin(string)
    string = string[2:]
    
    # En caso de que la cadena no sea de 10 bits, se completará
    remain_bits = 10 - len(string)
    string = '0'*remain_bits + string
    return string

#%% Función para mexclar dos miembros de la población
def Mix(input1, input2):
    output1 = ''
    output2 = ''
    for i in range(len(input1)):
        if random.randint(0,1) == 1:
            output1 = output1 + input1[i]
            output2 = output2 + input2[i]
        else:
            output1 = output1 + input2[i]
            output2 = output2 + input1[i]
    return output1, output2

#%% Procedimiento principal
def main(n = 10, length = 10):
    sample = []
    for i in range(n):
        sample.append(CreateString(length))
    print("Población:")
    print(sample)
    
    print("Intercambio:")
    for i in range(math.ceil(n/2)):
        print("Cadena " + str(i + 1) + " y " + str(n - i) + ":")
        sample[i], sample[n - i - 1] = Mix(sample[i], sample[n - i - 1])
    print("Nueva población:")
    print(sample)