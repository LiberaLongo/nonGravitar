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
    //cose grafiche e basta
    ColoreRGB colore;
    ColoreRGB atmosfera;

    //liste
    Lista<Punto> surface;
    Lista<Fuel> fuel;
    Lista<Bunker> bunker;
    /*ATTENZIONE!
    Serve la lista dei centri dei bunker
    per controllare i proiettili di entity*/
    Lista<Punto> centriBunker;

private:
    void generaPunti(void);
    void ordinaPunti(void);
    void generaBunkerFuel(void);

public:
    //costruttore vuoto
    Pianeta(void);
    //altri costruttori
    Pianeta(float x, float y, float raggio);
    //non usato, ma simile
    Pianeta(Punto centro, float raggio);

    //distruttore
    virtual ~Pianeta(void) {};

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
    /*ATTENZIONE!
    Serve la lista dei centri dei bunker
    per controllare i proiettili di entity*/
    struct Elem<Punto> *getHeadCentriBunker();

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

    //restituisce true se la lista dei bunker è vuota
    bool emptyBunker(void); 
};
#endif