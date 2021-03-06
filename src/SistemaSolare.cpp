#include "../header/SistemaSolare.hpp"

//dimensioni dello SCHERMO
extern float WIDTH, HEIGHT;
//dimensioni minime e massime del pianeta
extern float MIN_PIANETA_RAGGIO, MAX_PIANETA_RAGGIO;

//costruttore vuoto
SistemaSolare::SistemaSolare(void)
{
    //tutto di default
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
            //ora stampo solo i centri e non tutte le info dei pianeti
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
    //prima che vengono generati i pianeti rimuovo tutti i pianeti eventualmente rimasti
    while (!this->pianeti.empty())
    {
        this->pianeti.remove_head();
    }
    //genera tutti i pianeti all'inizio
    this->lengthPianeti = randomInt(MIN_PLANET, MAX_PLANET);
    for (int i = 0; i < this->lengthPianeti; i++)
    {
        //numero random per la dimensione del pianeta compreso tra min e max
        float raggio = (float)randomInt(MIN_PIANETA_RAGGIO, MAX_PIANETA_RAGGIO);

        //numero random per le coordinate
        float x = 0.f, y = 0.f;
        x = (float)randomInt(DISTANCE, WIDTH - DISTANCE);  //tra 0.f e WIDTH ma che non esca
        y = (float)randomInt(DISTANCE, HEIGHT - DISTANCE); //tra 0.f e HEIGHT ma che non esca

        //costruisci pianeta
        Pianeta newPianeta = Pianeta(x, y, raggio);

        //colore
        int r, g, b;
        r = randomInt(0, LUMUS_MAXIMA);
        g = randomInt(0, LUMUS_MAXIMA);
        b = randomInt(0, LUMUS_MAXIMA);
        newPianeta.setColore(r, g, b);

        //colore atmosfera
        int ro, go, bo;
        ro = randomInt(0, LUMUS_MAXIMA);
        go = randomInt(0, LUMUS_MAXIMA);
        bo = randomInt(0, LUMUS_MAXIMA);
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

void SistemaSolare::eliminaPianeta(struct Elem<Pianeta> *pianetaEliminato)
{
    this->pianeti.remove(pianetaEliminato);
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
        struct Elem<Pianeta> *iter = this->pianeti.head();
        //nessun pianeta è vicino prima di scorrere la lista
        bool vicino = false;
        while (!vicino && !(this->pianeti.finished(iter)))
        {
            //se iter è vicino alla navicella
            Pianeta controllato = this->pianeti.read(iter);
            if (navicella.isNear(controllato))
            {
                //esco dal while
                vicino = true;
                //aggiorno findedPlanet
                findedPlanet = iter;
            }
            //passo al successivo
            iter = this->pianeti.next(iter);
        }
    }
    return findedPlanet;
}
bool SistemaSolare::emptyPianeti(void)
{
    return this->pianeti.empty();
}
