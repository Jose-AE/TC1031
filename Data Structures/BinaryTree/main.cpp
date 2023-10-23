#include <iostream>
#include "AVLTree.h"
#include "BinarySearchTree.h"
using namespace std;
int main(int argc, char const *argv[]) {
   AVLTree<int> tree;

   int numbersToInsert[] = {-1, 2, 1, 0};  //{10, 15, 20, 12, 5}

   for (int number : numbersToInsert) {
      tree.Insert(number);
   }

   // tree.setRootPtr(tree.leftRotate(tree.getRootPtr()));

   // tree.Print();

   // cout << tree.getRootPtr()->getRightNodePtr()->getLeftNodePtr();

   // if (tree.getRootPtr()->getLeftNodePtr() != nullptr) {
   //    cout << tree.getRootPtr()->getLeftNodePtr()->getData() << endl;

   // } else
   //    cout << "nullp";

   // cout << "┌─┴─┐";

   // cout << tree.getRootPtr()->getData();

   return 0;
}
