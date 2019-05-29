//visuale sistema solare codice
#include "../header/visualeSistemaSolare.hpp"

visualeSistemaSolare::visualeSistemaSolare(void)
{
    //seme per i numeri casuali
    srand(time(NULL));
    this->sistemasolare.genera();
    //this->sistemasolare.print();

    //mia navicella
    this->player = Navicella(WIDTH / 2, HEIGHT / 2);
}

int visualeSistemaSolare::Run(sf::RenderWindow &App)
{
    bool Running = true;
    
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
            switch (event.type)
            {
            //se la finestra è stata chiusa
            case sf::Event::Closed:
                return -1;
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
					return (-1);
					break;
                //WASD
                case sf::Keyboard::W:
#ifdef DEBUG
                    cout << "W\n";
#endif
                    this->player.move(UP);
                    break;
                case sf::Keyboard::A:
#ifdef DEBUG
                    cout << "A\n";
#endif
                    this->player.move(LEFT);
                    break;
                case sf::Keyboard::S:
#ifdef DEBUG
                    cout << "S\n";
#endif
                    this->player.move(DOWN);
                    break;
                case sf::Keyboard::D:
#ifdef DEBUG
                    cout << "D\n";
#endif
                    this->player.move(RIGHT);
                    break;
                //freccie
                case sf::Keyboard::Up:
#ifdef DEBUG
                    cout << "Up\n";
#endif
                    this->player.move(UP);
                    break;
                case sf::Keyboard::Left:
#ifdef DEBUG
                    cout << "Left\n";
#endif
                    this->player.move(LEFT);
                    break;
                case sf::Keyboard::Down:
#ifdef DEBUG
                    cout << "Down\n";
#endif
                    this->player.move(DOWN);
                    break;
                case sf::Keyboard::Right:
#ifdef DEBUG
                    cout << "Right\n";
#endif
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
            /*la funzione controlli non va per non si sa quale motivo*/
        }

        //pulisci la finestra colorandola di nero
        App.clear(sf::Color::Black);

        //disegna qui...
        this->sistemasolare.draw(App);

        this->player.draw(App);

        if(haCliccato)
            mouseClick.draw(App);
        // App.draw(...);

        //fine del frame corrente
        App.display();
    }

    return -1;
}