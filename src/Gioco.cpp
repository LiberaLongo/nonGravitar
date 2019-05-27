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
	visualePianeta vP;
	Screens.push_back(&vP);
	visualeSistemaSolare vS;
	Screens.push_back(&vS);

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
    //ritorno VERO perchè il gioco non è stato ancora implementato
}
