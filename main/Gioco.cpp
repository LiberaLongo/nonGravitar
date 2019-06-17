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
	char chose;
	bool errato = true;

	cout << "\nVuoi MODIFICARE i settaggi di default? (Y/N)\t";
	//chiedo se si vogliono usare le impostazioni di default
	do
	{
		cin >> chose;
		//controllo se c'è un errore
		errato = !(chose == 'y' || chose == 'n' || chose == 'Y' || chose == 'N');
		if (errato)
		{
			cout << "\nERRORE! Inserisci [y] o [n] non altri caratteri!";
		}
	} while (errato);

	//se si vogliono cambiare gestisco ciò
	if (chose == 'y' || chose == 'Y')
	{
		//dimensioni di DEFAULT
		//dimenzioni dello SCHERMO
		float width = WIDTH;
		float height = HEIGHT;
		//dimensioni della navicella
		float size_navicella = SIZE_NAVICELLA;
		float speed_navicella = SPEED_NAVICELLA;
		//raggio minimo e massimo del pianeta
		float min_pianeta_raggio = MIN_PIANETA_RAGGIO;
		float max_pianeta_raggio = MAX_PIANETA_RAGGIO;

		cout << "\nHai deciso di MODIFICARE le impostazioni.\n";
		cout << "\nPuoi DECIDERE:";

		//dimensioni SCHERMO
		do
		{
			cout << "\nle dimensioni dello SCHERMO\n";
			cout << "\tLargezza (>= " << MIN_SCHERMO << ", default = " << WIDTH << " ):\t\t";
			cin >> width;
			cout << "\tAltezza (>= " << MIN_SCHERMO << ", default = " << HEIGHT << " ):\t\t";
			cin >> height;
			//controllo se c'è un errore
			errato = (width < MIN_SCHERMO || height < MIN_SCHERMO);
			//non ho modo di controllare se sono maggiori dello schermo del pc
			//almeno per ora
			if (errato)
			{
				cout << "\nERRORE! Inserisci delle dimensioni dello schermo corrette";
				cout << "\n(comprese tra " << MIN_SCHERMO << " e la dimensione del tuo fullscreen)";
			}
		} while (errato);

		//dimensioni NAVICELLA
		do
		{
			cout << "\ndella NAVICELLA\n";
			cout << "    la dimensione\n";
			cout << "\tsize (<= " << MAX_SIZE_NAVICELLA << ", default = " << SIZE_NAVICELLA << " ):\t\t\t";
			cin >> size_navicella;
			cout << "    la velocità\n";
			cout << "\tspeed ( " << MIN_SPEED_NAVICELLA << " <= speed <= " << MAX_SPEED_NAVICELLA << ", default = " << SPEED_NAVICELLA << " ):\t";
			cin >> speed_navicella;
			//controllo se c'è un errore
			errato = ((size_navicella < 0 || size_navicella > MAX_SIZE_NAVICELLA) || (speed_navicella < MIN_SPEED_NAVICELLA || speed_navicella > MAX_SPEED_NAVICELLA));
			//non ho modo di controllare se sono maggiori dello schermo del pc
			//almeno per ora
			if (errato)
			{
				cout << "\nERRORE! Inserisci delle dimensioni e una velocità della navicella corrette";
				cout << "\n(dimensini comprese tra 0 e " << MAX_SIZE_NAVICELLA << " )";
				cout << "\n(" << MIN_SPEED_NAVICELLA << " <= speed <= " << MAX_SPEED_NAVICELLA << ")";
			}
		} while (errato);

		//dimensioni PIANETA
		do
		{
			cout << "\nle dimensioni del PIANETA";
			cout << "\n    (entrambi maggiori della velocità della navicella = " << speed_navicella << " )\n";
			cout << "\tminimo (default = " << MIN_PIANETA_RAGGIO << " ):\t\t\t\t";
			cin >> min_pianeta_raggio;
			cout << "\tmassimo (default = " << MAX_PIANETA_RAGGIO << " ):\t\t\t";
			cin >> max_pianeta_raggio;
			//controllo se c'è un errore
			errato = (min_pianeta_raggio < speed_navicella || max_pianeta_raggio < min_pianeta_raggio);
			//non ho modo di controllare se sono maggiori dello schermo del pc
			//almeno per ora
			if (errato)
			{
				cout << "\nERRORE! Inserisci delle dimensioni del pianeta corrette";
				cout << "\n(maggiori di " << speed_navicella << ", e con minimo < massimo)";
			}
		} while (errato);

		//aggiorno i valori modificati

		//dimensioni di DEFAULT
		//dimenzioni dello SCHERMO
		float WIDTH = width;
		float HEIGHT = height;
		//dimensioni della navicella
		float SIZE_NAVICELLA = size_navicella;
		float SPEED_NAVICELLA = speed_navicella;
		//raggio minimo e massimo del pianeta
		float MIN_PIANETA_RAGGIO = min_pianeta_raggio;
		float MAX_PIANETA_RAGGIO = max_pianeta_raggio;
	}
	else
	{
		cout << "\nHai deciso di TENERE le PRE-impostazioni di DEFAULT.\n";
	}

	cout << "\nINIZIA IL GIOCO!\n";
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
