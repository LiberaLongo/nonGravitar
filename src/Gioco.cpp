//codice gioco
#include <SFML/Graphics.hpp>

#include "../header/Navicella.hpp"

bool Gioco(void)
{
    //codice della gestione del gioco

    //funzione finestra di SFML
    float width = 400.0, height = 500.0;
    // create the lobby
    sf::RenderWindow lobby(sf::VideoMode(width, height), "My lobby");

    // run the program as long as the window is open
    while (lobby.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (lobby.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                lobby.close();
        }

        // clear the window with black color
        lobby.clear(sf::Color::Black);

        // draw everything here...
        Navicella me = Navicella(width/2, height/2, 50.f);
        lobby.draw(me.draw());

        // lobby.draw(...);        

        // end the current frame
        lobby.display();
    }

    return false;
    //ritorno VERO perchè il gioco non è stato ancora implementato
}
