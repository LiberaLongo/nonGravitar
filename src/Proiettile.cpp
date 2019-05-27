//codice proiettile
#include "../header/Proiettile.hpp"

//costruttore vuoto
Proiettile::Proiettile(void) : Direzione() {}
//costruttore minimale
Proiettile::Proiettile(Punto origine) : Direzione(origine) {}
Proiettile::Proiettile(float x, float y) : Direzione(x, y) {}
//costruttore completo
Proiettile::Proiettile(Punto origine, float angolo, float speed) : Direzione(origine, angolo, speed) {}
Proiettile::Proiettile(float x, float y, float angolo, float speed) : Direzione(x, y, angolo, speed) {}
//distruttore
/*virtual*/ Proiettile::~Proiettile(void) {
    //distruttore vuoto
}
//stampa
void Proiettile::print(void) {
    cout << "Proiettile : [ origine = ";
    this->origine.print();
    cout << ", angolo = " << this->getAngolo();
    cout << ", speed = " << this->getSpeed();
    cout << " ]" << endl;
}
//disegna
void Proiettile::draw(sf::RenderWindow &window){}