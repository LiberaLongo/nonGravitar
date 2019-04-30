//header liste
#ifndef LISTA_H
#define LISTA_H

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
    struct Elem* head(void);
    struct Elem* tail(void);
    struct Elem* next(struct Elem* p);
    struct Elem* prev(struct Elem* p);
    bool finished(struct Elem* p);
    Tipo read(struct Elem* p);
    struct Elem* write(struct Elem* p, Tipo v);
    struct Elem* insert(struct Elem* p, Tipo v);
    struct Elem* remove(struct Elem* p);

    //metodi ausiliari

    //cerca v scorrendo la lista
    struct Elem* search(Tipo v);
    //inserisci in testa
    void insert_head(Tipo v);
    //inserisci in coda
    void insert_tail(Tipo v);
    //rimuovi in testa
    struct Elem* remove_head(void);
    //rimuovi in coda
    struct Elem* remove_tail(void);

    //stampe
    void printElem(struct Elem* p);
    void printList(void);
};

#endif //LISTA_H
