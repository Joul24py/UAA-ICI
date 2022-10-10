p_Asma_Bronquial = [[[90, 10],
                     [10, 90]],
                    [[40, 60],
                     [60, 40]],
                    [[50, 50],
                     [50, 50]]]

p_Bronquitis_Aguda = [[[30, 70],
                       [70, 30]],
                      [[48, 52],
                       [52, 48]],
                      [[20, 80],
                       [80, 20]],
                      [[60, 40],
                       [40, 60]]]

p_Gripe = [[[40, 60],
            [60, 40]],
           [[20, 80],
            [80, 20]],
           [[50, 50],
            [50, 50]],
           [[80, 20],
            [20, 80]],
           [[90, 10],
            [10, 90]],
           [[50, 50],
            [50, 50]],
           [[45.454, 54.545],
            [54.545, 45.454]]]

p_Influenza = [[[80, 20],
                [20, 80]],
               [[50, 50],
                [50, 50]],
               [[90, 10],
                [10, 90]],
               [[40, 60],
                [60, 40]]]

p_COVID = [[[33.333, 66.666],
            [66.666, 33.333]],
           [[90, 10],
            [10, 90]],
           [[54.545, 45.454],
            [45.454, 54.545]],
           [[60, 40],
            [40, 60]],
           [[40, 60],
            [60, 40]]]

p_Obstruccion_Bronquial = [[[30, 70],
                            [70, 30]],
                           [[90, 10],
                            [10, 90]]]

p_Broncoconstriccion = [[[90, 10],
                         [10, 90]],
                        [[16.666, 83.333],
                         [83.333, 16.666]]]

p_Rinitis_Alergica = [[[90, 10],
                       [10, 90]],
                      [[25, 75],
                       [75, 25]],
                      [[90, 10],
                       [10, 90]]]

p_Flujo_Nasal = [[[50, 50],
                  [50, 50]],
                 [[75, 25],
                  [25, 75]]]

p_Sepsis = [[[90, 10],
             [10, 90]],
            [[26.666, 73.333],
             [73.333, 26.666]],
            [[90, 10],
             [10, 90]],
            [[90, 10],
             [10, 90]]]

p_Inflamacion_Via_Aerea = [[[90, 10],
                            [10, 90]],
                           [[83.333, 16.666],
                            [16.666, 83.333]],
                           [[2, 98],
                            [98, 2]]]

p_Fatiga = [[[90, 10],
             [10, 90]],
            [[66.666, 33.333],
             [33.333, 66.666]]]

p_Mialgia = [[[90, 10],
              [10, 90]],
             [[33.333, 66.666],
              [66.666, 33.333]]]

Alta_Recurrencia = 0
Pocos_Dias = 0
Gradual = 0
Garganta_Cerrada = 0
Comezon_Ojos = 0
Ojos_Llorosos = 0
Estornudos = 0
Moqueo = 0
Ritmo_Cardiaco_Acelerado = 0
Baja_Presion = 0
Inflamacion_Corporal = 0
Dolor_Garganta = 0
Dificultad_Respiratoria = 0
Dolor_Cabeza = 0
Dolor_Muscular = 0
Cansancio = 0
Cuerpo_Cortado = 0
Tos = 0
Fiebre = 0



import random

aleatorio = 1
if aleatorio == 1:
    Alta_Recurrencia = random.randint(0,1)
    Pocos_Dias = random.randint(0,1)
    Gradual = random.randint(0,1)
    Garganta_Cerrada = random.randint(0,1)
    Comezon_Ojos = random.randint(0,1)
    Ojos_Llorosos = random.randint(0,1)
    Estornudos = random.randint(0,1)
    Moqueo = random.randint(0,1)
    Ritmo_Cardiaco_Acelerado = random.randint(0,1)
    Baja_Presion = random.randint(0,1)
    Inflamacion_Corporal = random.randint(0,1)
    Dolor_Garganta = random.randint(0,1)
    Dificultad_Respiratoria = random.randint(0,1)
    Dolor_Cabeza = random.randint(0,1)
    Dolor_Muscular = random.randint(0,1)
    Cansancio = random.randint(0,1)
    Cuerpo_Cortado = random.randint(0,1)
    Tos = random.randint(0,1)
    Fiebre = random.randint(0,1)



