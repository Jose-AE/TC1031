#include <iostream>
#include "AVLTree.h"
#include "BinarySearchTree.h"

// if on windows include win lib
#if _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

using namespace std;
int main(int argc, char const *argv[]) {
#if _WIN32
   // to print ascii correctly on windows
   SetConsoleOutputCP(CP_UTF8);
#endif

   AVLTree<int> tree;

   int numbersToInsert[] = {1,  57, 34, 92, 11, 45,
                            20, 89, 10, 15, 12, 5};  //{10, 15, 20, 12, 5}

   for (int number : numbersToInsert) {
      tree.Insert(number);
   }

   tree.Delete(57);

   cout << "------Program ended------------";
   return 0;
}
