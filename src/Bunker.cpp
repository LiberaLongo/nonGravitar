//codice bunker
#include "../header/Bunker.hpp"

//metodo per scorrere la lista e aggiornare i centri
void Bunker::aggiornaCentriDirezione(Lista<Direzione> headDir)
{
    if (!(headDir.empty()))
    {
        //primo elemento utile non la sentinella
        struct Elem<Direzione> *iter = headDir.head();
        //se non vuota e non finita
        while (!(headDir.finished(iter)))
        {
            //stampo elemento MODIFICATA!
            Direzione aggiornato = headDir.read(iter);
            aggiornato.setOrigine(this->centro.getX(), this->centro.getY());
            //passo al successivo e stampo freccia
            iter = headDir.next(iter);
        }
    }
    this->headDirezioni.setHead(headDir.getHead());
}

//costruttore vuoto
Bunker::Bunker(void)
{
    //tutto di default
    this->tipo = rand() % 2;
}
//costruttore minimale
Bunker::Bunker(Punto centro, float angolo)
{
    this->centro = centro;
    this->angolo = angolo;
    this->aggiornaCentriDirezione(this->headDirezioni);
    this->tipo = rand() % 2;
}
Bunker::Bunker(float x, float y, float angolo)
{
    this->centro.setCoord(x, y);
    this->aggiornaCentriDirezione(this->headDirezioni);
    this->angolo = angolo;
    this->tipo = rand() % 2;
}
//costruttore completo
Bunker::Bunker(Punto centro, float angolo, float speed, float size, Lista<Direzione> headDir)
{
    this->centro = centro;
    this->angolo = angolo;
    this->speed = speed;
    this->size = size;
    this->aggiornaCentriDirezione(headDir);
    this->tipo = rand() % 2;
}
Bunker::Bunker(float x, float y, float angolo, float speed, float size, Lista<Direzione> headDir)
{
    this->centro.setCoord(x, y);
    this->angolo = angolo;
    this->speed = speed;
    this->size = size;
    this->aggiornaCentriDirezione(headDir);
    this->tipo = rand() % 2;
}

//distruttore
/*virtual*/ Bunker::~Bunker(void)
{
    //distruttore di default
}

//setters
void Bunker::setX(float x)
{
    this->centro.setX(x);
    this->aggiornaCentriDirezione(this->headDirezioni);
}
void Bunker::setY(float y)
{
    this->centro.setY(y);
    this->aggiornaCentriDirezione(this->headDirezioni);
}
void Bunker::setCoord(float x, float y)
{
    this->centro.setCoord(x, y);
    this->aggiornaCentriDirezione(this->headDirezioni);
}
void Bunker::setAngolo(float angolo)
{
    this->angolo = angolo;
}
void Bunker::setSpeed(float speed)
{
    this->speed = speed;
}
void Bunker::setSize(float size)
{
    this->size = size;
}
int Bunker::getTipo(void) {
    return this->tipo;
}
//getters
float Bunker::getX(void)
{
    return this->centro.getX();
}
float Bunker::getY(void)
{
    return this->centro.getY();
}
float Bunker::getAngolo(void)
{
    return this->angolo;
}
float Bunker::getSpeed(void)
{
    return this->speed;
}
float Bunker::getSize(void)
{
    return this->size;
}

//stampa
void Bunker::print(void)
{
    cout << "Bunker : [ tipo = " << this->tipo;
    cout << "centro = ";
    this->centro.print();
    cout << ", angolo = " << this->angolo;
    cout << ", speed = " << this->speed;
    cout << ", size = " << this->size;
    this->headDirezioni.print();
    cout << " ]" << endl;
}

//contronto
bool Bunker::confronto(Bunker b)
{
    return (this->getX() == b.getX() && this->getY() == b.getY() && this->size == b.getSize() && this->angolo == b.getAngolo() && this->speed == b.getSpeed());
}

//disegna proiettili (privata)
void Bunker::drawProiettili(sf::RenderWindow &window)
{
    this->proiettili.draw(window);
}

//disegna
void Bunker::draw(sf::RenderWindow &window)
{
    ColoreRGB arancio = ColoreRGB(255, 129, 0);
    //codice per disegnare in seguito
    sf::CircleShape triangolo(this->size, 3);

    //colore rosso se di tipo 0 arancione se di tipo 1
    switch(this->tipo) {
        case 0:
            triangolo.setFillColor(sf::Color::Red);
            break;
        case 1:
            triangolo.setFillColor(arancio.getColorLib());
            break;
        default:
            cout << "\nil tipo = " << this->tipo << " del bunker non ha senso\n";
            break;
    }

    //ruota di angolo, PRIMA! della rotazione
    float angolo = angoloLibreria(this->angolo);
    triangolo.setRotation(angolo);

    //spostala  posizione effettiva del centro
    triangolo.setPosition(this->getX(), this->getY());

    //disegna sulla window passata per riferimento
    window.draw(triangolo);
}

//genera
void Bunker::genera(void)
{
    //in base al tipo riempi la lista con 2 o 3 direzioni
}

//spara
void Bunker::shoot(sf::Time tempo)
{
    //inserisci un nuovo colpo da aggiornare
    /*
    //aggiorna la direzione a cui punta la navicella
    this->dir.shoot(mouseclick);
    //inserisco un proiettile nella lista
    ColoreRGB giallo = ColoreRGB(LUMUS_MAXIMA, LUMUS_MAXIMA, 0);
    Proiettile newProiettile = Proiettile(this->getX(), this->getY(), this->getAngolo(), giallo);
    this->proiettili.insert_head(newProiettile);
*/
}

//aggiorno la lista di proiettili
void Bunker::aggiornaCoordinateProiettili(sf::Time tempo)
{
    int millisecondi = tempo.asMilliseconds();
    //se sono passati 100millisecondi dal reset o dal ultimo aggiorna
    if (millisecondi % AGGIORNA == 0)
    {
        if (!(this->proiettili.empty()))
        {
            //primo elemento utile non la sentinella
            struct Elem<Proiettile> *iter = this->proiettili.head();
            //se non vuota e non finita
            while (!(this->proiettili.finished(iter)))
            {
                //leggo il proiettile
                Proiettile aggiornato = this->proiettili.read(iter);
                aggiornato.move();
                if (aggiornato.isOutsideScreen())
                {
                    //se il proiettile è uscito dallo schermo devo rimuoverlo
                    this->proiettili.remove(iter);
#ifdef DEBUG_PROIETTILI
                    cout << "un proiettile è uscito" << endl;
#endif
                }
                else
                {
                    this->proiettili.write(iter, aggiornato);
                }

                //passo al successivo
                iter = this->proiettili.next(iter);
            }
        }
    }
}