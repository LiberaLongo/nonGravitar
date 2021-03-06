#include "../header/visualeOpzioni.hpp"

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

string testi[] = {"W", "A", "S", "D", "^", "<", "v", ">", "LShift", "RShift", "Space", "Enter"};

visualeOpzioni::visualeOpzioni(void)
{
    this->arrayButton[0] = this->buttonW;
    this->arrayButton[1] = this->buttonA;
    this->arrayButton[2] = this->buttonS;
    this->arrayButton[3] = this->buttonD;
    this->arrayButton[4] = this->buttonUp;
    this->arrayButton[5] = this->buttonLeft;
    this->arrayButton[6] = this->buttonDown;
    this->arrayButton[7] = this->buttonRight;
    this->arrayButton[8] = this->buttonRaggio1;
    this->arrayButton[9] = this->buttonRaggio2;
    this->arrayButton[10] = this->buttonMove;
    this->arrayButton[11] = this->buttonShoot;
    //mouse
    this->arrayButton[12] = this->buttonMouseLeft;
    this->arrayButton[13] = this->buttonMouseRight;
    //gli ultimi sono reset e back
    this->arrayButton[14] = this->buttonReset;
    this->arrayButton[15] = this->buttonBack;
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
    //resetto i testi
    testi[0] = "W";
    testi[1] = "A";
    testi[2] = "S";
    testi[3] = "D";
    testi[4] = "^";
    testi[5] = "<";
    testi[6] = "v";
    testi[7] = ">";
    testi[8] = "LShift";
    testi[9] = "RShift";
    testi[10] = "Space";
    testi[11] = "Enter";
    //modifico i testi dei bottoni
    for (int i = 0; i < this->dim - 4; i++)
    {
        this->arrayButton[i].setString(testi[i]);
    }
}

int visualeOpzioni::Run(sf::RenderWindow &App)
{
    int menu = 0;

    //TESTO
    int charSize = HEIGHT / 10;
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
    testoOptions.setPosition({WIDTH / 3, 0.f});

    testoMove.setFont(Font);
    testoMove.setCharacterSize(charSize);
    testoMove.setString("Move");
    testoMove.setPosition({WIDTH * 7 / 12, HEIGHT * 9 / 24});

    testoShoot.setFont(Font);
    testoShoot.setCharacterSize(charSize);
    testoShoot.setString("Shoot");
    testoShoot.setPosition({WIDTH / 4, HEIGHT * 3 / 5});

    testoRaggioTraente.setFont(Font);
    testoRaggioTraente.setCharacterSize(charSize);
    testoRaggioTraente.setString("R.T.");
    testoRaggioTraente.setPosition({WIDTH / 4, HEIGHT / 5});

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

    //mouseShape
    //cerchio
    sf::CircleShape mouseCircle(size);
    mouseCircle.setPosition(x_mouse - size, y_mouse + size);
    mouseCircle.setFillColor(sf::Color::Green);
    //rettangolo
    sf::RectangleShape mouseRectangle({size * 2, size});
    mouseRectangle.setPosition(x_mouse - size, y_mouse + size);
    mouseRectangle.setFillColor(sf::Color::Green);
    //mouseShape = cerchio union rettangolo

    sf::Event event;
    bool Running = true;

    //un punto adibito a mouse click
    Punto mouseClick;

    //
    while (Running)
    {
        //Verifying events
        while (App.pollEvent(event))
        {
            //finestra chiusa
            switch (event.type)
            {
            //finestra chiusa
            case sf::Event::Closed:
                return EXIT;
                break;
            //mouse
            case sf::Event::MouseButtonPressed:
                mouseClick.setCoord(event.mouseButton.x, event.mouseButton.y);
                //controlla quale bottone è stato premuto
                for (int i = 0; i < this->dim; i++)
                {
                    if (this->arrayButton[i].checkMouse(mouseClick))
                    {
                        menu = i;
                        break; //esci dal ciclo for
                    }
                }
                if (menu == this->dim - 2)
                { //if reset
                    this->resetButton();
                }
                else if (menu == this->dim - 1) //if back
                {
                    //fine dei giochi, si torna a lavoro...
                    return VISUALE_MENU;
                }
                break;
            //tastiera
            case sf::Event::KeyPressed:
                //Esc per uscire
                if (event.key.code == sf::Keyboard::Escape)
                    return VISUALE_MENU;
                else
                {
                    //si modificano i comandi
                    switch (menu)
                    {
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
                    if (menu < this->dim - 4)
                    {
                        //modifico la scritta del bottone
                        testi[menu] = to_string(event.key.code);
                        this->arrayButton[menu].setString(testi[menu]);
                    }
                }
            default:
                break;
            }
        }
        //tutti i bottoni checked false
        for (int i = 0; i < this->dim; i++)
        {
            this->arrayButton[i].setChecked(false);
        }
        //e risetta il button menu a true
        this->arrayButton[menu].setChecked(true);
        //pulisci scherma
        App.clear();
        //disegna
        //forma del mouse
        App.draw(mouseCircle);
        App.draw(mouseRectangle);
        //disegna i testi
        App.draw(testoOptions);
        App.draw(testoMove);
        App.draw(testoShoot);
        App.draw(testoRaggioTraente);
        //disegna ogni button
        for (int i = 0; i < this->dim; i++)
        {
            this->arrayButton[i].draw(App);
        }
        //mostra
        App.display();
    }
    //non dovrebbe mai arrivare qui
    return EXIT;
}
