//header pianeta
#ifndef PIANETA_H
#define PIANETA_H

#include "./DisegnabileI.hpp"
#include "./Punto.hpp"
#include "./Fuel.hpp"
#include "./ColoreRGB.hpp"

#include "./ListaClasse.hpp"

//ATTENZIONE! cpp sono qui inclusi per classi template
#include "./Bunker.hpp"

template class ListaClasse<Punto>;
template class ListaClasse<Fuel>;
template class ListaClasse<Bunker>;

class Pianeta : public DisegnabileI
{
protected:
    Punto centro;
    float raggio = PIANETA_RAGGIO;
    ListaClasse<Punto> surface;
    ListaClasse<Fuel> fuel;
    ListaClasse<Bunker> bunker;
    //cose grafiche e basta
    ColoreRGB colore;
    ColoreRGB outline;

public:
    //COSTRUTTORI
    //costruttore void
    Pianeta(void);
    //costruttori punto
    Pianeta(Punto centro);
    Pianeta(float x, float y);
    //costruttori punto e colore
    Pianeta(Punto centro, ColoreRGB colore);
    Pianeta(float x, float y, int red, int green, int blue);
    //costruttori punto e colore
    Pianeta(Punto centro, ColoreRGB colore, ColoreRGB outline);
    Pianeta(float x, float y, int red, int green, int blue, int red_o, int green_o, int blue_o);
    //costruttori completi
    Pianeta(Punto centro, float raggio, ColoreRGB colore, ColoreRGB outline, ListaClasse<Punto> listaSurface, ListaClasse<Fuel> listaFuel, ListaClasse<Bunker> listaBunker);
    Pianeta(float x, float y, float raggio, int red, int green, int blue, int red_o, int green_o, int blue_o, ListaClasse<Punto> listaSurface, ListaClasse<Fuel> listaFuel, ListaClasse<Bunker> listaBunker);
    //distruttore
    /*virtual*/ ~Pianeta(void);

    //SETTERS
    //cose importanti
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);
    void setRaggio(float raggio);
    //colori
    void setColore(ColoreRGB colore);
    void setColore(int red, int green, int blue);
    void setOutline(ColoreRGB outline);
    void setOutline(int red, int green, int blue);
    //setta la lista
    void setSurface(ListaClasse<Punto> listaSurface);
    void setFuel(ListaClasse<Fuel> listaFuel);
    void setBunker(ListaClasse<Bunker> listaBunker);
    //setta il puntatore della lista
    void setHeadSurface(struct Elem<Punto> *headSurface);
    void setHeadFuel(struct Elem<Fuel> *headFuel);
    void setHeadBunker(struct Elem<Bunker> *headBunker);

    //GETTERS
    float getX(void);
    float getY(void);
    float getRaggio(void);
    //colori
    sf::Color getColore(void);
    sf::Color getOutline(void);
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
    //genera Pianeta
    void genera(void);
    //altre cose
};
#endif