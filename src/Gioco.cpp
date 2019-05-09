//codice gioco
#include <iostream>

#include <SFML/Graphics.hpp>
//#include <Keyboard.hpp>

#include "../header/Gioco.hpp"

//#define DEBUG

bool Gioco(void)
{
    //codice della gestione del gioco

    //funzione finestra di SFML
    float width = 400.f, height = 500.f;
    //crea la lobby
    sf::RenderWindow lobby(sf::VideoMode(width, height), "My lobby");

    //mia navicella
    Navicella player = Navicella(width / 2, height / 2);

    //esegui il programma finchè la finestra è aperta
    while (lobby.isOpen())
    {
        //controlla se qualche evento viene scatenato prima del prossimo loop
        sf::Event event;
        while (lobby.pollEvent(event))
        {
            //le cose della Render Window le devo controllare in QUESTA funzione!
            //in particolare se la finestra è stata chiusa
            if (event.type == sf::Event::Closed)
                lobby.close();
            //altrimenti passo il controllo alla mia funzione dei controlli
            //controlli(player, event);
            /*la funzione controlli non va per non si sa quale motivo*/
            switch (event.type)
            {
            //tasti premuti?
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

            //noi non controlliamo gli altri tipi di evento
            default:
                break;
            }
            /*la funzione controlli non va per non si sa quale motivo*/
        }

        //pulisci la finestra colorandola di nero
        lobby.clear(sf::Color::Black);

        //disegna qui...
        lobby.draw(player.draw());

        // lobby.draw(...);

        //fine del frame corrente
        lobby.display();
    }

    return false;
    //ritorno VERO perchè il gioco non è stato ancora implementato
}
