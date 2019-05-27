//visuale pianeta header
#ifndef VISUALE_PIANETA
#define VISUALE_PIANETA

#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class visualePianeta : public cScreen
{
private:
	bool playing;
public:
	visualePianeta(void);
	virtual int Run(sf::RenderWindow &App);
};
#endif