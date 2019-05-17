//header carburante
#ifndef FUEL_H
#define FUEL_H

const float consumo = 1.f;

class Fuel : public DisegnabileI
{
private:
    Punto centro;
    float quantita = 100.f;

public:
    //costruttore vuoto
    Fuel(void);
    //costruttore coordinate
    Fuel(Punto centro);
    Fuel(float x, float y);
    //costruttore completo
    Fuel(Punto centro, float raggio);
    Fuel(float x, float y, float raggio);
    /*virtual*/ ~Fuel(void);

    //setters
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);
    void setQuantita(float quantita);

    //getters
    float getX(void);
    float getY(void);
    float getQuantita(void);

    //stampa
    void print(void);

    //contronto
    bool confronto(Fuel p);

    //disegna
    void draw(sf::RenderWindow &window);

    //consumo carburante
    float consumoFuel(void);
};
#endif //FUEL_H