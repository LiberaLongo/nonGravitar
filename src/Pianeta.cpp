//codice pianeta
#include "../header/Pianeta.hpp"

//#define DEBUG

//COSTRUTTORI
//costruttore void
Pianeta::Pianeta(void)
{
    //genera liste?
}
//costruttori punto
Pianeta::Pianeta(Punto centro)
{
    this->centro = centro;
    //raggio di default
}
Pianeta::Pianeta(float x, float y)
{
    this->centro.setCoord(x, y);
    //raggio di default
}
//costruttori completi
Pianeta::Pianeta(Punto centro, float raggio, ListaClasse<Punto> listaSurface, ListaClasse<Fuel> listaFuel, ListaClasse<Bunker> listaBunker)
{
    this->centro = centro;
    this->raggio = raggio;
    this->surface = listaSurface;
    this->fuel = listaFuel;
    this->bunker = listaBunker;
}
Pianeta::Pianeta(float x, float y, float raggio, ListaClasse<Punto> listaSurface, ListaClasse<Fuel> listaFuel, ListaClasse<Bunker> listaBunker)
{
    this->centro.setCoord(x, y);
    this->raggio = raggio;
    this->surface = listaSurface;
    this->fuel = listaFuel;
    this->bunker = listaBunker;
}
//distruttori
/*virtual*/ Pianeta::~Pianeta(void)
{
    //distruttore vuoto
}
//SETTERS
void Pianeta::setX(float x)
{
    this->centro.setX(x);
}
void Pianeta::setY(float y)
{
    this->centro.setY(y);
}
void Pianeta::setCoord(float x, float y)
{
    this->centro.setCoord(x, y);
}
void Pianeta::setRaggio(float raggio)
{
    this->raggio = raggio;
}
//setta la lista
void Pianeta::setSurface(ListaClasse<Punto> listaSurface)
{
    this->surface = listaSurface;
}
void Pianeta::setFuel(ListaClasse<Fuel> listaFuel)
{
    this->fuel = listaFuel;
}
void Pianeta::setBunker(ListaClasse<Bunker> listaBunker)
{
    this->bunker = listaBunker;
}
//setta il puntatore della lista
void Pianeta::setHeadSurface(struct Elem<Punto> *headSurface)
{
    this->surface.setHead(headSurface);
}
void Pianeta::setHeadFuel(struct Elem<Fuel> *headFuel)
{
    this->fuel.setHead(headFuel);
}
void Pianeta::setHeadBunker(struct Elem<Bunker> *headBunker)
{
    this->bunker.setHead(headBunker);
}
//getters
float Pianeta::getX(void)
{
    return this->centro.getX();
}
float Pianeta::getY(void)
{
    return this->centro.getY();
}
float Pianeta::getRaggio(void)
{
    return this->raggio;
}
//ottengo il puntatore alla testa, non al primo elemento
struct Elem<Punto> *Pianeta::getHeadSurface(void)
{
    return this->surface.getHead();
}
//
struct Elem<Fuel> *
Pianeta::getHeadFuel(void)
{
    return this->fuel.getHead();
}
//
struct Elem<Bunker> *
Pianeta::getHeadBunker(void)
{
    return this->bunker.getHead();
}
//stampa
void
Pianeta::print(void)
{
    cout << "Pianeta : { centro = ";
    this->centro.print();
    cout << ", raggio = " << this->raggio << endl;
    cout << "superficie";
    this->surface.print();
    cout << "carburante";
    this->fuel.print();
    cout << "bunker";
    this->bunker.print();
    cout << " }" << endl;
}
//confronto
bool Pianeta::confronto(Pianeta p)
{
    return (this->getX() == p.getX() && this->getY() == p.getY());
}
//disegna
void Pianeta::draw(sf::RenderWindow &window)
{
    sf::CircleShape pianeta(this->raggio);
    float x = this->getX() - this->raggio;
    float y = this->getY() - this->raggio;
    pianeta.setPosition(x, y);

    //colore verde
    pianeta.setFillColor(sf::Color(100, 250, 50));
    //setta un bordo di 10 all'interno del cerchio
    pianeta.setOutlineThickness(-10.f);
    //colore del bordo giallo
    pianeta.setOutlineColor(sf::Color(250, 0, 0));

    window.draw(pianeta);
}
void Pianeta::drawVisuale(sf::RenderWindow &window)
{
    //deve disegnare la visuale pianeta
    //il che implica che scorre le liste e disegna le varie cose
    //e per la superficie inserisce (preferibilmente in maniera ordinata)
    //i punti in una convex o in un poligono
}
//generaPianeta(void);
void Pianeta::genera(void)
{
    //genera tutti i pianeti all'inizio o man mano?
    for( int i = 0; i < MAX_PLANET ; i++) {
        //numero random per le coordinate
        float x = 0.f, y = 0.f;
        x = rand() % ((int)WIDTH);    //tra 0.f e WIDTH
        y = rand() % ((int)HEIGHT);   //tra 0.f e HEIGHT
        //costruisci pianeta
        Punto p = Punto(x, y);

        #ifdef DEBUG
            p.print();
            cout << "\t";
        #endif
        //inserirlo nella lista
        this->surface.insert_head(p);
    }
}
//altre cose