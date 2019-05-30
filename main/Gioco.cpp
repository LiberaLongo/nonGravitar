//codice gioco

#include "../header/Gioco.hpp"

#define DEBUG

SistemaSolare sistemasolare;
//puntatore alla posizione del pianeta corrente
struct Elem<Pianeta> *pianetaInsideNow = nullptr;

int Gioco(void)
{
	//seme per i numeri casuali
	srand(time(NULL));

	//genero il sistema solare
	sistemasolare.genera();
#ifdef DEBUG
	sistemasolare.printCentri();
#endif

	//Applications variables
	std::vector<cScreen *> Screens;
	int screen = 0;

	//Window creation
	sf::RenderWindow App(sf::VideoMode(WIDTH, HEIGHT), "SFML nonGravitar");

	//Mouse cursor visible? true => yes,it is; false => no it is'nt
	//App.setMouseCursorVisible(true);

	//Screens preparations
	visualeSistemaSolare vS;
	Screens.push_back(&vS);
	visualePianeta vP;
	Screens.push_back(&vP);

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
	//ritorno VERO perchè il gioco non è stato ancora implementato
}
