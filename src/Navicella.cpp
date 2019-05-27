//codice navicella
#include "../header/Navicella.hpp"

//#define DEBUG

//COSTRUTTORI
//costruttore void
Navicella::Navicella(void)
{
    //default tutto
}
//costruttori punto
Navicella::Navicella(Punto centro)
{
    this->centro = centro;
    this->dir.setOrigine(centro);
    //default size, dir, carburante
}
Navicella::Navicella(float x, float y)
{
    this->centro.setCoord(x, y);
    this->dir.setOrigine(x, y);
    //default size, dir, carburante
}
//costruttori completi
Navicella::Navicella(Punto centro, Fuel carburante, Direzione dir, float size)
{
    this->centro = centro;
    this->carburante = carburante;
    this->dir = dir;
    this->size = size;
}
Navicella::Navicella(float x, float y, float carburante, float angle, float speed, float size)
{
    this->centro.setCoord(x, y);
    this->carburante.setQuantita(carburante);
    this->dir.setOrigine(x, y);
    this->dir.setAngolo(angle);
    this->dir.setSpeed(speed);
    this->size = size;
}

//distruttore
/*virtual*/ Navicella::~Navicella(void)
{
    //distruttore vuoto
}

//setters
void Navicella::setX(float x)
{
    this->centro.setX(x);
}
void Navicella::setY(float y)
{
    this->centro.setY(y);
}
void Navicella::setCoord(float x, float y)
{
    this->centro.setCoord(x, y);
    this->dir.setOrigine(x, y);
}
void Navicella::setSize(float size)
{
    this->size = size;
}
void Navicella::setAngolo(float angle)
{
    this->dir.setAngolo(angle);
}
void Navicella::setSpeed(float speed)
{
    this->dir.setSpeed(speed);
}
void Navicella::setFuel(Fuel carburante)
{
    this->carburante = carburante;
}

//getters
float Navicella::getX(void)
{
    return this->centro.getX();
}
float Navicella::getY(void)
{
    return this->centro.getY();
}
float Navicella::getSize(void)
{
    return this->size;
}
float Navicella::getAngolo(void)
{
    return this->dir.getAngolo();
}
float Navicella::getSpeed(void)
{
    return this->dir.getSpeed();
}
float Navicella::getFuel(void)
{
    return this->carburante.getQuantita();
}

//stampa
void Navicella::print(void)
{
    cout << "Navicella : { centro = ";
    this->centro.print();
    this->dir.print();
    cout << ", size = " << this->size;
    cout << " } " << endl;
}

//disegna
void Navicella::draw(sf::RenderWindow &window)
{
#ifdef DEBUG
    this->dir.draw(window);
#endif
    
    //centro iniziale della figura prima di fare setPosition
    float x = 0.f, y = 0.f; //centro: (0,0)
    //crea una empty shape convex con 3 punti
    sf::ConvexShape triangolo;
    triangolo.setPointCount(3);
    //definisci i punti rispetto a (0,0)
    triangolo.setPoint(0, sf::Vector2f(x, y - this->size * 3));
    triangolo.setPoint(1, sf::Vector2f(x - this->size, y + this->size));
    triangolo.setPoint(2, sf::Vector2f(x + this->size, y + this->size));
    
    //blu
    triangolo.setFillColor(sf::Color::Blue);
    
    //ruota di angolo, PRIMA! della rotazione
    float angolo = angoloLibreria(this->dir.getAngolo());
    triangolo.setRotation(angolo);
#ifdef DEBUG
    cout << "angoloCanonico = " << this->dir.getAngolo();
    cout << ", angoloSFML = " << angolo; 
#endif
    //spostala  posizione effettiva del centro
    triangolo.setPosition(this->getX(), this->getY());
    
    //disegna sulla window passata per riferimento
    window.draw(triangolo);
}

void Navicella::move(float angolo)
{
    //WASD
    this->dir.setAngolo(angolo);
    this->dir.move();
    this->centro.setCoord(this->dir.getXOrigine(), this->dir.getYOrigine());
}
void Navicella::shoot(Punto mouseclick) {
    this->dir.shoot(mouseclick);
}
bool Navicella::isIn(Pianeta planet) {
    return this->centro.isIn(planet.getX(), planet.getY(), planet.getRaggio());
}