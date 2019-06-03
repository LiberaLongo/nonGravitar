//lista per le classi ereditata
//quindi non posso usare == o cout<<
//ma devo usare contronto() e print()

#include "../header/ListaClasse.hpp"

//#define DEBUG
//uncomment this line to remove DEBUG printing

//costruttore e distruttore
template <typename Tipo>
ListaClasse<Tipo>::ListaClasse(void) : Lista<Tipo>()
{
}
//
template <typename Tipo>
/*virtual*/ ListaClasse<Tipo>::~ListaClasse(void)
{
#ifdef DEBUG
	cout << "distruttore" << endl;
#endif
}

//cerca v scorrendo la lista
//override
template <typename Tipo>
struct Elem<Tipo> *ListaClasse<Tipo>::search(Tipo v)
{
#ifdef DEBUG
	cout << "cerca " << v << endl;
#endif
	struct Elem<Tipo> *find = nullptr;
	if (!(this->empty()))
	{
		struct Elem<Tipo> *iter = this->head();
		bool trovato = false;
		//se non finita, oppure lo hai trovato
		while (!(this->finished(iter)) || !trovato)
		{
			//se lo trovi
			if (v.confronto(this->read(iter))) //MODIFICATA!
			{
				find = iter;
				trovato = true;
			}
			iter = this->next(iter);
		}
	}
	return find;
}

//stampe
//override
template <typename Tipo>
void ListaClasse<Tipo>::print(void)
{
#ifdef DEBUG
	cout << "stampa lista" << endl;
#endif
	cout << " : [ ";
	if (!(this->empty()))
	{
		//primo elemento utile non la sentinella
		struct Elem<Tipo> *iter = this->head();
		//se non vuota e non finita
		while (!(this->finished(iter)))
		{
			//stampo elemento MODIFICATA!
			Tipo stampato = this->read(iter);
			stampato.print();
			//passo al successivo e stampo freccia
			iter = this->next(iter);
			if (!(this->finished(iter)))
				cout << " --> ";
		}
	}
	cout << " ]" << endl;
}
//disegna elementi
template <typename Tipo>
void ListaClasse<Tipo>::draw(sf::RenderWindow &window)
{
	if (!(this->empty()))
	{
		//primo elemento utile non la sentinella
		struct Elem<Tipo> *iter = this->head();
		//se non vuota e non finita
		while (!(this->finished(iter)))
		{
			//stampo elemento MODIFICATA!
			Tipo disegnato = this->read(iter);
			disegnato.draw(window);
			//passo al successivo
			iter = this->next(iter);
		}
	}
}

//metodi di ordinamento

//libro di algoritmi: pag 29/30.
//ATTENZIONE! il libro non ha il vettore delle posizioni da aggiornare!
template <typename Tipo>
void ListaClasse<Tipo>::Merge(float A[], int primo, int ultimo, int mezzo, struct Elem<Tipo> *posizioni[], float B[], struct Elem<Tipo> *posAux[])
{
	int i = primo, j = mezzo + 1, k = primo, h;
	//while i <= mezzo and j <= ultimo do
	while ((i <= mezzo) && (j <= ultimo))
	{
		if (A[i] <= A[j])
		{
			B[k] = A[i];
			//aggiorno il vettore dei puntatori
			posAux[k] = posizioni[i];
			//
			i = i + 1;
		}
		else
		{
			B[k] = A[j];
			//aggiorno il vettore dei puntatori
			posAux[k] = posizioni[j];
			//
			j = j + 1;
		}
		k = k + 1;
	}
	j = ultimo;
	//for h <-- mezzo downto i do
	for (h = mezzo; h >= i; h--)
	{
		A[j] = A[h];
		//aggiorno il vettore dei puntatori
		posizioni[j] = posizioni[h];
		//
		j = j - 1;
	}
	//for j <-- primo to k-1 do
	for (j = primo; j <= (k - 1); j++)
	{
		A[j] = B[j];
		//aggiorno il vettore dei puntatori
		posizioni[j] = posAux[j];
		//
	}
}
template <typename Tipo>
void ListaClasse<Tipo>::MergeSort(float A[], int primo, int ultimo, struct Elem<Tipo> *posizioni[], float B[], struct Elem<Tipo> *posAux[])
{
	if (primo < ultimo)
	{
		//integer mezzo <-- base[(primo + ultimo)/2]
		int mezzo = floor((primo + ultimo) / 2);
		this->MergeSort(A, primo, mezzo, posizioni, B, posAux);
		this->MergeSort(A, mezzo + 1, ultimo, posizioni, B, posAux);
		this->Merge(A, primo, ultimo, mezzo, posizioni, B, posAux);
	}
}