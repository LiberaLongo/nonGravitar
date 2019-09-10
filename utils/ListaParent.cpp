#include "../header/ListaParent.hpp"

//costruttore e distruttore
template <typename Tipo>
ListaParent<Tipo>::ListaParent(void)
{
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
	this->testa = head;
}
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::getHead(void)
{
	return this->testa;
}

//metodi
template <typename Tipo>
bool ListaParent<Tipo>::empty(void)
{
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
	return this->testa->next;
}
//
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::tail(void)
{
	return this->testa->prev;
}
//
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::next(struct Elem<Tipo> *p)
{
	return p->next;
}
//
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::prev(struct Elem<Tipo> *p)
{
	return p->prev;
}
//
template <typename Tipo>
bool ListaParent<Tipo>::finished(struct Elem<Tipo> *p)
{
	return (p == this->testa);
}
//
template <typename Tipo>
Tipo ListaParent<Tipo>::read(struct Elem<Tipo> *p)
{
	return p->item;
}
//
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::write(struct Elem<Tipo> *p, Tipo v)
{
	p->item = v;
}
//
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::insert(struct Elem<Tipo> *p, Tipo v)
{
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
	this->insert(this->head(), v);
}
//inserisci in coda
template <typename Tipo>
void ListaParent<Tipo>::insert_tail(Tipo v)
{
	this->insert(this->next(this->tail()), v);
}
//rimuovi in testa
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::remove_head(void)
{
	this->remove(this->head());
}
//rimuovi in coda
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::remove_tail(void)
{
	this->remove(this->tail());
}

//cerca v scorrendo la ListaParent
template <typename Tipo>
struct Elem<Tipo> *ListaParent<Tipo>::search(Tipo v)
{
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
