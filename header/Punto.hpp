//header punti
#ifndef PUNTO_H
#define PUNTO_H

class Punto
{
private:
    float x = 0.f;
    float y = 0.f;

public:
    //costruttori e distruttore
    Punto(void);
    Punto(float x, float y);
    /*virtual*/ ~Punto(void);

    //setters
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);

    //getters
    float getX(void);
    float getY(void);

    //stampa
    void print(void);

    //contronto
    bool confronto(Punto p);
};

#endif //PUNTO_H
