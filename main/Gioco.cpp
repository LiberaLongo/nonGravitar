//codice gioco

#include "../header/Gioco.hpp"

//#define DEBUG

//condizioni di esistenza per evitare bug eccessivi nel gioco
#define MIN_SCHERMO 300.f
#define MAX_NAVICELLA 20.f
#define MAX_SPEED 20.f

//dimensioni di DEFAULT
// 1366 x 768 risoluzione di uno scermo a 11,6 pollici
float WIDTH = 1200.f;
float HEIGHT = 600.f;
//raggio minimo e massimo del pianeta
float MIN_PIANETA_RAGGIO = 20.f;
float MAX_PIANETA_RAGGIO = 60.f;
//dimensioni della navicella
float SIZE_NAVICELLA = 10.f;
float SPEED_NAVICELLA = 5.f;

SistemaSolare sistemasolare;
//puntatore alla posizione del pianeta corrente
struct Elem<Pianeta> *pianetaInsideNow = nullptr;

void impostazioniGioco(void)
{
	char chose;
	bool errato = true;
	cout << "\nSETTAGGI DI DEFAULT: ";
	cout << "\nSchermo (width x height): " << WIDTH << " x " << HEIGHT << ".";
	cout << "\nNavicella: size = " << SIZE_NAVICELLA << ", speed = " << SPEED_NAVICELLA << ".";
	cout << "\nPianeti raggio: min = " << MIN_PIANETA_RAGGIO << ", max = " << MAX_PIANETA_RAGGIO << ".";

	cout << "\n\nVuoi MODIFICARE i settaggi di default?";
	cout << "\n(Y/N o un altro tasto per continuare)\t";
	//chiedo se si vogliono usare le impostazioni di default
	cin >> chose;

	//se si vogliono cambiare gestisco ciò
	if (chose == 'y' || chose == 'Y')
	{
		cout << "\nHai deciso di MODIFICARE le impostazioni.\n";
		cout << "\nPuoi DECIDERE:";

		//dimensioni SCHERMO
		do
		{
			cout << "\nle dimensioni dello SCHERMO\n";
			cout << "\tLargezza (>= " << MIN_SCHERMO << ", ora è = " << WIDTH << " ):\t";
			cin >> WIDTH;
			cout << "\tAltezza  (>= " << MIN_SCHERMO << ", ora è = " << HEIGHT << " ):\t";
			cin >> HEIGHT;
			//controllo se c'è un errore
			errato = (WIDTH < MIN_SCHERMO || HEIGHT < MIN_SCHERMO);
			//non ho modo di controllare se sono maggiori dello schermo del pc
			//almeno per ora
			if (errato)
			{
				cout << "\nERRORE! Inserisci delle dimensioni dello schermo corrette";
				cout <<"\n(comprese tra " << MIN_SCHERMO << " e la dimensione del tuo fullscreen)";
			}
		} while (errato);

		//NAVICELLA
		do
		{
			cout << "\ndella NAVICELLA";
			cout << "\n    la dimensione";
			cout << "\n\tsize (3 <= size <= " << MAX_NAVICELLA << ", ora è = " << SIZE_NAVICELLA << " ):\t";
			cin >> SIZE_NAVICELLA;
			cout << "    la velocità";
			cout << "\n\tspeed (1 <= speed <= " << MAX_SPEED << ", ora è = " << SPEED_NAVICELLA << " ):\t";
			cin >> SPEED_NAVICELLA;
			//controllo se c'è un errore
			errato = (SIZE_NAVICELLA < 3.f || SIZE_NAVICELLA > MAX_NAVICELLA) || (SPEED_NAVICELLA < 1.f || SPEED_NAVICELLA > MAX_SPEED);
			//non ho modo di controllare se sono maggiori dello schermo del pc
			//almeno per ora
			if (errato)
			{
				cout << "\nERRORE! Inserisci delle dimensioni della navicella corrette";
				cout << "\n(dimensioni comprese tra 0 e " << MAX_NAVICELLA << " )";
				cout << "\n(velocità compresa tra 3 e " << MAX_SPEED << " )";
			}
		} while (errato);

		//dimensioni PIANETA
		do
		{
			cout << "\nle dimensioni del PIANETA\n";
			cout << "\tminimo (>= " << SPEED_NAVICELLA << ", ora è = " << MIN_PIANETA_RAGGIO << " ):\t\t";
			cin >> MIN_PIANETA_RAGGIO;
			cout << "\tmassimo (>= " << SPEED_NAVICELLA << ", ora è = " << MAX_PIANETA_RAGGIO << " ):\t\t"; 
			cin >> MAX_PIANETA_RAGGIO;
			//controllo se c'è un errore
			errato = (MIN_PIANETA_RAGGIO < SPEED_NAVICELLA) || (MIN_PIANETA_RAGGIO < SPEED_NAVICELLA) || MAX_PIANETA_RAGGIO < MIN_PIANETA_RAGGIO;
			//non ho modo di controllare se sono maggiori dello schermo del pc
			//almeno per ora
			if (errato)
			{
				cout << "\nERRORE! Inserisci delle dimensioni del pianeta corrette";
				cout << "\n(maggiori di 0, e con minimo < massimo)";
			}
		} while (errato);
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

	//genero il sistema solare la prima volta
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
	visualeMenu vM;
	Screens.push_back(&vM);
	//indirizzo visuale pianeta nel vettore 0
	visualeSistemaSolare vS;
	Screens.push_back(&vS);
	//indirizzo visuale sistema solare nel vettore 1
	visualePianeta vP;
	Screens.push_back(&vP);
	//indirizzo visuale pianeta nel vettore 2
	visualeOpzioni vO;
	Screens.push_back(&vO);
	//indirizzo visuale opzioni nel vettore 3

	//se questi indirizzi vengono modificati bisogna modificare anche VISUALE_... di utils.hpp

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
	//ritorno VERO perchè il gioco non è stato ancora implementato
}
