
#include "BinarySearchTree.h"
#include <queue>

template <typename T>
inline BinarySearchTree<T>::BinarySearchTree() {
   this->root = nullptr;
}

template <typename T>
void BinarySearchTree<T>::Insert(T data, Node<T>* tempRoot) {
   if (this->root == nullptr) {
      this->root = new Node<T>(data);
      return;
   }
   if (tempRoot == nullptr) tempRoot = this->root;

   if (data < tempRoot->getData() && tempRoot->getLeftNodePtr() != nullptr) {
      // send left
      Insert(data, tempRoot->getLeftNodePtr());
   } else {
      // insert left
      tempRoot->setLeftNodePtr(new Node<T>(data));
   }

   if (data > tempRoot->getData() && tempRoot->getRightNodePtr() != nullptr) {
      // send right
      Insert(data, tempRoot->getRightNodePtr());
   } else {
      // insert on right
      tempRoot->setRightNodePtr(new Node<T>(data));
   }
}

template <typename T>
Node<T>* BinarySearchTree<T>::getRootPtr() {
   return nullptr;
}

template <typename T>
void BinarySearchTree<T>::Print(string prefix, Node<T>* node, bool isLeft) {
   if (node != nullptr) {
      cout << prefix;

      cout << (isLeft ? "|--" : "|--");  // └──

      // print the value of the node
      cout << node->getData() << std::endl;

      // enter the next tree level - left and right branch
      Print(prefix + (isLeft ? "│   " : "    "), node->getLeftNodePtr(), true);
      Print(prefix + (isLeft ? "│   " : "    "), node->getRightNodePtr(),
            false);
   }
}

template <typename T>
void BinarySearchTree<T>::Print() {
   Print("", root, false);
}

// Templates
template class BinarySearchTree<int>;