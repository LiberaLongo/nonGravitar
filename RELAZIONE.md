# RELAZIONE

## albero delle eredità:

```
ListaParent <--- Lista
  ^cpp             ^cpp
   --includeTemplate--
```

Direzione <-- Proiettile

Entity <-- [ Navicella, Bunker ]

cScreen  <-- [ visualePianeta, visualeSistemaSolare, visualeMenu, visualeOpzioni ]

## albero delle dipendenze
```
indipendenti:
[ utils, cScreen, DisegnabileI ]

Lista <-- ListaParent <-- utils

includeTemplate <-- [ Lista, Lista.cpp, ListaParent.cpp ]

ColoreRGB <-- [ utils ]

Punto <-- [ utils, DisegnabileI ]

Button <-- [ utils, DisegnabileI ]
        ^- Punto ...
        ^- ColoreRGB ...

Direzione <-- [ utils, DisegnabileI ]
           ^- Punto ...

Fuel <-- [ utils, DisegnabileI ]
      ^- ColoreRGB ...
      ^- Punto ...

Poligono <-- includeTemplate ...
          ^- Punto ...
          ^- ColoreRGB ...

Proiettile <-- [ DisegnabileI ]
            ^- Direzione ...
            ^- ColoreRGB ...
            ^- Poligono ...

Entity <-- [ utils, DisegnabileI]
        ^- Direzione
        ^- Proiettile

//ATTENZIONE! cpp inclusi per classi template
#include "./includeTemplate.hpp"

Bunker <-- [ DisegnabileI ]
        ^-Entity ...

Pianeta <-- includeTemplate ...
         ^- Fuel ...
         ^- Poligono ...
         ^- Bunker ...

Navicella <-- [ DisegnabileI ]
           ^- Entity ...
           ^- Fuel ...
           ^- Pianeta ...

SistemaSolare <-- [ utils ]
               ^- Pianeta ...
               ^- Navicella ...

//ATTENZIONE! cpp inclusi per classi template
#include "./includeTemplate.hpp"

main <-- gioco <-- screens <-- visualePianeta <-------- cScreen
                            |                        ^- SistemaSolare ...
                            ^- visualeSistemaSolare <-- cScreen
                            |                        ^- Navicella ...
                            |                        ^- SistemaSolare ...
                            ^- visualeMenu <----------- [Button, cScreen]
                            |                        ^- SistemaSolare ...
                            ^- visualeOpzioni <-------- [Button, cScreen]
```

## scelte progettuali

abbiamo cercato di tenere la logica di C++ ben distinta dalla logica della libreria grafica
per cui se avevo ad esempio un Angolo questo è salvato come angolo matematico
(sia per geometria, sia per funzioni tipo seno, coseno, tangente ...)
e poi successivamente modificata opportunamente (per lo meno abbiamo visto che funziona...)
per renderlo un angolo adatto alla libreria grafica

sono state usate classi, e membri privati, solo in Entity e in Direzione sono utilizzati protected
lasciando però i set e i get pubblici.

si è fatto uso di variabili extern comuni su più file ad esempio:
la vita della navicella, 
i punti,
il fuel.
e booleani per la gestione dei menù,
alcuni interi per i comandi.

si è fatto ampio uso delle liste, usando un array solo per salvare le direzioni dei bunker e per un vettore di bottoni nella visuale opzioni.

Sono stati aggiunti rispetto alle specifiche la visuale menù e la possibilità di modificare i tasti,
la grandezza dello schermo e altre impostazioni che non volevamo tenere fissate, ma lasciandole di default settate.

Sono stati aggiunti comandi:

move:
4 bottoni per spostarsi (WASD) +
le frecce +
un bottone (Space) per muoversi nella direzione corrente +
il tasto destro del mouse per modificare l'orientamento della navicella
e permettere di muoversi in obliquo.

r.t.:
2 per il raggio traente (entrambi gli shift)

shoot:
il tasto sinistro del mouse per sparare in un qualsiasi punto della finestra di gioco +
il tasto enter per sparare nella direzione corrente.

