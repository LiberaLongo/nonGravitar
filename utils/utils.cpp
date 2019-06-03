//codice cose utili usate in tutto il codice

#include "../header/utils.hpp"

//Precondition: prende un angolo in gradi in forma canonica
//Postcondition: lo trasforma secondo la libreria grafica per ora usata
//NOTA dei programmatori: ovviamente va modificata
//              quando si usa una libreria grafica diversa

float angoloLibreria(float angolo)
{
    //sembra che la libreria SFML fa aumentare l'angolo in senso antiorario
    //se le cose di default voglio che puntino verso l'alto
    //(perchè ad esempio un trangolo regolare (cerchio di 3 lati) non ruotato ha una punta verso l'alto )
    //ci devo aggiungere 90 gradi ma stando attenta al modulo
    return (-angolo + 90.f);
}
