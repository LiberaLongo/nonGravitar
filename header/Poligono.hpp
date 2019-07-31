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

//private:
public:
    //Dati 3 punti allineati la funzione controlla se
    //il punto P giace sul segmento AB.
    bool onSegment(Punto A, Punto P, Punto B);

    //Per trovare l'orientamento della tripletta ordinata (P, Q, R)
    //La funzione ritorna i seguenti valori
    //0 --> P, Q, R sono allineati
    //1 --> senso orario (clockwise, right turn)
    //2 --> senso antiorario (counterclockwise, left turn)
    int orientation(Punto P, Punto Q, Punto R);

    //La funzione ritorna true se
    //il segmento AB interseca il segmento CD.
    bool doIntersect(Punto A, Punto B, Punto C, Punto D);

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

    //insersici un punto in testa
    void insert(Punto P);
    void insert(float x, float y);

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

    //return true se il punto P giace dentro il poligono
    //precondition n è il numero di punti del poligono
    bool PointIsInside(Punto P, int n);
};

#endif //POLIGONO_HPP
