//codice liste
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
void Lista<Tipo>::setHead(struct Elem* head)
{
    this.head = head;
}
template <class Tipo>
struct Elem* Lista<Tipo>::getHead(void)
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
    struct Elem* inserito;
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
    struct Elem* temp = p->next;
    delete p;
    return temp;
}

/*
Nota1: funzioni ispirate al libro algorazmi (lol)
Nota2: NON sappiamo giocare con i puntatori
Nota3: deferenziare?
*/
