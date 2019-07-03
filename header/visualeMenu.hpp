#ifndef VISUALE_MENU_H
#define VISUALE_MENU_H

#include <iostream>

#include "cScreen.hpp"

#include "./SistemaSolare.hpp"

extern SistemaSolare sistemasolare;

class visualeMenu : public cScreen
{
private:
	bool playing = false;
public:
	visualeMenu(void);
	virtual int Run(sf::RenderWindow &App);
};

#endif //VISUALE_MENU_H
