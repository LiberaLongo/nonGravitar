//codice cose utili usate in tutto il codice

#include "../header/utils.hpp"
#include "../header/Punto.hpp"

//Precondition: prende un angolo in gradi in forma canonica
//Postcondition: lo trasforma secondo la libreria grafica per ora usata
//NOTA del programmatore: ovviamente va modificata quando si usa una libreria grafica diversa

float angoloLibreria(float angolo) {
    return angolo;
}
//distanza tra due punti
float distance(Punto a, Punto b) {
    return (float) sqrt( pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2) );
}