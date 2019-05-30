//header proiettile
#ifndef PROIETTILE_H
#define PROIETTILE_H

#include <ctime>
#include <cstdlib>

#include "./Direzione.hpp"
#include "./DisegnabileI.hpp"

class Proiettile : public Direzione //disegnabile
{
public:
    //costruttore vuoto
    Proiettile(void);
    //costruttore minimale
    Proiettile(Punto origine);
    Proiettile(float x, float y);
    //costruttore completo
    Proiettile(Punto origine, float angolo, float speed);
    Proiettile(float x, float y, float angolo, float speed);
    //distruttore
    virtual ~Proiettile(void);
    void print(void);
    //disegna
    void draw(sf::RenderWindow &window);
    /*spara non esiste... o è uguale a move in questo caso*/
};
#endif //PROIETTILE_H