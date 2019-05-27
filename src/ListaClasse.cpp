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
	cout << " : [ " << endl;
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
