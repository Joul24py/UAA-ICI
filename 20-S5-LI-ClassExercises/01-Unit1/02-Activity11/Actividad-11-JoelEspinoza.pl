persona(luis).
persona(johnny).
persona(emmanuel).
persona(pol).

/*
CONSULTAS

?- persona(_).

?- persona(X).

?- persona(luis).

?- persona(juan).
*/

estilo(thefold,rock).
estilo(alanwalker,electronica).
estilo(avicii,electronica).
estilo(thescore,rock).
estilo(edsheeran,pop).
estilo(greenday,punk).
estilo(eminem,rap).

/*
CONSULTAS

?- estilo(_,rock).

?- estilo(Banda,pop).

?- estilo(_,electronica).

?- estilo(_,clasica).

?- estilo(Banda,Estilo).
*/

escuchoeltema(luis,tema(medicine,thefold)).
escuchoeltema(luis,tema(love,thefold)).
escuchoeltema(luis,tema(stay,thescore)).
escuchoeltema(luis,tema(photograph,edsheeran)).

escuchoeltema(johnny,tema(medicine,thefold)).
escuchoeltema(johnny,tema(faded,alanwalker)).
escuchoeltema(johnny,tema(wakemeup,avicii)).
escuchoeltema(johnny,tema(berzerk,eminem)).

escuchoeltema(emmanuel,tema(medicine,thefold)).
escuchoeltema(emmanuel,tema(love,thefold)).
escuchoeltema(emmanuel,tema(faded,alanwalker)).
escuchoeltema(emmanuel,tema(wakemeup,avicii)).
escuchoeltema(emmanuel,tema(photograph,edsheeran)).

escuchoeltema(pol,tema(stay,thescore)).
escuchoeltema(pol,tema(holiday,greenday)).
escuchoeltema(pol,tema(berzerk,eminem)).

/*
CONSULTAS

?- escuchoeltema(_,_).

?- escuchoeltema(pol,tema(berzerk,eminem)).
*/

escuchoelestilo(Persona,Estilo) :- escuchoeltema(Persona,tema(Nombre,Banda)),estilo(Banda,Estilo).

/*
CONSULTAS

?- escuchoelestilo(_,rock).

?- escuchoelestilo(Persona,pop).
*/
