#include <iostream>
using namespace std;

//#include "../header/Gioco.hpp"
#include "../header/Lista.hpp"
#include "../header/Punto.hpp"

//ATTENZIONE!!!!
#include "./definizioni.cpp"
//fine ATTENZIONE!

//#define DIM 5;

int main()
{
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
	//chiamo funzione gioco
	//errore è true se si è presentato un errore, false altrimenti
	//bool errore = Gioco();
	//return (int) errore;
}
