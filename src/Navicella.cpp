#include "../header/Navicella.hpp"

extern float WIDTH, HEIGHT, SIZE_NAVICELLA;

//PRIVATE
void Navicella::aggiornaCentroRaggioTraente(void)
{
    //calcoli per il centro del raggio traente
    //l'angolo punta nel senso opposto dell'angolo della navicella
    float angolo = this->getAngolo() + 180.f;
    //rendo l'angolo comprensibile alle funzioni di cmath
    angolo = (double)angolo * M_PI / 180;
    //calcolo la distanza relativa
    double r_x = this->distanzaNavicellaRaggio * (cos(angolo));
    double r_y = this->distanzaNavicellaRaggio * (sin(angolo));
    //cout << "r_x = " << r_x << ", r_y = " << r_y << endl;
    //aggiorno il centro
    this->centroRaggioTraente.setX(this->getX() + (float)r_x);
    this->centroRaggioTraente.setY(this->getY() - (float)r_y);
}

//PUBBLICHE
//costruttore vuoto
Navicella::Navicella(void)
{
    //default tutto
    Entity::setSize(SIZE_NAVICELLA);
    this->setFuel(FUEL_NAVICELLA);
}
//altri costruttori
Navicella::Navicella(float x, float y) : Entity(x, y, SIZE_NAVICELLA)
{
    //default tutto
    this->setFuel(FUEL_NAVICELLA);
}
//non usato, ma simile
Navicella::Navicella(Punto centro) : Entity(centro, SIZE_NAVICELLA)
{
    //default tutto
    this->setFuel(FUEL_NAVICELLA);
}

//setters
void Navicella::setFuel(int quantita)
{
    this->carburante.setQuantita(quantita);
}
void Navicella::setVita(int vita)
{
    this->vita = vita;
}
//getters
int Navicella::getFuel(void)
{
    return this->carburante.getQuantita();
}
int Navicella::getVita(void)
{
    return this->vita;
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
    //spostala  posizione effettiva del centro
    triangolo.setPosition(this->getX(), this->getY());

    //i proiettilo sono disegnati prima della navicella
    this->drawProiettili(window);
    //disegna la navicella
    window.draw(triangolo);
}

void Navicella::drawRaggioTraente(sf::RenderWindow &window)
{
    //disegna raggio traente
    sf::CircleShape cerchioRaggioTraente(this->distanzaNavicellaRaggio);
    //viola
    ColoreRGB viola = ColoreRGB(128, 0, 255);
    cerchioRaggioTraente.setFillColor(viola.getColorLib());
    //posizione (ricordo che se disegno un cerchio a 0,0 questo ha il centro a raggio,raggio)
    float x = this->centroRaggioTraente.getX() - this->distanzaNavicellaRaggio;
    float y = this->centroRaggioTraente.getY() - this->distanzaNavicellaRaggio;
    cerchioRaggioTraente.setPosition(sf::Vector2f(x, y));
    //disegno
    window.draw(cerchioRaggioTraente);
}
void Navicella::draw(sf::RenderWindow &window, bool raggio)
{
    if (raggio)
    {
        //this->aggiornaCentroRaggioTraente();
        this->drawRaggioTraente(window);
    }
    this->draw(window);
}

//controlli di movimento
bool Navicella::move(void)
{
    this->Entity::move();
    return this->carburante.consumoFuel();
}
bool Navicella::move(float angle)
{
    this->setAngolo(angle);
    return this->move();
}
//spara
bool Navicella::shoot(void)
{
    //chiamo la shoot del padre Entity
    this->Entity::shoot(this->coloreProiettile);
    return this->carburante.consumoFuel();
}

bool Navicella::shoot(Punto mouseclick)
{
    //chiamo la shoot del padre Entity
    this->Entity::shoot(mouseclick, this->coloreProiettile);
    return this->carburante.consumoFuel();
}

bool Navicella::isNear(Pianeta planet)
{
    return this->Entity::isNear(planet.getX(), planet.getY(), planet.getRaggio());
}

