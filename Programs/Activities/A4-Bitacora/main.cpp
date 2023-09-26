#include <fstream>
#include <iostream>
#include "./Register.h"
#include "./utils/ReadSortTXT.h"
#include "Queue.h"
#include "Stack.h"

int main(int argc, char const *argv[]) {

   ReadSortTXT();

   Stack<string> stack;

   fstream newfile;
   newfile.open("data/sorted_bitacora.txt", ios::in);
   if (newfile.is_open()) {
      string line;
      while (getline(newfile, line)) {
         stack.push(new Node_Stack<string>(line));
      }
      newfile.close();
   }

   string input;
   while (input != "s" || input != "n") {
      cout << "Quieres sacar la incidencia de la pila? (s/n)";
      cin >> input;

      if (input == "s") {
         cout << "[" << stack.top()->getData() << "]" << endl;
      } else if (input == "n") {
         cout << "Saliendo del programa de pila " << endl;
         break;
      }
   }

   ////----------------Queue

   Queue<string> queue;

   newfile.open("data/sorted_bitacora.txt", ios::in);
   if (newfile.is_open()) {
      string line;
      while (getline(newfile, line)) {
         queue.enque(new Node_Queue<string>(line));
      }
      newfile.close();
   }

   input = "";
   while (input != "s" || input != "n") {
      cout << "Quieres sacar la cola del queue? (s/n)";
      cin >> input;

      if (input == "s") {
         cout << "[" << queue.getFirst()->getData() << "]" << endl;
      } else if (input == "n") {
         cout << "Saliendo del programa de cola  " << endl;
         break;
      }
   }

   return 0;
}
