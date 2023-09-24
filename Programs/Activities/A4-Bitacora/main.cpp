#include <fstream>
#include <iostream>
#include <string>
#include "../../../Functions/LinealDataStructures/LinkedList/LinkedList.h"
#include "../../../Functions/SortMethods/QuickSort.h"

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

   LinkedList<int> intlist;
   intlist.Insert(1);
   intlist.Insert(2);
   intlist.Insert(3);
   intlist.Insert(2);
   intlist.Insert(7);
   intlist.Insert(5);
   intlist.Insert(9);
   intlist.Insert(4);
   intlist.Insert(8);
   intlist.Insert(15);
   intlist.Insert(6);
   intlist.Insert(10);

   intlist.Swap(0, 1);

   QuickSort(intlist, 0, intlist.getLength() - 1);

   for (int i = 0; i < intlist.getLength(); i++) {
      cout << intlist[i] << endl;
   }

   return 0;
}
