#ifndef DISEGNABILE_INTERFACCIA_HPP
#define DISEGNABILE_INTERFACCIA_HPP

#include <SFML/Graphics.hpp>

class DisegnabileI
{
public:
    //disegna
    void draw(sf::RenderWindow &window);
};
#endif //DISEGNABILE_INTERFACCIA_HPP
