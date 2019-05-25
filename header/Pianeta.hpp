//header pianeta
#ifndef PIANETA_H
#define PIANETA_H

#include "../header/DisegnabileI.hpp"
#include "../header/Punto.hpp"
#include "../header/Fuel.hpp"

#include "../header/ListaClasse.hpp"

//ATTENZIONE! cpp sono qui inclusi per classi template
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
    //cose grafiche e basta
    //coloreRGB colore;

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
    //setta la lista
    void setSurface(ListaClasse<Punto> headSurface);
    void setFuel(ListaClasse<Fuel> headFuel);
    void setBunker(ListaClasse<Bunker> headBunker);
    //setta il puntatore della lista
    void setHeadSurface(struct Elem<Punto> *headSurface);
    void setHeadFuel(struct Elem<Fuel> *headFuel);
    void setHeadBunker(struct Elem<Bunker> *headBunker);
    //getters
    float getX(void);
    float getY(void);
    float getRaggio(void);
    //ottengo il puntatore alla testa, non al primo elemento
    struct Elem<Punto> *getHeadSurface(void);
    struct Elem<Fuel> *getHeadFuel(void);
    struct Elem<Bunker> *getHeadBunker(void);
    //stampa
    void print(void);
    //confronto
    bool confronto(Pianeta p);
    //disegna
    void draw(sf::RenderWindow &window);
    void drawVisuale(sf::RenderWindow &window);
    //generaPianeta(void);
    void generaPianeta(void);
    //altre cose
};
#endif