//menù

#include "../header/visualeMenu.hpp"

extern float WIDTH, HEIGHT;
bool generaSistema = true;

visualeMenu::visualeMenu(void)
{
    playing = false;
}

int visualeMenu::Run(sf::RenderWindow &App)
{
    if (generaSistema) {
        sistemasolare.genera();
        generaSistema = false;
    }
    float dist = HEIGHT/8;
    int charSize = HEIGHT/10;
    float x = WIDTH/2 - charSize;
    float y = HEIGHT/2 - charSize;

    sf::Event Event;
    bool Running = true;
    sf::Font Font;
    sf::Text buttonPlay;
    sf::Text buttonExit;
    sf::Text buttonContinue;
    int menu = 0;
    if (!Font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return EXIT;
    }
    buttonPlay.setFont(Font);
    buttonPlay.setCharacterSize(charSize);
    buttonPlay.setString("Play");
    buttonPlay.setPosition({x, y - dist});

    buttonExit.setFont(Font);
    buttonExit.setCharacterSize(charSize);
    buttonExit.setString("Exit");
    buttonExit.setPosition({x, y + dist});

    buttonContinue.setFont(Font);
    buttonContinue.setCharacterSize(charSize);
    buttonContinue.setString("Continue");
    buttonContinue.setPosition({x, y - dist});

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
                        //Let's get play !
                        playing = true;
                        return VISUALE_SISTEMA_SOLARE;
                    }
                    else
                    {
                        //Let's get work...
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
            buttonPlay.setFillColor(sf::Color(255, 0, 0, 255));
            buttonExit.setFillColor(sf::Color(255, 255, 255, 255));
            buttonContinue.setFillColor(sf::Color(255, 0, 0, 255));
        }
        else
        {
            buttonPlay.setFillColor(sf::Color(255, 255, 255, 255));
            buttonExit.setFillColor(sf::Color(255, 0, 0, 255));
            buttonContinue.setFillColor(sf::Color(255, 255, 255, 255));
        }

        //Clearing screen
        App.clear();
        //Drawing
        if (playing)
        {
            App.draw(buttonContinue);
        }
        else
        {
            App.draw(buttonPlay);
        }
        App.draw(buttonExit);
        App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return EXIT;
}