#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
int main(int argc, char const *argv[]) {
   BinarySearchTree<int> tree;

   tree.Insert(1);
   tree.Insert(2);
   tree.Insert(3);
   // tree.Print();

   tree.getRootPtr()->Print();

   // cout << "┌─┴─┐";

   // cout << tree.getRootPtr()->getData();

   return 0;
}
