//visuale sistema solare codice
#include "../header/visualeSistemaSolare.hpp"

visualeSistemaSolare::visualeSistemaSolare(void)
{
    //mia navicella
    this->player = Navicella(WIDTH / 2, HEIGHT / 2);
}

int visualeSistemaSolare::Run(sf::RenderWindow &App)
{
    bool Running = true;
    bool NavicellaMoved = false;
    
    sf::Event event;

    //un punto adibito a mouse click
    Punto mouseClick;
    bool haCliccato = false;

    //esegui il programma finchè la finestra è aperta
    while (Running)
    {
        //controlla se qualche evento viene scatenato prima del prossimo loop
        while (App.pollEvent(event))
        {
            NavicellaMoved = false;
            switch (event.type)
            {
            //se la finestra è stata chiusa
            case sf::Event::Closed:
                return EXIT;
                break;
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
                    this->player.shoot(mouseClick);
                }
                break;
            //tasti premuti?
            case sf::Event::KeyPressed:
                //...
                switch (event.key.code)
                {
                //tasto Esc
				case sf::Keyboard::Escape:
					return EXIT;
					break;
                //WASD
                case sf::Keyboard::W:
                    NavicellaMoved = true;
                    this->player.move(UP);
                    break;
                case sf::Keyboard::A:
                    NavicellaMoved = true;
                    this->player.move(LEFT);
                    break;
                case sf::Keyboard::S:
                    NavicellaMoved = true;
                    this->player.move(DOWN);
                    break;
                case sf::Keyboard::D:
                    NavicellaMoved = true;
                    this->player.move(RIGHT);
                    break;
                //freccie
                case sf::Keyboard::Up:
                    NavicellaMoved = true;
                    this->player.move(UP);
                    break;
                case sf::Keyboard::Left:
                    NavicellaMoved = true;
                    this->player.move(LEFT);
                    break;
                case sf::Keyboard::Down:
                    NavicellaMoved = true;
                    this->player.move(DOWN);
                    break;
                case sf::Keyboard::Right:
                    NavicellaMoved = true;
                    this->player.move(RIGHT);
                    break;
                default:
                    break;
                }
                break;

            //noi non controlliamo gli altri tipi di evento
            default:
                break;
            }
            if (NavicellaMoved == true)
            {
                cout << "mi sono mossa" << endl;
            }
        }

        //pulisci la finestra colorandola di nero
        App.clear(sf::Color::Black);

        //disegna qui...
        sistemasolare.draw(App);

        this->player.draw(App);

        if(haCliccato)
            mouseClick.draw(App);
        // App.draw(...);

        //fine del frame corrente
        App.display();
    }

    return EXIT;
}