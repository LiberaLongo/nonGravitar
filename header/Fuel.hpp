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
    int quantita = FUEL_1_QUANTITA;
    float size = SIZE_FUEL;
public:
    void generaTipo(void);
public:
    //costruttore vuoto
    Fuel(void);
    //altri costruttori
    Fuel(Punto centro);
    //non usato, ma simile
    Fuel(float x, float y);

    //distruttore
    virtual ~Fuel(void) {};

    //setters
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);
    void setQuantita(float quantita);
    void setSize(float size);

    //getters
    float getX(void);
    float getY(void);
    float getSize(void);
    int getQuantita(void);
    int getTipo(void);

    //stampa
    void print(void);

    //contronto
    bool confronto(Fuel f);

    //disegna
    void draw(sf::RenderWindow &window);

    //consumo carburante
    bool consumoFuel(void);
};
#endif //FUEL_H