# Mialgia
randomNumber = random.randint(0,100)
Mialgia = 0
if Cuerpo_Cortado == 1:
    if randomNumber < p_Mialgia[0][0][0]:
        Mialgia = Mialgia + 1
if Cuerpo_Cortado == 0:
    if randomNumber < p_Mialgia[0][1][0]:
        Mialgia = Mialgia + 1
if Cansancio == 1:
    if randomNumber < p_Mialgia[1][0][0]:
        Mialgia = Mialgia + 1
if Cansancio == 0:
    if randomNumber < p_Mialgia[1][1][0]:
        Mialgia = Mialgia + 1

randomNumber = random.randint(0,100)
Mialgia = (Mialgia / len(p_Mialgia)) * 100
if randomNumber < Mialgia:
    Mialgia = 1
else:
    Mialgia = 0

# Fatiga
randomNumber = random.randint(0,100)
Fatiga = 0
if Dolor_Muscular == 1:
    if randomNumber < p_Fatiga[0][0][0]:
        Fatiga = Fatiga + 1
if Dolor_Muscular == 0:
    if randomNumber < p_Fatiga[0][1][0]:
        Fatiga = Fatiga + 1
if Cansancio == 1:
    if randomNumber < p_Fatiga[1][0][0]:
        Fatiga = Fatiga + 1
if Cansancio == 0:
    if randomNumber < p_Fatiga[1][1][0]:
        Fatiga = Fatiga + 1

randomNumber = random.randint(0,100)
Fatiga = (Fatiga / len(p_Fatiga)) * 100
if randomNumber < Fatiga:
    Fatiga = 1
else:
    Fatiga = 0

# Inflamación de las Vías Aéreas
randomNumber = random.randint(0,100)
Inflamacion_Via_Aerea = 0
if Dificultad_Respiratoria == 1:
    if randomNumber < p_Inflamacion_Via_Aerea[0][0][0]:
        Inflamacion_Via_Aerea = Inflamacion_Via_Aerea + 1
if Dificultad_Respiratoria == 0:
    if randomNumber < p_Inflamacion_Via_Aerea[0][1][0]:
        Inflamacion_Via_Aerea = Inflamacion_Via_Aerea + 1
if Tos == 1:
    if randomNumber < p_Inflamacion_Via_Aerea[1][0][0]:
        Inflamacion_Via_Aerea = Inflamacion_Via_Aerea + 1
if Tos == 0:
    if randomNumber < p_Inflamacion_Via_Aerea[1][1][0]:
        Inflamacion_Via_Aerea = Inflamacion_Via_Aerea + 1
if Moqueo == 1:
    if randomNumber < p_Inflamacion_Via_Aerea[1][0][0]:
        Inflamacion_Via_Aerea = Inflamacion_Via_Aerea + 1
if Moqueo == 0:
    if randomNumber < p_Inflamacion_Via_Aerea[1][1][0]:
        Inflamacion_Via_Aerea = Inflamacion_Via_Aerea + 1

randomNumber = random.randint(0,100)
Inflamacion_Via_Aerea = (Inflamacion_Via_Aerea / len(p_Inflamacion_Via_Aerea)) * 100
if randomNumber < Inflamacion_Via_Aerea:
    Inflamacion_Via_Aerea = 1
else:
    Inflamacion_Via_Aerea = 0

# Sepsis
randomNumber = random.randint(0,100)
Sepsis = 0
if Inflamacion_Corporal == 1:
    if randomNumber < p_Sepsis[0][0][0]:
        Sepsis = Sepsis + 1
if Inflamacion_Corporal == 0:
    if randomNumber < p_Sepsis[0][1][0]:
        Sepsis = Sepsis + 1
if Fiebre == 1:
    if randomNumber < p_Sepsis[1][0][0]:
        Sepsis = Sepsis + 1
if Fiebre == 0:
    if randomNumber < p_Sepsis[1][1][0]:
        Sepsis = Sepsis + 1
if Baja_Presion == 1:
    if randomNumber < p_Sepsis[1][0][0]:
        Sepsis = Sepsis + 1
if Baja_Presion == 0:
    if randomNumber < p_Sepsis[1][1][0]:
        Sepsis = Sepsis + 1
