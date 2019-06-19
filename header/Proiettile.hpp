//header proiettile
#ifndef PROIETTILE_H
#define PROIETTILE_H

#include <ctime>
#include <cstdlib>

#include "./Direzione.hpp"
#include "./DisegnabileI.hpp"
#include "./ColoreRGB.hpp"

class Proiettile : public Direzione //disegnabile
{
private:
    float size = 1.f;
    ColoreRGB colore = ColoreRGB(LUMUS_MAXIMA, LUMUS_MAXIMA, 0);
public:
    //costruttore vuoto
    Proiettile(void);
    //costruttore minimale
    Proiettile(Punto origine, ColoreRGB colore);
    Proiettile(float x, float y, ColoreRGB colore);
    //costruttore completo
    Proiettile(Punto origine, float angolo, float speed, float size);
    Proiettile(float x, float y, float angolo, float speed, float size);
    //distruttore
    virtual ~Proiettile(void);

    //setters
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);
    //getters
    float getX(void);
    float getY(void);

    //stampa
    void print(void);
    //disegna
    void draw(sf::RenderWindow &window);
    /*spara non esiste... o è uguale a move in questo caso*/
    bool isOutsideScreen(void);
};
#endif //PROIETTILE_H