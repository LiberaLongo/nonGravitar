//header navicella
#ifndef NAVICELLA_H
#define NAVICELLA_H

#include <SFML/Graphics.hpp>

#include "./Punto.hpp"

class Navicella
{
private:
    //il centro della navicella
    Punto centro;   //di default (0,0) in accordo con il default di Punto
    //il raggio della circonferenza circoscritta
    float raggio = 25.f;

public:
    //costruttori e distruttore
    Navicella(void);
    Navicella(float raggio);
    Navicella(Punto centro);
    Navicella(float x, float y);
    Navicella(Punto centro, float raggio);
    Navicella(float x, float y, float raggio);
    /*virtual*/ ~Navicella(void);

    //setters
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);
    void setRaggio(float raggio);

    //getters
    float getX(void);
    float getY(void);
    float getRaggio(void);

    //stampa
    void print(void);

    //contronto
    bool confronto(Navicella nav);

    //disegna
     sf::CircleShape draw(void);
};

#endif //NAVICELLA_H
