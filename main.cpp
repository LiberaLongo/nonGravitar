#include <iostream>

#include "./header/Gioco.hpp"

using namespace std;

int main() {
  //testo cose
  Punto a = new Punto(0, 0);
  cout << a.getX();
  cout << a.getY();
  a.bistanceFrom(b);
  return 0;
  //chiamo funzione gioco
  //errore è true se si è presentato un errore, false altrimenti
  //bool errore = Gioco();
  //return (int) errore;
}
