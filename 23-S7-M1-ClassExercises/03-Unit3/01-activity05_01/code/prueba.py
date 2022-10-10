import pandas as pd

datos = pd.read_csv("Sentimiento.csv")

for i in datos.iloc[:,3]:
    hola = i.replace(" \'compound\': ","")
    hola = hola.replace("} ","")
    print(hola + " " + str(round(float(hola))))