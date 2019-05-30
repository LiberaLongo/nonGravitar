//header punti
#ifndef PUNTO_H
#define PUNTO_H

#include "./utils.hpp"
#include "./DisegnabileI.hpp"

class Punto : public DisegnabileI
{
private:
    float x = 0.f;
    float y = 0.f;

public:
    //costruttore vuoto
    Punto(void);
    //cotruttore completo
    Punto(float x, float y);
    //distruttore
    virtual ~Punto(void);

    //setters
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);

    //getters
    float getX(void);
    float getY(void);

    //stampa
    void print(void);

    //contronto
    bool confronto(Punto p);

    //disegna
    void draw(sf::RenderWindow &window);

    //è dentro?
    bool isIn(float x, float y, float size);
    bool isIn(Punto centro, float size);

    //restituisci un vettore della libreria
    sf::Vector2f getVector(void);
};

#endif //PUNTO_H
