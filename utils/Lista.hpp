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

//lista bidirezionale, circolare, con sentinella
template <class Tipo>
class Lista
{
private:
    struct Elem* head;
public:
    //costruttore e distruttore
    Lista(void);
    virtual ~Lista(void);

    //setters
    void setHead(struct Elem* head);
    struct Elem* getHead(void);

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
};

#endif //LISTA_H
