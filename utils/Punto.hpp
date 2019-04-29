//header punti
#ifndef PUNTO_H
#define PUNTO_H

class Punto
{
private:
    float x;
    float y;

public:
    //costruttore e distruttore
    Punto(float x, float y);
    virtual ~Punto();

    //setters
    void setX(float x);
    void setY(float y);
    void setCoord(float x, float y);

    //getters
    float getX(void);
    float getY(void);
};

#endif //PUNTO_H