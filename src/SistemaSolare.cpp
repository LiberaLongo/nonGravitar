//codice sistema solare

#include "../header/SistemaSolare.hpp"

//#define DEBUG

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
void
SistemaSolare::print(void)
{
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
    //genera tutti i pianeti all'inizio o man mano?
    for (int i = 0; i < MAX_PLANET; i++)
    {
        //numero random per le coordinate
        float x = 0.f, y = 0.f;
        //distanza raggio del pianeta più un pò di spazio per la navicella
        float dist = PIANETA_RAGGIO + 20.f;
        x = (rand() % (int)(WIDTH - dist*2)) + dist;  //tra 0.f e WIDTH ma che non esca
        y = (rand() % (int)(HEIGHT - dist*2)) + dist; //tra 0.f e HEIGHT ma che non esca

        //colore
        int r, g, b;
        r = (rand() % LUMUS_MAXIMA);
        g = (rand() % LUMUS_MAXIMA);
        b = (rand() % LUMUS_MAXIMA);

        //colore outline
        int ro, go, bo;
        ro = (rand() % LUMUS_MAXIMA);
        go = (rand() % LUMUS_MAXIMA);
        bo = (rand() % LUMUS_MAXIMA);

        //costruisci pianeta
        Pianeta newPianeta = Pianeta(x, y, r, g, b, ro, go, bo);
        //genera il pianeta
        newPianeta.genera();
//#ifdef DEBUG
//#endif
        //inserirlo nella lista
        this->pianeti.insert_head(newPianeta);
    }
    /*
    problema 1: i pianeti si possono generare "vicini vicini"
    se per ogni pianeta che genero controllo che non sia troppo vicino a
    un altro pianeta la complessità mi diventa da O(n) a O(n^2).
    problema 2: la navicella può essere dentro un pianeta appena generato,
    cè un algoritmo intelligente per evitarlo?
    si, compressione delle lunghezze e controllo if (pensato)
    ma, "keep it simple and stupid"
    */
}

