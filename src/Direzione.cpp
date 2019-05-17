//codice punti
#include <iostream>
using namespace std;

#include "../header/Direzione.hpp"

//costruttore vuoto
Direzione::Direzione(void) {
    //cose di default
}
//costruttore minimale
Direzione::Direzione(Punto origine) {
    this->origine = origine;
    //default angolo e speed
}
Direzione::Direzione(float x, float y) {
    this->origine.setCoord(x, y);
    //default angolo e speed
}
//costruttore completo
Direzione::Direzione(Punto origine, float angolo, float speed) {
    this->origine = origine;
    this->angolo = angolo;
    this->speed = speed;
}
Direzione::Direzione(float x, float y, float angolo, float speed) {
    this->origine.setCoord(x, y);
    this->angolo = angolo;
    this->speed = speed;
}

//distruttore
/*virtual*/ Direzione::~Direzione(void) {
    //distruttore di default
}

//setters
void Direzione::setXOrigine(float x){
    this->origine.setX(x);
}
void Direzione::setYOrigine(float y) {
    this->origine.setY(y);
}
void Direzione::setOrigine(Punto origine) {
    this->origine = origine;
}
void Direzione::setOrigine(float x, float y) {
    this->origine.setCoord(x, y);
}
void Direzione::setAngolo(float angolo) {
    this->angolo = angolo;
}
void Direzione::setSpeed(float speed) {
    this->speed = speed;
}

//getters
float Direzione::getXOrigine(void) {
    return this->origine.getX();
}
float Direzione::getYOrigine(void) {
    return this->origine.getY();
}
float Direzione::getAngolo(void) {
    return this->angolo;
}
float Direzione::getSpeed(void) {
    return this->speed;
}

//stampa
void Direzione::print(void) {
    cout << "Direzione : [ origine = ";
    this->origine.print();
    cout << ", angolo = " << this->angolo;
    cout << ", speed = " << this->speed;
    cout << " ]" << endl;
}

//contronto
bool Direzione::confronto(Direzione dir) {
    return (this->getXOrigine() == dir.getXOrigine() && this->origine.getY() == dir.getYOrigine() && this->speed == dir.getSpeed() && this->angolo == dir.getAngolo());    
}

//disegna
void Direzione::draw(sf::RenderWindow &window) {
    //per ora vuota
}
//move
void Direzione::move(void) {
    //dato l'angolo e l'origine
    //deve muoversi di speed pixel in quella direzione
    //e aggiornare le sue coordinate del origine
}