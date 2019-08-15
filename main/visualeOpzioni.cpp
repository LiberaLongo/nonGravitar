//codice opzioni
#include "../header/visualeOpzioni.hpp"

//menù

#include "../header/visualeMenu.hpp"

extern float WIDTH, HEIGHT;

//tastiera
int MOVE_UP_1 = sf::Keyboard::W, MOVE_UP_2 = sf::Keyboard::Up;
int MOVE_LEFT_1 = sf::Keyboard::A, MOVE_LEFT_2 = sf::Keyboard::Left;
int MOVE_DOWN_1 = sf::Keyboard::S, MOVE_DOWN_2 = sf::Keyboard::Down;
int MOVE_RIGHT_1 = sf::Keyboard::D, MOVE_RIGHT_2 = sf::Keyboard::Right;
int RAGGIO_TRAENTE_1 = sf::Keyboard::LShift, RAGGIO_TRAENTE_2 = sf::Keyboard::RShift;
int KEY_MOVE = sf::Keyboard::Space, KEY_SHOOT = sf::Keyboard::Return;
//mouse
int MOUSE_SHOOT = sf::Mouse::Left, MOUSE_MOVE = sf::Mouse::Right;

visualeOpzioni::visualeOpzioni(void)
{
    //vuoto
}

void visualeOpzioni::resetButton(void)
{
    //tastiera
    MOVE_UP_1 = sf::Keyboard::W;
    MOVE_UP_2 = sf::Keyboard::Up;
    MOVE_LEFT_1 = sf::Keyboard::A;
    MOVE_LEFT_2 = sf::Keyboard::Left;
    MOVE_DOWN_1 = sf::Keyboard::S;
    MOVE_DOWN_2 = sf::Keyboard::Down;
    MOVE_RIGHT_1 = sf::Keyboard::D;
    MOVE_RIGHT_2 = sf::Keyboard::Right;
    RAGGIO_TRAENTE_1 = sf::Keyboard::LShift;
    RAGGIO_TRAENTE_2 = sf::Keyboard::RShift;
    KEY_MOVE = sf::Keyboard::Space;
    KEY_SHOOT = sf::Keyboard::Return;
    //mouse
    MOUSE_SHOOT = sf::Mouse::Left;
    MOUSE_MOVE = sf::Mouse::Right;

    //stringa dei bottoni
    /*
    //tastiera
    this->buttonW.setString("W");
    this->buttonA.setString("A");
    this->buttonS.setString("S");
    this->buttonD.setString("D");
    this->buttonUp.setString("^");
    this->buttonLeft.setString("<");
    this->buttonDown.setString("v");
    this->buttonRight.setString(">");
    this->buttonRaggio1.setString("LShift");
    this->buttonRaggio2.setString("RShift");
    this->buttonMove.setString("Space");
    this->buttonShoot.setString("Enter");
    //mouse
    this->buttonMouseLeft.setString("L");
    this->buttonMouseRight.setString("R");
    */
}

