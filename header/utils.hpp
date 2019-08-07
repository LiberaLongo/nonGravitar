//header cose utili in tutto il codice ausiliarie
#ifndef UTILS_HPP
#define UTILS_HPP

//input e ouput
#include <iostream>
using namespace std;

//definizione per usare M_PI e M_E di cmath
#define _USE_MATH_DEFINES
#include <cmath>
//M_PI pigreco e M_E numero di eulero

//per i colori
#define LUMUS_MAXIMA 255 //LUMUS_MAXIMA, citazione Harry Potter, (luminosità RGB)

//alcune costanti nella costruzione delle varie parti del gioco
//costanti di quantità di fuel
#define CONSUMO 1
#define FUEL_1_QUANTITA 200
#define FUEL_2_QUANTITA 400
#define FUEL_NAVICELLA 500
//costanti
#define DISTANCE 100.f
#define SPEED_PROIETTILI 5.f

//angolo di differenza per la sparatoria del bunker
#define ANGOLO_BUNKER 30.f

//dimensioni non modificabili
#define SIZE_FUEL 10.f
#define SIZE_BUNKER 10.f
//raggio di defalut del pianeta
#define PIANETA_RAGGIO 40.f

//numero di pianeti/punti per sistema solare/pianeta
#define MAX_SUPERFICE 16 //42, Risposta alla domanda fondamentale sulla vita, l'universo e tutto quanto, (cit. Davoli)
#define MAX_BUNKER 5
#define MAX_FUEL 3
#define MAX_PLANET 7 //7, numero massimo di ogni cosa XD (cit. Sio, scottecs magazine YT)

//direzioni canoniche con angoli studiati in matematica
#define RIGHT   0.f
#define UP      90.f
#define LEFT    180.f
#define DOWN    270.f

//vita delle entità
#define VITA_NAVICELLA 5
#define VITA_BUNKER 1

//macro per gestire opportunamente le visuali
#define EXIT -1
enum visuale {VISUALE_MENU, VISUALE_SISTEMA_SOLARE, VISUALE_PIANETA};

//numero di millisecondi dopo i quali aggiornare i proiettil
#define AGGIORNA 100
//numero di millisecondi dopo cui il bunker spara in tutte le sue direzioni
#define SPARA 1000

//define per il codice, a volte non funziona fillColor
//di default dovrebbe essere non dichiarata, da modificare altrimenti
//#define NON_FUNZIONA_FILL_COLOR

//FUNZIONI

//Precondition: prende un angolo in gradi in forma canonica
//Postcondition: lo trasforma opportunamente secondo la libreria grafica
float angoloLibreria(float angolo);

#endif //UTILS_HPP
