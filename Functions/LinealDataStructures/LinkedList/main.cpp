#include <iostream>
#include "../../Utils/PrintArray.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, char const* argv[]) {

   cout << "------int linked list-----\n";

   int num = 99;

   LinkedList<int> intList(1);
   intList.Insert(5);
   intList.Insert(6);
   intList.Insert(num, 0);

   cout << "\nlist contents:\n";
   for (int i = 0; i < intList.length; i++) {
      cout << i << "-[";
      cout << intList[i];
      cout << "]\n";
   }

   cout << "Last element: " << intList[-1] << endl;
   cout << "First element: " << intList[0];

   cout << "\n\n------chaar linked list-----\n";

   LinkedList<char> charList('a');
   charList.Insert('b', 0);
   charList.Insert('c');

   cout << "\nlist contents:\n";
   for (int i = 0; i < charList.length; i++) {
      cout << i << "-[";
      cout << charList[i];
      cout << "]\n";
   }

   cout << "Last element: " << charList[-1] << endl;
   cout << "First element: " << charList[0];

   return 0;
}
