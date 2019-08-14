//cScreen rappresenta ogni screen
#ifndef C_SCREEN_HPP
#define C_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "./utils.hpp"

class cScreen
{
protected:
    bool generaSistema = false;
    bool haiVinto = false;
    bool haiPerso = false;
    int vita = VITA_NAVICELLA;
    int fuel = FUEL_NAVICELLA;
    int punteggio = 0;

protected:
    void reset(void)
    {
        //resetto la vita per la prossima partita
        vita = VITA_NAVICELLA;
        fuel = FUEL_NAVICELLA;
        punteggio = 0;
        //aggiorno i booleani
        haiPerso = true;
        generaSistema = true;
    }

public:
    virtual int Run(sf::RenderWindow &App) = 0;
};
#endif //C_SCREEN_HPP
