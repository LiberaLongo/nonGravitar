//codice liste
#include <iostream>
using namespace std;

#include "./Lista.hpp"

//costruttore e distruttore
template <typename Tipo>
Lista<Tipo>::Lista(void)
{
    struct Elem sentinella;
    sentinella.prev = sentinella;
    sentinella.next = sentinella;
    //sentinella.item non ci interessa
    this.head = &sentinella;
}

template <typename Tipo>
virtual Lista<Tipo>::~Lista(void)
{
}

//setters
template <typename Tipo>
void Lista<Tipo>::setHead(struct Elem *head)
{
    this.head = head;
}
template <typename Tipo>
struct Elem *Lista<Tipo>::getHead(void)
{
    return this.head;
}
//metodi
template <typename Tipo>
bool Lista<Tipo>::empty(void)
{
    return (this.head->next == this.head->prev == this.head);
}
template <typename Tipo>
struct Elem *Lista<Tipo>::head(void)
{
    return this.head->next;
}
template <typename Tipo>
struct Elem *Lista<Tipo>::tail(void)
{
    return this.head->prev;
}
template <typename Tipo>
struct Elem *Lista<Tipo>::next(struct Elem *p)
{
    return p->next;
}
template <typename Tipo>
struct Elem *Lista<Tipo>::prev(struct Elem *p)
{
    return p->prev;
}
template <typename Tipo>
bool Lista<Tipo>::finished(struct Elem *p)
{
    return (p == this.head);
}
template <typename Tipo>
Tipo Lista<Tipo>::read(struct Elem *p)
{
    return p->value;
}
template <typename Tipo>
struct Elem *Lista<Tipo>::write(struct Elem *p, Tipo v)
{
    p->value = v;
}
template <typename Tipo>
struct Elem *Lista<Tipo>::insert(struct Elem *p, Tipo v)
{
    struct Elem *inserito;
    inserito->value = v;
    inserito->prev = p->prev;
    inserito->prev->next = inserito;
    inserito->next = p;
    p->prev = inserito;
    return inserito;
}
template <typename Tipo>
struct Elem *Lista<Tipo>::remove(struct Elem *p)
{
    p->prev->next = p->next;
    p->next->prev = p->prev;
    struct Elem *temp = p->next;
    delete p;
    return temp;
}

//metodi ausiliari

//cerca v scorrendo la lista
template <typename Tipo>
struct Elem *Lista<Tipo>::search(Tipo v)
{
    struct Elem *iter = this.head();
    bool trovato = false;
    struct Elem *find = NULL;
    //se non vuota e non finita, oppure lo hai trovato
    while (!(this.empty() && this.finished(iter)) || trovato)
    {
        //se lo trovi
        if (this.read(iter) == v)
        {
            find = iter;
            trovato = true;
        }
        iter = this.next(iter);
    }
    return find;
}
//inserisci in testa
template <typename Tipo>
void Lista<Tipo>::insert_head(Tipo v)
{
    this.insert(this.head(), v);
}
//inserisci in coda
template <typename Tipo>
void Lista<Tipo>::insert_tail(Tipo v)
{
    this.insert(this.tail(), v);
}
//rimuovi in testa
template <typename Tipo>
struct Elem *Lista<Tipo>::remove_head(void)
{
    this.remove(this.head());
}
//rimuovi in coda
template <typename Tipo>
struct Elem *Lista<Tipo>::remove_tail(void)
{
    this.remove(this.tail());
}

//stampe
template <typename Tipo>
void Lista<Tipo>::printElem(struct Elem *p)
{
    cout << (char)this.read(p);
}
template <typename Tipo>
void Lista<Tipo>::printList(void)
{
    //primo elemento utile non la sentinella
    struct Elem *iter = this.head();
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
