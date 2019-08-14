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
}

int visualeOpzioni::Run(sf::RenderWindow &App)
{
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

    //BOTTONI
    float dist = HEIGHT / 8;
    float size = HEIGHT / 8, width = size * 3, height = size, x_rs = size, y_rgt = HEIGHT / 4;
    float x_wasd = WIDTH * 4 / 5, y_wasd = HEIGHT / 3 - size, y_arrow = HEIGHT * 2 / 3 - size;
    float x_mouse = WIDTH / 2, y_mouse = HEIGHT / 2;
    //WASD buttons
    Button buttonW = Button(x_wasd, y_wasd - size, "W", size);
    Button buttonA = Button(x_wasd - size, y_wasd, "A", size);
    Button buttonS = Button(x_wasd, y_wasd, "S", size);
    Button buttonD = Button(x_wasd + size, y_wasd, "D", size);
    //arrows buttons
    Button buttonUp = Button(x_wasd, y_arrow - size, "^", size);
    Button buttonLeft = Button(x_wasd - size, y_arrow, "<", size);
    Button buttonDown = Button(x_wasd, y_arrow, "v", size);
    Button buttonRight = Button(x_wasd + size, y_arrow, ">", size);
    //key move
    Button buttonMove = Button(WIDTH / 2, size * 3 / 2, "Space", width, height);
    //key shoot
    Button buttonShoot = Button(x_rs, HEIGHT * 2 / 3, "Enter", width, height);
    //key raggio traente
    Button buttonRaggio1 = Button(x_rs, y_rgt - height, "LShift", width, height);
    Button buttonRaggio2 = Button(x_rs, y_rgt, "RShift", width, height);
    //mouse
    Button buttonMouseLeft = Button(x_mouse - size, y_mouse, "L", size);
    Button buttonMouseRight = Button(x_mouse, y_mouse, "R", size);

    //reset button
    Button buttonReset = Button(0.f, HEIGHT - dist, "Reset");
    //exit button
    Button buttonBack = Button(WIDTH * 2 / 3, HEIGHT - dist, "Back");

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
                if (buttonBack.checkMouse(mouseClick))
                {
                    //fine dei giochi, si torna a lavoro...
                    return VISUALE_MENU;
                }
            case sf::Event::KeyPressed:
                //Esc per uscire
                switch (event.key.code)
                {
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
        //forma del mouse
        App.draw(mouseCircle);
        App.draw(mouseRectangle);
        //testo Opzioni
        App.draw(testoOptions);
        App.draw(testoMove);
        App.draw(testoShoot);
        App.draw(testoRaggioTraente);
        //WASD buttons
        buttonW.draw(App);
        buttonA.draw(App);
        buttonS.draw(App);
        buttonD.draw(App);
        //arrows buttons
        buttonUp.draw(App);
        buttonLeft.draw(App);
        buttonDown.draw(App);
        buttonRight.draw(App);
        //key move
        buttonMove.draw(App);
        //key shoot
        buttonShoot.draw(App);
        //key raggio traente
        buttonRaggio1.draw(App);
        buttonRaggio2.draw(App);
        //mouse
        buttonMouseLeft.draw(App);
        buttonMouseRight.draw(App);
        //altri
        buttonReset.draw(App);
        buttonBack.draw(App);
        //showing
        App.display();
    }
    //Never reaching this point normally, but just in case, exit the application
    return EXIT;
}
