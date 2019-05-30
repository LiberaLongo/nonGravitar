// visuale sistema solare header
#ifndef VISUALE_SISTEMA_SOLARE_H
#define VISUALE_SISTEMA_SOLARE_H

#include <iostream>

#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "cScreen.hpp"

#include "../header/Navicella.hpp"
#include "../header/SistemaSolare.hpp"

extern SistemaSolare sistemasolare;
extern struct Elem<Pianeta> *pianetaInsideNow;

class visualeSistemaSolare : public cScreen
{
private:
	Navicella player;

private:
	bool check(bool move);

public:
	visualeSistemaSolare(void);
	virtual int Run(sf::RenderWindow &App);
};
#endif //VISUALE_SISTEMA_SOLARE_H