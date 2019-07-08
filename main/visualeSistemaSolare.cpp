//visuale sistema solare codice
#include "../header/visualeSistemaSolare.hpp"

//#define DEBUG //se è definita stampo per debugghing

extern float WIDTH, HEIGHT;
extern bool generaSistema, haiVinto, haiPerso;
int vita = VITA_NAVICELLA, fuel;

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
    //inizializzo fuel
    fuel = this->player.getFuel();
}

int visualeSistemaSolare::Run(sf::RenderWindow &App)
{
    //aggiorno la vita e il fuel
    this->player.setVita(vita);
    this->player.setFuel(fuel);
    //aggiorno coordinate
    this->player.setCoord(WIDTH / 2, HEIGHT / 2);
    this->orologio.restart();

    //comincia la trattazione della finestra
    bool Running = true;
    bool NavicellaMoved = false;
    bool carburanteFinito = false;

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
            NavicellaMoved = false;
            haCliccato = false;
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
                    this->player.setAngolo(mouseClick);
                }
                break;
            //tasti premuti?
            case sf::Event::KeyPressed:
                //Esc per uscire
                if (event.key.code == sf::Keyboard::Escape)
                    return VISUALE_MENU;
                //Space per sparare
                else if (event.key.code == sf::Keyboard::Space)
                    this->player.shoot();
                //Enter per muoversi nella direzione precedente
                else if (event.key.code == sf::Keyboard::Return)
                {
                    NavicellaMoved = true;
                    carburanteFinito = this->player.move();
                }
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
        App.clear(sf::Color::Black);

        //disegna qui...
        if (!sistemasolare.emptyPianeti())
        {
            sistemasolare.draw(App);
        }
        else
        {
            vita = VITA_NAVICELLA;
            fuel = FUEL_NAVICELLA;
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

        //testo
        App.draw(testoVite);
        App.draw(testoFuel);

        //fine del frame corrente
        App.display();
    }

    return EXIT;
}
