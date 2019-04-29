//codice punti
#include "./Punto.hpp"

//costruttore
Punto::Punto(float x, float y) {
    this.x = x;
    this.y = y;
}
//distruttore
virtual Punto::~Punto() {
   //nothing to to  
}

//setters
void Punto::setX(float x) {
    this.x = x;
}
void Punto::setY(float y) {
    this.y = y;
}
void Punto::setCoord(float x, float y) {
    this.x = x;
    this.y = y;
}

//getters
float Punto::getX(void) {
    return this.x;
}
float Punto::getY(void) {
    return this.y;
}
