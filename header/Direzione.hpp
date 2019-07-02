#ifndef DIREZIONE_H
#define DIREZIONE_H

#include "./utils.hpp"
#include "./DisegnabileI.hpp"
#include "./Punto.hpp"

extern float SPEED_NAVICELLA;

class Direzione : public DisegnabileI
{
protected:
    Punto origine;
    float angolo = 0.f; //angolo canonico studiato in matematica
    float speed = SPEED_NAVICELLA;

public:
    //costruttore vuoto
    Direzione(void);
    //altri costruttori
    Direzione(float x, float y, float angolo);
    //non usato ma simile
    Direzione(Punto origine, float angolo);

    //distruttore
    virtual ~Direzione(void) {};

    //setters
    void setX_origine(float x); //x dell'origine
    void setY_origine(float y); //y dell'origine
    void setOrigine(Punto origine);
    void setOrigine(float x, float y);
    void setSpeed(float speed);
    void setAngolo(float angolo);
    void setAngolo(Punto arrivo);

    //getters
    float getX_origine(void);
    float getY_origine(void);
    float getAngolo(void);
    float getSpeed(void);

    //stampa
    void print(void);

    //contronto
    bool confronto(Direzione dir);

    //disegna
    void draw(sf::RenderWindow &window);

    bool isNear(float x, float y, float width, float height);
    bool isNear(float x, float y, float size);

    //move
    void move(void);
};

#endif