if Ritmo_Cardiaco_Acelerado == 1:
    if randomNumber < p_Sepsis[1][0][0]:
        Sepsis = Sepsis + 1
if Ritmo_Cardiaco_Acelerado == 0:
    if randomNumber < p_Sepsis[1][1][0]:
        Sepsis = Sepsis + 1

randomNumber = random.randint(0,100)
Sepsis = (Sepsis / len(p_Sepsis)) * 100
if randomNumber < Sepsis:
    Sepsis = 1
else:
    Sepsis = 0

# Flujo Nasal
randomNumber = random.randint(0,100)
Flujo_Nasal = 0
if Moqueo == 1:
    if randomNumber < p_Flujo_Nasal[0][0][0]:
        Flujo_Nasal = Flujo_Nasal + 1
if Moqueo == 0:
    if randomNumber < p_Flujo_Nasal[0][1][0]:
        Flujo_Nasal = Flujo_Nasal + 1
if Estornudos == 1:
    if randomNumber < p_Flujo_Nasal[1][0][0]:
        Flujo_Nasal = Flujo_Nasal + 1
if Estornudos == 0:
    if randomNumber < p_Flujo_Nasal[1][1][0]:
        Flujo_Nasal = Flujo_Nasal + 1

randomNumber = random.randint(0,100)
Flujo_Nasal = (Flujo_Nasal / len(p_Flujo_Nasal)) * 100
if randomNumber < Flujo_Nasal:
    Flujo_Nasal = 1
else:
    Flujo_Nasal = 0

# Rinitis Alérgica
randomNumber = random.randint(0,100)
Rinitis_Alergica = 0
if Ojos_Llorosos == 1:
    if randomNumber < p_Rinitis_Alergica[0][0][0]:
        Rinitis_Alergica = Rinitis_Alergica + 1
if Ojos_Llorosos == 0:
    if randomNumber < p_Rinitis_Alergica[0][1][0]:
        Rinitis_Alergica = Rinitis_Alergica + 1
if Estornudos == 1:
    if randomNumber < p_Rinitis_Alergica[1][0][0]:
        Rinitis_Alergica = Rinitis_Alergica + 1
if Estornudos == 0:
    if randomNumber < p_Rinitis_Alergica[1][1][0]:
        Rinitis_Alergica = Rinitis_Alergica + 1
if Comezon_Ojos == 1:
    if randomNumber < p_Rinitis_Alergica[1][0][0]:
        Rinitis_Alergica = Rinitis_Alergica + 1
if Comezon_Ojos == 0:
    if randomNumber < p_Rinitis_Alergica[1][1][0]:
        Rinitis_Alergica = Rinitis_Alergica + 1

randomNumber = random.randint(0,100)
Rinitis_Alergica = (Rinitis_Alergica / len(p_Rinitis_Alergica)) * 100
if randomNumber < Rinitis_Alergica:
    Rinitis_Alergica = 1
else:
    Rinitis_Alergica = 0

# Broncoconstricción
randomNumber = random.randint(0,100)
Broncoconstriccion = 0
if Garganta_Cerrada == 1:
    if randomNumber < p_Broncoconstriccion[0][0][0]:
        Broncoconstriccion = Broncoconstriccion + 1
if Garganta_Cerrada == 0:
    if randomNumber < p_Broncoconstriccion[0][1][0]:
        Broncoconstriccion = Broncoconstriccion + 1
if Tos == 1:
    if randomNumber < p_Broncoconstriccion[1][0][0]:
        Broncoconstriccion = Broncoconstriccion + 1
if Tos == 0:
    if randomNumber < p_Broncoconstriccion[1][1][0]:
        Broncoconstriccion = Broncoconstriccion + 1

randomNumber = random.randint(0,100)
Broncoconstriccion = (Broncoconstriccion / len(p_Broncoconstriccion)) * 100
if randomNumber < Broncoconstriccion:
    Broncoconstriccion = 1
else:
    Broncoconstriccion = 0

# Obstrucción Bronquial
randomNumber = random.randint(0,100)
Obstruccion_Bronquial = 0
if Inflamacion_Via_Aerea == 1:
    if randomNumber < p_Obstruccion_Bronquial[0][0][0]:
        Obstruccion_Bronquial = Obstruccion_Bronquial + 1
