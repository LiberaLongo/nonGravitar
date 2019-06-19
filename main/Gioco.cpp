//codice gioco

#include "../header/Gioco.hpp"

//#define DEBUG

//condizioni di esistenza per evitare bug eccessivi nel gioco
#define MIN_SCHERMO 50.f
#define MAX_NAVICELLA 20.f


//dimensioni di DEFAULT
float WIDTH = 900.f;
float HEIGHT = 600.f;
//raggio minimo e massimo del pianeta
float MIN_PIANETA_RAGGIO = 20.f;
float MAX_PIANETA_RAGGIO = 60.f;
//dimensioni della navicella
float SIZE_NAVICELLA = 10.f;

SistemaSolare sistemasolare;
//puntatore alla posizione del pianeta corrente
struct Elem<Pianeta> *pianetaInsideNow = nullptr;

void impostazioniGioco(void)
{
	char chose;
	bool errato = true;

	cout << "\nVuoi MODIFICARE i settaggi di default?";
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
			cout << "\tLargezza (>= " << MIN_SCHERMO << ", default = " << WIDTH << " ):\t";
			cin >> WIDTH;
			cout << "\tAltezza (>= " << MIN_SCHERMO << ", default = " << HEIGHT << "):\t\t";
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

		//dimensioni PIANETA
		do
		{
			cout << "\nle dimensioni del PIANETA\n";
			cout << "\tminimo (default = " << MIN_PIANETA_RAGGIO << "):\t\t\t";
			cin >> MIN_PIANETA_RAGGIO;
			cout << "\tmassimo (default = " << MAX_PIANETA_RAGGIO << "):\t\t\t"; 
			cin >> MAX_PIANETA_RAGGIO;
			//controllo se c'è un errore
			errato = (MIN_PIANETA_RAGGIO < 0 || MIN_PIANETA_RAGGIO < 0 || MAX_PIANETA_RAGGIO < MIN_PIANETA_RAGGIO);
			//non ho modo di controllare se sono maggiori dello schermo del pc
			//almeno per ora
			if (errato)
			{
				cout << "\nERRORE! Inserisci delle dimensioni del pianeta corrette";
				cout << "\n(maggiori di 0, e con minimo < massimo)";
			}
		} while (errato);

		//dimensioni NAVICELLA
		do
		{
			cout << "\nla dimensione della NAVICELLA\n";
			cout << "\tsize (<= " << MAX_NAVICELLA << ", default = " << SIZE_NAVICELLA << "):\t\t";
			cin >> SIZE_NAVICELLA;
			//controllo se c'è un errore
			errato = (SIZE_NAVICELLA < 0 || SIZE_NAVICELLA > MAX_NAVICELLA);
			//non ho modo di controllare se sono maggiori dello schermo del pc
			//almeno per ora
			if (errato)
			{
				cout << "\nERRORE! Inserisci delle dimensioni della navicella corrette";
				cout << "\n(comprese tra 0 e " << MAX_NAVICELLA << ")";
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
