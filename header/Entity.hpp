//navicella e bunker sono entità

#ifndef ENTITA_H
#define ENTITA_H

//#include <SFML/Graphics.hpp>

#include "./DisegnabileI.hpp"
#include "./utils.hpp"
#include "./Direzione.hpp"
#include "./Lista.hpp"
#include "./Proiettile.hpp"

//ATTENZIONE! cpp inclusi per classi template
#include "../utils/ListaParent.cpp"
#include "../utils/Lista.cpp"

template class Lista<Proiettile>;

extern float SIZE_NAVICELLA;

class Entity
{
private:
    Direzione dir;
    float size = SIZE_BUNKER;
    int vita = 1; //il bunker ha 1 vita, la navicella ha 5 vite
    int tipo = 1; //il bunker ha tipo 1, la navicella ha tipo 0
    //NB: questo tipo differenzia navicella e bunker non i due tipi di bunker

protected:
    Lista<Proiettile> proiettili;

public:
    void drawProiettili(sf::RenderWindow &window);

public:
    //costruttore vuoto
    Entity(void);
    //altri costruttori
    Entity(Punto centro, int vita, int tipo);
    Entity(float x, float y, int vita, int tipo);
    
    //distruttore
    virtual ~Entity(void) {};

    //SETTERS
    //setters coordinate
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);
    void setAngolo(float angolo);
    void setSpeed(float speed);
    void setSize(float size);
    void setHead(struct Elem<Proiettile> * head);
    //getters
    float getX(void);
    float getY(void);
    float getAngolo(void);
    float getSpeed(void);
    float getSize(void);
    int getVita(void);
    struct Elem<Proiettile> * getHead(void);

    //stampa
    void print(void);

    //disegna
    void draw(sf::RenderWindow &window);

    //muovi
    void move(void);

    //spara
    void shoot(ColoreRGB colore);
    void shoot(Punto mouseclick, ColoreRGB colore);

    bool isNear(float x, float y, float size);

    bool isOutsideScreen(void);

    //vita
    void muori(void);

    //aggiorno la lista di proiettili
    void aggiornaCoordinateProiettili(sf::Time tempo, Punto centroNavicella);
};

#endif //NAVICELLA_H
