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
    float angle = 0.f; //punta verso l'alto
    float speed = 5.f; //velocità

public:
    //COSTRUTTORI
    //costruttore void
    Navicella(void);
    //costruttori punto
    Navicella(Punto centro);
    Navicella(float x, float y);
    //costruttori completi
    Navicella(Punto centro, float raggio, float angle, float speed);
    Navicella(float x, float y, float raggio, float angle, float speed);

    //distruttori
    /*virtual*/ ~Navicella(void);

    //SETTERS
    //setters coordinate
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);
    //altri setter
    void setRaggio(float raggio);
    void setAngolo(float angle);
    void setSpeed(float speed);

    //getters
    float getX(void);
    float getY(void);
    float getRaggio(void);
    float getAngolo(void);
    float getSpeed(void);

    //stampa
    void print(void);

    //disegna
    sf::CircleShape draw(void);

    //controlli di movimento
    void moveUp(float hight);
    void moveLeft(float width);
    void moveDown(float hight);
    void moveRight(float width);
};

#endif //NAVICELLA_H