if Inflamacion_Via_Aerea == 0:
    if randomNumber < p_Obstruccion_Bronquial[0][1][0]:
        Obstruccion_Bronquial = Obstruccion_Bronquial + 1
if Broncoconstriccion == 1:
    if randomNumber < p_Obstruccion_Bronquial[1][0][0]:
        Obstruccion_Bronquial = Obstruccion_Bronquial + 1
if Broncoconstriccion == 0:
    if randomNumber < p_Obstruccion_Bronquial[1][1][0]:
        Obstruccion_Bronquial = Obstruccion_Bronquial + 1

randomNumber = random.randint(0,100)
Obstruccion_Bronquial = (Obstruccion_Bronquial / len(p_Obstruccion_Bronquial)) * 100
if randomNumber < Obstruccion_Bronquial:
    Obstruccion_Bronquial = 1
else:
    Obstruccion_Bronquial = 0

# COVID
randomNumber = random.randint(0,100)
COVID = 0
if Fiebre == 1:
    if randomNumber < p_COVID[0][0][0]:
        COVID = COVID + 1
if Fiebre == 0:
    if randomNumber < p_COVID[0][1][0]:
        COVID = COVID + 1
if Mialgia == 1:
    if randomNumber < p_COVID[1][0][0]:
        COVID = COVID + 1
if Mialgia == 0:
    if randomNumber < p_COVID[1][1][0]:
        COVID = COVID + 1
if Fatiga == 1:
    if randomNumber < p_COVID[2][0][0]:
        COVID = COVID + 1
if Fatiga == 0:
    if randomNumber < p_COVID[2][1][0]:
        COVID = COVID + 1
if Dolor_Cabeza == 1:
    if randomNumber < p_COVID[3][0][0]:
        COVID = COVID + 1
if Dolor_Cabeza == 0:
    if randomNumber < p_COVID[3][1][0]:
        COVID = COVID + 1
if Inflamacion_Via_Aerea == 1:
    if randomNumber < p_COVID[4][0][0]:
        COVID = COVID + 1
if Inflamacion_Via_Aerea == 0:
    if randomNumber < p_COVID[4][1][0]:
        COVID = COVID + 1

COVID = (COVID / len(p_COVID)) * 100

# Influenza
randomNumber = random.randint(0,100)
Influenza = 0
if Gradual == 1:
    if randomNumber < p_Influenza[0][0][0]:
        Influenza = Influenza + 1
if Gradual == 0:
    if randomNumber < p_Influenza[0][1][0]:
        Influenza = Influenza + 1
if Dolor_Garganta == 1:
    if randomNumber < p_Influenza[1][0][0]:
        Influenza = Influenza + 1
if Dolor_Garganta == 0:
    if randomNumber < p_Influenza[1][1][0]:
        Influenza = Influenza + 1
if Sepsis == 1:
    if randomNumber < p_Influenza[2][0][0]:
        Influenza = Influenza + 1
if Sepsis == 0:
    if randomNumber < p_Influenza[2][1][0]:
        Influenza = Influenza + 1
if Dolor_Cabeza == 1:
    if randomNumber < p_Influenza[3][0][0]:
        Influenza = Influenza + 1
if Dolor_Cabeza == 0:
    if randomNumber < p_Influenza[3][1][0]:
        Influenza = Influenza + 1

Influenza = (Influenza / len(p_Influenza)) * 100

# Gripe
randomNumber = random.randint(0,100)
Gripe = 0
if Fiebre == 1:
    if randomNumber < p_Gripe[0][0][0]:
        Gripe = Gripe + 1
if Fiebre == 0:
    if randomNumber < p_Gripe[0][1][0]:
        Gripe = Gripe + 1
if Gradual == 1:
    if randomNumber < p_Gripe[1][0][0]:
        Gripe = Gripe + 1
if Gradual == 0:
    if randomNumber < p_Gripe[1][1][0]:
        Gripe = Gripe + 1
if Dolor_Garganta == 1:
    if randomNumber < p_Gripe[2][0][0]:
        Gripe = Gripe + 1
if Dolor_Garganta == 0:
    if randomNumber < p_Gripe[2][1][0]:
        Gripe = Gripe + 1
