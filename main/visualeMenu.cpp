//menù

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
    //prima linea
    Button buttonPlay = Button(x, y, "Play");
    //seconda linea
    Button buttonOptions = Button(x, y + dist, "Options");
    //terza linea
    Button buttonExit = Button(x, y + dist * 2, "Exit");

    //un punto adibito a mouse click
    Punto mouseClick;
#ifdef NOME_PUNTO
    mouseClick.setName("MOUSE");
#endif
    while (Running)
    {
        //Verifying events
        while (App.pollEvent(event))
        {
            // Window closed
            switch (event.type)
            {
            case sf::Event::Closed:
                return EXIT;
                break;
            case sf::Event::MouseButtonPressed:
                mouseClick.setCoord(event.mouseButton.x, event.mouseButton.y);
                if (buttonExit.checkMouse(mouseClick))
                {
                    //fine dei giochi, si torna a lavoro...
                    return EXIT;
                }
                if (buttonOptions.checkMouse(mouseClick))
                {
                    //impostazioni del gioco
                    return VISUALE_OPZIONI;
                }
                //buttonPlay, buttonContinue, buttonNewGame
                //hanno tutti stessa x, y, widht, height
                //e non è necessario controllarne più di uno
                else if (buttonPlay.checkMouse(mouseClick))
                {
                    //giochiamo!
                    startGame();
                    return VISUALE_SISTEMA_SOLARE;
                }
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                //tasto Esc
                case sf::Keyboard::Escape:
                    return EXIT;
                    break;
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

        //Clearing screen
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
        //Drawing
        App.draw(testo);
        buttonPlay.draw(App);
        buttonOptions.draw(App);
        buttonExit.draw(App);
        //Showing
        App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return EXIT;
}
