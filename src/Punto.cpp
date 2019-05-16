//codice punti
#include <iostream>
using namespace std;

#include "../header/Punto.hpp"

//costruttore
Punto::Punto(void)
{
}
Punto::Punto(float x, float y)
{
    this->x = x;
    this->y = y;
}
//distruttore
/*virtual*/ Punto::~Punto(void)
{
    //nothing to to
}

//setters
void Punto::setX(float x)
{
    this->x = x;
}
void Punto::setY(float y)
{
    this->y = y;
}
void Punto::setCoord(float x, float y)
{
    this->x = x;
    this->y = y;
}

//getters
float Punto::getX(void)
{
    return this->x;
}
float Punto::getY(void)
{
    return this->y;
}

//stampa
void Punto::print(void)
{
    cout << "( " << this->x << ", " << this->y << " )";
}

//confronto
bool Punto::confronto(Punto p) {
    return (this->x == p.getX() && this->y == p.getY());
}

//disegna
void Punto::draw(sf::RenderWindow &window) {
    float size = 10.f;
    sf::RectangleShape rectangle(sf::Vector2f(size, size));
    rectangle.setPosition(this->x - size/2, this->y - size/2);
    //il punto è al centro del rettangolo
    window.draw(rectangle);
}