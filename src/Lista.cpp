//codice liste
#include <iostream>
using namespace std;

#include "../header/Lista.hpp"

//#define DEBUG
//uncomment this line to remove DEBUG printing

//costruttore e distruttore
template <typename Tipo>
Lista<Tipo>::Lista(void)
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
//
template <typename Tipo>
/*virtual*/ Lista<Tipo>::~Lista(void)
{
#ifdef DEBUG
	cout << "distruttore" << endl;
#endif
}

//setters
template <typename Tipo>
void Lista<Tipo>::setHead(struct Elem<Tipo> *head)
{
#ifdef DEBUG
	cout << "setta testa" << endl;
#endif
	this->testa = head;
}
template <typename Tipo>
struct Elem<Tipo> *Lista<Tipo>::getHead(void)
{
#ifdef DEBUG
	cout << "ottieni testa" << endl;
#endif
	return this->testa;
}

//metodi
template <typename Tipo>
bool Lista<Tipo>::empty(void)
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
struct Elem<Tipo> *Lista<Tipo>::head(void)
{
#ifdef DEBUG
	cout << "primo elemento in testa" << endl;
#endif
	return this->testa->next;
}
//
template <typename Tipo>
struct Elem<Tipo> *Lista<Tipo>::tail(void)
{
#ifdef DEBUG
	cout << "primo elemento in coda" << endl;
#endif
	return this->testa->prev;
}
//
template <typename Tipo>
struct Elem<Tipo> *Lista<Tipo>::next(struct Elem<Tipo> *p)
{
#ifdef DEBUG
	cout << "next" << endl;
#endif
	return p->next;
}
//
template <typename Tipo>
struct Elem<Tipo> *Lista<Tipo>::prev(struct Elem<Tipo> *p)
{
#ifdef DEBUG
	cout << "prev" << endl;
#endif
	return p->prev;
}
//
template <typename Tipo>
bool Lista<Tipo>::finished(struct Elem<Tipo> *p)
{
#ifdef DEBUG
	cout << "e' finita?" << endl;
#endif
	return (p == this->testa);
}
//
template <typename Tipo>
Tipo Lista<Tipo>::read(struct Elem<Tipo> *p)
{
#ifdef DEBUG
	cout << "leggi" << endl;
#endif
	return p->item;
}
//
template <typename Tipo>
struct Elem<Tipo> *Lista<Tipo>::write(struct Elem<Tipo> *p, Tipo v)
{
#ifdef DEBUG
	cout << "scrivi" << endl;
#endif
	p->item = v;
}
//
template <typename Tipo>
struct Elem<Tipo> *Lista<Tipo>::insert(struct Elem<Tipo> *p, Tipo v)
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
struct Elem<Tipo> *Lista<Tipo>::remove(struct Elem<Tipo> *p)
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

//inserisci in testa
template <typename Tipo>
void Lista<Tipo>::insert_head(Tipo v)
{
#ifdef DEBUG
	cout << "inserisci in testa" << endl;
#endif
	this->insert(this->head(), v);
}
//inserisci in coda
template <typename Tipo>
void Lista<Tipo>::insert_tail(Tipo v)
{
#ifdef DEBUG
	cout << "inserisci in coda" << endl;
#endif
	this->insert(this->tail(), v);
}
//rimuovi in testa
template <typename Tipo>
struct Elem<Tipo> *Lista<Tipo>::remove_head(void)
{
#ifdef DEBUG
	cout << "rimuovi in testa" << endl;
#endif
	this->remove(this->head());
}
//rimuovi in coda
template <typename Tipo>
struct Elem<Tipo> *Lista<Tipo>::remove_tail(void)
{
#ifdef DEBUG
	cout << "rimuovi in coda" << endl;
#endif
	this->remove(this->tail());
}

//cerca v scorrendo la lista
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
void Lista<Tipo>::print(void)
{
#ifdef DEBUG
	cout << "stampa lista" << endl;
#endif
	cout << "Lista : [ ";
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