if Pocos_Dias == 1:
    if randomNumber < p_Gripe[3][0][0]:
        Gripe = Gripe + 1
if Pocos_Dias == 0:
    if randomNumber < p_Gripe[3][1][0]:
        Gripe = Gripe + 1
if Flujo_Nasal == 1:
    if randomNumber < p_Gripe[4][0][0]:
        Gripe = Gripe + 1
if Flujo_Nasal == 0:
    if randomNumber < p_Gripe[4][1][0]:
        Gripe = Gripe + 1
if Alta_Recurrencia == 1:
    if randomNumber < p_Gripe[5][0][0]:
        Gripe = Gripe + 1
if Alta_Recurrencia == 0:
    if randomNumber < p_Gripe[5][1][0]:
        Gripe = Gripe + 1
if Fatiga == 1:
    if randomNumber < p_Gripe[6][0][0]:
        Gripe = Gripe + 1
if Fatiga == 0:
    if randomNumber < p_Gripe[6][1][0]:
        Gripe = Gripe + 1

Gripe = (Gripe / len(p_Gripe)) * 100

# Bronquitis Aguda
randomNumber = random.randint(0,100)
Bronquitis_Aguda = 0
if Inflamacion_Via_Aerea == 1:
    if randomNumber < p_Bronquitis_Aguda[0][0][0]:
        Bronquitis_Aguda = Bronquitis_Aguda + 1
if Inflamacion_Via_Aerea == 0:
    if randomNumber < p_Bronquitis_Aguda[0][1][0]:
        Bronquitis_Aguda = Bronquitis_Aguda + 1
if Moqueo == 1:
    if randomNumber < p_Bronquitis_Aguda[1][0][0]:
        Bronquitis_Aguda = Bronquitis_Aguda + 1
if Moqueo == 0:
    if randomNumber < p_Bronquitis_Aguda[1][1][0]:
        Bronquitis_Aguda = Bronquitis_Aguda + 1
if Pocos_Dias == 1:
    if randomNumber < p_Bronquitis_Aguda[2][0][0]:
        Bronquitis_Aguda = Bronquitis_Aguda + 1
if Pocos_Dias == 0:
    if randomNumber < p_Bronquitis_Aguda[2][1][0]:
        Bronquitis_Aguda = Bronquitis_Aguda + 1
if Rinitis_Alergica == 1:
    if randomNumber < p_Bronquitis_Aguda[3][0][0]:
        Bronquitis_Aguda = Bronquitis_Aguda + 1
if Rinitis_Alergica == 0:
    if randomNumber < p_Bronquitis_Aguda[3][1][0]:
        Bronquitis_Aguda = Bronquitis_Aguda + 1

Bronquitis_Aguda = (Bronquitis_Aguda / len(p_Bronquitis_Aguda)) * 100

# Asma Bronquial
randomNumber = random.randint(0,100)
Asma_Bronquial = 0
if Obstruccion_Bronquial == 1:
    if randomNumber < p_Asma_Bronquial[0][0][0]:
        Asma_Bronquial = Asma_Bronquial + 1
if Obstruccion_Bronquial == 0:
    if randomNumber < p_Asma_Bronquial[0][1][0]:
        Asma_Bronquial = Asma_Bronquial + 1
if Rinitis_Alergica == 1:
    if randomNumber < p_Asma_Bronquial[1][0][0]:
        Asma_Bronquial = Asma_Bronquial + 1
if Rinitis_Alergica == 0:
    if randomNumber < p_Asma_Bronquial[1][1][0]:
        Asma_Bronquial = Asma_Bronquial + 1
if Alta_Recurrencia == 1:
    if randomNumber < p_Asma_Bronquial[2][0][0]:
        Asma_Bronquial = Asma_Bronquial + 1
if Alta_Recurrencia == 0:
    if randomNumber < p_Asma_Bronquial[2][1][0]:
        Asma_Bronquial = Asma_Bronquial + 1

Asma_Bronquial = (Asma_Bronquial / len(p_Asma_Bronquial)) * 100

print("COVID = " + str(COVID))
print("Influenza = " + str(Influenza))
print("Gripe = " + str(Gripe))
print("Bronquitis Aguda = " + str(Bronquitis_Aguda))
print("Asma Bronquial = " + str(Asma_Bronquial))