# nonGravitar
progetto programmazione

viene utilizzata la libreria SFML per la grafica in C++.

## libreria grafica SFML

da noi su Linux:

apri il terminale
(Ctrl + Alt + T)

scarica la libreria
`sudo apt-get install libsfml-dev`

per maggiori informazioni sulla libreria
<https://www.sfml-dev.org/learn.php>

per maggiori informazioni su come installare sfml su linux
<https://www.sfml-dev.org/tutorials/2.5/start-linux.php>

## clonare il progetto

con il terminale aperto

spostati con il comando `cd` sulla cartella in cui vuoi clonare il progetto
(esempio Desktop: `cd Desktop` oppure Documents: `cd Documents`)

`git clone http://www.github.com/LiberaLongo/nonGravitar.git`

## compilare

con il terminale aperto

spostati sulla cartella del progetto
`cd nonGravitar`

compilare
`make`
(per pulire: `make clean`, ma non è necessario per ricompilare)

eventualmente rilanciare il gioco (rieseguendo il programma)
`./app`

### caso di errore nella compilazione

abbiamo notato che una funzione sfml
(sf::Text::setFillColor(...)) non sempre funziona
l'alternativa (sf::Text::setColor(...)) è deprecata
quindi se non dovesse funzionare è consigliato
scommentare la 
"//#define NON_FUNZIONA_FILL_COLOR"
in utils.hpp (riga 16)
togliendo le //
quindi risulta:
"#define NON_FUNZIONA_FILL_COLOR" 

## relazione e scelte progettuali
vedi RELAZIONE.md
