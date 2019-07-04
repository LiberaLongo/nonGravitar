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
Navicella::Navicella(float x, float y) : Entity(x, y, SIZE_NAVICELLA)
{
    //default tutto
}
//non usato, ma simile
Navicella::Navicella(Punto centro) : Entity(centro, SIZE_NAVICELLA)
{
    //default tutto
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
void Navicella::move(float angle)
{
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

void Navicella::muori(void)
{
    this->vita--;
}

//restituisce true se il pianeta deve essere distrutto
void Navicella::aggiornaCoordinateProiettili(sf::Time tempo, struct Elem<Bunker> *headEntita)
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
#ifdef DEBUG_PROIETTILI
                    cout << "un proiettile è uscito" << endl;
#endif
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
                            //passo al successivo
                            iterEntita = listaEntita.next(iterEntita);
                        }
                    }
                    /*
                    else
                    {
                        cout << "lista bunker vuota\n";
                        //se la lista di bunker è vuota devo distruggere il pianeta
                        return true;
                    }
                    */

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
    /*
    //non devo ancora distruggere il pianeta
    return false;
    */
}
