//codice bunker
#include "../header/Bunker.hpp"

//costruttore vuoto
Bunker::Bunker(void)
{
    //tutto di default
    this->tipo = rand() % 2;
}
//costruttore minimale
Bunker::Bunker(Punto centro, float angolo) : Entity(centro)
{
    this->setAngolo(angolo);
    this->tipo = rand() % 2;
}
Bunker::Bunker(float x, float y, float angolo) : Entity(x, y)
{
    this->setAngolo(angolo);
    this->tipo = rand() % 2;
}
//costruttore completo
Bunker::Bunker(Punto centro, float angolo, float speed, float size, Lista<Direzione> headDir) : Entity(centro, angolo, speed, size)
{
    this->tipo = rand() % 2;
    //head dir
}
Bunker::Bunker(float x, float y, float angolo, float speed, float size, Lista<Direzione> headDir) : Entity(x, y, angolo, speed, size)
{
    this->tipo = rand() % 2;
    //head dir
}

//distruttore
/*virtual*/ Bunker::~Bunker(void)
{
    //distruttore di default
}

//setters

//getters
int Bunker::getTipo(void) {
    return this->tipo;
}

//stampa
void Bunker::print(void)
{
    cout << "Bunker : [ tipo = " << this->tipo;
    this->Entity::print();
    this->headDirezioni.print();
    cout << " ]" << endl;
}

//contronto
bool Bunker::confronto(Bunker b)
{
    return (this->getX() == b.getX() && this->getY() == b.getY());
}

//disegna
void Bunker::draw(sf::RenderWindow &window)
{
    ColoreRGB arancio = ColoreRGB(255, 129, 0);
    //codice per disegnare in seguito
    sf::CircleShape triangolo(this->getSize(), 3);

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
    float angolo = angoloLibreria(this->getAngolo());
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
