//Poligono header
#ifndef POLIGONO_HPP
#define POLIGONO_HPP

#include "./Punto.hpp"
#include "./ColoreRGB.hpp"
#include "./Lista.hpp"

//ATTENZIONE! cpp inclusi per classi template
#include "./includeTemplate.hpp"

template class Lista<Punto>;

class Poligono
{
private:
    ColoreRGB colore;
    Lista<Punto> surface;

public:
    //costruttore
    Poligono(void);
    Poligono(ColoreRGB colore);
    //distruttore
    virtual ~Poligono(void){};

    //setters
    void setColore(ColoreRGB colore);
    void setColore(int red, int green, int blue);
    //setta la lista
    void setLista(Lista<Punto> listaSurface);
    //setta il puntatore alla lista
    void setHead(struct Elem<Punto> *headSurface);

    //getters
    sf::Color getColoreLib(void);
    //ottengo il puntatore alla testa, non al primo elemento
    struct Elem<Punto> *getHead(void);

    //numero punti
    int numPunti(void);
    //stampa
    void printColore(void);
    void print(void);
    //disegna
    void draw(sf::RenderWindow &window);

    //ordina
    void ordina(void);
    //genera
    void genera(void);
};

#endif //POLIGONO_HPP
