#ifndef VISUALE_OPZIONI_HPP
#define VISUALE_OPZIONI_HPP

#include <iostream>

#include "cScreen.hpp"
#include "./Button.hpp"

extern float WIDTH, HEIGHT;

class visualeOpzioni : public cScreen
{
private:
	float dist = HEIGHT / 8;
    float size = HEIGHT / 8;
	float width = size * 3;
	float height = size;
	float x_rs = size;
	float y_rgt = HEIGHT / 4;
    float x_wasd = WIDTH * 4 / 5;
	float y_wasd = HEIGHT / 3 - size;
	float y_arrow = HEIGHT * 2 / 3 - size;
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

    int dim = 16;
    Button arrayButton[16];

public:
	visualeOpzioni(void);
	void resetButton(void);
	virtual int Run(sf::RenderWindow &App);
};

#endif //VISUALE_OPZIONI_HPP
