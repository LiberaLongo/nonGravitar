//header bunker
#ifndef BUNKER_H
#define BUNKER_H

#include "./DisegnabileI.hpp"
#include "./Entity.hpp"
#include "./Direzione.hpp"

#include "./Lista.hpp"

//ATTENZIONE! cpp inclusi per classi template
#include "../utils/ListaParent.cpp"
#include "../utils/Lista.cpp"

//per Bunker
template class Lista<Direzione>;

class Bunker : public Entity
{
private:
    int tipo = 0;
    //il centro della navicella
    Punto centro; //di default (0,0) in accordo con il default di Punto
    Lista<Direzione> headDirezioni;
    Lista<Proiettile> proiettili;
    //il raggio della circonferenza circoscritta
    float size = 10.f; //ampiezza diviso 4...
    float angolo = 0.f; //angolo del cannone
    float speed = 5.f; //velocità degli spari
private:
    void aggiornaCentriDirezione(Lista<Direzione> headDir);
    void drawProiettili(sf::RenderWindow &window);
public:
    //costruttore vuoto
    Bunker(void);
    //costruttore minimale
    Bunker(Punto centro, float angolo);
    Bunker(float x, float y, float angolo);
    //costruttore completo
    Bunker(Punto centro, float angolo, float speed, float size, Lista<Direzione> headDir);
    Bunker(float x, float y, float angolo, float speed, float size, Lista<Direzione> headDir);

    //distruttore
    virtual ~Bunker(void);

    //setters
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);
    void setAngolo(float angolo);
    void setSpeed(float speed);
    void setSize(float size);

    //getters
    float getX(void);
    float getY(void);
    float getAngolo(void);
    float getSpeed(void);
    float getSize(void);
    int getTipo(void);

    //stampa
    void print(void);

    //contronto
    bool confronto(Bunker b);

    //disegna
    void draw(sf::RenderWindow &window);

    void genera(void);
    
    //spara
    void shoot(sf::Time tempo);

    //aggiorno la lista di proiettili
    void aggiornaCoordinateProiettili(sf::Time tempo);
};

#endif //BUNKER_H