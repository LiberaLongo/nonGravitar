//header sistema solare
#ifndef SISTEMA_SOLARE_HPP
#define SISTEMA_SOLARE_HPP

#include <ctime>
#include <cstdlib>

#include "./utils.hpp"
#include "./Pianeta.hpp"
#include "./Navicella.hpp"

//ATTENZIONE! cpp inclusi per classi template
#include "./includeTemplate.hpp"

template class Lista<Pianeta>;

class SistemaSolare : public DisegnabileI
{
private:
    Lista<Pianeta> pianeti;

public:
    //costruttore vuoto
    SistemaSolare(void);

    //distruttore
    virtual ~SistemaSolare(void) {};

    //SETTERS
    //setta la lista
    void setListaPianeti(Lista<Pianeta> listaPianeti);
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

    //elimina il pianeta dalla lista
    void eliminaPianeta(struct Elem<Pianeta>* pianetaEliminato);
    //restituisce true se la sua lista è vuota
    bool emptyPianeti(void);

    //restituisce il puntatore al pianeta ricevendo la sua posizione nella lista
    Pianeta toPtrPlanet(struct Elem<Pianeta>* posizionePianeta);
    //controlla se la navicella è vicina a un pianeta nella lista
    struct Elem<Pianeta> *isNavicellaNearAPlanet(Navicella navicella);

};

#endif //SISTEMA_SOLARE_HPP
