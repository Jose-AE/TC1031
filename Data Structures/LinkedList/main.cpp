#include "LinkedList.h"
using namespace std;
#include <iostream>

int main(int argc, char const *argv[]) {
   LinkedList<int> list;

   list.insert(1);
   list.insert(2);
   list.insert(3);
   list.insert(4);
   list.insert(5);

   // cout << list[-1] << endl;

   list.remove(0);
   list.print();

   return 0;
}
