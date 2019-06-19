//header cose utili in tutto il codice ausiliarie
#ifndef UTILS_H
#define UTILS_H

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
#define CONSUMO 1.f
#define FUEL1 100.f
#define FUEL2 200.f
//raggio di defalut del pianeta
#define PIANETA_RAGGIO 40.f
//numero di pianeti/punti per sistema solare/pianeta
#define MAX_SUPERFICE 8 //42, Risposta alla domanda fondamentale sulla vita, l'universo e tutto quanto, (cit. Davoli)
#define MAX_BUNKER 5
#define MAX_FUEL 3
#define MAX_PLANET 7 //7, numero massimo di ogni cosa XD (cit. Sio, scottecs magazine YT)

//direzioni canoniche con angoli studiati in matematica
#define RIGHT   0.f
#define UP      90.f
#define LEFT    180.f
#define DOWN    270.f

//macro per gestire opportunamente le visuali
#define EXIT -1
#define VISUALE_SISTEMA_SOLARE 0
#define VISUALE_PIANETA 1

//FUNZIONI

//Precondition: prende un angolo in gradi in forma canonica
//Postcondition: lo trasforma opportunamente secondo la libreria grafica
float angoloLibreria(float angolo);

//restituisce la distanza tra due punti
//float distance(Punto a, Punto b);
//float distance(Punto a, Punto b);

#endif //UTILS_H