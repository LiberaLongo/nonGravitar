//visuale pianeta header
#ifndef VISUALE_PIANETA_H
#define VISUALE_PIANETA_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "./cScreen.hpp"

#include "./utils.hpp"
#include "./SistemaSolare.hpp"

extern SistemaSolare sistemasolare;
extern struct Elem<Pianeta> *pianetaInsideNow;

class visualePianeta : public cScreen
{
private:
	Navicella player;
	Pianeta pianetaVisualizzato;
public:
	visualePianeta(void);
	virtual int Run(sf::RenderWindow &App);
};

#endif //VISUALE_PIANETA_H