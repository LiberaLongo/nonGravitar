//codice cose utili usate in tutto il codice

#include <cmath>
#include "../utils/Punto.hpp"

//distanza tra due punti
float distance(const Punto a, const Punto b) {
    return (float) sqrt( pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2) );
}