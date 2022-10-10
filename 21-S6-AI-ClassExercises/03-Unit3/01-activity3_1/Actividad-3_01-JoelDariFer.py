#%% Presentación
'''
   Universidad Autónoma de Aguascalientes

         Centro de Ciencias Básicas
 Departamento de Ciencias de la Computación
          Aprendizaje Inteligente
                   6° "A"

                Actividad 3.01

   Profesor: Francisco Javier Luna Rosas
  Alumnos:
      Espinoza Sánchez Joel Alejandro
      Gómez Garza Dariana
      González Arenas Fernando Francisco

  Fecha de Entrega: 12 de mayo del 2021

Descripción: Regresión lineal en Python
'''

# %% Código
# Uso de librerías
import pandas as pd

# Extracción de archivos
ArchivoCSV = pd.read_csv('C:/Users/alexe/Desktop/datos/prostate_data.csv',
                          engine = 'python', sep=';', decimal=',')
DatosMuestra = ArchivoCSV.values.tolist()

# Inicialización de variables
Componentes = []
n = len(DatosMuestra)
Sx = 0
Sx2 = 0
Sy = 0
Sxy = 0

# Obtención de las sumatorias de los datos
for i in range(8):
    for j in range(n):
        Sx = Sx + DatosMuestra[j][i]
        Sx2 = Sx2 + (DatosMuestra[j][i] * DatosMuestra[j][i])
        Sy = Sy + DatosMuestra[j][8]
        Sxy = Sxy + (DatosMuestra[j][i] * DatosMuestra[j][8])
    
    a = ((n * Sxy) - (Sx * Sy))/((n * Sx2) - (Sx * Sx))
    b = ((Sy) - (a * Sx))/(n)
    Componentes.append([a,b])
print(Componentes)

# Impresión de los resultados
print("RSS = (y1 - " + str(Componentes[0][0]) + " - " + str(Componentes[0][1]) + "x1)^2")
for i in range(7):
    print("+ (y" + str(i + 2) + " - " + 
          str(Componentes[i + 1][0]) + " - " + str(Componentes[i + 1][1]) + "x" + 
          str(i + 2) + ")^2")