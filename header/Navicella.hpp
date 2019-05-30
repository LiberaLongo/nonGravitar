//header navicella
#ifndef NAVICELLA_H
#define NAVICELLA_H

//#include <SFML/Graphics.hpp>

#include "./DisegnabileI.hpp"
#include "./utils.hpp"
#include "./Punto.hpp"
#include "./Direzione.hpp"
#include "./Fuel.hpp"
#include "./Pianeta.hpp"

class Navicella : public DisegnabileI
{
private:
    //il centro della navicella
    Punto centro;   //di default (0,0) in accordo con il default di Punto
    Fuel carburante;
    Direzione dir;
    //il raggio della circonferenza circoscritta
    float size = 10.f; //ampiezza diviso 4...

public:
    //COSTRUTTORI
    //costruttore void
    Navicella(void);
    //costruttori punto
    Navicella(Punto centro);
    Navicella(float x, float y);
    //costruttori completi
    Navicella(Punto centro, Fuel carburante, Direzione dir, float size);
    Navicella(float x, float y, float carburante, float angle, float speed, float size);

    //distruttori
    virtual ~Navicella(void);

    //SETTERS
    //setters coordinate
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);
    //altri setter
    void setSize(float size);
    void setAngolo(float angle);
    void setSpeed(float speed);
    void setFuel(Fuel carburante);
    //getters
    float getX(void);
    float getY(void);
    float getSize(void);
    float getAngolo(void);
    float getSpeed(void);
    float getFuel(void);

    //stampa
    void print(void);

    //disegna
    void draw(sf::RenderWindow &window);

    //controlli di movimento
    void move(float angle);

    //spara
    void shoot(Punto mouseclick);

    //controlla se è dentro
    bool isIn(Pianeta planet);
};

#endif //NAVICELLA_H
