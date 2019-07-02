//lista per le classi ereditata
#ifndef LISTA_H
#define LISTA_H

#include <SFML/Graphics.hpp>
#include "./ListaParent.hpp"

template <typename Tipo>
class Lista : public ListaParent<Tipo> {
public:
	//costruttore e distruttore
	Lista(void);
	virtual ~Lista(void) {};

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
#endif //LISTA_H