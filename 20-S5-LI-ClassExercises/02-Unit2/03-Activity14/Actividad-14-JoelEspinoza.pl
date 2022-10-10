/* Hechos */
persona(abuelaM).
persona(abueloM).
persona(mama).
persona(tiaM).
persona(tioM).
persona(esposaM).
persona(esposoM).
persona(primaM).
persona(bebe).
persona(hermana1).
persona(hermana2).
persona(hermano).
persona(abuelaP).
persona(abueloP).
persona(papa).
persona(tioP).
persona(esposaP).
persona(tiaP).
persona(esposoP).
persona(primoP).

madre(mama,bebe).
madre(mama,hermano).
madre(mama,hermana1).
madre(mama,hermana2).
madre(abuelaM,mama).
madre(abuelaM,tioM).
madre(abuelaM,tiaM).
madre(tiaM,primaM).
madre(abuelaP,papa).
madre(abuelaP,tiaP).
madre(abuelaP,tioP).
madre(tiaM,primoP).

padre(papa,bebe).
padre(papa,hermano).
padre(papa,hermana1).
padre(papa,hermana2).
padre(abueloM,mama).
padre(abueloM,tioM).
padre(abueloM,tiaM).
padre(esposoM,primaM).
padre(abueloP,papa).
padre(abueloP,tiaP).
padre(abueloP,tioP).
padre(esposoP,primoP).


/* Reglas */
/* Regla para hallar la relación hijo o hija */
hijo(X,Y):-padre(Y,X).
hijo(X,Y):-madre(Y,X).

/* Regla para hallar la relación abuelo o abuela */
abuelo_paterno(X,Y):-padre(Z,Y),padre(X,Z).
abuela_paterna(X,Y):-padre(Z,Y),madre(X,Z).
abuela_materna(X,Y):-madre(Z,Y),madre(X,Z).
abuelo_materno(X,Y):-madre(Z,Y),padre(X,Z).

/* Regla para hallar la relación hermano o hermana */
hermano(X,Y):-padre(Z,X),padre(Z,Y),X\=Y.
hermano(X,Y):-madre(Z,X),madre(Z,Y),X\=Y.

/* Regla para hallar la relación tío o tía */
tio(X,Y):-hermano(X,Z),padre(Z,Y).
tio(X,Y):-hermano(X,Z),madre(Z,Y).

/* Regla para hallar la relación esposo o esposa */
esposo(tioM,esposaM).
esposo(tiaP,esposoP).
esposo(tioP,esposaP).
esposo(X,Y):-padre(X,Z),madre(Y,Z).
esposo(X,Y):-madre(X,Z),padre(Y,Z).

/* Regla para hallar la relación primo o prima */
primo(X,Y):-padre(Z,X),tio(Z,Y).
primo(X,Y):-madre(Z,X),tio(Z,Y).

/* Regla para hallar la relación cuñado o cuñada */
cunado(X,Y):-hermano(Z,Y),esposo(Z,X).
cunado(X,Y):-hermano(Z,X),esposo(Z,Y).

/* Regla para hallar la relación nieto o nieta */
nieto(X,Y):-abuelo(Y,X).

/* Regla para hallar la relación nieto o nieta */
sobrino(X,Y):-hermano(Y,Z),padre(Z,X).
sobrino(X,Y):-hermano(Y,Z),madre(Z,X).