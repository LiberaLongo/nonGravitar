//header navicella
#ifndef NAVICELLA_H
#define NAVICELLA_H

#include <SFML/Graphics.hpp>

#include "./Punto.hpp"

class Navicella
{
private:
    Punto centro; //il centro della navicella
    float raggio;

public:
    //costruttori e distruttore
    Navicella(void);
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
    void draw(sf::RenderWindow window);
};

#endif //NAVICELLA_H