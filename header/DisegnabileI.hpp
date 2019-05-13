#ifndef DISEGNABILE_INTERFACCIA_H
#define DISEGNABILE_INTERFACCIA_H

#include <SFML/Graphics.hpp>

class DisegnabileI
{
public:
    //disegna
    void draw(sf::RenderWindow &window);
};
#endif //DISEGNABILE_INTERFACCIA_H
