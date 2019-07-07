//header navicella
#ifndef NAVICELLA_H
#define NAVICELLA_H

//#include <SFML/Graphics.hpp>

#include "./DisegnabileI.hpp"
#include "./Entity.hpp"
#include "./Fuel.hpp"

//qui viene incluso i template di bunker
#include "./Pianeta.hpp"

extern float SIZE_NAVICELLA;

class Navicella : public Entity
{
private:
    int vita = VITA_NAVICELLA;
    Fuel carburante;
    ColoreRGB coloreProiettile = ColoreRGB(LUMUS_MAXIMA, LUMUS_MAXIMA, 0);

public:
    //costruttore vuoto
    Navicella(void);
    //altri costruttori
    Navicella(float x, float y);
    //non usato, ma simile
    Navicella(Punto centro);

    //distruttore
    virtual ~Navicella(void) {};

    //setters
    void setFuel(int quantita);
    void setVita(int vita);
    //getters
    int getFuel(void);
    int getVita(void);

    //stampa
    void print(void);

    //disegna
    void draw(sf::RenderWindow &window);

    //controlli di movimento
    bool move(float angle);

    //spara
    bool shoot(void); //sparo nella mia direzione
    bool shoot(Punto mouseclick); //sparo nella direzione del mouse

    //controlla se è dentro il pianeta
    bool isNear(Pianeta planet);

    //override aggiornaProiettili di Entity
    void aggiornaCoordinateProiettili(sf::Time tempo, struct Elem<Bunker> *headEntita);
    //restituisce true se il pianeta deve essere distrutto
};

#endif //NAVICELLA_H
