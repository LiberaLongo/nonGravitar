//visuale pianeta codice

#include "../header/visualePianeta.hpp"

//#define DEBUG

extern float WIDTH, HEIGHT;
extern bool generaSistema, haiPerso;
extern int vita, fuel;

visualePianeta::visualePianeta(void)
{
    //aggiorno coordinate
    this->player = Navicella(SIZE_NAVICELLA * 4, SIZE_NAVICELLA * 4);
    this->orologio.restart();
}

int visualePianeta::Run(sf::RenderWindow &App)
{
    //aggiorno il fuel
    this->player.setFuel(fuel);
    //globale lunghezza della superficie
    int lengthSuperficie = 0;
    //aggiorno coordinate
    this->player.setCoord(SIZE_NAVICELLA * 4, SIZE_NAVICELLA * 4);
    this->orologio.restart();
    //aggiorno il pianeta
    if (pianetaInsideNow != nullptr)
    {
        //stampa
        //pianetaInsideNow è la posizione del pianeta nella lista
        this->pianetaVisualizzato = sistemasolare.toPtrPlanet(pianetaInsideNow);

        //conta i punti della superficie
        lengthSuperficie = this->pianetaVisualizzato.lunghezzaSuperfice();
        if (lengthSuperficie != MAX_SUPERFICE)
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
    bool carburanteFinito = false;
    bool raggio = false;

    sf::Event event;

    //testo
    float dist = HEIGHT / 8;
    int charSize = HEIGHT / 20;
    float x_testo = 0.f, y_testo = 0.f, dist_testo = WIDTH - charSize * 7;
    sf::Font Font;
    sf::Text testoVite;
    sf::Text testoFuel;
    ColoreRGB coloreTesto = ColoreRGB(255, 255, 255);

    //inizializzo il testo
    if (!Font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return EXIT;
    }
    testoVite.setFont(Font);
    testoVite.setCharacterSize(charSize);
    testoVite.setString("vite: " + to_string(vita));
    testoVite.setPosition({x_testo, y_testo});
    testoVite.setFillColor(coloreTesto.getColorLib());

    testoFuel.setFont(Font);
    testoFuel.setCharacterSize(charSize);
    testoFuel.setString("fuel: " + to_string(fuel));
    testoFuel.setPosition({x_testo + dist_testo, y_testo});
    testoFuel.setFillColor(coloreTesto.getColorLib());

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
            //aggiorno i booleani
            NavicellaMoved = false;
            haCliccato = false;
            raggio = false;

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
                    carburanteFinito = this->player.shoot(mouseClick);
                }
                else if (event.mouseButton.button == sf::Mouse::Right)
                {
                    haCliccato = true;
                    mouseClick.setCoord(event.mouseButton.x, event.mouseButton.y);
                    this->player.setAngolo(mouseClick);
                }
                break;
            //tasti premuti?
            case sf::Event::KeyPressed:
                //Esc per uscire
                if (event.key.code == sf::Keyboard::Escape)
                    return VISUALE_SISTEMA_SOLARE;
                //Space per muoversi nella direzione precedente
                else if (event.key.code == sf::Keyboard::Space)
                {
                    NavicellaMoved = true;
                    carburanteFinito = this->player.move();
                }
                //shift sinistro (o destro) per raggio traente
                else if (event.key.code == sf::Keyboard::LShift || event.key.code == sf::Keyboard::RShift)
                {
                    raggio = true;
                    this->player.raggioTraente(this->pianetaVisualizzato.getHeadFuel());
                }
                //Enter per sparare
                else if (event.key.code == sf::Keyboard::Return)
                    carburanteFinito = this->player.shoot();
                //WASD o freccie per muoversi
                else if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
                {
                    NavicellaMoved = true;
                    carburanteFinito = this->player.move(UP);
                }
                else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
                {
                    NavicellaMoved = true;
                    carburanteFinito = this->player.move(LEFT);
                }
                else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
                {
                    NavicellaMoved = true;
                    carburanteFinito = this->player.move(DOWN);
                }
                else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
                {
                    NavicellaMoved = true;
                    carburanteFinito = this->player.move(RIGHT);
                }
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
            //aggiorno la variabile globale
            fuel = this->player.getFuel();
            testoFuel.setString("fuel: " + to_string(fuel));
            if (carburanteFinito)
            {
                //resetto la vita e il fuel per la prossima partita
                vita = VITA_NAVICELLA;
                fuel = FUEL_NAVICELLA;
                //this->setVita(vita);
                //this->setFuel(fuel);
                //aggiorno i booleani
                haiPerso = true;
                generaSistema = true;
                //torno al menù
                return VISUALE_MENU;
            }
        }

        //pulisci la finestra colorandola di nero
        App.clear(this->pianetaVisualizzato.getAtmosferaLib());

        this->pianetaVisualizzato.drawVisuale(App, lengthSuperficie);

        this->player.draw(App, raggio);
        this->player.aggiornaCoordinateProiettili(this->orologio.getElapsedTime(), this->pianetaVisualizzato.getHeadBunker());
        if (this->pianetaVisualizzato.emptyBunker())
        {
            //distruggi il pianeta
            sistemasolare.eliminaPianeta(pianetaInsideNow);
            //ritorna alla visuale sistema solare
            return VISUALE_SISTEMA_SOLARE;
        }

        //faccio sparare i bunker del pianeta
        this->pianetaVisualizzato.shoot(this->orologio.getElapsedTime());
        vita = this->pianetaVisualizzato.aggiornaCoordinateProiettili(this->orologio.getElapsedTime(), this->player.getX(), this->player.getY(), this->player.getVita());
        if (vita <= 0)
        {
            //resetto la vita per la prossima partita
            vita = VITA_NAVICELLA;
            fuel = FUEL_NAVICELLA;
            //aggiorno i booleani
            haiPerso = true;
            generaSistema = true;
            //torno al menù
            return VISUALE_MENU;
        }
        else if (vita < this->player.getVita())
        {
            //aggiorno la vita
            this->player.setVita(vita);
            //ritorno al sistema solare
            return VISUALE_SISTEMA_SOLARE;
        }
        if (haCliccato)
            mouseClick.draw(App);
        //fine del frame corrente

        //testo
        App.draw(testoVite);
        App.draw(testoFuel);

        App.display();
    }
}
