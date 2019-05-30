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
//costruttori punto e colore
Pianeta::Pianeta(Punto centro, ColoreRGB colore)
{
    this->centro = centro;
    this->colore = colore;
    //raggio di default
}
Pianeta::Pianeta(float x, float y, int red, int green, int blue)
{
    this->centro.setCoord(x, y);
    this->colore.setRGB(red, green, blue);
    //raggio di default
}
//costruttori punto e colore
Pianeta::Pianeta(Punto centro, ColoreRGB colore, ColoreRGB outline)
{
    this->centro = centro;
    this->colore = colore;
    this->outline = outline;
    //raggio di default
}
Pianeta::Pianeta(float x, float y, int red, int green, int blue, int red_o, int green_o, int blue_o)
{
    this->centro.setCoord(x, y);
    this->colore.setRGB(red, green, blue);
    this->outline.setRGB(red_o, green_o, blue_o);
    //raggio di default
}
//costruttori completi
Pianeta::Pianeta(Punto centro, float raggio, ColoreRGB colore, ColoreRGB outline, ListaClasse<Punto> listaSurface, ListaClasse<Fuel> listaFuel, ListaClasse<Bunker> listaBunker)
{
    this->centro = centro;
    this->raggio = raggio;
    this->outline = outline;
    this->colore = colore;
    this->surface = listaSurface;
    this->fuel = listaFuel;
    this->bunker = listaBunker;
}
Pianeta::Pianeta(float x, float y, float raggio, int red, int green, int blue, int red_o, int green_o, int blue_o, ListaClasse<Punto> listaSurface, ListaClasse<Fuel> listaFuel, ListaClasse<Bunker> listaBunker)
{
    this->centro.setCoord(x, y);
    this->raggio = raggio;
    this->colore.setRGB(red, green, blue);
    this->colore.setRGB(red_o, green_o, blue_o);
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
//cose importanti
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
//colori
void Pianeta::setColore(ColoreRGB colore)
{
    this->colore = colore;
}
void Pianeta::setColore(int red, int green, int blue)
{
    this->colore.setRGB(red, green, blue);
}
void Pianeta::setOutline(ColoreRGB outline)
{
    this->outline = outline;
}
void Pianeta::setOutline(int red, int green, int blue)
{
    this->outline.setRGB(red, green, blue);
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

//GETTERS
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
//colori
sf::Color Pianeta::getColoreLib(void)
{
    this->colore.getColorLib();
}
sf::Color Pianeta::getOutlineLib(void)
{
    this->outline.getColorLib();
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
    cout << "Pianeta : { ";
    cout << "\ncentro = ";
    this->centro.print();
    cout << "\nraggio = " << this->raggio;
    cout << "\ncolore = ";
    this->colore.print();
    cout << "\noutline = ";
    this->outline.print();
    cout << "\nsuperficie";
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
    pianeta.setFillColor(this->getColoreLib());
    //setta un bordo di 10 all'interno del cerchio
    pianeta.setOutlineThickness(-10.f);
    //colore del bordo giallo
    pianeta.setOutlineColor(this->getOutlineLib());

    window.draw(pianeta);
}
void Pianeta::drawVisuale(sf::RenderWindow &window, int length)
{
    //non è l'indice del while, ma l'indice dei punti nella convex!
    int indice = 0;
    //crea una empty shape convex con 3 punti
    sf::ConvexShape convexSuperficie;
    convexSuperficie.setPointCount(length);

    //blu
    convexSuperficie.setFillColor(sf::Color::Blue);

    if (!(this->surface.empty()))
    {
        //primo elemento utile non la sentinella
        struct Elem<Punto> *iter = this->surface.head();
        //se non vuota e non finita
        while (!(this->surface.finished(iter)))
        {
            //stampo elemento MODIFICATA!
            Punto disegnato = this->surface.read(iter);
            //inserisci il punto nella convex shape
            convexSuperficie.setPoint(indice, disegnato.getPuntoLib());
            //passo al successivo e stampo freccia
            iter = this->surface.next(iter);
            indice++;
        }
    }

    //disegna sulla window passata per riferimento
    window.draw(convexSuperficie);
}
//generaPianeta(void);
void Pianeta::genera(void)
{
    //genera tutti i pianeti all'inizio o man mano?
    for (int i = 0; i < MAX_SUPERFICE; i++)
    {
        //numero random per le coordinate
        float x = 0.f, y = 0.f;
        x = rand() % ((int)WIDTH);  //tra 0.f e WIDTH
        y = rand() % ((int)HEIGHT); //tra 0.f e HEIGHT
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