//Poligono codice
#include "../header/Poligono.hpp"

//definizione di infinito (per algoritmo di Punto dentro Poligono)
#define INFINITO 10000.f

#define ORDINA

//dopo questa macro è da togliere!
//#define NOME_PUNTO_SUPERFICE
//macro che, se definita, ordina la lista dei punti della superfice

extern float WIDTH, HEIGHT, SIZE_NAVICELLA;

//costruttore
Poligono::Poligono(void)
{
    //tutto di default
}
Poligono::Poligono(ColoreRGB colore)
{
    this->colore = colore;
    //tutto di default
}
//setters
void Poligono::setColore(ColoreRGB colore)
{
    this->colore = colore;
}
void Poligono::setColore(int red, int green, int blue)
{
    this->colore.setRGB(red, green, blue);
}
//setta la lista
void Poligono::setLista(Lista<Punto> listaSurface)
{
    this->surface = listaSurface;
}
//setta il puntatore alla lista
void Poligono::setHead(struct Elem<Punto> *headSurface)
{
    this->surface.setHead(headSurface);
}

//getters
sf::Color Poligono::getColoreLib(void)
{
    this->colore.getColorLib();
}
//ottengo il puntatore alla testa, non al primo elemento
struct Elem<Punto> *Poligono::getHead(void)
{
    this->surface.getHead();
}

//inserisce in testa
void
Poligono::insert(Punto P)
{
    this->surface.insert_head(P);
}

//inserisce in testa
void Poligono::insert(float x, float y)
{
    Punto p = Punto(x, y);
    this->insert(p);
}

//numero punti
int Poligono::numPunti(void)
{
    return this->surface.lunghezza();
}
//stampa
void Poligono::printColore(void)
{
    this->colore.print();
}
void Poligono::print(void)
{
    cout << "Poligono: {";
    this->surface.print();
    cout << "}";
}
//disegna
void Poligono::draw(sf::RenderWindow &window)
{
    //non è l'indice del while, ma l'indice dei punti nella convex!
    int indice = 0;
    //crea una empty shape convex con 3 punti
    sf::ConvexShape convexSuperficie;
    //convexSuperficie.setPointCount(this->numPunti());
    convexSuperficie.setPointCount(MAX_SUPERFICE);

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
}

//ordina
void Poligono::ordina(void)
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
//genera
void Poligono::genera(void)
{
    //numero random per le coordinate
    float x = 0.f, y = 0.f;
    //genera tutti i PUNTI all'inizio
    for (int i = 0; i < MAX_SUPERFICE; i++)
    {
        x = (rand() % (int)(WIDTH - DISTANCE * 2)) + DISTANCE;  //tra 0.f e WIDTH ma che non esca
        y = (rand() % (int)(HEIGHT - DISTANCE * 2)) + DISTANCE; //tra 0.f e HEIGHT ma che non esca

        //costruisci punto della superfice
        Punto p = Punto(x, y);
        //inserirlo nella lista
        this->surface.insert_head(p);
    }
}

//PRIVATE

//Dati 3 punti allineati la funzione controlla se
//il punto P giace sul segmento AB.
bool Poligono::onSegment(Punto A, Punto P, Punto B)
{
    if (P.getX() <= max(A.getX(), B.getX()) && P.getX() >= min(A.getX(), B.getX()) && P.getY() <= max(A.getY(), B.getY()) && P.getY() >= min(A.getY(), B.getY()))
        return true;
    return false;
}

//Per trovare l'orientamento della tripletta ordinata (P, Q, R)
//La funzione ritorna i seguenti valori
//0 --> P, Q, R sono allineati
//1 --> senso orario (clockwise, right turn)
//2 --> senso antiorario (counterclockwise, left turn)
int Poligono::orientation(Punto P, Punto Q, Punto R)
{
    int val = (Q.getY() - P.getY()) * (R.getX() - Q.getX()) -
              (Q.getX() - P.getX()) * (R.getY() - Q.getY());
    if (val == 0)
        return 0;             //allineati
    return (val > 0) ? 1 : 2; //senso orario o antiorario
}

//La funzione ritorna true se
//il segmento AB interseca il segmento CD.
bool Poligono::doIntersect(Punto A, Punto B, Punto C, Punto D)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(A, B, C);
    int o2 = orientation(A, B, D);
    int o3 = orientation(C, D, A);
    int o4 = orientation(C, D, B);

    // caso generale
    if (o1 != o2 && o3 != o4)
        return true;

    // casi speciali
    // A, B e C sono allineati e C giace sul segmento AB
    if (o1 == 0 && onSegment(A, C, B))
        return true;

    // A, B e C sono allineati e D giace sul segmento AB
    if (o2 == 0 && onSegment(A, D, B))
        return true;

    // C, D e A sono allineati e A giace sul segmento CD
    if (o3 == 0 && onSegment(C, A, D))
        return true;

    // C, D e B sono allineati e B giace sul segmento CD
    if (o4 == 0 && onSegment(C, B, D))
        return true;

    return false; // Non si cade in nessuno dei precedenti casi
}

//PUBBLICA

//return true se il punto giace dentro il poligono
bool Poligono::PointIsInside(Punto P, int n)
{
    //Ci devono essere almeno 3 vertici per il poligono
    if (n < 3)
        return false;
    //Crea un punto per fare il segmento da p a infinito
    Punto extreme = Punto(INFINITO, P.getY());
    //Conta le intersezioni della linea precedente con i lati del poligono
    int count = 0;
    //iteratore, primo elemento esclusa la sentinella
    struct Elem<Punto> *iter = this->surface.head();
    Punto current = this->surface.read(iter);
    do
    {
        //int next = (prev+1)%n;
        if (iter != this->surface.tail())
        {
            iter = this->surface.next(iter);
        }
        else
        {
            iter = this->surface.head();
        }
        Punto next = this->surface.read(iter);
        //Controlla se le linee del segmento da P a infinito intersecano
        //con la linea del segmento da current a next
        if (doIntersect(current, next, P, extreme))
        {
            //Se il punto P è allineato con il segmento 'current-next'
            //Allora controlla se esso giace sul segmento.
            //Se ci giace, ritorna VERO, altrimenti FALSO.
            if (orientation(current, P, next) == 0)
            {
                return onSegment(current, P, next);
            }
            count++;
        }
        current = next;

    } while (iter != this->surface.head()); //prev != 0
    //Ritorna VERO se conta è dispari, altrimenti FALSO.
    return (count % 2 == 1);
}
