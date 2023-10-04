#include <iostream>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "Ticket.h"
using namespace std;

int main() {

   Stack stack;
   Queue queue;
   LinkedList<Ticket> list;

   string input;

   while (true) {
      cout << "[1]Ingresar Ticket\n";
      cout << "[2]Sacar Ticket Prior 1\n";
      cout << "[3]Sacar Ticket Prior 0\n";
      cout << "[4]Mostrar lista de tickets ordenada\n";
      cout << "[5]Salir\n";

      cin >> input;

      if (input == "1") {
         int id;
         string description;
         int priority;

         cout << "Ingrese el ID del ticket: ";
         cin >> id;
         cout << "Ingrese la descripcion del ticket: ";
         cin >> description;
         cout << "Ingrese la prioridad del ticket (0 o 1): ";
         cin >> priority;

         Ticket newTicket(id, description, priority);
         if (priority == 1) {
            queue.enque(newTicket);
            list.append(newTicket);
         } else {
            stack.push(newTicket);
            list.append(newTicket);
         }

         cout << "\n ---[Ticket agregado]---\n\n\n\n";

      } else if (input == "2") {
         cout << "\n\n[Removed Ticket]: " << queue.deque() << " From Queue\n\n";
      } else if (input == "3") {
         cout << "\n\n[Removed Ticket]: " << stack.pop() << " From Stack\n\n";
      } else if (input == "4") {

         list.QuickSort(list, 0, list.getLength() - 1);
         cout << "\n\n----[Tickets ordenados por numero]----\n";
         list.Print();
         cout << "\n\n\n";
      } else if (input == "5") {
         break;
      } else {
         cout << "Opcion no valida. Por favor, seleccione una opción valida."
              << endl;
      }
   }

   return 0;
}