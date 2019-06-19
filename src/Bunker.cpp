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
}
//costruttore minimale
Bunker::Bunker(Punto centro)
{
    this->centro = centro;
    this->aggiornaCentriDirezione(this->headDirezioni);
}
Bunker::Bunker(float x, float y)
{
    this->centro.setCoord(x, y);
    this->aggiornaCentriDirezione(this->headDirezioni);
}
//costruttore completo
Bunker::Bunker(Punto centro, float angolo, float speed, float size, Lista<Direzione> headDir)
{
    this->centro = centro;
    this->angolo = angolo;
    this->speed = speed;
    this->size = size;
    this->aggiornaCentriDirezione(headDir);
}
Bunker::Bunker(float x, float y, float angolo, float speed, float size, Lista<Direzione> headDir)
{
    this->centro.setCoord(x, y);
    this->angolo = angolo;
    this->speed = speed;
    this->size = size;
    this->aggiornaCentriDirezione(headDir);
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
    cout << "Bunker : [ centro = ";
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
void Bunker::drawProiettili(sf::RenderWindow &window) {
    this->proiettili.draw(window);
}

//disegna
void Bunker::draw(sf::RenderWindow &window)
{
    //codice per disegnare in seguito
    sf::CircleShape triangolo(this->size, 3);

    //colore rosso
    triangolo.setFillColor(sf::Color::Red);

    //ruota di angolo, PRIMA! della rotazione
    float angolo = angoloLibreria(this->angolo);
    triangolo.setRotation(angolo);

    //spostala  posizione effettiva del centro
    triangolo.setPosition(this->getX(), this->getY());

    //disegna sulla window passata per riferimento
    window.draw(triangolo);
}

//spara
void Bunker::shoot(sf::Time tempo)
{
    //inserisci un nuovo colpo da aggiornare
}

//aggiorno la lista di proiettili
void Bunker::aggiornaCoordinateProiettili(sf::Time tempo)
{
    //
}