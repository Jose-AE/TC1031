#include <fstream>
#include <iostream>
#include "./utils/ReadSortTXT.h"
#include "./utils/Stack/Stack.h"
int main(int argc, char const *argv[]) {

   // ReadSortTXT();

   fstream newfile;
   Stack<Register> stack();

   newfile.open("data/sorted_bitacora.txt", ios::in);
   if (newfile.is_open()) {
      string line;
      while (getline(newfile, line)) {
         stack.push(new Node<Register>(Register(line)));
      }
      newfile.close();
   }

   string input;
   while (input != "s" || input != "n") {
      cout << "Quieres sacar la incidencia de la pila? (s/n)";
      cin >> input;

      if (input == "s") {
         cout << stack.top() << endl;
      }
   }

   return 0;
}
