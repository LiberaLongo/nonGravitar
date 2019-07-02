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
Entity::Entity(Punto centro, int vita, int tipo)
{
    //default tutto
    this->dir.setOrigine(centro.getX(), centro.getY());
    this->vita = vita;
    this->tipo = tipo;
}

Entity::Entity(float x, float y, int vita, int tipo)
{
    //default tutto
    this->dir.setOrigine(x, y);
    this->vita = vita;
    this->tipo = tipo;
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
int Entity::getVita(void)
{
    return this->vita;
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
    this->dir.setAngolo(mouseclick);
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

void Entity::muori(void)
{
    this->vita--;
}

//aggiorno la lista di proiettili
void Entity::aggiornaCoordinateProiettili(sf::Time tempo, Punto centroNavicella)
{
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
                    Punto centroEntita = Punto (this->getX(), this->getY());
                    if (centroEntita.isNear(centroNavicella, this->size))
                    {
                        //rimuovo il proiettile se il bunker colpisce la navicella
                        iterProiettile = this->proiettili.remove(iterProiettile);
                    }
                    else
                    {
                        //aggiorno il proiettile
                        this->proiettili.write(iterProiettile, aggiornato);
                    }
                    //passo al successivo
                    iterProiettile = this->proiettili.next(iterProiettile);
                }
            }
        }
    }
}