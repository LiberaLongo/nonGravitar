//codice sistema solare

#include "../header/SistemaSolare.hpp"

//#define DEBUG

//dimensioni dello SCHERMO
extern float WIDTH, HEIGHT;
//dimensioni minime e massime del pianeta
extern float MIN_PIANETA_RAGGIO, MAX_PIANETA_RAGGIO;

//COSTRUTTORI
//costruttore void
SistemaSolare::SistemaSolare(void)
{
    //tutto di default
}
//costruttori completi
SistemaSolare::SistemaSolare(Lista<Pianeta> listaPianeti)
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
void SistemaSolare::setListaPianeti(Lista<Pianeta> listaPianeti)
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
void SistemaSolare::printCentri(void)
{
    cout << "//stampo SOLTANTO i centri dei pianeti" << endl;
    cout << "SistemaSolare : {" << endl;
    cout << " : [ ";
    if (!(this->pianeti.empty()))
    {
        //primo elemento utile non la sentinella
        struct Elem<Pianeta> *iter = this->pianeti.head();
        //se non vuota e non finita
        while (!(this->pianeti.finished(iter)))
        {
            //stampo elemento MODIFICATA!
            Pianeta stampato = this->pianeti.read(iter);
            Punto centro = Punto(stampato.getX(), stampato.getY());
            centro.print();
            //passo al successivo e stampo freccia
            iter = this->pianeti.next(iter);
            if (!(this->pianeti.finished(iter)))
                cout << " --> ";
        }
    }
    cout << " ]\n}" << endl;
}
//disegna
void SistemaSolare::draw(sf::RenderWindow &window)
{
    this->pianeti.draw(window);
}
//genera lista di pianeti
void SistemaSolare::genera()
{
    //genera tutti i pianeti all'inizio
    for (int i = 0; i < MAX_PLANET; i++)
    {
        //numero random per la dimensione del pianeta compreso tra min e max
        float raggio = (rand() % (int)MAX_PIANETA_RAGGIO) + MIN_PIANETA_RAGGIO;

        //numero random per le coordinate
        float x = 0.f, y = 0.f;
        //distanza raggio del pianeta più un pò di spazio per la navicella
        float dist = raggio + 20.f;
        x = (rand() % (int)(WIDTH - dist * 2)) + dist;  //tra 0.f e WIDTH ma che non esca
        y = (rand() % (int)(HEIGHT - dist * 2)) + dist; //tra 0.f e HEIGHT ma che non esca

        //costruisci pianeta
        Pianeta newPianeta = Pianeta(x, y, raggio);

        //colore
        int r, g, b;
        r = (rand() % LUMUS_MAXIMA);
        g = (rand() % LUMUS_MAXIMA);
        b = (rand() % LUMUS_MAXIMA);
        newPianeta.setColore(r, g, b);

        //colore atmosfera
        int ro, go, bo;
        ro = (rand() % LUMUS_MAXIMA);
        go = (rand() % LUMUS_MAXIMA);
        bo = (rand() % LUMUS_MAXIMA);
        newPianeta.setAtmosfera(ro, go, bo);

        //genera il pianeta
        newPianeta.genera();
        
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

//restituisce il puntatore al pianeta ricevendo la sua posizione nella lista
Pianeta SistemaSolare::toPtrPlanet(struct Elem<Pianeta> *posizionePianeta)
{
    return (this->pianeti.read(posizionePianeta));
}

//controlla se la navicella è vicina a un pianeta nella lista
struct Elem<Pianeta> *SistemaSolare::isNavicellaNearAPlanet(Navicella navicella)
{
    struct Elem<Pianeta> *findedPlanet = nullptr;
    if (!(this->pianeti.empty()))
    {
#ifdef DEBUG
        cout << "lista non vuota" << endl;
#endif
        struct Elem<Pianeta> *iter = this->pianeti.head();
        //nessun pianeta è vicino prima di scorrere la lista
        bool vicino = false;
        while (!vicino && !(this->pianeti.finished(iter)))
        {
#ifdef DEBUG
            cout << "non vicino e non finita" << endl;
#endif
            //se iter è vicino alla navicella
            Pianeta controllato = this->pianeti.read(iter);
            if (navicella.isNear(controllato))
            {
#ifdef DEBUG
                cout << "navicella vicino al pianeta: " << endl;
#endif
                //esco dal while
                vicino = true;
                //aggiorno findedPlanet
                findedPlanet = iter;
            }
            //passo al successivo
            iter = this->pianeti.next(iter);
        }
    }
#ifdef DEBUG
    cout << "esco dal isNavicellaNearAPlanet" << endl;
#endif
    return findedPlanet;
}
