//visuale sistema solare codice
#include "../header/visualeSistemaSolare.hpp"

//#define DEBUG //se è definita stampo per debugghing

extern float WIDTH, HEIGHT;
extern bool generaSistema, haiVinto;

//privata
bool visualeSistemaSolare::check(void)
{
    bool ritorno = false;
    pianetaInsideNow = sistemasolare.isNavicellaNearAPlanet(this->player);
    //controlla se la navicella è vicina a un pianeta nella lista
    //e setto pianetaInsideNow con il pianeta in cui si trova la navicella
    if (pianetaInsideNow != nullptr)
    {
        ritorno = true;
#ifdef DEBUG
        //stampa
        //pianetaInsideNow è la posizione del pianeta nella lista
        Pianeta pianeta = sistemasolare.toPtrPlanet(pianetaInsideNow);
        //voglio sapere come dare nome a un oggetto puntato da un puntatore
        pianeta.print();
#endif
    }
    this->orologio.restart();
    return ritorno;
}

//pubbliche
visualeSistemaSolare::visualeSistemaSolare(void)
{
    //mia navicella
    this->player = Navicella(WIDTH / 2, HEIGHT / 2);
    this->orologio.restart();
    generaSistema = false;
    haiVinto = false;
}

int visualeSistemaSolare::Run(sf::RenderWindow &App)
{
    //aggiorno coordinate
    this->player.setCoord(WIDTH / 2, HEIGHT / 2);
    this->orologio.restart();

    //comincia la trattazione della finestra
    bool Running = true;
    bool NavicellaMoved = false;

    sf::Event event;

    //un punto adibito a mouse click
    Punto mouseClick;
#ifdef NOME_PUNTO
    mouseClick.setName("MOUSE");
#endif
    bool haCliccato = false;

    //esegui il programma finchè la finestra è aperta
    while (Running)
    {
        //controlla se qualche evento viene scatenato prima del prossimo loop
        while (App.pollEvent(event))
        {
            NavicellaMoved = false;
            haCliccato = false;
            switch (event.type)
            {
            //se la finestra è stata chiusa
            case sf::Event::Closed:
                return EXIT;
                break;
            /*
            //mouse cliccato
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    haCliccato = true;
                    mouseClick.setCoord(event.mouseButton.x, event.mouseButton.y);
                    this->player.shoot(mouseClick);
#ifdef DEBUG
                    mouseClick.print();
#endif
                }
                break;
            */
            //tasti premuti?
            case sf::Event::KeyPressed:
                //...
                switch (event.key.code)
                {
                //tasto Esc
                case sf::Keyboard::Escape:
                    haiVinto = false;
                    return VISUALE_MENU;
                    break;
                /*
                //tasto Spazio
                case sf::Keyboard::Space:
                    this->player.shoot();                    
                    break;
                */
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
                    //cout << "NON USCIRE DALLO SCHERMO, TI HO VISTO!" << endl;
                    haiVinto = false;
                    return VISUALE_MENU;
                }
                if (this->check())
                {
#ifdef DEBUG
                    cout << "uscita di emergenza" << endl;
#endif
                    return VISUALE_PIANETA;
                }
            }
        }

        //pulisci la finestra colorandola di nero
        App.clear(sf::Color::Black);

        //disegna qui...
        if(!sistemasolare.emptyPianeti()) {
            sistemasolare.draw(App);
        }
        else {
            generaSistema = true;
            haiVinto = true;
            return VISUALE_MENU;
        }

        this->player.draw(App);
        /*
        this->player.aggiornaCoordinateProiettili(this->orologio.getElapsedTime());
        */
        if (haCliccato)
            mouseClick.draw(App);

        // App.draw(...);

        //fine del frame corrente
        App.display();
    }

    return EXIT;
}
