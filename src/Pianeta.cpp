//codice pianeta
#include "../header/Pianeta.hpp"

//#define DEBUG
#define ORDINA

//dopo questa macro è da togliere!
//#define NOME_PUNTO_SUPERFICE
//macro che, se definita, ordina la lista dei punti della superfice

extern float WIDTH, HEIGHT, SIZE_NAVICELLA;

//COSTRUTTORI
//costruttore void
Pianeta::Pianeta(void)
{
    //genera liste vuote
}
//altri costruttori
Pianeta::Pianeta(float x, float y, float raggio)
{
    this->centro.setCoord(x, y);
    this->raggio = raggio;
}
//non usato, ma simile
Pianeta::Pianeta(Punto centro, float raggio)
{
    this->centro = centro;
    this->raggio = raggio;
}

//SETTERS
//cose importanti
void Pianeta::setX(float x)
{
    this->centro.setX(x);
}
void Pianeta::setY(float y)
{
    this->centro.setY(y);
}
void Pianeta::setCoord(float x, float y)
{
    this->centro.setCoord(x, y);
}
void Pianeta::setRaggio(float raggio)
{
    this->raggio = raggio;
}
//colori
void Pianeta::setColore(ColoreRGB colore)
{
    this->colore = colore;
}
void Pianeta::setColore(int red, int green, int blue)
{
    this->colore.setRGB(red, green, blue);
}
void Pianeta::setAtmosfera(ColoreRGB outline)
{
    this->atmosfera = outline;
}
void Pianeta::setAtmosfera(int red, int green, int blue)
{
    this->atmosfera.setRGB(red, green, blue);
}
//setta la lista
void Pianeta::setSurface(Lista<Punto> listaSurface)
{
    this->surface = listaSurface;
}
void Pianeta::setFuel(Lista<Fuel> listaFuel)
{
    this->fuel = listaFuel;
}
void Pianeta::setBunker(Lista<Bunker> listaBunker)
{
    this->bunker = listaBunker;
}
//setta il puntatore della lista
void Pianeta::setHeadSurface(struct Elem<Punto> *headSurface)
{
    this->surface.setHead(headSurface);
}
void Pianeta::setHeadFuel(struct Elem<Fuel> *headFuel)
{
    this->fuel.setHead(headFuel);
}
void Pianeta::setHeadBunker(struct Elem<Bunker> *headBunker)
{
    this->bunker.setHead(headBunker);
}

//GETTERS
float Pianeta::getX(void)
{
    return this->centro.getX();
}
float Pianeta::getY(void)
{
    return this->centro.getY();
}
float Pianeta::getRaggio(void)
{
    return this->raggio;
}
//colori
sf::Color Pianeta::getColoreLib(void)
{
    this->colore.getColorLib();
}
sf::Color Pianeta::getAtmosferaLib(void)
{
    this->atmosfera.getColorLib();
}
//ottengo il puntatore alla testa, non al primo elemento
struct Elem<Punto> *Pianeta::getHeadSurface(void)
{
    return this->surface.getHead();
}
//
struct Elem<Fuel> *
Pianeta::getHeadFuel(void)
{
    return this->fuel.getHead();
}
//
struct Elem<Bunker> *
Pianeta::getHeadBunker(void)
{
    return this->bunker.getHead();
} struct Elem<Punto> *

/*ATTENZIONE!
Serve la lista dei centri dei bunker
per controllare i proiettili di entity*/
Pianeta::getHeadCentriBunker(void)
{
    return this->centriBunker.getHead();
}

//conta i punti della superficie
int
Pianeta::lunghezzaSuperfice(void)
{
    return this->surface.lunghezza();
}
//stampa
void Pianeta::print(void)
{
    cout << "Pianeta : { ";
    cout << "\ncentro = ";
    this->centro.print();
    cout << "\nraggio = " << this->raggio;
    cout << "\ncolore = ";
    this->colore.print();
    cout << "\noutline = ";
    this->atmosfera.print();
    cout << "\nsuperficie";
    this->surface.print();
    cout << "carburante";
    this->fuel.print();
    cout << "bunker";
    this->bunker.print();
    cout << " }" << endl;
}
//confronto
bool Pianeta::confronto(Pianeta p)
{
    return (this->getX() == p.getX() && this->getY() == p.getY());
}

