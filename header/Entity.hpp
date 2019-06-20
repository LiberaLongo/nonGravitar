//navicella e bunker sono entità

#ifndef ENTITA_H
#define ENTITA_H

//#include <SFML/Graphics.hpp>

#include "./DisegnabileI.hpp"
#include "./utils.hpp"
#include "./Direzione.hpp"
#include "./Lista.hpp"
#include "./Proiettile.hpp"

template class Lista<Proiettile>;

extern float SIZE_NAVICELLA;

class Entity
{
private:
    Direzione dir;
    float size = SIZE_NAVICELLA;
    Lista<Proiettile> proiettili;

public:
    void drawProiettili(sf::RenderWindow &window);

public:
    //COSTRUTTORI
    //costruttore void
    Entity(void);
    //costruttori punto
    Entity(Punto centro);
    Entity(float x, float y);
    Entity(Direzione dir, float size);
    //costruttori completi
    Entity(Punto centro, float angolo, float speed, float size);
    Entity(float x, float y, float angolo, float speed, float size);
    Entity(Direzione dir, float size, Lista<Proiettile> proiettili); 
    Entity(float x, float y, float angolo, float speed, float size, Lista<Proiettile> proiettili);
    //distruttori
    virtual ~Entity(void);

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
    struct Elem<Proiettile> * getHead(void);

    //stampa
    void print(void);

    //disegna
    void draw(sf::RenderWindow &window);

    //muovi
    void move(void);

    //spara
    void shoot(Punto mouseclick, ColoreRGB colore);

    bool isNear(float x, float y, float size);

    bool isOutsideScreen(void);

    //aggiorno la lista di proiettili
    void aggiornaCoordinateProiettili(sf::Time tempo);
};

#endif //NAVICELLA_H
