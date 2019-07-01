//codice carburante
#include "../header/Fuel.hpp"

//PRIVATA
void Fuel::generaTipo(void)
{
    this->tipo = rand() % 2;
    switch (this->tipo)
    {
    case 0:
        this->quantita = FUEL_1_QUANTITA;
        break;
    case 1:
        this->quantita = FUEL_2_QUANTITA;
        break;
    default:
        cout << "\nil tipo = " << this->tipo << " del fuel non ha senso\n";
        break;
    }
}

//costruttore vuoto
Fuel::Fuel(void)
{
    //tutto di default
    this->generaTipo();
}
//costruttore coordinate
Fuel::Fuel(Punto centro)
{
    this->centro = centro;
    this->generaTipo();
}
Fuel::Fuel(float x, float y)
{
    this->centro.setCoord(x, y);
    this->generaTipo();
}
//costruttore completo
Fuel::Fuel(Punto centro, float size)
{
    this->centro = centro;
    this->size = size;
    this->generaTipo();
}
Fuel::Fuel(float x, float y, float size)
{
    this->centro.setCoord(x, y);
    this->size = size;
    this->generaTipo();
}

//distruttore
/*virtual*/ Fuel::~Fuel(void)
{
    //distruttore di default
}

//setters
void Fuel::setX(float x)
{
    this->centro.setX(x);
}
void Fuel::setY(float y)
{
    this->centro.setY(y);
}
void Fuel::setCoord(float x, float y)
{
    this->centro.setCoord(x, y);
}
void Fuel::setQuantita(float quantita)
{
    this->quantita = quantita;
}
void Fuel::setSize(float size)
{
    this->size = size;
}

//getters
float Fuel::getX(void)
{
    return this->centro.getX();
}
float Fuel::getY(void)
{
    return this->centro.getY();
}
float Fuel::getQuantita(void)
{
    return this->quantita;
}
float Fuel::getSize(void)
{
    return this->size;
}
int Fuel::getTipo(void)
{
    return this->tipo;
}

//stampa
void Fuel::print(void)
{
    cout << "Fuel : [ centro = ";
    this->centro.print();
    cout << ", size = " << this->size;
    cout << " ]" << endl;
}

//contronto
bool Fuel::confronto(Fuel f)
{
    return (this->centro.getX() == f.getX() && this->centro.getY() == f.getY() && this->quantita == f.getQuantita() && this->size == f.getSize());
}

//disegna
void Fuel::draw(sf::RenderWindow &window)
{
    ColoreRGB viola = ColoreRGB(255, 0, 255);
    //disegna carburante
    sf::RectangleShape rectangle(sf::Vector2f(this->size, this->size));
    //colore rosso se di tipo 0 viola se di tipo 1
    switch (this->tipo)
    {
    case 0:
        rectangle.setFillColor(sf::Color::Black);
        break;
    case 1:
        rectangle.setFillColor(viola.getColorLib());
        break;
    default:
        cout << "\nil tipo = " << this->tipo << " del bunker non ha senso\n";
        break;
    }
    rectangle.setPosition(this->getX() - this->size / 2, this->getY() - this->size / 2);

//nome se esiste
#ifdef NOME_PUNTO
    sf::Text testo;
    testo.setString(this->centro.getName());
#endif

    //il punto è al centro del rettangolo
    window.draw(rectangle);

#ifdef NOME_PUNTO
    window.draw(testo);
#endif
}

//consumo carburante
float Fuel::consumoFuel(void)
{
    //consuma fuel
}