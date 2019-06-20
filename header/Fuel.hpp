//header carburante
#ifndef FUEL_H
#define FUEL_H

#include "./utils.hpp"
#include "./DisegnabileI.hpp"
#include "./ColoreRGB.hpp"
#include "./Punto.hpp"

class Fuel : public DisegnabileI
{
private:
    int tipo = 0;
    Punto centro;
    float quantita = FUEL1;
    float size = 10.f;
public:
    void generaTipo(void);
public:
    //costruttore vuoto
    Fuel(void);
    //costruttore coordinate
    Fuel(Punto centro);
    Fuel(float x, float y);
    //costruttore completo - la quantita decisa dal tipo
    Fuel(Punto centro, float size);
    Fuel(float x, float y, float size);

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
    int getTipo(void);

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