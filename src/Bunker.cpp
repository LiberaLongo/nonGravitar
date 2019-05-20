//codice bunker
#include "../header/Bunker.hpp"

template class ListaClasse<Direzione>;
template class Elem<Direzione>;

//metodo per scorrere la lista e aggiornare i centri
void Bunker::aggiornaCentriDirezione(ListaClasse<Direzione> headDir)
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
Bunker::Bunker(Punto centro, float angolo, float speed, float size, ListaClasse<Direzione> headDir)
{
    this->centro = centro;
    this->angle = angolo;
    this->speed = speed;
    this->size = size;
    this->aggiornaCentriDirezione(headDirezioni);
}
Bunker::Bunker(float x, float y, float angolo, float speed, float size, ListaClasse<Direzione> headDir)
{
    this->centro.setCoord(x, y);
    this->angle = angolo;
    this->speed = speed;
    this->size = size;
    this->aggiornaCentriDirezione(headDirezioni);
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
    this->angle = angolo;
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
    return this->angle;
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
    cout << ", angolo = " << this->angle;
    cout << ", speed = " << this->speed;
    cout << ", size = " << this->size;
    this->headDirezioni.print();
    cout << " ]" << endl;
}

//contronto
bool Bunker::confronto(Bunker b)
{
    return (this->getX() == b.getX() && this->getY() == b.getY() && this->size == b.getSize() && this->angle == b.getAngolo() && this->speed == b.getSpeed());
}

//disegna
void Bunker::draw(sf::RenderWindow &window) {
    //codice per disegnare in seguito
}

//spara
void Bunker::shoot(void) {
    //per ogni Direzione in Lista aggiorna posizione proiettili
}