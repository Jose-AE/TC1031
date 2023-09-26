#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "../../../../Functions/LinealDataStructures/LinkedList/LinkedList.h"
#include "../../../../Functions/SortMethods/QuickSort.h"
#include "../Register.h"

void ReadSortTXT() {

   LinkedList<Register> list;
   fstream newfile;

   newfile.open("data/bitacora.txt", ios::in);
   if (newfile.is_open()) {
      string line;
      while (getline(newfile, line)) {
         list.Insert(Register(line));  // insert register instead of string
      }
      newfile.close();
   }

   cout << "Ordenando IPs..." << endl;
   QuickSort(list, 0, list.getLength() - 1);

   string start;
   string end;
   cout << "Input start IP:  ";
   cin >> start;
   cout << "\nInput end IP:  ";
   cin >> end;

   start = "998.94.195.38:416";
   end = "995.50.337.89:553";

   // save range in new txt
   newfile.open("data/sorted_bitacora.txt", ios::out);
   for (int i = 0; i < list.getLength(); i++) {
      if (start >= list[i].getIP() && list[i].getIP() <= end) {
         newfile << list[i].getData() << endl;
      }
   }
   newfile.close();
}