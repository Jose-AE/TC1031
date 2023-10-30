#include <iostream>
#include "AVLTree.h"
#include "BinarySearchTree.h"
using namespace std;
int main(int argc, char const *argv[]) {
   AVLTree<int> tree;

   int numbersToInsert[] = {1,  57, 34, 92,
                            11, 45, 20, 89};  //{10, 15, 20, 12, 5}

   /*
   1, 57, 34, 92, 11, 45, 20, 89, 62,
       3, 68, 79, 29, 18, 73, 10, 95, 25
   */
   for (int number : numbersToInsert) {
      tree.Insert(number);
   }

   /*
   To find error search for "error-flag"

   */

   cout << "------Program ended------------";
   return 0;
}
