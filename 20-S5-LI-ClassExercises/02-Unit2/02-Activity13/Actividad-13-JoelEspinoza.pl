/* Predicates
hombre(symbol,integer).
mujer(symbol,integer).
padre(symbol,symbol).
madre(symbol,symbol).
papas(symbol,symbol,symbol).
persona(symbol).
suma_hombres(integer).
*/


/* Clauses */
hombre(jose,62).
hombre(jose,20).
hombre(pedro,50).
hombre(luis,40).

mujer(lupe,40).
mujer(irma,40).
mujer(maria,40).

padre(jose,lupe).
padre(pedro,luis).
padre(luis,jose).

madre(maria,luis).
madre(lupe,jose).

papas(X,Y,Z):-padre(X,Y),madre(Y,Z).

persona(X):-hombre(X,W),W<40.
persona(X):-mujer(X,W),W<40.

suma_hombres(S):-hombre(_,Y),S1=S+Y,write(S1),suma_hombres(S1).
suma_hombres(S).