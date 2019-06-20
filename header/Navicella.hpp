//header navicella
#ifndef NAVICELLA_H
#define NAVICELLA_H

//#include <SFML/Graphics.hpp>

#include "./DisegnabileI.hpp"
#include "./Entity.hpp"
#include "./Fuel.hpp"

//qui viene incluso i template di bunker
#include "./Pianeta.hpp"

extern float SIZE_NAVICELLA;

class Navicella : public Entity
{
private:
    Fuel carburante;

public:
    //COSTRUTTORI
    //costruttore void
    Navicella(void);
    //costruttori punto
    Navicella(Punto centro);
    Navicella(float x, float y);
    //costruttori completi
    Navicella(Direzione dir, Fuel carburante, float size);
    Navicella(float x, float y, float angolo, float speed, float size, float carburante);

    //distruttori
    virtual ~Navicella(void);

    //setters
    void setFuel(Fuel carburante);
    //getters
    float getFuel(void);

    //stampa
    void print(void);

    //disegna
    void draw(sf::RenderWindow &window);

    //controlli di movimento
    void move(float angle);

    //spara
    void shoot(Punto mouseclick);

    //controlla se è dentro il pianeta
    bool isNear(Pianeta planet);
};

#endif //NAVICELLA_H
