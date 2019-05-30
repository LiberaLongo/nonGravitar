//codice proiettile
#include "../header/Proiettile.hpp"

//costruttore vuoto
Proiettile::Proiettile(void) : Direzione()
{
    //tutto fatto nel costruttore di direzione
}
//costruttore minimale
Proiettile::Proiettile(Punto origine) : Direzione(origine)
{
    //tutto fatto nel costruttore di direzione
}
Proiettile::Proiettile(float x, float y) : Direzione(x, y)
{
    //tutto fatto nel costruttore di direzione
}
//costruttore completo
Proiettile::Proiettile(Punto origine, float angolo, float speed) : Direzione(origine, angolo, speed)
{
    //tutto fatto nel costruttore di direzione
}
Proiettile::Proiettile(float x, float y, float angolo, float speed) : Direzione(x, y, angolo, speed)
{
    //tutto fatto nel costruttore di direzione
}
//distruttore
/*virtual*/ Proiettile::~Proiettile(void)
{
    //distruttore vuoto
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
void Proiettile::draw(sf::RenderWindow &window) {}