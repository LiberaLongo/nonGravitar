//codice navicella
#include <iostream>
using namespace std;

#include "../header/Navicella.hpp"

//#define DEBUG

//funzione privata che setta origin
/*void Navicella::setOrigin()
{
    //float x = 900.f/2 , y = 700.f/2 ;
    float x = this->centro.getX() + this->raggio;
    float y = this->centro.getY() + this->raggio;
    this->origine.setCoord(x, y);
}*/

//COSTRUTTORI
//costruttore void
Navicella::Navicella(void)
{
    //default tutto
    //this->setOrigin();
}
//costruttori punto
Navicella::Navicella(Punto centro)
{
    this->centro = centro;
    //default raggio, velocità, angolo
    //this->setOrigin();
}
Navicella::Navicella(float x, float y)
{
    this->centro.setCoord(x, y);
    //default raggio, velocità, angolo
    //this->setOrigin();
}
//costruttori completi
Navicella::Navicella(Punto centro, float raggio, float angle, float speed)
{
    this->centro = centro;
    this->raggio = raggio;
    this->angle = angle;
    this->speed = speed;
    //this->setOrigin();
}
Navicella::Navicella(float x, float y, float raggio, float angle, float speed)
{
    this->centro.setCoord(x, y);
    this->raggio = raggio;
    this->angle = angle;
    this->speed = speed;
    //this->setOrigin();
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
    //this->setOrigin();
}
void Navicella::setY(float y)
{
    this->centro.setY(y);
    //this->setOrigin();
}
void Navicella::setCoord(float x, float y)
{
    this->centro.setCoord(x, y);
    //this->setOrigin();
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
    /*#ifdef DEBUG
    cout << ", origine = ";
    this->origine.print();
#endif*/
    cout << ", raggio = " << this->raggio;
    cout << ", angolo = " << this->angle;
    cout << ", speed = " << this->speed;
    cout << " ]" << endl;
}

//disegna
void Navicella::draw(sf::RenderWindow &window)
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
    //triangolo.setOrigin(this->origine.getX(), this->origine.getY());
    //ruota di angolo
    //triangolo.rotate(this->angle);
    window.draw(triangolo);
}

void Navicella::moveUp(void)
{
    //sù
#ifdef DEBUG
    cout << "W\t";
#endif
    float y = this->getY() - this->speed;
    if ((y - this->raggio) < 0.f) //se non vuole andare troppo in alto
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
    if ((x - this->raggio) < 0.f) //se non vuole andare troppo in alto
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
    if ((y + this->raggio) > height ) //se non vuole andare troppo in alto
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
    if ((x + this->raggio) > width ) //se non vuole andare troppo in alto
    {
        //collisione
        cout << "non uscire dallo schermo" << endl;
    }
    else
        this->setX(x);
    this->angle = 90.f;
}