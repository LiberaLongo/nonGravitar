#ifndef DIREZIONE_H
#define DIREZIONE_H

#include "./utils.hpp"
#include "./DisegnabileI.hpp"
#include "./Punto.hpp"

class Direzione : public DisegnabileI
{
private:
    Punto origine;
    float angolo = 0.f; //angolo canonico studiato in matematica
    float speed = SPEED;
public:
    //costruttore vuoto
    Direzione(void);
    //costruttore minimale
    Direzione(Punto origine);
    Direzione(float x, float y);
    //costruttore completo
    Direzione(Punto origine, float angolo, float speed);
    Direzione(float x, float y, float angolo, float speed);

    //distruttore
    /*virtual*/ ~Direzione(void);

    //setters
    void setXOrigine(float x);
    void setYOrigine(float y);
    void setOrigine(Punto origine);
    void setOrigine(float x, float y);
    void setAngolo(float angolo);
    void setSpeed(float speed);

    //getters
    float getXOrigine(void);
    float getYOrigine(void);
    float getAngolo(void);
    float getSpeed(void);

    //stampa
    void print(void);

    //contronto
    bool confronto(Direzione dir);

    //disegna
    void draw(sf::RenderWindow &window);
    //move
    void move(void);
};

#endif
