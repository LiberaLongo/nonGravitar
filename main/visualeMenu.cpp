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
    float dist = HEIGHT / 8;
    int charSize = HEIGHT / 10;
    float x = WIDTH / 2 - charSize;
    float y = HEIGHT / 2 - charSize / 2;
    //focalizzato
    ColoreRGB rosso = ColoreRGB(LUMUS_MAXIMA, 0, 0);
    //non focalizzato
    ColoreRGB bianco = ColoreRGB(LUMUS_MAXIMA, LUMUS_MAXIMA, LUMUS_MAXIMA);
    //colore della vittoria
    ColoreRGB coloreTesto = ColoreRGB(LUMUS_MAXIMA, 0, LUMUS_MAXIMA);

    sf::Event Event;
    bool Running = true;
    sf::Font Font;
    sf::Text testoGioco, testoHaiVinto, testoHaiPerso;
    sf::Text buttonPlay, buttonContinue, buttonNewGame;
    sf::Text buttonExit;
    int menu = 0;

    if (!Font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return EXIT;
    }
    testoHaiVinto.setFont(Font);
    testoHaiVinto.setCharacterSize(charSize);
    testoHaiVinto.setString("HAI VINTO!");
    testoHaiVinto.setPosition({x - dist * 2, y - dist});
    testoHaiVinto.setFillColor(coloreTesto.getColorLib());

    testoHaiPerso.setFont(Font);
    testoHaiPerso.setCharacterSize(charSize);
    testoHaiPerso.setString("HAI PERSO!");
    testoHaiPerso.setPosition({x - dist * 2, y - dist});
    testoHaiPerso.setFillColor(coloreTesto.getColorLib());

    testoGioco.setFont(Font);
    testoGioco.setCharacterSize(charSize);
    testoGioco.setString("Non Gravitar");
    testoGioco.setPosition({x - dist * 2, y - dist});
    testoGioco.setFillColor(coloreTesto.getColorLib());

    buttonPlay.setFont(Font);
    buttonPlay.setCharacterSize(charSize);
    buttonPlay.setString("Play");
    buttonPlay.setPosition({x, y});

    buttonContinue.setFont(Font);
    buttonContinue.setCharacterSize(charSize);
    buttonContinue.setString("Continue");
    buttonContinue.setPosition({x - dist, y});

    buttonNewGame.setFont(Font);
    buttonNewGame.setCharacterSize(charSize);
    buttonNewGame.setString("New Game");
    buttonNewGame.setPosition({x - dist, y});

    buttonExit.setFont(Font);
    buttonExit.setCharacterSize(charSize);
    buttonExit.setString("Exit");
    buttonExit.setPosition({x, y + dist});

    while (Running)
    {
        //Verifying events
        while (App.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return EXIT;
            }
            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
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
            }
        }
        if (menu == 0)
        {
            buttonPlay.setFillColor(rosso.getColorLib());
            buttonContinue.setFillColor(rosso.getColorLib());
            buttonNewGame.setFillColor(rosso.getColorLib());

            buttonExit.setFillColor(bianco.getColorLib());
        }
        else
        {
            buttonPlay.setFillColor(bianco.getColorLib());
            buttonContinue.setFillColor(bianco.getColorLib());
            buttonNewGame.setFillColor(bianco.getColorLib());

            buttonExit.setFillColor(rosso.getColorLib());
        }

        //Clearing screen
        App.clear();
        //Drawing
        if (playing)
        {
            if (haiVinto)
            {
                App.draw(testoHaiVinto);
                App.draw(buttonNewGame);
            }
            else if (haiPerso)
            {
                App.draw(testoHaiPerso);
                App.draw(buttonNewGame);
            }
            else
            {
                App.draw(testoGioco);
                App.draw(buttonContinue);
            }
        }
        else
        {
            App.draw(testoGioco);
            App.draw(buttonPlay);
        }
        App.draw(buttonExit);
        App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return EXIT;
}
