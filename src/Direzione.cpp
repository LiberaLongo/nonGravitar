//codice punti
#include "../header/Direzione.hpp"

#define DEBUG

//costruttore vuoto
Direzione::Direzione(void)
{
    //cose di default
}
//costruttore minimale
Direzione::Direzione(Punto origine)
{
    this->origine = origine;
    //default angolo e speed
}
Direzione::Direzione(float x, float y)
{
    this->origine.setCoord(x, y);
    //default angolo e speed
}
//costruttore completo
Direzione::Direzione(Punto origine, float angolo, float speed)
{
    this->origine = origine;
    this->angolo = angolo;
    this->speed = speed;
}
Direzione::Direzione(float x, float y, float angolo, float speed)
{
    this->origine.setCoord(x, y);
    this->angolo = angolo;
    this->speed = speed;
}

//distruttore
/*virtual*/ Direzione::~Direzione(void)
{
    //distruttore di default
}

//setters
void Direzione::setXOrigine(float x)
{
    this->origine.setX(x);
}
void Direzione::setYOrigine(float y)
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
    //tangente(AB) = (xB - xA ) / (yB - yA);
    float deltaX = arrivo.getX() - this->getXOrigine();
    float deltaY = arrivo.getY() - this->getYOrigine();
    float tangente = deltaX / deltaY;
    double angoloRadianti = atan(tangente);
    float angoloGradi = angoloRadianti * 180 / M_PI;
#ifdef DEBUG
    cout << "deltaX = " << arrivo.getX() << " - " << this->getXOrigine() << " = " << deltaX << endl;
    cout << "deltaY = " << arrivo.getY() << " - " << this->getYOrigine() << " = " << deltaY << endl;
    cout << "tangente = " << tangente << endl;
    cout << "angoloRadianti = " << angoloRadianti << endl;
    cout << "angoloGradi = "<< angoloGradi << endl;
#endif
    this->angolo = (float)angoloGradi;
}
//getters
float Direzione::getXOrigine(void)
{
    return this->origine.getX();
}
float Direzione::getYOrigine(void)
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
    return (this->getXOrigine() == dir.getXOrigine() && this->origine.getY() == dir.getYOrigine() && this->speed == dir.getSpeed() && this->angolo == dir.getAngolo());
}

//disegna
void Direzione::draw(sf::RenderWindow &window)
{
    sf::RectangleShape line(sf::Vector2f(5.f, -150.f));
    line.setPosition(this->getXOrigine(), this->getYOrigine());
    line.rotate(this->angolo);
    window.draw(line);
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
#ifdef DEBUG
    this->print();
    cout << "s_x = [speed = " << this->speed << "]*[cos(" << this->angolo << " gradi) = " << (cos(angolo)) << "] = " << s_x << endl;
    cout << "s_y = [speed = " << this->speed << "]*[sin(" << this->angolo << " gradi) = " << (sin(angolo)) << "] = " << s_y << endl;
#endif
    //a cui viene opportunamente aggiunto (o sottratto) le coordinate iniziali
    this->setXOrigine(this->getXOrigine() + (float)s_x);
    this->setYOrigine(this->getYOrigine() - (float)s_y);
#ifdef DEBUG
    this->print();
    cout << endl;
#endif
}

void Direzione::shoot(Punto mouseclick)
{
    this->setAngolo(mouseclick);
    //se abbiamo bisogno restituiamo l'angolo
}