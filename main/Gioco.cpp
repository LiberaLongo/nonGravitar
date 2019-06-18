//codice gioco

#include "../header/Gioco.hpp"

//#define DEBUG

//condizioni di esistenza per evitare bug eccessivi nel gioco
#define MIN_SCHERMO 50.f
#define MAX_SIZE_NAVICELLA 20.f
#define MIN_SPEED_NAVICELLA 1.f
#define MAX_SPEED_NAVICELLA 20.f

//dimensioni di DEFAULT
//dimenzioni dello SCHERMO
float WIDTH = 900.f;
float HEIGHT = 600.f;
//dimensioni della navicella
float SIZE_NAVICELLA = 10.f;
float SPEED_NAVICELLA = 5.f;
//raggio minimo e massimo del pianeta
float MIN_PIANETA_RAGGIO = 20.f;
float MAX_PIANETA_RAGGIO = 60.f;

SistemaSolare sistemasolare;
//puntatore alla posizione del pianeta corrente
struct Elem<Pianeta> *pianetaInsideNow = nullptr;

void impostazioniGioco(void)
{
}

int Gioco(void)
{
	//chiedi all'utente se vuole modificare le preimpostazioni
	impostazioniGioco();

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
	//indirizzo visuale sistema solare nel vettore 0
	visualePianeta vP;
	Screens.push_back(&vP);
	//indirizzo visuale pianeta nel vettore 1
	//se questi indirizzi vengono modificati bisogna modificare anche VISUALE_... di utils.hpp

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
	//ritorno VERO perchè il gioco non è stato ancora implementato
}