//disegna
void Pianeta::draw(sf::RenderWindow &window)
{
    float atmosfera = -(this->raggio / 5);
    sf::CircleShape pianeta(this->raggio);
    float x = this->getX() - this->raggio;
    float y = this->getY() - this->raggio;
    pianeta.setPosition(x, y);

    //colore verde
    pianeta.setFillColor(this->getColoreLib());
    //setta un bordo di 10 all'interno del cerchio
    pianeta.setOutlineThickness(atmosfera);
    //colore del bordo giallo
    pianeta.setOutlineColor(this->getAtmosferaLib());

    window.draw(pianeta);
}
void Pianeta::drawVisuale(sf::RenderWindow &window, int length)
{
    //non è l'indice del while, ma l'indice dei punti nella convex!
    int indice = 0;
    //crea una empty shape convex con 3 punti
    sf::ConvexShape convexSuperficie;
    convexSuperficie.setPointCount(length);

    //blu
    convexSuperficie.setFillColor(this->getColoreLib());

    if (!(this->surface.empty()))
    {
        //primo elemento utile non la sentinella
        struct Elem<Punto> *iter = this->surface.head();
        //se non vuota e non finita
        while (!(this->surface.finished(iter)))
        {
            //stampo elemento MODIFICATA!
            Punto disegnato = this->surface.read(iter);
            //inserisci il punto nella convex shape
            convexSuperficie.setPoint(indice, disegnato.getPuntoLib());
            //passo al successivo
            iter = this->surface.next(iter);
            indice++;
        }
    }

    //disegna sulla window passata per riferimento
    window.draw(convexSuperficie);

#ifdef NOME_PUNTO_SUPERFICE
    this->surface.draw(window);
#endif
    this->fuel.draw(window);
    this->bunker.draw(window);
}

//PRIVATE
//generaPianeta(void);
void Pianeta::generaPunti(void)
{
    //numero random per le coordinate
    float x = 0.f, y = 0.f;
    //distanza dimensione navicella un pò di spazio per la navicella
    float dist = SIZE_NAVICELLA * 7;

    //genera tutti i PUNTI all'inizio
    for (int i = 0; i < MAX_SUPERFICE; i++)
    {
        x = (rand() % (int)(WIDTH - dist * 2)) + dist;  //tra 0.f e WIDTH ma che non esca
        y = (rand() % (int)(HEIGHT - dist * 2)) + dist; //tra 0.f e HEIGHT ma che non esca

        //costruisci punto della superfice
        Punto p = Punto(x, y);
        //inserirlo nella lista
        this->surface.insert_head(p);
    }
}

//PRIVATA
//ordina la lista dei punti del pianeta...
void Pianeta::ordinaPunti(void)
{
    //non fare niente se ORDINA non è definito
#ifdef ORDINA
    //idea: ordinare i punti in base al loro angolo rispetto al centro
    //inizializzo il punto centrale
    Punto centro = Punto(WIDTH / 2, HEIGHT / 2);
    //utilizzo quindi un vettore di angoli, un vettore di posizioni e merge-sort
    float angoli[MAX_SUPERFICE];
    struct Elem<Punto> *posizioni[MAX_SUPERFICE];

    //inizializzo l'iteratore della lista
    struct Elem<Punto> *iter = this->surface.head();

    //inizializzo i vettori di angoli e di posizioni
    if (!(this->surface.empty()))
    {
        for (int i = 0; i < MAX_SUPERFICE; i++)
        {
            if (!(this->surface.finished(iter)))
            {
                //leggo l'elemento
                Punto calcolato = this->surface.read(iter);
                //calcolo e salvo l'angolo nell'array
                angoli[i] = centro.calcolaAngolo(calcolato);
#ifdef NOME_PUNTO_SUPERFICE
                //setto il nome alla variabile "locale" calcolato
                calcolato.setName(to_string(angoli[i]));
                //aggiorno la superfice
                this->surface.write(iter, calcolato);
#endif
                //salvo il puntatore
                posizioni[i] = iter;
                //passo al successivo
                iter = this->surface.next(iter);
            }
            else
            {
                cout << "errore lista finita ma vettore più grande";
            }
        }
    }
    else
    {
        cout << "errore lista vuota";
    }
    //merge-sort
    //vettori ausiliari
    float B[MAX_SUPERFICE];
    struct Elem<Punto> *posAux[MAX_SUPERFICE];
    //eseguo algoritmo di ordinamento e sistemo la lista
    this->surface.ordina(MAX_SUPERFICE, angoli, B, posizioni, posAux);
#ifdef NOME_PUNTO_SUPERFICE
    int conta = 0;
    if (!(this->surface.empty()))
    {
        //primo elemento utile non la sentinella
        struct Elem<Punto> *iter = this->surface.head();
        //se non vuota e non finita
        while (!(this->surface.finished(iter)))
        {
            //aggiorno contatore
            conta++;
            //setto il nome al punto
            Punto nominato = this->surface.read(iter);
            nominato.setName(to_string(conta) + ", " + nominato.getName());
            this->surface.write(iter, nominato);
            //passo al successivo
            iter = this->surface.next(iter);
        }
    }
#endif //NOME_PUNTO_SUPERFICE

#endif //ORDINA
}

