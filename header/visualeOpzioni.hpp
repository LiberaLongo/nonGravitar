#ifndef VISUALE_OPZIONI_HPP
#define VISUALE_OPZIONI_HPP

#include <iostream>

#include "cScreen.hpp"

#include "./Button.hpp"

class visualeOpzioni : public cScreen
{
private:

public:
	visualeOpzioni(void);
	virtual int Run(sf::RenderWindow &App);
};

#endif //VISUALE_OPZIONI_HPP
