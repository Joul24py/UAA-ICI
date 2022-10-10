#%% Datos del programa
'''
Autor: Joel Alejandro Espinoza Sánchez
Fecha: 01/09/2020
Descripción:
    El programa pide un número inicial (x1) y a un número determinado de
    participantes (p) en donde cada uno proporcionará un número con la
    misma cantidad de dígitos que el primer número. Al final todos estos
    deben sumar otro dado (total)
    
    Los números de los participantes se guardan en la lista números
    Los complementos que permiten llegar a total se guardan en la
    lista complementos
    Para conocer la cantidad de dígitos de x1 se usa lenx1
    Para conocer el tope al que debe llegar la suma entre cada número de
    los participantes y cada complemento propuesto por el mago, este
    número se determina con tope
'''

#%% Pedimos el número inicial
print("==================== COMENCEMOS ====================")
x1 = input("Escriba un número: ")
print("")

#%% Verificamos que el número sea válido
while True:
    try:
        x1 = int(x1)
        lenx1 = len(str(x1))
        if not (lenx1 > 1):
            print("El número que introdujo no es un número entero válido")
            raise Exception
        break
    except:
        print("El número a introducir debe ser uno tal que tenga por lo menos dos dígitos")
        x1 = input("Introduzca un nuevo número: ")
        print("")

#%% Con la información que tenemos, podemos pedir el número que se debe alcanzar tras la suma de complementos
tope = 0
for i in range(lenx1):
    tope = (tope*10) + 9

#%% Pedimos la cantidad de participantes en el juego
print("================== PARTICIPANTES ==================")
p = input("Escriba la cantidad de participantes que nos proporcionarán un número: ")
print("")

#%% Verificamos que el número sea válido
while True:
    try:
        p = int(p)
        if not (p > 0):
            print("La cantidad de participantes que introdujo no es un número entero válido")
            raise Exception
        break
    except:
        print("La cantidad de participantes debe ser un número entero mayor a 0")
        p = input("Introduzca una nueva cantidad de participantes: ")
        print("")

#%% ¡Qué comience la magia!
total = x1 + (p*tope)
print("==================== A PREDECIR ====================")
print("")
print("Yo sé que llegaremos al siguiente número: " + str(total))
print("")

#%% Pediremos el número de cada participante
print("================ HORA DE PARTICIPAR ================")
numeros = []
complementos = []
for i in range(p):
    print("Participante " + str(i + 1) + ":")
    xnew = input("Escriba un número que tenga " + str(lenx1) + " dígitos: ")
    print("")
    while True:
        try:
            xnew = int(xnew)
            dim = xnew // 10 **(lenx1 - 1)
            if (dim < 1) or (dim > 9):
                print("El número que introdujo no es un número entero válido")
                raise Exception
            break
        except:
            print("El número otorgado debe ser un número entero positivo con " + str(lenx1) + " dígitos")
            xnew = input("Introduzca un nuevo número: ")
            print("")
    numeros.append(xnew)
    complementos.append(tope - xnew)

#%% Desplegamos los valores al usuario
print("================== HAGAMOS MAGIA ==================")
print("")
print("Voy a proponer algunos números para cada número de los participantes y veamos cuánto suman los números siguientes:")
print("")
print("El primer número indicado fue " + str(x1))
print("")
for i in range(p):
    print("El participante " + str(i + 1) + " ha dado el número " + str(numeros[i]))
    print("Y yo propongo el número " + str(complementos[i]))
    print("")

print("Ahora comprueba si los anteriores números suman " + str(total))
print("")
print("¡VERDADERA MAGIA!")