//codice opzioni
#include "../header/visualeOpzioni.hpp"

//menù

#include "../header/visualeMenu.hpp"

extern float WIDTH, HEIGHT;

visualeOpzioni::visualeOpzioni(void)
{
    //vuoto
}

int visualeOpzioni::Run(sf::RenderWindow &App)
{
    float dist = HEIGHT / 6;
    float x = WIDTH / 4;
    float y = HEIGHT / 3;
    //colore della vittoria
    ColoreRGB coloreTesto = ColoreRGB(LUMUS_MAXIMA, 0, LUMUS_MAXIMA);

    Button buttonReset = Button(x, y + dist, "Reset");
    //exit button
    Button buttonExit = Button(x, y + dist*2, "Exit");

    sf::Event event;
    bool Running = true;

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
            case sf::Event::KeyPressed:
                //Esc per uscire
                switch(event.key.code) {
                    case sf::Keyboard::Escape:
                        return VISUALE_MENU;
                        break;
                    default:
                        break;                    
                }
            default:
                break;
            }
        }
        //Clearing screen
        App.clear();
        //Drawing
        buttonExit.draw(App);
        buttonReset.draw(App);
        //showing
        App.display();
    }
    //Never reaching this point normally, but just in case, exit the application
    return EXIT;
}
