//codice carburante
#include <iostream>
using namespace std;

#include "../header/Fuel.hpp"

//costruttore vuoto
Fuel::Fuel(void)
{
    //tutto di default
}
//costruttore coordinate
Fuel::Fuel(Punto centro) {
    this->centro = centro;
}
Fuel::Fuel(float x, float y) {
    this->centro.setCoord(x, y);
}
//costruttore completo
Fuel::Fuel(Punto centro, float quantita, float size) {
    this->centro = centro;
    this->quantita = quantita;
    this->size = size;
}
Fuel::Fuel(float x, float y, float quantita, float size) {
    this->centro.setCoord(x, y);
    this->quantita = quantita;
    this->size = size;    
}

//distruttore
/*virtual*/ Fuel::~Fuel(void) {
    //distruttore di default
}

//setters
void Fuel::setX(float x) {
    this->centro.setX(x);
}
void Fuel::setY(float y) {
    this->centro.setY(y);
}
void Fuel::setCoord(float x, float y)
{
    this->centro.setCoord(x, y);
}
void Fuel::setQuantita(float quantita){
    this->quantita = quantita;
}
void Fuel::setSize(float size) {
    this->size = size;
}

//getters
float Fuel::getX(void) {
    return this->centro.getX();
}
float Fuel::getY(void) {
    return this->centro.getY();
}
float Fuel::getQuantita(void) {
    return this->quantita;
}
float Fuel::getSize(void) {
    return this->size;
}

//stampa
void Fuel::print(void) {
    cout << "Fuel : [ centro = ";
    this->centro.print();
    cout << ", size = " << this->size;
    cout << " ]" << endl;
}

//contronto
bool Fuel::confronto(Fuel f) {
    return (this->centro.getX() == f.getX() && this->centro.getY() == f.getY() && this->quantita == f.getQuantita() && this->size == f.getSize());
}

//disegna
void Fuel::draw(sf::RenderWindow &window) {
    //disegna carburante
}

//consumo carburante
float Fuel::consumoFuel(void) {
    //consuma fuel
}