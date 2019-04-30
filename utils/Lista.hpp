//header liste
#ifndef LISTA_H
#define LISTA_H


template <class Tipo>
struct Elem
{
    struct Elem* prev;
    struct Elem* next;
    Tipo item;
};

typedef struct Elem* pos;
typedef struct Elem* typeHead;

//lista bidirezionale, circolare, con sentinella
template <class Tipo>
class Lista
{
private:
    typeHead head;
public:
    //costruttore e distruttore
    Lista(void);
    virtual ~Lista(void);

    //setters
    void setHead(typeHead head);
    typeHead getHead(void);

    //metodi
    bool empty(void);
    pos head(void);
    pos tail(void);
    pos next(pos p);
    pos prev(pos p);
    bool finished(pos p);
    Tipo read(pos p);
    pos write(pos p, Tipo v);
    pos insert(pos p, Tipo v);
    pos remove(pos p);

    //metodi ausiliari

    //cerca v scorrendo la lista
    pos search(Tipo v);
    //inserisci in testa
    void insert_head(Tipo v);
    //inserisci in coda
    void insert_tail(Tipo v);
    //rimuovi in testa
    typeHead remove_head(void);
    //rimuovi in coda
    typeHead remove_tail(void);

    //stampe
    void printElem(pos p);
    void printList(void);
};

#endif //LISTA_H
