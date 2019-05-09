//codice navicella
#include <iostream>
using namespace std;

#include "../header/Navicella.hpp"

//#define DEBUG

//COSTRUTTORI
//costruttore void
Navicella::Navicella(void)
{
    //default tutto
}
//costruttori punto
Navicella::Navicella(Punto centro)
{
    this->centro = centro;
    //default raggio, velocità, angolo
}
Navicella::Navicella(float x, float y)
{
    this->centro.setCoord(x, y);
    //default raggio, velocità, angolo
}
//costruttori completi
Navicella::Navicella(Punto centro, float raggio, float angle, float speed)
{
    this->centro = centro;
    this->raggio = raggio;
    this->angle = angle;
    this->speed = speed;
}
Navicella::Navicella(float x, float y, float raggio, float angle, float speed)
{
    this->centro.setCoord(x, y);
    this->raggio = raggio;
    this->angle = angle;
    this->speed = speed;
}

//distruttore
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
void Navicella::setAngolo(float angle)
{
    this->angle = angle;
}
void Navicella::setSpeed(float speed)
{
    this->speed = speed;
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
float Navicella::getAngolo(void)
{
    return this->angle;
}
float Navicella::getSpeed(void)
{
    return this->speed;
}

//stampa
void Navicella::print(void)
{
    cout << "Navicella : [ centro = ";
    this->centro.print();
    cout << ", raggio = " << this->raggio;
    cout << ", angolo = " << this->angle;
    cout << ", speed = " << this->speed;
    cout << " ]" << endl;
}

//disegna
sf::CircleShape Navicella::draw(void)
{
    //calcolo x e y in modo che il centro
    //sia effettivamente il centro della circonferenza circoscritta il triangolo
    //anche per la libreria SFML
    float x = this->getX() - this->raggio;
    float y = this->getY() - this->raggio;
    //il triangolo è una circonferenza con solo 3 lati
    sf::CircleShape triangolo(this->raggio, 3);
    //blu
    triangolo.setFillColor(sf::Color::Blue);
    //in posizione effettiva del centro
    triangolo.setPosition(x, y);
    //punto di origine per la trasfomazione
    //triangolo.setOrigin(x, y);
    //ruota di angolo
    //triangolo.rotate(this->angle);
    return triangolo;
}

void Navicella::moveUp(void)
{
    //sù
#ifdef DEBUG
    std::cout << "W\t";
#endif
    this->setY(this->getY() - this->speed);
    this->angle = 0.f;
}
void Navicella::moveLeft(void)
{
    //sinistra
#ifdef DEBUG
    std::cout << "A\t";
#endif
    this->setX(this->getX() - this->speed);
    this->angle = 270.f;
}
void Navicella::moveDown(void)
{
    //giù
#ifdef DEBUG
    std::cout << "S\t";
#endif
    this->setY(this->getY() + this->speed);
    this->angle = 180.f;
}
void Navicella::moveRight(void)
{
#ifdef DEBUG
    std::cout << "D\t";
#endif
    //destra
    this->setX(this->getX() + this->speed);
    this->angle = 90.f;
}