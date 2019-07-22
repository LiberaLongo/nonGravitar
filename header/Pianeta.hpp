//header pianeta
#ifndef PIANETA_HPP
#define PIANETA_HPP

#include "./Fuel.hpp"
#include "./Poligono.hpp"
#include "./Bunker.hpp"

//ATTENZIONE! cpp inclusi per classi template
#include "./includeTemplate.hpp"

template class Lista<Fuel>;
template class Lista<Bunker>;

class Pianeta : public DisegnabileI
{
private:
    Punto centro;
    float raggio = PIANETA_RAGGIO;
    //cose grafiche e basta
    ColoreRGB atmosfera;

    //il poligono è una lista di punti
    Poligono poligono;

    //liste
    Lista<Fuel> fuel;
    Lista<Bunker> bunker;

private:
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
    //provo a ottenre il poligono
    Poligono getPoligono(void);

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

    //fa sparare i bunker
    void shoot(sf::Time tempo);

    //aggiorna coordinate dei proiettili sparati dai bunker
    int aggiornaCoordinateProiettili(sf::Time tempo, float x, float y, int vita);
};
#endif //PIANETA_HPP
