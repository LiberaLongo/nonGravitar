//lista per le classi ereditata
#ifndef LISTA_CLASSE_H
#define LISTA_CLASSE_H

#include <SFML/Graphics.hpp>
#include "./Lista.hpp"

template <typename Tipo>
class ListaClasse : public Lista<Tipo> {
public:
	//costruttore e distruttore
	ListaClasse(void);
	virtual ~ListaClasse(void);

    //cerca v scorrendo la lista
    //override
	struct Elem<Tipo>* search(Tipo v);

	//stampe
    //override
	void print(void);
	
	//disegna elementi
	void draw(sf::RenderWindow &window);

	//metodi di ordinamento
	void Merge(int primo, int ultimo, int mezzo, float A[], float B[], struct Elem<Tipo> *posizioni[], struct Elem<Tipo> *posAux[]);
	void MergeSort(int primo, int ultimo, float A[], float B[], struct Elem<Tipo> *posizioni[], struct Elem<Tipo> *posAux[]);
	void ordina(const int dim, float A[], float B[], struct Elem<Tipo> *posizioni[], struct Elem<Tipo> *posAux[]);
};
#endif //LISTA_CLASSE_H