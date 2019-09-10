#include "../header/Punto.hpp"

//costruttore
Punto::Punto(void)
{
}
Punto::Punto(float x, float y)
{
    this->x = x;
    this->y = y;
}

//setters
void Punto::setX(float x)
{
    this->x = x;
}
void Punto::setY(float y)
{
    this->y = y;
}
void Punto::setCoord(float x, float y)
{
    this->x = x;
    this->y = y;
}

//getters
float Punto::getX(void)
{
    return this->x;
}
float Punto::getY(void)
{
    return this->y;
}

//stampa
void Punto::print(void)
{
    cout << "( " << this->x << ", " << this->y << " )";
}

//confronto
bool Punto::confronto(Punto p)
{
    return (this->x == p.getX() && this->y == p.getY());
}

//disegna
void Punto::draw(sf::RenderWindow &window)
{
    float size = 5.f;
    sf::RectangleShape rectangle(sf::Vector2f(size * 2, size * 2));
    rectangle.setPosition(this->x - size, this->y - size);

    //il punto è al centro del rettangolo
    window.draw(rectangle);
}
//distanza
//distanza tra due punti
float Punto::distance(float x, float y)
{
    return (float)sqrt(pow(this->getX() - x, 2) + pow(this->getY() - y, 2));
}
float Punto::distance(Punto p)
{
    return this->distance(p.getX(), p.getY());
}

//il punto è dentro un rettangolo con centro x y e dimensioni "raddoppiate"
bool Punto::isNear(float x, float y, float width, float height)
{
    //and
    if (this->x < x - width) //minore di minX
        return false;
    if (this->x > x + width) //maggiore di maxX
        return false;
    if (this->y < y - height) //minore di minY
        return false;
    if (this->y > y + height) //maggiore di maxY
        return false;
    return true;
}
//se è dentro un cerchio di raggio size e centro (x, y)
bool Punto::isNear(float x, float y, float size)
{
    bool isNear = this->isNear(x, y, size, size);

    if (isNear)
    {
        //controllo anche la distanza dal centro
        if (this->distance(x, y) > size)
        {
            isNear = false;
        }
    }

    return isNear;
}

bool Punto::isNear(Punto centro, float size)
{
    return this->isNear(centro.getX(), centro.getY(), size);
}

//calcola angolo rispetto al punto corrente
float Punto::calcolaAngolo(Punto arrivo)
{
    float angolo = 0.f;

    //tangente(AB) = (xB - xA ) / (yB - yA);
    float deltaX = arrivo.getX() - this->x;
    //la Y va nella direzione opposta
    float deltaY = -(arrivo.getY() - this->y);
    if (deltaY != 0)
    {
        //se posso fare la divisione
        float tangente = deltaX / deltaY;
        double angoloRadianti = atan(tangente);
        //trasformo l'angolo opportunamente secondo la libreria grafica
        float angoloGradi = angoloLibreria(angoloRadianti * 180 / M_PI);
        if (deltaY > 0)
        {
            //se arrivo è "sopra" la partenza
            //la tangente ha segnato l'ancolo corretto
            angolo = (float)angoloGradi;
        }
        else
        {
            //altrimenti giralo di un angolo piatto
            angolo = (float)(angoloGradi + 180.f);
        }
    }
    else if (deltaX < 0)
    {
        angolo = 180.f;
    }
    return angolo;
}

sf::Vector2f Punto::getPuntoLib(void)
{
    return sf::Vector2f(this->x, this->y);
}
