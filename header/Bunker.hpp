//header bunker
#ifndef BUNKER_H
#define BUNKER_H

#include "./DisegnabileI.hpp"
#include "./Direzione.hpp"

class Bunker : public DisegnabileI
{
private:
    //il centro della navicella
    Punto centro; //di default (0,0) in accordo con il default di Punto
    ListaClasse<Direzione> headDirezioni;
    //il raggio della circonferenza circoscritta
    float size = 10.f; //ampiezza diviso 4...
    float angle = 0.f; //angolo del cannone
    float speed = 5.f; //velocità degli spari
private:
    //bla bla bla
};

#endif //BUNKER_H