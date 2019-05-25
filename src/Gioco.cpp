//codice gioco
#include <SFML/Graphics.hpp>
//#include <Keyboard.hpp>

#include "../header/Gioco.hpp"

//#define DEBUG

bool Gioco(void)
{
    //codice della gestione del gioco

    //funzione finestra di SFML
    float width = 900.f, height = 600.f;
    //crea la lobby
    sf::RenderWindow lobby(sf::VideoMode(width, height), "My lobby");

    //mia navicella
    Navicella player = Navicella(width / 2, height / 2);

    //un punto adibito a mouse click
    Punto mouseClick;
    bool haCliccato = false;

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
            //mouse cliccato
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
#ifdef DEBUG
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
#endif
                    haCliccato = true;
                    mouseClick.setCoord(event.mouseButton.x, event.mouseButton.y);
                    player.shoot(mouseClick);
                }
                break;
            //tasti premuti?
            case sf::Event::KeyPressed:
                //...
                switch (event.key.code)
                {
                //WASD
                case sf::Keyboard::W:
#ifdef DEBUG
                    cout << "W\n";
#endif
                    player.move(UP);
                    break;
                case sf::Keyboard::A:
#ifdef DEBUG
                    cout << "A\n";
#endif
                    player.move(LEFT);
                    break;
                case sf::Keyboard::S:
#ifdef DEBUG
                    cout << "S\n";
#endif
                    player.move(DOWN);
                    break;
                case sf::Keyboard::D:
#ifdef DEBUG
                    cout << "D\n";
#endif
                    player.move(RIGHT);
                    break;
                //freccie
                case sf::Keyboard::Up:
#ifdef DEBUG
                    cout << "Up\n";
#endif
                    player.move(UP);
                    break;
                case sf::Keyboard::Left:
#ifdef DEBUG
                    cout << "Left\n";
#endif
                    player.move(LEFT);
                    break;
                case sf::Keyboard::Down:
#ifdef DEBUG
                    cout << "Down\n";
#endif
                    player.move(DOWN);
                    break;
                case sf::Keyboard::Right:
#ifdef DEBUG
                    cout << "Right\n";
#endif
                    player.move(RIGHT);
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

        Pianeta earth = Pianeta(width/3, height/4);
        //disegna qui...
        earth.draw(lobby);
        player.draw(lobby);
        if(haCliccato)
            mouseClick.draw(lobby);
        // lobby.draw(...);

        //fine del frame corrente
        lobby.display();
    }

    return false;
    //ritorno VERO perchè il gioco non è stato ancora implementato
}
