//codice sistema solare
#include <ctime>
#include <cstdlib>

#include "../header/SistemaSolare.hpp"

//COSTRUTTORI
//costruttore void
SistemaSolare::SistemaSolare(void)
{
    //tutto di default
}
//costruttori completi
SistemaSolare::SistemaSolare(ListaClasse<Pianeta> listaPianeti)
{
    this->pianeti = listaPianeti;
}
SistemaSolare::SistemaSolare(struct Elem<Pianeta> *headPianeti)
{
    this->pianeti.setHead(headPianeti);
}
//distruttore
/*virtual*/ SistemaSolare::~SistemaSolare(void)
{
    //distruttore vuoto
}

//SETTERS
//setta la lista
void SistemaSolare::setListaPianeti(ListaClasse<Pianeta> listaPianeti)
{
    this->pianeti = listaPianeti;
}
//setta il puntatore della lista
void SistemaSolare::setHeadPianeti(struct Elem<Pianeta> *headPianeti)
{
    this->pianeti.setHead(headPianeti);
}
//GETTERS
struct Elem<Pianeta> *SistemaSolare::getHeadPianeti(void)
{
    return this->pianeti.getHead();
}

//stampa
void SistemaSolare::print(void) {
    cout << "SistemaSolare : {" << endl;
    this->pianeti.print();
    cout << " }" << endl;
}
//disegna
void SistemaSolare::draw(sf::RenderWindow &window)
{
    if (!(this->pianeti.empty()))
    {
        //primo elemento utile non la sentinella
        struct Elem<Pianeta> *iter = this->pianeti.head();
        //se non vuota e non finita
        while (!(this->pianeti.finished(iter)))
        {
            //stampo elemento MODIFICATA!
            Pianeta disegnato = this->pianeti.read(iter);
            disegnato.draw(window);
            //passo al successivo e stampo freccia
            iter = this->pianeti.next(iter);
        }
    }
}
//genera lista di pianeti
void SistemaSolare::genera()
{
    //seme per i numeri casuali
    srand(time(NULL));
    //genera tutti i pianeti all'inizio o man mano?
    for (int i = 1; i < MAX_PLANET; i++)
    {
        //numero random per le coordinate
        float x = 0.f, y = 0.f;
        x = rand() % ((int)WIDTH);  //tra 0.f e WIDTH
        y = rand() % ((int)HEIGHT); //tra 0.f e HEIGHT
        //costruisci pianeta
        Pianeta newPianeta = Pianeta(x, y);
        //genera il pianeta
        newPianeta.genera();
        //inserirlo nella lista
        this->pianeti.insert_head(newPianeta);
    }
}