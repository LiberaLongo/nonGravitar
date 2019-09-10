//codice bunker
#include "../header/Bunker.hpp"

//costruttore vuoto
Bunker::Bunker(void)
{
    //tutto di default
    this->tipo = rand() % 2;
}
//altri costruttori
Bunker::Bunker(Punto centro, float angolo) : Entity(centro, SIZE_BUNKER)
{
    this->setAngolo(angolo);
    this->tipo = rand() % 2;
}
//non usato, ma simile
Bunker::Bunker(float x, float y, float angolo) : Entity(x, y, SIZE_BUNKER)
{
    this->setAngolo(angolo);
    this->tipo = rand() % 2;
}

//setters

//getters
int Bunker::getTipo(void)
{
    return this->tipo;
}

//stampa
void Bunker::print(void)
{
    cout << "Bunker : [ tipo = " << this->tipo;
    this->Entity::print();
    for (int i = 0; i < MAX_DIREZIONI; i++) {
        this->direzioni[i].print();
    }
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
    //centro iniziale della figura prima di fare setPosition
    float x = 0.f, y = 0.f; //centro: (0,0)
    float size = this->getSize();
    //crea una empty shape convex con 3 punti
    sf::ConvexShape triangolo;
    triangolo.setPointCount(3);
    //definisci i punti rispetto a (0,0)
    triangolo.setPoint(0, sf::Vector2f(x, y - size)); //(x, y - altezza)
    triangolo.setPoint(1, sf::Vector2f(x - size, y));
    triangolo.setPoint(2, sf::Vector2f(x + size, y));
    //sf::CircleShape triangolo(this->getSize(), 3);

    //colore rosso se di tipo 0 arancione se di tipo 1
    switch (this->tipo)
    {
    case 0: //2 direzioni
        triangolo.setFillColor(arancio.getColorLib());
        break;
    case 1: //3 direzioni
        triangolo.setFillColor(sf::Color::Red);
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
    this->drawProiettili(window);
    window.draw(triangolo);
}

//genera
void Bunker::genera(void)
{
    //in base al tipo riempi la lista con 2 o 3 direzioni
    //i = 0 left, i = 1 right (i=2 centro)
    for (int i = -1 ; i < (this->tipo + 1)*2; i += 2)
    {
        //calcolo l'angolo generando bene solo sinistra e destra
        float angolo = this->getAngolo() + i * ANGOLO_BUNKER;
        Direzione dirCannoni = Direzione(this->getX(), this->getY(), angolo);
        //se sto generando la 3a direzione risetto all'angolo mettendolo centrale
        if (i == 3)
        {
            dirCannoni.setAngolo(this->getAngolo());
        }
        this->direzioni[(i+1)/2] = dirCannoni;
    }
}

//spara
void Bunker::shoot(void)
{
    ColoreRGB giallo = ColoreRGB(LUMUS_MAXIMA, LUMUS_MAXIMA, 0);
    //genero una direzione random dipendente dal tipo
    int randomDir = randomInt(0, this->tipo+1);
    Direzione dirInCuiSparo = this->direzioni[randomDir];
    //inserisci un nuovo colpo da aggiornare
    Proiettile newProiettile = Proiettile(dirInCuiSparo, giallo);
    this->proiettili.insert_head(newProiettile);
}
