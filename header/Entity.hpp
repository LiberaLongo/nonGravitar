//navicella e bunker sono entità

#ifndef ENTITA_HPP
#define ENTITA_HPP

//#include <SFML/Graphics.hpp>

#include "./DisegnabileI.hpp"
#include "./utils.hpp"
#include "./Direzione.hpp"
#include "./Lista.hpp"
#include "./Proiettile.hpp"

//ATTENZIONE! cpp inclusi per classi template
#include "./includeTemplate.hpp"

template class Lista<Proiettile>;

extern float SIZE_NAVICELLA;

class Entity
{
private:
    Direzione dir;
    float size = SIZE_BUNKER;

protected:
    Lista<Proiettile> proiettili;

public:
    void drawProiettili(sf::RenderWindow &window);

public:
    //costruttore vuoto
    Entity(void);
    //altri costruttori
    Entity(Punto centro, float size);
    Entity(float x, float y, float size);
    
    //distruttore
    virtual ~Entity(void) {};

    //SETTERS
    //setters coordinate
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);
    void setAngolo(float angolo);
    void setAngolo(Punto mouseclick);
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
    void shoot(ColoreRGB colore);
    void shoot(Punto mouseclick, ColoreRGB colore);

    bool isNear(float x, float y, float size);

    bool isOutsideScreen(void);

    //aggiorno la lista di proiettili
    int aggiornaCoordinateProiettili(float x, float y, int vita, Poligono pol, int n);
};

#endif //ENTITA_HPP
