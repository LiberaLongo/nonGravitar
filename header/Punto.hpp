//header punti
#ifndef PUNTO_HPP
#define PUNTO_HPP

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
    virtual ~Punto(void) {};

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

    //distanza tra due punti
    float distance(float x, float y);
    float distance(Punto p);
    
    //è dentro?
    bool isNear(float x, float y, float width, float height);
    bool isNear(float x, float y, float size);
    bool isNear(Punto centro, float size);

    //calcola angolo rispetto al punto corrente
    float calcolaAngolo(Punto arrivo);

    //restituisci un vettore della libreria
    sf::Vector2f getPuntoLib(void);
};

#endif //PUNTO_HPP
