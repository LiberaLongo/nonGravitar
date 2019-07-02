//codice navicella
#include "../header/Navicella.hpp"

//#define DEBUG
//#define DEBUG_PROIETTILI

extern float WIDTH, HEIGHT, SIZE_NAVICELLA;

//costruttore vuoto
Navicella::Navicella(void)
{
    //default tutto
    Entity::setSize(SIZE_NAVICELLA);
}
//altri costruttori
Navicella::Navicella(float x, float y) : Entity(x, y, VITA_NAVICELLA, TIPO_NAVICELLA)
{
    //default tutto
    Entity::setSize(SIZE_NAVICELLA);
}
//non usato, ma simile
Navicella::Navicella(Punto centro) : Entity(centro, VITA_NAVICELLA, TIPO_NAVICELLA)
{
    //default tutto
    Entity::setSize(SIZE_NAVICELLA);
}

//setters
void Navicella::setFuel(Fuel carburante)
{
    this->carburante = carburante;
}

//getters
float Navicella::getFuel(void)
{
    return this->carburante.getQuantita();
}

//stampa
void Navicella::print(void)
{
    cout << "Navicella : { ";
    //chiamo la print del padre Entity
    this->Entity::print();
    this->carburante.print();
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
    float size = this->getSize();
    //crea una empty shape convex con 3 punti
    sf::ConvexShape triangolo;
    triangolo.setPointCount(3);
    //definisci i punti rispetto a (0,0)
    triangolo.setPoint(0, sf::Vector2f(x, y - size * 3));
    triangolo.setPoint(1, sf::Vector2f(x - size, y + size));
    triangolo.setPoint(2, sf::Vector2f(x + size, y + size));

    //blu
    triangolo.setFillColor(sf::Color::Blue);

    //ruota di angolo, PRIMA! della rotazione
    float angolo = angoloLibreria(this->getAngolo());
    triangolo.setRotation(angolo);
#ifdef DEBUG
    cout << "angoloCanonico = " << this->dir.getAngolo();
    cout << ", angoloSFML = " << angolo;
#endif
    //spostala  posizione effettiva del centro
    triangolo.setPosition(this->getX(), this->getY());

    //i proiettilo sono disegnati prima della navicella
    this->drawProiettili(window);
    //disegna la navicella
    window.draw(triangolo);
}

//controlli di movimento
void Navicella::move(float angle) {
    this->setAngolo(angle);
    this->Entity::move();
}

void Navicella::shoot(void)
{
    //chiamo la shoot del padre Entity
    this->Entity::shoot(this->coloreProiettile);
}

void Navicella::shoot(Punto mouseclick)
{
    //chiamo la shoot del padre Entity
    this->Entity::shoot(mouseclick, this->coloreProiettile);
}

bool Navicella::isNear(Pianeta planet)
{
    return this->Entity::isNear(planet.getX(), planet.getY(), planet.getRaggio());
}