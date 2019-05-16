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
    //default size, velocità, angolo
    
}
Navicella::Navicella(float x, float y)
{
    this->centro.setCoord(x, y);
    //default size, velocità, angolo
    
}
//costruttori completi
Navicella::Navicella(Punto centro, float size, float angle, float speed)
{
    this->centro = centro;
    this->size = size;
    this->angle = angle;
    this->speed = speed;
    
}
Navicella::Navicella(float x, float y, float size, float angle, float speed)
{
    this->centro.setCoord(x, y);
    this->size = size;
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
void Navicella::setSize(float size)
{
    this->size = size;
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
float Navicella::getSize(void)
{
    return this->size;
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
    cout << ", size = " << this->size;
    cout << ", angolo = " << this->angle;
    cout << ", speed = " << this->speed;
    cout << " ]" << endl;
}

//disegna
void Navicella::draw(sf::RenderWindow &window)
{
    //centro iniziale della figura prima di fare setPosition
    float x = 0.f, y = 0.f; //centro: (0,0)
    Punto a = Punto(x, y);
    //crea una empty shape convex con 3 punti
    sf::ConvexShape triangolo;
    triangolo.setPointCount(3);
    //definisci i punti rispetto a (0,0)
    triangolo.setPoint(0, sf::Vector2f(x, y - this->size*3));
    triangolo.setPoint(1, sf::Vector2f(x - this->size, y + this->size));
    triangolo.setPoint(2, sf::Vector2f(x + this->size, y + this->size));
    //blu
    triangolo.setFillColor(sf::Color::Blue);
    //ruota di angolo, PRIMA! della rotazione
    triangolo.setRotation(this->angle);
    //spostala  posizione effettiva del centro
    triangolo.setPosition(this->getX(), this->getY());
    //disegna sulla window passata per riferimento
    window.draw(triangolo);
}

void Navicella::moveUp(void)
{
    //sù
#ifdef DEBUG
    cout << "W\t";
#endif
    float y = this->getY() - this->speed;
    if ((y - this->size) < 0.f) //se non vuole andare troppo in alto
    {
        //collisione
        cout << "non uscire dallo schermo" << endl;
    }
    else
        this->setY(y);
    this->angle = 0.f;
}
void Navicella::moveLeft(void)
{
    //sinistra
#ifdef DEBUG
    cout << "A\t";
#endif
    float x = this->getX() - this->speed;
    if ((x - this->size) < 0.f) //se non vuole andare troppo in alto
    {
        //collisione
        cout << "non uscire dallo schermo" << endl;
    }
    else           
        this->setX(x);
    this->angle = 270.f;
}
void Navicella::moveDown(float height)
{
    //giù
#ifdef DEBUG
    cout << "S\t";
#endif
    float y = this->getY() + this->speed;
    if ((y + this->size) > height ) //se non vuole andare troppo in alto
    {
        //collisione
        cout << "non uscire dallo schermo" << endl;
    }
    else
        this->setY(y);
    this->angle = 180.f;
}
void Navicella::moveRight(float width)
{
    //destra
#ifdef DEBUG
    cout << "D\t";
#endif
    float x = this->getX() + this->speed;
    if ((x + this->size) > width ) //se non vuole andare troppo in alto
    {
        //collisione
        cout << "non uscire dallo schermo" << endl;
    }
    else
        this->setX(x);
    this->angle = 90.f;
}