rendendo di fatto possibile:
muoversi obliquamente oppure muoversi solo nelle 4 direzioni.

abbiamo ordinato la superfice del pianeta in funzione dell'angolo tra un vertice
e il centro della finestra

l'hitbox della navicella e dei bunker e del raggio traente sono tutti circolari.

# difficoltà riscontrate

trovare un algoritmo efficente per scoprire se un punto è interno a un poligono concavo, poichè
dato un algortimo trovavamo sempre il controesempio.

far sparare sempre un solo proiettile senza salvarsi il tempo vecchio.

nel caso si voglia giocare con solo le 4 direzioni è possibile trovare un bunker irraggiungibile in questo modo, inoltre a volte i bunker sono disegnati stranamente.

# bugs notati

la navicella può inseguire il suo proiettile e raggiungerlo.

in alcuni computer non funziona la funzione setFillColor di sf::Text (della libreria sfml)
per cui abbiamo definito una define (riga 16 ./nonGravitar/header/utils.hpp)

//define per il codice, a volte non funziona fillColor di sf::Text
//di default dovrebbe essere non dichiarata, da modificare altrimenti
//#define NON_FUNZIONA_FILL_COLOR

da scommentare in caso di mancato funzionamento di setFillColor
questa invece di usare setFillColor utilizza la deprecata setColor.

aggiungendo la visualeOpzioni non richiesta dalle specifiche
volevamo rendere facile all'utente vedere quali tasti usare
ed eventualmente modificarli ma non si riesce a modificare il comando per il raggio traente.

se viene rimpicciolita o ingrandita la finestra dopo averla generata (impostata da terminale)
non si scalano le figure opportunamente, e non funziona il punto del mouse per l'utilizzo di seno e coseno riferito alla sola circonferenza goniometrica (non dipendenti dall'altezza e larghezza dello schermo)

## principali algoritmi usati

Liste: circolari bidirezionali con sentinella.
complessità O(1) (guardare anche easteregg)
utilizzate altrove con cicli però, con complessità O(n)
libro di algoritmi.

Poligono: algoritmo di conta di quante intersezioni ci sono tra la semiretta che va
dal punto a infinito a destra con i lati del poligono concavo
(dati due punti A, B appartenenti al poligono non è detto che tutti i punti del segmento che li unisce appartengono al poligono.)
https://www.geeksforgeeks.org/how-to-check-if-a-given-point-lies-inside-a-polygon/

Movimento: utilizzo seno e coseno riferito alla circonferenza goniometrica

passaggio per parametro della lista (che si occupa di controllare
se una navicella colpisce un bunker o viceversa)

aggiornamento della posizione della navicella in funzione degli eventi sulla tastiera o mouse

aggiornamento degli proiettili e degli spari in funzione del tempo.

trovato su internet (non ci ricordiamo dove)
la soluzione per gestire visuali multiple
utilizzando un array di sottoclassi di cScreen
frammento di codice trovato:
```
{
  std::vector<cScreen *> Screens;
	int screen = 0;
	...
	visuale1 v1;
	Screens.push_back(&v1);
	visuale2 v2;
	Screens.push_back(&v2);
  ...
  //Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
}
```

## easter egg del codice

il nome del gruppo è "mettete i fiori nei vostri cannoni"
a sottolineare la nostra poca voglia di programmare un gioco violento.

ma i proiettili sono gialli perchè spariamo Flowy
un fiore giallo cattivo di Undertale.

#define LUMUS_MAXIMA 255 (citazione a Harry Potter)

//42, Risposta alla domanda fondamentale sulla vita, l'universo e tutto quanto, (cit. Davoli)
non potuta eseguire per non appesantire il calcolo sul punto interno o esterno al poligono...

//7, numero massimo di ogni cosa XD (cit. Sio, scottecs magazine YT)
numero medio (minimo: 5, massimo 10) di pianeti nel sistema solare.

ah dimenticavo,
"algarazmi" per indicare la traduzione da pseudocodice a codice funzionante
degli algoritmi per gestire le liste (circolari bidirezionali con sentinella).
con complessità O(Bertossi) (cioè O(1), ottima)