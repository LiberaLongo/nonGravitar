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

//dimensioni
#define HEIGHT 600.f
#define WIDTH 900.f
//alcune costanti nella costruzione delle varie parti del gioco
#define CONSUMO 1.f
#define FUEL1 100.f
#define FUEL2 200.f
#define SPEED 5.f
#define PIANETA_RAGGIO 50.f
#define MAX_PLANET 7 //numero massimo di ogni cosa XD (cit. Sio, scottecs magazine YT)

//direzioni canoniche con angoli studiati in matematica
#define RIGHT   0.f
#define UP      90.f
#define LEFT    180.f
#define DOWN    270.f

//Precondition: prende un angolo in gradi in forma canonica
//Postcondition: lo trasforma opportunamente secondo la libreria grafica
float angoloLibreria(float angolo);

//restituisce la distanza tra due punti
//float distance(Punto a, Punto b);

#endif //UTILS_H