//header liste
#ifndef LISTA_PARENT_H
#define LISTA_PARENT_H

#include "./utils.hpp"

template <typename Tipo>
struct Elem
{
	struct Elem<Tipo>* prev;
	struct Elem<Tipo>* next;
	Tipo item;
};

/*volevamo definire struct Elem* come pos e typeHead
ma non è facilmente disponibile typedef template
bisogna fare cose difficilmente comprensibili*/

template <typename Tipo>
class ListaParent
{
private:
	struct Elem<Tipo>* testa;
public:
	//costruttore e distruttore
	ListaParent(void);
	virtual ~ListaParent(void);

	//setters
	void setHead(struct Elem<Tipo>* head);
	struct Elem<Tipo>* getHead(void);

	//metodi
	bool empty(void);
	struct Elem<Tipo>* head(void);
	struct Elem<Tipo>* tail(void);
	struct Elem<Tipo>* next(struct Elem<Tipo>* p);
	struct Elem<Tipo>* prev(struct Elem<Tipo>* p);
	bool finished(struct Elem<Tipo>* p);
	Tipo read(struct Elem<Tipo>* p);
	struct Elem<Tipo>* write(struct Elem<Tipo>* p, Tipo v);
	struct Elem<Tipo>* insert(struct Elem<Tipo>* p, Tipo v);
	struct Elem<Tipo>* remove(struct Elem<Tipo>* p);

	//metodi ausiliari
	//calcola la lunghezza della ListaParent (e serve per non fare errori)
	int lunghezza(void);
	//inserisci in testa
	void insert_head(Tipo v);
	//inserisci in coda
	void insert_tail(Tipo v);
	//rimuovi in testa
	struct Elem<Tipo>* remove_head(void);
	//rimuovi in coda
	struct Elem<Tipo>* remove_tail(void);

	//cerca v scorrendo la ListaParent
	struct Elem<Tipo>* search(Tipo v);

	//stampe
	void print(void);
};

#endif //ListaParent_H
