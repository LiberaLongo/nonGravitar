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

//alcune costanti nella costruzione delle varie parti del gioco
#define CONSUMO 1.f
#define FUEL1 100.f
#define FUEL2 200.f
#define SPEED 5.f

//direzioni con la tastiera WASD o freccette
#define UP 0.f
#define RIGHT 90.f
#define DOWN 180.f
#define LEFT 270.f

#endif //UTILS_H