//restituisce true se il pianeta deve essere distrutto
void Navicella::aggiornaCoordinateProiettili(sf::Time tempo, struct Elem<Bunker> *headEntita, Poligono pol, int n)
{
    Lista<Bunker> listaEntita;
    listaEntita.setHead(headEntita);

    int millisecondi = tempo.asMilliseconds();
    //se sono passati 100millisecondi dal reset o dal ultimo aggiorna
    if (millisecondi % AGGIORNA == 0)
    {
        if (!(this->proiettili.empty()))
        {
            //primo elemento utile non la sentinella
            struct Elem<Proiettile> *iterProiettile = this->proiettili.head();
            //se non vuota e non finita
            while (!(this->proiettili.finished(iterProiettile)))
            {

                //leggo il proiettile
                Proiettile aggiornato = this->proiettili.read(iterProiettile);
                aggiornato.move();

                if (aggiornato.isOutsideScreen())
                {
                    //se il proiettile è uscito dallo schermo devo rimuoverlo
                    iterProiettile = this->proiettili.remove(iterProiettile);
                }                
                if (aggiornato.isInsidePlanet(pol, n))
                {
                    //se il proiettile è entrato nel pianeta devo rimuoverlo
                    iterProiettile = this->proiettili.remove(iterProiettile);
                }
                else
                {
                    bool colpitoQualcosa = false;
                    //controllo se il proiettile è troppo vicino al centro di un altra entità

                    if (!listaEntita.empty())
                    {
                        //primo elemento utile non la sentinella
                        struct Elem<Bunker> *iterEntita = listaEntita.head();
                        while (!(listaEntita.finished(iterEntita) || colpitoQualcosa))
                        {
                            float size;
                            Bunker controllataEntita = listaEntita.read(iterEntita);
                            Punto centroEntita = Punto(controllataEntita.getX(), controllataEntita.getY());
                            Punto centroProiettile = Punto(aggiornato.getX(), aggiornato.getY());
                            if (centroProiettile.isNear(centroEntita, this->getSize()))
                            {
                                colpitoQualcosa = true;
                                //rimuovo il proiettile
                                iterProiettile = this->proiettili.remove(iterProiettile);
                                //rimuovo il bunker
                                iterEntita = listaEntita.remove(iterEntita);
                            }
                            else
                            {
                                //passo al successivo
                                iterEntita = listaEntita.next(iterEntita);
                            }
                        }
                    }

                    if (!colpitoQualcosa)
                    {
                        this->proiettili.write(iterProiettile, aggiornato);
                        //passo al successivo
                        iterProiettile = this->proiettili.next(iterProiettile);
                    }
                }
            }
        }
    }
}

void Navicella::raggioTraente(struct Elem<Fuel> *headFuel)
{
    //lista di fuel per fare le operazioni
    Lista<Fuel> listaFuel;
    listaFuel.setHead(headFuel);
    if (!listaFuel.empty())
    {
        //se trovo il fuel corrispondente non devo cercare gli altri
        bool trovato = false;
        aggiornaCentroRaggioTraente();
        //primo elemento utile non la sentinella
        struct Elem<Fuel> *iter = listaFuel.head();
        //se non vuota e non finita
        while (!(listaFuel.finished(iter) || trovato))
        {
            //leggo il fuel
            Fuel controllato = listaFuel.read(iter);
            //calcolo il centro
            Punto centroFuel = Punto(controllato.getX(), controllato.getY());
            if (this->centroRaggioTraente.isNear(centroFuel, this->distanzaNavicellaRaggio))
            {
                trovato = true;
                this->setFuel(this->getFuel() + controllato.getQuantita());
                //rimuovo il fuel
                iter = listaFuel.remove(iter);
            }
            else
            {
                //passo al successivo
                iter = listaFuel.next(iter);
            }
        }
    }
}

bool Navicella::isInsidePoligon(Poligono p, int n) {
    return p.PointIsInside(this->getX(), this->getY(), n);
}