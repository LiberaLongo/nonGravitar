#include "../header/Direzione.hpp"

//costruttore vuoto
Direzione::Direzione(void)
{
    //cose di default
}
//altri costruttori
Direzione::Direzione(float x, float y, float angolo)
{
    this->origine.setCoord(x, y);
    this->angolo = angolo;
    //default angolo e speed
}
//non usato ma simile
Direzione::Direzione(Punto origine, float angolo)
{
    this->origine = origine;
    this->angolo = angolo;
    //default angolo e speed
}

//setters
void Direzione::setX_origine(float x)
{
    this->origine.setX(x);
}
void Direzione::setY_origine(float y)
{
    this->origine.setY(y);
}
void Direzione::setOrigine(Punto origine)
{
    this->origine = origine;
}
void Direzione::setOrigine(float x, float y)
{
    this->origine.setCoord(x, y);
}
void Direzione::setSpeed(float speed)
{
    this->speed = speed;
}
void Direzione::setAngolo(float angolo)
{
    this->angolo = angolo;
}
void Direzione::setAngolo(Punto arrivo)
{
    this->angolo = this->origine.calcolaAngolo(arrivo);
}
//getters
float Direzione::getX_origine(void)
{
    return this->origine.getX();
}
float Direzione::getY_origine(void)
{
    return this->origine.getY();
}
float Direzione::getAngolo(void)
{
    return this->angolo;
}
float Direzione::getSpeed(void)
{
    return this->speed;
}

//stampa
void Direzione::print(void)
{
    cout << "Direzione : [ origine = ";
    this->origine.print();
    cout << ", angolo = " << this->angolo;
    cout << ", speed = " << this->speed;
    cout << " ]" << endl;
}

//contronto
bool Direzione::confronto(Direzione dir)
{
    return (this->getX_origine() == dir.getX_origine() && this->getY_origine() == dir.getY_origine() && this->speed == dir.getSpeed() && this->angolo == dir.getAngolo());
}

//disegna
void Direzione::draw(sf::RenderWindow &window)
{
    sf::RectangleShape line(sf::Vector2f(5.f, -150.f));
    line.setPosition(this->getX_origine(), this->getY_origine());
    line.rotate(this->angolo);
    window.draw(line);
}

bool Direzione::isNear(float x, float y, float width, float height) {
    return this->origine.isNear(x, y, width, height);
}

bool Direzione::isNear(float x, float y, float size) {
    return this->origine.isNear(x, y, size);
}
//move

//Precondition: dato l'angolo e l'origine
//Postcondition: deve muoversi di speed pixel in quella direzione
//              e aggiornare le sue coordinate del origine
void Direzione::move(void)
{
    //this->angolo è l'angolo secondo l'orientamento di sfml
    //angolo è l'angolo invece di cmath
    float angolo = (double)this->angolo * M_PI / 180;
    //il movimento si scompone della sua parte s_x e s_y
    //prima erano float e round();
    double s_x = this->speed * (cos(angolo));
    double s_y = this->speed * (sin(angolo));
    //a cui viene opportunamente aggiunto le coordinate iniziali
    this->setX_origine(this->getX_origine() + (float)s_x);
    //la y va nella direzione opposta
    this->setY_origine(this->getY_origine() - (float)s_y);
}
