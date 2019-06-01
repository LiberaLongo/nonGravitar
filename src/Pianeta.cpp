//codice pianeta
#include "../header/Pianeta.hpp"

//#define DEBUG
//#define DEBUG_ORDINAMENTO
#define ORDINA
//macro che, se definita, ordina la lista dei punti della superfice

//PRIVATI
float B[MAX_SUPERFICE];
struct Elem<Punto> *posAux[MAX_SUPERFICE];
//metodi di ordinamento

//libro di algoritmi: pag 29/30.
//ATTENZIONE! il libro non ha il vettore delle posizioni da aggiornare!
void Pianeta::Merge(float A[], int primo, int ultimo, int mezzo, struct Elem<Punto> *posizioni[])
{
    int i = primo, j = mezzo + 1, k = primo, h;
    //while i <= mezzo and j <= ultimo do
    while ((i <= mezzo) && (j <= ultimo))
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            //aggiorno il vettore dei puntatori
            posAux[k] = posizioni[i];
            //
            i = i + 1;
        }
        else
        {
            B[k] = A[j];
            //aggiorno il vettore dei puntatori
            posAux[k] = posizioni[j];
            //
            j = j + 1;
        }
        k = k + 1;
    }
    j = ultimo;
    //for h <-- mezzo downto i do
    for (h = mezzo; h >= i; h--)
    {
        A[j] = A[h];
        //aggiorno il vettore dei puntatori
        posizioni[j] = posizioni[h];
        //
        j = j - 1;
    }
    //for j <-- primo to k-1 do
    for (j = primo; j <= (k - 1); j++)
    {
        A[j] = B[j];
        //aggiorno il vettore dei puntatori
        posizioni[j] = posAux[j];
        //
    }
}
void Pianeta::MergeSort(float A[], int primo, int ultimo, struct Elem<Punto> *posizioni[])
{
    if (primo < ultimo)
    {
        //integer mezzo <-- base[(primo + ultimo)/2]
        int mezzo = floor((primo + ultimo) / 2);
        this->MergeSort(A, primo, mezzo, posizioni);
        this->MergeSort(A, mezzo + 1, ultimo, posizioni);
        this->Merge(A, primo, ultimo, mezzo, posizioni);
    }
}

//COSTRUTTORI
//costruttore void
Pianeta::Pianeta(void)
{
    //genera liste vuote
}
//costruttori punto
Pianeta::Pianeta(Punto centro, float raggio)
{
    this->centro = centro;
    this->raggio = raggio;
}
Pianeta::Pianeta(float x, float y, float raggio)
{
    this->centro.setCoord(x, y);
    this->raggio = raggio;
}
//costruttori completi
Pianeta::Pianeta(Punto centro, float raggio, ColoreRGB colore, ColoreRGB outline, ListaClasse<Punto> listaSurface, ListaClasse<Fuel> listaFuel, ListaClasse<Bunker> listaBunker)
{
    this->centro = centro;
    this->raggio = raggio;
    this->atmosfera = outline;
    this->colore = colore;
    this->surface = listaSurface;
    this->fuel = listaFuel;
    this->bunker = listaBunker;
}
Pianeta::Pianeta(float x, float y, float raggio, int red, int green, int blue, int red_o, int green_o, int blue_o, ListaClasse<Punto> listaSurface, ListaClasse<Fuel> listaFuel, ListaClasse<Bunker> listaBunker)
{
    this->centro.setCoord(x, y);
    this->raggio = raggio;
    this->colore.setRGB(red, green, blue);
    this->colore.setRGB(red_o, green_o, blue_o);
    this->surface = listaSurface;
    this->fuel = listaFuel;
    this->bunker = listaBunker;
}
//distruttori
/*virtual*/ Pianeta::~Pianeta(void)
{
    //distruttore vuoto
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
void Pianeta::setSurface(ListaClasse<Punto> listaSurface)
{
    this->surface = listaSurface;
}
void Pianeta::setFuel(ListaClasse<Fuel> listaFuel)
{
    this->fuel = listaFuel;
}
void Pianeta::setBunker(ListaClasse<Bunker> listaBunker)
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
}
//generaPianeta(void);
void Pianeta::genera(void)
{
    //genera tutti i punti all'inizio
    for (int i = 0; i < MAX_SUPERFICE; i++)
    {
        //numero random per le coordinate
        float x = 0.f, y = 0.f;
        x = rand() % ((int)WIDTH);  //tra 0.f e WIDTH
        y = rand() % ((int)HEIGHT); //tra 0.f e HEIGHT
        //costruisci pianeta
        Punto p = Punto(x, y);

#ifdef DEBUG
        p.print();
        cout << "\t";
#endif
        //inserirlo nella lista
        this->surface.insert_head(p);
    }
}

//ordina la lista dei punti del pianeta...
void Pianeta::ordinaPunti(void)
{
#ifdef DEBUG_ORDINAMENTO
    cout << "lista prima dell' ordinamento";
    this->surface.print();
#endif
    //non fare niente
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
#ifdef DEBUG_ORDINAMENTO
                cout << "Punto: ";
                calcolato.print();
                cout << ",\tAngolo: " << angoli[i] << endl;
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
#ifdef DEBUG_ORDINAMENTO
    cout << "\nvettore prima MergeSort: [";
    for (int i = 0; i < MAX_SUPERFICE; i++)
    {
        cout << angoli[i] << ", ";
    }
    cout << "]\n";
#endif
#ifdef ORDINA
    //merge-sort
    this->MergeSort(angoli, 0, MAX_SUPERFICE - 1, posizioni);
#endif
#ifdef DEBUG_ORDINAMENTO
    cout << "\nvettore dopo MergeSort:  [";
    for (int i = 0; i < MAX_SUPERFICE; i++)
    {
        cout << angoli[i] << ", ";
    }
    cout << "]\n\n";
#endif
    //ricostruisci la lista della superfice ordinata
#ifdef ORDINA
    ListaClasse<Punto> ordinata;
    for (int i = 0; i < MAX_SUPERFICE; i++)
    {
        ordinata.insert_head(this->surface.read(posizioni[i]));
        //NB: uso insert_head per ordinarli dal più grande al più piccolo, in senso orario
        //uso insert_tail per ordinarli dal più piccolo al più grande, in senso anti-orario
    }
    this->surface.setHead(ordinata.getHead());
#endif
#ifdef DEBUG_ORDINAMENTO
    cout << "lista dopo ordinamento";
    this->surface.print();
#endif
}
