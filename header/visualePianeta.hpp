//visuale pianeta header
#ifndef VISUALE_PIANETA_H
#define VISUALE_PIANETA_H

#include <iostream>
#include "./cScreen.hpp"

#include <SFML/Graphics.hpp>

#include "./utils.hpp"
#include "./SistemaSolare.hpp"

extern SistemaSolare sistemasolare;

class visualePianeta : public cScreen
{
private:
	bool playing;
public:
	visualePianeta(void);
	virtual int Run(sf::RenderWindow &App);
};

#endif //VISUALE_PIANETA_H