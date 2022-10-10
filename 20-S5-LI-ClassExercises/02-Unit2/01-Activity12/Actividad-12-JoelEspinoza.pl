/* Definición de los padres */
padre(daniel,consuelo).
padre(daniel,mary).
padre(daniel,emanuel).

padre(emanuel,dany).
padre(emanuel,paola).

padre(josedejesus,joseluis).
padre(josedejesus,alicia).
padre(josedejesus,martha).
padre(josedejesus,juancarlos).
padre(josedejesus,armando).

padre(joseluis,joel).
padre(joseluis,joseluisjr).

padre(juancarlos,farrah).

padre(armando,luisarmando).
padre(armando,lucero).
padre(armando,cristobal).

/* Definición de las madres */
madre(maria,consuelo).
madre(maria,mary).
madre(maria,emanuel).

madre(consuelo,joel).
madre(consuelo,joseluisjr).

madre(mary,fernanda).
madre(mary,emmanuel).

madre(mariadejesus,joseluis).
madre(mariadejesus,alicia).
madre(mariadejesus,martha).
madre(mariadejesus,juancarlos).
madre(mariadejesus,armando).

madre(alicia,tony).

madre(martha,waldo).

/* Regla para hallar la relación hijo o hija */
hijo(X,Y):-padre(Y,X).
hijo(X,Y):-madre(Y,X).

/* Regla para hallar la relación abuelo o abuela */
abuelo(X,Y):-padre(Z,Y),padre(X,Z).
abuelo(X,Y):-padre(Z,Y),madre(X,Z).
abuelo(X,Y):-madre(Z,Y),madre(X,Z).
abuelo(X,Y):-madre(Z,Y),padre(X,Z).

/* Regla para hallar la relación hermano o hermana */
hermano(X,Y):-padre(Z,X),padre(Z,Y),X\=Y.
hermano(X,Y):-madre(Z,X),madre(Z,Y),X\=Y.

/* Regla para hallar la relación tío o tía */
tio(X,Y):-hermano(X,Z),padre(Z,Y).
tio(X,Y):-hermano(X,Z),madre(Z,Y).

/* Regla para hallar la relación esposo o esposa */
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

/* Regla para hallar la relación bisabuelo o bisabuela */
bisabuelo(X,Y):-abuelo(X,Z),padre(Z,Y).
bisabuelo(X,Y):-abuelo(X,Z),madre(Z,Y).

/* Regla para hallar la relación bisnieto o bisnieta */
bisnieto(X,Y):-bisabuelo(Y,X).

/* Regla para hallar la relación yerno o nuera */
yerno_nuera(X,Y):-hijo(Z,Y),esposo(X,Z).

/* Regla para hallar la relación suegro o suegra */
suegro(X,Y):-yerno_nuera(Y,X).