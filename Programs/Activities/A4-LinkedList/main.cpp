#include <iostream>
#include "LinkedList.h"
#include "Node.h"
#include "Persona.h"

using namespace std;

int main() {
   cout << "d";
   LinkedList<Persona> list;
   list.addNode(new Node<Persona>(Persona("Juan", 30)));
   list.addNode(new Node<Persona>(Persona("Pedro", 20)));
   list.addNode(new Node<Persona>(Persona("Maria", 55)));
   list.addNode(new Node<Persona>(Persona("Jose", 50)));
   list.addNode(new Node<Persona>(Persona("Jose", 15)));
   list.print();
   list.bubbleSort();
   list.print();
   cout << "----";

   return 0;
}
