#ifndef VISUALE_MENU_HPP
#define VISUALE_MENU_HPP

#include <iostream>

#include "cScreen.hpp"

#include "./SistemaSolare.hpp"
#include "./Button.hpp"

extern SistemaSolare sistemasolare;

class visualeMenu : public cScreen
{
private:
	bool playing = false;
public:
	visualeMenu(void);
	virtual int Run(sf::RenderWindow &App);
};

#endif //VISUALE_MENU_HPP
