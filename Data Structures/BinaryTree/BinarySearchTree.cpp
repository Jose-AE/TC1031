
#include "BinarySearchTree.h"

template <typename T>
inline BinarySearchTree<T>::BinarySearchTree() {}

template <typename T>
void BinarySearchTree<T>::Insert(T data, Node<T>* tempRoot) {
   cout << "insert" << endl;
   if (this->root == nullptr) {
      root->setData(data);
      return;
   }
   if (tempRoot == nullptr) tempRoot = this->root;

   if (data < tempRoot->getData() && tempRoot->getLeftNodePtr() != nullptr) {
      // send left
      cout << "send left" << endl;
      Insert(data, tempRoot->getLeftNodePtr());
   } else {
      // insert left
      tempRoot->setLeftNodePtr(new Node<T>(data));
   }

   if (data > tempRoot->getData() && tempRoot->getRightNodePtr() != nullptr) {
      // send right
      cout << "send right" << endl;
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
void BinarySearchTree<T>::Print(Node<T>* tempRoot) {
   cout << "hola";
   if (tempRoot == nullptr) tempRoot = this->root;

   cout << tempRoot->getData();
   // print left
   if (tempRoot->getLeftNodePtr() != nullptr) Print(tempRoot->getLeftNodePtr());

   // print right
   if (tempRoot->getRightNodePtr() != nullptr)
      Print(tempRoot->getRightNodePtr());
}

// Templates
template class BinarySearchTree<int>;