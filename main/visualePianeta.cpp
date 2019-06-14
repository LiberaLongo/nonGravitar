//visuale pianeta codice

#include "../header/visualePianeta.hpp"

//#define DEBUG

visualePianeta::visualePianeta(void)
{
    //aggiorno coordinate
    this->player = Navicella(WIDTH / 4, HEIGHT / 4);
}

int visualePianeta::Run(sf::RenderWindow &App)
{
    //globale lunghezza della superficie
    int lengthSuperficie = 0;
    //aggiorno coordinate
    this->player.setCoord(WIDTH / 4, HEIGHT / 4);
    //aggiorno il pianeta
    if (pianetaInsideNow != nullptr)
    {
        //stampa
        //pianetaInsideNow è la posizione del pianeta nella lista
        this->pianetaVisualizzato = sistemasolare.toPtrPlanet(pianetaInsideNow);

        //conta i punti della superficie
        lengthSuperficie = this->pianetaVisualizzato.lunghezzaSuperfice();
        if(lengthSuperficie != MAX_SUPERFICE)
        {
            cout << "Errore nella conta o nella generazione della superfice";
            return EXIT;
        }
//voglio sapere come dare nome a un oggetto puntato da un puntatore
#ifdef DEBUG
        this->pianetaVisualizzato.print();
#endif
    }
#ifdef DEBUG
    cout << "sono dentro il pianeta!" << endl;
#endif

    //comincia la trattazione della finestra
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
                    return VISUALE_SISTEMA_SOLARE;
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
            if (NavicellaMoved)
            {
                if (this->player.isOutsideScreen())
                {
#ifdef DEBUG
                    cout << "ritornato a sistema solare" << endl;
#endif
                    return VISUALE_SISTEMA_SOLARE;
                }
            }
        }

        //pulisci la finestra colorandola di nero
        App.clear(this->pianetaVisualizzato.getAtmosferaLib());

        this->pianetaVisualizzato.drawVisuale(App, lengthSuperficie);
        this->player.draw(App);

        if (haCliccato)
            mouseClick.draw(App);
        //fine del frame corrente
        App.display();
    }
}