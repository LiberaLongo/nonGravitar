//codice pianeta
#include "../header/Pianeta.hpp"

//#define DEBUG
#define ORDINA

extern float WIDTH, HEIGHT, SIZE_NAVICELLA;

//COSTRUTTORI
//costruttore void
Pianeta::Pianeta(void)
{
    //genera liste vuote
}
//altri costruttori
Pianeta::Pianeta(float x, float y, float raggio)
{
    this->centro.setCoord(x, y);
    this->raggio = raggio;
}
//non usato, ma simile
Pianeta::Pianeta(Punto centro, float raggio)
{
    this->centro = centro;
    this->raggio = raggio;
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
    this->poligono.setColore(colore);
}
void Pianeta::setColore(int red, int green, int blue)
{
    this->poligono.setColore(red, green, blue);
}
void Pianeta::setAtmosfera(ColoreRGB outline)
{
    this->atmosfera = outline;
}
void Pianeta::setAtmosfera(int red, int green, int blue)
{
    this->atmosfera.setRGB(red, green, blue);
}
//setta la lista
void Pianeta::setSurface(Lista<Punto> listaSurface)
{
    this->poligono.setLista(listaSurface);
}
void Pianeta::setFuel(Lista<Fuel> listaFuel)
{
    this->fuel = listaFuel;
}
void Pianeta::setBunker(Lista<Bunker> listaBunker)
{
    this->bunker = listaBunker;
}
//setta il puntatore della lista
void Pianeta::setHeadSurface(struct Elem<Punto> *headSurface)
{
    this->poligono.setHead(headSurface);
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
    this->poligono.getColoreLib();
}
sf::Color Pianeta::getAtmosferaLib(void)
{
    this->atmosfera.getColorLib();
}
//ottengo il puntatore alla testa, non al primo elemento
struct Elem<Punto> *Pianeta::getHeadSurface(void)
{
    return this->poligono.getHead();
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

//conta i punti della superficie
int
Pianeta::lunghezzaSuperfice(void)
{
    return this->poligono.numPunti();
}
//stampa
void Pianeta::print(void)
{
    cout << "Pianeta : { ";
    cout << "\ncentro = ";
    this->centro.print();
    cout << "\nraggio = " << this->raggio;
    cout << "\ncolore = ";
    this->poligono.printColore();
    cout << "\noutline = ";
    this->atmosfera.print();
    cout << "\nsuperficie";
    this->poligono.print();
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
    float atmosfera = -(this->raggio / 5);
    sf::CircleShape pianeta(this->raggio);
    float x = this->getX() - this->raggio;
    float y = this->getY() - this->raggio;
    pianeta.setPosition(x, y);

    //colore verde
    pianeta.setFillColor(this->getColoreLib());
    //setta un bordo di 10 all'interno del cerchio
    pianeta.setOutlineThickness(atmosfera);
    //colore del bordo giallo
    pianeta.setOutlineColor(this->getAtmosferaLib());

    window.draw(pianeta);
}
void Pianeta::drawVisuale(sf::RenderWindow &window, int length)
{
    this->poligono.draw(window);
    this->fuel.draw(window);
    this->bunker.draw(window);
}

//PRIVATA
void Pianeta::generaBunkerFuel()
{
    Lista<Punto> surface;
    surface.setHead(this->poligono.getHead());
    int numeroFuel = 0, numeroBunker = 0;
    enum
    {
        tipo_niente,
        tipo_fuel,
        tipo_bunker
    };
    Punto p1, p2, pMedio;
    if (!(surface.empty()))
    {
        //primo elemento utile non la sentinella
        struct Elem<Punto> *iter = surface.head();
        struct Elem<Punto> *sentinella = surface.prev(iter);
        //se non vuota e non finita
        while (!(surface.finished(iter)))
        {
            int cosaGenero = rand() % 3;
            //se devo generare qualcosa
            if (cosaGenero != tipo_niente)
            {
                //stampo elemento MODIFICATA!
                p1 = surface.read(iter);
                //se il successivo non è la sentinella
                if (surface.next(iter) != sentinella)
                {
                    p2 = surface.read(surface.next(iter));
                }
                else
                {
                    p2 = surface.read(surface.tail());
                }
                //calcolo il punto medio
                int x_medio = (p1.getX() + p2.getX()) / 2;
                int y_medio = (p1.getY() + p2.getY()) / 2;
                pMedio.setCoord(x_medio, y_medio);
                //se devo generare del fuel e non ho superato il massimo
                if (cosaGenero == tipo_fuel && numeroFuel < MAX_FUEL)
                {
                    //aggiorno il numero di fuel generati
                    numeroFuel++;
#ifdef NOME_PUNTO
                    pMedio.setName("Fuel" + to_string(numeroFuel));
#endif
                    //genero il carburante
                    Fuel metano = Fuel(pMedio);
                    //inserirlo nella lista
                    this->fuel.insert_head(metano);
                }
                //se devo generare un bunker e non ho superato il massimo
                if (cosaGenero == tipo_bunker && numeroBunker < MAX_BUNKER && p1.distance(p2) > SIZE_BUNKER * 2)
                {
                    //calcolo l'angolo...
                    int angolo = p1.calcolaAngolo(p2) + 90.f;
                    //aggiorno il numero di bunker generati
                    numeroBunker++;
#ifdef NOME_PUNTO
                    pMedio.setName("Bunker" + to_string(numeroBunker));
#endif
                    Bunker cannone = Bunker(pMedio, angolo);
                    cannone.genera();
                    //inserirlo nella lista
                    this->bunker.insert_head(cannone);
                }
            }
            //passo al successivo
            iter = surface.next(iter);
        }
    }
}

void Pianeta::genera(void)
{
    this->poligono.genera();
#ifdef ORDINA
    this->poligono.ordina();
#endif
    this->generaBunkerFuel();
}

bool Pianeta::emptyBunker(void)
{
    return this->bunker.empty();
}

//fa sparare i bunker
void Pianeta::shoot(sf::Time tempo)
{
    int millisecondi = tempo.asMilliseconds();
    //se sono passati 300millisecondi dal reset o dal ultimo sparo
    if (millisecondi % SPARA == 0)
    {
        if (!(this->bunker.empty()))
        {
            //primo elemento utile non la sentinella
            struct Elem<Bunker> *iter = this->bunker.head();
            //se non vuota e non finita
            while (!(this->bunker.finished(iter)))
            {
                Bunker cannoneSpara = this->bunker.read(iter);
                cannoneSpara.shoot();
                //passo al successivo
                iter = this->bunker.next(iter);
            }
        }
    }
}

//aggiorna coordinate dei proiettili sparati dai bunker
int Pianeta::aggiornaCoordinateProiettili(sf::Time tempo, float x, float y, int vita)
{
    int millisecondi = tempo.asMilliseconds();
    //se sono passati 300millisecondi dal reset o dal ultimo sparo
    if (millisecondi % AGGIORNA == 0)
    {
        if (!(this->bunker.empty()))
        {
            //primo elemento utile non la sentinella
            struct Elem<Bunker> *iter = this->bunker.head();
            //se non vuota e non finita
            while (!(this->bunker.finished(iter)))
            {
                Bunker cannoneAggiorna = this->bunker.read(iter);
                vita = cannoneAggiorna.aggiornaCoordinateProiettili(x, y, vita);
                //passo al successivo
                iter = this->bunker.next(iter);
            }
        }
    }
    return vita;
}
