//codice gioco

#include "../header/Gioco.hpp"

//#define DEBUG

int Gioco(void)
{
    	//Applications variables
	std::vector<cScreen*> Screens;
	int screen = 0;

	//Window creation
	sf::RenderWindow App(sf::VideoMode(WIDTH, HEIGHT), "SFML nonGravitar");

	//Mouse cursor no more visible
	App.setMouseCursorVisible(false);

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