//PRIVATA
void Pianeta::generaBunkerFuel()
{
    int numeroFuel = 0, numeroBunker = 0;
    enum
    {
        tipo_niente,
        tipo_fuel,
        tipo_bunker
    };
    Punto p1, p2, pMedio;
    if (!(this->surface.empty()))
    {
        //primo elemento utile non la sentinella
        struct Elem<Punto> *iter = this->surface.head();
        struct Elem<Punto> *sentinella = this->surface.prev(iter);
        //se non vuota e non finita
        while (!(this->surface.finished(iter)))
        {
            int cosaGenero = rand() % 3;
            //se devo generare qualcosa
            if (cosaGenero != tipo_niente)
            {
                //stampo elemento MODIFICATA!
                p1 = this->surface.read(iter);
                //se il successivo non è la sentinella
                if (this->surface.next(iter) != sentinella)
                {
                    p2 = this->surface.read(this->surface.next(iter));
                }
                else
                {
                    p2 = this->surface.read(this->surface.tail());
                }
                //calcolo il punto medio
                int x_medio = (p1.getX() + p2.getX()) / 2;
                int y_medio = (p1.getY() + p2.getY()) / 2;
                pMedio.setCoord(x_medio, y_medio);
                //se devo generare del fuel e non ho superato il massimo
                if (cosaGenero == tipo_fuel && numeroFuel < MAX_FUEL)
                {
                    //aggiorno il numero di fuel generati
                    numeroFuel++;
#ifdef NOME_PUNTO
                    pMedio.setName("Fuel" + to_string(numeroFuel));
#endif
                    //genero il carburante
                    Fuel metano = Fuel(pMedio);
                    //inserirlo nella lista
                    this->fuel.insert_head(metano);
                }
                //se devo generare un bunker e non ho superato il massimo
                if (cosaGenero == tipo_bunker && numeroBunker < MAX_BUNKER && p1.distance(p2) > SIZE_BUNKER * 2)
                {
                    //calcolo l'angolo...
                    int angolo = p1.calcolaAngolo(p2) + 90.f;
                    //aggiorno il numero di bunker generati
                    numeroBunker++;
#ifdef NOME_PUNTO
                    pMedio.setName("Bunker" + to_string(numeroBunker));
#endif
                    Bunker cannone = Bunker(pMedio, angolo);
                    cannone.genera();
                    //inserirlo nella lista
                    this->bunker.insert_head(cannone);

                    /*ATTENZIONE!
                    Serve la lista dei centri dei bunker
                    per controllare i proiettili di entity*/
                    //inserisco nella lista dei centri
                    this->centriBunker.insert_head(pMedio);
                }
            }
            //passo al successivo
            iter = this->surface.next(iter);
        }
    }
}

void Pianeta::genera(void)
{
    this->generaPunti();
    this->ordinaPunti();
    this->generaBunkerFuel();
}

bool Pianeta::emptyBunker(void)
{
    return this->bunker.empty();
}

//fa sparare i bunker
void Pianeta::shoot(sf::Time tempo)
{
    int millisecondi = tempo.asMilliseconds();
    //se sono passati 300millisecondi dal reset o dal ultimo sparo
    if (millisecondi % SPARA == 0)
    {
        if (!(this->bunker.empty()))
        {
            //primo elemento utile non la sentinella
            struct Elem<Bunker> *iter = this->bunker.head();
            //se non vuota e non finita
            while (!(this->bunker.finished(iter)))
            {
                Bunker cannoneSpara = this->bunker.read(iter);
                cannoneSpara.shoot();
                //passo al successivo
                iter = this->bunker.next(iter);
            }
        }
    }
}

//aggiorna coordinate dei proiettili sparati dai bunker
void Pianeta::aggiornaCoordinateProiettili(sf::Time tempo, float x, float y)
{
    int millisecondi = tempo.asMilliseconds();
    //se sono passati 300millisecondi dal reset o dal ultimo sparo
    if (millisecondi % AGGIORNA == 0)
    {
        if (!(this->bunker.empty()))
        {
            //primo elemento utile non la sentinella
            struct Elem<Bunker> *iter = this->bunker.head();
            //se non vuota e non finita
            while (!(this->bunker.finished(iter)))
            {
                Bunker cannoneAggiorna = this->bunker.read(iter);
                cannoneAggiorna.aggiornaCoordinateProiettili(x, y);
                //passo al successivo
                iter = this->bunker.next(iter);
            }
        }
    }
}
