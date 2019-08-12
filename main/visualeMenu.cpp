//menù

#include "../header/visualeMenu.hpp"

extern float WIDTH, HEIGHT;
bool generaSistema = false;
bool haiVinto = false, haiPerso = false;

visualeMenu::visualeMenu(void)
{
    playing = false;
}

int visualeMenu::Run(sf::RenderWindow &App)
{
    float dist = HEIGHT / 6;
    int charSize = HEIGHT / 10;
    float x = WIDTH / 4;
    float y = HEIGHT / 3;
    //colore della vittoria
    ColoreRGB coloreTesto = ColoreRGB(LUMUS_MAXIMA, 0, LUMUS_MAXIMA);

    sf::Event event;
    bool Running = true;
    sf::Font Font;
    sf::Text testoGioco, testoHaiVinto, testoHaiPerso;
    int menu = 0;

    if (!Font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return EXIT;
    }
    testoHaiVinto.setFont(Font);
    testoHaiVinto.setCharacterSize(charSize);
    testoHaiVinto.setString("HAI VINTO!");
    testoHaiVinto.setPosition({x, y - dist});

    testoHaiPerso.setFont(Font);
    testoHaiPerso.setCharacterSize(charSize);
    testoHaiPerso.setString("HAI PERSO!");
    testoHaiPerso.setPosition({x, y - dist});

    testoGioco.setFont(Font);
    testoGioco.setCharacterSize(charSize);
    testoGioco.setString("Non Gravitar");
    testoGioco.setPosition({x, y - dist});
#ifndef NON_FUNZIONA_FILL_COLOR
    testoHaiVinto.setFillColor(coloreTesto.getColorLib());
    testoHaiPerso.setFillColor(coloreTesto.getColorLib());
    testoGioco.setFillColor(coloreTesto.getColorLib());
#endif
#ifdef NON_FUNZIONA_FILL_COLOR
    testoHaiVinto.setColor(coloreTesto.getColorLib());
    testoHaiPerso.setColor(coloreTesto.getColorLib());
    testoGioco.setColor(coloreTesto.getColorLib());
#endif
    //bottoni
    //prima linea
    Button buttonPlay = Button(x, y, "Play");
    Button buttonContinue = Button(x, y, "Continue");
    Button buttonNewGame = Button(x, y, "New Game");
    //seconda linea
    Button buttonExit = Button(x, y + dist, "Exit");

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
                //buttonPlay, buttonContinue, buttonNewGame
                //hanno tutti stessa x, y, widht, height
                //e non è necessario controllarne più di uno
                else if (buttonPlay.checkMouse(mouseClick))
                {
                    //giochiamo!
                    playing = true;
                    haiVinto = false;
                    if (generaSistema)
                    {
                        sistemasolare.genera();
                        generaSistema = false;
                    }
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
                    menu = 0;
                    break;
                case sf::Keyboard::Down:
                    menu = 1;
                    break;
                case sf::Keyboard::Return:
                    if (menu == 0)
                    {
                        //giochiamo!
                        playing = true;
                        haiVinto = false;
                        if (generaSistema)
                        {
                            sistemasolare.genera();
                            generaSistema = false;
                        }
                        return VISUALE_SISTEMA_SOLARE;
                    }
                    else
                    {
                        //fine dei giochi, si torna a lavoro...
                        return EXIT;
                    }
                    break;
                default:
                    break;
                }
            default:
                break;
            }
        }
        if (menu == 0)
        {
            //prima linea focalizzata
            buttonPlay.setChecked(true);
            buttonContinue.setChecked(true);
            buttonNewGame.setChecked(true);
            //le altre no
            buttonExit.setChecked(false);
        }
        else
        {
            //seconda linea focalizzata
            buttonExit.setChecked(true);
            //le altre no
            buttonPlay.setChecked(false);
            buttonContinue.setChecked(false);
            buttonNewGame.setChecked(false);
        }

        //Clearing screen
        App.clear();
        //Drawing
        if (playing)
        {
            if (haiVinto)
            {
                App.draw(testoHaiVinto);
                buttonNewGame.draw(App);
            }
            else if (haiPerso)
            {
                App.draw(testoHaiPerso);
                buttonNewGame.draw(App);
            }
            else
            {
                App.draw(testoGioco);
                buttonContinue.draw(App);
            }
        }
        else
        {
            App.draw(testoGioco);
            buttonPlay.draw(App);
        }
        buttonExit.draw(App);
        App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return EXIT;
}
