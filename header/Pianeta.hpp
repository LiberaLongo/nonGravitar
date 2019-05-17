//header pianeta
#ifndef PIANETA_H
#define PIANETA_H

#include "../header/DisegnabileI.hpp"
#include "../header/ListaClasse.hpp"
#include "../header/Punto.hpp"
#include "../header/Fuel.hpp"
#include "../header/Bunker.hpp"

template class ListaClasse<Punto>;
template class ListaClasse<Fuel>;
template class ListaClasse<Bunker>;

class Pianeta : public DisegnabileI
{
protected:
    Punto centro;
    float raggio = 50.f;
    ListaClasse<Punto> surface;
    ListaClasse<Fuel> fuel;
    ListaClasse<Bunker> bunker;
public:
    //COSTRUTTORI
    //costruttore void
    Pianeta(void);
    //costruttori punto
    Pianeta(Punto centro);
    Pianeta(float x, float y);
    //costruttori completi
    Pianeta(Punto centro, float raggio, ListaClasse<Punto> headSurface, ListaClasse<Fuel> headFuel, ListaClasse<Bunker> headBunker);
    Pianeta(float x, float y, float raggio, ListaClasse<Punto> headSurface, ListaClasse<Fuel> headFuel, ListaClasse<Bunker> headBunker);
    //distruttori
    /*virtual*/ ~Pianeta(void);
    //SETTERS
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);
    void setRaggio(float raggio);
    void setHeadSurface(ListaClasse<Punto> headSurface);
    void setHeadFuel(ListaClasse<Fuel> headFuel);
    void setHeadBunker(ListaClasse<Bunker> headBunker);
    //getters
    float getX(void);
    float getY(void);
    float getRaggio(void);
    struct Elem<Punto>* getHeadSurface(void);
    struct Elem<Fuel>* getHeadFuel(void);
    struct Elem<Bunker>* getHeadBunker(void);
    //stampa
    void print(void);
    //confronto
    bool confronto(Pianeta p);
    //disegna
    void draw(sf::RenderWindow &window);
    //generaPianeta(void);
    void generaPianeta(void);
    //altre cose

};
#endif