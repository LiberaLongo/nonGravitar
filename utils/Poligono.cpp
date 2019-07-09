//Poligono codice
#include "../header/Poligono.hpp"

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

//numero punti
int
Poligono::numPunti(void)
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
