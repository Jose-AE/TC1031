
#include "BinarySearchTree.h"

template <typename T>
inline BinarySearchTree<T>::BinarySearchTree() {}

template <typename T>
void BinarySearchTree<T>::Insert(T data, Node<T>* tempRoot) {
   if (root == nullptr) {
      root = new Node<T>(data, nullptr, nullptr);
      return;
   }

   if (tempRoot->getLeftNodePtr == nullptr) {
      tempRoot->setLeftNodePtr(new Node<T>(data));
      return;
   }

   if (tempRoot->getRightNodePtr == nullptr) {
      tempRoot->setRightNodePtr(new Node<T>(data));
      return;
   }

   if (data < tempRoot->getData()) {
      Insert(data, tempRoot->getLeftNodePtr());
   } else if (data > tempRoot->getData()) {
      Insert(data, tempRoot->getRightNodePtr());
   }
}

template <typename T>
Node<T>* BinarySearchTree<T>::getRootPtr() {
   return nullptr;
}

template class BinarySearchTree<int>;