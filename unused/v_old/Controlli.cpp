//codice controlli
#include <SFML/Graphics.hpp>

#include "../header/Controlli.hpp"

void controlli(Navicella player, sf::Event event)
{
    switch (event.type)
    {
    // key pressed
    case sf::Event::KeyPressed:
        //...
        switch (event.key.code)
        {
        //WASD
        case sf::Keyboard::W:
            player.moveUp();
            break;
        case sf::Keyboard::A:
            player.moveLeft();
            break;
        case sf::Keyboard::S:
            player.moveDown();
            break;
        case sf::Keyboard::D:
            player.moveRight();
            break;
        //freccie
        case sf::Keyboard::Up:
            player.moveUp();
            break;
        case sf::Keyboard::Left:
            player.moveLeft();
            break;
        case sf::Keyboard::Down:
            player.moveDown();
            break;
        case sf::Keyboard::Right:
            player.moveRight();
            break;
        default:
            break;
        }
        break;

    // we don't process other types of events
    default:
        break;
    }
}