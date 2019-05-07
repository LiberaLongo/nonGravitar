//lista per le classi ereditata
#ifndef LISTA_CLASSE_H
#define LISTA_CLASSE_H

#include "./Lista.hpp"

template <typename Tipo>
class ListaClasse : public Lista<Tipo> {
public:
	//costruttore e distruttore
	ListaClasse(void);
	/*virtual*/ ~ListaClasse(void);

    //cerca v scorrendo la lista
    //override
	struct Elem<Tipo>* search(Tipo v);

	//stampe
    //override
	void print(void);
};
#endif //LISTA_CLASSE_H