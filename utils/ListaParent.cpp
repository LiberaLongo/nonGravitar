//codice liste

#include "../header/ListaParent.hpp"

//#define DEBUG
//uncomment this line to remove DEBUG printing

//costruttore e distruttore
template <typename Tipo>
ListaParent<Tipo>::ListaParent(void)
{
#ifdef DEBUG
	cout << "costruttore" << endl;
#endif
	struct Elem<Tipo> *sentinella = new Elem<Tipo>;
	sentinella->prev = sentinella;
	sentinella->next = sentinella;
	//sentinella.item non ci interessa
	this->testa = sentinella;
}

//setters
template <typename Tipo>
void ListaParent<Tipo>::setHead(struct Elem<Tipo> *head)
{
#ifdef DEBUG
	cout << "setta testa" << endl;
#endif
	this->testa = head;
}
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::getHead(void)
{
#ifdef DEBUG
	cout << "ottieni testa" << endl;
#endif
	return this->testa;
}

//metodi
template <typename Tipo>
bool ListaParent<Tipo>::empty(void)
{
#ifdef DEBUG
	cout << "e' vuota?" << endl;
#endif
	if (this->testa->next != this->testa->prev)
		return false;
	if (this->testa->next != this->testa)
		return false;
	return true;
}
//
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::head(void)
{
#ifdef DEBUG
	cout << "primo elemento in testa" << endl;
#endif
	return this->testa->next;
}
//
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::tail(void)
{
#ifdef DEBUG
	cout << "primo elemento in coda" << endl;
#endif
	return this->testa->prev;
}
//
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::next(struct Elem<Tipo> *p)
{
#ifdef DEBUG
	cout << "next" << endl;
#endif
	return p->next;
}
//
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::prev(struct Elem<Tipo> *p)
{
#ifdef DEBUG
	cout << "prev" << endl;
#endif
	return p->prev;
}
//
template <typename Tipo>
bool ListaParent<Tipo>::finished(struct Elem<Tipo> *p)
{
#ifdef DEBUG
	cout << "e' finita?" << endl;
#endif
	return (p == this->testa);
}
//
template <typename Tipo>
Tipo ListaParent<Tipo>::read(struct Elem<Tipo> *p)
{
#ifdef DEBUG
	cout << "leggi" << endl;
#endif
	return p->item;
}
//
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::write(struct Elem<Tipo> *p, Tipo v)
{
#ifdef DEBUG
	cout << "scrivi" << endl;
#endif
	p->item = v;
}
//
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::insert(struct Elem<Tipo> *p, Tipo v)
{
#ifdef DEBUG
	cout << "inserisci" << endl;
#endif
	struct Elem<Tipo> *inserito = new Elem<Tipo>;
	inserito->item = v;
	inserito->prev = p->prev;
	inserito->prev->next = inserito;
	inserito->next = p;
	p->prev = inserito;
	return inserito;
}
//
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::remove(struct Elem<Tipo> *p)
{
#ifdef DEBUG
	cout << "rimuovi" << endl;
#endif
	p->prev->next = p->next;
	p->next->prev = p->prev;
	struct Elem<Tipo> *temp = p->next;
	delete p;
	return temp;
}

//metodi ausiliari
//calcola la lunghezza della ListaParent (e serve per non fare errori)
template <typename Tipo>
int ListaParent<Tipo>::lunghezza(void)
{
	//conta il numero di elementi
	int conta = 0;
	if (!(this->empty()))
	{
		//primo elemento utile non la sentinella
		struct Elem<Tipo> *iter = this->head();
		//se non vuota e non finita
		while (!(this->finished(iter)))
		{
			//incremento la conta
			conta++;
			//passo al successivo
			iter = this->next(iter);
		}
	}
	return conta;
}
//inserisci in testa
template <typename Tipo>
void ListaParent<Tipo>::insert_head(Tipo v)
{
#ifdef DEBUG
	cout << "inserisci in testa" << endl;
#endif
	this->insert(this->head(), v);
}
//inserisci in coda
template <typename Tipo>
void ListaParent<Tipo>::insert_tail(Tipo v)
{
#ifdef DEBUG
	cout << "inserisci in coda" << endl;
#endif
	this->insert(this->tail(), v);
}
//rimuovi in testa
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::remove_head(void)
{
#ifdef DEBUG
	cout << "rimuovi in testa" << endl;
#endif
	this->remove(this->head());
}
//rimuovi in coda
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::remove_tail(void)
{
#ifdef DEBUG
	cout << "rimuovi in coda" << endl;
#endif
	this->remove(this->tail());
}

//cerca v scorrendo la ListaParent
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::search(Tipo v)
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
			if (this->read(iter) == v)
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
template <typename Tipo>
void ListaParent<Tipo>::print(void)
{
#ifdef DEBUG
	cout << "stampa ListaParent" << endl;
#endif
	cout << "ListaParent : [ ";
	if (!(this->empty()))
	{
		//primo elemento utile non la sentinella
		struct Elem<Tipo> *iter = this->head();
		//se non vuota e non finita
		while (!(this->finished(iter)))
		{
			//stampo elemento
			cout << this->read(iter);
			//passo al successivo e stampo freccia
			iter = this->next(iter);
			if (!(this->finished(iter)))
				cout << " --> ";
		}
	}
	cout << " ]" << endl;
}

/*
Nota1: funzioni ispirate al libro algorazmi (lol)
Nota2: NON sappiamo giocare con i puntatori
Nota3: deferenziare?
*/
