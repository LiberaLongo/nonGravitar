//navicella e bunker sono entità
//codice Entity
#include "../header/Entity.hpp"

//#define DEBUG
//#define DEBUG_PROIETTILI

extern float WIDTH, HEIGHT;

//COSTRUTTORI
//costruttore void
Entity::Entity(void)
{
    //default tutto
}
//costruttori Direzione
Entity::Entity(Direzione dir)
{
    this->dir = dir;
    //default size, dir, carburante
}
Entity::Entity(float x, float y)
{
    this->dir.setOrigine(x, y);
    //default size, dir, carburante
}
//costruttori completi

Entity::Entity(Direzione dir, float size, Lista<Proiettile> proiettili) {
    this->dir = dir;
    this->size = size;
    this->proiettili = proiettili;
}
Entity::Entity(float x, float y, float angle, float speed, float size, Lista<Proiettile> proiettili) {
    this->dir.setOrigine(x, y);
    this->dir.setAngolo(angle);
    this->dir.setSpeed(speed);
    this->size = size;
    this->proiettili = proiettili;
}

//distruttore
/*virtual*/ Entity::~Entity(void)
{
    //distruttore vuoto
}

//setters
void Entity::setX(float x)
{
    this->dir.setX_origine(x);
}
void Entity::setY(float y)
{
    this->dir.setY_origine(y);
}
void Entity::setCoord(float x, float y)
{
    this->dir.setOrigine(x, y);
}
void Entity::setAngolo(float angle)
{
    this->dir.setAngolo(angle);
}
void Entity::setSpeed(float speed)
{
    this->dir.setSpeed(speed);
}
void Entity::setSize(float size)
{
    this->size = size;
}

//getters
float Entity::getX(void)
{
    return this->dir.getX_origine();
}
float Entity::getY(void)
{
    return this->dir.getY_origine();
}
float Entity::getAngolo(void)
{
    return this->dir.getAngolo();
}
float Entity::getSpeed(void)
{
    return this->dir.getSpeed();
}
float Entity::getSize(void)
{
    return this->size;
}

//stampa
void Entity::print(void)
{
    cout << "Entity : { ";
    this->dir.print();
    cout << ", size = " << this->size;
    this->proiettili.print();
    cout << " } " << endl;
}

//disegna proiettili (privata)
void Entity::drawProiettili(sf::RenderWindow &window)
{
    this->proiettili.draw(window);
}
//disegna
void Entity::draw(sf::RenderWindow &window)
{
//si disegnano in modo diverso
}
void Entity::shoot(Punto mouseclick)
{
    //aggiorna la direzione a cui punta la Entity
    this->dir.shoot(mouseclick);
    //inserisco un proiettile nella lista
    ColoreRGB giallo = ColoreRGB(LUMUS_MAXIMA, LUMUS_MAXIMA, 0);
    Proiettile newProiettile = Proiettile(this->getX(), this->getY(), this->getAngolo(), giallo);
    this->proiettili.insert_head(newProiettile);
}
bool Entity::isOutsideScreen(void)
{
    return !this->dir.isNear(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT / 2);
}

//aggiorno la lista di proiettili
void Entity::aggiornaCoordinateProiettili(sf::Time tempo)
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