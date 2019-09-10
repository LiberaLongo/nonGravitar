#include "../header/visualeMenu.hpp"

extern float WIDTH, HEIGHT;

//variabili condivise tra le visuali
bool generaSistema = false;
bool haiVinto = false;
bool haiPerso = false;
int vita = VITA_NAVICELLA;
int fuel = FUEL_NAVICELLA;
int punteggio = 0;

visualeMenu::visualeMenu(void)
{
    playing = false;
}

void visualeMenu::startGame()
{
    this->playing = true;
    haiVinto = false;
    if (generaSistema)
    {
        sistemasolare.genera();
        generaSistema = false;
    }
}

int visualeMenu::Run(sf::RenderWindow &App)
{
    float dist = HEIGHT / 6;
    int charSize = HEIGHT / 10;
    float x = WIDTH / 4;
    float y = HEIGHT / 3;
    //colore del testo
    ColoreRGB coloreTesto = ColoreRGB(LUMUS_MAXIMA, 0, LUMUS_MAXIMA);

    sf::Event event;
    bool Running = true;
    sf::Font Font;
    sf::Text testo;
    int menu = 0;

    if (!Font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return EXIT;
    }

    testo.setFont(Font);
    testo.setCharacterSize(charSize);
    testo.setString("Non Gravitar");
    testo.setPosition({x, y - dist});
#ifndef NON_FUNZIONA_FILL_COLOR
    testo.setFillColor(coloreTesto.getColorLib());
#endif
#ifdef NON_FUNZIONA_FILL_COLOR
    testo.setColor(coloreTesto.getColorLib());
#endif
    //bottoni
    Button buttonPlay = Button(x, y, "Play");
    Button buttonOptions = Button(x, y + dist, "Options");
    Button buttonExit = Button(x, y + dist * 2, "Exit");

    //un punto adibito a mouse click
    Punto mouseClick;
    while (Running)
    {
        //verifica gli eventi
        while (App.pollEvent(event))
        {
            switch (event.type)
            {
            //finestra chiusa
            case sf::Event::Closed:
                return EXIT;
                break;
            //mouse
            case sf::Event::MouseButtonPressed:
                mouseClick.setCoord(event.mouseButton.x, event.mouseButton.y);
                //verifico se è stato premuto un bottone
                if (buttonExit.checkMouse(mouseClick))
                {
                    //fine dei giochi, si torna a lavoro...
                    return EXIT;
                }
                else if (buttonOptions.checkMouse(mouseClick))
                {
                    //impostazioni del gioco
                    return VISUALE_OPZIONI;
                }
                else if (buttonPlay.checkMouse(mouseClick))
                {
                    //giochiamo!
                    startGame();
                    return VISUALE_SISTEMA_SOLARE;
                }
                break;
            //tastiera
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                //tasto Esc
                case sf::Keyboard::Escape:
                    return EXIT;
                    break;
                //freccie su giù
                case sf::Keyboard::Up:
                    if(menu > 0)
                        menu--;
                    else
                        menu = 2;
                    break;
                case sf::Keyboard::Down:
                    if(menu < 2)
                        menu++;
                    else
                        menu = 0;
                    break;
                //tasto enter
                case sf::Keyboard::Return:
                    switch(menu)
                    {
                    case 0:
                        startGame();
                        return VISUALE_SISTEMA_SOLARE; 
                        break;
                    case 1:
                        return VISUALE_OPZIONI;
                        break;
                    case 2:
                        return EXIT;
                        break;
                    default:
                        cout << "menuError" << endl;
                        break;
                    }
                default:
                    break;
                }
            default:
                break;
            }
        }
        switch (menu)
        {
        case 0:
            //prima linea focalizzata
            buttonPlay.setChecked(true);
            //seconda
            buttonOptions.setChecked(false);
            //terza
            buttonExit.setChecked(false);
            break;
        case 1:
            //prima
            buttonPlay.setChecked(false);
            //seconda linea focalizzata
            buttonOptions.setChecked(true);
            //terza
            buttonExit.setChecked(false);
            break;
        case 2:
            //prima
            buttonPlay.setChecked(false);
            //seconda
            buttonOptions.setChecked(false);
            //terza linea focalizzata
            buttonExit.setChecked(true);
            break;
        default:
            cout << "menuError" << endl;
            break;
        }

        //pulisco lo schermo
        App.clear();
        //setto la stringa giusta a testo e buttonPlay
        if (playing)
        {
            if (haiVinto)
            {
                testo.setString("HAI VINTO!");
                buttonPlay.setString("New Game");
            }
            else if (haiPerso)
            {
                testo.setString("HAI PERSO!");
                buttonPlay.setString("New Game");
            }
            else
            {
                testo.setString("Non Gravitar");
                buttonPlay.setString("Continue");
            }
        }
        else
        {
            testo.setString("Non Gravitar");
            buttonPlay.setString("Play");
        }
        //disegno
        App.draw(testo);
        buttonPlay.draw(App);
        buttonOptions.draw(App);
        buttonExit.draw(App);
        //mostro
        App.display();
    }

    //non dovrebbe mai raggiungere questo
    return EXIT;
}
