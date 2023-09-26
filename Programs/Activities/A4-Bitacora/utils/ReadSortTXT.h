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

   // start = "909.95.412.60:5908";
   // end = "910.95.412.60:5908";

   // save range in new txt
   newfile.open("data/sorted_bitacora.txt", ios::out);
   for (int i = 0; i < list.getLength(); i++) {
      if (end > list[i].getIP() && list[i].getIP() >= start) {
         newfile << list[i].getData() << endl;
      }
   }
   newfile.close();
}