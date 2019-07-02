//header bunker
#ifndef BUNKER_H
#define BUNKER_H

#include "./DisegnabileI.hpp"
#include "./Entity.hpp"

//per Bunker
template class Lista<Direzione>;

class Bunker : public Entity
{
private:
    int tipo = 0;
    Lista<Direzione> headDirezioni;

public:
    //costruttore vuoto
    Bunker(void);
    //altri costruttori
    Bunker(Punto centro, float angolo);
    //non usato, ma simile
    Bunker(float x, float y, float angolo);

    //distruttore
    virtual ~Bunker(void) {};

    //setters

    //getters
    int getTipo(void);

    //stampa
    void print(void);

    //contronto
    bool confronto(Bunker b);

    //disegna
    void draw(sf::RenderWindow &window);

    void genera(void);
    
    //spara
    void shoot(sf::Time tempo);
};

#endif //BUNKER_H