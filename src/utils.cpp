//codice cose utili usate in tutto il codice

#include <cmath>
#include "../header/Punto.hpp"

//distanza tra due punti
float distance(Punto a, Punto b) {
    return (float) sqrt( pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2) );
}