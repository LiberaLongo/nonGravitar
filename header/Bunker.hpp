//header bunker
#ifndef BUNKER_H
#define BUNKER_H

#include "./DisegnabileI.hpp"
#include "./Direzione.hpp"

#include "./ListaClasse.hpp"

//ATTENZIONE! cpp inclusi per classi template
#include "../utils/Lista.cpp"
#include "../utils/ListaClasse.cpp"

//per Bunker
template class ListaClasse<Direzione>;

class Bunker : public DisegnabileI
{
private:
    //il centro della navicella
    Punto centro; //di default (0,0) in accordo con il default di Punto
    ListaClasse<Direzione> headDirezioni;
    //il raggio della circonferenza circoscritta
    float size = 10.f; //ampiezza diviso 4...
    float angle = 0.f; //angolo del cannone
    float speed = 5.f; //velocità degli spari
private:
    void aggiornaCentriDirezione(ListaClasse<Direzione> headDir);
public:
    //costruttore vuoto
    Bunker(void);
    //costruttore minimale
    Bunker(Punto centro);
    Bunker(float x, float y);
    //costruttore completo
    Bunker(Punto centro, float angolo, float speed, float size, ListaClasse<Direzione> headDir);
    Bunker(float x, float y, float angolo, float speed, float size, ListaClasse<Direzione> headDir);

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

    //stampa
    void print(void);

    //contronto
    bool confronto(Bunker b);

    //disegna
    void draw(sf::RenderWindow &window);
    
    //spara
    void shoot(void);
};

#endif //BUNKER_H