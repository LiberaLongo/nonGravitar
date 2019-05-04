#include <iostream>
using namespace std;

//#include "../header/Gioco.hpp"
#include "../header/Lista.hpp"


//ATTENZIONE!
//le definizioni dei template non vengono incluse nei file oggetto dei sorgenti C++
//#include "./dichiarazioni.cpp"
template class Lista<int>;
//fine ATTENZIONE!


int main()
{
  //testo cose
  Lista<int> lista; //senza parentesi ()
  lista.insert_head(1);
  lista.insert_head(2);
  lista.insert_head(3);
  lista.printList();
  lista.remove(lista.search(2));
  lista.printList();
  //chiamo funzione gioco
  //errore è true se si è presentato un errore, false altrimenti
  //bool errore = Gioco();
  //return (int) errore;
}
