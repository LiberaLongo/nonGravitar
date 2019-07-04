//cScreen rappresenta ogni screen
#ifndef C_SCREEN_H
#define C_SCREEN_H

#include <SFML/Graphics.hpp>

class cScreen
{
public :
    virtual int Run (sf::RenderWindow &App) = 0;
};
#endif //C_SCREEN_H
