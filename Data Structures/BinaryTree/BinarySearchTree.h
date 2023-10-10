#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class BinarySearchTree {
  private:
   Node<T>* root;

  public:
   BinarySearchTree();
   void Insert(T data, Node<T>* tempRoot = nullptr);
   Node<T>* getRootPtr();

   void Print() { InOrderTraversal(root); }
   void InOrderTraversal(Node<T>* node) {
      if (node != nullptr) {
         InOrderTraversal(node->getLeftNodePtr());
         std::cout << node->getData() << " ";
         InOrderTraversal(node->getRightNodePtr());
      }
   }
};
