//visuale pianeta header
#ifndef VISUALE_PIANETA_HPP
#define VISUALE_PIANETA_HPP

#include <iostream>

#include "./cScreen.hpp"

#include "./SistemaSolare.hpp"

extern SistemaSolare sistemasolare;
extern struct Elem<Pianeta> *pianetaInsideNow;

class visualePianeta : public cScreen
{
private:
	Navicella player;
	Pianeta pianetaVisualizzato;
	sf::Clock orologio;
public:
	visualePianeta(void);
	virtual int Run(sf::RenderWindow &App);
};

#endif //VISUALE_PIANETA_HPP
