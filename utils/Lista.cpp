//lista per le classi ereditata
//quindi non posso usare == o cout<<
//ma devo usare contronto() e print()

#include "../header/Lista.hpp"

//#define DEBUG
//uncomment this line to remove DEBUG printing

//costruttore e distruttore
template <typename Tipo>
Lista<Tipo>::Lista(void) : ListaParent<Tipo>()
{
}

//cerca v scorrendo la lista
//override
template <typename Tipo>
struct Elem<Tipo> *Lista<Tipo>::search(Tipo v)
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
void Lista<Tipo>::print(void)
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
void Lista<Tipo>::draw(sf::RenderWindow &window)
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
void Lista<Tipo>::Merge(int primo, int ultimo, int mezzo, float A[], float B[], struct Elem<Tipo> *posizioni[], struct Elem<Tipo> *posAux[])
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
void Lista<Tipo>::MergeSort(int primo, int ultimo, float A[], float B[], struct Elem<Tipo> *posizioni[], struct Elem<Tipo> *posAux[])
{
	if (primo < ultimo)
	{
		//integer mezzo <-- base[(primo + ultimo)/2]
		int mezzo = floor((primo + ultimo) / 2);
		this->MergeSort(primo, mezzo, A, B, posizioni, posAux);
		this->MergeSort(mezzo + 1, ultimo, A, B, posizioni, posAux);
		this->Merge(primo, ultimo, mezzo, A, B, posizioni, posAux);
	}
}
template <typename Tipo>
void Lista<Tipo>::ordina(const int dim, float A[], float B[], struct Elem<Tipo> *posizioni[], struct Elem<Tipo> *posAux[])
{
    this->MergeSort(0, dim - 1, A, B, posizioni, posAux);
    //ricostruisci la lista della superfice ordinata
    Lista<Tipo> ordinata;
    for (int i = 0; i < dim; i++)
    {
        ordinata.insert_head(this->read(posizioni[i]));
        //NB: uso insert_head per ordinarli dal più grande al più piccolo, in senso orario
        //uso insert_tail per ordinarli dal più piccolo al più grande, in senso anti-orario
    }
    this->setHead(ordinata.getHead());
}
