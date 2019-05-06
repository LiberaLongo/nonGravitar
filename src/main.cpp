#include <iostream>
using namespace std;

//#include "../header/Gioco.hpp"
#include "../header/Lista.hpp"
#include "../header/Punto.hpp"

//ATTENZIONE!!!!
#include "./definizioni.cpp"
//fine ATTENZIONE!

int main()
{

	//testo cose
	Punto p(100, 100);
	p.print();
	//chiamo funzione gioco
	//errore è true se si è presentato un errore, false altrimenti
	//bool errore = Gioco();
	//return (int) errore;
}
