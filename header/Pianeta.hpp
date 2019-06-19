//header pianeta
#ifndef PIANETA_H
#define PIANETA_H

#include "./DisegnabileI.hpp"
#include "./Punto.hpp"
#include "./Fuel.hpp"
#include "./ColoreRGB.hpp"

#include "./Lista.hpp"

//ATTENZIONE! cpp sono qui inclusi per classi template
#include "./Bunker.hpp"


template class Lista<Punto>;
template class Lista<Fuel>;
template class Lista<Bunker>;

class Pianeta : public DisegnabileI
{
private:
    Punto centro;
    float raggio = PIANETA_RAGGIO;
    Lista<Punto> surface;
    Lista<Fuel> fuel;
    Lista<Bunker> bunker;
    //cose grafiche e basta
    ColoreRGB colore;
    ColoreRGB atmosfera;
public:
    //COSTRUTTORI
    //costruttore void
    Pianeta(void);
    //costruttori punto e raggio
    Pianeta(Punto centro, float raggio);
    Pianeta(float x, float y, float raggio);
    //costruttori completi
    Pianeta(Punto centro, float raggio, ColoreRGB colore, ColoreRGB outline, Lista<Punto> listaSurface, Lista<Fuel> listaFuel, Lista<Bunker> listaBunker);
    Pianeta(float x, float y, float raggio, ColoreRGB colore, ColoreRGB outline, Lista<Punto> listaSurface, Lista<Fuel> listaFuel, Lista<Bunker> listaBunker);
    //distruttore
    virtual ~Pianeta(void);

    //SETTERS
    //cose importanti
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);
    void setRaggio(float raggio);
    //colori
    void setColore(ColoreRGB colore);
    void setColore(int red, int green, int blue);
    void setAtmosfera(ColoreRGB outline);
    void setAtmosfera(int red, int green, int blue);
    //setta la lista
    void setSurface(Lista<Punto> listaSurface);
    void setFuel(Lista<Fuel> listaFuel);
    void setBunker(Lista<Bunker> listaBunker);
    //setta il puntatore della lista
    void setHeadSurface(struct Elem<Punto> *headSurface);
    void setHeadFuel(struct Elem<Fuel> *headFuel);
    void setHeadBunker(struct Elem<Bunker> *headBunker);

    //GETTERS
    float getX(void);
    float getY(void);
    float getRaggio(void);
    //colori
    sf::Color getColoreLib(void);
    sf::Color getAtmosferaLib(void);
    //ottengo il puntatore alla testa, non al primo elemento
    struct Elem<Punto> *getHeadSurface(void);
    struct Elem<Fuel> *getHeadFuel(void);
    struct Elem<Bunker> *getHeadBunker(void);

    //conta i punti della superficie
    int lunghezzaSuperfice(void);
    
    //stampa
    void print(void);

    //confronto
    bool confronto(Pianeta p);

    //disegna
    void draw(sf::RenderWindow &window);
    void drawVisuale(sf::RenderWindow &window, int length);

    //genera Pianeta
    void genera(void);

    //ordina la lista dei punti del pianeta...
    void ordinaPunti(void);

    //aggiorno la lista di proiettili
    void aggiornaCoordinateProiettili(sf::Time tempo);
};
#endif