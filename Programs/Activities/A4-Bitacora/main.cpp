#include <fstream>
#include <iostream>
#include <string>
#include "../../../Functions/LinealDataStructures/LinkedList/LinkedList.h"

void Sort(LinkedList<string> list) {
   bool sorted = false;

   while (!sorted) {
      sorted = false;
      for (int i = 0; i < list.getLength(); i++) {

         if (list[i] > list[i + 1 < list.getLength() ? i + 1 : 0]) {
            list.Switch(i, i + 1 < list.getLength() ? i + 1 : 0);
            sorted = false;
         }
      }
   }
}

int main(int argc, char const *argv[]) {

   LinkedList<string> list;
   fstream newfile;

   newfile.open("data/bitacora.txt", ios::in);
   if (newfile.is_open()) {
      string tp;
      while (getline(newfile, tp)) {
         list.Insert(tp);
      }
      newfile.close();
   }

   Sort(list);

   for (int i = 0; i < list.getLength(); i++) {
      cout << list[i] << endl;
   }

   return 0;
}
