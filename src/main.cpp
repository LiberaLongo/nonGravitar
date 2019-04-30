#include <iostream>

#include "./header/Gioco.hpp"
#include "./header/Lista.hpp"

using namespace std;

int main()
{
  //testo cose
  List<int> lista = new List<int>();
  lista.insert_head(1);
  lista.insert_head(2);
  lista.insert_head(3);
  lista.printList();
  lista = lista.remove(search(2));
  lista.printList();
  //chiamo funzione gioco
  //errore è true se si è presentato un errore, false altrimenti
  //bool errore = Gioco();
  //return (int) errore;
}
