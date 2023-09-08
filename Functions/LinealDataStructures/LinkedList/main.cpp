#include <iostream>
#include "../../Utils/PrintArray.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, char const* argv[]) {

   cout << "------int linked list-----\n";

   LinkedList<int> intList;

   intList.Insert(5);
   intList.Insert(6);

   cout << "\nlist contents:\n";

   for (int i = 0; i < intList.getLength(); i++) {
      cout << i << "-[";
      cout << intList[i];
      cout << "]\n";
   }

   cout << "Last element: " << intList[1] << endl;
   cout << "First element: " << intList[0];

   return 0;
}
