//codice navicella
#include "../header/Navicella.hpp"

//#define DEBUG
//#define DEBUG_PROIETTILI

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
    //default tutto
    this->setCoord(centro.getX(), centro.getY());
}
Navicella::Navicella(float x, float y)
{
    //default tutto
    this->setCoord(x, y);
}
//costruttori completi
Navicella::Navicella(Direzione dir, Fuel carburante, float size) : Entity(dir)
{
    this->carburante = carburante;
    this->setSize(size);
}
Navicella::Navicella(float x, float y, float angolo, float speed, float size, float carburante) : Entity(x, y, angolo, speed, size)
{
    this->carburante.setQuantita(carburante);
}

//distruttore
/*virtual*/ Navicella::~Navicella(void)
{
    //distruttore vuoto
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

void Navicella::shoot(Punto mouseclick)
{
    ColoreRGB giallo = ColoreRGB(LUMUS_MAXIMA, LUMUS_MAXIMA, 0);
    //chiamo la shoot del padre Entity
    this->Entity::shoot(mouseclick, giallo);
}

bool Navicella::isNear(Pianeta planet)
{
    return this->Entity::isNear(planet.getX(), planet.getY(), planet.getRaggio());
}