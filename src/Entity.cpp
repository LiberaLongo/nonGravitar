//navicella e bunker sono entità
//codice Entity
#include "../header/Entity.hpp"

//#define DEBUG
//#define DEBUG_PROIETTILI

extern float WIDTH, HEIGHT;

//costruttore vuoto
Entity::Entity(void)
{
    //default tutto
}
//altri costruttori
Entity::Entity(Punto centro, float size)
{
    //default tutto
    this->dir.setOrigine(centro.getX(), centro.getY());
    this->size = size;
}

Entity::Entity(float x, float y, float size)
{
    //default tutto
    this->dir.setOrigine(x, y);
    this->size = size;
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
void Entity::setAngolo(Punto mouseclick)
{
    this->dir.setAngolo(mouseclick);
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
void Entity::move(void)
{
    //WASD
    this->dir.move();
}

void Entity::shoot(ColoreRGB colore)
{
    //creo un nuovo proiettile e lo aggiungo alla lista
    Proiettile newProiettile = Proiettile(this->getX(), this->getY(), this->getAngolo(), colore);
    this->proiettili.insert_head(newProiettile);
}
void Entity::shoot(Punto mouseclick, ColoreRGB colore)
{
    //aggiorna la direzione a cui punta la Entity
    this->setAngolo(mouseclick);
    //e spara
    this->shoot(colore);
}

bool Entity::isNear(float x, float y, float size)
{
    return this->dir.isNear(x, y, size);
}

bool Entity::isOutsideScreen(void)
{
    return !this->dir.isNear(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT / 2);
}

//aggiorno la lista di proiettili
int Entity::aggiornaCoordinateProiettili(float x, float y, int vita, Poligono pol, int n)
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
                iter = this->proiettili.remove(iter);
#ifdef DEBUG_PROIETTILI
                cout << "uscito" << endl;
#endif
            }
            if (aggiornato.isInsidePlanet(pol, n))
            {
                //se il proiettile è entrato nel pianeta devo rimuoverlo
                iter = this->proiettili.remove(iter);
#ifdef DEBUG_PROIETTILI
                cout << "entrato nel pianeta" << endl;
#endif
            }
            else
            {
                Punto centroProiettile = Punto(aggiornato.getX(), aggiornato.getY());
                if (centroProiettile.isNear(x, y, SIZE_NAVICELLA))
                {
                    //rimuovo il proiettile se il bunker colpisce la navicella
                    iter = this->proiettili.remove(iter);
                    //faccio scendere la vita della navicella
                    vita--;
#ifdef DEBUG_PROIETTILI
                    cout << "un proiettile ha colpito la navicella" << endl;
#endif
                }
                else
                {
                    //aggiorno il proiettile
                    this->proiettili.write(iter, aggiornato);
                    //passo al successivo
                    iter = this->proiettili.next(iter);
                }
            }
        }
    }
    return vita;
}