int visualeOpzioni::Run(sf::RenderWindow &App)
{
    int menu = 0;

    //TESTO
    int charSize = HEIGHT/10;
    sf::Font Font;

    sf::Text testoOptions, testoMove, testoShoot, testoRaggioTraente;
    //colore del testo
    ColoreRGB coloreTesto = ColoreRGB(LUMUS_MAXIMA, 0, LUMUS_MAXIMA);
    if (!Font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return EXIT;
    }
    //opzioni
    testoOptions.setFont(Font);
    testoOptions.setCharacterSize(charSize);
    testoOptions.setString("Options");
    testoOptions.setPosition({WIDTH/3, 0.f});

    testoMove.setFont(Font);
    testoMove.setCharacterSize(charSize);
    testoMove.setString("Move");
    testoMove.setPosition({WIDTH*7/12, HEIGHT*9/24});

    testoShoot.setFont(Font);
    testoShoot.setCharacterSize(charSize);
    testoShoot.setString("Shoot");
    testoShoot.setPosition({WIDTH/4, HEIGHT*3/5});

    testoRaggioTraente.setFont(Font);
    testoRaggioTraente.setCharacterSize(charSize);
    testoRaggioTraente.setString("R.T.");
    testoRaggioTraente.setPosition({WIDTH/4, HEIGHT/5});

#ifndef NON_FUNZIONA_FILL_COLOR
    testoOptions.setFillColor(coloreTesto.getColorLib());
    testoMove.setFillColor(coloreTesto.getColorLib());
    testoShoot.setFillColor(coloreTesto.getColorLib());
    testoRaggioTraente.setFillColor(coloreTesto.getColorLib());
#endif
#ifdef NON_FUNZIONA_FILL_COLOR
    testoOptions.setColor(coloreTesto.getColorLib());
    testoMove.setColor(coloreTesto.getColorLib());
    testoShoot.setColor(coloreTesto.getColorLib());
    testoRaggioTraente.setColor(coloreTesto.getColorLib());
#endif

    //BOTTONI (nell .hpp)
	Button arrayButton[] = {
        this->buttonW, this->buttonA, this->buttonS, this->buttonD,
        this->buttonUp, this->buttonLeft, this->buttonDown, this->buttonRight,
        this->buttonRaggio1, this->buttonRaggio2,
        this->buttonMove, this->buttonShoot,
        this->buttonMouseLeft, this->buttonMouseRight,
        //gli ultimi sono reset e back      
        this->buttonReset, this->buttonBack
    };
    int dim = sizeof(arrayButton)/sizeof(arrayButton[0]);

    //mouseShape
    // define a circle
    sf::CircleShape mouseCircle(size);
    mouseCircle.setPosition(x_mouse - size, y_mouse + size );
    mouseCircle.setFillColor(sf::Color::Green);
    //define a rectangle
    sf::RectangleShape mouseRectangle({size*2, size});
    mouseRectangle.setPosition(x_mouse - size, y_mouse + size );
    mouseRectangle.setFillColor(sf::Color::Green);
    //mouseShape = mouseCircle union mouseRectangle

    sf::Event event;
    bool Running = true;

    //un punto adibito a mouse click
    Punto mouseClick;
#ifdef NOME_PUNTO
    mouseClick.setName("MOUSE");
#endif

    //
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
                for(int i = 0; i < dim ; i++) {
                    if(arrayButton[i].checkMouse(mouseClick)) {
                        menu = i;
                        break; //esci dal ciclo for
                    }
                }
                if (menu == dim - 2) { //if reset
                    this->resetButton();
                }
                else if (menu == dim - 1) //if back
                {
                    //fine dei giochi, si torna a lavoro...
                    return VISUALE_MENU;
                }
                break;
            case sf::Event::KeyPressed:
                //Esc per uscire
                if( event.key.code == sf::Keyboard::Escape)
                    return VISUALE_MENU;
                else {
                    switch(menu) {
                        case 0:
                            MOVE_UP_1 = event.key.code;
                            break;
                        case 1:
                            MOVE_LEFT_1 = event.key.code;
                            break;
                        case 2:
                            MOVE_DOWN_1 = event.key.code;
                            break;
                        case 3:
                            MOVE_RIGHT_1 = event.key.code;
                            break;
                        case 4:
                            MOVE_UP_2 = event.key.code;
                            break;
                        case 5:
                            MOVE_LEFT_2 = event.key.code;
                            break;
                        case 6:
                            MOVE_DOWN_2 = event.key.code;
                            break;
                        case 7:
                            MOVE_RIGHT_2 = event.key.code;
                            break;
                        case 8:
                            RAGGIO_TRAENTE_1 = event.key.code;
                            break;
                        case 9:
                            RAGGIO_TRAENTE_2 = event.key.code;
                            break;
                        case 10:
                            KEY_MOVE = event.key.code;
                            break;
                        case 11:
                            KEY_SHOOT = event.key.code;
                            break;
                        default:
                            break;
                    }
                    if( !( menu == dim-2 || menu == dim-1) )
                    arrayButton[menu].setString(to_string(event.key.code));
                }
            default:
                break;
            }
        }
        //tutti i bottoni checked false
        for(int i = 0; i < dim; i++) {
            arrayButton[i].setChecked(false);
        }
        //e risetta il button menu a true
        arrayButton[menu].setChecked(true);
        //Clearing screen
        App.clear();
        //Drawing
        //forma del mouse
        App.draw(mouseCircle);
        App.draw(mouseRectangle);
        //disegna i testi
        App.draw(testoOptions);
        App.draw(testoMove);
        App.draw(testoShoot);
        App.draw(testoRaggioTraente);
        //disegna ogni button
        for(int i = 0; i < dim; i++) {
            arrayButton[i].draw(App);
        }
        //showing
        App.display();
    }
    //Never reaching this point normally, but just in case, exit the application
    return EXIT;
}
