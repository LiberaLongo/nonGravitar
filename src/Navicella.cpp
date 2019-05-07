//codice navicella
#include <iostream>
using namespace std;

#include "../header/Navicella.hpp"

//costruttori e distruttore
Navicella::Navicella(void)
{
    this->centro.setCoord(0.f, 0.f);
    this->raggio = 0.f;
}
Navicella::Navicella(Punto centro, float raggio)
{
    this->centro = centro;
    this->raggio = raggio;
}
Navicella::Navicella(float x, float y, float raggio)
{
    this->centro.setCoord(x, y);
    this->raggio = raggio;
}
/*virtual*/ Navicella::~Navicella(void)
{
    //distruttore vuoto
}

//setters
void Navicella::setX(float x)
{
    this->centro.setX(x);
}
void Navicella::setY(float y)
{
    this->centro.setY(y);
}
void Navicella::setCoord(float x, float y)
{
    this->centro.setCoord(x, y);
}
void Navicella::setRaggio(float raggio)
{
    this->raggio = raggio;
}

//getters
float Navicella::getX(void)
{
    return this->centro.getX();
}
float Navicella::getY(void)
{
    return this->centro.getY();
}
float Navicella::getRaggio(void)
{
    return this->raggio;
}

//stampa
void Navicella::print(void)
{
    cout << "Navicella : [ centro = ";
    this->centro.print();
    cout << ", raggio = " << this->raggio << " ]" << endl;
}

//contronto
bool Navicella::confronto(Navicella nav)
{
    //confronto non necessario per ora
    return false;
}

//disegna
sf::CircleShape Navicella::draw(void)
{
    //calcolo x e y in modo che il centro
    //sia effettivamente il centro della circonferenza circoscritta il triangolo
    //anche per la libreria SFML
    float x = this->centro.getX() - this->raggio;
    float y = this->centro.getY() - this->raggio;
    //il triangolo è una circonferenza con solo 3 lati
    sf::CircleShape triangolo(this->raggio, 3);
    //blu
    triangolo.setFillColor(sf::Color::Blue);
    //in posizione effettiva del centro
    triangolo.setPosition(x, y);
    return triangolo;
}
