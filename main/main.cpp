#include "../header/Gioco.hpp"

#define DIM 5
#define INFINITO 10000.f

bool InsidePoligono(Punto poligono[], int n, Punto P)
{
	Poligono pollo;
    //Ci devono essere almeno 3 vertici per il poligono
    if (n < 3)
        return false;
    //Crea un punto per fare il segmento da p a infinito
    Punto extreme = Punto(INFINITO, P.getY());
    //Conta le intersezioni della linea precedente con i lati del poligono
    int count = 0, current = 0;
    //iteratore, primo elemento esclusa la sentinella
    //struct Elem<Punto> *iter = this->surface.head();
    //Punto current = this->surface.read(iter);
    do
    {
        int next = (current+1)%n;
		/*
        if (iter != this->surface.tail())
        {
            iter = this->surface.next(iter);
        }
        else
        {
            iter = this->surface.head();
        }
        Punto next = this->surface.read(iter);
		*/
        //Controlla se le linee del segmento da P a infinito intersecano
        //con la linea del segmento da current a next
        if (pollo.doIntersect(poligono[current], poligono[next], P, extreme))
        {
            //Se il punto P è allineato con il segmento 'current-next'
            //Allora controlla se esso giace sul segmento.
            //Se ci giace, ritorna VERO, altrimenti FALSO.
            if (pollo.orientation(poligono[current], P, poligono[next]) == 0)
            {
                return pollo.onSegment(poligono[current], P, poligono[next]);
            }
            count++;
        }
        current = next;

	} while (current != 0);
	cout << "\ncount = " << count;
    //} while (iter != this->surface.head()); //prev != 0
    //Ritorna VERO se conta è dispari, altrimenti FALSO.
    return (count % 2 == 1);
}

int main()
{
	//chiamo funzione gioco
	//return Gioco();

	float x, y;
	char fine;
	Punto p;
	int n = DIM;
	Poligono pol;
	//si sa che non andrebbe fatto ma è un test...
	Punto poligonoVettore[DIM];

	do
	{
		cout << "\ninsert x of polygon:\t";
		cin >> x;
		cout << "insert y of polygon:\t";
		cin >> y;
		p.setCoord(x, y);
		p.print();
		//decremento
		n --;
		//inserisco nel vettore
		poligonoVettore[n] = p;
		//e nella lista
		pol.insert(p);
	} while (n > 0);

	cout << "\n\n";
	pol.print();

	//int n = pol.numPunti();
	n = DIM;
	do
	{
		cout << "\ninsert x :\t";
		cin >> x;
		cout << "insert y :\t";
		cin >> y;
		p.setCoord(x, y);
		p.print();
		cout << "\t";

		//è dentro il poligono per il vettore?
		cout << "\nVettore: ";
		InsidePoligono(poligonoVettore, n, p)? cout << "yes" : cout << "no";

		//è dentro il poligono per la lista?
		cout << "\t\tLista: ";
		pol.PointIsInside(p, n) ? cout << "yes" : cout << "no";
		cout << "\nfine? (y/n)\t";
		cin >> fine;
	} while (fine != 'y');

}
