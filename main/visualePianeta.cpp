//visuale pianeta codice

#include "../header/visualePianeta.hpp"

//#define DEBUG

extern float WIDTH, HEIGHT;

//variabili condivise tra le visuali
extern bool haiPerso;
extern int vita, fuel, punteggio;

//tastiera
extern int MOVE_UP_1, MOVE_UP_2;
extern int MOVE_LEFT_1, MOVE_LEFT_2;
extern int MOVE_DOWN_1, MOVE_DOWN_2;
extern int MOVE_RIGHT_1, MOVE_RIGHT_2;
extern int RAGGIO_TRAENTE_1, RAGGIO_TRAENTE_2;
extern int KEY_MOVE, KEY_SHOOT;
//mouse
extern int MOUSE_SHOOT, MOUSE_MOVE;

visualePianeta::visualePianeta(void)
{
    //aggiorno coordinate
    this->player = Navicella(SIZE_NAVICELLA * 4, SIZE_NAVICELLA * 4);
    this->orologio.restart();
}

int visualePianeta::Run(sf::RenderWindow &App)
{
    //aggiorno il fuel e la vita
    this->player.setFuel(fuel);
    this->player.setVita(vita);
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
        if (lengthSuperficie > MAX_SUPERFICE || lengthSuperficie < MIN_SUPERFICE)
        {
            cout << "Errore nella conta o nella generazione della superfice";
            return EXIT;
        }
        //Poligono pol = this->pianetaVisualizzato.getPoligono();
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
    float x_testo = 10.f, y_testo = 0.f, dist_testo = WIDTH / 4;
    sf::Font Font;
    sf::Text testoVite;
    sf::Text testoFuel;
    sf::Text testoPunti;
    ColoreRGB coloreTesto = ColoreRGB(255, 255, 255);

    //inizializzo il testo
    if (!Font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return EXIT;
    }
    testoVite.setFont(Font);
    testoVite.setCharacterSize(charSize);
    testoVite.setString("vite: " + to_string(vita) +
                        "  (new live: " + to_string(NEW_LIVE) +
                        "k, bonus: " + to_string(BONUS) + "k)");
    testoVite.setPosition({x_testo, y_testo});

    testoFuel.setFont(Font);
    testoFuel.setCharacterSize(charSize);
    testoFuel.setString("fuel: " + to_string(fuel));
    testoFuel.setPosition({x_testo + dist_testo*2, y_testo});

    testoPunti.setFont(Font);
    testoPunti.setCharacterSize(charSize);
    testoPunti.setString("punteggio: " + to_string(punteggio) + "k");
    testoPunti.setPosition({x_testo + dist_testo*3, y_testo});

#ifndef NON_FUNZIONA_FILL_COLOR
    testoVite.setFillColor(coloreTesto.getColorLib());
    testoFuel.setFillColor(coloreTesto.getColorLib());
    testoPunti.setFillColor(coloreTesto.getColorLib());
#endif
#ifdef NON_FUNZIONA_FILL_COLOR
    testoVite.setColor(coloreTesto.getColorLib());
    testoFuel.setColor(coloreTesto.getColorLib());
    testoPunti.setColor(coloreTesto.getColorLib());
#endif

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
                haCliccato = true;
                mouseClick.setCoord(event.mouseButton.x, event.mouseButton.y);
                if (event.mouseButton.button == MOUSE_SHOOT)
                    carburanteFinito = this->player.shoot(mouseClick);
                else if (event.mouseButton.button == MOUSE_MOVE)
                    this->player.setAngolo(mouseClick);
                else
                    cout << "error\n";
                break;
            //tasti premuti?
            case sf::Event::KeyPressed:
                //Esc per uscire
                if (event.key.code == sf::Keyboard::Escape)
                    return VISUALE_SISTEMA_SOLARE;
                //Space per muoversi nella direzione precedente
                else if (event.key.code == KEY_MOVE)
                {
                    NavicellaMoved = true;
                    carburanteFinito = this->player.move();
                }
                //Enter per sparare
                else if (event.key.code == KEY_SHOOT)
                    carburanteFinito = this->player.shoot();
                //shift sinistro (o destro) per raggio traente
                else if (event.key.code == RAGGIO_TRAENTE_1 || event.key.code == RAGGIO_TRAENTE_2)
                {
                    raggio = true;
                    this->player.raggioTraente(this->pianetaVisualizzato.getHeadFuel());
                }
                //WASD o freccie per muoversi
                else if (event.key.code == MOVE_UP_1 || event.key.code == MOVE_UP_2)
                {
                    NavicellaMoved = true;
                    carburanteFinito = this->player.move(UP);
                }
                else if (event.key.code == MOVE_LEFT_1 || event.key.code == MOVE_LEFT_2)
                {
                    NavicellaMoved = true;
                    carburanteFinito = this->player.move(LEFT);
                }
                else if (event.key.code == MOVE_DOWN_1 || event.key.code == MOVE_DOWN_2)
                {
                    NavicellaMoved = true;
                    carburanteFinito = this->player.move(DOWN);
                }
                else if (event.key.code == MOVE_RIGHT_1 || event.key.code == MOVE_RIGHT_2)
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
                if (this->player.isInsidePoligon(this->pianetaVisualizzato.getPoligono(), lengthSuperficie))
                {
                    //perdo una vita
                    vita--;
                    this->player.setVita(vita);
                    //if (vita <= 0)

#ifdef DEBUG
                    cout << "entrato nel pianeta" << endl;
#endif

                    return VISUALE_SISTEMA_SOLARE;
                }
            }
            //aggiorno la variabile globale
            fuel = this->player.getFuel();
            testoFuel.setString("fuel: " + to_string(fuel));
            //if (carburanteFinito)
        }

        //pulisci la finestra colorandola di nero
        App.clear(this->pianetaVisualizzato.getAtmosferaLib());

        this->pianetaVisualizzato.drawVisuale(App, lengthSuperficie);

        this->player.draw(App, raggio);
        this->player.aggiornaCoordinateProiettili(this->orologio.getElapsedTime(), this->pianetaVisualizzato.getHeadBunker(), this->pianetaVisualizzato.getPoligono(), lengthSuperficie);
        if (this->pianetaVisualizzato.emptyBunker())
        {
            //distruggi il pianeta
            sistemasolare.eliminaPianeta(pianetaInsideNow);
            //incrementa il punteggio di BONUS, ed eventualmente incrementa la vita
            punteggio += BONUS;
            if (punteggio >= NEW_LIVE)
            {
                punteggio -= NEW_LIVE;
                vita++;
            }
            //ritorna alla visuale sistema solare
            return VISUALE_SISTEMA_SOLARE;
        }

        //faccio sparare i bunker del pianeta
        this->pianetaVisualizzato.shoot(this->orologio.getElapsedTime());
        vita = this->pianetaVisualizzato.aggiornaCoordinateProiettili(this->orologio.getElapsedTime(), this->player.getX(), this->player.getY(), this->player.getVita());
        if (vita <= 0 || carburanteFinito)
        {
            haiPerso = true;
            reset();
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
        App.draw(testoPunti);

        App.display();
    }
}
