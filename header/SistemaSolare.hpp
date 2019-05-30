//header sistema solare
#ifndef SISTEMA_SOLARE_HPP
#define SISTEMA_SOLARE_HPP

#include <ctime>
#include <cstdlib>

#include "./utils.hpp"
#include "./Pianeta.hpp"
#include "./Navicella.hpp"

template class ListaClasse<Pianeta>;

class SistemaSolare : public DisegnabileI
{
private:
    ListaClasse<Pianeta> pianeti;

public:
    //COSTRUTTORI
    //costruttore void
    SistemaSolare(void);
    //costruttori completi
    SistemaSolare(ListaClasse<Pianeta> listaPianeti);
    SistemaSolare(struct Elem<Pianeta> *headPianeti);
    //distruttore
    virtual ~SistemaSolare(void);

    //SETTERS
    //setta la lista
    void setListaPianeti(ListaClasse<Pianeta> listaPianeti);
    //setta il puntatore della lista
    void setHeadPianeti(struct Elem<Pianeta> *headPianeti);
    //GETTERS
    struct Elem<Pianeta> *getHeadPianeti(void);

    //stampa
    void print(void);
    void printCentri(void);
    //disegna
    void draw(sf::RenderWindow &window);
    //genera lista di pianeti
    void genera();
    //restituisce il puntatore al pianeta ricevendo la sua posizione nella lista
    Pianeta toPtrPlanet(struct Elem<Pianeta>* posizionePianeta);
    //controlla se la navicella è vicina a un pianeta nella lista
    struct Elem<Pianeta> *isNavicellaNearAPlanet(Navicella navicella);
};

#endif //SISTEMA_SOLARE_HPP