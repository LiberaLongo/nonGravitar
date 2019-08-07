//header bunker
#ifndef BUNKER_HPP
#define BUNKER_HPP

#include "./DisegnabileI.hpp"
#include "./Entity.hpp"

//ATTENZIONE! cpp inclusi per classi template
//#include "./includeTemplate.hpp"

//per Bunker
//template class Lista<Direzione>;
#define MAX_DIREZIONI 3

class Bunker : public Entity
{
private:
    int tipo = 0;
    ColoreRGB coloreProiettile = ColoreRGB(LUMUS_MAXIMA, LUMUS_MAXIMA, 0);
    //Lista<Direzione> direzioni;
    Direzione direzioni[MAX_DIREZIONI]; //ci sono al massimo 3 direzioni

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
    void shoot(void);
};

#endif //BUNKER_HPP
