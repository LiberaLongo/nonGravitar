//codice navicella
#include "../header/Navicella.hpp"

//#define DEBUG

extern float WIDTH, HEIGHT;

//COSTRUTTORI
//costruttore void
Navicella::Navicella(void)
{
    //default tutto
}
//costruttori punto
Navicella::Navicella(Punto centro)
{
    this->dir.setOrigine(centro);
    //default size, dir, carburante
}
Navicella::Navicella(float x, float y)
{
    this->dir.setOrigine(x, y);
    //default size, dir, carburante
}
//costruttori completi
Navicella::Navicella(Direzione dir, Fuel carburante, float size)
{
    this->dir = dir;
    this->carburante = carburante;
    this->size = size;
}
Navicella::Navicella(float x, float y, float angle, float speed, float carburante, float size)
{
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
    this->dir.setX_origine(x);
}
void Navicella::setY(float y)
{
    this->dir.setY_origine(y);
}
void Navicella::setCoord(float x, float y)
{
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
    return this->dir.getX_origine();
}
float Navicella::getY(void)
{
    return this->dir.getY_origine();
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
    cout << "Navicella : { ";
    this->dir.print();
    this->carburante.print();
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
}
void Navicella::shoot(Punto mouseclick) {
    this->dir.shoot(mouseclick);
}
bool Navicella::isNear(Pianeta planet) {
    return this->dir.isNear(planet.getX(), planet.getY(), planet.getRaggio());
}
bool Navicella::isOutsideScreen(void) {
    return !this->dir.isNear(WIDTH/2, HEIGHT/2, WIDTH/2, HEIGHT/2);
}