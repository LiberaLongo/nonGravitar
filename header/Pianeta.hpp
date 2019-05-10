//header pianeta
#ifndef PIANETA_H
#define PIANETA_H

#include "../header/ListaClasse.hpp"
#include "../header/Punto.hpp"

class Pianeta
{
protected:
    Punto centro;
    float circonferenza = 50.f;
    ListaClasse<Punto> surface;
    //ListaClasse<Fuel> fuel;
    //ListaClasse<Bunker> bunker;
public:
    //COSTRUTTORI
    //costruttore void
    Pianeta(void);
    //costruttori punto
    Pianeta(Punto centro);
    Pianeta(float x, float y);
    //costruttori completi
    Pianeta(Punto centro, float circonferenza, ListaClasse<Punto> headSurface/* ListaClasse<Fuel> headFuel, ListaClasse<Bunker> headBunker*/);
    Pianeta(float x, float y, float circonferenza, ListaClasse<Punto> headSurface/* ListaClasse<Fuel> headFuel, ListaClasse<Bunker> headBunker*/);
    //distruttori
    //SETTERS
    //getters
    //stampa
    //disegna
    //disegna(void);
    //altre cose
    //generaPianeta(void);

};
#endif