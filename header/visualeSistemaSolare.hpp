// visuale sistema solare header
#ifndef VISUALE_SISTEMA_SOLARE
#define VISUALE_SISTEMA_SOLARE

#include <iostream>

#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "cScreen.hpp"

#include "../header/Navicella.hpp"
#include "../header/SistemaSolare.hpp"

class visualeSistemaSolare : public cScreen
{
private:
	bool playing;
public:
	visualeSistemaSolare(void);
	virtual int Run(sf::RenderWindow &App);
};
#endif