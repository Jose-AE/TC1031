
#include "BinarySearchTree.h"
#include <queue>

template <typename T>
inline BinarySearchTree<T>::BinarySearchTree() {}

template <typename T>
void BinarySearchTree<T>::Insert(T data, Node<T>* tempRoot) {
   if (this->root == nullptr) {
      this->root = new Node<T>(data);
      return;
   }
   if (tempRoot == nullptr) {
      tempRoot = this->root;
   };

   // if should send left
   if (data < tempRoot->getData()) {

      if (tempRoot->getLeftNodePtr() != nullptr) {
         // recurse left
         Insert(data, tempRoot->getLeftNodePtr());
      } else {
         // insert left
         tempRoot->setLeftNodePtr(new Node<T>(data));
      }
   }

   // if should send right
   if (data > tempRoot->getData()) {

      if (tempRoot->getRightNodePtr() != nullptr) {
         // recurse right
         Insert(data, tempRoot->getRightNodePtr());
      } else {
         // insert rigth
         tempRoot->setRightNodePtr(new Node<T>(data));
      }
   }
}

template <typename T>
Node<T>* BinarySearchTree<T>::getRootPtr() {
   return root;
}

template <typename T>
void BinarySearchTree<T>::Print(string prefix, Node<T>* node, bool isLeft) {
   if (node != nullptr) {
      cout << prefix;

      cout << (isLeft ? "|--[" : "|--[");  // └──

      // print the value of the node
      cout << node->getData() << std::endl;

      // enter the next tree level - left and right branch
      Print(prefix + (isLeft ? "|   " : "    "), node->getLeftNodePtr(), true);
      Print(prefix + (isLeft ? "|   " : "    "), node->getRightNodePtr(),
            false);
   }
}

template <typename T>
void BinarySearchTree<T>::Print() {
   cout << "\nHeight: " << root->getHeight() << "\n\n";
   Print("", root, false);
}

// Templates
template class BinarySearchTree<int>;