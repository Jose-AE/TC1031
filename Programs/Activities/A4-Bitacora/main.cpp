#include <fstream>
#include <iostream>
#include <string>
#include "../../../Functions/LinealDataStructures/LinkedList/LinkedList.h"
#include "../../../Functions/SortMethods/QuickSort.h"
#include "./Register.h"

int main(int argc, char const *argv[]) {

   string test =
       "Jun 21 16:33:38 194.9.625.71:6781 Failed password for illegal user "
       "guest";

   // test = "Oct 5 13:22:29 382.85.124.86:4971 Failed password for root";
   //   cout << test.substr(28, 1);

   // if (test.substr(28, 1) == ":")  // long ip
   //    cout << test.substr(15, 13);
   // else
   //    cout << test.substr(15, 12);

   // return 0;

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
   // QuickSort(list, 0, list.getLength() - 1);

   for (int i = 0; i < 20; i++) {
      cout << list[i].getData() << endl;

      cout << list[i].getIP() << endl;
   }
   return 0;

   string start;
   string end;
   cout << "Input start IP:  ";
   cin >> start;
   cout << "\nInput end IP:  ";
   cin >> end;

   start = "998.94.195.38:416";
   end = "995.50.337.89:553";

   for (int i = 0; i < list.getLength(); i++) {
      if (start >= list[i].getIP() && list[i].getIP() <= end) {
         cout << list[i].getData() << endl;
      }
   }

   return 0;
}
