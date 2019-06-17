//#include <SFML/Graphics.hpp>

#include "../header/Gioco.hpp"

//#include "../header/Lista.hpp"
//#include "../header/Punto.hpp"
//#include "../header/SistemaSolare.hpp"
//#include "../header/Navicella.hpp"

//#define DIM 5;

//dimensioni di DEFAULT
float WIDTH = 900.f;
float HEIGHT = 600.f;

int main()
{
	char chose;
	bool errato = true;

	cout << "\nVuoi usare i settaggi di default? (Y/N)";
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
	if (chose == 'n' || chose == 'N')
	{
		cout << "\nHai deciso di MODIFICARE le impostazioni.\n";
		cout << "\nPuoi DECIDERE:";
		do
		{
			cout << "\nle DIMENSIONI dello SCHERMO\n";
			cout << "\tLargezza: ";
			cin >> WIDTH;
			cout << "\tAltezza: ";
			cin >> HEIGHT;
			//controllo se c'è un errore
			errato = (WIDTH < 0 || HEIGHT < 0);
			//non ho modo di controllare se sono maggiori dello schermo del pc
			//almeno per ora
			if (errato)
			{
				cout << "\nERRORE! Inserisci delle dimensioni corrette (comprese tra 0 e la dimensione del tuo schermo)";
			}
		} while (errato);
	}
	else
	{
		cout << "\nHai deciso di TENERE le PRE-impostazioni di DEFAULT.\n";
	}

	//chiamo funzione gioco
	//errore è true se si è presentato un errore, false altrimenti
	int risultato = Gioco();
	return risultato;
	/*
	float X[] = {1, 2, 3, 4, 5};
	float Y[] = {5, 4, 3, 2, 1};
	//testo cose
	ListaClasse<Punto> lista;
	Punto p;
	lista.insert_head(p);
	for(int i = 0; i < 5 ; i++) {
		p.setCoord(X[i], Y[i]);
		lista.insert_head(p);
	}
	lista.print();
	*/
}
