//codice proiettile
#include "../header/Proiettile.hpp"

extern float WIDTH, HEIGHT;

//costruttore vuoto
Proiettile::Proiettile(void) : Direzione()
{
    //tutto fatto nel costruttore di direzione
}
//costruttore minimale
Proiettile::Proiettile(Punto origine, float angolo, ColoreRGB colore) : Direzione(origine, angolo)
{
    //costruttore di direzione
    this->colore = colore;
}
Proiettile::Proiettile(float x, float y, float angolo, ColoreRGB colore) : Direzione(x, y, angolo)
{
    //costruttore di direzione
    this->colore = colore;
}
//costruttore completo
Proiettile::Proiettile(Punto origine, float angolo, float speed, float size) : Direzione(origine, angolo, speed)
{
    //costruttore di direzione
    this->size = size;
}
Proiettile::Proiettile(float x, float y, float angolo, float speed, float size) : Direzione(x, y, angolo, speed)
{
    //costruttore di direzione
    this->size = size;
}
//distruttore
/*virtual*/ Proiettile::~Proiettile(void)
{
    //distruttore vuoto
}

//setters
void Proiettile::setX(float x)
{
    this->origine.setX(x);
}
void Proiettile::setY(float y)
{
    this->origine.setY(y);
}
void Proiettile::setCoord(float x, float y) {
    this->setX(x);
    this->setY(y);
}
//getters
float Proiettile::getX(void)
{
    return this->getX_origine();
}
float Proiettile::getY(void)
{
    return this->getY_origine();
}

//stampa
void Proiettile::print(void)
{
    cout << "Proiettile : [ origine = ";
    this->origine.print();
    cout << ", angolo = " << this->getAngolo();
    cout << ", speed = " << this->getSpeed();
    cout << " ]" << endl;
}
//disegna
void Proiettile::draw(sf::RenderWindow &window)
{
    //disegnamo flowy molto molto piccolo
    //"mettete i fiori nei vostri cannoni"
    sf::CircleShape flowy(this->size);
    float x = this->getX() - this->size;
    float y = this->getY() - this->size;
    flowy.setPosition(x, y);

    //colore verde
    flowy.setFillColor(this->colore.getColorLib());

    window.draw(flowy);
}

bool Proiettile::isOutsideScreen(void) {
    return !this->isNear(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT / 2);
}