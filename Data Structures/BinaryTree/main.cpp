#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
int main(int argc, char const *argv[]) {
   BinarySearchTree<int> tree;

   tree.Insert(1);
   tree.Insert(2);
   tree.Insert(3);
   tree.Print();

   // if (tree.getRootPtr()->getLeftNodePtr() != nullptr) {
   //    cout << tree.getRootPtr()->getLeftNodePtr()->getData() << endl;

   // } else
   //    cout << "nullp";

   // cout << "┌─┴─┐";

   // cout << tree.getRootPtr()->getData();

   return 0;
}
