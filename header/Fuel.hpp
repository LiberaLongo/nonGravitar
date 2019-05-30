//header carburante
#ifndef FUEL_H
#define FUEL_H

#include "./utils.hpp"
#include "./DisegnabileI.hpp"
#include "./Punto.hpp"

class Fuel : public DisegnabileI
{
private:
    Punto centro;
    float quantita = FUEL1;
    float size;

public:
    //costruttore vuoto
    Fuel(void);
    //costruttore coordinate
    Fuel(Punto centro);
    Fuel(float x, float y);
    //costruttore completo
    Fuel(Punto centro, float quantita, float size);
    Fuel(float x, float y, float quantita, float size);

    //distruttore
    virtual ~Fuel(void);

    //setters
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);
    void setQuantita(float quantita);
    void setSize(float size);

    //getters
    float getX(void);
    float getY(void);
    float getQuantita(void);
    float getSize(void);

    //stampa
    void print(void);

    //contronto
    bool confronto(Fuel f);

    //disegna
    void draw(sf::RenderWindow &window);

    //consumo carburante
    float consumoFuel(void);
};
#endif //FUEL_H