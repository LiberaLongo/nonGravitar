//codice liste
#include <iostream>
using namespace std;

#include "./Lista.hpp"

//costruttore e distruttore
template <class Tipo>
Lista<Tipo>::Lista(void)
{
    struct Elem sentinella;
    sentinella.prev = sentinella;
    sentinella.next = sentinella;
    //sentinella.item non ci interessa
    this.head = &sentinella;
}

template <class Tipo>
virtual Lista<Tipo>::~Lista(void)
{
}

//setters
template <class Tipo>
void Lista<Tipo>::setHead(typeHead head)
{
    this.head = head;
}
template <class Tipo>
typeHead Lista<Tipo>::getHead(void)
{
    return this.head;
}
//metodi
template <class Tipo>
bool Lista<Tipo>::empty(void)
{
    return (this.head->next == this.head->prev == this.head);
}
template <class Tipo>
pos Lista<Tipo>::head(void)
{
    return this.head->next;
}
template <class Tipo>
pos Lista<Tipo>::tail(void)
{
    return this.head->prev;
}
template <class Tipo>
pos Lista<Tipo>::next(pos p)
{
    return p->next;
}
template <class Tipo>
pos Lista<Tipo>::prev(pos p)
{
    return p->prev;
}
template <class Tipo>
bool Lista<Tipo>::finished(pos p)
{
    return (p == this.head);
}
template <class Tipo>
Tipo Lista<Tipo>::read(pos p)
{
    return p->value;
}
template <class Tipo>
pos Lista<Tipo>::write(pos p, Tipo v)
{
    p->value = v;
}
template <class Tipo>
pos Lista<Tipo>::insert(pos p, Tipo v)
{
    pos inserito;
    inserito->value = v;
    inserito->prev = p->prev;
    inserito->prev->next = inserito;
    inserito->next = p;
    p->prev = inserito;
    return inserito;
}
template <class Tipo>
pos Lista<Tipo>::remove(pos p)
{
    p->prev->next = p->next;
    p->next->prev = p->prev;
    pos temp = p->next;
    delete p;
    return temp;
}

//metodi ausiliari

//cerca v scorrendo la lista
template <class Tipo>
pos Lista<Tipo>::search(Tipo v) {

}
//inserisci in testa
template <class Tipo>
void Lista<Tipo>::insert_head(Tipo v) {

}
//inserisci in coda
template <class Tipo>
void Lista<Tipo>::insert_tail(Tipo v){

}
//rimuovi in testa
template <class Tipo>
typeHead Lista<Tipo>::remove_head(void){

}
//rimuovi in coda
template <class Tipo>
typeHead Lista<Tipo>::remove_tail(void){
    
}

//stampe
void printElem(pos p)
{
    cout << (char)this.read(p);
}
void printList(void)
{
    //primo elemento utile non la sentinella
    pos iter = this.head();
    //se non vuota e non finita
    while (!(this.empty() && this.finished(iter)))
    {
        printElem(iter);
        iter = this.next(iter);
    }
}

/*
Nota1: funzioni ispirate al libro algorazmi (lol)
Nota2: NON sappiamo giocare con i puntatori
Nota3: deferenziare?
*/
