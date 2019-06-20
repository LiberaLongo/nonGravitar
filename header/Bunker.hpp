//header bunker
#ifndef BUNKER_H
#define BUNKER_H

#include "./DisegnabileI.hpp"
#include "./Entity.hpp"
#include "./Direzione.hpp"

#include "./Lista.hpp"

//ATTENZIONE! cpp inclusi per classi template
#include "../utils/ListaParent.cpp"
#include "../utils/Lista.cpp"

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
    //costruttore minimale
    Bunker(Punto centro, float angolo);
    Bunker(float x, float y, float angolo);
    //costruttore completo
    Bunker(Punto centro, float angolo, float speed, float size, Lista<Direzione> headDir);
    Bunker(float x, float y, float angolo, float speed, float size, Lista<Direzione> headDir);

    //distruttore
    virtual ~Bunker(void);

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